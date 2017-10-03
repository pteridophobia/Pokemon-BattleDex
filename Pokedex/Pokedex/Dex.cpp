#include "Dex.h"
using std::getline;
//Dex::Dex()
//{
//	headPkmn = nullptr;
//}

//Dex::Dex(const Dex& copy)
//{
//
//}
//Dex::~Dex()
//{
//
//}

//precondition: newNode is NOT null
//Should Dex ALWAYS insert at end? Well it will using this function
//bool Dex::insertAtEnd(DexNode* newNode, Dex& Pokedex)
//{
//	if (headPkmn == nullptr)
//	{
//		Pokedex.headPkmn = newNode;
//		Pokedex.lastPkmn = newNode;
//		return true;
//	}
//	else
//	{
//		Pokedex.lastPkmn->setNextPkmn(newNode);  //Originally, this had the lastPkmn pointer retrieving the next pokemon and setting it's next ptr to node
//		Pokedex.lastPkmn = newNode;                             //We then made it so that lassPkmn has its nextPkmn set to newNode
//		return  true;
//	}
//	return false;
//}

//bool Dex::initializePkmnHeightWeight()
//{
//	int id = 0;
//	double height = 0, weight = 0;
//	std::string  str, name, species;
//	Pokemon newPkmn;
//	DexNode* newNode = nullptr;
//
//	mFile.open("pokemon.csv", std::ios::in);
//	mFile.clear();
//	mFile.seekg(0, std::ios::beg);
//	getline(mFile, str);
//
//	while (!mFile.eof())
//	{
//		getline(mFile, str, ',');
//		id = atoi(str.c_str());
//
//		getline(mFile, str, ',');
//		name = str;
//
//		getline(mFile, str, ',');
//		species = str;
//
//		getline(mFile, str, ',');
//		height = atoi(str.c_str());
//
//		getline(mFile, str, '\n');
//		weight = atoi(str.c_str());
//
//		newNode = new DexNode();
//		
//		newPkmn.setId(id);
//		newPkmn.setName(name);
//		newPkmn.setSpecies(species);
//		newPkmn.setHeight(height);
//		newPkmn.setWeight(weight);
//		newNode->setPkmn(newPkmn);
//
//		if (newNode == nullptr)
//		{
//			std::cout << "Something went wrong with creating new DexNode! Pokemon Not initialized";
//		}
//		else
//		{
//			insertAtEnd(newNode, *this);
//		}
//	}
//	mFile.close();
//	if (headPkmn != nullptr)
//	{
//		return true;
//	}
//	return false;
//	
//}

//void Dex::printDex()
//{
//	DexNode* pCur = headPkmn;
//	std::cout << "ID   Name   Height   Weight" << std::endl;
//	while (pCur != nullptr)
//	{
//		pCur->printPkmn();
//		pCur = pCur->getNextPkmn();
//	}
//}

////This reads 'pokemon_types' and sets the type id to an integer that represents the type
//bool Dex::initializeTypes()
//{
//	//File Format: ID, Type ID, Slot Number
//	std::string str, id, type, slot;
//	DexNode* pCur = headPkmn;
//	mFile.open("Types.csv", std::ios::in);
//	mFile.clear();
//	mFile.seekg(0, std::ios::beg);
//	getline(mFile, str);  //eats up the header of the file
//	while (!mFile.eof())
//	{
//		getline(mFile, str, ',');
//		id = str;     //reads the Pokemon ID 
//		while (atoi(id.c_str()) != pCur->getPokemon().getId())  //makes sure we are inserting info into the right pokemon by moving through the file 
//		{														//till we find the correct pokemon
//			pCur = pCur->getNextPkmn();							//We will update this once the list is made doubly linked
//		}
//		getline(mFile, str, ',');  //we  now get the actual type, which will be a int value representing the actual type
//		type = str;
//		type = intToType(type);  //converts the int representation of a type into the actual type
//		getline(mFile, str, '\n'); ////this determines if this type will be the first type or second 
//		slot = str;
//		if (atoi(slot.c_str()) == 1)
//		{
//			pCur->getPokemon().setType1(type);  //insert type into correct type
//		}
//		else if (atoi(slot.c_str()) == 2)
//		{
//			pCur->getPokemon().setType2(type);//insert type into correct type
//		}
//	}
//	mFile.close();
//	if (headPkmn->getPokemon().getType1() != "")
//	{
//		return true;
//	}
//	return false;
//}

char* intToType(std::string typeNum)
{
	switch (atoi(typeNum.c_str()))
	{
	case NORMAL:
		return "Normal";
	case FIGHTING:
		return "Fighting";
	case FLYING:
		return "Flying";
	case POISON :
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