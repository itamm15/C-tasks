#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

bool flag = true;

struct CarRent{
    std::string CarType {};
    std::string CarModel {};
    std::string CarID {};
    int rentDuration {};
    double pricePerDay {};
    double priceTotal = pricePerDay * rentDuration;
};

struct CarLender{
    std::string Name {};
    std::string Surname {};
    std::string LenderID {};
};

void clearWindow(){
    system("clear");
}

void pushToVector(CarLender carLen, std::vector<CarLender> &det){
    det.push_back(carLen);
}

void printTable(std::vector<CarLender> &det){
    for(std::vector<CarLender>::iterator itr = det.begin();itr != det.end();++itr){
        std::cout << itr->Name << "\t" << itr->Surname << "\t" << itr->LenderID <<  std::endl;
    }
}

void createAccount(){
    std::string login;
    std::cout << "Provide login\t";
    std::getline(std::cin, login);
    std::string password;
    std::cout << "Provide password\t";
    std::getline(std::cin, password);
}

int main(){

    //MAIN MENU
    char choice {};

    while(flag){

        std::cout << "Would you like to log in, or to create account? [1/2]\n";
        std::cin >> choice;
        clearWindow();

    switch(choice){
        case '1':{
            //Log in
            std::string login, password;
            std::cout << "Provide your login \t";
            std::cin.ignore();
            std::getline(std::cin, login);
            std::cout << "Provide your password \t";
            std::getline(std::cin, password);
            //std::cout << login << " " << password << std::endl;
            flag = false;
            clearWindow();
            break;
        }
        case '2':{
            //Create an account
            createAccount();
            break;
        }
        default:{
            std::cout << "Please, provide value 1 or 2.\n";
        }
      }
    }

    std::vector<CarLender> carLenders;
    CarLender Matthew;
    Matthew.Name = "Matthew";
    Matthew.Surname = "Osinski";
    Matthew.LenderID = "000123DE45"; 
    CarLender Victor;
    Victor.Name = "Victor";
    Victor.Surname = "Ludwiniak";
    Victor.LenderID = "000321ED54";
    pushToVector(Matthew, carLenders);
    pushToVector(Victor, carLenders);

    /*
    To create your account function, user MUST BE logged in. 
    Also in the future, I will provide such an opitions:
    - logging in with database control and security, 
    - for given account type (by that I mean admin, customer, accountant etc.) will be displayed different options
    
    */
    flag = true;
    while(flag){
        std::cout << "Welcome in Car Rental Program! To chose given option, enter the number and press enter.\n1. Table with description,\n2. Your account,\n3. Extend rental,\n4. Finish rental,\n5. Check rental history,\n6. Exit.\n";
        std::cin >> choice;
        switch(choice){
            case '1':{
                bool flag = true;
                char choice {};
                while(flag){
                    clearWindow();
                    printTable(carLenders);
                    std::cout << "\nTo exit press [X] and enter\t";
                    std::cin >> choice;
                    if(choice == 'x' || choice == 'X') flag = false;
                }
                break;
            }
            case '2':{

                break;
            }
            case '3':{

                break;
            }
            case '4':{

                break;
            }
            case '5':{

                break;
            }
            case '6':{
                flag = false;
                break;
            }
            default:{
                std::cout << "Provide correct option!\n";
            }
        }
        clearWindow();
    }

    return 0;
}