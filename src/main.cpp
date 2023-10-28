#include "state.h"
#include <iostream>

//Teste
int main() {
    state A;
    state *B = new state();
    state *C = new state();
    A.set_transition('a', B);
    B->set_transition('a', C, 3);
    A.set_output('a', 2);
    A.set_final(true);

    std::cout << A.get_output('a') << " " << A.get_transition('a')->get_output('a');
    return 0;
}