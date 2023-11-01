#ifndef MINIMAL_FST_H
#define MINIMAL_FST_H

#include "state.h"
#include <fstream>
#include <string>



class minimal_fst {
public:
    minimal_fst(std::string filename);
    void display(std::string prefix, int n);
private:
    state* root;
};

#endif