#include <iostream>
#include "Student.h"

// initializes the name and id attributes to values in the parenthesis

// default constructor 
Student::Student() :  name(""), id(0) {
    
}

std::string Student::getName() {
    return name;
}

int Student::getId() const {
    return id;
}

void Student::setData(std::string stringValue, int idValue) {
    name = stringValue;
    id = idValue;
}

void Student::print() const {
    std::cout << "name: " << name << std::endl;
    std::cout << "id: " << id << std::endl;
}