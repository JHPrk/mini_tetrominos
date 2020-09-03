#pragma once
#include <iostream>


class Grid
{
public:
	Grid(int width, int height)
	{
		this->width = width;
		this->height = height;
		gridField = new bool *[height];
		for (int i = 0; i < height; i++)
		{
			gridField[i] = new bool[width];
			memset(gridField[i], false, width * sizeof(bool));
		}
	}
	~Grid()
	{
		for (int i = 0; i < height; i++)
		{
			delete[] gridField[i];
		}
		delete[] gridField;
	}
	bool** getGrid()
	{
		return gridField;
	}
	bool getFieldValue(int x, int y)
	{
		return gridField[x][y];
	}
	void setFieldValue(int x, int y, bool value)
	{
		gridField[x][y] = value;
	}
	string toString()
	{
		string str = "";
		for (int i = 0; i < height; i++)
		{
			if (i > 0)
			{
				str += "\n";
			}
			str += "| ";
			for (int j = 0; j < width; j++)
			{
				str += (gridField[i][j] ? "1" : "0");
				str += " | ";
			}
		}
		return str;
	}
	int getWidth()
	{
		return width;
	}
	int getHeight()
	{
		return height;
	}

protected:
	int width;
	int height;
	bool** gridField;
};

class SameGrid : public Grid
{
public :
	SameGrid(int size) : Grid(size, size)
	{
		this->size = size;
	}
	void rotate90Degrees()
	{
		for (int i = 0; i<size / 2; i++)
			for (int j = 0; j<(size + 1) / 2; j++)
				cyclic_roll(gridField[i][j], gridField[size - 1 - j][i], gridField[size - 1 - i][size - 1 - j], gridField[j][size - 1 - i]);
	}
private :

	void cyclic_roll(bool &a, bool &b, bool &c, bool &d)
	{
		bool temp = a;
		a = b;
		b = c;
		c = d;
		d = temp;
	}
	int size;
};