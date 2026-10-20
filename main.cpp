/*
 * Carlos Campos
 * CS 210 Project Three
 * October 2026
 *
 * main.cpp
 * Corner Grocer item tracking program
 * Loads the day's purchase records, creates frequency.dat as a backup,
 * and runs a menu that lets the user search, list, and graph item counts.
 */

#include <iostream>
#include <limits>
#include <string>

#include "GroceryTracker.h"

using namespace std;

// File names used by the program
const string INPUT_FILE_NAME = "CS210_Project_Three_Input_File.txt";
const string BACKUP_FILE_NAME = "frequency.dat";

// Displays the menu options.
void DisplayMenu() {
    cout << "===== Corner Grocer Item Tracker =====" << endl;
    cout << "1. Look up how often an item was purchased" << endl;
    cout << "2. Show purchase counts for all items" << endl;
    cout << "3. Show purchase histogram for all items" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice (1-4): ";
}

// Reads a menu choice and keeps asking until it is a whole number from 1 to 4.
int GetMenuChoice() {
    int choice;
    while (true) {
        if (cin >> choice && choice >= 1 && choice <= 4) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
        // Invalid input: reset cin, discard the bad line, and ask again
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter a number from 1 to 4: ";
    }
}

int main() {
    GroceryTracker tracker;

    // Load the purchase records. The program cannot continue without them.
    if (!tracker.LoadItems(INPUT_FILE_NAME)) {
        cout << "Error: Could not open " << INPUT_FILE_NAME << endl;
        return 1;
    }

    // Create the backup file automatically at startup
    if (!tracker.WriteBackupFile(BACKUP_FILE_NAME)) {
        cout << "Warning: Could not create " << BACKUP_FILE_NAME << endl;
    }

    int choice = 0;
    while (choice != 4) {
        DisplayMenu();
        choice = GetMenuChoice();

        switch (choice) {
        case 1: {
            string itemName;
            cout << "Enter the item to look up: ";
            getline(cin, itemName);
            cout << endl << itemName << " was purchased "
                << tracker.GetItemFrequency(itemName) << " time(s)." << endl << endl;
            break;
        }
        case 2:
            tracker.PrintAllFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        }
    }

    return 0;
}