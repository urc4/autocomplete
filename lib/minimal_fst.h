#ifndef MINIMAL_FST_H
#define MINIMAL_FST_H

#define MAX_WORD_SIZE 50

#include "state.h"
#include <fstream>
#include <string>
#include <set>

class minimal_fst {
public:
    minimal_fst(std::string filename);
    int count_vertices();
    int get_size();
    void display(std::string prefix, int n);
private:
    state* root;
    int count = 0;
    int size = 0;
};

class InexistentFileException : public std::exception {
public:
    std::string what();
};

#endif