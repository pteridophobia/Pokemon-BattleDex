#ifndef DEXNODE_H
#define DEXNODE_H
#include <iostream>
#include <string>
#include "Pokemon.h"
#define TOTALPKMN 803

class DexNode
{
public:
	DexNode::DexNode()
	{
		nextPkmn = nullptr;
		prevPkmn = nullptr;
	}
	DexNode::DexNode(const DexNode& copy)
	{

	}

	DexNode::~DexNode()
	{

	}

	Pokemon& DexNode::getPokemon()
	{
		return mPokemon;
	}

	DexNode* DexNode::getNextPkmn()
	{
		return nextPkmn;
	}

	DexNode* DexNode::getPrevPkmn()
	{
		return prevPkmn;
	}

	void setNextPkmn( DexNode* newPkmn)
	{
		nextPkmn = newPkmn;
	}

	void setPrevPkmn(DexNode* newPkmn)
	{
		prevPkmn = newPkmn;
	}

	void DexNode::printPkmn()
	{

		std::cout << this->getPokemon().getId() << " ";
		std::cout << this->getPokemon().getName() << " ";
		std::cout << this->getPokemon().getHeight() << " ";
		std::cout << this->getPokemon().getWeight() << " ";
		std::cout << this->getPokemon().getType1Name() << " ";
		std::cout << this->getPokemon().getType2Name() << std::endl;
	}
	void setPkmn(Pokemon newPkmn)
	{
		mPokemon = newPkmn;
	}
	
private:
	Pokemon mPokemon;
	DexNode* nextPkmn;
	DexNode* prevPkmn;
};

#endif