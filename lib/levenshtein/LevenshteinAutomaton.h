#ifndef LEVENSHTEIN_AUTOMATON
#define LEVENSHTEIN_AUTOMATON

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

class LevestheinAutomaton
{
private:
   std::string word;
   int max_edits;

public:
   LevestheinAutomaton(const std::string str, const int n);
   ~LevestheinAutomaton();

   std::vector<int> start();
   std::vector<int> step(const std::vector<int> state, char c);
   bool is_match(const std::vector<int> state);
   bool can_match(const std::vector<int> state);
   std::unordered_set<char> transitions(const std::vector<int> state);
};

#endif