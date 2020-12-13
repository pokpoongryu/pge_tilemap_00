#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"


#include <iostream>

#include "Tile.h"



using namespace std;


/*
 * create by pokpoongryu
 *
 * this class is to the tile.
*/


class Example : public olc::PixelGameEngine
{
private:
	CTile mTile;


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
		
		mTile.CreateRyu();


		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		//
		//
		
		mTile.UpdateRyu();
	
		Clear(olc::BLACK);		
		
		
		
		mTile.DisplayRyu();
		
		 
		return true;
	}

	//bool OnUserDestroy() override 
	bool OnUserDestroy() override
	{
		
		mTile.DestroyRyu();

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
