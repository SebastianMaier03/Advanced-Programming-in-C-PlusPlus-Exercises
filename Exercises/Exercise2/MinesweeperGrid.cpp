#include "MinesweeperGrid.h"
#include <cstdlib>
#include <ctime>
#include "Int2.h"
MinesweeperGrid::MinesweeperGrid(unsigned int width, unsigned int height, float bombsPercentage)
        : m_Width(width), m_Height(height), m_BombsPercentage(bombsPercentage) {
    InitializeCells();
}

void MinesweeperGrid::InitializeCells() {
    m_Values.clear();
    m_Values.resize(m_Width * m_Height);

    srand(static_cast<unsigned int>(time(nullptr)));

    unsigned int totalCells = m_Width * m_Height;
    unsigned int numBombs = static_cast<unsigned int>(totalCells * m_BombsPercentage);

    for (unsigned int i = 0; i < numBombs; ++i) {
        unsigned int randomIndex = rand() % totalCells;
        m_Values[randomIndex] = MinesweeperCell(GetLocationFromIndex(randomIndex), true);
    }

    for (unsigned int i = 0; i < totalCells; ++i) {
        if (!IsBomb(i)) {
            int2 location = GetLocationFromIndex(i);
            m_Values[i].m_NeighborBombCount = CalculateNeighboringBombsCount(location);
        }
    }
}

int MinesweeperGrid::CalculateNeighboringBombsCount(int2 location) {
    int count = 0;
    for (int y = -1; y <= 1; ++y) {
        for (int x = -1; x <= 1; ++x) {
            int2 neighborLocation(location.x + x, location.y + y);
            if (LocationInBounds(neighborLocation) && IsBomb(neighborLocation))
                ++count;
        }
    }
    return count;
}

bool MinesweeperGrid::IsBomb(unsigned int index) const {
    if (index >= m_Values.size()) {
        return false;
    }
    return m_Values[index].IsBomb();
}

bool MinesweeperGrid::IsBomb(int2 location) const {
    unsigned int index = GetIndexFromLocation(location);
    return IsBomb(index);
}

int MinesweeperGrid::GetNeighborBombCount(unsigned int index) const {
    if (index >= m_Values.size()) {
        return 0; 
    }
    return m_Values[index].m_NeighborBombCount;
}

int MinesweeperGrid::GetNeighborBombCount(int2 location) const {
    unsigned int index = GetIndexFromLocation(location);
    return GetNeighborBombCount(index);
}

unsigned int MinesweeperGrid::GetIndexFromLocation(int2 location) const {
    return location.y * m_Width + location.x;
}

int2 MinesweeperGrid::GetLocationFromIndex(unsigned int index) const {
    unsigned int x = index % m_Width;
    unsigned int y = index / m_Width;
    return int2(x, y);
}

unsigned int MinesweeperGrid::GetWidth() const {
    return m_Width;
}

unsigned int MinesweeperGrid::GetHeight() const {
    return m_Height;
}

bool MinesweeperGrid::IndexInBounds(unsigned int index) const {
    return index < m_Width * m_Height;
}

bool MinesweeperGrid::LocationInBounds(int2 location) const {
    return location.x >= 0 && location.x < static_cast<int>(m_Width) &&
           location.y >= 0 && location.y < static_cast<int>(m_Height);
}

void MinesweeperGrid::PrintGrid() const {
    std::cout << "+";
    for (unsigned int i = 0; i < m_Width; ++i) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

    for (unsigned int y = 0; y < m_Height; ++y) {
        std::cout << "|";
        for (unsigned int x = 0; x < m_Width; ++x) {
            unsigned int index = y * m_Width + x;
            if (IsBomb(index)) {
                std::cout << "X";
            } else {
                int neighborBombCount = GetNeighborBombCount(index);
                if (neighborBombCount > 0) {
                    std::cout << neighborBombCount;
                } else {
                    std::cout << " ";
                }
            }
        }
        std::cout << "|" << std::endl;
    }

    std::cout << "+";
    for (unsigned int i = 0; i < m_Width; ++i) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;
}


