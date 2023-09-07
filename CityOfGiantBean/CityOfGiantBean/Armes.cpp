#include "Armes.h"

Armes::Armes() : NonVivant()
{
	degat = 0;
	mana = 0;
}

Armes::~Armes()
{
}

void Armes::SetStats(std::string _nom, int _degat, int _mana, int _prix)
{
	nom = _nom;
	degat = _degat;
	mana = _mana;
	prix = _prix;
}