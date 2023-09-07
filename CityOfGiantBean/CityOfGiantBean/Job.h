#pragma once
#include "Tools.h"

class Job
{
protected:

	std::string nameJob;
	int pv;
	int defense;
	int attaque;
	//int argent;
	int mana;
	int endurance;
	int vitesse;

public:

	enum Effets
	{
		Poison,
		Tank,
		Brulure,
		Soin,
	}effet;

	Job();//constructeur 1
	~Job();
	void DisplayStat();
	inline std::string GetName() { return nameJob; }
	inline void SetName(std::string _nameJob) { nameJob = _nameJob; }
	inline int GetPV() { return pv; }
	inline void SetPV(int _pv) { pv = _pv; }
	inline int GetDefense() { return defense; }
	inline void SetDefense(int _defense) { defense = _defense; }
	inline int GetAttaque() { return attaque; }
	inline void SetAttaque(int _attaque) { attaque = _attaque; }
	//inline int GetArgent() { return argent; }
	//inline void SetArgent(int _argent) { argent = _argent; }
	inline int GetMana() { return mana; }
	inline void SetMana(int _mana) { mana = _mana; }
	inline int GetEndurance() { return endurance; }
	inline void SetEndurance(int _endurance) { endurance = _endurance; }
	inline int GetVitesse() { return vitesse; }
	inline void SetVitesse(int _vitesse) { vitesse = _vitesse; }
	inline void SetEffet(Effets _effet) { effet = _effet; }
	inline int GetEffet() { return effet; }

	//void Aptitude(Effets _effet);
};
