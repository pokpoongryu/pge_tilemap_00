#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"


#include <iostream>
using namespace std;


class CUnit
{
public:
	void Doit()
	{
		cout<<"CUnit::Doit()"<<endl;
	};

};


class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "pge_tilemap_00";

		CUnit tUnit;
		tUnit.Doit();
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		//
		//
	
		Clear(olc::BLACK);		
		
		
		
		
		 
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
