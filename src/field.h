#pragma once
#include "point.h"
#include "block.h"
#include <vector>

#define ORIGIN_X 4
#define ORIGIN_Y 0

class GameField : public Grid
{
public:
	GameField(int width = 10, int height = 30) : Grid(width, height) {
		currentCursor = new FieldPoint(width, height, ORIGIN_X, ORIGIN_Y);
	}
	~GameField() {
		delete currentCursor;
	}
	bool updateField(TetrominoBlock* currentBlock, int& clearedLine, bool& isHit)
	{
		if (canMoveDown(currentBlock))
		{
			currentCursor->moveDownPoint();
		}
		else
		{
			if (currentCursor->getX() == ORIGIN_X && currentCursor->getY() == ORIGIN_Y)
				return false;
			hitBlock(currentBlock);
			int n = 0;
			while ((n = checkLine()) != -1)
			{
				clearedLine++;
				lineClear(n);
				moveDownClearedLine(n);
			}
			isHit = true;
		}
		return true;
	}
	bool canRotate(TetrominoBlock* currentBlock)
	{
		currentBlock->rotate();
			
		currentBlock->unrotate();
		return true;
	}
	bool hitBlock(TetrominoBlock* currentBlock)
	{
		int blockSize = currentBlock->getSize();
		int check_start_i = currentCursor->getY() - blockSize / 2;
		int check_start_j = currentCursor->getX() - blockSize / 2;
		for (int i = 0; i < blockSize; i++)
		{
			for (int j = 0; j < blockSize; j++)
			{
				if (currentBlock->checkFill(i, j))
				{
					gridField[check_start_i + i][check_start_j + j] = true;
				}
			}
		}
		currentCursor->setPoint(ORIGIN_X, ORIGIN_Y);
		return true;
	}
	bool canMoveDown(TetrominoBlock* currentBlock)
	{
		int blockSize = currentBlock->getSize();
		int check_start_x = currentCursor->getX() - blockSize / 2;
		int check_start_y = currentCursor->getY() - blockSize / 2;
		for (int i = 0; i < blockSize; i++)
		{
			for (int j = 0; j < blockSize; j++)
			{
				int target_x = check_start_x + j;
				int target_y = check_start_y + i + 1;
				if (target_x < 0 || target_x >= width || target_y < 0)
					continue;
				if (currentBlock->checkFill(i, j) && checkFill(target_y, target_x))
				{
					return false;
				}
			}
		}
		return true;
	}
	int checkLine()
	{
		int trueCnt = 0;
		for (int i = height - 1; i >= 0; i--)
		{
			trueCnt = 0;
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
		return -1;
	}
	void moveDownClearedLine(int cleared_line)
	{
		bool changeFlag = false;
		for (int i = cleared_line; i >= 1; i--)
		{
			changeFlag = false;
			for (int j = 0; j < width; j++)
			{
				if (checkFill(i - 1, j))
				{
					changeFlag = true;
					gridField[i][j] = true;
					gridField[i - 1][j] = false;
				}
			}
			if (!changeFlag)
				break;
		}
	}
	void lineClear(int lineNumber)
	{
		for (int index = 0; index < width; index++)
		{
			gridField[lineNumber][index] = false;
		}
	}
	bool checkFill(int target_x, int target_y)
	{
		if (checkBorder(target_x,target_y))
			return true;
		return gridField[target_x][target_y];
	}
	bool checkBorder(int target_x, int target_y)
	{
		return (target_x < 0 || target_x >= height || target_y < 0 || target_y >= width);
	}
	string toString(TetrominoBlock* currentBlock)
	{
		int blockSize = currentBlock->getSize();
		int check_start_j = currentCursor->getX() - blockSize / 2;
		int check_start_i = currentCursor->getY() - blockSize / 2;
		string str = "";
		for (int i = 0; i < width; i++)
		{
			str += "-----";
		}
		for (int i = 0; i < height; i++)
		{
			str += "\n";
			
			str += "| ";
			for (int j = 0; j < width; j++)
			{
				if (check_start_i <= i && check_start_i + blockSize > i && check_start_j <= j && check_start_j + blockSize > j)
				{
					str += (currentBlock->checkFill(i- check_start_i,j- check_start_j) || gridField[i][j] ? "[]" : "  ");
				}
				else
					str += (gridField[i][j] ? "[]" : "  ");
				str += " | ";
			}
		}
		str += "\n";
		for (int i = 0; i < width; i++)
		{
			str += "-----";
		}
		return str;
	}
	string toString()
	{
		return __super::toString();
	}
	
protected:
	FieldPoint* currentCursor;
	
};