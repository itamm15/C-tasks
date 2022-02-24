#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>

bool flag = true;
std::string login, surname, password;

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
    std::string password {};
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

CarLender createAccount(std::fstream &file){
    CarLender lender;
    std::cout << "Provide name\t";
    std::cin >> login;
    lender.Name = login;
    std::cout << "Provid surname\t";
    std::cin >> surname;
    lender.Surname = surname;
    std::cout << "Provide password\t";
    std::cin >> password;
    lender.password = password;
    if(file.is_open()){
        //std::cout << "i am here";
        file << lender.Name << ";" << lender.Surname << ";" << lender.password << "\n";
    }else{
        std::cout << "The database is not working!";
    }
    return lender;
}

void loginInto(std::fstream &file){
    std::string line;
    std::cout << "Provide login\t";
    std::cin >> login;
    std::cout << "Provide password\t";
    std::cin >> password;
    if(file.is_open()){
        while(std::getline(file, line)){
            //std::cout << line << std::endl;
            int founded = line.find(';');
            std::string loginCompare = line.substr(0,founded), passwordCompare = line.substr(founded + 1, line.length()-1);
            //std::cout << "Founded:\t" << founded << "login to compare:" << loginCompare <<std::endl;
            //std::cout << "Password to compare:" << passwordCompare << std::endl;
            if(login == loginCompare){
                //std::cout << "I AM HERE!" << loginCompare << " " << passwordCompare << std::endl;
                if(password == passwordCompare){
                    std::cout << "Authorization completed.\n";
                    std::getchar();
                }else{
                    std::cout << "Authorization not completed. Please, try again later.";
                    std::getchar();
                    exit(0);
                }
            }
        }
    }
}

int main(){

    std::fstream fileData;
    fileData.open("data.txt", std::ios::in | std::ios::out | std::ios::app);

    //MAIN MENU
    char choice {};

    while(flag){

        std::cout << "Would you like to log in, or to create account? [1/2]\n";
        std::cin >> choice;
        clearWindow();

    switch(choice){
        case '1':{
            //Log in
            loginInto(fileData);
            flag = false;
            clearWindow();
            break;
        }
        case '2':{
            //Create an account
            CarLender lender = createAccount(fileData);
            flag = false;
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
        //std::cout << login << " " << password << "I AM HERE!\n";
        std::cout << "Welcome in Car Rental Program, " << login << "! To chose given option, enter the number and press enter.\n1. Table with description,\n2. Your account,\n3. Extend rental,\n4. Finish rental,\n5. Check rental history,\n6. Exit.\n";
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

    fileData.close();

    return 0;
}