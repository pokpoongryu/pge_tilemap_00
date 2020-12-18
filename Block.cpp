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
void CBlock::DisplayRyu(int tGrid[][TOTAL_GRID_W], int tX, int tY)
{
	//cout<<"DisplayRyu"<<endl;

	// mpPGE->FillRect( mX, mY, mWidth, mHeight, olc::WHITE);
	// mpPGE->DrawRect(mX, mY, mWidth, mHeight, olc::BLACK);

	

	// int tCol = mX/32;
	// int tRow = mY/32;
	int tCol = ( mX + tX*32 )/32;/*mY/32;/*/
	int tRow = ( mY + tY*32 )/32;//mY/32;


	//표시할 데이터를 결정할, 속성 데이터를 알아냄
	int tAttribute = tGrid[tRow][tCol];

	//이 부분을 타일 이미지로 하면 되겠다.
	//
	//속성 그리드의 속성 데이터를 참고하여 
	//화면에 표시할 데이터를 선택 
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
