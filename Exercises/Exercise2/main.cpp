#include "Int2.h"
#include "Cell.h"
#include "Grid.h"

#include <iostream>

int main() {
    int2 point1;
    std::cout << point1.x << ", " << point1.y << std::endl;

    int2 point2(5, 8);

    std::cout <<  point2.x << ", "<< point2.y << std::endl;
    int2 position(3, 4);
    Cell cell(position);

    int2 cellPosition = cell.GetPosition();
    std::cout << cellPosition.x << ", " << cellPosition.y ;

    std::cout << std::endl;

    Grid grid(5, 4);

    grid.SetValueAtLocation(int2(1, 6), true);
    grid.SetValueAtLocation(int2(2, 2), true);
    grid.SetValueAtLocation(int2(3, 3), true);
    grid.SetValueAtLocation(int2(4, 4), true);
    grid.SetValueAtLocation(int2(3, 3), true);

    grid.SetValueAtLocation(int2(1, 3), true);


    grid.Print();

    std::cout << "Value at index 6: " << grid.GetValueAtIndex(6) << std::endl;

    std::cout << "Value at location (2, 2): " << grid.GetValueAtLocation(int2(2, 2)) << std::endl;

    std::cout << "Index for location (3, 2): " << grid.GetIndexFromLocation(int2(3, 2)) << std::endl;


    int2 location = grid.GetLocationFromIndex(13);
    std::cout << "Location for index 13: (" << location.x << ", " << location.y << ")" << std::endl;

    return 0;
}