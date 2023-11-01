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

std::size_t std::hash<state*>::operator()(const state* state) const {
    std::size_t seed;
    seed = 0;

    boost::hash_combine(seed, state->final);

    for(const auto& t : state->transitions) {
        boost::hash_combine(seed, t.first);
        boost::hash_combine(seed, t.second.first);
        boost::hash_combine(seed, t.second.second);
    }
    return seed;
}

bool std::equal_to<state*>::operator()(const state* lhs, const state* rhs) const {
    if(lhs->transitions.size() != rhs->transitions.size()) {
        return false;
    }

    if(lhs->final != rhs->final) {
        return false;
    }

    for(const auto& t : lhs->transitions) {
        auto got = rhs->transitions.find(t.first);
        if(got == rhs->transitions.end()) {
            return false;
        }
        if(got->first != t.first) {
            return false;
        }
        if(got->second != t.second) {
            return false;
        }
    }

    return true;
}

state* dictionary::member(state* s) {
    const auto got = hash.find(s);
    if(got == hash.end()){
        return nullptr;
    }
    else{
        return *got;
    }
}

void dictionary::insert(state *s) {
    hash.insert(s);
}