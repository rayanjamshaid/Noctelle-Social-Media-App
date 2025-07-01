#include "Helper.h"

int Helper::getLastLineInteger(string filename)
{
    ifstream file(filename, ios::ate); // Open the file and seek to the end
    if (!file.is_open()) {
        // If file doesn't exist or can't be opened, return 0 as starting ID
        return 0;
    }

    // Handle empty file case
    if (file.tellg() == 0) {
        file.close();
        return 0;
    }

    string lastLine;
    char ch;

    // Navigate to the last line
    file.seekg(-1, ios::end); // Go to the end of the file

    // Check if file ends with newline
    if (file.peek() == '\n') {
        file.seekg(-2, ios::cur); // Move back past the newline
    }

    // Find the start of the last line
    while (file.tellg() > 0) {
        file.get(ch);
        if (ch == '\n') break; // Stop when a newline is found
        if (file.tellg() > 1) { // Make sure we don't go before the start
            file.seekg(-2, ios::cur); // Move two steps back
        }
        else {
            file.seekg(0, ios::beg); // If at the beginning, stay there
            break;
        }
    }

    getline(file, lastLine); // Read the last line
    file.close();

    // Extract the integer at the beginning
    int firstInt = 0; // Default to 0 if parsing fails
    istringstream iss(lastLine);
    iss >> firstInt;

    return firstInt;
}

void Helper::add_post_record(string filename, int id, int likes, int d, int m, int y,
    string text, string activity_type, string activity_value)
{
    ofstream fw(filename, ios::app);
    

    
    fw << id << " " << likes << " " << d << " " << m << " " << y << " "
        << text << "," << activity_type << "," << activity_value << ",";

    
    fw << endl; // Add newline at the end of the record
    fw.close();
}