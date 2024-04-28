#include "Cell.h"
#include <iostream>
#include "Int2.h"

Cell::Cell(int2 position) : m_Position(position) {}

int2 Cell::GetPosition() {
    return m_Position;
}
int main() {
    int2 position(3, 4);
    Cell cell(position);

    int2 cellPosition = cell.GetPosition();
    std::cout << cellPosition.x << ", " << cellPosition.y ;

    return 0;
}