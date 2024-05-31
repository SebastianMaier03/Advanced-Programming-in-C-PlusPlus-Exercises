#include <iostream>
#include "MinesweeperGrid.h"
#include "Int2.h"
#include <windows.h>
void clear();

int main() {
    unsigned int width = 20;
    unsigned int height = 10;
    float bombsPercentage = 0.2f;
    MinesweeperGrid grid(width, height, bombsPercentage);

    bool gameOver = false;
    bool gameWon = false;

    HANDLE hIn;
    INPUT_RECORD InRec;
    DWORD NumRead;
    DWORD fdwMode;

    hIn = GetStdHandle(STD_INPUT_HANDLE);

    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

    if (!SetConsoleMode(hIn, fdwMode))
        return -1;

    grid.PrintGrid();

    while (!gameOver && !gameWon) {
        while (ReadConsoleInput(hIn, &InRec, 1, &NumRead) && NumRead > 0) {
                    COORD mPos = InRec.Event.MouseEvent.dwMousePosition;
                    DWORD mouseState = InRec.Event.MouseEvent.dwButtonState;

                    int x = mPos.X;
                    int y = mPos.Y;
                    --x;
                    --y;

                    int2 clickLocation(x, y);

                    if (mouseState & FROM_LEFT_1ST_BUTTON_PRESSED) {
                        grid.ClickCell(clickLocation);
                        clear();
                        grid.PrintGrid();
                        if (grid.IsBomb(clickLocation)) {
                            std::cout << "Game Over! You clicked on a bomb." << std::endl;
                            gameOver = true;
                        } else {
                            bool allNonBombCellsRevealed = true;
                            for (unsigned int i = 0; i < width * height; ++i) {
                                int2 location = grid.GetLocationFromIndex(i);
                                if (!grid.IsBomb(location) && !grid.IsRevealed(location)) {
                                    allNonBombCellsRevealed = false;
                                    break;
                                }
                            }
                            if (allNonBombCellsRevealed) {
                                bool allBombCellsFlagged = true;
                                for (unsigned int i = 0; i < width * height; ++i) {
                                    int2 location = grid.GetLocationFromIndex(i);
                                    if (grid.IsBomb(location) && !grid.IsCellFlagged(location)) {
                                        allBombCellsFlagged = false;
                                        break;
                                    }
                                }
                                if (allBombCellsFlagged) {
                                    gameWon = true;
                                }
                            }
                        }
                    } else if (mouseState & RIGHTMOST_BUTTON_PRESSED) {
                        grid.FlagCell(clickLocation);
                        clear();
                        grid.PrintGrid();
                    }
                    break;
                }
            }
        if (gameOver) {
            std::cout << "Game Over! Revealing all bombs:" << std::endl;
            grid.RevealAllBombs();
            grid.PrintGrid();
            system("pause");
        }
        if (gameWon) {
            std::cout << "Congratulations! You have won the game!" << std::endl;
            system("pause");
        }
    return 0;
}
void clear() {
    HANDLE console;
    CONSOLE_SCREEN_BUFFER_INFO screen;
    COORD origin;
    DWORD chars_written;

    console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &screen);

    origin.X = 0;
    origin.Y = 0;
    FillConsoleOutputCharacter(console, 32, screen.dwSize.X * screen.dwSize.Y, origin, &chars_written);
    FillConsoleOutputAttribute(console, screen.wAttributes, screen.dwSize.X * screen.dwSize.Y, origin, &chars_written);

    SetConsoleCursorPosition(console, origin);
}