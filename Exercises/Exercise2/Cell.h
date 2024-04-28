#pragma once
#include "Int2.h"

class Cell
{
private:
    int2 m_Position;

public:
    Cell(int2 position);

    int2 GetPosition();

    bool blocked = false;
};
