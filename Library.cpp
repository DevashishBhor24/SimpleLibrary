#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Book {
    std::string title;
    std::string author;
    int year;
};

std::vector<Book> library;

void addBook(const std::string& title, const std::string& author, int year) {
    Book newBook;
    newBook.title = title;
    newBook.author = author;
    newBook.year = year;
    library.push_back(newBook);
    std::cout << "Book added to the library.\n";
}

void displayBooks() {
    if (library.empty()) {
        std::cout << "The library is empty.\n";
    } else {
        std::cout << "Library Books:\n";
        for (const auto& book : library) {
            std::cout << "Title: " << book.title << ", Author: " << book.author << ", Year: " << book.year << "\n";
        }
    }
}

void searchByAuthor(const std::string& author) {
    std::cout << "Books by " << author << ":\n";
    bool found = false;
    for (const auto& book : library) {
        if (book.author == author) {
            std::cout << "Title: " << book.title << ", Year: " << book.year << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found by " << author << ".\n";
    }
}

int main() {
    int choice;
    std::string title, author;
    int year;

    do {
        std::cout << "\n--- Library Management System ---\n";
        std::cout << "1. Add a book\n";
        std::cout << "2. Display all books\n";
        std::cout << "3. Search books by author\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter book title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter book author: ";
                std::getline(std::cin, author);
                std::cout << "Enter publication year: ";
                std::cin >> year;
                addBook(title, author, year);
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                std::cout << "Enter author name: ";
                std::cin.ignore();
                std::getline(std::cin, author);
                searchByAuthor(author);
                break;
            case 4:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
