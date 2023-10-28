#include <vector>
#include <utility>
#include <unordered_map>

#ifndef STATE_H
#define STATE_H

// Class to represent the state of the FST
class state{
public:
    state();
    bool get_final(); //returns true if state is final state
    void set_final(bool is_final); //set true if final state
    state* get_transition(char input); //returns a pointer to the state corresponding to input char
    void set_transition(char input, state *next, int output = 0); //set transition state and value (optionally)
    int get_output(char input); //returns the transition value
    void set_output(char input, int output); //set the value for a transition

private:
    // for each char, stores the corresponding transition state and value
    std::unordered_map<char, std::pair<state*, int>> transitions;

    bool final;
};

#endif