#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class Loan {
    private:
        std::string isbn;
        std::string memberId;
        std::string startDate;
        std::string dueDate;
        bool returned;
    public:
        Loan(const std::string& isbn, const std::string& memberId, const std::string& startDate,  const std::string&
            dueDate)
            : isbn(isbn), memberId(memberId), startDate(startDate), dueDate(dueDate), returned(false){
                
                
                if (dueDate < startDate) 
                    throw std::invalid_argument("Due date cannot be before start date!");
                
                if (isbn.empty()) 
                    throw std::invalid_argument("ISBN cannot be empty");
                
                if (memberId.empty()) 
                    throw std::invalid_argument("Member ID cannot be empty");
            }
        void markReturned(){ returned = true;}
        bool isOverdue(const std::string& today) const {
            return !returned && today > dueDate;
        }
        std::string getISBN() const { return isbn; }
        std::string getMemberId() const { return memberId; }
        std::string getStartDate() const { return startDate; }
        std::string getDueDate() const { return dueDate; }
        bool isReturned() const { return returned; }

        std::string to_string() const {
            return "Loan: ISBN=" + isbn +
                ", MemberID=" + memberId +
                ", Start=" + startDate +
                ", Due=" + dueDate +
                ", Returned=" + (returned ? "Yes" : "No");
        }
};