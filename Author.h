#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class Author {
private:
    std::string name;
    int birthYear;
public:
    Author(): name("Unknown"), birthYear(1900) {}
    Author(const std::string& name, int birthYear): name(name), birthYear(birthYear) {}

    ~Author() = default;

    std::string to_string() const {
        return "The man, the myth, the legend: " + name + "! Born in " + std::to_string(birthYear);
    };

    std::string getName() const {return name;}
    int getYear() const {return birthYear;}

    void setName(const std::string& name){
        if (name.empty()){
            throw std::invalid_argument("Invalid data for name!");
        }
        this->name = name;
    }

    void setBirthYear(int year){
        if (year < 1850 || year > 2025){
            throw std::invalid_argument("Invalid birth year!");
        }

        this->birthYear = year;
    }
};