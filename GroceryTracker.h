/*
 * Carlos Campos
 * CS 210 Project Three
 * October 2026
 *
 * GroceryTracker.h
 * Corner Grocer item tracking program
 * Declares the GroceryTracker class, which reads the daily purchase
 * records, counts how often each item was bought, and backs the
 * counts up to frequency.dat.
 */

#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <map>
#include <string>

class GroceryTracker {
public:
    // Loads item counts from the input file. Returns false if the file can't be opened.
    bool LoadItems(const std::string& inputFileName);

    // Writes every item and its count to the backup file.
    bool WriteBackupFile(const std::string& outputFileName) const;

    // Menu option 1: returns how many times one item was purchased.
    int GetItemFrequency(const std::string& itemName) const;

    // Menu option 2: prints every item with its count.
    void PrintAllFrequencies() const;

    // Menu option 3: prints every item with a histogram bar.
    void PrintHistogram() const;

private:
    // Item name -> number of times purchased. std::map keeps items sorted alphabetically.
    std::map<std::string, int> itemFrequencies;

    // Converts a word to lowercase so lookups are not case sensitive.
    static std::string ToLower(const std::string& text);
};

#endif