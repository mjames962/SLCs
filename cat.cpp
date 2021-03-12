//
// Created by mjame on 18/02/2021.
//

#include <iostream>
#include "cat.h"

cat::cat(std::string name) {

    std::cout << "Constructor called with name...\n";

    this->name = name;
    this->lives = 9;
}

cat::cat(std::string name, unsigned int lives) {

    //std::cout << "Constructor called with name and lives...\n";

    this->name = name;
    this->lives = lives;
}

cat::~cat() {
   // std::cout << "Destructor called...\n";
}

std::string cat::get_name() const {
    return name;
}

unsigned int cat::get_lives() const {
    return lives;
}

void cat::set_name(std::string name) {
    std::cout << "set_name called...\n";

    this->name = name;
}
void cat::set_lives(unsigned int lives) {
    std::cout << "set_lives called...\n";

    if(this->lives > lives && lives >= 0) {
        this->lives = lives;

        if (this->lives == 0) {
            set_name("The Cat formerly known as " + get_name());
        }

    }
}

cat::cat() {
    std::cout << "Default constructor called...\n";

    this->name = "Tom";
    this->lives = 9;
}

std::ostream &operator<<(std::ostream &os, const cat &cat) {
    return std::cout << cat.get_name() << " has " << cat.get_lives() << " lives...";
}

bool operator==(const cat &lhs, const cat &rhs) {

    if (std::hash<cat>()(lhs) == std::hash<cat>()(rhs)) {
        return true;
    }


    return false;
}

bool operator<(const cat &lhs, const cat &rhs) {

    if (lhs.get_name() < rhs.get_name()) {
        return true;
    } else if (lhs.get_name() == rhs.get_name() and lhs.get_lives() < rhs.get_lives()) {
        return true;
    }

    return false;
}

