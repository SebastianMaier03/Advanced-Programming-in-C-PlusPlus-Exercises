# Exercise 2: Classes and operators

- These exercises teach you the basics of classes and structs
- Please name everything as it is described in the exercises.

---

# 1. Exercise 2.1: Int2

Create a struct with the following header file `Int2.h`:

```cpp
#pragma once

struct int2
{
	int x;
	int y;

	int2();
	int2(int _x, int _y);
}
```

- Create a corresponding `.cpp` file, that includes the header file and contains implementations for all of the structs functions.
- Implement the default constructor to initialize the member variables to `0`.
- Implement the constructor `int2(int _x, int _y)`, so that the member variables `x` and `y` are initialized to the values of `_x` and `_y` respectively

# Exercise 2.2: Grid


- Create the corresponding `.cpp` file to this header file. 
- The constructor should initialize `m_Position` to the value of `position`
- `GetPosition()` should simply return `m_Position`

```cpp
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
```

---

- Create the corresponding `.cpp` file for this header file.

```cpp
#pragma once

#include <vector>
#include "Cell.h"
#include "Int2.h"

class Grid
{
public:
	Grid(unsigned int width, unsigned int height); //initialize m_Width and m_Height and call InitializeCells()

	void InitializeCells(); //set all cells to be not blocked and initialize their positions
	bool GetValueAtIndex(unsigned int index); //retrieve whether or not a cell at a given index is blocked
	bool GetValueAtLocation(int2 location); //retrieve whether or not a cell at a given location is blocked
	void SetValueAtIndex(unsigned int index, bool value); //set the blocked value of a cell at a given index
	void SetValueAtLocation(int2 location, bool value); //set the blocked value of a given location
	unsigned int GetIndexFromLocation(int2 location); //convert a location to an index
	int2 GetLocationFromIndex(unsigned int index); //convert an index into a location
	unsigned int GetWidth(); //retrieve the width of the grid
	unsigned int GetHeight(); //retrieve the height of the grid
	bool IndexInBounds(unsigned int index); //check, whether a given index is in the bounds of the grid
	bool LocationInBounds(int2 location); //check, whether a given location is in the bounds of the grid
	
	/*
	Print the grid in the following format (1 for blocked, 0 for free):
	Grid:
	0 0 0 0 0
	0 1 0 0 0
	0 1 1 1 1
	*/
	void Print(); 

private:
	unsigned int m_Width;
	unsigned int m_Height;

	std::vector<Cell> m_Values;
};
```

`Grid` is a class that represents a two dimensional array and provides useful functionality to allow easy access and manipulation of such arrays. In later exercises this class will be very useful.

The class stores the two dimensional array in a single dimension.

Here is an example grid of width `3` and height `2`. This grid can be stored in a single dimension of the length `width * height` (6). 
Usually we would want to access a 2 dimensional array with a 2 dimensional index, e.g. `[1][0]` or in our case, using our `int2` class (in the context of a grid called `location`). To convert such an index to work with our one-dimensional array, 
we can use the following formula:
`index = grid.height * int2.x + int2.y`

We can also find out using a given index and our `width` and `height`, which location (`int2`) this index corresponds to.
This can be useful, for example if we want to initialize the values of our grid, using a one dimensional loop.

Implement the functions of the `Grid` class, according to the comments behind them

Since we are dealing with arrays here, make sure to always perform bounds checks to ensure that the program does not crash, when we use invalid indices. If such a case occurs, log it to the console!

# Submission

Submission is due until 05.05. 23:59. Please put all `.cpp` and `.h` files in the same folder and upload them as a `.zip` into your personal folder found here (https://docs.google.com/spreadsheets/d/1zemIwLL1jsERbjPznQ-w-f5jOn5tZb2JrHSRPuqDLXI/edit#gid=0)
