#include "../lib/minimal_fst.h"
#include <chrono>
#include <termios.h>

char getch() {
   char buf = 0;
   struct termios old = {0};
   if (tcgetattr(0, &old) < 0)
       perror("tcsetattr()");
   old.c_lflag &= ~ICANON;
   old.c_lflag &= ~ECHO;
   old.c_cc[VMIN] = 1;
   old.c_cc[VTIME] = 0;
   if (tcsetattr(0, TCSANOW, &old) < 0)
       perror("tcsetattr ICANON");
   if (read(0, &buf, 1) < 0)
       perror ("read()");
   old.c_lflag |= ICANON;
   old.c_lflag |= ECHO;
   if (tcsetattr(0, TCSADRAIN, &old) < 0)
       perror ("tcsetattr ~ICANON");
   return (buf);
}

int main() {
    // Build tree
    auto start = std::chrono::high_resolution_clock::now();
    minimal_fst fst("../data/american-english-dict-ascii");
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Data Structure: Finite State Transducer\n";
    std::cout << "Build time: " << elapsed.count() << " segundos \n";
    std::cout << "Space: " << fst.get_size() << " bytes \n";
    std::cout << "Vertices: " << fst.count_vertices() << "\n\n";

    std::cout << "Digite a sua busca (Aperte ENTER para sair)\n";
    std::string input;
    for (char c = getch(); c != '\n'; c = getch()) {
        if (c != 8 && c != 127){
            input += c;
        }
        else{
            if (!input.empty()) {
                input.erase(input.size()-1);
            }
        }
        std::cout << "\033[2K\033[0G" << input << "\n\n";
        fst.display(input, 10);
        for(int i = 1; i <= 13; i++){
            std::cout << "\r\033[A";
        }
   }
    for(int i = 1; i <= 13; i++) {
        std::cout << "\033[2K\n";
    }
    return 0;
}

//a