#ifndef CPP_CW_RESIT_FOR_FUN_PEOPLE_H
#define CPP_CW_RESIT_FOR_FUN_PEOPLE_H
#include <string>

class person {
public:
    unsigned int birth, death;
    std::string name;
    person(const unsigned int birth, const unsigned int death, const std::string name);

};


#endif //CPP_CW_RESIT_FOR_FUN_PEOPLE_H
