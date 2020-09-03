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

class TetrisBlock {

public:
	TetrisBlock(int size)
	{
		this->size = size;
		blockField = new SameGrid(size);
		centerPoint = new Point(size/2, size/2);
	}
	~TetrisBlock()
	{
		delete blockField;
		delete centerPoint;
	}
	void rotate()
	{
		blockField->rotate90Degrees();
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

protected:

	int size;
	SameGrid* blockField;
	Point* centerPoint;
};

class I_Block : public TetrisBlock {
public: 
	I_Block() : TetrisBlock(4)
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

class O_Block : public TetrisBlock {
public:
	O_Block() : TetrisBlock(2)
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

class J_Block : public TetrisBlock {
public:
	J_Block() : TetrisBlock(3)
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

class L_Block : public TetrisBlock {
public:
	L_Block() : TetrisBlock(3)
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

class S_Block : public TetrisBlock {
public:
	S_Block() : TetrisBlock(3)
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

class Z_Block : public TetrisBlock {
public:
	Z_Block() : TetrisBlock(3)
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


class T_Block : public TetrisBlock {
public:
	T_Block() : TetrisBlock(3)
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

class BlockFactory {
public :
	TetrisBlock* createTetrisBlock(int type)
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