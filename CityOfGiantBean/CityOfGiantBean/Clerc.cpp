#include "Clerc.h"

Clerc::Clerc()
{
	nameJob = "Clerc";
	pv = 500;
	defense = 250;
	attaque = 200;
	//argent = 10000;
	mana = 250;
	endurance = 10; // /100
	vitesse = 50; // /100
	effet = Soin;
}

void Clerc::ChangeStatNiveau(Clerc _perso, std::string _nameJob, int _pv, int _mana, int _endurance, int _vitesse)
{
	_perso.nameJob = _nameJob;
	_perso.pv = _pv;
	_perso.mana = _mana;
	_perso.endurance = _endurance;
	_perso.vitesse = _vitesse;
}

void Clerc::DisplayStat()
{
	std::cout << "Nom:" << nameJob << " Pv:" << pv << " Mana:" << mana << " Endurance:" << endurance << " Vitesse : " << vitesse << std::endl;
}
void Clerc::AfficheStatAv(myWindow& _window, sf::Text texte) {
	texte.setString(GetName() + "\nVit: " + std::to_string(GetVitesse()) + "\nPV: " + std::to_string(GetPV()) + "\nAtk: " + std::to_string(GetAttaque()) + "\nDef: " + std::to_string(GetDefense()) + "\nMana: " + std::to_string(GetMana()) + "\nElement: \n Eau");
	_window.Draw(texte);
}
