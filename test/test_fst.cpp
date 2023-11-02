#include "../lib/minimal_fst.h"

int main() {
    std::string prefix;
    minimal_fst fst("../data/american-english-dict-ascii");
    std::cout << "Digite a sua busca\n";
    std::cin >> prefix;

    while(prefix != "") {
        fst.display(prefix, 10);
        std::cout << "Digite a sua busca\n";
        std::cin >> prefix;
    }
    return 0;
}