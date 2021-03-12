//
// Created by mjame on 18/02/2021.
//

#ifndef CLASSES_CAT_H
#define CLASSES_CAT_H


#include <sstream>

class cat {

protected:
    std::string name;
    unsigned int lives;
public:
    cat(std::string name);

    cat(std::string name, unsigned int lives);

    ~cat();

    cat();

    std::string get_name() const;

    unsigned int get_lives() const;

    void set_name(std::string name);

    void set_lives(unsigned int lives);

    friend std::ostream &operator<<(std::ostream &os, const cat &cat);

    friend bool operator==(const cat& lhs, const cat& rhs);

    friend bool operator<(const cat &lhs, const cat &rhs);
};

namespace std {

    template<>
    struct hash<cat> {
        size_t operator()(const cat &obj) const {
            // ... compute a hash as an unsigned
            // integer and return it...

           basic_string<char> ss = "" + obj.get_name() + std::to_string(obj.get_lives());

           std::hash<std::string> hasher;

           auto digest = hasher(ss);

            return digest;
        }


    };
}





#endif //CLASSES_CAT_H