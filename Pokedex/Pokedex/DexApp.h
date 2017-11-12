#ifndef DEXAPP_H
#define DEXAPP_H

#include "Dex.h"
#include <fstream>
#include <iostream>
using namespace std;
#define TOTALPKMN 803

class DexApp
{
public:
	/*
		DexApp():
		Default constructors that initializes the pokedex by ready all PKMN
		and their respective info from files. It also creates the search hash
		for lookups by name
	*/
	DexApp::DexApp()
	{
		mPokeDex.initializePkmnNameHeightWeight();
		mPokeDex.initializeTypes();
		mPokeDex.createHash();
		mPokeDex.initializeAbilities();
		mPokeDex.initializeStats();
	}

	/*
		runApp():
		Main function for using the Pokedex. Brings up the Dex Menu
	*/
	void DexApp::runApp()
	{
		this->dexMenu();
	}

	/*
		~DexApp():
		Dex destructor. Currently empty because the default constructor
		can take care of everything itself
	*/
	DexApp::~DexApp()
	{
		//this->mPokeDex.deleteDexHelper();
	}

	/*
		dexMenu():
		Presents the user with many options on displaying the info of the dex. 
		The choice selected by the user if handled by several if statements.
		This might be changed in favor of a switch statement
	*/
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

				
				mPokeDex.findPkmnByName(name);
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
	
};
#endif
