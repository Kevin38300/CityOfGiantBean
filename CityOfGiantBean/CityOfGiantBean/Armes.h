#pragma once
#include "NonVivant.h"

class Armes :   public NonVivant
{
	int degat;
	int mana;

public:

	Armes();
	~Armes();

	int GetDegat() { return degat; }
	void SetDegat(int _value) { degat = _value; }
	int GetMana() { return mana; }
	void SetMana(int _value) { mana = _value; }
	void SetStats(std::string _nom, int _degat, int _mana, int _prix);

};

