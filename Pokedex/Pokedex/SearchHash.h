#pragma once

#include <fstream>
#include <string>

#include <conio.h>
#include <string>

#include <vector>
using namespace std;
#define TOTALPKMN 803


class SearchHash
{
public:
	SearchHash()
	{
		hash.resize(727);
		tableSize = 727;
		
	}

	void initializeHash(Dex pokeDex)
	{
		for (int i = 1; i < TOTALPKMN; i++)
		{
			addPkmn(pokeDex.getAt(i));
		}
	}

	int hashFunction(string pkmnName)
	{
		unsigned int hashKey = 0;

		//for (char ch : pkmnName)
		//	 hashKey = 37 * hashKey + ch;
		int i = 0;

		for (char ch = pkmnName[0]; i < pkmnName.length(); i++)
		{
			ch = pkmnName[i];
			hashKey = 37 * hashKey + ch;
		}

		return hashKey % tableSize;
	}

	void findPkmnHelper()
	{

	}

	int findPkmn(string pkmnName)
	{
		int hashKey = hashFunction(pkmnName);
		int i = 0, success = -1;

		if (hash[hashKey].size() == 0)
		{
			return -1;
		}

		vector<Pokemon>::iterator itr = hash[hashKey].begin();

		while (itr != hash[hashKey].end())
		{
			if (itr->getName() == pkmnName)
			{
				return itr->getId();
			}
			itr++;
		}

		// In case something happens and gets all the way thru without finding anything
		return -1;
	}
	

private:
	vector<vector<Pokemon>> hash;
	int currentPkmnCount;
	int tableSize;

	
	void addPkmn(Pokemon pkmn)
	{
		unsigned int hashKey = hashFunction(pkmn.getName());
		int i = 0;

		hash[hashKey].push_back(pkmn);
	}
	

};