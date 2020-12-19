#include "Block.h"


#include <iostream>
using namespace std;

void CBlock::CreateRyu(int tX, int tY, int tWidth, int tHeight)
{
	cout<<"CreateRyu"<<endl;

	mX = tX;
	mY = tY;
	mWidth = tWidth;
	mHeight = tHeight;
}
void CBlock::DestroyRyu()
{
	cout<<"DestroyRyu"<<endl;
}
void CBlock::UpdateRyu()
{
	//cout<<"UpdateRyu"<<endl;
}
void CBlock::DisplayRyu(int tGrid[][TOTAL_GRID_W], int tCameraColWorld, int tCameraRowWorld)
{
	//cout<<"DisplayRyu"<<endl;

	// mpPGE->FillRect( mX, mY, mWidth, mHeight, olc::WHITE);
	// mpPGE->DrawRect(mX, mY, mWidth, mHeight, olc::BLACK);

	
	//Find out the property value of an arbitrary position on the grid
	int tCameraXWorld 				= tCameraColWorld*32;
	const int CAMERA_X_SCREEN 		= 1*32;
	int tDiffScreen 				= mX - CAMERA_X_SCREEN;
	int tBlockXWorld 				= tCameraXWorld + tDiffScreen;



	int tCameraYWorld 				= tCameraRowWorld*32;
	const int CAMERA_Y_SCREEN 		= 1*32;
	tDiffScreen 					= mY - CAMERA_Y_SCREEN;
	int tBlockYWorld 				= tCameraYWorld + tDiffScreen;
	

	
	int tCol = tBlockXWorld/32;
	int tRow = tBlockYWorld/32;


	//Select the data to be displayed by referring to the attribute grid
	int tAttribute = tGrid[tRow][tCol];
	switch( tAttribute )
	{
		case 0:
		{
			mpPGE->FillRect( mX, mY, mWidth, mHeight, olc::WHITE);
			mpPGE->DrawRect(mX, mY, mWidth, mHeight, olc::BLACK);
		}
		break;
		case 1:
		{
			mpPGE->FillRect( mX, mY, mWidth, mHeight, olc::RED);
			mpPGE->DrawRect(mX, mY, mWidth, mHeight, olc::BLACK);
		}
		break;
		case 2:
		{
			mpPGE->FillRect( mX, mY, mWidth, mHeight, olc::BLUE);
			mpPGE->DrawRect(mX, mY, mWidth, mHeight, olc::BLACK);
		}
		break;
		case 3:
		{
			mpPGE->FillRect( mX, mY, mWidth, mHeight, olc::GREEN);
			mpPGE->DrawRect(mX, mY, mWidth, mHeight, olc::BLACK);
		}
		break;
	}


}
void CBlock::SetPGE(olc::PixelGameEngine *tpPGE)
{
	cout<<"SetPGE"<<endl;

	mpPGE = tpPGE;
}
