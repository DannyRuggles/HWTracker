#include "homework.h"
#include <iostream>

using namespace std;

int main() {
    //Maximum number of homework entries the program can handle
    const int MAX_HOMEWORK = 100;

    //Array to store homework
    Homework homeworkArray[MAX_HOMEWORK];


    // Counter to keep track of the number of homework entries
    int homeworkCount = 0;

    // User's menu choice
    int choice;

    // File name for saving and loading homework entries
    string fileName = "homework.txt"; // Save file name


    // Menu loop that continues until the user chooses to exit
    do {
        // Display the menu options
        displayMenu();

        // Prompt the user to enter their choice
        cout << "Enter your choice (1-6): ";
        cin >> choice;


        // Switch statement to execute the chosen menu option
        switch (choice) {
            case 1:
                // Add new homework entry
                addHomework(homeworkArray, homeworkCount);
                break;
            case 2:
                // View all homework entries
                viewHomework(homeworkArray, homeworkCount);
                break;
            case 3:
                // Save homework entries to a file
                saveToFile(homeworkArray, homeworkCount, fileName);
                break;
            case 4:
                // Load homework entries from a file
                loadFromFile(homeworkArray, homeworkCount, fileName);
                break;
            case 5:
                // Search for a homework entry by title
                searchByTitle(homeworkArray, homeworkCount);
                break;
            case 6:
                // Exit the program
                cout << "Exiting program.\n";
                break;
            default:
                // Invalid choice message
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 6);// Continue the loop until the user chooses to exit

    // End of the program
    return 0;
}
