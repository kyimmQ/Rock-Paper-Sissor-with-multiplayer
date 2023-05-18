#include "init.h"
class gameplay: public init{
public:
    gameplay(){
        gameplay_logic();
    }
    void gameplay_logic(){
        if(num_of_player == 1){
            int computer = rand() % 3 + 1;
            std::cout << "Computer choice: " << computer << std::endl;
            if(computer == 1) rock.push_back("Computer");
            else if(computer == 2) paper.push_back("Computer");
            else if(computer == 3) sissor.push_back("Computer"); 
        }
        if((rock.size() > 0) + (paper.size() > 0) + (sissor.size() > 0) == 1) {
            std::string choice;
            choice = rock.size() > 0 ? "Rock" : paper.size() > 0 ? "Paper" : "Sissor";
            std::cout << "Result: Draw. Both Player and Computer chose: " << choice << std::endl;
            std::cout << "New game? 0 or 1: ";
            int new_game;
            std::cin >> new_game;
            if(new_game) gameplay game;
            return;
        }
        else if((rock.size() > 0) + (paper.size() > 0) + (sissor.size() > 0) == 3){
            std::cout << "Result: Draw" << std::endl;
            std::cout << "Players who chose Rock: ";
            for(int i = 0; i < rock.size(); i++) std::cout << rock[i] << " ";
            std::cout << std:: endl << "Players who chose Paper: ";
            for(int i = 0; i < paper.size(); i++) std::cout << paper[i] << " ";
            std::cout << std:: endl << "Players who chose Sissor: ";
            for(int i = 0; i < sissor.size(); i++) std::cout << sissor[i] << " ";
            std::cout << std:: endl;
            check_game_state(name);
            return;
        }
        else if((rock.size() > 0) + (paper.size() > 0) + (sissor.size() > 0) == 2){
            std::vector<std::string> win;
            std::vector<std::string> lose;
            std::string win_choice;
            std::string lose_choice;
            if(rock.size()){
                if(paper.size()) {
                    win = paper;
                    lose.insert(lose.end(), rock.begin(), rock.end());
                    win_choice = "Paper";
                    lose_choice = "Rock";
                }
                else {
                    win = rock;
                    lose.insert(lose.end(), sissor.begin(), sissor.end());
                    win_choice = "Rock";
                    lose_choice = "Sissor";
                }
            }
            else{
                win = sissor;
                lose.insert(lose.end(), paper.begin(), paper.end());
                win_choice = "Sissor";
                lose_choice = "Paper";
            }
            std::cout << "----------------------------------------------------------------------" << std::endl;
            std::cout << "Players who win: ";
            for(int i = 0; i < win.size(); i++) std::cout << win[i] << " ";
            std::cout << "chose " << win_choice << std::endl;
            std::cout << "Players who lose: ";
            for(int i = 0; i < lose.size(); i++) std::cout << lose[i] << " ";
            std::cout << "chose " << lose_choice << std::endl;
            check_game_state(win);
            std::cout << "New game? 0 or 1: ";
            int new_game;
            std::cin >> new_game;
            if(new_game) gameplay game;
            return;
            // }            
        }

    };
    void check_game_state(std::vector<std::string> win){
        if(win.size() > 1){
            rock.clear();
            paper.clear();
            sissor.clear();
            std::cout << std::endl;
            std::cout << "Continue:" << std::endl;
            for(int i = 0; i < win.size(); i++){
                std::cout << std::endl;
                std::cout << win[i] << "'s turn: "; 
                
                HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
                DWORD mode = 0;
                GetConsoleMode(hStdin, &mode);
                SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

                std::string s;
                // std::cin.ignore();
                std::fflush(stdin);
                getline(std::cin, s);
                SetConsoleMode(hStdin, mode);

                std::cout<<std::endl;
                if(s == "1") rock.push_back(win[i]);
                else if(s == "2") paper.push_back(win[i]);
                else if(s == "3") sissor.push_back(win[i]);
                else {
                    std::cout << "Invalid choice. Enter again" << std::endl;
                    i--;
                    continue;
                }
                std::cout << std::endl;
             }
            gameplay_logic();
        }
        
    }
};  