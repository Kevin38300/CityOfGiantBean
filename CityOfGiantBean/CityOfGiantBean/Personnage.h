#pragma once
#include "Tools.h"
#include "Job.h"
#include "Armes.h"
#include "Armures.h"
#include "Consos.h"


class Personnage
{
protected:
	sf::Sprite persoSprite;
	sf::Texture persoMTexture;
	sf::Texture persoFTexture;
	sf::Vector2f vitessePerso;
	sf::IntRect persoRect;
	bool isMoving;
	////////////////////////////
	std::string name;
	int niveau;
	int pv;
	int defense;
	int attaque;
	int argent;
	int mana;
	int endurance;
	int vitesse;
	float degatsElem;
	////////////////////////////
	int Totpv;
	int TotpvMax;
	int Totdefense;
	int Totattaque;
	int Totargent;
	int Totmana;
	int TotmanaMax;
	int Totendurance;
	int Totvitesse;
	////////////////////////////
	int lootCuivre;
	int lootFourrure;
	int lootFer;
	int lootCuire;
	////////////////////////////
	int NbFillet;
	int NbSuperFillet;
	////////////////////////////

	Job job;
	Armes mon_arme;
	Armures mon_armure;
	Consos ma_conso;

public:
	int persoFrameX;
	int persoFrameY;
	sf::Vector2f persoPosition;
	enum Elements
	{
		Feu,
		Eau,
		Terre,
		Vent,
		Ombre,
		Lumiere,
		None
	}element;

	float animTime = 0.0f;

	inline std::string GetName() { return name; }
	inline void SetName(std::string _name) { name = _name; }

	inline int GetNiveau() { return niveau; }
	inline void SetNiveau(int _value) { niveau = _value; }

	inline sf::Vector2f GetPos() { return persoPosition; }

	inline int GetPv() { return pv; }
	inline int GetTotPv() { return Totpv; }
	inline int GetTotPvMax() { return pv + job.GetPV(); }
	inline void SetPv(int _value) { pv = _value; }
	inline void SetTotPv(int _value) { Totpv = _value; }
	inline void SetTotPvMax(int _value) { TotpvMax = _value; }

	inline int GetDefense() { return defense; }
	inline int GetTotDefense() { return Totdefense; }
	inline void SetDefense(int _value) { defense = _value; }
	inline void SetTotDefense(int _value) { Totdefense = _value; }

	inline int GetAttaque() { return attaque; }
	inline int GetTotAttaque() { return Totattaque; }
	inline void SetAttaque(int _value) { attaque = _value; }
	inline void SetTotAttaque(int _value) { Totattaque = _value; }

	inline int GetArgent() { return argent; }
	inline int GetTotArgent() { return Totargent; }
	inline void SetArgent(int _value) { argent = _value; }
	inline void SetTotArgent(int _value) { Totargent = _value; }
	inline void AjoutAArgent(int value) { Totargent += value; }

	inline int GetMana() { return mana; }
	inline int GetTotMana() { return Totmana; }
	inline int GetTotManaMax() { return mana + mon_arme.GetMana() + mon_armure.GetMana() + job.GetMana(); }
	inline void SetMana(int _value) { mana = _value; }
	inline void SetTotMana(int _value) { Totmana = _value; }
	inline void SetTotManaMax(int _value) { TotmanaMax = _value; }

	inline int GetEndurance() { return endurance; }
	inline int GetTotEndurance() { return endurance; }
	inline void SetEndurance(int _value) { Totendurance = _value; }
	inline void SetTotEndurance(int _value) { Totendurance = _value; }

	inline int GetVitesse() { return vitesse; }
	inline int GetTotVitesse() { return Totvitesse; }
	inline void SetVitesse(int _value) { vitesse = _value; }
	inline void SetTotVitesse(int _value) { Totvitesse = _value; }

	int GetFillet() { return NbFillet; }
	int GetSuperFillet() { return NbSuperFillet; }
	void SetFillet(int _value) { NbFillet = _value; }
	void SetSuperFillet(int _value) { NbSuperFillet = _value; }

	inline void SetRect(sf::IntRect _persoRect) { persoRect = _persoRect; }

	int GetLootCuivre() { return lootCuivre; }
	void SetLootCuivre(int _value) { lootCuivre = _value; }
	int GetLootFer() { return lootFer; }
	void SetLootFer(int _value) { lootFer = _value; }
	int GetLootCuire() { return lootCuire; }
	void SetLootCuire(int _value) { lootCuire = _value; }
	int GetLootFourrure() { return lootFourrure; }
	void SetLootFourrure(int _value) { lootFourrure = _value; }

	inline void SetArme(Armes _arme) { mon_arme = _arme; }
	inline Armes GetArme() { return mon_arme; }
	inline void SetArmure(Armures _armure) { mon_armure = _armure; }
	inline Armures GetArmure() { return mon_armure; }
	inline Consos GetConso() { return ma_conso; }

	Personnage();//constructeur 1
	~Personnage();//destructeur 1
	Personnage(std::string _name, int _niveau, int _pv, int defense, int attaque, int argent, int _mana, int _endurance, int _vitesse); //constructeur 2

	Elements GetElement() {return element;}
	std::string GetNomElem();
	inline float GetDegatElement() {return degatsElem;}
	inline void SetElement(Elements _element) {element = _element;}
	//void ChoixElement(Elements _elementAtk, Elements _elementDef);
	void DisplayStat();
	void AfficheStats(myWindow& _window, sf::Text texte);
	void ChangeStatNiveau(int _niveau);
	void ChangeStatNiveau2(int _niveau);
	void UpdateStatsJob();
};

