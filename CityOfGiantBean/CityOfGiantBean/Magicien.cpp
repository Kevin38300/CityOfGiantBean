#include "Magicien.h"

Magicien::Magicien()
{
	nameJob = "Magicien";
	pv = 100;
	defense = 10;
	attaque = 400;
	//argent = 1000;
	mana = 200;
	endurance = 10; // /100
	vitesse = 10; // /100 
	effet = Brulure;
}

void Magicien::ChangeStatNiveau(Magicien _perso, std::string _nameJob, int _pv, int _mana, int _endurance, int _vitesse)
{
	_perso.nameJob = _nameJob;
	_perso.pv = _pv;
	_perso.mana = _mana;
	_perso.endurance = _endurance;
	_perso.vitesse = _vitesse;
}

void Magicien::DisplayStat()
{
	std::cout << "Nom:" << nameJob << " Pv:" << pv << " Mana:" << mana << " Endurance:" << endurance << " Vitesse : " << vitesse << std::endl;
}

void Magicien::AfficheStatAv(myWindow& _window, sf::Text texte) {
	texte.setString(GetName() + "\nVit: " + std::to_string(GetVitesse()) + "\nPV: " + std::to_string(GetPV()) + "\nAtk: " + std::to_string(GetAttaque()) + "\nDef: " + std::to_string(GetDefense()) + "\nMana: " + std::to_string(GetMana()) + "\nElement: \n Vent");
	_window.Draw(texte);
}