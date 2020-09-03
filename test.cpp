#include <iostream>
#include "block.h"
#include "field.h"
#include <vector>
#include <string>


using namespace std;

int main()
{
	TetrisBlock* IBlock = new I_Block();
	TetrisBlock* OBlock = new O_Block();
	TetrisBlock* JBlock = new J_Block();
	TetrisBlock* LBlock = new L_Block();
	TetrisBlock* SBlock = new S_Block();
	TetrisBlock* ZBlock = new Z_Block();
	TetrisBlock* TBlock = new T_Block();

	vector<TetrisBlock*> blockList;
	blockList.push_back(IBlock);
	blockList.push_back(OBlock);
	blockList.push_back(JBlock);
	blockList.push_back(ZBlock);
	blockList.push_back(TBlock);
	blockList.push_back(LBlock);
	blockList.push_back(SBlock);
	
	vector<TetrisBlock*>::iterator iter;
	for (iter = blockList.begin(); iter != blockList.end(); iter++)
	{
		cout << (*iter)->getType() << endl;
		cout << (*iter)->toString() << endl;
		(*iter)->rotate();
		cout << (*iter)->getType() << endl;
		cout << (*iter)->toString() << endl;
	}
	GameField* field = new GameField();
	cout << "FIELD" << endl;
	cout << field->toString() << endl;
	return 0;
}