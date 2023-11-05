#ifndef BUILD_DFA_FROM_LA
#define BUILD_DFA_FROM_LA

#include <unordered_map>
#include <tuple>
#include "LevenshteinAutomaton.h"

namespace buildDFAfromLA
{

   std::unordered_map<std::tuple<std::vector<int>, std::vector<int>, char>, int> states;
   std::vector<std::tuple<int, int, char>> transitions;
   std::vector<int> matching;
   int counter = 0;

      LevestheinAutomaton lev = LevestheinAutomaton("woof", 1);

   int explore(const std::vector<int> &state);

}

#endif