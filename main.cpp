#include <iostream>
#include "Author.h"
#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include "Library.h"

int main() {
    Author a1;
    Author a2("J.K. Rowling", 1965);
    Author a3 = a2;     // copy test
    a3.setName("Changed Author");
    a3.setBirthYear(1970);

    Book b1;
    Book b2("Harry Potter", a2, 1997, 29.99, "9780545010221");
    Book b3 = b2;
    Book b4 = std::move(b3); 

    b4.setTitle("Harry Potter Updated");
    b4.setYear(1998);
    b4.setPrice(35.50);

    Member m1;
    std::cout << m1.to_string() << "\n\n";

    Member m2("Tsvetan Zlatev", "1234567890", 2020);
    m2.setName("Tseko");
    m2.setMemberId("0987654321");

    Loan l1("9780545010221", "0987654321", "2024-05-01", "2024-05-20");

    Library lib;

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b4);

    lib.addMember(m1);
    lib.addMember(m2);

    std::cout << "Has book? " 
              << lib.hasBook("9780545010221") << "\n";

    std::cout << "Is book available? "
              << lib.isBookAvailable("9780545010221") << "\n";

    std::cout << "Loan attempt 1: "
              << lib.loanBook("9780545010221", "0987654321",
                              "2024-05-01", "2024-05-20") << "\n";

    std::cout << "Loan attempt 2 (should fail if unavailable): "
              << lib.loanBook("9780545010221", "0987654321",
                              "2024-05-02", "2024-05-25") << "\n";

    std::cout << "Return book: "
              << lib.returnBook("9780545010221", "0987654321") << "\n\n";

    auto found = lib.findByAuthor("Rowling");
    std::cout << "Books by Rowling: " << found.size() << "\n";
    for (const auto& b : found)
        std::cout << b.to_string() << "\n";

    std::cout << "\n" << lib.to_string() << "\n";

    return 0;
}
