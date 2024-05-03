#include "Grid.h"
#include <iostream>

Grid::Grid(unsigned int width, unsigned int height)
        : m_Width(width), m_Height(height) {
    InitializeCells();
}

void Grid::InitializeCells() {
    m_Values.clear();
    m_Values.resize(m_Width * m_Height, Cell(int2(0, 0)));
    for (unsigned int y = 0; y < m_Height; ++y) {
        for (unsigned int x = 0; x < m_Width; ++x) {
            unsigned int index = y * m_Width + x;
            m_Values[index] = Cell(int2(x, y));
        }
    }
}

bool Grid::GetValueAtIndex(unsigned int index) {
    if (!IndexInBounds(index)) {
        std::cout << "Index out of bounds!" << std::endl;
        return false;
    }
    return m_Values[index].blocked;
}

bool Grid::GetValueAtLocation(int2 location) {
    unsigned int index = GetIndexFromLocation(location);
    return GetValueAtIndex(index);
}

void Grid::SetValueAtIndex(unsigned int index, bool value) {
    if (!IndexInBounds(index)) {
        std::cout << "Index out of bounds!" << std::endl;
        return;
    }
    m_Values[index].blocked = value;
}

void Grid::SetValueAtLocation(int2 location, bool value) {
    unsigned int index = GetIndexFromLocation(location);
    SetValueAtIndex(index, value);
}

unsigned int Grid::GetIndexFromLocation(int2 location) {
    if (!LocationInBounds(location)) {
        std::cout << "Location out of bounds!" << std::endl;
        return 0;
    }
    return location.y * m_Width + location.x;
}

int2 Grid::GetLocationFromIndex(unsigned int index) {
    if (!IndexInBounds(index)) {
        std::cout << "Index out of bounds!" << std::endl;
        return int2(0, 0);
    }
    unsigned int x = index % m_Width;
    unsigned int y = index / m_Width;
    return int2(x, y);
}

unsigned int Grid::GetWidth() {
    return m_Width;
}

unsigned int Grid::GetHeight() {
    return m_Height;
}

bool Grid::IndexInBounds(unsigned int index) {
    return index < m_Width * m_Height;
}

bool Grid::LocationInBounds(int2 location) {
    return location.x >= 0 && location.x < static_cast<int>(m_Width) &&
           location.y >= 0 && location.y < static_cast<int>(m_Height);
}

void Grid::Print() {
    std::cout << "Grid:" << std::endl;
    for (unsigned int y = 0; y < m_Height; ++y) {
        for (unsigned int x = 0; x < m_Width; ++x) {
            unsigned int index = y * m_Width + x;
            std::cout << GetValueAtIndex(index) << " ";
        }
        std::cout << std::endl;
    }
}
