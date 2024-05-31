#include <iostream>
#include "MinesweeperGrid.h"
#include "Int2.h"
int main() {
    unsigned int width = 20;
    unsigned int height = 10;
    float bombsPercentage = 0.2f;
    MinesweeperGrid grid(width, height, bombsPercentage);

    bool gameOver = false;
    bool gameWon = false;


    while (!gameOver && !gameWon) {
        grid.PrintGrid();

        int x, y;
        std::string action;
        std::cout << "Enter coordinates to click (x y), type flag (flag x y), or type 'exit' to quit: ";
        std::cin >> action;

        if (action == "exit") {
            gameOver = true;
            break;
        }

        try {
            if (action == "flag") {
                std::cin >> x >> y;
                --x;
                --y;
                int2 flagLocation(x, y);
                grid.FlagCell(flagLocation);
            } else {
                x = std::stoi(action);
                std::cin >> y;
                --x;
                --y;
                int2 clickLocation(x, y);
                grid.ClickCell(clickLocation);
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
                            std::cout << "Congratulations! You have won the game!" << std::endl;
                            gameOver = true;
                            gameWon = true;
                        }
                    }
                }
            }
        } catch (std::exception& e) {
            std::cout << "Invalid input. Please enter valid coordinates or type 'exit' to quit." << std::endl;
            continue;
        }
    }

    // Show all bombs when the game is over
    if (gameOver) {
        std::cout << "Game Over! Revealing all bombs:" << std::endl;
        grid.RevealAllBombs();
        grid.PrintGrid();
    }

    return 0;
}
