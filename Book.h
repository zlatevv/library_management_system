#pragma once
#include <string>
#include <stdexcept>
#include "Author.h"

class Book {
private:
    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;

    static int totalBooks;

public:
    // Default constructor
    Book() 
        : title(""), author(), year(0), price(0.0), isbn("") 
    {
        ++totalBooks;
    }

    // Param constructor
    Book(const std::string& title, const Author& author, int year, double price, const std::string& isbn)
        : title(title), author(author), year(year), price(price), isbn(isbn) 
    {
        if (title.empty()) throw std::invalid_argument("Title cannot be empty");
        if (isbn.empty()) throw std::invalid_argument("ISBN cannot be empty");
        if (price < 0) throw std::invalid_argument("Price cannot be negative");
        if (year < 1850 || year > 2025) throw std::invalid_argument("Invalid year");

        ++totalBooks;
    }

    // Copy constructor
    Book(const Book& other)
        : title(other.title),
          author(other.author),
          year(other.year),
          price(other.price),
          isbn(other.isbn)
    {
        ++totalBooks;
    }

    // Move constructor
    Book(Book&& other) noexcept
        : title(std::move(other.title)),
          author(std::move(other.author)),
          year(other.year),
          price(other.price),
          isbn(std::move(other.isbn))
    {
        ++totalBooks;
    }

    // Copy assignment
    Book& operator=(const Book& other) {
        if (this != &other) {
            title = other.title;
            author = other.author;
            year = other.year;
            price = other.price;
            isbn = other.isbn;
        }
        return *this;
    }

    // Move assignment
    Book& operator=(Book&& other) noexcept {
        if (this != &other) {
            title = std::move(other.title);
            author = std::move(other.author);
            year = other.year;
            price = other.price;
            isbn = std::move(other.isbn);
        }
        return *this;
    }

    // Destructor
    ~Book() { --totalBooks; }

    // Getters
    const std::string& getTitle() const { return title; }
    const Author& getAuthor() const { return author; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    const std::string& getISBN() const { return isbn; }

    // Setters
    void setTitle(const std::string& t) {
        if (t.empty()) throw std::invalid_argument("Title cannot be empty");
        title = t;
    }

    void setYear(int y) {
        if (y < 1850 || y > 2025) throw std::invalid_argument("Invalid year");
        year = y;
    }

    void setPrice(double p) {
        if (p < 0) throw std::invalid_argument("Price cannot be negative");
        price = p;
    }

    void setISBN(const std::string& id) {
        if (id.empty()) throw std::invalid_argument("ISBN cannot be empty");
        isbn = id;
    }

    static int getTotalBooks() { return totalBooks; }

    std::string to_string() const {
        return "Book: " + title +
               ", Author: " + author.to_string() +
               ", Year: " + std::to_string(year) +
               ", Price: " + std::to_string(price) +
               ", ISBN: " + isbn;
    }
};

int Book::totalBooks = 0;
