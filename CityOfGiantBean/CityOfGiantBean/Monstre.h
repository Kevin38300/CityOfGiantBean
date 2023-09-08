#pragma once
#include "Personnage.h"

enum TYPE_MONSTRE { LOUP, ORC, GOBELIN, OURS };

class Monstre : public Personnage
{
protected:
	std::string nomM, nameElement;
	int pv, totpv;
	int defense, totdef;
	int attaque, totatk;
	int vitesse, totvit;
	int niveau;

public:

	enum Materiaux
	{
		Cuivre,
		Fer,
		Cuire,
		Fourrure,
	}materiaux;

	Monstre();
	void DisplayStatM();
	void SetMonstre(Monstre& _monstre);
	void ChangeStatNiveau(int _niveau, Monstre& _monstre);

	inline int GetNiveau() { return niveau; }
	int GetPV()	{return pv;}
	int GettotPV()	{return totpv;}
	void SettotPV(int _value) {totpv = _value;}
	void SetPV(int _value) {pv = _value;}
	int GetDefense() { return defense; }
	int GettotDefense() { return totdef; }
	void SetDefense(int _value) { defense = _value;}
	void SettotDefense(int _value) { totdef = _value;}
	int GetAttaque() { return attaque; }
	int GettotAttaque() { return totatk; }
	void SetAttaque(int _value) { totatk = _value;}
	void SettotAttaque(int _value) { attaque = _value;}
	int GetVitesse() { return vitesse; }
	int GettotVitesse() { return totvit; }
	void SetVitesse(int _value) { totvit = _value;}
	void SettotVitesse(int _value) { vitesse = _value;}
	std::string GetName() {return nomM;	}
	std::string GetNameElem() {return nameElement;	}
	void SetName(std::string _name) {nomM = _name;}
	void SetNameElement(std::string _name) {nameElement = _name;}
	void AfficheStatsM(myWindow& _window, sf::Text texte);
	Elements GetElement(){ return element; }
	void RestartState();

	//void GetLoot(Personnage& _perso1);
	//void combat(Personnage& _perso1);
};

/// ////////////////////////////////////////////////  Gobelin  //
 
class Gobelin : public Monstre
{
public:
	Gobelin();
	void GetLoot(Personnage& _perso1);
	void combat(Personnage& _perso1);
};

/// ////////////////////////////////////////////////  Loup  //

class Loup : public Monstre
{
public:
	Loup();
	void GetLoot(Personnage& _perso1);
	void combat(Personnage& _perso1);
};

/// ////////////////////////////////////////////////  Orc  //

class Orc : public Monstre
{
public:
	Orc();
	void GetLoot(Personnage& _perso1);
	void combat(Personnage& _perso1);
};



/// ////////////////////////////////////////////////  Ours  //

class Ours : public Monstre
{
public:
	Ours();
	void GetLoot(Personnage& _perso1);
	void combat(Personnage& _perso1);
};

