// #pragma once
#include "olcPixelGameEngine.h"




/*
 * create by pokpoongryu
 *
 * this class is to the tile.
*/

#define TOTAL_GRID_W 9
#define TOTAL_GRID_H 9


class CBlock
{
public:
	//해당 타일이 표시될 위치
	int mX = 0;
	int mY = 0;
	//해당 타일의 너비 높이 
	int mWidth = 0;
	int mHeight = 0;


	olc::PixelGameEngine *mpPGE = nullptr;

public:
	//Block이 Screen에 고정된 위치, Block의 한 변의 길이
	void CreateRyu(int tX, int tY, int tWidth = 32, int tHeight = 32);
	void DestroyRyu();
	void UpdateRyu();
	//월드의 속성그리드를 참고하여 표시할 데이터를 선택, ???
	void DisplayRyu(int tGrid[][TOTAL_GRID_W], int tX, int tY);

	void SetPGE(olc::PixelGameEngine *tpPGE);

};

