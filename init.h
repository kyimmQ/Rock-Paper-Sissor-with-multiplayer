#include <bits/stdc++.h>
#include <windows.h>
class init{
public:
    int num_of_player;
    std::vector<std::string> rock;
    std::vector<std::string> paper;
    std::vector<std::string> sissor;
    std::vector<std::string> name;
    std::set<std::string> unique_name;
    init(){
        num_of_player = 0;
        init_logic();
    };
    void init_logic(){
        //for hiding input
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
        DWORD mode = 0;
        GetConsoleMode(hStdin, &mode);
        std::cout << "----------------------------------------------------------------------" << std::endl;
        std::cout << "Game State";
        std::cout << std::endl;
        std::cout << "Enter number of player: ";
        std::cin >> num_of_player;
        int count = 1;

        while(count <= num_of_player){
            std::cout << std::endl;
            std::cout << "Enter player" << count << "'s name: ";
            std::string player;
            std::cin >> player;
            if(unique_name.count(player)) {
                std::cout << "Player name is already used. Enter another name" << std::endl;
                continue;
            }
            unique_name.insert(player);
            name.push_back(player);
            std::cout << "Enter your choice: ";
            SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
            std::string s;
            std::cin.ignore();
            std::fflush(stdin);
            getline(std::cin, s);
            SetConsoleMode(hStdin, mode);
            std::cout<<std::endl;
            if(s == "1") rock.push_back(player);
            else if(s == "2") paper.push_back(player);
            else if(s == "3") sissor.push_back(player);
            else {
                std::cout << "Invalid choice. Enter again" << std::endl;
                unique_name.erase(player);
                continue;
            }
            count++;
            std::cout << std::endl;
        }
    }
    ~init(){};
};

