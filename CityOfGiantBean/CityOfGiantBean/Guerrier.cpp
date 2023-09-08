#include "Guerrier.h"

Guerrier::Guerrier()
{
	nameJob = "Guerrier";
	pv = 1000;
	defense = 250;
	attaque = 200;
	//argent = 500;
	mana = 50;
	endurance = 100; // /100
	vitesse = 10; // /100
	effet = Tank;
}

void Guerrier::ChangeStatNiveau(Guerrier _perso, std::string _nameJob, int _pv, int _mana, int _endurance, int _vitesse)
{
	_perso.nameJob = _nameJob;
	_perso.pv = _pv;
	_perso.mana = _mana;
	_perso.endurance = _endurance;
	_perso.vitesse = _vitesse;
}

void Guerrier::DisplayStat()
{
	std::cout << "Nom:" << nameJob << " Pv:" << pv << " Mana:" << mana << " Endurance:" << endurance << " Vitesse : " << vitesse << std::endl;
}

void Guerrier::AfficheStatAv(myWindow& _window, sf::Text texte) {
	texte.setString(GetName() + "\nVit: " + std::to_string(GetVitesse()) + "\nPV: " + std::to_string(GetPV()) + "\nAtk: " + std::to_string(GetAttaque()) + "\nDef: " + std::to_string(GetDefense()) + "\nMana: " + std::to_string(GetMana()) + "\nElement: \n Terre");
	_window.Draw(texte);
}