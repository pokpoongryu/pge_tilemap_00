#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"


#include <iostream>

#include "Block.h"



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
		1,1,1, 1,1,1, 1,1,2,
		1,0,0, 0,0,0, 0,0,2,
		1,0,0, 0,0,1, 0,0,2,

		1,0,0, 0,0,1, 0,0,1,
		2,2,2, 0,0,1, 0,0,2,
		1,0,2, 0,0,1, 0,0,2,

		1,0,0, 0,0,1, 0,0,1,
		1,0,0, 0,0,0, 0,3,1,
		1,1,1, 1,1,1, 1,1,1,
	};
	


	



	//화면에 보여질 그리드의 일부 영역 
	//CBlock mTile;
	CBlock mBlocks[GRID_H][GRID_W];



	int mCameraCol = 1;
	int mCameraRow = 1;

	int mDisplayStartX = 0;
	int mDisplayStartY = 0;

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
				int tX = mDisplayStartX + tCol*32;
				int tY = mDisplayStartY + tRow*32;

				mBlocks[tRow][tCol].CreateRyu(tX, tY, 32, 32);

				mBlocks[tRow][tCol].SetPGE(this);
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

		if (GetKey(olc::Key::LEFT).bReleased)
		{
			mCameraCol = mCameraCol - 1;	

			//clipping
			if( mCameraCol - 1 < 0)
			{
				mCameraCol = 1;
			}

			cout<<"mCameraCol: "<<mCameraCol<<endl;
		}

		if (GetKey(olc::Key::RIGHT).bReleased)
		{
			mCameraCol = mCameraCol + 1;	

			//clipping
			if( mCameraCol  > 9 - 1 - 1 )
			{
				mCameraCol = 9 - 1 - 1;
			}

			cout<<"mCameraCol: "<<mCameraCol<<endl;
		}



		if (GetKey(olc::Key::UP).bReleased)
		{
			mCameraRow = mCameraRow - 1;	

			//clipping
			if( mCameraRow  < 1 )
			{
				mCameraRow = 1;
			}

			cout<<"mCameraRow: "<<mCameraRow<<endl;
		}

		if (GetKey(olc::Key::DOWN).bReleased)
		{
			mCameraRow = mCameraRow + 1;	

			//clipping
			if( mCameraRow  > 9 - 1 - 1 )
			{
				mCameraRow = 9 - 1 - 1;
			}

			cout<<"mCameraRow: "<<mCameraRow<<endl;

		}
		

		for(int tRow = 0; tRow<GRID_H; tRow++)
		{	
			for(int tCol = 0; tCol<GRID_W; tCol++)
			{
				mBlocks[tRow][tCol].UpdateRyu();
			}
		}

	
		Clear(olc::BLACK);		
			
		
		
		for(int tRow = 0; tRow<GRID_H; tRow++)
		{
			for(int tCol = 0; tCol<GRID_W; tCol++)
			{
				mBlocks[tRow][tCol].DisplayRyu(mGrid, mCameraCol, mCameraRow);
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
				mBlocks[tRow][tCol].DestroyRyu();
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
