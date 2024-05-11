#include "MinesweeperCell.h"

MinesweeperCell::MinesweeperCell(int2 position, bool isBomb) : m_Position(position), m_IsBomb(isBomb) {}

MinesweeperCell::MinesweeperCell() {}

int2 MinesweeperCell::GetPosition() {
    return m_Position;
}

bool MinesweeperCell::IsBomb() const {
    return m_IsBomb;
}
