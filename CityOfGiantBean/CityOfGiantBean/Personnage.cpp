#include "Personnage.h"

extern std::string NomElement;
extern std::string NomJob;

Personnage::Personnage(){
	name = save::getpseudo1();
	NomElement = "None";
	element = None;
	niveau = 1;
	pv = 2000;
	defense = 100;
	attaque = 200;
	mana = 20;
	endurance = 50; // /100
	vitesse = 15; // /100
	lootCuivre = 0 ;
	lootFourrure = 0 ;
	lootFer = 0 ;
	lootCuire = 0 ;
	NbFillet = 0;
	NbSuperFillet = 0;
}

Personnage::~Personnage(){
}

Personnage::Personnage(std::string _name, int _niveau, int _pv, int _defense, int _attaque, int _argent, int _mana, int _endurance, int _vitesse)
{
	name = _name;
	niveau = _niveau;
	pv = _pv;
	defense = _defense;
	attaque = _attaque;
	argent = _argent;
	mana = _mana;
	endurance = _endurance;
	vitesse = _vitesse;
	Totargent = argent;
}

std::string Personnage::GetNomElem(){
	switch (element)
	{
	case Feu:
		return "Feu";
		break;
	case Eau:
		return "Eau";
		break;
	case Vent:
		return "Vent";
		break;
	case Terre:
		return "Terre";
		break;
	case Lumiere:
		return "Lumiere";
		break;
	case Ombre:
		return "Ombre";
		break;
	case None:
		return "none";
		break;
	default:
		return "defaut";
		break;
	}
}

void Personnage::DisplayStat() {
	std::cout << name << " Niv: " << niveau << "Job: " << NomJob << " Pv: " << Totpv << " Defense: " << Totdefense << " Attaque: " << Totattaque << " Argent: " << Totargent << " Mana: " << Totmana << " Endurance: " << Totendurance << " Vitesse: " << Totvitesse << " Element: " << NomElement << std::endl;
}

void Personnage::AfficheStats(myWindow& _window, sf::Text texte){
	texte.setString(GetName() + "\nVit: " + std::to_string(GetTotVitesse()) + "\nPV: " + std::to_string(GetTotPv()) + "\nAtk: " + std::to_string(GetTotAttaque()) + "\nDef: " + std::to_string(GetTotDefense()) + "\nMana: " + std::to_string(GetTotMana()) + "\nElement: \n" + GetNomElem());
	_window.Draw(texte);
}

void Personnage::ChangeStatNiveau(int _niveau)
{
	pv = pv * 1.2f;
	defense = defense * 1.2f;
	attaque = attaque * 1.2f;
	mana = mana * 1.2f;
	vitesse = vitesse * 1.2f;
	/*pv = pv * ((_niveau - 1) * 1.2f);
	defense = defense * ((_niveau - 1) * 1.2f);
	attaque = attaque * ((_niveau - 1) * 1.2f);
	mana = mana * ((_niveau - 1) * 1.2f);
	vitesse = vitesse * ((_niveau - 1) * 1.2f);*/
	UpdateStatsJob();
}

void Personnage::ChangeStatNiveau2(int _niveau)
{
	if (_niveau <= 1)
		pv = GetPv();
	else
		pv = pv * 1.2f;
	if (_niveau <= 1)
		defense = GetDefense();
	else
		defense = defense * 1.2f;
	if (_niveau <= 1)
		attaque = GetAttaque();
	else
		attaque = attaque * 1.2f;
	if (_niveau <= 1)
		vitesse = GetVitesse();
	else
		vitesse = vitesse * 1.2f;
	/*if (_niveau <= 1)
		pv = GetPv();
	else
		pv = pv * ((_niveau - 1) * 1.2f);
	if (_niveau <= 1)
		defense = GetDefense();
	else
		defense = defense * ((_niveau - 1) * 1.2f);
	if (_niveau <= 1)
		attaque = GetAttaque();
	else
		attaque = attaque * ((_niveau - 1) * 1.2f);
	if (_niveau <= 1)
		vitesse = GetVitesse();
	else
		vitesse = vitesse * ((_niveau - 1) * 1.2f);*/
	 
	UpdateStatsJob();
}

void Personnage::UpdateStatsJob()
{
	Totpv = pv + job.GetPV();
	Totvitesse = vitesse + job.GetVitesse();
	Totendurance = endurance + job.GetEndurance();
	Totdefense = defense + job.GetDefense() + mon_armure.GetRes();
	Totattaque = attaque + job.GetAttaque() + mon_arme.GetDegat();
	Totmana = mana + job.GetMana() + mon_arme.GetMana() + mon_armure.GetMana();
}