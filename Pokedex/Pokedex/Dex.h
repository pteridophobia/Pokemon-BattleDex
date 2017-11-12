#ifndef DEX_H
#define DEX_H

#include "Pokemon.h"
#include "EfficacyChart.h"
#include "SearchHash.h"

#include <fstream>
#include <string>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <vector>
using std::vector;
#define NORMAL 1	
#define FIGHTING 2
#define FLYING 3
#define POISON 4
#define GROUND 5
#define ROCK 6
#define BUG 7
#define GHOST 8
#define STEEL 9
#define FIRE 10
#define WATER 11
#define GRASS 12
#define ELECTRIC 13
#define PSYCHIC 14
#define ICE 15
#define DRAGON 16
#define DARK 17
#define FAIRY 18
using namespace std;
#define TOTALPKMN 803

class Dex
{
public:

	/*
		Dex():
		Default Dex constructor. The Dex is a vector of Pokemon types. The reason for pushing
		back an empty PKMN is because I wanted the vector to begin indexing at 1, and this was
		just a easy to make sure it happened
	*/
	Dex::Dex()
	{
		Pokemon placeholder;
		dexVector.push_back(placeholder);
		currentPkmnCount = 0;
	}

	/*
		createHash():
		creates search hash for name lookups. There must be a better way of doing this, because
		right now we call createHash in DexApp.h which calls this function and then calls Hash's
		createHash() whice makes the hash
	*/
	void createHash()
	{
		hash.createHash(this->dexVector);
	}

	/*
		Dex(const Dex& other):
		Dex Copy Constructor. Uses a reference to another dex and copies it values into it.
		Does so by copying the vector and PKMN count.
	*/
	Dex::Dex(const Dex& other)
	{
		
		this->dexVector = other.dexVector;
		this->currentPkmnCount = other.currentPkmnCount;
	}

	/*
		~Dex():
		Empty Destructor because default destructor is good enough
	*/
	Dex::~Dex()
	{
		
	}

	/*
		printDex():
		Prints out all the pokemon in the PokeDex one by one.
	*/
	void Dex::printDex()
	{
		system("cls");

		int i = 1;
		while (i < TOTALPKMN)
		{
			/*dexVector.at(i).printPkmn();*/
			this->printAt(i);
			i++;
		}
		system("pause");
	}

	/*
		printByRegion():
		The user chooses a region, and all the pokemon in that region are 
		printed to the screen
	*/
	void printByRegion()
	{
		int RegionChoice = 0, i = 1;
		system("cls");

		cout << "Choose a Region:" << endl;
		cout << "1. KANTO    2. JOHTO   3. HOENN\n4. SINNOH   5. UNOVA   6. KALOS 7. ALOLA" << endl;
		cin >> RegionChoice; 

		//KANTO
		if (RegionChoice == 1)
		{
			system("cls");
			cout << "KANTO POKEDEX" << endl;
			while (i < 152)
			{
				this->printAt(i);
				i++;
			}
		}

		//JOHTO
		else if (RegionChoice == 2)
		{
			system("cls");
			cout << "JOHTO POKEDEX" << endl;
			i = 152;
			while (i < 252)
			{
				this->printAt(i);
				i++;
			}
		}

		//HOENN
		else if (RegionChoice == 3)
		{
			system("cls");
			cout << "HOENN POKEDEX" << endl;
			i = 252;
			while (i < 387)
			{
				this->printAt(i);
				i++;
			}
		}

		//SINNOH
		else if (RegionChoice == 4)
		{
			system("cls");
			cout << "SINNOH POKEDEX" << endl;
			i = 387;
			while (i < 494)
			{
				this->printAt(i);
				i++;
			}
		}

		//UNOVA
		else if (RegionChoice == 5)
		{
			system("cls");
			cout << "UNOVA POKEDEX" << endl;
			i = 494;
			while (i < 650)
			{
				this->printAt(i);
				i++;
			}
		}

		//KALOS
		else if (RegionChoice == 6)
		{
			system("cls");
			cout << "KALOS POKEDEX" << endl;
			i = 650;
			while (i < 722)
			{
				this->printAt(i);
				i++;
			}
		}

		else if (RegionChoice == 7)
		{
			system("cls");
			cout << "ALOLA POKEDEX" << endl;
			i = 650;
			while (i < TOTALPKMN)
			{
				this->printAt(i);
				i++;
			}
		}
	}

	/*
		ManualView():
		The user begins at the first PKMN in the PokeDex (Bulbasaur) and
		uses the keyboard to traverse through the pokedex
	*/
	void ManualView()
	{
		system("cls");
		int c = '\0';
		bool exit = false;

		cout << "Manual View\nUse 'A to go right, 'D' to go left." << endl;
		
		int i = 1;
		dexVector.at(i).printPkmn();

		while (!exit)
		{
	
				switch (getch()) { // the real value
				case 'd':
				case 'D':
					system("cls");
					i++;
					if (i > 802)
						i = 1;
					else if (i < 1)
						i = 721;
					cout << "Manual View\nUse 'A to go right, 'D' to go left." << endl;
					dexVector.at(i).printPkmn();
				
					//code for right arrow
					break;
				case 'a':
				case 'A':
					system("cls");
					i--;
					if (i > 802)
						i = 1;
					else if (i < 1)
						i = 721;
					cout << "Manual View\nUse 'A to go right, 'D' to go left." << endl;
					dexVector.at(i).printPkmn();
					
					// code for arrow left
					break;
				default:
					exit = true;
					break;
				}
				
		}
	}

	/*
		listByTypeMenu():
		The user chooses a type, and that type is passed into listByTypeHelper()
		and lists all the Pokemon in the PokeDex with that type
	*/
	void Dex::listByTypeMenu()
	{
		string choice;
		cout << "Select a Type:" << endl;
		cout << "1. Normal" << endl;
		cout << "2. Fighting" << endl;
		cout << "3. Flying" << endl;
		cout << "4. Poison" << endl;
		cout << "5. Ground " << endl;
		cout << "6. Rock" << endl;
		cout << "7. Bug" << endl;
		cout << "8. Ghost" << endl;
		cout << "9. Steel" << endl;
		cout << "10. Fire" << endl;
		cout << "11. Water" << endl;
		cout << "12. Grass" << endl;
		cout << "13. Electric" << endl;
		cout << "14. Psychic" << endl;
		cout << "15. Ice" << endl;
		cout << "16. Dragon" << endl;
		cout << "17. Dark" << endl;
		cout << "18. Fairy" << endl;
		cin >> choice;

		switch (stoi(choice))
		{
		case NORMAL:
			listByTypeHelper(NORMAL);
			break;
		case FIGHTING:
			listByTypeHelper(FIGHTING);
			break;
		case FLYING:
			listByTypeHelper(FLYING);
			break;
		case POISON:
			listByTypeHelper(POISON);
			break;
		case GROUND:
			listByTypeHelper(GROUND);
			break;
		case ROCK:
			listByTypeHelper(ROCK);
			break;
		case BUG:
			listByTypeHelper(BUG);
			break;
		case GHOST:
			listByTypeHelper(GHOST);
			break;
		case STEEL:
			listByTypeHelper(STEEL);
			break;
		case FIRE:
			listByTypeHelper(FIRE);
			break;
		case WATER:
			listByTypeHelper(WATER);
			break;
		case GRASS:
			listByTypeHelper(GRASS);
			break;
		case ELECTRIC:
			listByTypeHelper(ELECTRIC);
			break;
		case PSYCHIC:
			listByTypeHelper(PSYCHIC);
			break;
		case ICE:
			listByTypeHelper(ICE);
			break;
		case DRAGON:
			listByTypeHelper(DRAGON);
			break;
		case DARK:
			listByTypeHelper(DARK);
			break;
		case FAIRY:
			listByTypeHelper(FAIRY);
			break;
		default:
			break;
		}
		
			
	}

	/*
		initializePkmnNameHeightWeight():
		Reads from the file "pokemon.csv" and gets the ID, Name, Species,
		height and weight of a PKMN and stores it in the respective slot in the
		vector.
	*/
	void Dex::initializePkmnNameHeightWeight()
	{
		int id = 0;
		double height = 0, weight = 0;
		std::string  str, name, species;
		Pokemon newPkmn;
		std::fstream mFile;

		mFile.open("pokemon.csv", std::ios::in);

		getline(mFile, str);

		while (!mFile.eof())
		{
			getline(mFile, str, ',');
			id = atoi(str.c_str());

			getline(mFile, str, ',');
			name = str;

			getline(mFile, str, ',');
			species = str;

			getline(mFile, str, ',');
			height = atoi(str.c_str());

			getline(mFile, str, '\n');
			weight = atoi(str.c_str());

			newPkmn.setId(id);
			newPkmn.setName(name);
			newPkmn.setSpecies(species);
			newPkmn.setHeight(height);
			newPkmn.setWeight(weight);
			
			currentPkmnCount++;
			dexVector.push_back(newPkmn);
		}

	}

	/*
		printAt(int i):
		Prints the PKMN at slot i in the vector i.e prints PKMN # i
	*/
	void printAt(int i)
	{
		dexVector.at(i).printPkmn();
	}

	/*
		getAt(i):
		Returns the PKMN at spot i.
		Not sure if to make this a reference or not.
	*/
	Pokemon getAt(int i)
	{
		return dexVector.at(i);
	}

	/*
		initializeTypes():
		Reads the file "pokemon_types.csv" and gets the types for every pokemon.
		The type is represented by an int value, which is converted to it's real value using intToType.
	*/
	bool Dex::initializeTypes()
	{
		std::string str, id, type, slot, typeName;
		std::fstream mFile;
		int idInt = 0;

		mFile.open("pokemon_types.csv", std::ios::in);
		getline(mFile, str);  //eats up the first line of the file
		while (!mFile.eof())
		{
			getline(mFile, id, ',');  //reads the Pokemon ID 
			idInt = atoi(id.c_str());

			getline(mFile, type, ',');  //we  now get the actual type, which will be a int value representing the actual type
		
			typeName = intToType(type);  //converts the int representation of a type into the actual type
			getline(mFile, slot, '\n'); ////this determines if this type will be the first type or second 

			if (atoi(slot.c_str()) == 1)
			{
				dexVector.at(idInt).setType1Name(typeName);  //insert type into correct type
				dexVector.at(idInt).setType1id(type);
				dexVector.at(idInt).setType2id("-1");
			}
			else if (atoi(slot.c_str()) == 2)
			{
				dexVector.at(idInt).setType2Name(typeName);//insert type into correct type
				dexVector.at(idInt).setType2id(type);
			}
		}
		mFile.close();
		if (dexVector.at(1).getType1Name() != "")
		{
			return true;
		}
		return false;
	}

	void initializeAbilities()
	{
		fstream abilityNames("abilities.csv"), abilities("pokemon_abilities.csv");
		string pkmnID, abilityID, abilityName, str;
		string abilityNameArray[233];

		getline(abilityNames, str);  //eats up the first line of the file
		//// Create array with all the ability names for easy index accessing
		for (int i = 1; i < 233; i++)
		{
			getline(abilityNames, abilityID, ',');
			getline(abilityNames, abilityName, ',');

			abilityNameArray[stoi(abilityID)] = abilityName;
			getline(abilityNames, str, '\n');
		}

		// Now we read the pokemon_abilities.csv file and add abilities to all the PKMN
		getline(abilities, str);  //eats up the first line of the file
		while (!abilities.eof())
		{
			getline(abilities, pkmnID, ',');
			getline(abilities, abilityID, ',');

			dexVector.at(stoi(pkmnID)).addAbility(abilityNameArray[stoi(abilityID)]);

			getline(abilities, str, '\n');
		}
	}

	void initializeStats()
	{
		fstream statsFile;
		string str, stat;
		int pkmnID = 1;
		Stats newStats;
		/*
			STATS COME IN THIS ORDER: HP, attack, defense, sp. atk, sp. def, speed
		*/
		statsFile.open("pokemon_stats.csv");
		getline(statsFile, str);  //eats up the first line of the file
		while (!statsFile.eof())
		{
			for (int i = 1; i < 7; i++)
			{
				getline(statsFile, str, ',');
				getline(statsFile, str, ',');
				getline(statsFile, stat, ',');

				if (1 == i)
				{
					newStats.HP = stoi(stat);
				}
				else if (2 == i)
				{
					newStats.attack = stoi(stat);
				}
				else if (3 == i)
				{
					newStats.defense = stoi(stat);
				}
				else if (4 == i)
				{
					newStats.SpAtk = stoi(stat);
				}
				else if (5 == i)
				{
					newStats.SpDef = stoi(stat);
				}
				else
				{
					newStats.speed = stoi(stat);
				}
				getline(statsFile, str, '\n');
			}

			dexVector.at(pkmnID).setStats(newStats);
			pkmnID++;
		}
	}
	/*
		showPkmnWeaknessResistanceImmunities(Pokemon pkmn):
		Finds all the weakness, immunities and resistances of a PKMN and
		prints them to the screen. Uses the efficacyChart class to do this.
	*/
	void showPkmnWeaknessResistanceImmunities(Pokemon pkmn)
	{
		effectChart.displayAllWeaknessResistancesImmunities(pkmn);
		cout << endl;
		system("pause");
	}

	/*
		findPkmnByName(string pkmnName):
		Find a PKMN using its name by using a hash table. The hash look up function
		findPkmn() returns -1 if the pokemon does not exist. Currently case sensitive.
	*/
	void findPkmnByName(string pkmnName)
	{
		int id = hash.findPkmn(pkmnName);

		if (id != -1)
		{
			this->printAt(id);
			this->showPkmnWeaknessResistanceImmunities(this->getAt(id));
		}
		else
			cout << pkmnName << " not found!" << endl << endl;
	}

	/*
		intToType(string typeNum):
		Takes a number that represents a type and returns actual Type name.
	*/
	 char* intToType(string typeNum)
	{
		switch (atoi(typeNum.c_str()))
		{
		case NORMAL:
			return "Normal";
		case FIGHTING:
			return "Fighting";
		case FLYING:
			return "Flying";
		case POISON:
			return "Poison";
		case GROUND:
			return "Ground";
		case ROCK:
			return "Rock";
		case BUG:
			return "Bug";
		case GHOST:
			return "Ghost";
		case STEEL:
			return "Steel";
		case FIRE:
			return "Fire";
		case WATER:
			return "Water";
		case GRASS:
			return "Grass";
		case ELECTRIC:
			return "Electric";
		case PSYCHIC:
			return "Psychic";
		case ICE:
			return "Ice";
		case DRAGON:
			return "Dragon";
		case DARK:
			return "Dark";
		case FAIRY:
			return "Fairy";
		default:
			break;
		}
	}

private:
	vector<Pokemon> dexVector;
	int currentPkmnCount;
	EfficacyChart effectChart;
	SearchHash hash;

	/*
		listByTypeHelper(int type):
		used by listByType() to list all the PKMN of a particular type.
		Traverses through the whole list to find the right PKMN to print
		to the screen
	*/
	void listByTypeHelper(int type)
	{
		int i = 1;
		while (i < TOTALPKMN)
		{
			if (stoi(dexVector.at(i).getType1id()) == type || stoi(dexVector.at(i).getType2id()) == type)
			{
				this->printAt(i);
			}
			i++;
		}
	}
};

#endif