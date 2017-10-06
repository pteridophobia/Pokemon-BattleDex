#pragma once

#include "Dex.h"
#include <iostream>
using namespace std;

class DexApp
{
public:
	DexApp::DexApp()
	{
		mPokeDex.initializePkmnNameHeightWeight();
		mPokeDex.initializeTypes();
	}
	void DexApp::runApp()
	{
		this->dexMenu();
	}

	DexApp::~DexApp()
	{
		this->mPokeDex.deleteDexHelper();
	}

	void DexApp::dexMenu(void)
	{
		while (1)
		{
			int option = 0;
			cout << "WELCOME TO THE POKEMON BATTLEDEX" << endl << "CHOOSE A FUNCTION:" << endl;
			cout << "1. Print Dex" << endl;
			cout << "2. View by Region" << endl;
			cout << "3. Manual View" << endl;
			cout << "4. Exit" << endl;
			cin >> option;
			if (option == 1)
			{
				mPokeDex.printDex();
			}
			else if (option == 2)
			{
				mPokeDex.printByRegion();
			}
			else if (option == 3)
			{
				mPokeDex.ManualView();
			}
			else if (option == 4)
			{
				break;
			}
		}
	}
private:
	Dex mPokeDex;
};
