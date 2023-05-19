#include "gameplay.h"

int main(){
    std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << "                      Welcome to Rock - Paper - Sissor                " << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << "This is a version of Rock - Paper - Sissor supporting multiplayer implemented in C++ with OOP" << std::endl;
    std::cout << "1: Rock" << std::endl << "2: Paper" << std::endl << "3: Sissor" << std::endl;
    
    while(true){
        gameplay game;
        std::cout << "New game? 0 or 1: ";
        int new_game;
        std::cin >> new_game;
        if(!new_game) break;
    }
    
    return 0;
}