#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
#include <boost/container_hash/hash.hpp>

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
    void set_state_output(std::string s);
    std::string get_state_output();
    int get_output(char input); //returns the transition value
    void set_output(char input, int output); //set the value for a transition
    state* copy() const;
    void clear();
    void dfs(std::string prefix, int n);

    //friend classes
    friend class std::hash<state*>;
    friend class std::equal_to<state*>;

private:
    // for each char, stores the corresponding transition state and value
    void dfs_aux(std::string prefix, int n, int& leaf_count);
    std::map<char, std::pair<state*, int>> transitions;
    bool final;
    std::string output;
};

// Hasher for state class
template<>
class std::hash<state*> {
public:
    std::size_t operator()(const state* state) const;
};

// Comparator for state class
template<>
class std::equal_to<state*> {
public:
    bool operator()(const state* lhs, const state* rhs) const;
};

class dictionary {
public:
    state* member(state* s);
    void insert(state* s);
    state* find_minimized(state* s);
    
private:
    std::unordered_set<state*> hash;
};

#endif