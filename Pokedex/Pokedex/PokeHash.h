#ifndef POKEHASH_H
#define POKEHASH_H
#include "HashTable.h"
#include "Pokemon.h"
#include <fstream>
#include <string>
#include <conio.h>

#include <string>
#include <vector>
using namespace std;

#define TOTALPKMN 803

class PokeHash : public HashTable<Pokemon>
{
public:
	PokeHash()
	{
		hash.resize(TOTALPKMN);
		tableSize = 802;
	}

	PokeHash(vector<Pokemon>& pkDex)
	{
		for (int i = 1; i < TOTALPKMN; i++)
		{
			addValue(pkDex.at(i));
		}
	}

	void createHash(vector<Pokemon>& list)
	{
		for (int i = 1; i < TOTALPKMN; i++)
		{
			addValue(list.at(i));
			currentCount++;
		}
	}

	int findValue(string value)
	{
		value = inputFixer(value);
		int hashKey = hashFunction(value);
		int i = 0, success = -1;

		if (hash[hashKey].size() == 0)
		{
			return -1;
		}

		vector<Pokemon>::iterator itr = hash[hashKey].begin();

		while (itr != hash[hashKey].end())
		{
			if (itr->getName() == value)
			{
				return itr->getId();
			}
			itr++;
		}
		// In case something happens and gets all the way thru without finding anything
		return -1;
	}


private:
	void addValue(Pokemon value)
	{
		unsigned int hashKey = hashFunction(value.getName());
		
		hash[hashKey].push_back(value);
	}

	string inputFixer(string value)
	{
		for (int i = 0; i < value.size(); i++)
		{
			if (value[i] == ' ')
			{
				value[i] = '-';
			}
			else
				value[i] = tolower(value[i]);
		}
		return value;
	}
};

#endif