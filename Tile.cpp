#include "Tile.h"


#include <iostream>
using namespace std;

void CTile::CreateRyu(int tX, int tY, int tWidth, int tHeight)
{
	cout<<"CreateRyu"<<endl;

	mX = tX;
	mY = tY;
	mWidth = tWidth;
	mHeight = tHeight;
}
void CTile::DestroyRyu()
{
	cout<<"DestroyRyu"<<endl;
}
void CTile::UpdateRyu()
{
	//cout<<"UpdateRyu"<<endl;
}
void CTile::DisplayRyu()
{
	//cout<<"DisplayRyu"<<endl;
	
	mpPGE->DrawRect(mX, mY, mWidth, mHeight, olc::WHITE);
}
void CTile::SetPGE(olc::PixelGameEngine *tpPGE)
{
	cout<<"SetPGE"<<endl;

	mpPGE = tpPGE;
}
