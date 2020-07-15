#include "person.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>

std::vector<std::string> split(const std::string &s) {
    std::string str(s);
    std::string buf;
    std::stringstream ss(str);
    std::vector<std::string> elems;
    while (ss >> buf)
        elems.push_back(buf);

    return elems;
}

std::vector<person> read_people(){
    std::vector<person> people;
    std::ifstream in("people.txt");
    std::string line;
    std::string tmp_name;
    std::vector<std::string> tmp_elems;
    unsigned int tmp_birth, tmp_death;
    while(getline(in, line)) {
        tmp_elems = split(line);
        tmp_birth =std::stoul(tmp_elems[0]);
        tmp_death = std::stoul(tmp_elems[1]);
        tmp_name = tmp_elems[2];
        person *tmp_person = new person(tmp_birth, tmp_death, tmp_name);
        people.push_back(*tmp_person);
    }
    return people;
}

void print_people_alive(const unsigned int year, std::vector<person> people){
    std::vector<person> people_alive;
    for (auto p : people){
        if (p.death >= year && p.birth <= year) {
            people_alive.push_back(p);
        }
    }
    for (auto a : people_alive){
        std::cout <<  a.name << " " << "(" << a.birth << "-" << a.death << ")" << '\n';
    }
}



int main(){
    std::vector<unsigned int> years;
    std::string line;
    auto peple = read_people();
    while(getline(std::cin, line)) {
        years.push_back(std::stoul(line));
    }
    for (auto l : years){
        std::cout << "People alive in " << l << ":" << '\n';
        print_people_alive(l, peple);
    }

    return 1;
}
