#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <fstream>
#include <string>
#include <conio.h>

#include <string>
#include <vector>
using namespace std;

template<typename VALUE>
class HashTable
{
public:
	HashTable()
	{
		//tableSize = 1;
	}

	int hashFunction(string key)
	{
		unsigned int hashKey = 0;

		//for (char ch : pkmnName)
		//	 hashKey = 37 * hashKey + ch;
		unsigned int i = 0;

		for (char ch = key[0]; i < key.length(); i++)
		{
			ch = key[i];
			hashKey = 37 * hashKey + ch;
		}

		return hashKey % tableSize;
	}

	virtual void createHash(vector<VALUE>& list) = 0;
	virtual int findValue(string value) = 0;


protected:
	int tableSize;
	int currentCount;
	vector<vector<VALUE>> hash;

	virtual void addValue(VALUE value) = 0;

};
#endif
