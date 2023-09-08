#include "Monstre.h"

Monstre::Monstre()
{
	//nomM = "default";
	//pv = 0;
	//defense = 0;
	//attaque = 0;
	//vitesse = 0; // /100
}

void Monstre::DisplayStatM() {
	std::cout << "name : " << nomM << " Pv:" << pv << " Defense : " << defense << " Attaque : " << attaque << " Vitesse : " << vitesse << std::endl;
}

void Monstre::SetMonstre(Monstre& _monstre) {

	pv = _monstre.GetPV();
	totpv = pv;
	defense = _monstre.GetDefense();
	totdef = defense;
	attaque = _monstre.GetAttaque();
	totatk = attaque;
	vitesse = _monstre.GetVitesse();
	totvit = vitesse;
	element = _monstre.GetElement();
	nameElement = _monstre.GetNameElem();
	niveau = _monstre.GetNiveau();
}

void Monstre::ChangeStatNiveau(int _niveau, Monstre& _monstre) {
	if (_niveau <= 1)
		pv = _monstre.GetPV();
	else
		pv = _monstre.GetPV() * ((_niveau - 1) * 1.5f);
	if (_niveau <= 1)
		defense = _monstre.GetDefense();
	else
		defense = _monstre.GetDefense() * ((_niveau - 1) * 1.5f);
	if (_niveau <= 1)
		attaque = _monstre.GetAttaque();
	else
		attaque = _monstre.GetAttaque() * ((_niveau - 1) * 1.5f);
	if (_niveau <= 1)
		vitesse = _monstre.GetVitesse();
	else
		vitesse = _monstre.GetVitesse() * ((_niveau - 1) * 1.5f);


}

void Monstre::AfficheStatsM(myWindow& _window, sf::Text texte) {
	texte.setString(GetName() + "\nVit: " + std::to_string(GetVitesse()) + "\nPV: " + std::to_string(GetPV()) + "\nAtk: " + std::to_string(GetAttaque()) + "\nDef: " + std::to_string(GetDefense()) + "\nElement: \n" + GetNameElem());
	_window.Draw(texte);

}

void Monstre::RestartState() {

}

///////////////////////////////////////////////    Gobelin

Gobelin::Gobelin() {
	nomM = "Gobelin";
	attaque = 110;
	defense = 100;
	vitesse = 10;
	pv = 200;
	materiaux = Cuivre;
	lootCuivre = 1;
	element = Eau;
	nameElement = "Eau";
	niveau = 1;
}

void Gobelin::GetLoot(Personnage& _perso1) {
	int _loot = _perso1.GetLootCuivre() + 1;
	_perso1.SetLootCuivre(_loot);
}

void Gobelin::combat(Personnage& _perso1) {

}

///////////////////////////////////////////////    Orc

Orc::Orc() {
	nomM = "Orc";
	attaque = 550;
	defense = 250;
	vitesse = 20;
	pv = 1000;
	materiaux = Fer;
	lootFer = 1;
	element = Terre;
	nameElement = "Terre";
	niveau = 1;
}

void Orc::GetLoot(Personnage& _perso1) {
	int _loot = _perso1.GetLootFer() + 1;
	_perso1.SetLootFer(_loot);
}

void Orc::combat(Personnage& _perso1) {

}

///////////////////////////////////////////////    Loup

Loup::Loup() {
	nomM = "Loup";
	attaque = 210;
	defense = 210;
	vitesse = 70;
	pv = 500;
	materiaux = Fourrure;
	lootFourrure = 1;
	element = Feu;
	nameElement = "Feu";
	niveau = 1;
}

void Loup::GetLoot(Personnage& _perso1) {
	int _loot = _perso1.GetLootFourrure() + 1;
	_perso1.SetLootFourrure(_loot);
}

void Loup::combat(Personnage& _perso1) {

}

///////////////////////////////////////////////    Ours  

Ours::Ours() {
	nomM = "Ours";
	attaque = 400;
	defense = 350;
	vitesse = 20;
	pv = 2000;
	materiaux = Cuire;
	lootCuire = 1;
	element = Vent;
	nameElement = "Vent";
	niveau = 1;
}

void Ours::GetLoot(Personnage& _perso1) {
	int _loot = _perso1.GetLootCuire() + 1;
	_perso1.SetLootCuire(_loot);
}

void Ours::combat(Personnage& _perso1) {
}

