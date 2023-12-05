#ifndef HOMEWORK_H
#define HOMEWORK_H

#include <string>

// Define a structure to represent homework
struct Homework {
    std::string subject;
    std::string title; // the name of the assignment
    std::string description;
    std::string dueDate;
    bool isCompleted;
};

// Function declarations
void displayMenu();
void addHomework(Homework* homeworkArray, int& count);
void viewHomework(Homework* homeworkArray, int count);
void saveToFile(const Homework* homeworkArray, int count, const std::string& fileName);
void loadFromFile(Homework* homeworkArray, int& count, const std::string& fileName);
void searchByTitle(Homework* homeworkArray, int count);

#endif // HOMEWORK_H
