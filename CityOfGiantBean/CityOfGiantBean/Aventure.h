#pragma once
#include "Tools.h"
#include "Game.h"
#include "Joueur.h"

class Joueur;
class Assassin;
class Guerrier;
class Clerc;
class Magicien;
class Villagois;
class Consos;
//class Personnage;

class Aventure
{

public:

	int _choixAttaque, AnnulAtk = 1, iZoneAv{ 1 };

	std::vector<Joueur*> ennemis;

	void initEnnemi();
	void UpdateAventure(Joueur& _perso1, ModeGame& _mode, Consos& _conso, AventureGame& _modeAv);
	void ChoixActionAv();
	void combatAventureAss(Joueur& _perso1, Assassin& _perso2, Consos& _conso, ModeGame& _mode, int _numPerso);
	void combatAventureMag(Joueur& _perso1, Magicien& _perso2, Consos& _conso, ModeGame& _mode, int _numPerso);
	void combatAventureGuer(Joueur& _perso1, Guerrier& _perso2, Consos& _conso, ModeGame& _mode, int _numPerso);
	void combatAventureClerc(Joueur& _perso1, Clerc& _perso2, Consos& _conso, ModeGame& _mode, int _numPerso);
	void combatAventureVill(Joueur& _perso1, Villagois& _perso2, Consos& _conso, ModeGame& _mode);
	void Fuite(Joueur& _perso1, Joueur& _perso2, ModeGame& _mode);
	void displayAventure(myWindow& _window, ModeGame& _mode, Joueur& _perso1, AventureGame& _modeAv);
};
	void ChoixObjetAventure(Joueur& _perso1, Joueur& _perso2, Consos& _conso, int _def, int _pv, Personnage::Elements _element);
	void ChoixActionSkill(Joueur& _perso1, Joueur& _perso2, Consos& _conso, int _def, int _pv, Personnage::Elements _element);

