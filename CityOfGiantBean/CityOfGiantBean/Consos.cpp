#include "Consos.h"

Consos::Consos() : NonVivant()
{
	degat = 0;
	soinPv = 0;
	soinM = 0;
}
Consos::~Consos()
{
}
void Consos::SetStats(std::string _nom, int _degat, int _soinPv, int _soinM, int _prix)
{
	nom = _nom;
	degat = _degat;
	soinPv = _soinPv;
	soinM = _soinM;
	prix = _prix;
}