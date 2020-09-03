#pragma once
#include "point.h"
#include "block.h"
#include <vector>


class GameField : public Grid
{
public:
	GameField(int width = 10, int height = 30) : Grid(width, height) {
	}
	void updateField(int input)
	{
		if (canMoveDown())
		{
		}
	}
	void rotateTetrisBlock()
	{

	}
	void drawBlock()
	{

	}
	bool canMoveDown()
	{
		Grid* tetrisField = currentBlock->getField();
		bool** tetriGrid = tetrisField->getGrid();
		int size = tetrisField->getWidth();
		int check_start_x = currentCursor->getX() - size / 2;
		int check_start_y = currentCursor->getY() - size / 2;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (checkFill(check_start_x + i, check_start_y + j))
				{
					return false;
				}
			}
		}
		return true;
	}
	int checkLine()
	{
		for (int i = height - 1; i >= 0 ; i--)
		{
			int trueCnt = 0;
			for (int j = 0; j < width; j++)
			{
				if (checkFill(i, j + 1))
				{
					trueCnt++;
				}
			}
			if (trueCnt == width)
				return i;
		}
	}
	void moveDownClearedLine(int cleared_line)
	{
		for (int i = 0; i < cleared_line; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (!checkFill(i, j + 1))
				{
					gridField[i][j] = false;
					gridField[i][j + 1] = true;
				}
			}
		}
	}
	bool checkCollision()
	{

	}
	bool checkFill(int target_x, int target_y)
	{
		if (target_x < 0 || target_x >= height || target_y < 0 || target_y >= width)
			return true;
		return gridField[target_x][target_y];
	}
	void lineClear(int lineNumber)
	{

	} 
	
protected:
	vector<TetrisBlock*> blockList;
	FieldPoint* currentCursor;
	TetrisBlock* currentBlock;
	
};