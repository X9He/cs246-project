#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <vector>
#include <utility>
#include "item.h"
class Cell {

	char type;

	int row;

	int col;
	// xu hao
	int num;


public:
	Cell(char type, int row, int col, int num);

	~Cell();

	virtual void prettyPrint()=0;

	// decide if 
	virtual int canPass(char type)=0;

	//
	int getRow();

	int getCol();

};

#endif
