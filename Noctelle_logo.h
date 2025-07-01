#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>

#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>

class Noctelle {
private:
    HANDLE hConsole;

    void setColor(int color) {
        SetConsoleTextAttribute(hConsole, color);
    }

    void moveCursor(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(hConsole, coord);
    }

    // Print the Twitter logo in ASCII art
    void drawTwitterLogo() {
        int startX = 5, startY = 5;
        std::vector<std::string> bird = {
          
        };

        setColor(1); // Blue (for Twitter background)
        for (int i = 0; i < bird.size(); ++i) {
            moveCursor(startX, startY + i);
            std::cout << bird[i];
        }
        setColor(7); // Reset color
    }

public:
    Noctelle() {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    void printLogo() {
        system("cls");
        drawTwitterLogo();
    }
};

