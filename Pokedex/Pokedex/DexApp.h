#pragma once

#include "Dex.h"

class DexApp
{
public:
	DexApp()
	{}
	void DexApp::runApp()
	{
		mPokeDex.initializePkmnHeightWeight();
		mPokeDex.initializeTypes();
		mPokeDex.printDex();

	}
private:
	Dex mPokeDex;
};
