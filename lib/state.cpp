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
    const auto got = transitions.find(input);
    if(got == transitions.end()){
        transitions.insert({input, std::make_pair(next, output)});
        return;
    }
    transitions.erase(input);
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

void state::set_state_output(std::string s) {
    output = s;
}

std::string state::get_state_output() {
    return output;
}

state* state::copy() const {
    state* s = new state();
    s->transitions = this->transitions;
    s->final = this->final;
    s->output = this->output;
    return s;
}

void state::clear() {
    this->transitions.clear();
    this->final = false;
    this->output = "";
}

void state::dfs_aux(std::vector<std::string>& output, std::string prefix, int n, int& leaf_count) {
    if(final) {
       output.push_back(prefix);
       leaf_count++;
    }

    if(transitions.size() == 0) {
        return;
    }

    for(auto it = transitions.begin(); it != transitions.end(); ++it) {
       if(leaf_count >= n) {
           return;
       }
       it->second.first->dfs_aux(output, prefix + it->first, n, leaf_count);
    }
}

int state::dfs(std::vector<std::string>& output, std::string prefix, int n) {
    output.clear();
    int leaf_count = 0;
    dfs_aux(output, prefix, n, leaf_count);
    return leaf_count;
}



std::size_t std::hash<state*>::operator()(const state* state) const {
    std::size_t seed;
    seed = 0;

    boost::hash_combine(seed, state->final);

    for(auto it = state->transitions.begin(); it != state->transitions.end(); ++it) {
        boost::hash_combine(seed, it->first);
        boost::hash_combine(seed, it->second.first);
        boost::hash_combine(seed, it->second.second);
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

    for(auto it = lhs->transitions.begin(); it != lhs->transitions.end(); ++it) {
        auto got = rhs->transitions.find(it->first);
        if(got == rhs->transitions.end()) {
            return false;
        }
        if(got->second.first != it->second.first) {
            return false;
        }
        if(got->second.second != it->second.second) {
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

state* dictionary::find_minimized(state *s, int& count, int& size) {
    state* r = member(s);
    if(r == nullptr) {
        r = s->copy();
        insert(r);
        count++;
        size += sizeof(*r);
    }
    return r;
}

//a