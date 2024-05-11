#include "Int2.h"
#include "MinesweeperGrid.h"

#include <iostream>

int main() {
    // Exercise 3.1
    int2 a(3, 4);
    int2 b(2, 3);
    int2 c = a + b;		//expected value of c: (x= 5,y= 7)
    int2 d = a - c;		//expected value of d: (x=-2,y=-3)
    b = d * a;		    //expected value of b: (x=-6,y=-12)
    int2 e = b / c;		//expected value of e: (x=-1,y=-1)
    a.x = 2;		    //expected value of a: (x= 2,y= 4)
    c *= a;			    //expected value of c: (x=10,y=28)
    c *= 2;			    //expected value of c: (x=20,y=56)
    d += a;			    //expected value of d: (x= 0,y= 1)
    d -= b;			    //expected value of d: (x= 6,y=13)
    d.y = 6;		    //expected value of d: (x= 6,y= 6)

    std::cout << d << std::endl; //expected output: (6|6)
    std::cout << e << std::endl; //expected output: (6|6)


    // Create a MinesweeperCell
    MinesweeperCell cell1({3, 5}, false); // Cell at position (3, 5), not a bomb
    MinesweeperCell cell2({2, 4}, true);  // Cell at position (2, 4), is a bomb

    // Display cell information
    std::cout << "Cell 1 position: (" << cell1.GetPosition().x << ", " << cell1.GetPosition().y << ")" << std::endl;
    std::cout << "Cell 1 is a bomb: " << (cell1.IsBomb() ? "Yes" : "No") << std::endl;
    std::cout << "Cell 2 position: (" << cell2.GetPosition().x << ", " << cell2.GetPosition().y << ")" << std::endl;
    std::cout << "Cell 2 is a bomb: " << (cell2.IsBomb() ? "Yes" : "No") << std::endl;

    // Create a Minesweeper grid with width 5, height 5, and 20% bombs
    MinesweeperGrid grid(20, 20, 0.2f);

    // Print the grid
    std::cout << "Minesweeper Grid:" << std::endl;
    grid.PrintGrid();

    return 0;



}