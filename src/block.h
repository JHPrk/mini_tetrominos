#pragma once
#include "point.h"
#include "grid.h"



class Block
{
public :
	virtual void rotate() = 0;
	virtual Grid* getShape() = 0;
	virtual string getType() = 0;
	virtual string toString() = 0;

protected:
	int size;
};

class TetrominoBlock {

public:
	TetrominoBlock(int size)
	{
		this->size = size;
		blockField = new SameGrid(size);
		centerPoint = new Point(size/2, size/2);
	}
	~TetrominoBlock()
	{
		delete blockField;
		delete centerPoint;
	}
	void rotate()
	{
		blockField->rotate90Degrees();
	}
	void unrotate()
	{
		blockField->rotateMinus90Degrees();
	}
	Grid* getField()
	{
		return blockField;
	}
	virtual string getType() = 0;
	string toString()
	{
		return blockField->toString();
	}
	Point* getCenterPoint()
	{
		return centerPoint;
	}
	int getSize()
	{
		return size;
	}
	bool checkFill(int x,int y)
	{
		return blockField->getFieldValue(x, y);
	}

protected:

	int size;
	SameGrid* blockField;
	Point* centerPoint;
};

class I_Block : public TetrominoBlock {
public: 
	I_Block() : TetrominoBlock(4)
	{
		for (int i = 0; i < size; i++)
		{
			blockField->setFieldValue(i, 2, true);
		}
	}
	string getType()
	{
		return "I_Block";
	}
};

class O_Block : public TetrominoBlock {
public:
	O_Block() : TetrominoBlock(2)
	{
		for (int i = 0; i < size; i++)
		{
			blockField->setFieldValue(0, i, true);
			blockField->setFieldValue(1, i, true);
		}
	}
	string getType()
	{
		return "O_Block";
	}
};

class J_Block : public TetrominoBlock {
public:
	J_Block() : TetrominoBlock(3)
	{
		blockField->setFieldValue(0, 2, true);
		for (int i = 0; i < size; i++)
		{
			blockField->setFieldValue(1, i, true);
		}
	}
	string getType()
	{
		return "J_Block";
	}
};

class L_Block : public TetrominoBlock {
public:
	L_Block() : TetrominoBlock(3)
	{
		blockField->setFieldValue(0, 0, true);
		for (int i = 0; i < size; i++)
		{
			blockField->setFieldValue(1, i, true);
		}
	}
	string getType()
	{
		return "L_Block";
	}

};

class S_Block : public TetrominoBlock {
public:
	S_Block() : TetrominoBlock(3)
	{
		for (int i = 0; i < 2; i++)
		{
			blockField->setFieldValue(0, i + 1, true);
			blockField->setFieldValue(1, i, true);
		}
	}
	string getType()
	{
		return "S_Block";
	}

};

class Z_Block : public TetrominoBlock {
public:
	Z_Block() : TetrominoBlock(3)
	{
		for (int i = 0; i < 2; i++)
		{
			blockField->setFieldValue(0, i, true);
			blockField->setFieldValue(1, i + 1, true);
		}
	}
	string getType()
	{
		return "Z_Block";
	}

};


class T_Block : public TetrominoBlock {
public:
	T_Block() : TetrominoBlock(3)
	{
		blockField->setFieldValue(0, 1, true);
		for (int i = 0; i < size; i++)
		{
			blockField->setFieldValue(1, i, true);
		}
	}
	string getType()
	{
		return "T_Block";
	}

};

class TetrominoFactory {
public :
	static TetrominoBlock* createTetrominoBlock(int type)
	{
		switch (type) 
		{
		case 0: return new I_Block(); break;
		case 1: return new O_Block(); break;
		case 2: return new J_Block(); break;
		case 3: return new L_Block(); break;
		case 4: return new S_Block(); break;
		case 5: return new Z_Block(); break;
		case 6: return new T_Block(); break;
		default: throw exception("TETRIS BLOCK TYPE ERROR!"); break;
		}
	}
};