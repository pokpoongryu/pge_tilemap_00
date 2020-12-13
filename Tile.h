#include "olcPixelGameEngine.h"




/*
 * create by pokpoongryu
 *
 * this class is to the tile.
*/
class CTile
{
public:
	int mX = 0;
	int mY = 0;

	int mWidth = 0;
	int mHeight = 0;


	olc::PixelGameEngine *mpPGE = nullptr;

public:
	void CreateRyu(int tX, int tY, int tWidth = 32, int tHeight = 32);
	void DestroyRyu();
	void UpdateRyu();
	void DisplayRyu();

	void SetPGE(olc::PixelGameEngine *tpPGE);

};

