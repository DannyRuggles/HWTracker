#include "homework.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "Homework Tracker Menu\n";
    cout << "1. Add Homework\n";
    cout << "2. View Homework\n";
    cout << "3. Save Homework to File\n";
    cout << "4. Load Homework from File\n";
    cout << "5. Search by Homework Title\n";
    cout << "6. Exit the Program\n";
}

// Function to add homework to the array
void addHomework(Homework* homeworkArray, int& count) {
    // Clear the input buffer to handle invalid input
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter subject: ";
    getline(cin, homeworkArray[count].subject);

    cout << "Enter title: ";
    getline(cin, homeworkArray[count].title);

    cout << "Enter description: ";
    getline(cin, homeworkArray[count].description);

    cout << "Enter due date (DD-MM-YYYY): ";
    getline(cin, homeworkArray[count].dueDate);

    homeworkArray[count].isCompleted = false;

    count++;
}

// Function to view all homework
void viewHomework(Homework* homeworkArray, int count) {
    cout << "Homework List:\n";
    for (int i = 0; i < count; ++i) {
        cout << "Subject: " << homeworkArray[i].subject << "\n";
        cout << "Title: " << homeworkArray[i].title << "\n";
        cout << "Description: " << homeworkArray[i].description << "\n";
        cout << "Due Date: " << homeworkArray[i].dueDate << "\n";
        cout << "Completed: " << (homeworkArray[i].isCompleted ? "Yes" : "No") << "\n";

        // Check if homework is not already completed before prompting
        if (!homeworkArray[i].isCompleted) {
            // Prompt user to update completion status
            char completionChoice;
            cout << "Is this homework done? (y/n): ";
            cin >> completionChoice;

            if (completionChoice == 'y' || completionChoice == 'Y') {
                homeworkArray[i].isCompleted = true;
            } else if (completionChoice == 'n' || completionChoice == 'N') {
                homeworkArray[i].isCompleted = false;
            } else {
                cout << "Invalid choice. Assuming 'No' for completion status.\n";
                homeworkArray[i].isCompleted = false;
            }
        } else {
            cout << "This homework is already marked as completed.\n";
        }
        cout << "\n";  // Add a newline for better formatting
    }
    if(count == 0) {
        cout << "There are no homework entries to view. \n";
    }
}

// Function to save homework to a file
void saveToFile(const Homework* homeworkArray, int count, const string& fileName) {
    int i;
    // Open the file output stream using the file name provided as input
    ofstream outputFile(fileName);

    // Starting at zero, while i is less then the current number of homework structures stored in the array, increment i and print out each attribues to a file
    for ( i = 0; i < count; ++i) {
        outputFile << homeworkArray[i].subject << "\n";
        outputFile << homeworkArray[i].title << "\n";
        outputFile << homeworkArray[i].description << "\n";
        outputFile << homeworkArray[i].dueDate << "\n";
        outputFile << homeworkArray[i].isCompleted << "\n";
    }

    // Close the file. connection one the function has been completed.
    outputFile.close();
}

// Function to load homework from a file
void loadFromFile(Homework* homeworkArray, int& count, const string& fileName) {

    // Open the input file stream using the file path provided as a argument of the function.
    ifstream inputFile(fileName);

    // If the file connection doesn't open, display an error message to the user and leave the function
    if (!inputFile.is_open()) {
        cout << "Error: Could not open file.\n";
        return;
    }

    // While the read pointer is not reading an end of line character, read in the file data to the homework structure found at that count in the array
    while (!inputFile.eof()) {
        inputFile >> homeworkArray[count].subject;
        inputFile >> homeworkArray[count].title;
        inputFile >> homeworkArray[count].description;
        inputFile >> homeworkArray[count].dueDate;
        inputFile >> homeworkArray[count].isCompleted;

        // If the file has not ended, add to the count of homework items.
        if (!inputFile.eof()) {
            count++;
        }
    }

    // close the file connection
    inputFile.close();
}

// Function to find an object in the homework array based on its title value
void searchByTitle(Homework* homeworkArray, int count) {
    string title;

    // Declare the iteration value
    int i = 0;
    cout << "What title would like to search: ";

    // Get the title from the user
    cin >> title;

    // While the iteration count is less the current number of homework structures
    while (i < count) {

        // If the searched tittle is the same as the current iterations homework structure title
        if (title == homeworkArray[i].title) {
            // Print out each sattriubte of the structre
            cout << "Subject: " << homeworkArray[i].subject << "\n";
            cout << "Title: " << homeworkArray[i].title << "\n";
            cout << "Description: " << homeworkArray[i].description << "\n";
            cout << "Due Date: " << homeworkArray[i].dueDate << "\n";
            cout << "Completed: " << (homeworkArray[i].isCompleted ? "Yes" : "No") << "\n";

            // If isCompleted is false
            if (!homeworkArray[i].isCompleted) {

                char completionChoice;

                // Ask the user if the homework is done and get their input
                cout << "Is this homework done? (y/n): ";
                cin >> completionChoice;

                // If their input was y or Y, set isCompleted to true
                if (completionChoice == 'y' || completionChoice == 'Y') {
                    homeworkArray[i].isCompleted = true;

                    // If their input was n or N, isCompleted to false
                } else if (completionChoice == 'n' || completionChoice == 'N') {
                    homeworkArray[i].isCompleted = false;

                    // If their input was wrong, tell the user so and set isCompleted to false
                } else {
                    cout << "Invalid choice. Assuming 'No' for completion status.\n";
                    homeworkArray[i].isCompleted = false;
                }
                // If isCompleted was true, print out the answer
            } else {
                cout << "This homework is already marked as completed.\n";
            }
            cout << "\n";

            // Exit the function because the title was found
            return;
        };

        // increment the control variable at the end of each loop
        i++;
    }

    // If the title wasn't found, print and error message
    cout << "Error, title of homework can not be found. \n";
}

