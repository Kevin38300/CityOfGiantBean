#include "Armures.h"

Armures::Armures() : NonVivant()
{
	res = 0;
	mana = 0;
}
Armures::~Armures()
{
}
void Armures::SetStats(std::string _nom, int _res, int _mana, int _prix)
{
	nom = _nom;
	res = _res;
	mana = _mana;
	prix = _prix;
}