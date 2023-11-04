#include "LevenshteinAutomaton.h"

LevestheinAutomaton::LevestheinAutomaton(const std::string str, const int n)
{
   this->word = str;
   this->max_edits = n;
}

LevestheinAutomaton::~LevestheinAutomaton()
{
}

std::vector<int> LevestheinAutomaton::start()
{
   std::vector<int> start_state;
   start_state.resize(this->word.length() + 1);

   for (int i = 0; i < this->word.length() + 1; i++)
   {
      start_state[i] = i;
   }
   return start_state;
}

std::vector<int> LevestheinAutomaton::step(const std::vector<int> state, char c)
{
   std::vector<int> new_state;
   new_state.resize(this->word.length() + 1);
   new_state[0] = state[0] + 1;

   for (int i = 0; i < this->word.length() - 1; i++)
   {
      int cost = (c == this->word[i]) ? 0 : 1;
      new_state[i] = std::min(std::min(new_state[i] + 1, state[i] + cost), state[i + 1] + 1);
   }

   for (int i = 0; i < new_state.size(); i++)
   {
      new_state[i] = std::min(new_state[i], this->max_edits + 1);
   }

   return new_state;
}

bool LevestheinAutomaton::is_match(const std::vector<int> state)
{
   return (this->max_edits == state[state.size() - 1]);
}

bool LevestheinAutomaton::can_match(const std::vector<int> state)
{
   return (*(std::min_element(state.begin(), state.end())) <= this->max_edits);
}

std::unordered_set<char> LevestheinAutomaton::transitions(const std::vector<int> state)
{
   std::unordered_set<char> transitions;
   for (int i = 0; i < this->word.length(); i++)
   {
      if (state[i] <= this->max_edits)
      {
         transitions.insert(this->word[i]);
      }
   }
   return std::unordered_set<char>();
}
