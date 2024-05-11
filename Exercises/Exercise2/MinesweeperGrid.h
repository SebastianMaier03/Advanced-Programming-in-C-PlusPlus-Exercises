#include <vector>
#include "MinesweeperCell.h"
#include "Int2.h"

class MinesweeperGrid
{
public:
    MinesweeperGrid(unsigned int width, unsigned int height, float bombsPercentage);

    void InitializeCells();
    int CalculateNeighboringBombsCount(int2 location);

    bool IsBomb(unsigned int index) const;
    bool IsBomb(int2 location) const;

    int GetNeighborBombCount(unsigned int index) const;
    int GetNeighborBombCount(int2 location) const;

    unsigned int GetIndexFromLocation(int2 location) const;
    int2 GetLocationFromIndex(unsigned int index) const;

    unsigned int GetWidth() const;
    unsigned int GetHeight() const;

    bool IndexInBounds(unsigned int index) const;
    bool LocationInBounds(int2 location) const;

    void PrintGrid() const;

private:
    unsigned int m_Width = 0;
    unsigned int m_Height = 0;
    float m_BombsPercentage = 0.0f;

    std::vector<MinesweeperCell> m_Values;
};
