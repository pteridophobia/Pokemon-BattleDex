#ifndef EFFICACYCHART_H
#define EFFICACYCHART_H


#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>
#include <string>
#include <vector>
using namespace std;
#define TOTALPKMN 803
#define NORMAL 1	
#define FIGHTING 2
#define FLYING 3
#define POISON 4
#define GROUND 5
#define ROCK 6
#define BUG 7
#define GHOST 8
#define STEEL 9
#define FIRE 10
#define WATER 11
#define GRASS 12
#define ELECTRIC 13
#define PSYCHIC 14
#define ICE 15
#define DRAGON 16
#define DARK 17
#define FAIRY 18

class EfficacyChart {

public:
	EfficacyChart()
	{
		initializeChart();
	}

	void initializeChart()
	{
		fstream infile;
		infile.open("type_efficacy.csv", std::ios::in);

		string str, damageNum, targetNum, amount;
		getline(infile, str);

		for (int i = 1; i < 325; i++)
		{
			getline(infile, damageNum, ',');
			getline(infile, targetNum, ',');
			getline(infile, amount, '\n');

			effectChart[i][0] = stoi(damageNum);
			effectChart[i][1] = stoi(targetNum);
			effectChart[i][2] = stoi(amount);

		}
	}


	/*
		In order to display all the weaknesses of a pokemon,
		we should traverse the array using the PKMN types and going from 1 - 18 
		in the damage_type ID. If the value ever equal 100, it is a weakness
	*/
	void displayAllWeakness(Pokemon pkmn)
	{
		int pkmnType1 = stoi(pkmn.getType1id());
		int pkmnType2 = stoi(pkmn.getType2id());

		/// Loop for pkmnType1
		for (int i = 1; i < 19; i++)
		{
			if (effectChart[i][pkmnType1] == 200)
			{
				cout << pkmn.getName() << " is weak to " << intToType(to_string(i)) << endl;
			}
		}
		if (pkmnType2 != 0)
		{
			/// Loop for pkmnType1
			for (int i = 0; i < 18; i++)
			{
				if (effectChart[i][pkmnType2] == 200)
				{
					cout << pkmn.getName() << " is weak to " << intToType(to_string(i)) << endl;
				}
			}
		}
	}

	void displayAllResistancesAndIneffects(Pokemon pkmn)
	{

	}


	static char* intToType(std::string typeNum)
	{
		switch (atoi(typeNum.c_str()))
		{
		case NORMAL:
			return "Normal";
		case FIGHTING:
			return "Fighting";
		case FLYING:
			return "Flying";
		case POISON:
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
private:
	int effectChart[325][3];
};

#endif