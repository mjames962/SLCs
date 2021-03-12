#include <iostream>
#include <unordered_set>
#include <set>
#include "cat.h"

int main(int argc, char* argv []) {

    cat a("Garfield" , 42);

    std::cout << std::hash<cat>()(a) << " = " << a << std:: endl;

    // Note the double ()() syntax!

    // std::hash <Cat>() default constructs an
    // object of type std::hash<Cat>

    // std::hash<Cat>()(a) invokes the call
    // operator () on that object with parameter

    // std::hash<Cat>()(a) returns an unsigned long integer


    std::unordered_set <cat> unique_cats;
    unique_cats.insert(cat("Garfield", 42));
    unique_cats.insert(cat("Garfield", 10));
    unique_cats.insert(cat("Catbert", 666));
    unique_cats.insert(cat("Toothless", 13));
    unique_cats.insert(cat("Garfield", 42));
    unique_cats.insert(cat("Garfield", 42));
    std::cout << std::endl << "Unique Cats" << std::endl;

    for (auto it = unique_cats.begin(); it != unique_cats.end(); it++) {
        std::cout << *it << std::endl;
    }


    std::set<cat> unique_cats2;
    unique_cats2.insert(cat("Garfield", 42));
    unique_cats2.insert(cat("Garfield", 10));
    unique_cats2.insert(cat("Catbert", 666));
    unique_cats2.insert(cat("Toothless", 13));
    unique_cats2.insert(cat("Garfield", 42));
    unique_cats2.insert(cat("Garfield", 42));
    std::cout << "\nUnique Ordered Cats" << std::endl;

    for (auto it = unique_cats2.begin(); it != unique_cats2.end(); it++) {
        std::cout << *it << std::endl;
    }

    return 0;
}
