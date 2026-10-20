/*
 * Carlos Campos
 * CS 210 Project Three
 * October 2026
 *
 * GroceryTracker.cpp
 * Implements the GroceryTracker class.
 */

#include "GroceryTracker.h"

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

// Reads one item per line and increments that item's count in the map.
bool GroceryTracker::LoadItems(const string& inputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        return false;
    }

    itemFrequencies.clear();
    string itemName;
    while (inputFile >> itemName) {
        itemFrequencies[itemName]++;  // Adds the item at 0 if new, then increments
    }

    inputFile.close();
    return true;
}

// Saves the accumulated counts as "Item Count" lines for backup.
bool GroceryTracker::WriteBackupFile(const string& outputFileName) const {
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        return false;
    }

    for (const auto& item : itemFrequencies) {
        outputFile << item.first << " " << item.second << endl;
    }

    outputFile.close();
    return true;
}

// Searches for the item without regard to capitalization. Returns 0 if not found.
int GroceryTracker::GetItemFrequency(const string& itemName) const {
    string searchName = ToLower(itemName);

    for (const auto& item : itemFrequencies) {
        if (ToLower(item.first) == searchName) {
            return item.second;
        }
    }
    return 0;
}

// Prints each item name and count in aligned columns.
void GroceryTracker::PrintAllFrequencies() const {
    cout << endl;
    for (const auto& item : itemFrequencies) {
        cout << left << setw(14) << item.first << right << setw(3) << item.second << endl;
    }
    cout << endl;
}

// Prints each item followed by one asterisk per purchase.
void GroceryTracker::PrintHistogram() const {
    cout << endl;
    for (const auto& item : itemFrequencies) {
        cout << left << setw(14) << item.first << string(item.second, '*') << endl;
    }
    cout << endl;
}

// Helper used for case insensitive comparisons.
string GroceryTracker::ToLower(const string& text) {
    string lowered = text;
    for (char& letter : lowered) {
        letter = static_cast<char>(tolower(static_cast<unsigned char>(letter)));
    }
    return lowered;
}