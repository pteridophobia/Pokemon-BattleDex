#pragma once
#include <iostream>
#include <string>
#include "Pokemon.h"

class DexNode
{
public:
	DexNode::DexNode(/*std::string newName, int newId, std::string newSpecies, double newHeight, double newWeight, std::string newType1, std::string newType2*/)
	{
		/*this->mPokemon.setName(newName);
		this->mPokemon.setId(newId);
		this->mPokemon.setSpecies(newSpecies);
		this->mPokemon.setHeight(newHeight);
		this->mPokemon.setWeight(newWeight);
		this->mPokemon.setType1(newType1);
		this->mPokemon.setType2(newType2);*/
		nextPkmn = nullptr;
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
	void setNextPkmn( DexNode* newPkmn)
	{
		nextPkmn = newPkmn;
	}
	void DexNode::printPkmn()
	{

		std::cout << this->getPokemon().getId() << " ";
		std::cout << this->getPokemon().getName() << " ";
		std::cout << this->getPokemon().getHeight() << " ";
		std::cout << this->getPokemon().getWeight() << " ";
		std::cout << this->getPokemon().getType1() << " ";
		std::cout << this->getPokemon().getType2() << std::endl;
	}
	void setPkmn(Pokemon newPkmn)
	{
		mPokemon = newPkmn;
	}
	
private:
	Pokemon mPokemon;
	DexNode* nextPkmn;
};

