#include "Assassin.h"

Assassin::Assassin()
{
	nameJob = "Assassin";
	pv = 300;
	defense = 50;
	attaque = 500;
	//argent = 10000;
	mana = 10;
	endurance = 100; // /100
	vitesse = 100; // /100
	effet = Poison;
}
void Assassin::ChangeStatNiveau(Assassin _perso, std::string _nameJob, int _pv, int _mana, int _endurance, int _vitesse)
{
	_perso.nameJob = _nameJob;
	_perso.pv = _pv;
	_perso.mana = _mana;
	_perso.endurance = _endurance;
	_perso.vitesse = _vitesse;
}
void Assassin::DisplayStat()
{
	std::cout << "Nom:" << nameJob << " Pv:" << pv << " Mana:" << mana << " Endurance:" << endurance << " Vitesse : " << vitesse << std::endl;

}
void Assassin::AfficheStatAv(myWindow& _window, sf::Text texte) {
	texte.setString(GetName() + "\nVit: " + std::to_string(GetVitesse()) + "\nPV: " + std::to_string(GetPV()) + "\nAtk: " + std::to_string(GetAttaque()) + "\nDef: " + std::to_string(GetDefense()) + "\nMana: " + std::to_string(GetMana()) + "\nElement: \n Feu" );
	_window.Draw(texte);
}