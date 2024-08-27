#include <iostream>
#include <string>
#include "Student.h"

int main() {
    Student s[3];
    int i = 1;
    for(Student &student: s) {
        int id;
        std::string name;
        std::cout << "Enter a name for student " << i << " : ";
        std::cin >> name;
        std::cout << std::endl <<"Enter an id for student " << i << " : ";
        std::cin >> id;
        student.setData(name, id);
    }

    while(true) {
        std::string input;
        std::cout << "Search for a student by typing an id or name (press q to quit): ";
        std::cin >> input;
        if(input == "q" || input == "Q") {
            return 0;
        }
        bool found = false; 
        for(Student &student: s) {
            if(input == student.getName()) {
                std::cout << std::endl << "The associated id for " << student.getName() << " is " << student.getId() << std::endl;
                found = true;
                break;
            } else if (input == std::to_string(student.getId())) {
                std::cout << std::endl << "The associated name for " << student.getId() << " is " << student.getName() << std::endl;
                found = true;
                break;
            }
        }
        if(!found) {
            std::cout << "Error! No student with that name or id!" << std::endl;
        }
    }
    
    return 0;
}