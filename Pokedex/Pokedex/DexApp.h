#pragma once

#include "Dex.h"
#include "SearchHash.h"
#include "EfficacyChart.h"
#include <iostream>
using namespace std;
#define TOTALPKMN 803

class DexApp
{
public:
	DexApp::DexApp()
	{
		mPokeDex.initializePkmnNameHeightWeight();
		mPokeDex.initializeTypes();
		hash.initializeHash(mPokeDex);
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
			cout << "4. List by Type" << endl;
			cout << "5. Search by Name" << endl;
			cout << "6. Search by ID Number" << endl;
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
				mPokeDex.listByTypeMenu();
			}
			else if (option == 5)
			{
				string name;
				cout << "Which PKMN would you like to find?" << endl;
				cin >> name;

				int id = hash.findPkmn(name);

				if (id != -1)
					mPokeDex.printAt(id);
				else
					cout << name << " not found!" << endl << endl;
				
			}
			else if (option == 6)
			{
				int num;
				cout << "Which PKMN would you like to find?" << endl;
				cin >> num;

				if (num < 1 || num > TOTALPKMN)
					cout << "PKMN does not exist!" << endl << endl;
				else
					mPokeDex.printAt(num);
			}
		}
	}
private:
	Dex mPokeDex;
	SearchHash hash;
};
