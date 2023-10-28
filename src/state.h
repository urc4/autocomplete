#include <vector>
#include <utility>
#include <unordered_map>

#ifndef STATE_H
#define STATE_H

class state{
public:
    state();
    bool get_final();
    void set_final(bool is_final);
    state* get_transition(char input);
    void set_transition(char input, state *next, int output = 0);
    int get_output(char input);
    void set_output(char input, int output);

private:
    std::unordered_map<char, std::pair<state*, int>> transitions;
    bool final;
};

#endif