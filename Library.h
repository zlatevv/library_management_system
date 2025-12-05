#pragma once
#include <vector>
#include <string>
#include <stdexcept>

#include "Book.h"
#include "Member.h"
#include "Loan.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;

public:

    // Add book
    void addBook(const Book& b) {
        books.push_back(b);
    }

    // Add member
    void addMember(const Member& m) {
        members.push_back(m);
    }

    // Check book existence
    bool hasBook(const std::string& isbn) const {
        for (const auto& b : books)
            if (b.getISBN() == isbn)
                return true;
        return false;
    }

    // Check if available (no active loans)
    bool isBookAvailable(const std::string& isbn) const {
        for (const auto& l : loans)
            if (l.getISBN() == isbn && !l.isReturned())
                return false;
        return true;
    }

    // Check member existence
    bool isValidMember(const std::string& id) const {
        for (const auto& m : members)
            if (m.getMemberId() == id)
                return true;
        return false;
    }

    // Loan a book
    bool loanBook(const std::string& isbn, const std::string& memberId,
                  const std::string& start, const std::string& due)
    {
        if (!hasBook(isbn)) return false;
        if (!isBookAvailable(isbn)) return false;
        if (!isValidMember(memberId)) return false;

        loans.emplace_back(isbn, memberId, start, due);
        return true;
    }

    // Return a book
    bool returnBook(const std::string& isbn, const std::string& memberId) {
        for (auto& loan : loans) {
            if (loan.getISBN() == isbn &&
                loan.getMemberId() == memberId &&
                !loan.isReturned())
            {
                loan.markReturned();
                return true;
            }
        }
        return false;
    }

    std::vector<Book> findByAuthor(const std::string& authorName) const {
        std::vector<Book> result;
        for (const auto& b : books)
            if (b.getAuthor().getName().find(authorName) != std::string::npos)
                result.push_back(b);
        return result;
    }

    // Summary
    std::string to_string() const {
        return "Library: Books=" + std::to_string(books.size()) +
               ", Members=" + std::to_string(members.size()) +
               ", Loans=" + std::to_string(loans.size());
    }
};
