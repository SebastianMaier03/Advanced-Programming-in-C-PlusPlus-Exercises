#include "Cell.h"
#include "Int2.h"

Cell::Cell(int2 position) : m_Position(position) {}

int2 Cell::GetPosition() {
    return m_Position;
}
