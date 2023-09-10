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

sf::Vector2f rsize{ 50,50 };

sf::Texture ttAss, ttGuer, ttClerc, ttMag, ttVill;

sf::Sprite spAss, spGuer, spClerc, spMag, spVill;

bool bPnj{ false },bVill{ false }, bAss{ false }, bMag{ false }, bGuer{ false }, bClerc{ false }, bAtkPerso{ false }, bFuite{ false }, bAtkMonstre{ false }, bChoixAction{ false }, bDescCombat{ false }, bChoixObjet{ false }, bChoixSkill{ false }, bIsSkill{ false }, bVictory{ false }, bDefaite{ false };

std::string stParoleAv, stNomEnnemi, stDescCombatP, stDescCombatM, stNbDegP, stNbDegM, stVictory, stDefaite, stBoostAtk, stBoostDef, stPoison, stImmunite, stClercHeal, stFuiteok, stFuiteR, stObj;

sf::Text txParoleAv, txStatsPerso, txStatsEnnemi, DetailActionAventureA, ActionAventure, AventureAttaque, AventureSkill, AventureObjet, AventureFuite, txSoinPV, txSoinMana, txSkill1, txSkill2, txSkill3, txSkill4, txBombe, txRetourAction, txDescCombat;

sf::Font fontAv;

int choixskill{ 1 }, irsVieAss{ 1 }, irsVieGuer{ 1 }, irsVieClerc{ 1 }, irsVieMag{ 1 }, irsVieVill{ 1 }, iChoixCote{ 0 }, choixActionA{ 1 }, choixActionO{ 1 }, iDescCombat{ 0 }, iNbAss{ 0 }, iNbGuer{ 0 }, iNbMag{ 0 }, iNbClerc{ 0 }, iNbVill{ 0 };

float timerChoixActionA{ 0.0f }, timerDescritionCombat{ 0.0f }, timerChoixSkill{ 0.0f };

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
	ttGuer.loadFromFile("..\\Ressources\\Textures\\CLASSE\\Guerrier.png");
	spGuer.setTexture(ttGuer);
	spGuer.setScale(0.2, 0.2);
	ttClerc.loadFromFile("..\\Ressources\\Textures\\CLASSE\\Clerc.png");
	spClerc.setTexture(ttClerc);
	spClerc.setScale(0.18, 0.18);
	ttMag.loadFromFile("..\\Ressources\\Textures\\CLASSE\\Magicien.png");
	spMag.setTexture(ttMag);
	spMag.setScale(0.2, 0.2);
	ttVill.loadFromFile("..\\Ressources\\Textures\\CLASSE\\Villagois.png");
	spVill.setTexture(ttVill);
	spVill.setScale(0.35, 0.35);

	rsAss.setSize(rsize);
	rsAss.setFillColor(sf::Color::Cyan);

	rsGuer.setSize(rsize);
	rsGuer.setFillColor(sf::Color::Red);

	rsClerc.setSize(rsize);
	rsClerc.setFillColor(sf::Color::Yellow);

	rsMag.setSize(rsize);
	rsMag.setFillColor(sf::Color::Green);

	rsVill.setSize(rsize);
	rsVill.setFillColor(sf::Color::Black);

	posRsAss = { 200,300 };
	posRsGuerr = { 900,300 };
	posRsClerc = { 600,420 };
	posRsMag = { 500,80 };
	posRsVill = { 500,300 };

	ennemis.push_back(&VillagoisEnnemi);
	ennemis.push_back(&AssassinEnnemi);
	ennemis.push_back(&GuerrierEnnemi);
	ennemis.push_back(&ClercEnnemi);
	ennemis.push_back(&MagicienEnnemi);

	postexte = { 100,470 };
	txParoleAv.setFont(fontAv);
	txParoleAv.setFillColor(sf::Color::Black);

	posCombatAv = { 270,190 };
	posCombatEnemi = { 930,160 };

	txStatsPerso.setFont(fontAv);
	txStatsPerso.setOrigin(txStatsPerso.getGlobalBounds().height / 2, txStatsPerso.getGlobalBounds().width / 2);
	txStatsPerso.setPosition(25, 40);
	txStatsPerso.setFillColor(sf::Color::Red);

	txStatsEnnemi.setFont(fontAv);
	txStatsEnnemi.setOrigin(txStatsEnnemi.getGlobalBounds().height / 2, txStatsEnnemi.getGlobalBounds().width / 2);
	txStatsEnnemi.setPosition(1133, 45);
	txStatsEnnemi.setFillColor(sf::Color::Red);

	DetailActionAventureA.setFont(fontAv);
	DetailActionAventureA.setOrigin(DetailActionAventureA.getGlobalBounds().height / 2, DetailActionAventureA.getGlobalBounds().width / 2);
	DetailActionAventureA.setPosition(100, 560);
	DetailActionAventureA.setFillColor(sf::Color::Red);

	ActionAventure.setFont(fontAv);
	ActionAventure.setOrigin(ActionAventure.getGlobalBounds().height / 2, ActionAventure.getGlobalBounds().width / 2);
	ActionAventure.setPosition(300, 510);
	ActionAventure.setFillColor(sf::Color::Red);

	AventureAttaque.setFont(fontAv);
	AventureAttaque.setOrigin(AventureAttaque.getGlobalBounds().height / 2, AventureAttaque.getGlobalBounds().width / 2);
	AventureAttaque.setPosition(120, 375);
	AventureAttaque.setFillColor(sf::Color::Red);

	AventureSkill.setFont(fontAv);
	AventureSkill.setOrigin(AventureSkill.getGlobalBounds().height / 2, AventureSkill.getGlobalBounds().width / 2);
	AventureSkill.setPosition(390, 375);
	AventureSkill.setFillColor(sf::Color::Red);

	AventureObjet.setFont(fontAv);
	AventureObjet.setOrigin(AventureObjet.getGlobalBounds().height / 2, AventureObjet.getGlobalBounds().width / 2);
	AventureObjet.setPosition(660, 375);
	AventureObjet.setFillColor(sf::Color::Red);

	AventureFuite.setFont(fontAv);
	AventureFuite.setOrigin(AventureFuite.getGlobalBounds().height / 2, AventureFuite.getGlobalBounds().width / 2);
	AventureFuite.setPosition(930, 375);
	AventureFuite.setFillColor(sf::Color::Red);

	txSoinPV.setFont(fontAv);
	txSoinPV.setOrigin(txSoinPV.getGlobalBounds().height / 2, txSoinPV.getGlobalBounds().width / 2);
	txSoinPV.setPosition(120, 375);
	txSoinPV.setFillColor(sf::Color::Red);

	txDescCombat.setFont(fontAv);
	txDescCombat.setOrigin(txDescCombat.getGlobalBounds().height / 2, txDescCombat.getGlobalBounds().width / 2);
	txDescCombat.setPosition(100, 560);
	txDescCombat.setFillColor(sf::Color::Red);

	txSoinMana.setFont(fontAv);
	txSoinMana.setOrigin(txSoinMana.getGlobalBounds().height / 2, txSoinMana.getGlobalBounds().width / 2);
	txSoinMana.setPosition(390, 375);
	txSoinMana.setFillColor(sf::Color::Red);

	txBombe.setFont(fontAv);
	txBombe.setOrigin(txBombe.getGlobalBounds().height / 2, txBombe.getGlobalBounds().width / 2);
	txBombe.setPosition(660, 375);
	txBombe.setFillColor(sf::Color::Red);

	txSkill1.setFont(fontAv);
	txSkill1.setOrigin(txSkill1.getGlobalBounds().height / 2, txSkill1.getGlobalBounds().width / 2);
	txSkill1.setPosition(120, 375);
	txSkill1.setFillColor(sf::Color::Red);

	txSkill2.setFont(fontAv);
	txSkill2.setOrigin(txSkill2.getGlobalBounds().height / 2, txSkill2.getGlobalBounds().width / 2);
	txSkill2.setPosition(390, 375);
	txSkill2.setFillColor(sf::Color::Red);

	txSkill3.setFont(fontAv);
	txSkill3.setOrigin(txSkill3.getGlobalBounds().height / 2, txSkill3.getGlobalBounds().width / 2);
	txSkill3.setPosition(660, 375);
	txSkill3.setFillColor(sf::Color::Red);

	txSkill4.setFont(fontAv);
	txSkill4.setOrigin(txSkill4.getGlobalBounds().height / 2, txSkill4.getGlobalBounds().width / 2);
	txSkill4.setPosition(930, 375);
	txSkill4.setFillColor(sf::Color::Red);

	txRetourAction.setFont(fontAv);
	txRetourAction.setOrigin(txRetourAction.getGlobalBounds().height / 2, txRetourAction.getGlobalBounds().width / 2);
	txRetourAction.setPosition(1133, 375);
	txRetourAction.setFillColor(sf::Color::Red);

	ActionAventure.setString("Choisissez votre action :");
	AventureAttaque.setString("Attaque");
	AventureSkill.setString("Skill");
	AventureObjet.setString("Objet");
	AventureFuite.setString("Fuite");

	txSkill1.setString("Skill 1");
	txSkill2.setString("Skill 2");
	txSkill3.setString("Skill 3");
	txSkill4.setString("Skill 4");

	txSoinPV.setString("Soin PV");
	txSoinMana.setString("Soin Mana");
	txBombe.setString("Bombe");
	txRetourAction.setString("Retour");

	stDescCombatP = { "Vous avez attaque le " };
	stDescCombatM = { " vous a attaque" };
	stNbDegP = { ". Les degats inflige sont de : " };
	stNbDegM = { ". Les degats subis sont de :" };
	stVictory = { "\nFelicitation vous avez gagne" };
	stDefaite = { "\nVous avez perdu, le ranger va vous soigner" };

	stBoostAtk = { "Votre attaque est booster" };
	stBoostDef = { "Votre defense est booster" };
	stPoison = { "Vous avez infliger poison au monstre" };
	stImmunite = { "Vous vous etes mis une immunite" };
	stClercHeal = { "L'ennemi a gagner des pv :" };

	stFuiteok = "Vous allez reussir a fuire";
	stFuiteR = "Echec de la fuite";

	boiteDiscussion::initBoiteDiscussion();
}

void Aventure::UpdateAventure(Joueur& _perso1, ModeGame& _mode, Consos& _conso) {

	if (_mode == ModeGame::LIBRE) {

		if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posRsVill, rsize)) {
			bPnj = true;
			stParoleAv = { "Battez mes 4 sbires si vous pensez pouvoir m'affronter" };
		}
		else
			bPnj = false;

		if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsAss, rsize) && irsVieAss >= 1) {

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
		if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsGuerr, rsize) && irsVieGuer >= 1) {

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
		if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsClerc, rsize) && irsVieClerc >= 1) {

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
		if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posRsMag, rsize) && irsVieMag >= 1) {

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
		if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posRsVill, rsize) && iNbAss > 0 && iNbGuer > 0 && iNbClerc > 0 && iNbMag > 0) {

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
	if (_mode == ModeGame::AVE) {

		if (bAss == true) {
			combatAventureAss(_perso1, assassinA, _conso, _mode);
		}
		if (bClerc == true) {
			combatAventureClerc(_perso1, clercA, _conso, _mode);
		}
		if (bGuer == true) {
			combatAventureGuer(_perso1, guerrierA, _conso, _mode);
		}
		if (bMag == true) {
			combatAventureMag(_perso1, magicienA, _conso, _mode);
		}
		if (bVill == true) {
			combatAventureVill(_perso1, villagoisA, _conso, _mode);
		}
	}
	spAss.setPosition(posRsAss);
	spGuer.setPosition(posRsGuerr);
	spClerc.setPosition(posRsClerc);
	spMag.setPosition(posRsMag);
	spVill.setPosition(posRsVill);
	rsAss.setPosition(posRsAss);
	rsGuer.setPosition(posRsGuerr);
	rsClerc.setPosition(posRsClerc);
	rsMag.setPosition(posRsMag);
	rsVill.setPosition(posRsVill);
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
		DetailActionAventureA.setString("Attaque : l'attaque de base prend en compte l'attaque du lanceur\n et la defense de la cible puis applique l'avantage selon l'element");
		break;
	case 2:
		DetailActionAventureA.setString("Skill : Permet d'utiliser une competence possede");
		break;
	case 3:
		DetailActionAventureA.setString("Objet : Permet d'utilise un objet equipe");
		break;
	case 4:
		DetailActionAventureA.setString("Fuite : Permet de fuir un combat, si votre vitesse est superieur a celle\n de l'adversaire fuite a 100%, sinon selon une probabilite");
		break;
	default:
		break;
	}
}

void Aventure::combatAventureAss(Joueur& _perso1, Assassin& _perso2, Consos& _conso, ModeGame& _mode) {
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
				irsVieAss = 0;
				_perso1.Experience((30 * AssassinEnnemi.GetNiveau()));
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
				posRsAss = posSaveMonstre;
				_perso1.persoPosition.x = posSavePosition.x;
				_perso1.persoPosition.y = posSavePosition.y + 20;
				bAss = false;
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
				bAss = false;
				bFuite = false;
			}
		}
	}
}

void Aventure::combatAventureMag(Joueur& _perso1, Magicien& _perso2, Consos& _conso, ModeGame& _mode) {
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
				irsVieMag = 0;
				_perso1.Experience((30 * MagicienEnnemi.GetNiveau()));
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
				posRsMag = posSaveMonstre;
				_perso1.persoPosition.x = posSavePosition.x;
				_perso1.persoPosition.y = posSavePosition.y + 20;
				bMag = false;
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
				bMag = false;
				bFuite = false;
			}
		}
	}
}

void Aventure::combatAventureGuer(Joueur& _perso1, Guerrier& _perso2, Consos& _conso, ModeGame& _mode) {
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
				irsVieGuer = 0;
				_perso1.Experience((30 * GuerrierEnnemi.GetNiveau()));
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
				posRsGuerr = posSaveMonstre;
				_perso1.persoPosition.x = posSavePosition.x;
				_perso1.persoPosition.y = posSavePosition.y + 20;
				bGuer = false;
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
				bGuer = false;
				bFuite = false;
			}
		}
	}
}

void Aventure::combatAventureClerc(Joueur& _perso1, Clerc& _perso2, Consos& _conso, ModeGame& _mode) {
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
				irsVieClerc = 0;
				_perso1.Experience((30 * ClercEnnemi.GetNiveau()));
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
				bClerc = false;
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
				posRsClerc = posSaveMonstre;
				Fuite(_perso1, ClercEnnemi, _mode);
				bClerc = false;
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
		DetailActionAventureA.setString("Vous allez soigner vos PV");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
			if (_perso1.SoinPvBuy >= 1) {
				tmpint = _perso1.GetTotPvMax() - _perso1.GetTotPv();
				stObj = { "Vous avez soigne vos Pv de " + std::to_string(tmpint) };
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
				bChoixObjet = false;
				bDescCombat = true;
				iDescCombat = 3;
			}
			timerChoixActionA = 0.0f;
		}
		break;
	case 2:
		DetailActionAventureA.setString("Vous allez soigner votre Mana");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionA > 0.3f) {
			if (_perso1.SoinManaBuy >= 1) {
				tmpint = _perso1.GetTotManaMax() - _perso1.GetTotMana();
				stObj = { "Vous avez soigne votre Mana de " + tmpint };
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
				bChoixObjet = false;
				bDescCombat = true;
				iDescCombat = 3;
			}
			timerChoixActionA = 0.0f;
		}
		break;
	case 3:
		DetailActionAventureA.setString("Vous allez faire des degats au monstre");
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
				bChoixObjet = false;
				bDescCombat = true;
				iDescCombat = 3;
			}
			timerChoixActionA = 0.0f;
		}
		break;
	case 4:
		DetailActionAventureA.setString("Retour au choix d'attaque");
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
			DetailActionAventureA.setString("Skill 1 : Attaque avec le double de degats");
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
			DetailActionAventureA.setString("Vous ne posseder pas de skill 1");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
				bChoixSkill = false;
				timerChoixSkill = 0.0f;
			}
		}
		break;
	case 2:
		if (_perso1.SKILL[1] == true || _perso1.SKILL[2] == true) {
			if (_perso1.SKILL[1] == true) {
				DetailActionAventureA.setString("Skill 2 : Attaque en ignorant les elements");
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
				DetailActionAventureA.setString("Skill 2 : Attaque en ignorant la defense");
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
			DetailActionAventureA.setString("Vous ne posseder pas de skill 2");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
				bChoixSkill = false;
				timerChoixSkill = 0.0f;
			}
		}
		break;
	case 3:
		if (_perso1.SKILL[3] == true || _perso1.SKILL[4] == true || _perso1.SKILL[5] == true || _perso1.SKILL[6] == true) {
			if (_perso1.SKILL[3] == true) {
				DetailActionAventureA.setString("Skill 3 : Boost des degats pour 2 tour (50%)");
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
				DetailActionAventureA.setString("Skill 3 : Boost de la resistance aux degats pour 2 tour (50%)");
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
				DetailActionAventureA.setString("Skill 3 : Inflige poison pendant 2 tour(50% de l'attaque)");
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
				DetailActionAventureA.setString("Skill 3 : S'octroie une immunite a tous degats (2 tour)");
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
			DetailActionAventureA.setString("Vous ne posseder pas de skill 3");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
				bChoixSkill = false;
				timerChoixSkill = 0.0f;
			}
		}
		break;
	case 4:
		if (_perso1.SKILL[7] == true || _perso1.SKILL[8] == true) {
			if (_perso1.SKILL[7] == true) {
				DetailActionAventureA.setString("Skill 4 : Invoque une creature !! A venir Prochainement !!");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
					bChoixSkill = false;
					timerChoixSkill = 0.0f;
				}
			}
			if (_perso1.SKILL[8] == true) {
				DetailActionAventureA.setString("Skill 4 : Invoque un villagois kidnapper !! A venir Prochainement !! ");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
					bChoixSkill = false;
					timerChoixSkill = 0.0f;
				}
			}
		}
		else {
			DetailActionAventureA.setString("Vous ne posseder pas de skill 4");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
				bChoixSkill = false;
				timerChoixSkill = 0.0f;
			}
		}
		break;
	case 5:
		DetailActionAventureA.setString("Retour au choix d'attaque");
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
	_perso1.persoPosition.x = posSavePosition.x;
	_perso1.persoPosition.y = posSavePosition.y + 50;
	_mode = ModeGame::LIBRE;
}

void Aventure::displayAventure(myWindow& _window, ModeGame& _mode, Joueur& _perso1) {
	if (_mode == ModeGame::LIBRE) {

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
			txParoleAv.setString(stParoleAv);
			_window.Draw(txParoleAv);
		}
	}
	if (_mode == ModeGame::AVE) {
		_perso1.AfficheStats(_window, txStatsPerso);
		if (bAss == true) {
			AssassinEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spAss);
		}
		if (bGuer == true) {
			GuerrierEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spGuer);
		}
		if (bClerc == true) {
			ClercEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spClerc);
		}
		if (bMag == true) {
			MagicienEnnemi.AfficheStats(_window, txStatsEnnemi);
			_window.Draw(spMag);
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
					txDescCombat.setString(stDescCombatP + stNomEnnemi + stNbDegP + std::to_string((int)degatFinal));
					_window.Draw(txDescCombat);
				}
				else {
					txDescCombat.setString(stDescCombatP + stNomEnnemi + stNbDegP + std::to_string((int)degatFinal) + stVictory);
					_window.Draw(txDescCombat);
				}
			}
			if (iDescCombat == 2) {
				txDescCombat.setString(stNomEnnemi + stDescCombatM + stNbDegM + std::to_string((int)degatFinal));
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 3) {
				txDescCombat.setString(stObj);
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 5) {
				txDescCombat.setString(stFuiteok);
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 6) {
				txDescCombat.setString(stFuiteR);
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 7) {
				txDescCombat.setString(stBoostAtk);
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 8) {
				txDescCombat.setString(stBoostDef);
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 9) {
				txDescCombat.setString(stPoison);
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 10) {
				txDescCombat.setString(stImmunite);
				_window.Draw(txDescCombat);
			}
			if (iDescCombat == 13) {
				txDescCombat.setString(stClercHeal + std::to_string((int)degatFinal));
				_window.Draw(txDescCombat);
			}
		}
	}
}