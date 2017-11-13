#ifndef ABILITYHASH_H
#define ABILITYHASH_H
#include "HashTable.h"
#include "Pokemon.h"
#include <fstream>
#include <string>
#include <conio.h>

#include <string>
#include <vector>
using namespace std;

class AbilityHash : public HashTable<Ability>
{
public:

	AbilityHash()
	{
		hash.resize(233);
		tableSize = 233;
		initializaHash();
	}

	AbilityHash(vector<Ability>& list)
	{

	}

	void initializaHash()
	{
		fstream abilityNames("Ability.csv");
		string pkmnID, Num, Name, str, Effect;
		Ability newAbility;

		getline(abilityNames, str);  //eats up the first line of the file
									 //// Create array with all the ability names for easy index accessing
		for (int i = 1; i < 233; i++)
		{
			getline(abilityNames, Num, ',');
			getline(abilityNames, Name, ',');
			getline(abilityNames, Effect, '\n');

			newAbility.abilityName = Name;
			newAbility.abilityID = stoi(Num);
			newAbility.abilityDef = Effect;
		
			addValue(newAbility);
		}

	}

	void createHash(vector<Ability>& list)
	{
		for (int i = 1; i < tableSize; i++)
		{
			addValue(list.at(i));
			currentCount++;
		}
	}

	int findValue(string value)
	{
		int hashKey = hashFunction(value);
		int i = 0, success = -1;

		if (hash[hashKey].size() == 0)
		{
			return -1;
		}

		vector<Ability>::iterator itr = hash[hashKey].begin();

		while (itr != hash[hashKey].end())
		{
			if (itr->abilityName == value)
			{
				system("cls");
				cout << "Ability: " << itr->abilityName << endl;
				cout << itr->abilityDef << endl << endl;
				return 1;
				//return itr->getId();
			}
			itr++;
		}
		// In case something happens and gets all the way thru without finding anything
		return -1;
	}
private:
	void addValue(Ability value)
	{
		int hashKey = hashFunction(value.abilityName);

		hash[hashKey].push_back(value);
	}
};

#endif