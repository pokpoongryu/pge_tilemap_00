#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"


#include <iostream>

#include "Tile.h"



using namespace std;

#define GRID_W 15
#define GRID_H 15


/*
 * create by pokpoongryu
 *
 * this class is to the tile.
*/


class Example : public olc::PixelGameEngine
{
private:
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
