#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

//1
// Define a structure to represent homework
struct Homework {
    string subject;
    string title; // the name of the assignment
    string description;
    string dueDate;
    bool isCompleted;
};
// Function to display the menu
void displayMenu() {
    cout << "Homework Tracker Menu\n";
    cout << "1. Add Homework\n";
    cout << "2. View Homework\n";
    cout << "3. Save Homework to File\n";
    cout << "4. Load Homework from File\n";
    cout << "5. Quit\n";
}

//2
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
}

//3
// Function to save homework to a file
void saveToFile(const Homework* homeworkArray, int count, const string& fileName) {
    ofstream outputFile(fileName);

    for (int i = 0; i < count; ++i) {
        outputFile << homeworkArray[i].subject << "\n";
        outputFile << homeworkArray[i].title << "\n";
        outputFile << homeworkArray[i].description << "\n";
        outputFile << homeworkArray[i].dueDate << "\n";
        outputFile << homeworkArray[i].isCompleted << "\n";
    }

    outputFile.close();
}
// Function to load homework from a file
void loadFromFile(Homework* homeworkArray, int& count, const string& fileName) {
    ifstream inputFile(fileName);

    if (!inputFile) {
        cout << "Error: Could not open file.\n";
        return;
    }

    while (inputFile >> homeworkArray[count].subject) {
        inputFile >> homeworkArray[count].title;
        inputFile >> homeworkArray[count].description;
        inputFile >> homeworkArray[count].dueDate;
        inputFile >> homeworkArray[count].isCompleted;

        count++;
    }

    inputFile.close();
}

//4
int main() {
    const int MAX_HOMEWORK = 100;
    Homework homeworkArray[MAX_HOMEWORK];
    int homeworkCount = 0;

    int choice;
    string fileName = "homework.txt"; // Save file name

    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addHomework(homeworkArray, homeworkCount);
                break;
            case 2:
                viewHomework(homeworkArray, homeworkCount);
                break;
            case 3:
                saveToFile(homeworkArray, homeworkCount, fileName);
                break;
            case 4:
                loadFromFile(homeworkArray, homeworkCount, fileName);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
