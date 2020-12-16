#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"


#include <iostream>

#include "Tile.h"



using namespace std;

#define TOTAL_GRID_W 9
#define TOTAL_GRID_H 9

#define GRID_W 3
#define GRID_H 3


/*
 * create by pokpoongryu
 *
 * this class is to the tile.
*/


class Example : public olc::PixelGameEngine
{
private:

	//전체 그리드의 속성 배열
	int mGrid[TOTAL_GRID_H][TOTAL_GRID_W] = 
	{
		1,1,1, 1,0,0, 0,0,2,
		1,0,0, 0,0,0, 0,0,2,
		0,0,0, 0,0,1, 0,0,2,

		0,0,0, 0,0,1, 0,0,0,
		0,0,0, 0,0,1, 0,0,2,
		0,0,0, 0,0,1, 0,0,2,

		0,0,0, 0,0,1, 0,0,0,
		0,0,0, 0,0,0, 0,0,0,
		1,1,0, 0,0,1, 0,0,3,
	};
	// {
	// 	0,0,0, 0,0,0, 0,0,0,
	// 	0,0,0, 0,0,0, 0,0,0,
	// 	0,0,0, 0,0,0, 0,0,0,
	// 	0,0,0, 0,0,0, 0,0,0,
	// 	0,0,0, 0,0,0, 0,0,0,
	// 	0,0,0, 0,0,0, 0,0,0,
	// 	0,0,0, 0,0,0, 0,0,0,
	// 	0,0,0, 0,0,0, 0,0,0,
	// 	0,0,0, 0,0,0, 0,0,0,
	// };

	//화면에 보여질 그리드의 일부 영역 
	//CTile mTile;
	CTile mTile[GRID_H][GRID_W];

public:
	Example()
	{
		sAppName = "pge_tilemap_00";

	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		//
		
		//여기서는 주어진 맵의 너비 높이 만큼 모두 타일로 출력하고 있다.
		for(int tRow = 0; tRow<GRID_H; tRow++)
		{
			for(int tCol = 0; tCol<GRID_W; tCol++)
			{
				mTile[tRow][tCol].CreateRyu(tCol*32, tRow*32, 32, 32);

				mTile[tRow][tCol].SetPGE(this);
			}
		}
		//mTile.CreateRyu();


		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		//
		//
		

		for(int tRow = 0; tRow<GRID_H; tRow++)
		{	
			for(int tCol = 0; tCol<GRID_W; tCol++)
			{
				mTile[tRow][tCol].UpdateRyu();
			}
		}

	
		Clear(olc::BLACK);		
			
		
		
		for(int tRow = 0; tRow<GRID_H; tRow++)
		{
			for(int tCol = 0; tCol<GRID_W; tCol++)
			{
				mTile[tRow][tCol].DisplayRyu();
			}
		}
		
		 
		return true;
	}

	//bool OnUserDestroy() override 
	bool OnUserDestroy() override
	{
		for(int tRow = 0; tRow<GRID_H; tRow++)
		{
			for(int tCol = 0; tCol<GRID_W; tCol++)
			{
				mTile[tRow][tCol].DestroyRyu();
			}
		}

		return true;
	}
};


int main()
{
	Example demo;
	if (demo.Construct(800, 600, 1, 1))
		demo.Start();

	return 0;
}
