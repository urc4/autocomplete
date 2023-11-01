#include "../lib/state.h"
#include <iostream>

state* return_nullptr() {
    return nullptr;
}

int main() {
    state *A = new state();
    state *B = new state();
    state *C = new state();
    state *D = new state();
    state *E = new state();
    state *F = new state();

    dictionary d;

    A->set_transition('a', B, 3);
    A->set_transition('b', D, 2);
    A->set_transition('c', E, 1);
    C->set_transition('b', D, 2);
    C->set_transition('c', E, 1);
    C->set_transition('a', B, 3);
    D->set_transition('b', B, 3);
    E->set_transition('a', B, 2);
    F->set_transition('a', C, 3);
    d.insert(A);
    d.insert(C);
    d.insert(D);
    d.insert(E);
    d.insert(F);

    std::cout << " " << A << " " << d.member(C) << "\n";
    std::cout << " " << d.member(D) << " " << d.member(E) << " " << d.member(F) << "\n";
    std::cout << " " << d.member(B) << " " << return_nullptr() << "\n";
    
    return 0;
}