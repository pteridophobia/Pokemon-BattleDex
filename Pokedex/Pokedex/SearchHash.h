#ifndef SEARCHHASH_H
#define SEARCHHASH_H
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
		hash.resize(TOTALPKMN);
		tableSize = 802;
	}

	SearchHash(vector<Pokemon>& pkDex)
	{
		for (int i = 1; i < TOTALPKMN; i++)
		{
			addPkmn(pkDex.at(i));
		}
	}

	void createHash(vector<Pokemon>& pkDex)
	{
		for (int i = 1; i < TOTALPKMN; i++)
		{
			addPkmn(pkDex.at(i));
		}
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

#endif