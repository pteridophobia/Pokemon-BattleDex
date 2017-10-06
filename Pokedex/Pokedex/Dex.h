#pragma once

#include <fstream>
#include <string>
#include "DexNode.h"
#include <conio.h>
#include <string.h>

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

char* intToType(std::string typeNum);
#include <iostream>
using namespace std;

class Dex
{
public:
	Dex::Dex()
	{
		headPkmn = nullptr;
	}

	//copy constructor
	Dex::Dex(const Dex& other)
	{
		DexNode* pOther = other.headPkmn;

		while (pOther != nullptr)
		{
			this->insertAtEnd(pOther);
			pOther = pOther->getNextPkmn();
		}
	}

	Dex::~Dex()
	{
		
	}

	void Dex::printDex()
	{
		system("cls");
		DexNode* pCur = headPkmn;
		int i = 0;
		std::cout << "ID   Name    Height   Weight Type1   Type2" << std::endl;
		while (i < 721)
		{
			pCur->printPkmn();
			pCur = pCur->getNextPkmn();
			i++;
			
		}
	/*	while (1)
		{
			cout << "Press any button to return to the Dex Menu" << endl;
			if (getch)
			{
				break;
			}
		}*/
	}

	void printByRegion()
	{
		int RegionChoice = 0, i = 1;
		DexNode* pCur = headPkmn;
		system("cls");

		cout << "Choose a Region:" << endl;
		cout << "1. KANTO    2. JOHTO   3. HOENN\n4. SINNOH   5. UNOVA   6. KALOS" << endl;
		cin >> RegionChoice; 

		//KANTO
		if (RegionChoice == 1)
		{
			system("cls");
			cout << "KANTO POKEDEX" << endl;
			while (i < 151)
			{
				pCur->printPkmn();
				pCur = pCur->getNextPkmn();
				i++;
			}
		}

		//JOHTO
		else if (RegionChoice == 2)
		{
			system("cls");
			cout << "JOHTO POKEDEX" << endl;
			while (i < 152)
			{
				pCur = pCur->getNextPkmn();
				i++;
			}
			while (i < 252)
			{
				pCur->printPkmn();
				pCur = pCur->getNextPkmn();
				i++;
			}
		}

		//HOENN
		else if (RegionChoice == 3)
		{
			system("cls");
			cout << "HOENN POKEDEX" << endl;
			while (i < 252)
			{
				pCur = pCur->getNextPkmn();
				i++;
			}
			while (i < 387)
			{
				pCur->printPkmn();
				pCur = pCur->getNextPkmn();
				i++;
			}
		}

		//SINNOH
		else if (RegionChoice == 4)
		{
			system("cls");
			cout << "SINNOH POKEDEX" << endl;
			while (i < 387)
			{
				pCur = pCur->getNextPkmn();
				i++;
			}
			while (i < 494)
			{
				pCur->printPkmn();
				pCur = pCur->getNextPkmn();
				i++;
			}
		}

		//UNOVA
		else if (RegionChoice == 5)
		{
			system("cls");
			cout << "UNOVA POKEDEX" << endl;
			while (i < 494)
			{
				pCur = pCur->getNextPkmn();
				i++;
			}
			while (i < 650)
			{
				pCur->printPkmn();
				pCur = pCur->getNextPkmn();
				i++;
			}
		}

		//KALOS
		else if (RegionChoice == 6)
		{
			system("cls");
			cout << "KALOS POKEDEX" << endl;
			while (i < 650)
			{
				pCur = pCur->getNextPkmn();
				i++;
			}
			while (i < 722)
			{
				pCur->printPkmn();
				pCur = pCur->getNextPkmn();
				i++;
			}
		}
	}

	void ManualView()
	{
		DexNode* pCur = headPkmn;
		system("cls");
		int c = '\0';
		bool exit = false;

		cout << "Manual View\nUse 'A to go right, 'D' to go left." << endl;
		
		pCur->printPkmn();

		while (!exit)
		{
				switch (getch()) { // the real value
				case 'a':
				case 'A':
					system("cls");
					cout << "Manual View\nUse 'A to go right, 'D' to go left." << endl;
					pCur = pCur->getNextPkmn();
					pCur->printPkmn();
					//code for right arrow
					break;
				case 'd':
				case 'D':
					system("cls");
					cout << "Manual View\nUse 'A to go right, 'D' to go left." << endl;
					pCur = pCur->getPrevPkmn();
					pCur->printPkmn();
					// code for arrow left
					break;
				default:
					exit = true;
					break;
				}
		}
	}

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

		
			
	}

	bool Dex::initializePkmnNameHeightWeight()
	{
		int id = 0;
		double height = 0, weight = 0;
		std::string  str, name, species;
		Pokemon newPkmn;
		DexNode* newNode = nullptr;
		std::fstream mFile;

		mFile.open("pokemon.csv", std::ios::in);
		mFile.clear();
		mFile.seekg(0, std::ios::beg);
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

			newNode = new DexNode();

			newPkmn.setId(id);
			newPkmn.setName(name);
			newPkmn.setSpecies(species);
			newPkmn.setHeight(height);
			newPkmn.setWeight(weight);
			newNode->setPkmn(newPkmn);

			if (newNode == nullptr)
			{
				std::cout << "Something went wrong with creating new DexNode! Pokemon Not initialized" << endl;
			}
			else
			{
				insertAtEnd(newNode);
			}
		}
		mFile.close();
		if (headPkmn != nullptr)
		{
			headPkmn->setPrevPkmn(lastPkmn);
			lastPkmn->setNextPkmn(headPkmn);
			return true;
		}
		return false;

	}

	//This reads 'pokemon_types' and sets the type id to an integer that represents the type
	bool Dex::initializeTypes()
	{
		//File Format: ID, Type ID, Slot Number
		std::string str, id, type, slot;
		DexNode* pCur = headPkmn;
		std::fstream mFile;

		mFile.open("Types.csv", std::ios::in);
		mFile.clear();
		mFile.seekg(0, std::ios::beg);
		getline(mFile, str);  //eats up the header of the file
		while (!mFile.eof())
		{
			getline(mFile, str, ',');
			id = str;     //reads the Pokemon ID 
			while (atoi(id.c_str()) != pCur->getPokemon().getId())  //makes sure we are inserting info into the right pokemon by moving through the file 
			{														//till we find the correct pokemon
				pCur = pCur->getNextPkmn();							//We will update this once the list is made doubly linked
			}
			getline(mFile, str, ',');  //we  now get the actual type, which will be a int value representing the actual type
			type = str;
			type = intToType(type);  //converts the int representation of a type into the actual type
			getline(mFile, str, '\n'); ////this determines if this type will be the first type or second 
			slot = str;
			if (atoi(slot.c_str()) == 1)
			{
				pCur->getPokemon().setType1Name(type);  //insert type into correct type
			}
			else if (atoi(slot.c_str()) == 2)
			{
				pCur->getPokemon().setType2Name(type);//insert type into correct type
			}
		}
		mFile.close();
		if (headPkmn->getPokemon().getType1Name() != "")
		{
			return true;
		}
		return false;
	}

	void Dex::deleteDexHelper()
	{
		this->deleteHelper(this->headPkmn);
	}

private:
	DexNode* headPkmn;
	DexNode* lastPkmn;
	

	//precondition: newNode is NOT null
	//Should Dex ALWAYS insert at end? Well it will using this function
	bool Dex::insertAtEnd(DexNode* newNode)
	{
		if (headPkmn == nullptr)
		{
			this->headPkmn = newNode;
			this->lastPkmn = newNode;
			return true;
		}
		else
		{
			newNode->setPrevPkmn(this->lastPkmn);
			this->lastPkmn->setNextPkmn(newNode);  //Originally, this had the lastPkmn pointer retrieving the next pokemon and setting it's next ptr to node
			this->lastPkmn = newNode;                             //We then made it so that lassPkmn has its nextPkmn set to newNode
			return  true;
		}
		return false;
	}

	

	void deleteHelper(DexNode* &node)
	{
		while (node)
		{
			DexNode* temp = node;
			node = node->getNextPkmn();
			delete temp;
		}
	}
};

//char* intToType(std::string typeNum)
//{
//	switch (atoi(typeNum.c_str()))
//	{
//	case NORMAL:
//		return "Normal";
//	case FIGHTING:
//		return "Fighting";
//	case FLYING:
//		return "Flying";
//	case POISON:
//		return "Poison";
//	case GROUND:
//		return "Ground";
//	case ROCK:
//		return "Rock";
//	case BUG:
//		return "Bug";
//	case GHOST:
//		return "Ghost";
//	case STEEL:
//		return "Steel";
//	case FIRE:
//		return "Fire";
//	case WATER:
//		return "Water";
//	case GRASS:
//		return "Grass";
//	case ELECTRIC:
//		return "Electric";
//	case PSYCHIC:
//		return "Psychic";
//	case ICE:
//		return "Ice";
//	case DRAGON:
//		return "Dragon";
//	case DARK:
//		return "Dark";
//	case FAIRY:
//		return "Fairy";
//	default:
//		break;
//	}
//}