#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <fstream>
#include <iostream>

class Pokemon
{
public:
	Pokemon::Pokemon()
	{
		mName = "";
		mId = 0;
		mSpecies = "";
		mHeight = 0;
		mWeight = 0;
		mType1id = "";
		mType2id = "";
		mType1Name = "";
		mType2Name = "";

	}

	Pokemon::Pokemon(const Pokemon& copy)
	{
		mName = copy.mName;
		mId = copy.mId;
		mSpecies = copy.mSpecies;
		mHeight = copy.mHeight;
		mWeight = copy.mWeight;
		mType1id = copy.mType1id;
		mType2id = copy.mType2id;
		mType1Name = copy.mType1Name;
		mType2Name = copy.mType2Name;

	}
	Pokemon::~Pokemon()
	{
	}

	void Pokemon::printPkmn()
	{

		std::cout << "# " << this->getId() << std::endl;
		std::cout << this->getName() << std::endl;
		std::cout << "Height: " << this->getHeight() << std::endl;
		std::cout << "Weight: " << this->getWeight() << std::endl;
		std::cout << "Type 1: " << this->getType1Name() << std::endl;
		if(!this->getType2Name().empty())
			std::cout << "Type 2: " << this->getType2Name() << std::endl;
	/*	std::cout << std::endl;*/
	}

	std::string Pokemon::getName() const
	{
		return mName;
	}
	int Pokemon::getId() const
	{
		return mId;
	}
	std::string Pokemon::getSpecies() const
	{
		return mSpecies;
	}
	int Pokemon::getHeight() const
	{
		return mHeight;
	}
	int Pokemon::getWeight() const
	{
		return mWeight;
	}
	std::string Pokemon::getType1id() const
	{
		return mType1id;
	}

	std::string Pokemon::getType2id() const
	{
		//if (!mType2.empty())
		return mType2id; // Not all Pokemon have a second type, so we gotta check to see if a Pokemon has a second  type
	}
	std::string Pokemon::getType1Name() const
	{
		return mType1Name;
	}
	std::string Pokemon::getType2Name() const
	{
		return mType2Name;
	}

	void Pokemon::setName(const std::string newName)
	{
		mName = newName;
	}
	void Pokemon::setId(const int newId)
	{
		mId = newId;
	}
	void Pokemon::setSpecies(const std::string newSpecies)
	{
		mSpecies = newSpecies;
	}
	void Pokemon::setHeight(const int newHeight)
	{
		mHeight = newHeight;
	}
	void Pokemon::setWeight(const int newWeight)
	{
		mWeight = newWeight;
	}
	void Pokemon::setType1id(const std::string newType1)
	{
		mType1id = newType1;
	}
	void Pokemon::setType2id(const std::string newType2) //Not all Pokemon have a second type,
	{
		mType2id = newType2;
	}
	void Pokemon::setType1Name(const std::string newType1)
	{
		mType1Name = newType1;
	}
	void Pokemon::setType2Name(const std::string newType2)
	{
		mType2Name = newType2;
	}

	Pokemon& Pokemon::operator=(const Pokemon & rhs)
	{
		mName = rhs.mName;
		mId = rhs.mId;
		mSpecies = rhs.mSpecies;
		mHeight = rhs.mHeight;
		mWeight = rhs.mWeight;
		mType1id = rhs.mType1id;
		mType2id = rhs.mType2id;
		
		return *this;
	}

private:
	std::string mName;
	int mId;
	std::string mSpecies;
	int mHeight;
	int mWeight;
	std::string mType1id;
	std::string mType2id;
	std::string mType1Name;
	std::string mType2Name;
};

#endif