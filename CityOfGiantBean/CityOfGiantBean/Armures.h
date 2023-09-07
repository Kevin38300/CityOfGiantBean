#pragma once
#include "NonVivant.h"

class Armures :   public NonVivant
{
	int res;
	int mana;

public:

	Armures();
	~Armures();

	int GetRes() { return res; }
	void SetRes(int _value) { res = _value; }
	int GetMana() { return mana; }
	void SetMana(int _value) { mana = _value; }
	void SetStats(std::string _nom, int _res, int _mana, int _prix);
};

