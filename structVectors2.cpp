#include <iostream>
#include <vector>
#include <string>

struct Athlete{
    std::string firstName;
    std::string lastName;
    int bench;
    int deadlift;
};

void display(std::vector<Athlete> &det){
    for(int i = 0;i<det.size();i++){
        std::cout << i << ". " <<det[i].firstName << '\t' << det[i].lastName << '\t' << det[i].bench << '\t' << det[i].deadlift << '\t' << det[i].bench + det[i].deadlift << std::endl;
    }
}

void readAbout(Athlete *athlete){
    std::cin >> athlete->firstName;
    std::cin >> athlete->lastName;
    std::cin >> athlete->bench;
    std::cin >> athlete->deadlift;
}

int personalBestBench(std::vector<Athlete> &det){
    int greatest = 0;
    for(int i = 0;i<det.size();i++){
        if(det[i].bench > greatest) greatest = det[i].bench;
    }
    return greatest;
}

int personalBestDeadlift(std::vector<Athlete> &det){
    int greatest = 0;
    for(int i = 0;i<det.size();i++){
        if(det[i].deadlift > greatest) greatest = det[i].deadlift;
    }
    return greatest;
}

void sortUser(std::vector<Athlete> &det){
    int greatest = 0, great = 0;
    for(int i = 0;i<det.size();i++){
        great = det[i].bench + det[i].deadlift;
        for(int j = 0;j<det.size();j++){
            greatest = det[j].bench + det[j].deadlift;
            if(greatest < great){
                std::string tmp = det[i].firstName;
                det[i].firstName = det[j].firstName;
                det[j].firstName = tmp;
                tmp = det[i].lastName;
                det[i].lastName = det[j].lastName;
                det[j].lastName = tmp;
                int tmpi = det[i].bench;
                det[i].bench = det[j].bench;
                det[j].bench = tmpi;
                tmpi = det[i].deadlift;
                det[i].deadlift = det[j].deadlift;
                det[j].deadlift = tmpi;
            }
        }
    }
    display(det);
}

void deleteSur(std::vector<Athlete> &det, std::string surname){
    for(int i = 0;i<det.size();i++){
        if(det[i].lastName == surname){
            std::cout << "\nI will erase this human - " << det[i].firstName << " " << det[i].lastName << std::endl;
            det.erase(det.begin() + i);
        }
    }
}

int main(){

    std::vector<Athlete> athlete;

    Athlete Arnold = {"Arnold", "Schwanzi", 200, 300};
    Athlete Rambo = {"Rambo", "Stalone", 250, 350};
    Athlete Termin = {"Termi", "Nator", 300, 500};

    athlete.push_back(Arnold);
    athlete.push_back(Rambo);
    athlete.push_back(Termin);

    Athlete Mateo;
    // std::cin >> Mateo.firstName;
    // std::cin >> Mateo.lastName;
    // std::cin >> Mateo.bench;
    // std::cin >> Mateo.deadlift;
    readAbout(&Mateo);
    athlete.push_back(Mateo);

    //

    std::cout << personalBestBench(athlete) << std::endl;
    std::cout << personalBestDeadlift(athlete) << std::endl;

    std::cout << "Sorted users!\n";
    sortUser(athlete);

    deleteSur(athlete, "Schwanzi");
    std::cout << "Display deleted structure!\n"; 
    display(athlete);

    std::cout << "\nDone challenge!" << std::endl;
    return 0;
}