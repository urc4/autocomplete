#include "../lib/minimal_fst.h"

int main() {
    minimal_fst fst("../data/american-english-dict-ascii");
    std::cout << "Digite a sua busca\n";
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        std::cout << "\n";
        fst.display(input, 10);
        std::cout << "-----------------------\nDigite a sua busca\n";
    }
    return 0;
}