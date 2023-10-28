#include "state.h"

state::state() {
    final = 0;
}

bool state::get_final() {
    return final;
}

void state::set_final(bool is_final) {
    final = is_final;
}

state* state::get_transition(char input) {
    const auto got = transitions.find(input);
    if(got == transitions.end()){
        return nullptr;
    }
    else{
        return (got->second).first;
    }
}

void state::set_transition(char input, state *next, int output/*= 0*/) {
    transitions.insert({input, std::make_pair(next, output)});
}

int state::get_output(char input) {
    const auto got = transitions.find(input);
    if(got == transitions.end()){
        return -1;
    }
    else{
        return (got->second).second;
    }
}

void state::set_output(char input, int output) {
    const auto got = transitions.find(input);
    if(got == transitions.end()){
        return;
    }
    (got->second).second = output;
}
