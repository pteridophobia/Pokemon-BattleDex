#pragma once
#include <string>


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
		mType1 = "";
		mType2 = "";
	}
	Pokemon::Pokemon(const Pokemon& copy)
	{
		mName = copy.mName;
		mId = copy.mId;
		mSpecies = copy.mSpecies;
		mHeight = copy.mHeight;
		mWeight = copy.mWeight;
		mType1 = copy.mType1;
		mType2 = copy.mType2;
	}
	Pokemon::~Pokemon()
	{
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
	std::string Pokemon::getType1() const
	{
		return mType1;
	}

	std::string Pokemon::getType2() const
	{
		//if (!mType2.empty())
		return mType2; // Not all Pokemon have a second type, so we gotta check to see if a Pokemon has a second  type
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
	void Pokemon::setType1(const std::string newType1)
	{
		mType1 = newType1;
	}
	void Pokemon::setType2(const std::string newType2) //Not all Pokemon have a second type,
	{
		mType2 = newType2;
	}

private:
	std::string mName;
	int mId;
	std::string mSpecies;
	int mHeight;
	int mWeight;
	std::string mType1;
	std::string mType2;
};
