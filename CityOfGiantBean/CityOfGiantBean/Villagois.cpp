#include "Villagois.h"

Villagois::Villagois()
{
	nameJob = "Vilagois";
	pv = 0;
	defense = 0;
	attaque = 0;
	//argent = 0;
	mana = 0;
	endurance = 0; // /100
	vitesse = 0; // /100	
}
void Villagois::ChangeStatNiveau(Villagois _perso, std::string _nameJob, int _pv, int _mana, int _endurance, int _vitesse)
{
	_perso.nameJob = _nameJob;
	_perso.pv = _pv;
	_perso.mana = _mana;
	_perso.endurance = _endurance;
	_perso.vitesse = _vitesse;
}
void Villagois::DisplayStat()
{
	std::cout << "Nom:" << nameJob << " Pv:" << pv << " Mana:" << mana << " Endurance:" << endurance << " Vitesse : " << vitesse << std::endl;

}
void Villagois::AfficheStatAv(myWindow& _window, sf::Text texte) {
	texte.setString(GetName() + "\nVit: " + std::to_string(GetVitesse()) + "\nPV: " + std::to_string(GetPV()) + "\nAtk: " + std::to_string(GetAttaque()) + "\nDef: " + std::to_string(GetDefense()) + "\nMana: " + std::to_string(GetMana()) + "\nElement: \n None");
	_window.Draw(texte);
}

void Villagois::SetStatVillagois(int _pv, int _mana, int _atk, int _def, int _endurance, int _vitesse){
	pv = _pv;
	mana = _mana;
	endurance = _endurance;
	vitesse = _vitesse;
	attaque = _atk;
	defense = _def;
}
