#include "buildDFAfromLA.h"
#include <iostream>

int buildDFAfromLA::explore(const std::vector<int> &state)
{
   auto key = std::make_tuple(state, state, '*');
   if (states.find(key) != states.end())
   {
      return states[key];
   }
   int i = counter++;
   states[key] = i;
   if (lev.is_match(state))
   {
      matching.push_back(i);
   }

   for (char c : lev.transitions(state))
   {

      auto new_state = lev.step(state, c);
      int j = explore(new_state);
      transitions.emplace_back(i, j, c);
   }

   return i;
}

int main()
{

   buildDFAfromLA::explore(buildDFAfromLA::lev.start());
   std::sort(buildDFAfromLA::transitions.begin(), buildDFAfromLA::transitions.end(), [](const auto &a, const auto &b)
             { return std::get<0>(a) < std::get<0>(b); });

   // Output to Graphviz
   std::cout << "digraph G {" << std::endl;
   for (const auto &t : buildDFAfromLA::transitions)
   {
      std::cout << std::get<0>(t) << " -> " << std::get<1>(t) << " [label=\" " << std::get<2>(t) << " \"]" << std::endl;
   }
   for (int i : buildDFAfromLA::matching)
   {
      std::cout << i << " [style=filled]" << std::endl;
   }
   std::cout << "}" << std::endl;

   return 0;
}