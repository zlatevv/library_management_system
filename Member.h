#include <iostream>
#include <stdexcept>
#pragma once
using namespace std;

class Member {
    private:
        std::string name;
        std::string memberId;
        int yearJoined;
    public:
        Member(): name("Unknown"), memberId("0000"), yearJoined(2025) {};
        Member(const std::string& name, const std::string& memberId, int yearJoined)
            : name(name), memberId(memberId), yearJoined(yearJoined) {}
        
        std::string getName() const { return name; }
        std::string getMemberId() const { return memberId; }
        int getYearJoined() const { return yearJoined; }

        void setName(const std::string& name){
            if (name.empty()){
                throw std::invalid_argument("Name is empty!");
            }

            this->name = name;
        }

        void setMemberId(const std::string& memberId){
            if (memberId.empty()){
                throw std::invalid_argument("Id is empty!");
            }

            this->memberId = memberId;
        }
        void setYearJoined(int year){
            if (year < 1900 || year > 2025){
                throw std::invalid_argument("Invalid year joined!");
            }
            this->yearJoined = year;
        }

        string to_string() const{
            return "Member: " + name + ", ID: " + memberId + 
            ", Joined: " + std::to_string(yearJoined);
        }
};