#include "Int2.h"

class MinesweeperCell
{
private:

    int2 m_Position;

public:

    MinesweeperCell(int2 position, bool isBomb);
    MinesweeperCell();

    int2 GetPosition();
    bool IsBomb() const;

    int m_NeighborBombCount = 0;
    bool m_Revealed = true;
    bool m_Flagged = false;
    bool IsFlagged() const;
private:
    bool m_IsBomb = false;

};