#include "Aventure.h"
#include "Assassin.h"
#include "Guerrier.h"
#include "Clerc.h"
#include "Magicien.h"
#include "Villagois.h"
#include "Consos.h"

#define PlusRapide(_perso1 , _perso2) (((_perso1.GetTotVitesse())>=(_perso2.GetTotVitesse()))?(true):(false))

Villagois villagoisA = Villagois();
Assassin assassinA = Assassin();
Clerc clercA = Clerc();
Magicien magicienA = Magicien();
Guerrier guerrierA = Guerrier();
Joueur VillagoisEnnemi;
Joueur AssassinEnnemi;
Joueur GuerrierEnnemi;
Joueur ClercEnnemi;
Joueur MagicienEnnemi;

sf::RectangleShape rsAss, rsGuer, rsClerc, rsMag, rsVill;

sf::Vector2f posRsAss, posRsGuerr, posRsClerc, posRsMag, posRsVill, postexte, posSavePosition, posCombatAv, posCombatEnemi, posSaveMonstre;

sf::Vector2f rsize{ AjustResoX * 50,AjustResoY * 50 };

sf::Texture ttAss, ttGuer, ttClerc, ttMag, ttVill;

sf::Sprite spAss, spGuer, spClerc, spMag, spVill;
sf::Sprite spAss2, spGuer2, spClerc2, spMag2, spVill2;
sf::Sprite spAss3, spGuer3, spClerc3, spMag3, spVill3;
sf::Sprite spAss4, spGuer4, spClerc4, spMag4, spVill4;

bool bPnj{ false }, bVill{ false }, bAss{ false }, bMag{ false }, bGuer{ false }, bClerc{ false }, bAtkPerso{ false }, bFuite{ false }, bAtkMonstre{ false }, bChoixAction{ false }, bDescCombat{ false }, bChoixObjet{ false }, bChoixSkill{ false }, bIsSkill{ false }, bVictory{ false }, bDefaite{ false };
bool bAss2{ false }, bMag2{ false }, bGuer2{ false }, bClerc2{ false };
bool bAss3{ false }, bMag3{ false }, bGuer3{ false }, bClerc3{ false };
bool bAss4{ false }, bMag4{ false }, bGuer4{ false }, bClerc4{ false };

std::string stParoleAv, stNomEnnemi, stDescCombatP, stDescCombatM, stNbDegP, stNbDegM, stVictory, stDefaite, stBoostAtk, stBoostDef, stPoison, stImmunite, stClercHeal, stFuiteok, stFuiteR, stObj;
std::string stParoleAvEn, stNomEnnemiEn, stDescCombatPEn, stDescCombatMEn, stNbDegPEn, stNbDegMEn, stVictoryEn, stDefaiteEn, stBoostAtkEn, stBoostDefEn, stPoisonEn, stImmuniteEn, stClercHealEn, stFuiteokEn, stFuiteREn, stObjEn;

sf::Text txParoleAv, txStatsPerso, txStatsEnnemi, DetailActionAventureA, ActionAventure, AventureAttaque, AventureSkill, AventureObjet, AventureFuite, txSoinPV, txSoinMana, txSkill1, txSkill2, txSkill3, txSkill4, txBombe, txRetourAction, txDescCombat;

sf::Font fontAv;

int choixskill{ 1 }, irsVieAss{ 1 }, irsVieGuer{ 1 }, irsVieClerc{ 1 }, irsVieMag{ 1 }, irsVieVill{ 1 }, iChoixCote{ 0 }, choixActionA{ 1 }, choixActionO{ 1 }, iDescCombat{ 0 }, iNbAss{ 0 }, iNbGuer{ 0 }, iNbMag{ 0 }, iNbClerc{ 0 }, iNbVill{ 0 };
int irsVieAss2{ 1 }, irsVieGuer2{ 1 }, irsVieClerc2{ 1 }, irsVieMag2{ 1 };
int irsVieAss3{ 1 }, irsVieGuer3{ 1 }, irsVieClerc3{ 1 }, irsVieMag3{ 1 };
int irsVieAss4{ 1 }, irsVieGuer4{ 1 }, irsVieClerc4{ 1 }, irsVieMag4{ 1 };

float timerChoixActionA{ 0.0f }, timerDescritionCombat{ 0.0f }, timerChoixSkill{ 0.0f };
float timerVieAss{ 0.0f }, timerVieAss2{ 0.0f }, timerVieAss3{ 0.0f }, timerVieAss4{ 0.0f };
float timerVieMag{ 0.0f }, timerVieMag2{ 0.0f }, timerVieMag3{ 0.0f }, timerVieMag4{ 0.0f };
float timerVieGuer{ 0.0f }, timerVieGuer2{ 0.0f }, timerVieGuer3{ 0.0f }, timerVieGuer4{ 0.0f };
float timerVieClerc{ 0.0f }, timerVieClerc2{ 0.0f }, timerVieClerc3{ 0.0f }, timerVieClerc4{ 0.0f };

float degatFinal, PvRestant;

void Aventure::initEnnemi() {

	fontAv.loadFromFile("../Ressources/Fonts/Typewriter.ttf");


	VillagoisEnnemi.SetElement(Personnage::None);

	AssassinEnnemi.SetElement(Personnage::Feu);

	GuerrierEnnemi.SetElement(Personnage::Terre);

	ClercEnnemi.SetElement(Personnage::Eau);

	MagicienEnnemi.SetElement(Personnage::Vent);

	ttAss.loadFromFile("..\\Ressources\\Textures\\CLASSE\\Assassin.png");
	spAss.setTexture(ttAss);
	spAss.setScale(0.06, 0.04);
	spAss2.setTexture(ttAss);
	spAss2.setScale(0.06, 0.04);
	spAss3.setTexture(ttAss);
	spAss3.setScale(0.06, 0.04);
	spAss4.setTexture(ttAss);
	spAss4.setScale(0.06, 0.04);
	ttGuer.loadFromFile("..\\Ressources\\Textures\\CLASSE\\Guerrier.png");
	spGuer.setTexture(ttGuer);
	spGuer.setScale(0.2, 0.2);
	spGuer2.setTexture(ttGuer);
	spGuer2.setScale(0.2, 0.2);
	spGuer3.setTexture(ttGuer);
	spGuer3.setScale(0.2, 0.2);
	spGuer4.setTexture(ttGuer);
	spGuer4.setScale(0.2, 0.2);
	ttClerc.loadFromFile("..\\Ressources\\Textures\\CLASSE\\Clerc.png");
	spClerc.setTexture(ttClerc);
	spClerc.setScale(0.18, 0.18);
	spClerc2.setTexture(ttClerc);
	spClerc2.setScale(0.18, 0.18);
	spClerc3.setTexture(ttClerc);
	spClerc3.setScale(0.18, 0.18);
	spClerc4.setTexture(ttClerc);
	spClerc4.setScale(0.18, 0.18);
	ttMag.loadFromFile("..\\Ressources\\Textures\\CLASSE\\Magicien.png");
	spMag.setTexture(ttMag);
	spMag.setScale(0.2, 0.2);
	spMag2.setTexture(ttMag);
	spMag2.setScale(0.2, 0.2);
	spMag3.setTexture(ttMag);
	spMag3.setScale(0.2, 0.2);
	spMag4.setTexture(ttMag);
	spMag4.setScale(0.2, 0.2);
	ttVill.loadFromFile("..\\Ressources\\Textures\\CLASSE\\Villagois.png");
	spVill.setTexture(ttVill);
	spVill.setScale(0.35, 0.35);
	spVill2.setTexture(ttVill);
	spVill2.setScale(0.35, 0.35);
	spVill3.setTexture(ttVill);
	spVill3.setScale(0.35, 0.35);
	spVill4.setTexture(ttVill);
	spVill4.setScale(0.35, 0.35);

	rsAss.setSize(sf::Vector2f(spAss.getGlobalBounds().width, spAss.getGlobalBounds().height));
	rsAss.setFillColor(sf::Color::Cyan);

	rsGuer.setSize(sf::Vector2f(spGuer.getGlobalBounds().width, spGuer.getGlobalBounds().height));
	rsGuer.setFillColor(sf::Color::Red);

	rsClerc.setSize(sf::Vector2f(spClerc.getGlobalBounds().width, spClerc.getGlobalBounds().height));
	rsClerc.setFillColor(sf::Color::Yellow);

	rsMag.setSize(sf::Vector2f(spMag.getGlobalBounds().width, spMag.getGlobalBounds().height));
	rsMag.setFillColor(sf::Color::Green);

	rsVill.setSize(sf::Vector2f(spVill.getGlobalBounds().width, spVill.getGlobalBounds().height));
	rsVill.setFillColor(sf::Color::Black);

	posRsAss = { AjustResoX * 380,AjustResoY * 409 };
	posRsGuerr = { AjustResoX * 1411,AjustResoY * 390 };
	posRsClerc = { AjustResoX * 877,AjustResoY * 835 };
	posRsMag = { AjustResoX * 885,AjustResoY * 112 };
	posRsVill = { AjustResoX * 847,AjustResoY * 378 };

	ennemis.push_back(&VillagoisEnnemi);
	ennemis.push_back(&AssassinEnnemi);
	ennemis.push_back(&GuerrierEnnemi);
	ennemis.push_back(&ClercEnnemi);
	ennemis.push_back(&MagicienEnnemi);

	postexte = { AjustResoX * 150.0f, AjustResoY * 850.0f };
	txParoleAv.setFont(fontAv);
	txParoleAv.setFillColor(sf::Color::Black);

	posCombatAv = { AjustResoX * 349.0f, AjustResoY * 293.0f };
	posCombatEnemi = { AjustResoX * 1275.0f, AjustResoY * 287.0f };

	txStatsPerso.setFont(fontAv);
	txStatsPerso.setOrigin(txStatsPerso.getGlobalBounds().height / 2, txStatsPerso.getGlobalBounds().width / 2);
	txStatsPerso.setPosition(AjustResoX * 32.0f, AjustResoY * 80.0f);
	txStatsPerso.setFillColor(sf::Color::Red);

	txStatsEnnemi.setFont(fontAv);
	txStatsEnnemi.setOrigin(txStatsEnnemi.getGlobalBounds().height / 2, txStatsEnnemi.getGlobalBounds().width / 2);
	txStatsEnnemi.setPosition(AjustResoX * 1526.0f, AjustResoY * 85.0f);
	txStatsEnnemi.setFillColor(sf::Color::Red);

	DetailActionAventureA.setFont(fontAv);
	DetailActionAventureA.setOrigin(DetailActionAventureA.getGlobalBounds().height / 2, DetailActionAventureA.getGlobalBounds().width / 2);
	DetailActionAventureA.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	DetailActionAventureA.setFillColor(sf::Color::Red);

	ActionAventure.setFont(fontAv);
	ActionAventure.setOrigin(ActionAventure.getGlobalBounds().height / 2, ActionAventure.getGlobalBounds().width / 2);
	ActionAventure.setPosition(AjustResoX * 150.0f, AjustResoY * 800.0f);
	ActionAventure.setFillColor(sf::Color::Red);

	AventureAttaque.setFont(fontAv);
	AventureAttaque.setOrigin(AventureAttaque.getGlobalBounds().height / 2, AventureAttaque.getGlobalBounds().width / 2);
	AventureAttaque.setPosition(AjustResoX * 195.0f, AjustResoY * 645.0f);
	AventureAttaque.setFillColor(sf::Color::Red);

	AventureSkill.setFont(fontAv);
	AventureSkill.setOrigin(AventureSkill.getGlobalBounds().height / 2, AventureSkill.getGlobalBounds().width / 2);
	AventureSkill.setPosition(AjustResoX * 470.0f, AjustResoY * 645.0f);
	AventureSkill.setFillColor(sf::Color::Red);

	AventureObjet.setFont(fontAv);
	AventureObjet.setOrigin(AventureObjet.getGlobalBounds().height / 2, AventureObjet.getGlobalBounds().width / 2);
	AventureObjet.setPosition(AjustResoX * 851.0f, AjustResoY * 645.0f);
	AventureObjet.setFillColor(sf::Color::Red);

	AventureFuite.setFont(fontAv);
	AventureFuite.setOrigin(AventureFuite.getGlobalBounds().height / 2, AventureFuite.getGlobalBounds().width / 2);
	AventureFuite.setPosition(AjustResoX * 1188.0f, AjustResoY * 645.0f);
	AventureFuite.setFillColor(sf::Color::Red);

	txDescCombat.setFont(fontAv);
	txDescCombat.setOrigin(txDescCombat.getGlobalBounds().height / 2, txDescCombat.getGlobalBounds().width / 2);
	txDescCombat.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	txDescCombat.setFillColor(sf::Color::Red);

	txSoinPV.setFont(fontAv);
	txSoinPV.setOrigin(txSoinPV.getGlobalBounds().height / 2, txSoinPV.getGlobalBounds().width / 2);
	txSoinPV.setPosition(AjustResoX * 195.0f, AjustResoY * 645.0f);
	txSoinPV.setFillColor(sf::Color::Red);

	txSoinMana.setFont(fontAv);
	txSoinMana.setOrigin(txSoinMana.getGlobalBounds().height / 2, txSoinMana.getGlobalBounds().width / 2);
	txSoinMana.setPosition(AjustResoX * 470.0f, AjustResoY * 645.0f);
	txSoinMana.setFillColor(sf::Color::Red);

	txBombe.setFont(fontAv);
	txBombe.setOrigin(txBombe.getGlobalBounds().height / 2, txBombe.getGlobalBounds().width / 2);
	txBombe.setPosition(AjustResoX * 851.0f, AjustResoY * 645.0f);
	txBombe.setFillColor(sf::Color::Red);

	txSkill1.setFont(fontAv);
	txSkill1.setOrigin(txSkill1.getGlobalBounds().height / 2, txSkill1.getGlobalBounds().width / 2);
	txSkill1.setPosition(AjustResoX * 195.0f, AjustResoY * 645.0f);
	txSkill1.setFillColor(sf::Color::Red);

	txSkill2.setFont(fontAv);
	txSkill2.setOrigin(txSkill2.getGlobalBounds().height / 2, txSkill2.getGlobalBounds().width / 2);
	txSkill2.setPosition(AjustResoX * 470.0f, AjustResoY * 645.0f);
	txSkill2.setFillColor(sf::Color::Red);

	txSkill3.setFont(fontAv);
	txSkill3.setOrigin(txSkill3.getGlobalBounds().height / 2, txSkill3.getGlobalBounds().width / 2);
	txSkill3.setPosition(AjustResoX * 851.0f, AjustResoY * 645.0f);
	txSkill3.setFillColor(sf::Color::Red);

	txSkill4.setFont(fontAv);
	txSkill4.setOrigin(txSkill4.getGlobalBounds().height / 2, txSkill4.getGlobalBounds().width / 2);
	txSkill4.setPosition(AjustResoX * 1188.0f, AjustResoY * 645.0f);
	txSkill4.setFillColor(sf::Color::Red);

	txRetourAction.setFont(fontAv);
	txRetourAction.setOrigin(txRetourAction.getGlobalBounds().height / 2, txRetourAction.getGlobalBounds().width / 2);
	txRetourAction.setPosition(AjustResoX * 1527.0f, AjustResoY * 645.0f);
	txRetourAction.setFillColor(sf::Color::Red);

	tools::ChoixLangue(tools::GetTrad(), ActionAventure, "Choisissez votre action :", "Choose your action:");
	tools::ChoixLangue(tools::GetTrad(), AventureAttaque, "Attaque", "Attack");
	tools::ChoixLangue(tools::GetTrad(), AventureSkill, "Skill", "Skill");
	tools::ChoixLangue(tools::GetTrad(), AventureObjet, "Objet", "Item");
	tools::ChoixLangue(tools::GetTrad(), AventureFuite, "Fuite", "Feel");

	tools::ChoixLangue(tools::GetTrad(), txSkill1, "Skill 1", "Skill 1");
	tools::ChoixLangue(tools::GetTrad(), txSkill2, "Skill 2", "Skill 2");
	tools::ChoixLangue(tools::GetTrad(), txSkill3, "Skill 3", "Skill 3");
	tools::ChoixLangue(tools::GetTrad(), txSkill4, "Skill 4", "Skill 4");

	tools::ChoixLangue(tools::GetTrad(), txSoinPV, "Soin PV", "Healing PV");
	tools::ChoixLangue(tools::GetTrad(), txSoinMana, "Soin Mana", "Healing Mana");
	tools::ChoixLangue(tools::GetTrad(), txBombe, "Bombe", "Bomb");
	tools::ChoixLangue(tools::GetTrad(), txRetourAction, "Retour", "Back");

	stDescCombatP = { "Vous avez attaque le " };
	stDescCombatM = { " vous a attaque" };
	stNbDegP = { ". Les degats inflige sont de : " };
	stNbDegM = { ". Les degats subis sont de :" };
	stVictory = { "\nFelicitation vous avez gagne" };
	stDefaite = { "\nVous avez perdu, le ranger va vous soigner" };

	stDescCombatPEn = { "You attacked the " };
	stDescCombatMEn = { " attacked you" };
	stNbDegPEn = { ". The damage inflicted is : " };
	stNbDegMEn = { ". The damage suffered is :" };
	stVictoryEn = { "\nCongratulations you won" };
	stDefaiteEn = { "\nYou lost, the ranger will heal you" };

	stBoostAtk = { "Votre attaque est augmenter" };
	stBoostDef = { "Votre defense est augmenter" };
	stPoison = { "Vous avez infliger poison au monstre" };
	stImmunite = { "Vous vous etes mis une immunite" };
	stClercHeal = { "L'ennemi a gagner des pv :" };

	stBoostAtkEn = { "Your attack is increasing" };
	stBoostDefEn = { "Your defense is increase" };
	stPoisonEn = { "You have inflicted poison on the monster" };
	stImmuniteEn = { "You have put yourself immunity" };
	stClercHealEn = { "The enemy has gained pv :" };

	stFuiteok = "Vous avez reussi a fuire";
	stFuiteR = "Echec de la fuite";

	stFuiteokEn = "You managed to flee";
	stFuiteREn = "Flee failed";

	boiteDiscussion::initBoiteDiscussion();
}

void Aventure::UpdateAventure(Joueur& _perso1, ModeGame& _mode, Consos& _conso, AventureGame& _modeAv) {
	if (_mode == ModeGame::LIBRE) {

		if (_modeAv == AventureGame::ZONE_MAGE) {
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsMag, sf::Vector2f(spMag.getGlobalBounds().width, spMag.getGlobalBounds().height)) && irsVieMag >= 1) {

				MagicienEnnemi.SetName("Magicien");
				MagicienEnnemi.SetJob(magicienA);
				MagicienEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { MagicienEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= MagicienEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bMag = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsMag;
				posRsMag = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsGuerr, sf::Vector2f(spMag.getGlobalBounds().width, spMag.getGlobalBounds().height)) && irsVieMag >= 1) {

				MagicienEnnemi.SetName("Magicien");
				MagicienEnnemi.SetJob(magicienA);
				MagicienEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { MagicienEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= MagicienEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bMag2 = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsGuerr;
				posRsGuerr = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsClerc, sf::Vector2f(spMag.getGlobalBounds().width, spMag.getGlobalBounds().height)) && irsVieMag >= 1) {

				MagicienEnnemi.SetName("Magicien");
				MagicienEnnemi.SetJob(magicienA);
				MagicienEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { MagicienEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= MagicienEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bMag3 = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsClerc;
				posRsClerc = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsAss, sf::Vector2f(spMag.getGlobalBounds().width, spMag.getGlobalBounds().height)) && irsVieMag >= 1) {

				MagicienEnnemi.SetName("Magicien");
				MagicienEnnemi.SetJob(magicienA);
				MagicienEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { MagicienEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= MagicienEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bMag4 = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsAss;
				posRsAss = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (irsVieMag <= 0) {
				timerVieMag += tools::GetTimeDelta();
				if (timerVieMag >= 10.0f) {
					irsVieMag = 1;
				}
			}
			else
				timerVieMag = 0.0f;
			if (irsVieMag2 <= 0) {
				timerVieMag2 += tools::GetTimeDelta();
				if (timerVieMag2 >= 10.0f) {
					irsVieMag2 = 1;
				}
			}
			else
				timerVieMag2 = 0.0f;
			if (irsVieMag3 <= 0) {
				timerVieMag3 += tools::GetTimeDelta();
				if (timerVieMag3 >= 10.0f) {
					irsVieMag3 = 1;
				}
			}
			else
				timerVieMag3 = 0.0f;
			if (irsVieMag4 <= 0) {
				timerVieMag4 += tools::GetTimeDelta();
				if (timerVieMag4 >= 10.0f) {
					irsVieMag4 = 1;
				}
			}
			else
				timerVieMag4 = 0.0f;
		}
		if (_modeAv == AventureGame::ZONE_ASSASSIN) {
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsAss, sf::Vector2f(spAss.getGlobalBounds().width, spAss.getGlobalBounds().height)) && irsVieAss >= 1) {

				AssassinEnnemi.SetName("Assassin");
				AssassinEnnemi.SetJob(assassinA);
				AssassinEnnemi.ChangeStatNiveau2(iZoneAv);
				AssassinEnnemi.SetElement(Personnage::Feu);
				stNomEnnemi = { AssassinEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= AssassinEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bAss = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsAss;
				posRsAss = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsGuerr, sf::Vector2f(spAss.getGlobalBounds().width, spAss.getGlobalBounds().height)) && irsVieAss >= 1) {

				AssassinEnnemi.SetName("Assassin");
				AssassinEnnemi.SetJob(assassinA);
				AssassinEnnemi.ChangeStatNiveau2(iZoneAv);
				AssassinEnnemi.SetElement(Personnage::Feu);
				stNomEnnemi = { AssassinEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= AssassinEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bAss2 = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsGuerr;
				posRsGuerr = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsClerc, sf::Vector2f(spAss.getGlobalBounds().width, spAss.getGlobalBounds().height)) && irsVieAss >= 1) {

				AssassinEnnemi.SetName("Assassin");
				AssassinEnnemi.SetJob(assassinA);
				AssassinEnnemi.ChangeStatNiveau2(iZoneAv);
				AssassinEnnemi.SetElement(Personnage::Feu);
				stNomEnnemi = { AssassinEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= AssassinEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bAss3 = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsClerc;
				posRsClerc = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsMag, sf::Vector2f(spAss.getGlobalBounds().width, spAss.getGlobalBounds().height)) && irsVieAss >= 1) {

				AssassinEnnemi.SetName("Assassin");
				AssassinEnnemi.SetJob(assassinA);
				AssassinEnnemi.ChangeStatNiveau2(iZoneAv);
				AssassinEnnemi.SetElement(Personnage::Feu);
				stNomEnnemi = { AssassinEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= AssassinEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bAss4 = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsMag;
				posRsMag = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (irsVieAss <= 0) {
				timerVieAss += tools::GetTimeDelta();
				if (timerVieAss >= 10.0f) {
					irsVieAss = 1;
				}
			}
			else
				timerVieAss = 0.0f;
			if (irsVieAss2 <= 0) {
				timerVieAss2 += tools::GetTimeDelta();
				if (timerVieAss2 >= 10.0f) {
					irsVieAss2 = 1;
				}
			}
			else
				timerVieAss2 = 0.0f;
			if (irsVieAss3 <= 0) {
				timerVieAss3 += tools::GetTimeDelta();
				if (timerVieAss3 >= 10.0f) {
					irsVieAss3 = 1;
				}
			}
			else
				timerVieAss3 = 0.0f;
			if (irsVieAss4 <= 0) {
				timerVieAss4 += tools::GetTimeDelta();
				if (timerVieAss4 >= 10.0f) {
					irsVieAss4 = 1;
				}
			}
			else
				timerVieAss4 = 0.0f;
		}
		if (_modeAv == AventureGame::ZONE_GUERRIER) {
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsGuerr, sf::Vector2f(spGuer.getGlobalBounds().width, spGuer.getGlobalBounds().height)) && irsVieGuer >= 1) {

				GuerrierEnnemi.SetName("Guerrier");
				GuerrierEnnemi.SetJob(guerrierA);
				GuerrierEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { GuerrierEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= GuerrierEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bGuer = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsGuerr;
				posRsGuerr = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsAss, sf::Vector2f(spGuer.getGlobalBounds().width, spGuer.getGlobalBounds().height)) && irsVieGuer >= 1) {

				GuerrierEnnemi.SetName("Guerrier");
				GuerrierEnnemi.SetJob(guerrierA);
				GuerrierEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { GuerrierEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= GuerrierEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bGuer2 = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsAss;
				posRsAss = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsClerc, sf::Vector2f(spGuer.getGlobalBounds().width, spGuer.getGlobalBounds().height)) && irsVieGuer >= 1) {

				GuerrierEnnemi.SetName("Guerrier");
				GuerrierEnnemi.SetJob(guerrierA);
				GuerrierEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { GuerrierEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= GuerrierEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bGuer3 = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsClerc;
				posRsClerc = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsMag, sf::Vector2f(spGuer.getGlobalBounds().width, spGuer.getGlobalBounds().height)) && irsVieGuer >= 1) {

				GuerrierEnnemi.SetName("Guerrier");
				GuerrierEnnemi.SetJob(guerrierA);
				GuerrierEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { GuerrierEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= GuerrierEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bGuer4 = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsMag;
				posRsMag = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (irsVieGuer <= 0) {
				timerVieGuer += tools::GetTimeDelta();
				if (timerVieGuer >= 10.0f) {
					irsVieGuer = 1;
				}
			}
			else
				timerVieGuer = 0.0f;
			if (irsVieGuer2 <= 0) {
				timerVieGuer2 += tools::GetTimeDelta();
				if (timerVieGuer2 >= 10.0f) {
					irsVieGuer2 = 1;
				}
			}
			else
				timerVieGuer2 = 0.0f;
			if (irsVieGuer3 <= 0) {
				timerVieGuer3 += tools::GetTimeDelta();
				if (timerVieGuer3 >= 10.0f) {
					irsVieGuer3 = 1;
				}
			}
			else
				timerVieGuer3 = 0.0f;
			if (irsVieGuer4 <= 0) {
				timerVieGuer4 += tools::GetTimeDelta();
				if (timerVieGuer4 >= 10.0f) {
					irsVieGuer4 = 1;
				}
			}
			else
				timerVieGuer4 = 0.0f;
		}
		if (_modeAv == AventureGame::ZONE_CLERC) {
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsClerc, sf::Vector2f(spClerc.getGlobalBounds().width, spClerc.getGlobalBounds().height)) && irsVieClerc >= 1) {

				ClercEnnemi.SetName("Clerc");
				ClercEnnemi.SetJob(clercA);
				ClercEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { ClercEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= ClercEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bClerc = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsClerc;
				posRsClerc = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsAss, sf::Vector2f(spClerc.getGlobalBounds().width, spClerc.getGlobalBounds().height)) && irsVieClerc >= 1) {

				ClercEnnemi.SetName("Clerc");
				ClercEnnemi.SetJob(clercA);
				ClercEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { ClercEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= ClercEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bClerc3 = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsAss;
				posRsAss = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsGuerr, sf::Vector2f(spClerc.getGlobalBounds().width, spClerc.getGlobalBounds().height)) && irsVieClerc >= 1) {

				ClercEnnemi.SetName("Clerc");
				ClercEnnemi.SetJob(clercA);
				ClercEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { ClercEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= ClercEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bClerc2 = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsGuerr;
				posRsGuerr = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsMag, sf::Vector2f(spClerc.getGlobalBounds().width, spClerc.getGlobalBounds().height)) && irsVieClerc >= 1) {

				ClercEnnemi.SetName("Clerc");
				ClercEnnemi.SetJob(clercA);
				ClercEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { ClercEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= ClercEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bClerc4 = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsMag;
				posRsMag = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (irsVieClerc <= 0) {
				timerVieClerc += tools::GetTimeDelta();
				if (timerVieClerc >= 10.0f) {
					irsVieClerc = 1;
				}
			}
			else
				timerVieClerc = 0.0f;
			if (irsVieClerc2 <= 0) {
				timerVieClerc2 += tools::GetTimeDelta();
				if (timerVieClerc2 >= 10.0f) {
					irsVieClerc2 = 1;
				}
			}
			else
				timerVieClerc2 = 0.0f;
			if (irsVieClerc3 <= 0) {
				timerVieClerc3 += tools::GetTimeDelta();
				if (timerVieClerc3 >= 10.0f) {
					irsVieClerc3 = 1;
				}
			}
			else
				timerVieClerc3 = 0.0f;
			if (irsVieClerc4 <= 0) {
				timerVieClerc4 += tools::GetTimeDelta();
				if (timerVieClerc4 >= 10.0f) {
					irsVieClerc4 = 1;
				}
			}
			else
				timerVieClerc4 = 0.0f;
		}
		if (_modeAv == AventureGame::AVENTURE) {

			if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posRsVill, sf::Vector2f(spVill.getGlobalBounds().width, spVill.getGlobalBounds().height))) {
				bPnj = true;
				stParoleAv = { "Battez mes 4 sbires si vous pensez pouvoir m'affronter" };
				stParoleAvEn = { "Defeat my 4 minions if you think you can beat me" };
			}
			else
				bPnj = false;

			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsAss, sf::Vector2f(spAss.getGlobalBounds().width, spAss.getGlobalBounds().height)) && irsVieAss >= 1) {

				AssassinEnnemi.SetName("Assassin");
				AssassinEnnemi.SetJob(assassinA);
				AssassinEnnemi.ChangeStatNiveau2(iZoneAv);
				AssassinEnnemi.SetElement(Personnage::Feu);
				stNomEnnemi = { AssassinEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= AssassinEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bAss = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsAss;
				posRsAss = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsGuerr, sf::Vector2f(spGuer.getGlobalBounds().width, spGuer.getGlobalBounds().height)) && irsVieGuer >= 1) {

				GuerrierEnnemi.SetName("Guerrier");
				GuerrierEnnemi.SetJob(guerrierA);
				GuerrierEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { GuerrierEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= GuerrierEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bGuer = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsGuerr;
				posRsGuerr = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsClerc, sf::Vector2f(spClerc.getGlobalBounds().width, spClerc.getGlobalBounds().height)) && irsVieClerc >= 1) {

				ClercEnnemi.SetName("Clerc");
				ClercEnnemi.SetJob(clercA);
				ClercEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { ClercEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= ClercEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bClerc = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsClerc;
				posRsClerc = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsMag, sf::Vector2f(spMag.getGlobalBounds().width, spMag.getGlobalBounds().height)) && irsVieMag >= 1) {

				MagicienEnnemi.SetName("Magicien");
				MagicienEnnemi.SetJob(magicienA);
				MagicienEnnemi.ChangeStatNiveau2(iZoneAv);
				stNomEnnemi = { MagicienEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= MagicienEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bMag = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsMag;
				posRsMag = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
			if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posRsVill, sf::Vector2f(spVill.getGlobalBounds().width, spVill.getGlobalBounds().height)) && iNbAss > 0 && iNbGuer > 0 && iNbClerc > 0 && iNbMag > 0) {

				VillagoisEnnemi.SetName("Boss");
				VillagoisEnnemi.SetJob(villagoisA);
				villagoisA.SetStatVillagois(1000 * iZoneAv, 50 * iZoneAv, 200 * iZoneAv, 200 * iZoneAv, 1000 * iZoneAv, 50 * iZoneAv);
				stNomEnnemi = { VillagoisEnnemi.GetName() };

				if (_perso1.GetTotVitesse() >= VillagoisEnnemi.GetTotVitesse()) {
					bAtkPerso = true;
					bAtkMonstre = false;
					iChoixCote = 1;
				}
				else {
					bAtkPerso = false;
					bAtkMonstre = true;
					iChoixCote = 2;
				}

				bVill = true;
				posSavePosition = _perso1.GetPos();
				_perso1.persoPosition = posCombatAv;
				_perso1.directionCombat();
				posSaveMonstre = posRsVill;
				posRsVill = posCombatEnemi;
				_mode = ModeGame::AVE;
			}
		}
	}
	if (_mode == ModeGame::AVE) {

		if (bAss == true) {
			combatAventureAss(_perso1, assassinA, _conso, _mode, 1, _modeAv);
		}
		if (bAss2 == true) {
			combatAventureAss(_perso1, assassinA, _conso, _mode, 2, _modeAv);
		}
		if (bAss3 == true) {
			combatAventureAss(_perso1, assassinA, _conso, _mode, 3, _modeAv);
		}
		if (bAss4 == true) {
			combatAventureAss(_perso1, assassinA, _conso, _mode, 4, _modeAv);
		}
		if (bClerc == true) {
			combatAventureClerc(_perso1, clercA, _conso, _mode, 1, _modeAv);
		}
		if (bClerc2 == true) {
			combatAventureClerc(_perso1, clercA, _conso, _mode, 2, _modeAv);
		}
		if (bClerc3 == true) {
			combatAventureClerc(_perso1, clercA, _conso, _mode, 3, _modeAv);
		}
		if (bClerc4 == true) {
			combatAventureClerc(_perso1, clercA, _conso, _mode, 4, _modeAv);
		}
		if (bGuer == true) {
			combatAventureGuer(_perso1, guerrierA, _conso, _mode, 1, _modeAv);
		}
		if (bGuer2 == true) {
			combatAventureGuer(_perso1, guerrierA, _conso, _mode, 2, _modeAv);
		}
		if (bGuer3 == true) {
			combatAventureGuer(_perso1, guerrierA, _conso, _mode, 3, _modeAv);
		}
		if (bGuer4 == true) {
			combatAventureGuer(_perso1, guerrierA, _conso, _mode, 4, _modeAv);
		}
		if (bMag == true) {
			combatAventureMag(_perso1, magicienA, _conso, _mode, 1, _modeAv);
		}
		if (bMag2 == true) {
			combatAventureMag(_perso1, magicienA, _conso, _mode, 2, _modeAv);
		}
		if (bMag3 == true) {
			combatAventureMag(_perso1, magicienA, _conso, _mode, 3, _modeAv);
		}
		if (bMag4 == true) {
			combatAventureMag(_perso1, magicienA, _conso, _mode, 4, _modeAv);
		}
		if (bVill == true) {
			combatAventureVill(_perso1, villagoisA, _conso, _mode);
		}
	}
	spAss.setPosition(posRsAss);
	spAss2.setPosition(posRsGuerr);
	spAss3.setPosition(posRsClerc);
	spAss4.setPosition(posRsMag);
	//rsAss.setPosition(posRsAss);
	spGuer.setPosition(posRsGuerr);
	spGuer2.setPosition(posRsAss);
	spGuer3.setPosition(posRsClerc);
	spGuer4.setPosition(posRsMag);
	//rsGuer.setPosition(posRsGuerr);
	spClerc.setPosition(posRsClerc);
	spClerc2.setPosition(posRsGuerr);
	spClerc3.setPosition(posRsAss);
	spClerc4.setPosition(posRsMag);
	//rsClerc.setPosition(posRsClerc);
	spMag.setPosition(posRsMag);
	spMag2.setPosition(posRsGuerr);
	spMag3.setPosition(posRsClerc);
	spMag4.setPosition(posRsAss);
	//rsMag.setPosition(posRsMag);
	spVill.setPosition(posRsVill);
	//rsVill.setPosition(posRsVill);
}


void Aventure::ChoixActionAv() {
	bChoixAction = true;
	timerChoixActionA += tools::GetTimeDelta();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && choixActionA > 1 && timerChoixActionA > 0.3f) {
		choixActionA -= 1;
		timerChoixActionA = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && choixActionA < 4 && timerChoixActionA > 0.3f) {
		choixActionA += 1;
		timerChoixActionA = 0.0f;
	}
	switch (choixActionA)
	{
	case 1:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Attaque : l'attaque de base prend en compte l'attaque du lanceur\n et la defense de la cible puis applique l'avantage selon l'element", "Attack: The basic attack takes into account the attack of the launchern\nand the defense of the target and then applies the advantage according to the element");
		break;
	case 2:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Skill : Permet d'utiliser une competence possede", "Skill: Allows you to use a possesssede skill");
		break;
	case 3:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Objet : Permet d'utilise un objet equipe", "Subject: Allows you to use a team object");
		break;
	case 4:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Fuite : Permet de fuir un combat, si votre vitesse est superieur a celle\n de l'adversaire fuite a 100%, sinon selon une probabilite", "Escape: Allows you to flee a fight, if your speed is higher than that\nof the opponent flight has 100%, otherwise according to a probability");
		break;
	default:
		break;
	}
}

void Aventure::combatAventureAss(Joueur& _perso1, Assassin& _perso2, Consos& _conso, ModeGame& _mode, int _numPerso, AventureGame& _modeAv) {
	bIsSkill = true;
	if (bDescCombat == false && bChoixObjet == false && bChoixSkill == false) {
		txDescCombat.setString("");
		switch (iChoixCote)
		{
		case 1:
			if (bAtkPerso == true && bDescCombat == false && _perso1.GetTotPv() > 0) {
				if (bIsSkill == true) {
					_perso1.iImmunite -= 1;
					_perso1.iBoostAtk -= 1;
					_perso1.iBoostDef -= 1;
					bIsSkill = false;
				}
				ChoixActionAv();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
					bChoixAction = false;
					timerChoixActionA = 0.0f;
					switch (choixActionA)
					{
					case 1:
						if (_perso1.iBoostAtk > 0) {
							degatFinal = (((_perso1.GetTotAttaque() * 1.5) - AssassinEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), AssassinEnnemi.GetElement()));
						}
						else {
							degatFinal = ((_perso1.GetTotAttaque() - AssassinEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), AssassinEnnemi.GetElement()));
						}
						if (degatFinal <= 0)
							degatFinal = 0;
						PvRestant = AssassinEnnemi.GetTotPv() - degatFinal;
						if (PvRestant <= 0)
							PvRestant = 0;
						AssassinEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { AssassinEnnemi.GetName() };
						timerDescritionCombat = 0.0f;
						iDescCombat = 1;
						bDescCombat = true;
						bAtkPerso = false;
						bAtkMonstre = true;
						break;
					case 2:
						bChoixSkill = true;
						break;
					case 3:
						bChoixObjet = true;
						break;
					case 4:
						timerDescritionCombat = 0.0f;
						bFuite = true;
						iDescCombat = 5;
						bDescCombat = true;
						_choixAttaque = 0;
						break;
					default:
						break;
					}
				}
			}
			if (bAtkMonstre == true && bDescCombat == false && AssassinEnnemi.GetTotPv() > 0) {
				if (_perso1.iPoison > 0) {
					int tmp, tmp2;
					tmp = _perso1.GetTotAttaque() * 0.1;
					tmp2 = AssassinEnnemi.GetTotPv() - tmp;
					if (tmp2 < 0)
						tmp2 = 0;
					AssassinEnnemi.SetTotPv(tmp2);
					_perso1.iPoison -= 1;
				}
				if (_perso1.iBoostDef > 0) {
					degatFinal = ((AssassinEnnemi.GetTotAttaque() - (_perso1.GetTotDefense() * 1.5) * _perso1.ChoixElement(_perso1.GetElement(), AssassinEnnemi.GetElement())));
				}
				else {
					degatFinal = ((AssassinEnnemi.GetTotAttaque() - _perso1.GetTotDefense() * _perso1.ChoixElement(_perso1.GetElement(), AssassinEnnemi.GetElement())));
				}
				if (degatFinal <= 0)
					degatFinal = 0;
				if (_perso1.iImmunite > 0)
					degatFinal = 0.0f;
				PvRestant = _perso1.GetTotPv() - degatFinal;
				_perso1.SetTotPv(PvRestant);
				timerDescritionCombat = 0.0f;
				iDescCombat = 2;
				bDescCombat = true;
				bAtkPerso = true;
				bAtkMonstre = false;
			}
			break;
		case 2:
			if (bAtkMonstre == true && bDescCombat == false && AssassinEnnemi.GetTotPv() > 0) {
				if (_perso1.iPoison > 0) {
					int tmp, tmp2;
					tmp = _perso1.GetTotAttaque() * 0.5;
					tmp2 = AssassinEnnemi.GetTotPv() - tmp;
					if (tmp2 < 0)
						tmp2 = 0;
					AssassinEnnemi.SetTotPv(tmp2);
					_perso1.iPoison -= 1;
				}
				if (_perso1.iBoostDef > 0) {
					degatFinal = ((AssassinEnnemi.GetTotAttaque() - (_perso1.GetTotDefense() * 1.5) * _perso1.ChoixElement(_perso1.GetElement(), AssassinEnnemi.GetElement())));
				}
				else {
					degatFinal = ((AssassinEnnemi.GetTotAttaque() - _perso1.GetTotDefense() * _perso1.ChoixElement(_perso1.GetElement(), AssassinEnnemi.GetElement())));
				}
				if (degatFinal <= 0)
					degatFinal = 0;
				if (_perso1.iImmunite > 0)
					degatFinal = 0.0f;
				PvRestant = _perso1.GetTotPv() - degatFinal;
				_perso1.SetTotPv(PvRestant);
				timerDescritionCombat = 0.0f;
				iDescCombat = 2;
				bDescCombat = true;
				bAtkPerso = true;
				bAtkMonstre = false;
			}
			if (bAtkPerso == true && bDescCombat == false && _perso1.GetTotPv() > 0) {
				if (bIsSkill == true) {
					_perso1.iImmunite -= 1;
					_perso1.iBoostAtk -= 1;
					_perso1.iBoostDef -= 1;
					bIsSkill == false;
				}
				ChoixActionAv();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
					bChoixAction = false;
					timerChoixActionA = 0.0f;
					switch (choixActionA)
					{
					case 1:
						if (_perso1.iBoostAtk > 0) {
							degatFinal = (((_perso1.GetTotAttaque() * 1.5) - AssassinEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), AssassinEnnemi.GetElement()));
						}
						else {
							degatFinal = ((_perso1.GetTotAttaque() - AssassinEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), AssassinEnnemi.GetElement()));
						}
						if (degatFinal <= 0)
							degatFinal = 0;
						PvRestant = AssassinEnnemi.GetTotPv() - degatFinal;
						if (PvRestant <= 0)
							PvRestant = 0;
						AssassinEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { AssassinEnnemi.GetName() };
						timerDescritionCombat = 0.0f;
						iDescCombat = 1;
						bDescCombat = true;
						bAtkPerso = false;
						bAtkMonstre = true;
						break;
					case 2:
						bChoixSkill = true;
						break;
					case 3:
						bChoixObjet = true;
						break;
					case 4:
						if (tools::iRand(0, 3) >= 2) {
							timerDescritionCombat = 0.0f;
							std::cout << "fuit reussi" << std::endl;
							bFuite = true;
							iDescCombat = 5;
							bDescCombat = true;
							_choixAttaque = 0;
						}
						else {
							timerDescritionCombat = 0.0f;
							std::cout << "Echec" << std::endl;
							iDescCombat = 6;
							bDescCombat = true;
							bAtkPerso = false;
							bAtkMonstre = true;
							_choixAttaque = 0;
						}

						_choixAttaque = 0;
						break;
					default:
						break;
					}
				}
			}
			break;
		default:
			break;
		}
		if (AssassinEnnemi.GetTotPv() <= 0 || _perso1.GetTotPv() <= 0)
		{
			if (AssassinEnnemi.GetTotPv() <= 0) {
				_perso1.SetTotPv(_perso1.GetTotPvMax());
				_perso1.NbEnnemiBattu += 1;
				_perso1.NbAss += 1;
				iNbAss += 1;
				if (_numPerso == 1)
					irsVieAss = 0;
				if (_numPerso == 2)
					irsVieAss2 = 0;
				if (_numPerso == 3)
					irsVieAss3 = 0;
				if (_numPerso == 4)
					irsVieAss4 = 0;
				_perso1.Experience((30 * AssassinEnnemi.GetNiveau()));
				LootCombat(_perso1, _modeAv);
				bVictory = true;
			}
			if (_perso1.GetTotPv() <= 0) {
				int tmp_arg;
				tmp_arg = _perso1.GetTotArgent() - 100;
				if (tmp_arg <= 0)
					tmp_arg = 0;
				_perso1.SetTotArgent(tmp_arg);
				bDefaite = true;
			}


			if (bDescCombat == false) {
				_perso1.persoPosition.x = posSavePosition.x;
				_perso1.persoPosition.y = posSavePosition.y + 20;
				if (_numPerso == 1) {
					bAss = false;
					posRsAss = posSaveMonstre;
				}
				if (_numPerso == 2) {
					bAss2 = false;
					posRsGuerr = posSaveMonstre;
				}
				if (_numPerso == 3) {
					bAss3 = false;
					posRsClerc = posSaveMonstre;
				}
				if (_numPerso == 4) {
					bAss4 = false;
					posRsMag = posSaveMonstre;
				}
				bVictory = false;
				bDefaite = false;
				_mode = ModeGame::LIBRE;
			}
			_choixAttaque = 0;
			_perso1.iPoison = 0;
			_perso1.iImmunite = 0;
			_perso1.iBoostAtk = 0;
			_perso1.iBoostDef = 0;
		}
	}
	if (bChoixObjet == true && bDescCombat == false) {
		ChoixObjetAventure(_perso1, AssassinEnnemi, _conso, AssassinEnnemi.GetTotDefense(), AssassinEnnemi.GetTotPv(), AssassinEnnemi.GetElement());
	}
	if (bChoixSkill == true && bDescCombat == false) {
		ChoixActionSkill(_perso1, AssassinEnnemi, _conso, AssassinEnnemi.GetTotDefense(), AssassinEnnemi.GetTotPv(), AssassinEnnemi.GetElement());
	}
	if (bDescCombat == true) {
		timerDescritionCombat += tools::GetTimeDelta();
		if (timerDescritionCombat > 2.0f && bDescCombat == true) {
			iDescCombat = 0;
			bVictory = false;
			bDefaite = false;
			bDescCombat = false;
			if (bFuite == true) {
				posRsAss = posSaveMonstre;
				Fuite(_perso1, AssassinEnnemi, _mode);
				if (_numPerso == 1)
					bAss = false;
				if (_numPerso == 2)
					bAss2 = false;
				if (_numPerso == 3)
					bAss3 = false;
				if (_numPerso == 4)
					bAss4 = false;
				bFuite = false;
			}
		}
	}
}

void Aventure::combatAventureMag(Joueur& _perso1, Magicien& _perso2, Consos& _conso, ModeGame& _mode, int _numPerso, AventureGame& _modeAv) {
	bIsSkill = true;
	if (bDescCombat == false && bChoixObjet == false && bChoixSkill == false) {
		txDescCombat.setString("");
		switch (iChoixCote)
		{
		case 1:
			if (bAtkPerso == true && bDescCombat == false && _perso1.GetTotPv() > 0) {
				if (bIsSkill == true) {
					_perso1.iImmunite -= 1;
					_perso1.iBoostAtk -= 1;
					_perso1.iBoostDef -= 1;
					bIsSkill = false;
				}
				ChoixActionAv();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
					bChoixAction = false;
					timerChoixActionA = 0.0f;
					switch (choixActionA)
					{
					case 1:
						if (_perso1.iBoostAtk > 0) {
							degatFinal = (((_perso1.GetTotAttaque() * 1.5) - MagicienEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), MagicienEnnemi.GetElement()));
						}
						else {
							degatFinal = ((_perso1.GetTotAttaque() - MagicienEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), MagicienEnnemi.GetElement()));
						}
						if (degatFinal <= 0)
							degatFinal = 0;
						PvRestant = MagicienEnnemi.GetTotPv() - degatFinal;
						if (PvRestant <= 0)
							PvRestant = 0;
						MagicienEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { MagicienEnnemi.GetName() };
						timerDescritionCombat = 0.0f;
						iDescCombat = 1;
						bDescCombat = true;
						bAtkPerso = false;
						bAtkMonstre = true;
						break;
					case 2:
						bChoixSkill = true;
						break;
					case 3:
						bChoixObjet = true;
						break;
					case 4:
						timerDescritionCombat = 0.0f;
						bFuite = true;
						iDescCombat = 5;
						bDescCombat = true;
						_choixAttaque = 0;
						break;
					default:
						break;
					}
				}
			}
			if (bAtkMonstre == true && bDescCombat == false && MagicienEnnemi.GetTotPv() > 0) {
				if (_perso1.iPoison > 0) {
					int tmp, tmp2;
					tmp = _perso1.GetTotAttaque() * 0.1;
					tmp2 = MagicienEnnemi.GetTotPv() - tmp;
					if (tmp2 < 0)
						tmp2 = 0;
					MagicienEnnemi.SetTotPv(tmp2);
					_perso1.iPoison -= 1;
				}
				if (_perso1.iBoostDef > 0) {
					degatFinal = ((MagicienEnnemi.GetTotAttaque() - (_perso1.GetTotDefense() * 1.5) * _perso1.ChoixElement(_perso1.GetElement(), MagicienEnnemi.GetElement())));
				}
				else {
					degatFinal = ((MagicienEnnemi.GetTotAttaque() - _perso1.GetTotDefense() * _perso1.ChoixElement(_perso1.GetElement(), MagicienEnnemi.GetElement())));
				}
				if (degatFinal <= 0)
					degatFinal = 0;
				if (_perso1.iImmunite > 0)
					degatFinal = 0.0f;
				PvRestant = _perso1.GetTotPv() - degatFinal;
				_perso1.SetTotPv(PvRestant);
				timerDescritionCombat = 0.0f;
				iDescCombat = 2;
				bDescCombat = true;
				bAtkPerso = true;
				bAtkMonstre = false;
			}
			break;
		case 2:
			if (bAtkMonstre == true && bDescCombat == false && MagicienEnnemi.GetTotPv() > 0) {
				if (_perso1.iPoison > 0) {
					int tmp, tmp2;
					tmp = _perso1.GetTotAttaque() * 0.5;
					tmp2 = MagicienEnnemi.GetTotPv() - tmp;
					if (tmp2 < 0)
						tmp2 = 0;
					MagicienEnnemi.SetTotPv(tmp2);
					_perso1.iPoison -= 1;
				}
				if (_perso1.iBoostDef > 0) {
					degatFinal = ((MagicienEnnemi.GetTotAttaque() - (_perso1.GetTotDefense() * 1.5) * _perso1.ChoixElement(_perso1.GetElement(), MagicienEnnemi.GetElement())));
				}
				else {
					degatFinal = ((MagicienEnnemi.GetTotAttaque() - _perso1.GetTotDefense() * _perso1.ChoixElement(_perso1.GetElement(), MagicienEnnemi.GetElement())));
				}
				if (degatFinal <= 0)
					degatFinal = 0;
				if (_perso1.iImmunite > 0)
					degatFinal = 0.0f;
				PvRestant = _perso1.GetTotPv() - degatFinal;
				_perso1.SetTotPv(PvRestant);
				timerDescritionCombat = 0.0f;
				iDescCombat = 2;
				bDescCombat = true;
				bAtkPerso = true;
				bAtkMonstre = false;
			}
			if (bAtkPerso == true && bDescCombat == false && _perso1.GetTotPv() > 0) {
				if (bIsSkill == true) {
					_perso1.iImmunite -= 1;
					_perso1.iBoostAtk -= 1;
					_perso1.iBoostDef -= 1;
					bIsSkill == false;
				}
				ChoixActionAv();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
					bChoixAction = false;
					timerChoixActionA = 0.0f;
					switch (choixActionA)
					{
					case 1:
						if (_perso1.iBoostAtk > 0) {
							degatFinal = (((_perso1.GetTotAttaque() * 1.5) - MagicienEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), MagicienEnnemi.GetElement()));
						}
						else {
							degatFinal = ((_perso1.GetTotAttaque() - MagicienEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), MagicienEnnemi.GetElement()));
						}
						if (degatFinal <= 0)
							degatFinal = 0;
						PvRestant = MagicienEnnemi.GetTotPv() - degatFinal;
						if (PvRestant <= 0)
							PvRestant = 0;
						MagicienEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { MagicienEnnemi.GetName() };
						timerDescritionCombat = 0.0f;
						iDescCombat = 1;
						bDescCombat = true;
						bAtkPerso = false;
						bAtkMonstre = true;
						break;
					case 2:
						bChoixSkill = true;
						break;
					case 3:
						bChoixObjet = true;
						break;
					case 4:
						if (tools::iRand(0, 3) >= 2) {
							timerDescritionCombat = 0.0f;
							std::cout << "fuit reussi" << std::endl;
							bFuite = true;
							iDescCombat = 5;
							bDescCombat = true;
							_choixAttaque = 0;
						}
						else {
							timerDescritionCombat = 0.0f;
							std::cout << "Echec" << std::endl;
							iDescCombat = 6;
							bDescCombat = true;
							bAtkPerso = false;
							bAtkMonstre = true;
							_choixAttaque = 0;
						}

						_choixAttaque = 0;
						break;
					default:
						break;
					}
				}
			}
			break;
		default:
			break;
		}
		if (MagicienEnnemi.GetTotPv() <= 0 || _perso1.GetTotPv() <= 0)
		{
			if (MagicienEnnemi.GetTotPv() <= 0) {
				_perso1.SetTotPv(_perso1.GetTotPvMax());
				_perso1.NbEnnemiBattu += 1;
				_perso1.NbMag += 1;
				iNbMag += 1;
				if (_numPerso == 1)
					irsVieMag = 0;
				if (_numPerso == 2)
					irsVieMag2 = 0;
				if (_numPerso == 3)
					irsVieMag3 = 0;
				if (_numPerso == 4)
					irsVieMag4 = 0;
				_perso1.Experience((30 * MagicienEnnemi.GetNiveau()));
				LootCombat(_perso1, _modeAv);
				bVictory = true;
			}
			if (_perso1.GetTotPv() <= 0) {
				int tmp_arg;
				tmp_arg = _perso1.GetTotArgent() - 100;
				if (tmp_arg <= 0)
					tmp_arg = 0;
				_perso1.SetTotArgent(tmp_arg);
				bDefaite = true;
			}


			if (bDescCombat == false) {
				_perso1.persoPosition.x = posSavePosition.x;
				_perso1.persoPosition.y = posSavePosition.y + 20;
				if (_numPerso == 1) {
					bMag = false;
					posRsMag = posSaveMonstre;
				}
				if (_numPerso == 2) {
					bMag2 = false;
					posRsGuerr = posSaveMonstre;
				}
				if (_numPerso == 3) {
					bMag3 = false;
					posRsClerc = posSaveMonstre;
				}
				if (_numPerso == 4) {
					bMag4 = false;
					posRsAss = posSaveMonstre;
				}
				bVictory = false;
				bDefaite = false;
				_mode = ModeGame::LIBRE;
			}
			_choixAttaque = 0;
			_perso1.iPoison = 0;
			_perso1.iImmunite = 0;
			_perso1.iBoostAtk = 0;
			_perso1.iBoostDef = 0;
		}
	}
	if (bChoixObjet == true && bDescCombat == false) {
		ChoixObjetAventure(_perso1, MagicienEnnemi, _conso, MagicienEnnemi.GetTotDefense(), MagicienEnnemi.GetTotPv(), MagicienEnnemi.GetElement());
	}
	if (bChoixSkill == true && bDescCombat == false) {
		ChoixActionSkill(_perso1, MagicienEnnemi, _conso, MagicienEnnemi.GetTotDefense(), MagicienEnnemi.GetTotPv(), MagicienEnnemi.GetElement());
	}
	if (bDescCombat == true) {
		timerDescritionCombat += tools::GetTimeDelta();
		if (timerDescritionCombat > 2.0f && bDescCombat == true) {
			iDescCombat = 0;
			bVictory = false;
			bDefaite = false;
			bDescCombat = false;
			if (bFuite == true) {
				posRsMag = posSaveMonstre;
				Fuite(_perso1, MagicienEnnemi, _mode);
				if (_numPerso == 1)
					bMag = false;
				if (_numPerso == 2)
					bMag2 = false;
				if (_numPerso == 3)
					bMag3 = false;
				if (_numPerso == 4)
					bMag4 = false;
				bFuite = false;
			}
		}
	}
}

void Aventure::combatAventureGuer(Joueur& _perso1, Guerrier& _perso2, Consos& _conso, ModeGame& _mode, int _numPerso, AventureGame& _modeAv) {
	bIsSkill = true;
	if (bDescCombat == false && bChoixObjet == false && bChoixSkill == false) {
		txDescCombat.setString("");
		switch (iChoixCote)
		{
		case 1:
			if (bAtkPerso == true && bDescCombat == false && _perso1.GetTotPv() > 0) {
				if (bIsSkill == true) {
					_perso1.iImmunite -= 1;
					_perso1.iBoostAtk -= 1;
					_perso1.iBoostDef -= 1;
					bIsSkill = false;
				}
				ChoixActionAv();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
					bChoixAction = false;
					timerChoixActionA = 0.0f;
					switch (choixActionA)
					{
					case 1:
						if (_perso1.iBoostAtk > 0) {
							degatFinal = (((_perso1.GetTotAttaque() * 1.5) - GuerrierEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), GuerrierEnnemi.GetElement()));
						}
						else {
							degatFinal = ((_perso1.GetTotAttaque() - GuerrierEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), GuerrierEnnemi.GetElement()));
						}
						if (degatFinal <= 0)
							degatFinal = 0;
						PvRestant = GuerrierEnnemi.GetTotPv() - degatFinal;
						if (PvRestant <= 0)
							PvRestant = 0;
						GuerrierEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { GuerrierEnnemi.GetName() };
						timerDescritionCombat = 0.0f;
						iDescCombat = 1;
						bDescCombat = true;
						bAtkPerso = false;
						bAtkMonstre = true;
						break;
					case 2:
						bChoixSkill = true;
						break;
					case 3:
						bChoixObjet = true;
						break;
					case 4:
						timerDescritionCombat = 0.0f;
						bFuite = true;
						iDescCombat = 5;
						bDescCombat = true;
						_choixAttaque = 0;
						break;
					default:
						break;
					}
				}
			}
			if (bAtkMonstre == true && bDescCombat == false && GuerrierEnnemi.GetTotPv() > 0) {
				if (_perso1.iPoison > 0) {
					int tmp, tmp2;
					tmp = _perso1.GetTotAttaque() * 0.1;
					tmp2 = GuerrierEnnemi.GetTotPv() - tmp;
					if (tmp2 < 0)
						tmp2 = 0;
					GuerrierEnnemi.SetTotPv(tmp2);
					_perso1.iPoison -= 1;
				}
				if (_perso1.iBoostDef > 0) {
					degatFinal = ((GuerrierEnnemi.GetTotAttaque() - (_perso1.GetTotDefense() * 1.5) * _perso1.ChoixElement(_perso1.GetElement(), GuerrierEnnemi.GetElement())));
				}
				else {
					degatFinal = ((GuerrierEnnemi.GetTotAttaque() - _perso1.GetTotDefense() * _perso1.ChoixElement(_perso1.GetElement(), GuerrierEnnemi.GetElement())));
				}
				if (degatFinal <= 0)
					degatFinal = 0;
				if (_perso1.iImmunite > 0)
					degatFinal = 0.0f;
				PvRestant = _perso1.GetTotPv() - degatFinal;
				_perso1.SetTotPv(PvRestant);
				timerDescritionCombat = 0.0f;
				iDescCombat = 2;
				bDescCombat = true;
				bAtkPerso = true;
				bAtkMonstre = false;
			}
			break;
		case 2:
			if (bAtkMonstre == true && bDescCombat == false && GuerrierEnnemi.GetTotPv() > 0) {
				if (_perso1.iPoison > 0) {
					int tmp, tmp2;
					tmp = _perso1.GetTotAttaque() * 0.5;
					tmp2 = GuerrierEnnemi.GetTotPv() - tmp;
					if (tmp2 < 0)
						tmp2 = 0;
					GuerrierEnnemi.SetTotPv(tmp2);
					_perso1.iPoison -= 1;
				}
				if (_perso1.iBoostDef > 0) {
					degatFinal = ((GuerrierEnnemi.GetTotAttaque() - (_perso1.GetTotDefense() * 1.5) * _perso1.ChoixElement(_perso1.GetElement(), GuerrierEnnemi.GetElement())));
				}
				else {
					degatFinal = ((GuerrierEnnemi.GetTotAttaque() - _perso1.GetTotDefense() * _perso1.ChoixElement(_perso1.GetElement(), GuerrierEnnemi.GetElement())));
				}
				if (degatFinal <= 0)
					degatFinal = 0;
				if (_perso1.iImmunite > 0)
					degatFinal = 0.0f;
				PvRestant = _perso1.GetTotPv() - degatFinal;
				_perso1.SetTotPv(PvRestant);
				timerDescritionCombat = 0.0f;
				iDescCombat = 2;
				bDescCombat = true;
				bAtkPerso = true;
				bAtkMonstre = false;
			}
			if (bAtkPerso == true && bDescCombat == false && _perso1.GetTotPv() > 0) {
				if (bIsSkill == true) {
					_perso1.iImmunite -= 1;
					_perso1.iBoostAtk -= 1;
					_perso1.iBoostDef -= 1;
					bIsSkill == false;
				}
				ChoixActionAv();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
					bChoixAction = false;
					timerChoixActionA = 0.0f;
					switch (choixActionA)
					{
					case 1:
						if (_perso1.iBoostAtk > 0) {
							degatFinal = (((_perso1.GetTotAttaque() * 1.5) - GuerrierEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), GuerrierEnnemi.GetElement()));
						}
						else {
							degatFinal = ((_perso1.GetTotAttaque() - GuerrierEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), GuerrierEnnemi.GetElement()));
						}
						if (degatFinal <= 0)
							degatFinal = 0;
						PvRestant = GuerrierEnnemi.GetTotPv() - degatFinal;
						if (PvRestant <= 0)
							PvRestant = 0;
						GuerrierEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { GuerrierEnnemi.GetName() };
						timerDescritionCombat = 0.0f;
						iDescCombat = 1;
						bDescCombat = true;
						bAtkPerso = false;
						bAtkMonstre = true;
						break;
					case 2:
						bChoixSkill = true;
						break;
					case 3:
						bChoixObjet = true;
						break;
					case 4:
						if (tools::iRand(0, 3) >= 2) {
							timerDescritionCombat = 0.0f;
							std::cout << "fuit reussi" << std::endl;
							bFuite = true;
							iDescCombat = 5;
							bDescCombat = true;
							_choixAttaque = 0;
						}
						else {
							timerDescritionCombat = 0.0f;
							std::cout << "Echec" << std::endl;
							iDescCombat = 6;
							bDescCombat = true;
							bAtkPerso = false;
							bAtkMonstre = true;
							_choixAttaque = 0;
						}

						_choixAttaque = 0;
						break;
					default:
						break;
					}
				}
			}
			break;
		default:
			break;
		}
		if (GuerrierEnnemi.GetTotPv() <= 0 || _perso1.GetTotPv() <= 0)
		{
			if (GuerrierEnnemi.GetTotPv() <= 0) {
				_perso1.SetTotPv(_perso1.GetTotPvMax());
				_perso1.NbEnnemiBattu += 1;
				_perso1.NbGuer += 1;
				iNbGuer += 1;
				if (_numPerso == 1)
					irsVieGuer = 0;
				if (_numPerso == 2)
					irsVieGuer2 = 0;
				if (_numPerso == 3)
					irsVieGuer3 = 0;
				if (_numPerso == 4)
					irsVieGuer4 = 0;
				_perso1.Experience((30 * GuerrierEnnemi.GetNiveau()));
				LootCombat(_perso1, _modeAv);
				bVictory = true;
			}
			if (_perso1.GetTotPv() <= 0) {
				int tmp_arg;
				tmp_arg = _perso1.GetTotArgent() - 100;
				if (tmp_arg <= 0)
					tmp_arg = 0;
				_perso1.SetTotArgent(tmp_arg);
				bDefaite = true;
			}


			if (bDescCombat == false) {
				_perso1.persoPosition.x = posSavePosition.x;
				_perso1.persoPosition.y = posSavePosition.y + 20;
				if (_numPerso == 1) {
					bGuer = false;
					posRsGuerr = posSaveMonstre;
				}
				if (_numPerso == 2) {
					bGuer2 = false;
					posRsAss = posSaveMonstre;
				}
				if (_numPerso == 3) {
					bGuer3 = false;
					posRsClerc = posSaveMonstre;
				}
				if (_numPerso == 4) {
					bGuer4 = false;
					posRsMag = posSaveMonstre;
				}
				bVictory = false;
				bDefaite = false;
				_mode = ModeGame::LIBRE;
			}
			_choixAttaque = 0;
			_perso1.iPoison = 0;
			_perso1.iImmunite = 0;
			_perso1.iBoostAtk = 0;
			_perso1.iBoostDef = 0;
		}
	}
	if (bChoixObjet == true && bDescCombat == false) {
		ChoixObjetAventure(_perso1, GuerrierEnnemi, _conso, GuerrierEnnemi.GetTotDefense(), GuerrierEnnemi.GetTotPv(), GuerrierEnnemi.GetElement());
	}
	if (bChoixSkill == true && bDescCombat == false) {
		ChoixActionSkill(_perso1, GuerrierEnnemi, _conso, GuerrierEnnemi.GetTotDefense(), GuerrierEnnemi.GetTotPv(), GuerrierEnnemi.GetElement());
	}
	if (bDescCombat == true) {
		timerDescritionCombat += tools::GetTimeDelta();
		if (timerDescritionCombat > 2.0f && bDescCombat == true) {
			iDescCombat = 0;
			bVictory = false;
			bDefaite = false;
			bDescCombat = false;
			if (bFuite == true) {
				posRsGuerr = posSaveMonstre;
				Fuite(_perso1, GuerrierEnnemi, _mode);
				if (_numPerso == 1)
					bGuer = false;
				if (_numPerso == 2)
					bGuer2 = false;
				if (_numPerso == 3)
					bGuer3 = false;
				if (_numPerso == 4)
					bGuer4 = false;
				bFuite = false;
			}
		}
	}
}

void Aventure::combatAventureClerc(Joueur& _perso1, Clerc& _perso2, Consos& _conso, ModeGame& _mode, int _numPerso, AventureGame& _modeAv) {
	bIsSkill = true;
	if (bDescCombat == false && bChoixObjet == false && bChoixSkill == false) {
		txDescCombat.setString("");
		switch (iChoixCote)
		{
		case 1:
			if (bAtkPerso == true && bDescCombat == false && _perso1.GetTotPv() > 0) {
				if (bIsSkill == true) {
					_perso1.iImmunite -= 1;
					_perso1.iBoostAtk -= 1;
					_perso1.iBoostDef -= 1;
					bIsSkill = false;
				}
				ChoixActionAv();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
					bChoixAction = false;
					timerChoixActionA = 0.0f;
					switch (choixActionA)
					{
					case 1:
						if (_perso1.iBoostAtk > 0) {
							degatFinal = (((_perso1.GetTotAttaque() * 1.5) - ClercEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), ClercEnnemi.GetElement()));
						}
						else {
							degatFinal = ((_perso1.GetTotAttaque() - ClercEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), ClercEnnemi.GetElement()));
						}
						if (degatFinal <= 0)
							degatFinal = 0;
						PvRestant = ClercEnnemi.GetTotPv() - degatFinal;
						if (PvRestant <= 0)
							PvRestant = 0;
						ClercEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { ClercEnnemi.GetName() };
						timerDescritionCombat = 0.0f;
						iDescCombat = 1;
						bDescCombat = true;
						bAtkPerso = false;
						bAtkMonstre = true;
						break;
					case 2:
						bChoixSkill = true;
						break;
					case 3:
						bChoixObjet = true;
						break;
					case 4:
						timerDescritionCombat = 0.0f;
						bFuite = true;
						iDescCombat = 5;
						bDescCombat = true;
						_choixAttaque = 0;
						break;
					default:
						break;
					}
				}
			}
			if (bAtkMonstre == true && bDescCombat == false && ClercEnnemi.GetTotPv() > 0) {
				if (_perso1.iPoison > 0) {
					int tmp, tmp2;
					tmp = _perso1.GetTotAttaque() * 0.1;
					tmp2 = ClercEnnemi.GetTotPv() - tmp;
					if (tmp2 < 0)
						tmp2 = 0;
					ClercEnnemi.SetTotPv(tmp2);
					_perso1.iPoison -= 1;
				}
				PvRestant = ClercEnnemi.GetTotPv() + ClercEnnemi.GetTotAttaque();
				degatFinal = ClercEnnemi.GetTotAttaque();
				ClercEnnemi.SetTotPv(PvRestant);
				timerDescritionCombat = 0.0f;
				iDescCombat = 13;
				bDescCombat = true;
				bAtkPerso = true;
				bAtkMonstre = false;
			}
			break;
		case 2:
			if (bAtkMonstre == true && bDescCombat == false && ClercEnnemi.GetTotPv() > 0) {
				if (_perso1.iPoison > 0) {
					int tmp, tmp2;
					tmp = _perso1.GetTotAttaque() * 0.5;
					tmp2 = ClercEnnemi.GetTotPv() - tmp;
					if (tmp2 < 0)
						tmp2 = 0;
					ClercEnnemi.SetTotPv(tmp2);
					_perso1.iPoison -= 1;
				}
				PvRestant = ClercEnnemi.GetTotPv() + ClercEnnemi.GetTotAttaque();
				degatFinal = ClercEnnemi.GetTotAttaque();
				ClercEnnemi.SetTotPv(PvRestant);
				timerDescritionCombat = 0.0f;
				iDescCombat = 13;
				bDescCombat = true;
				bAtkPerso = true;
				bAtkMonstre = false;
			}
			if (bAtkPerso == true && bDescCombat == false && _perso1.GetTotPv() > 0) {
				if (bIsSkill == true) {
					_perso1.iImmunite -= 1;
					_perso1.iBoostAtk -= 1;
					_perso1.iBoostDef -= 1;
					bIsSkill == false;
				}
				ChoixActionAv();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
					bChoixAction = false;
					timerChoixActionA = 0.0f;
					switch (choixActionA)
					{
					case 1:
						if (_perso1.iBoostAtk > 0) {
							degatFinal = (((_perso1.GetTotAttaque() * 1.5) - ClercEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), ClercEnnemi.GetElement()));
						}
						else {
							degatFinal = ((_perso1.GetTotAttaque() - ClercEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), ClercEnnemi.GetElement()));
						}
						if (degatFinal <= 0)
							degatFinal = 0;
						PvRestant = ClercEnnemi.GetTotPv() - degatFinal;
						if (PvRestant <= 0)
							PvRestant = 0;
						ClercEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { ClercEnnemi.GetName() };
						timerDescritionCombat = 0.0f;
						iDescCombat = 1;
						bDescCombat = true;
						bAtkPerso = false;
						bAtkMonstre = true;
						break;
					case 2:
						bChoixSkill = true;
						break;
					case 3:
						bChoixObjet = true;
						break;
					case 4:
						if (tools::iRand(0, 3) >= 2) {
							timerDescritionCombat = 0.0f;
							std::cout << "fuit reussi" << std::endl;
							bFuite = true;
							iDescCombat = 5;
							bDescCombat = true;
							_choixAttaque = 0;
						}
						else {
							timerDescritionCombat = 0.0f;
							std::cout << "Echec" << std::endl;
							iDescCombat = 6;
							bDescCombat = true;
							bAtkPerso = false;
							bAtkMonstre = true;
							_choixAttaque = 0;
						}
						_choixAttaque = 0;
						break;
					default:
						break;
					}
				}
			}
			break;
		default:
			break;
		}
		if (ClercEnnemi.GetTotPv() <= 0 || _perso1.GetTotPv() <= 0)
		{
			if (ClercEnnemi.GetTotPv() <= 0) {
				_perso1.SetTotPv(_perso1.GetTotPvMax());
				_perso1.NbEnnemiBattu += 1;
				_perso1.NbClerc += 1;
				iNbClerc += 1;
				if (_numPerso == 1)
					irsVieClerc = 0;
				if (_numPerso == 2)
					irsVieClerc2 = 0;
				if (_numPerso == 3)
					irsVieClerc3 = 0;
				if (_numPerso == 4)
					irsVieClerc4 = 0;
				_perso1.Experience((30 * ClercEnnemi.GetNiveau()));
				LootCombat(_perso1, _modeAv);
				bVictory = true;
			}
			if (_perso1.GetTotPv() <= 0) {
				int tmp_arg;
				tmp_arg = _perso1.GetTotArgent() - 100;
				if (tmp_arg <= 0)
					tmp_arg = 0;
				_perso1.SetTotArgent(tmp_arg);
				bDefaite = true;
			}


			if (bDescCombat == false) {
				posRsClerc = posSaveMonstre;
				_perso1.persoPosition.x = posSavePosition.x;
				_perso1.persoPosition.y = posSavePosition.y + 20;
				if (_numPerso == 1)
					bClerc = false;
				if (_numPerso == 2)
					bClerc2 = false;
				if (_numPerso == 3)
					bClerc3 = false;
				if (_numPerso == 4)
					bClerc4 = false;
				bVictory = false;
				bDefaite = false;
				_mode = ModeGame::LIBRE;
			}
			_choixAttaque = 0;
			_perso1.iPoison = 0;
			_perso1.iImmunite = 0;
			_perso1.iBoostAtk = 0;
			_perso1.iBoostDef = 0;
		}
	}
	if (bChoixObjet == true && bDescCombat == false) {
		ChoixObjetAventure(_perso1, ClercEnnemi, _conso, ClercEnnemi.GetTotDefense(), ClercEnnemi.GetTotPv(), ClercEnnemi.GetElement());
	}
	if (bChoixSkill == true && bDescCombat == false) {
		ChoixActionSkill(_perso1, ClercEnnemi, _conso, ClercEnnemi.GetTotDefense(), ClercEnnemi.GetTotPv(), ClercEnnemi.GetElement());
	}
	if (bDescCombat == true) {
		timerDescritionCombat += tools::GetTimeDelta();
		if (timerDescritionCombat > 2.0f && bDescCombat == true) {
			iDescCombat = 0;
			bVictory = false;
			bDefaite = false;
			bDescCombat = false;
			if (bFuite == true) {
				if (_numPerso == 1) {
					posRsClerc = posSaveMonstre;
					bClerc = false;
				}
				if (_numPerso == 2) {
					posRsClerc = posSaveMonstre;
					bClerc2 = false;
				}
				if (_numPerso == 3) {
					bClerc3 = false;
					posRsGuerr = posSaveMonstre;
				}
				if (_numPerso == 4) {
					bClerc4 = false;
					posRsMag = posSaveMonstre;
				}
				Fuite(_perso1, ClercEnnemi, _mode);
				bFuite = false;
			}
		}
	}
}

void Aventure::combatAventureVill(Joueur& _perso1, Villagois& _perso2, Consos& _conso, ModeGame& _mode) {
	bIsSkill = true;
	if (bDescCombat == false && bChoixObjet == false && bChoixSkill == false) {
		txDescCombat.setString("");
		switch (iChoixCote)
		{
		case 1:
			if (bAtkPerso == true && bDescCombat == false && _perso1.GetTotPv() > 0) {
				if (bIsSkill == true) {
					_perso1.iImmunite -= 1;
					_perso1.iBoostAtk -= 1;
					_perso1.iBoostDef -= 1;
					bIsSkill = false;
				}
				ChoixActionAv();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
					bChoixAction = false;
					timerChoixActionA = 0.0f;
					switch (choixActionA)
					{
					case 1:
						if (_perso1.iBoostAtk > 0) {
							degatFinal = (((_perso1.GetTotAttaque() * 1.5) - VillagoisEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), VillagoisEnnemi.GetElement()));
						}
						else {
							degatFinal = ((_perso1.GetTotAttaque() - VillagoisEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), VillagoisEnnemi.GetElement()));
						}
						if (degatFinal <= 0)
							degatFinal = 0;
						PvRestant = VillagoisEnnemi.GetTotPv() - degatFinal;
						if (PvRestant <= 0)
							PvRestant = 0;
						VillagoisEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { VillagoisEnnemi.GetName() };
						timerDescritionCombat = 0.0f;
						iDescCombat = 1;
						bDescCombat = true;
						bAtkPerso = false;
						bAtkMonstre = true;
						break;
					case 2:
						bChoixSkill = true;
						break;
					case 3:
						bChoixObjet = true;
						break;
					case 4:
						timerDescritionCombat = 0.0f;
						bFuite = true;
						iDescCombat = 5;
						bDescCombat = true;
						_choixAttaque = 0;
						break;
					default:
						break;
					}
				}
			}
			if (bAtkMonstre == true && bDescCombat == false && VillagoisEnnemi.GetTotPv() > 0) {
				if (_perso1.iPoison > 0) {
					int tmp, tmp2;
					tmp = _perso1.GetTotAttaque() * 0.1;
					tmp2 = VillagoisEnnemi.GetTotPv() - tmp;
					if (tmp2 < 0)
						tmp2 = 0;
					VillagoisEnnemi.SetTotPv(tmp2);
					_perso1.iPoison -= 1;
				}
				if (_perso1.iBoostDef > 0) {
					degatFinal = ((VillagoisEnnemi.GetTotAttaque() - (_perso1.GetTotDefense() * 1.5) * _perso1.ChoixElement(_perso1.GetElement(), VillagoisEnnemi.GetElement())));
				}
				else {
					degatFinal = ((VillagoisEnnemi.GetTotAttaque() - _perso1.GetTotDefense() * _perso1.ChoixElement(_perso1.GetElement(), VillagoisEnnemi.GetElement())));
				}
				if (degatFinal <= 0)
					degatFinal = 0;
				if (_perso1.iImmunite > 0)
					degatFinal = 0.0f;
				PvRestant = _perso1.GetTotPv() - degatFinal;
				_perso1.SetTotPv(PvRestant);
				timerDescritionCombat = 0.0f;
				iDescCombat = 2;
				bDescCombat = true;
				bAtkPerso = true;
				bAtkMonstre = false;
			}
			break;
		case 2:
			if (bAtkMonstre == true && bDescCombat == false && VillagoisEnnemi.GetTotPv() > 0) {
				if (_perso1.iPoison > 0) {
					int tmp, tmp2;
					tmp = _perso1.GetTotAttaque() * 0.5;
					tmp2 = VillagoisEnnemi.GetTotPv() - tmp;
					if (tmp2 < 0)
						tmp2 = 0;
					VillagoisEnnemi.SetTotPv(tmp2);
					_perso1.iPoison -= 1;
				}
				if (_perso1.iBoostDef > 0) {
					degatFinal = ((VillagoisEnnemi.GetTotAttaque() - (_perso1.GetTotDefense() * 1.5) * _perso1.ChoixElement(_perso1.GetElement(), VillagoisEnnemi.GetElement())));
				}
				else {
					degatFinal = ((VillagoisEnnemi.GetTotAttaque() - _perso1.GetTotDefense() * _perso1.ChoixElement(_perso1.GetElement(), VillagoisEnnemi.GetElement())));
				}
				if (degatFinal <= 0)
					degatFinal = 0;
				if (_perso1.iImmunite > 0)
					degatFinal = 0.0f;
				PvRestant = _perso1.GetTotPv() - degatFinal;
				_perso1.SetTotPv(PvRestant);
				timerDescritionCombat = 0.0f;
				iDescCombat = 2;
				bDescCombat = true;
				bAtkPerso = true;
				bAtkMonstre = false;
			}
			if (bAtkPerso == true && bDescCombat == false && _perso1.GetTotPv() > 0) {
				if (bIsSkill == true) {
					_perso1.iImmunite -= 1;
					_perso1.iBoostAtk -= 1;
					_perso1.iBoostDef -= 1;
					bIsSkill == false;
				}
				ChoixActionAv();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
					bChoixAction = false;
					timerChoixActionA = 0.0f;
					switch (choixActionA)
					{
					case 1:
						if (_perso1.iBoostAtk > 0) {
							degatFinal = (((_perso1.GetTotAttaque() * 1.5) - VillagoisEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), VillagoisEnnemi.GetElement()));
						}
						else {
							degatFinal = ((_perso1.GetTotAttaque() - VillagoisEnnemi.GetTotDefense()) * _perso1.ChoixElement(_perso1.GetElement(), VillagoisEnnemi.GetElement()));
						}
						if (degatFinal <= 0)
							degatFinal = 0;
						PvRestant = VillagoisEnnemi.GetTotPv() - degatFinal;
						if (PvRestant <= 0)
							PvRestant = 0;
						VillagoisEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { VillagoisEnnemi.GetName() };
						timerDescritionCombat = 0.0f;
						iDescCombat = 1;
						bDescCombat = true;
						bAtkPerso = false;
						bAtkMonstre = true;
						break;
					case 2:
						bChoixSkill = true;
						break;
					case 3:
						bChoixObjet = true;
						break;
					case 4:
						if (tools::iRand(0, 3) >= 2) {
							timerDescritionCombat = 0.0f;
							std::cout << "fuit reussi" << std::endl;
							bFuite = true;
							iDescCombat = 5;
							bDescCombat = true;
							_choixAttaque = 0;
						}
						else {
							timerDescritionCombat = 0.0f;
							std::cout << "Echec" << std::endl;
							iDescCombat = 6;
							bDescCombat = true;
							bAtkPerso = false;
							bAtkMonstre = true;
							_choixAttaque = 0;
						}

						_choixAttaque = 0;
						break;
					default:
						break;
					}
				}
			}
			break;
		default:
			break;
		}
		if (VillagoisEnnemi.GetTotPv() <= 0 || _perso1.GetTotPv() <= 0)
		{
			if (VillagoisEnnemi.GetTotPv() <= 0) {
				_perso1.SetTotPv(_perso1.GetTotPvMax());
				_perso1.NbEnnemiBattu += 1;
				_perso1.iBossAv += 1;
				iNbVill += 1;
				iZoneAv += 1;
				iNbAss = 0;
				iNbClerc = 0;
				iNbGuer = 0;
				iNbMag = 0;
				irsVieAss = 1;
				irsVieClerc = 1;
				irsVieGuer = 1;
				irsVieMag = 1;
				_perso1.Experience((50 * iZoneAv));
				bVictory = true;
			}
			if (_perso1.GetTotPv() <= 0) {
				int tmp_arg;
				tmp_arg = _perso1.GetTotArgent() - 100;
				if (tmp_arg <= 0)
					tmp_arg = 0;
				_perso1.SetTotArgent(tmp_arg);
				bDefaite = true;
			}


			if (bDescCombat == false) {
				posRsVill = posSaveMonstre;
				_perso1.persoPosition.x = posSavePosition.x;
				_perso1.persoPosition.y = posSavePosition.y + 20;
				bVill = false;
				bVictory = false;
				bDefaite = false;
				_mode = ModeGame::LIBRE;
			}
			_choixAttaque = 0;
			_perso1.iPoison = 0;
			_perso1.iImmunite = 0;
			_perso1.iBoostAtk = 0;
			_perso1.iBoostDef = 0;
		}
	}
	if (bChoixObjet == true && bDescCombat == false) {
		ChoixObjetAventure(_perso1, VillagoisEnnemi, _conso, VillagoisEnnemi.GetTotDefense(), VillagoisEnnemi.GetTotPv(), VillagoisEnnemi.GetElement());
	}
	if (bChoixSkill == true && bDescCombat == false) {
		ChoixActionSkill(_perso1, VillagoisEnnemi, _conso, VillagoisEnnemi.GetTotDefense(), VillagoisEnnemi.GetTotPv(), VillagoisEnnemi.GetElement());
	}
	if (bDescCombat == true) {
		timerDescritionCombat += tools::GetTimeDelta();
		if (timerDescritionCombat > 2.0f && bDescCombat == true) {
			iDescCombat = 0;
			bVictory = false;
			bDefaite = false;
			bDescCombat = false;
			if (bFuite == true) {
				posRsVill = posSaveMonstre;
				Fuite(_perso1, VillagoisEnnemi, _mode);
				bVill = false;
				bFuite = false;
			}
		}
	}
}

void ChoixObjetAventure(Joueur& _perso1, Joueur& _perso2, Consos& _conso, int _def, int _pv, Personnage::Elements _element) {

	int tmpint;
	timerChoixActionA += tools::GetTimeDelta();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && choixActionO > 1 && timerChoixActionA > 0.3f) {
		choixActionO -= 1;
		timerChoixActionA = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && choixActionO < 4 && timerChoixActionA > 0.3f) {
		choixActionO += 1;
		timerChoixActionA = 0.0f;
	}
	switch (choixActionO)
	{
	case 1:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Vous allez soigner vos PV", "You will heal your PV");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
			if (_perso1.SoinPvBuy >= 1) {
				tmpint = _perso1.GetTotPvMax() - _perso1.GetTotPv();
				stObj = { "Vous avez soigne vos Pv de " + std::to_string(tmpint) };
				stObjEn = { "You have taken care of your Pv of " + std::to_string(tmpint) };
				_perso1.SetTotPv(_perso1.GetTotPvMax());
				_perso1.SoinPvBuy -= 1;
				if (_perso1.SoinPvBuy <= 0)
					_perso1.soinPvEquipe = false;
				timerDescritionCombat = 0.0f;
				iDescCombat = 3;
				bDescCombat = true;
				bAtkPerso = false;
				bAtkMonstre = true;
				bChoixObjet = false;
			}
			else {
				stObj = { "Vous n'avez pas l' objet de soin de PV" };
				stObjEn = { "You do not have the object of care of PV" };
				bChoixObjet = false;
				bDescCombat = true;
				iDescCombat = 3;
			}
			timerChoixActionA = 0.0f;
		}
		break;
	case 2:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Vous allez soigner votre Mana", "You will heal your Mana");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
			if (_perso1.SoinManaBuy >= 1) {
				tmpint = _perso1.GetTotManaMax() - _perso1.GetTotMana();
				stObj = { "Vous avez soigne votre Mana de " + tmpint };
				stObjEn = { "You have healed your Mana of " + tmpint };
				_perso1.SetTotMana(tmpint);
				_perso1.SoinManaBuy -= 1;
				if (_perso1.SoinManaBuy <= 0)
					_perso1.soinManaEquipe = false;
				timerDescritionCombat = 0.0f;
				iDescCombat = 3;
				bDescCombat = true;
				bAtkPerso = false;
				bAtkMonstre = true;
				bChoixObjet = false;
			}
			else {
				stObj = { "Vous n'avez pas l' objet de soin de Mana" };
				stObjEn = { "You don't have Mana's healing object" };
				bChoixObjet = false;
				bDescCombat = true;
				iDescCombat = 3;
			}
			timerChoixActionA = 0.0f;
		}
		break;
	case 3:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Vous allez faire des degats au monstre", "You will do damage to the monster");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
			if (_perso1.BombeBuy >= 1) {
				degatFinal = (1000 - _def);
				if (degatFinal <= 0)
					degatFinal = 0;
				PvRestant = _pv - degatFinal;
				if (PvRestant <= 0)
					PvRestant = 0;
				if (bAss == true) {
					AssassinEnnemi.SetTotPv(PvRestant);
					stNomEnnemi = { AssassinEnnemi.GetName() };
				}
				if (bGuer == true) {
					GuerrierEnnemi.SetTotPv(PvRestant);
					stNomEnnemi = { GuerrierEnnemi.GetName() };
				}
				if (bClerc == true) {
					ClercEnnemi.SetTotPv(PvRestant);
					stNomEnnemi = { ClercEnnemi.GetName() };
				}
				if (bMag == true) {
					MagicienEnnemi.SetTotPv(PvRestant);
					stNomEnnemi = { MagicienEnnemi.GetName() };
				}
				if (bVill == true) {
					VillagoisEnnemi.SetTotPv(PvRestant);
					stNomEnnemi = { VillagoisEnnemi.GetName() };
				}
				stObj = { "Vous avez fais des degats : " + std::to_string((int)degatFinal) };
				stObjEn = { "You have done damage : " + std::to_string((int)degatFinal) };
				_perso1.BombeBuy -= 1;
				if (_perso1.BombeBuy <= 0)
					_perso1.bombeEquipe -= 1;
				timerDescritionCombat = 0.0f;
				iDescCombat = 3;
				bDescCombat = true;
				bAtkPerso = false;
				bAtkMonstre = true;
				bChoixObjet = false;
			}
			else {
				stObj = { "Vous n'avez pas de Bombe" };
				stObjEn = { "You don't have a Bomb" };
				bChoixObjet = false;
				bDescCombat = true;
				iDescCombat = 3;
			}
			timerChoixActionA = 0.0f;
		}
		break;
	case 4:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Retour au choix d'attaque", "Back to attack choice");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
			bChoixObjet = false;
			timerChoixActionA = 0.0f;
		}
		break;
	default:
		break;
	}

}

void ChoixActionSkill(Joueur& _perso1, Joueur& _perso2, Consos& _conso, int _def, int _pv, Personnage::Elements _element) {
	int tmpint;
	timerChoixSkill += tools::GetTimeDelta();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && choixskill > 1 && timerChoixSkill > 0.3f) {
		choixskill -= 1;
		timerChoixSkill = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && choixskill < 5 && timerChoixSkill > 0.3f) {
		choixskill += 1;
		timerChoixSkill = 0.0f;
	}
	switch (choixskill)
	{
	case 1:
		if (_perso1.SKILL[0] == true) {
			tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Skill 1 : Attaque avec le double de degats", "Skill 1: Attack with double the damage");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
				degatFinal = ((_perso1.GetTotAttaque() - _def) * _perso1.ChoixElement(_perso1.GetElement(), _element) * 2);
				if (degatFinal <= 0)
					degatFinal = 0;
				PvRestant = _pv - degatFinal;
				if (PvRestant <= 0)
					PvRestant = 0;
				if (bAss == true) {
					AssassinEnnemi.SetTotPv(PvRestant);
					stNomEnnemi = { AssassinEnnemi.GetName() };
				}
				if (bGuer == true) {
					GuerrierEnnemi.SetTotPv(PvRestant);
					stNomEnnemi = { GuerrierEnnemi.GetName() };
				}
				if (bClerc == true) {
					ClercEnnemi.SetTotPv(PvRestant);
					stNomEnnemi = { ClercEnnemi.GetName() };
				}
				if (bMag == true) {
					MagicienEnnemi.SetTotPv(PvRestant);
					stNomEnnemi = { MagicienEnnemi.GetName() };
				}
				if (bVill == true) {
					VillagoisEnnemi.SetTotPv(PvRestant);
					stNomEnnemi = { VillagoisEnnemi.GetName() };
				}
				timerDescritionCombat = 0.0f;
				timerChoixSkill = 0.0f;
				iDescCombat = 1;
				bChoixSkill = false;
				bDescCombat = true;
				bAtkPerso = false;
				bAtkMonstre = true;
			}
		}
		else {
			tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Vous ne posseder pas de skill 1", "You don't have skill 1");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
				bChoixSkill = false;
				timerChoixSkill = 0.0f;
			}
		}
		break;
	case 2:
		if (_perso1.SKILL[1] == true || _perso1.SKILL[2] == true) {
			if (_perso1.SKILL[1] == true) {
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Skill 2 : Attaque en ignorant les elements", "Skill 2: Attack by ignoring the elements");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
					degatFinal = (_perso1.GetTotAttaque() - _def);
					if (degatFinal <= 0)
						degatFinal = 0;
					PvRestant = _pv - degatFinal;
					if (PvRestant <= 0)
						PvRestant = 0;
					if (bAss == true) {
						AssassinEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { AssassinEnnemi.GetName() };
					}
					if (bGuer == true) {
						GuerrierEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { GuerrierEnnemi.GetName() };
					}
					if (bClerc == true) {
						ClercEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { ClercEnnemi.GetName() };
					}
					if (bMag == true) {
						MagicienEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { MagicienEnnemi.GetName() };
					}
					if (bVill == true) {
						VillagoisEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { VillagoisEnnemi.GetName() };
					}
					timerDescritionCombat = 0.0f;
					timerChoixSkill = 0.0f;
					iDescCombat = 1;
					bChoixSkill = false;
					bDescCombat = true;
					bAtkPerso = false;
					bAtkMonstre = true;
				}
			}
			if (_perso1.SKILL[2] == true) {
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Skill 2 : Attaque en ignorant la defense", "Skill 2: Attack by ignoring defense");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
					degatFinal = (_perso1.GetTotAttaque() * _perso1.ChoixElement(_perso1.GetElement(), _element));
					if (degatFinal <= 0)
						degatFinal = 0;
					PvRestant = _pv - degatFinal;
					if (PvRestant <= 0)
						PvRestant = 0;
					if (bAss == true) {
						AssassinEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { AssassinEnnemi.GetName() };
					}
					if (bGuer == true) {
						GuerrierEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { GuerrierEnnemi.GetName() };
					}
					if (bClerc == true) {
						ClercEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { ClercEnnemi.GetName() };
					}
					if (bMag == true) {
						MagicienEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { MagicienEnnemi.GetName() };
					}
					if (bVill == true) {
						VillagoisEnnemi.SetTotPv(PvRestant);
						stNomEnnemi = { VillagoisEnnemi.GetName() };
					}
					timerDescritionCombat = 0.0f;
					timerChoixSkill = 0.0f;
					iDescCombat = 1;
					bChoixSkill = false;
					bDescCombat = true;
					bAtkPerso = false;
					bAtkMonstre = true;
				}
			}
		}
		else {
			tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Vous ne posseder pas de skill 2", "You don't have skill 2");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
				bChoixSkill = false;
				timerChoixSkill = 0.0f;
			}
		}
		break;
	case 3:
		if (_perso1.SKILL[3] == true || _perso1.SKILL[4] == true || _perso1.SKILL[5] == true || _perso1.SKILL[6] == true) {
			if (_perso1.SKILL[3] == true) {
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Skill 3 : Boost des degats pour 2 tour (50%)", "Skill 3: Damage boost for 2 turns (50%)");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
					_perso1.iBoostAtk = 2;
					timerChoixSkill = 0.0f;
					timerDescritionCombat = 0.0f;
					iDescCombat = 7;
					bChoixSkill = false;
					bDescCombat = true;
					bAtkPerso = false;
					bAtkMonstre = true;
				}
			}
			if (_perso1.SKILL[4] == true) {
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Skill 3 : Boost de la resistance aux degats pour 2 tour (50%)", "Skill 3: Damage resistance boost for 2 turns (50%)");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
					_perso1.iBoostDef = 2;
					timerChoixSkill = 0.0f;
					timerDescritionCombat = 0.0f;
					iDescCombat = 8;
					bChoixSkill = false;
					bDescCombat = true;
					bAtkPerso = false;
					bAtkMonstre = true;
				}
			}
			if (_perso1.SKILL[5] == true) {
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Skill 3 : Inflige poison pendant 2 tour(50% de l'attaque)", "Skill 3: Inflicts poison for 2 turns(50% of the attack)");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
					_perso1.iPoison = 2;
					timerDescritionCombat = 0.0f;
					timerChoixSkill = 0.0f;
					iDescCombat = 9;
					bChoixSkill = false;
					bDescCombat = true;
					bAtkPerso = false;
					bAtkMonstre = true;
				}
			}
			if (_perso1.SKILL[6] == true) {
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Skill 3 : S'octroie une immunite a tous degats (2 tour)", "Skill 3: Grants yourself an immunity to all damages (2 round)");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
					_perso1.iImmunite = 2;
					timerChoixSkill = 0.0f;
					timerDescritionCombat = 0.0f;
					iDescCombat = 10;
					bChoixSkill = false;
					bDescCombat = true;
					bAtkPerso = false;
					bAtkMonstre = true;
				}
			}
		}
		else {
			tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Vous ne posseder pas de skill 3", "You don't have a skill 3");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
				bChoixSkill = false;
				timerChoixSkill = 0.0f;
			}
		}
		break;
	case 4:
		if (_perso1.SKILL[7] == true || _perso1.SKILL[8] == true) {
			if (_perso1.SKILL[7] == true) {
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Skill 4 : Invoque une creature !! A venir Prochainement !!", "Skill 4: Summon a creature!! Coming soon !!");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
					bChoixSkill = false;
					timerChoixSkill = 0.0f;
				}
			}
			if (_perso1.SKILL[8] == true) {
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Skill 4 : Invoque un villagois kidnapper !! A venir Prochainement !!", "Skill 4: Summon a villagois kidnap!! Coming soon !!");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
					bChoixSkill = false;
					timerChoixSkill = 0.0f;
				}
			}
		}
		else {
			tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Vous ne posseder pas de skill 4", "You don't have skill 4");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
				bChoixSkill = false;
				timerChoixSkill = 0.0f;
			}
		}
		break;
	case 5:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureA, "Retour au choix d'attaque", "Back to attack choice");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
			bChoixSkill = false;
			timerChoixSkill = 0.0f;
		}
		break;
	default:
		break;
	}
}

void Aventure::Fuite(Joueur& _perso1, Joueur& _perso2, ModeGame& _mode) {
	_perso1.SetTotPv(_perso1.GetTotPvMax());
	_perso1.persoPosition = sf::Vector2f(AjustResoX * 950, AjustResoY * 317);
	_mode = ModeGame::LIBRE;
}

void Aventure::displayAventure(myWindow& _window, ModeGame& _mode, Joueur& _perso1, AventureGame& _modeAv) {
	if (_mode == ModeGame::LIBRE) {
		if (_modeAv == AventureGame::ZONE_MAGE) {
			if (irsVieMag >= 1) {
				_window.Draw(spMag);
			}
			if (irsVieMag2 >= 1) {
				_window.Draw(spMag2);
			}
			if (irsVieMag3 >= 1) {
				_window.Draw(spMag3);
			}
			if (irsVieMag4 >= 1) {
				_window.Draw(spMag4);
			}
			if (irsVieVill >= 1) {
				_window.Draw(spVill);
			}
		}
		if (_modeAv == AventureGame::ZONE_ASSASSIN) {
			if (irsVieAss >= 1) {
				_window.Draw(spAss);
			}
			if (irsVieAss2 >= 1) {
				_window.Draw(spAss2);
			}
			if (irsVieAss3 >= 1) {
				_window.Draw(spAss3);
			}
			if (irsVieAss4 >= 1) {
				_window.Draw(spAss4);
			}
			if (irsVieVill >= 1) {
				_window.Draw(spVill);
			}
		}
		if (_modeAv == AventureGame::ZONE_GUERRIER) {
			if (irsVieGuer >= 1) {
				_window.Draw(spGuer);
			}
			if (irsVieGuer2 >= 1) {
				_window.Draw(spGuer2);
			}
			if (irsVieGuer3 >= 1) {
				_window.Draw(spGuer3);
			}
			if (irsVieGuer4 >= 1) {
				_window.Draw(spGuer4);
			}
			if (irsVieVill >= 1) {
				_window.Draw(spVill);
			}
		}
		if (_modeAv == AventureGame::ZONE_CLERC) {
			if (irsVieClerc >= 1) {
				_window.Draw(spClerc);
			}
			if (irsVieClerc2 >= 1) {
				_window.Draw(spClerc2);
			}
			if (irsVieClerc3 >= 1) {
				_window.Draw(spClerc3);
			}
			if (irsVieClerc4 >= 1) {
				_window.Draw(spClerc4);
			}
			if (irsVieVill >= 1) {
				_window.Draw(spVill);
			}
		}
		if (_modeAv == AventureGame::AVENTURE) {

			if (irsVieAss >= 1) {
				_window.Draw(spAss);
			}
			if (irsVieGuer >= 1) {
				_window.Draw(spGuer);
			}
			if (irsVieClerc >= 1) {
				_window.Draw(spClerc);
			}
			if (irsVieMag >= 1) {
				_window.Draw(spMag);
			}
			if (irsVieVill >= 1) {
				_window.Draw(spVill);
			}


			if (bPnj == true) {
				boiteDiscussion::displayBoiteDiscussion(_window);
				txParoleAv.setPosition(postexte);
				tools::ChoixLangue(tools::GetTrad(), txParoleAv, stParoleAv, stParoleAvEn);
				_window.Draw(txParoleAv);
			}
		}
	}
	if (_mode == ModeGame::AVE) {
		_perso1.AfficheStats(_window, txStatsPerso);
		if (bAss == true) {
			AssassinEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spAss);
		}
		if (bAss2 == true) {
			AssassinEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spAss2);
		}
		if (bAss3 == true) {
			AssassinEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spAss3);
		}
		if (bAss4 == true) {
			AssassinEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spAss4);
		}
		if (bGuer == true) {
			GuerrierEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spGuer);
		}
		if (bGuer2 == true) {
			GuerrierEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spGuer2);
		}
		if (bGuer3 == true) {
			GuerrierEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spGuer3);
		}
		if (bGuer4 == true) {
			GuerrierEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spGuer4);
		}
		if (bClerc == true) {
			ClercEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spClerc);
		}
		if (bClerc2 == true) {
			ClercEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spClerc2);
		}
		if (bClerc3 == true) {
			ClercEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spClerc3);
		}
		if (bClerc4 == true) {
			ClercEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spClerc4);
		}
		if (bMag == true) {
			MagicienEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spMag);
		}
		if (bMag2 == true) {
			MagicienEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spMag2);
		}
		if (bMag3 == true) {
			MagicienEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spMag3);
		}
		if (bMag4 == true) {
			MagicienEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spMag4);
		}
		if (bVill == true) {
			VillagoisEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spVill);
		}
		if (bChoixAction == true && bDescCombat == false && bChoixObjet == false && bChoixSkill == false) {

			switch (choixActionA)
			{
			case 1:
				AventureAttaque.setScale(1.2, 1.2);
				AventureSkill.setScale(1, 1);
				AventureObjet.setScale(1, 1);
				AventureFuite.setScale(1, 1);
				break;
			case 2:
				AventureAttaque.setScale(1, 1);
				AventureSkill.setScale(1.2, 1.2);
				AventureObjet.setScale(1, 1);
				AventureFuite.setScale(1, 1);
				break;
			case 3:
				AventureAttaque.setScale(1, 1);
				AventureSkill.setScale(1, 1);
				AventureObjet.setScale(1.2, 1.2);
				AventureFuite.setScale(1, 1);
				break;
			case 4:
				AventureAttaque.setScale(1, 1);
				AventureSkill.setScale(1, 1);
				AventureObjet.setScale(1, 1);
				AventureFuite.setScale(1.2, 1.2);
				break;
			default:
				break;
			}
			_window.Draw(ActionAventure);
			_window.Draw(DetailActionAventureA);
			_window.Draw(AventureAttaque);
			_window.Draw(AventureSkill);
			_window.Draw(AventureFuite);
			_window.Draw(AventureObjet);
		}
		if (bChoixObjet == true && bDescCombat == false && bChoixSkill == false) {
			switch (choixActionO)
			{
			case 1:
				txSoinPV.setScale(1.2, 1.2);
				txSoinMana.setScale(1, 1);
				txBombe.setScale(1, 1);
				txRetourAction.setScale(1, 1);
				break;
			case 2:
				txSoinPV.setScale(1, 1);
				txSoinMana.setScale(1.2, 1.2);
				txBombe.setScale(1, 1);
				txRetourAction.setScale(1, 1);
				break;
			case 3:
				txSoinPV.setScale(1, 1);
				txSoinMana.setScale(1, 1);
				txBombe.setScale(1.2, 1.2);
				txRetourAction.setScale(1, 1);
				break;
			case 4:
				txSoinPV.setScale(1, 1);
				txSoinMana.setScale(1, 1);
				txBombe.setScale(1, 1);
				txRetourAction.setScale(1.2, 1.2);
				break;
			default:
				break;
			}
			_window.Draw(ActionAventure);
			_window.Draw(DetailActionAventureA);
			_window.Draw(txSoinPV);
			_window.Draw(txSoinMana);
			_window.Draw(txBombe);
			_window.Draw(txRetourAction);
		}
		if (bChoixSkill == true && bDescCombat == false && bChoixObjet == false) {
			switch (choixskill)
			{
			case 1:
				txSkill1.setScale(1.2, 1.2);
				txSkill2.setScale(1, 1);
				txSkill3.setScale(1, 1);
				txSkill4.setScale(1, 1);
				txRetourAction.setScale(1, 1);
				break;
			case 2:
				txSkill1.setScale(1, 1);
				txSkill2.setScale(1.2, 1.2);
				txSkill3.setScale(1, 1);
				txSkill4.setScale(1, 1);
				txRetourAction.setScale(1, 1);
				break;
			case 3:
				txSkill1.setScale(1, 1);
				txSkill2.setScale(1, 1);
				txSkill3.setScale(1.2, 1.2);
				txSkill4.setScale(1, 1);
				txRetourAction.setScale(1, 1);
				break;
			case 4:
				txSkill1.setScale(1, 1);
				txSkill2.setScale(1, 1);
				txSkill3.setScale(1, 1);
				txSkill4.setScale(1.2, 1.2);
				txRetourAction.setScale(1, 1);
				break;
			case 5:
				txSkill1.setScale(1, 1);
				txSkill2.setScale(1, 1);
				txSkill3.setScale(1, 1);
				txSkill4.setScale(1, 1);
				txRetourAction.setScale(1.2, 1.2);
				break;
			default:
				break;
			}
			_window.Draw(ActionAventure);
			_window.Draw(DetailActionAventureA);
			_window.Draw(txSkill1);
			_window.Draw(txSkill2);
			_window.Draw(txSkill3);
			_window.Draw(txSkill4);
			_window.Draw(txRetourAction);
		}
		if (bDescCombat == true) {
			if (iDescCombat == 1) {
				if (bVictory == false) {
					tools::ChoixLangue(tools::GetTrad(), txDescCombat, stDescCombatP + stNomEnnemi + stNbDegP + std::to_string((int)degatFinal), stDescCombatPEn + stNomEnnemi + stNbDegPEn + std::to_string((int)degatFinal));
					_window.Draw(txDescCombat);
				}
				else {
					tools::ChoixLangue(tools::GetTrad(), txDescCombat, stDescCombatP + stNomEnnemi + stNbDegP + std::to_string((int)degatFinal) + stVictory, stDescCombatPEn + stNomEnnemiEn + stNbDegPEn + std::to_string((int)degatFinal) + stVictoryEn);
					_window.Draw(txDescCombat);
				}
			}
			if (iDescCombat == 2) {
				tools::ChoixLangue(tools::GetTrad(), txDescCombat, stNomEnnemi + stDescCombatM + stNbDegM + std::to_string((int)degatFinal), stNomEnnemiEn + stDescCombatMEn + stNbDegMEn + std::to_string((int)degatFinal));
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 3) {
				tools::ChoixLangue(tools::GetTrad(), txDescCombat, stObj, stObjEn);
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 5) {
				tools::ChoixLangue(tools::GetTrad(), txDescCombat, stFuiteok, stFuiteokEn);
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 6) {
				txDescCombat.setString(stFuiteR);
				tools::ChoixLangue(tools::GetTrad(), txDescCombat, stFuiteR, stFuiteREn);
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 7) {
				tools::ChoixLangue(tools::GetTrad(), txDescCombat, stBoostAtk, stBoostAtkEn);
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 8) {
				tools::ChoixLangue(tools::GetTrad(), txDescCombat, stBoostDef, stBoostDefEn);
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 9) {
				tools::ChoixLangue(tools::GetTrad(), txDescCombat, stPoison, stPoisonEn);
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 10) {
				tools::ChoixLangue(tools::GetTrad(), txDescCombat, stImmunite, stImmuniteEn);
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 13) {
				tools::ChoixLangue(tools::GetTrad(), txDescCombat, stClercHeal + std::to_string((int)degatFinal), stClercHealEn + std::to_string((int)degatFinal));
				_window.Draw(txDescCombat);
			}
		}
	}
}

void Aventure::LootCombat(Joueur& _perso1, AventureGame& _modeAv) {

	if (_modeAv == AventureGame::ZONE_ASSASSIN) {
		int tmp;
		tmp = _perso1.GetTotArgent() + 1000 * iZoneAv;
		_perso1.SetTotArgent(tmp);
	}
	if (_modeAv == AventureGame::ZONE_CLERC) {
		int tmp;
		tmp = tools::iRand(1, 4);
		if (tmp == 1)
			_perso1.SoinPvBuy += 1;
		if (tmp == 2)
			_perso1.SoinManaBuy += 1;
		if (tmp == 3)
			_perso1.BombeBuy += 1;
	}
	if (_modeAv == AventureGame::ZONE_GUERRIER) {
		int tmp;
		tmp = tools::iRand(1, 4);
		if (tmp == 1)
			_perso1.LegerBuy += 1;
		if (tmp == 2)
			_perso1.LourdBuy += 1;
		if (tmp == 3)
			_perso1.BouclierBuy += 1;
	}
	if (_modeAv == AventureGame::ZONE_MAGE) {
		int tmp;
		tmp = tools::iRand(1, 4);
		if (tmp == 1)
			_perso1.EpeeBuy += 1;
		if (tmp == 2)
			_perso1.LanceBuy += 1;
		if (tmp == 3)
			_perso1.BatonBuy += 1;
	}
}
