#pragma once
#include "Tools.h"
#include "Game.h"

class Joueur;
class Monstre;
class Consos;

class Safarie
{
	sf::RectangleShape rsRoiGobelin, rsRoiOurs, rsRoiOrc, rsRoiLoup, rsRanger, rsLoup, rsGobelin, rsOurs, rsOrc;

	sf::Vector2f posRoiGoblein, posRoiOurs, posRoiOrc, posRoiLoup, posGobelin, posOurs, posOrc, posLoup, posRanger, posText, posSavePosition, posCombatSafari, posCombatMonstre, posSaveMonstre;

	sf::Vector2f rsize{ 50,50 };

	int irsVieGobelin{ 1 }, irsVieOrc{ 1 }, irsVieOurs{ 1 }, irsVieLoup{ 1 }, choixActionS{1}, choixActionO{1}, choixskill{1}, iAtkFini{0}, iDescCombat{0}, iChoixCote{0}, iNbGob{1}, iNbOrc{0}, iNbLoup{0}, iNbOurs{0};

	float timerrsGob{ 0.0f }, timerrsLoup{ 0.0f }, timerrsOurs{ 0.0f }, timerrsOrc{ 0.0f }, timerChoixActionS{ 0.0f }, timerChoixActionO{ 0.0f }, timerChoixSkill{ 0.0f }, timerDescritionCombat{ 0.0f }, fTmp{ 0.0f };

	bool bColRanger{false}, bColLoup{false}, bColOurs{false}, bColOrc{false}, bColGobelin{false}, bColRoiMonstre{false}, bIsSkill{false}, bChoixAction, bAtkPerso, bAtkMonstre, bFuite{false}, bDescCombatP, bDescCombatM, bDescCombat, bVictory{false}, bDefaite{false}, bLoot{false}, bChoixObjet{false}, bChoixSkill{false}, bCombatMonstre{false}, bElevation{false}, bTmp{false}, bLvlUp{false}, bTimeRanger{false},bCatch{false};

	sf::IntRect	tmpRect, rectLoup, rectOurs, rectGobelin, rectOrc,rectCLoup, rectCOurs, rectCGobelin, rectCOrc;

	sf::Text txParoleSafarie, DetailActionAventureS, AventureFuiteS, AventureObjetS, AventureSkillS, AventureAttaqueS, ActionAventureS, txStatsPerso, txStatsMonstre, txDescCombat, txElevation, txLevelUp;

	std::string stParoleSafarie, stDescCombatP, stDescCombatM, stNbDegP, stNbDegM, stNomMonstre, stDegatInflige, stVictory, stDefaite, stObj, stFuiteR, stFuiteok, stPoison, stImmunite, stBoostAtk, stBoostDef, stElevation, stCatch, stNonCatch, stLoot;
	std::string stParoleSafarieEn, stDescCombatPEn, stDescCombatMEn, stNbDegPEn, stNbDegMEn, stNomMonstreEn, stDegatInfligeEn, stVictoryEn, stDefaiteEn, stObjEn, stFuiteREn, stFuiteokEn, stPoisonEn, stImmuniteEn, stBoostAtkEn, stBoostDefEn, stElevationEn, stCatchEn, stNonCatchEn, stLootEn;

	sf::Text ActionAventure, DetailActionAventure, AventureAttaque, AventureSkill, AventureObjet, AventureFuite, txSoinPV, txSoinMana, txBombe, txFilet, txSFilet, txSkill1, txSkill2, txSkill3, txSkill4, txRetourAction;

	sf::Texture ttLoup, ttOurs, ttGobelin, ttOrc;

	sf::Sprite spLoup, spOurs, spGobelin, spOrc;


	float degatFinal, PvRestant;
	sf::Font fontS;

	sf::SoundBuffer SonG_wooshBuff, SonG_AktPBuff, SonG_AtkMBuff, SonG_PVpBuff, SonG_PVmBuff;

	sf::Sound SonG_woosh, SonG_AktP, SonG_AtkM, SonG_PVp, SonG_PVm;
	
public:
	int _choixAttaque, AnnulAtk = 1, iZonzSafari{ 1 };
	std::vector<Monstre*> monstres;

	void SetZone(int value) { iZonzSafari = value; }

	void initSafari();
	void initMonstreSafari();
	void updateSafari(Joueur& _perso1, ModeGame& _mode, Consos& _conso);
	void combatSafari(Joueur& _perso1, Monstre& _monstre1, Consos& _conso, ModeGame& _mode);
	void ChoixObjetAventure(Joueur& _perso1, Monstre& _monstre1, Consos& _conso);
	void drawSafari(myWindow& _window, ModeGame& _mode, Joueur& _perso1);
	void TimerRespawn(float timer, int Vie);
	void ChoixActionSafarie();
	void ChoixActionSkill(Joueur& _perso1, Monstre& _monstre1, Consos& _conso);
	void ChoixCote();
	void Fuite(Joueur& _perso1, Monstre& _monstre1, ModeGame& _mode);
	void Catch(Joueur& _perso1, Monstre& _monstre1, ModeGame& _mode);
	void Loot(Joueur& _perso1);
};

