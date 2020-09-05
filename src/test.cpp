#include <iostream>
#include "block.h"
#include "field.h"
#include <queue>
#include <string>
#include <windows.h>


using namespace std;

int main()
{
	TetrominoBlock* IBlock = new I_Block();
	TetrominoBlock* OBlock = new O_Block();
	TetrominoBlock* JBlock = new J_Block();
	TetrominoBlock* LBlock = new L_Block();
	TetrominoBlock* SBlock = new S_Block();
	TetrominoBlock* ZBlock = new Z_Block();
	TetrominoBlock* TBlock = new T_Block();

	queue<TetrominoBlock*> blockList;
	blockList.push(IBlock);
	blockList.push(OBlock);
	blockList.push(JBlock);
	blockList.push(ZBlock);
	blockList.push(TBlock);
	blockList.push(LBlock);
	blockList.push(SBlock);
	
	/*
	vector<TetrominoBlock*>::iterator iter;
	for (iter = blockList.begin(); iter != blockList.end(); iter++)
	{
		cout << (*iter)->getType() << endl;
		cout << (*iter)->toString() << endl;
		(*iter)->rotate();
		cout << (*iter)->getType() << endl;
		cout << (*iter)->toString() << endl;
		(*iter)->unrotate();
		cout << (*iter)->getType() << endl;
		cout << (*iter)->toString() << endl;
	}*/
	GameField* field = new GameField();
	cout << "FIELD" << endl;
	cout << field->toString() << endl;
	int elapsedSeconds = 0;
	int clearedLine = 0;
	bool isHit = false;
	TetrominoBlock* curBlock = blockList.front();
	blockList.pop();
	bool fieldOK = false;
	while (elapsedSeconds < 200)
	{
		clearedLine = 0;
		isHit = false;
		fieldOK = field->updateField(curBlock, clearedLine, isHit);
		cout << field->toString(curBlock) << endl;
		if (isHit)
		{
			blockList.push(TetrominoFactory::createTetrominoBlock(0));
			curBlock = blockList.front();
			blockList.pop();
		}
		if (!fieldOK)
		{
			cout << "----------------GAME END--------------------" << endl;
		}
		Sleep(100);
		elapsedSeconds++;
	}
	return 0;
}