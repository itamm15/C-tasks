#include <iostream>
#include <string>

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
    for(int i = 0;i<15;i++){
        std::cout << std::endl;
    }
}

int main(){

    //MAIN MENU
    
    char choice {};

    while(flag){
        std::cout << "Welcome in Car Rental Program! To chose given option, enter the number and press enter.\n1. Table with description,\n2. Your account,\n3. Extend rental,\n4. Finish rental,\n5. Check rental history,\n6. Exit.\n";
        std::cin >> choice;
        switch(choice){
            case '1':{

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