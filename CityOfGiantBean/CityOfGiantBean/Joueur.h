#pragma once
#include "Personnage.h"
#include "Game.h"

class Joueur :  public Personnage
{
	int TotalExp;
	int skillPoint;
	int niveauSkill;
	int choixSkill;
	int choixS;

	int choixUseObjet;
	float timerCombat;
	int choixCaseCombatJoueur;
	sf::Vector2f posCaseJoueur;
	sf::Vector2f posCaseEnnemi;
	sf::RectangleShape CaseCombat;
	bool boolCaseCombat;

	bool persoSelected;

	sf::Font fontA;

	bool bCombat;
public:

	int MonterNiveau() {
		return TotalExp - exp;
	}

	bool Branche1, Branche2, Branche3, Branche4, UnlockBranche, choixSkillTree;
	std::string stPseudo, stStats;
	sf::Text txPseudo;

	int EpeeBuy;
	int LanceBuy;
	int BatonBuy;
	int BouclierBuy;
	int LourdBuy;
	int LegerBuy;
	int SoinPvBuy;
	int SoinManaBuy;
	int BombeBuy;
	int iPotionMy{ 0 };

	int NbMonstreBattu{ 0 }, NbEnnemiBattu{ 0 }, NbMonstreCapture{ 0 }, NbGob{ 0 }, NbOrc{ 0 }, NbLoup{ 0 }, NbOurs{ 0 }, NbPersoBattu{ 0 }, NbMag{ 0 }, NbGuer{ 0 }, NbClerc{ 0 }, NbAss{ 0 }, iChgElem{ 0 }, iChgClasse{ 0 }, iAchat{ 0 }, iFabrique{ 0 }, iBossAv{ 0 };

	int iCatchGob{ 0 }, iCatchOrc{ 0 }, iCatchLoup{ 0 }, iCatchOurs{ 0 }, iCatchGobOurs{ 0 }, iCatchGobLoup{ 0 }, iCatchOursOrc{ 0 }, iCatchLouRoc{ 0 };

	int iPoison{0}, iImmunite{ 0 }, iBoostAtk{ 0 }, iBoostDef{ 0 };

	int expDemande;
	int exp;

	int AnnulAtk;

	bool armeEquipe, armureEquipe, bEpeeEquip{ false }, bLanceEquip{ false }, bBagueEquip{ false }, bLegerEquip{ false }, bLourdEquip{ false }, bBouclierEquip{ false }, bChoixPseudo{ false }, bConfirmPseudo{ false };
	int soinPvEquipe{ 0 }, soinManaEquipe{0}, bombeEquipe{0};

	bool SKILL[9];
	Joueur();
	~Joueur();

	int GetSkillPoint() { return skillPoint; }
	void SetSkillPoint(int value) { skillPoint = value; }

	void Experience(int _xp);
	void SetJob(Job& _job);
	void SetEffet(Job::Effets& _effet);
	inline Job GetJob() { return job; }
	inline int GetSexe() { return choixS; }

	inline bool GetEquipEpee() { return bEpeeEquip; }
	inline bool GetEquipLance() { return bLanceEquip; }
	inline bool GetEquipBague() { return bBagueEquip; }
	inline bool GetEquipLeger() { return bLegerEquip; }
	inline bool GetEquipLourd() { return bLourdEquip; }
	inline bool GetEquipBoucclier() { return bBouclierEquip; }

	void skillTree();
	void UseSkill(Joueur& _perso1, Joueur& _perso2);

	float ChoixElement(Elements _elementAtk, Elements _elementDef);

	void initPerso();
	void updatePerso(myWindow& _window, ModeGame _mode);
	void displayPerso(myWindow& _window, ModeGame _mode);
	void directionCombat();

	void ChoixObjetCombat(Personnage& _perso1, Personnage& _perso2, Consos _conso);
	void UseSoinPvCombat(Personnage& _perso1, Consos _conso);
	void UseSoinMCombat(Personnage& _perso1, Consos _conso);
	void UseBombeCombat(Personnage& _perso1, Personnage& _perso2, Consos _conso);

	std::string ArmeEquiper();
	std::string ArmureEquiper();

};

