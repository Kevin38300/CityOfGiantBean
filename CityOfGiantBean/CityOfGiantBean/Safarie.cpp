#include "Safarie.h"
#include "Joueur.h"
#include "Monstre.h"
#include "Consos.h"

#define PlusRapide(_perso1 , _perso2) (((_perso1.GetTotVitesse())>=(_perso2.GetTotVitesse()))?(true):(false))

Gobelin gobelin = Gobelin();
Orc orc = Orc();
Ours ours = Ours();
Loup loup = Loup();

Monstre Gobelin1;
Monstre Gobelin2;
Monstre Gobelin3;
Monstre Gobelin4;
Monstre Ours1;
Monstre Ours2;
Monstre Ours3;
Monstre Ours4;
Monstre Orc1;
Monstre Orc2;
Monstre Orc3;
Monstre Orc4;
Monstre Loup1;
Monstre Loup2;
Monstre Loup3;
Monstre Loup4;

void Safarie::initSafari() {
	fontS.loadFromFile("../Ressources/Fonts/Typewriter.ttf");

	posRoiGoblein = { AjustResoX * 752.0f, AjustResoY * 663.0f };
	rsRoiGobelin.setSize(sf::Vector2f(AjustResoX * 84, AjustResoY * 69));
	rsRoiGobelin.setPosition(posRoiGoblein);
	rsRoiGobelin.setFillColor(sf::Color::Cyan);

	posRoiOurs = { AjustResoX * 1136.0f, AjustResoY * 503.0f };
	rsRoiOurs.setSize(sf::Vector2f(AjustResoX * 106, AjustResoY * 90));
	rsRoiOurs.setPosition(posRoiOurs);
	rsRoiOurs.setFillColor(sf::Color::Cyan);

	posRoiOrc = { AjustResoX * 803.0f, AjustResoY * 349.0f };
	rsRoiOrc.setSize(sf::Vector2f(AjustResoX * 64, AjustResoY * 73));
	rsRoiOrc.setPosition(posRoiOrc);
	rsRoiOrc.setFillColor(sf::Color::Cyan);

	posRoiLoup = { AjustResoX * 537.0f, AjustResoY * 484.0f };
	rsRoiLoup.setSize(sf::Vector2f(AjustResoX * 88, AjustResoY * 74));
	rsRoiLoup.setPosition(posRoiLoup);
	rsRoiLoup.setFillColor(sf::Color::Cyan);

	posRanger = { AjustResoX * 949.0f, AjustResoY * 486.0f };
	rsRanger.setSize(sf::Vector2f(AjustResoX * 67, AjustResoY * 82));
	rsRanger.setPosition(posRanger);
	rsRanger.setFillColor(sf::Color::Cyan);

	boiteDiscussion::initBoiteDiscussion();
	posText = { AjustResoX * 150.0f, AjustResoY * 850.0f };
	txParoleSafarie.setFont(fontS);
	txParoleSafarie.setFillColor(sf::Color::Black);


	txLevelUp.setFont(fontS);
	txLevelUp.setOrigin(txLevelUp.getGlobalBounds().height / 2, txLevelUp.getGlobalBounds().width / 2);
	txLevelUp.setPosition(AjustResoX * 150.0f, AjustResoY * 800.0f);
	txLevelUp.setFillColor(sf::Color::Red);

	DetailActionAventureS.setFont(fontS);
	DetailActionAventureS.setOrigin(DetailActionAventureS.getGlobalBounds().height / 2, DetailActionAventureS.getGlobalBounds().width / 2);
	DetailActionAventureS.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	DetailActionAventureS.setFillColor(sf::Color::Red);

	ActionAventureS.setFont(fontS);
	ActionAventureS.setOrigin(ActionAventureS.getGlobalBounds().height / 2, ActionAventureS.getGlobalBounds().width / 2);
	ActionAventureS.setPosition(AjustResoX * 150.0f, AjustResoY * 800.0f);
	ActionAventureS.setFillColor(sf::Color::Red);

	AventureAttaqueS.setFont(fontS);
	AventureAttaqueS.setOrigin(AventureAttaqueS.getGlobalBounds().height / 2, AventureAttaqueS.getGlobalBounds().width / 2);
	AventureAttaqueS.setPosition(AjustResoX * 195.0f, AjustResoY * 645.0f);
	AventureAttaqueS.setFillColor(sf::Color::Red);

	AventureSkillS.setFont(fontS);
	AventureSkillS.setOrigin(AventureSkillS.getGlobalBounds().height / 2, AventureSkillS.getGlobalBounds().width / 2);
	AventureSkillS.setPosition(AjustResoX * 470.0f, AjustResoY * 645.0f);
	AventureSkillS.setFillColor(sf::Color::Red);

	AventureObjetS.setFont(fontS);
	AventureObjetS.setOrigin(AventureObjetS.getGlobalBounds().height / 2, AventureObjetS.getGlobalBounds().width / 2);
	AventureObjetS.setPosition(AjustResoX * 851.0f, AjustResoY * 645.0f);
	AventureObjetS.setFillColor(sf::Color::Red);

	AventureFuiteS.setFont(fontS);
	AventureFuiteS.setOrigin(AventureFuiteS.getGlobalBounds().height / 2, AventureFuiteS.getGlobalBounds().width / 2);
	AventureFuiteS.setPosition(AjustResoX * 1188.0f, AjustResoY * 645.0f);
	AventureFuiteS.setFillColor(sf::Color::Red);

	txStatsMonstre.setFont(fontS);
	txStatsMonstre.setOrigin(txStatsMonstre.getGlobalBounds().height / 2, txStatsMonstre.getGlobalBounds().width / 2);
	txStatsMonstre.setPosition(AjustResoX * 1526.0f, AjustResoY * 85.0f);
	txStatsMonstre.setFillColor(sf::Color::Red);

	txStatsPerso.setFont(fontS);
	txStatsPerso.setOrigin(txStatsPerso.getGlobalBounds().height / 2, txStatsPerso.getGlobalBounds().width / 2);
	txStatsPerso.setPosition(AjustResoX * 32.0f, AjustResoY * 80.0f);
	txStatsPerso.setFillColor(sf::Color::Red);

	txDescCombat.setFont(fontS);
	txDescCombat.setOrigin(txDescCombat.getGlobalBounds().height / 2, txDescCombat.getGlobalBounds().width / 2);
	txDescCombat.setPosition(AjustResoX * 150.0f, AjustResoY * 800.0f);
	txDescCombat.setFillColor(sf::Color::Red);

	txElevation.setFont(fontS);
	txElevation.setOrigin(txElevation.getGlobalBounds().height / 2, txElevation.getGlobalBounds().width / 2);
	txElevation.setPosition(AjustResoX * 150.0f, AjustResoY * 950.0f);
	txElevation.setFillColor(sf::Color::Black);


	txSoinPV.setFont(fontS);
	txSoinPV.setOrigin(txSoinPV.getGlobalBounds().height / 2, txSoinPV.getGlobalBounds().width / 2);
	txSoinPV.setPosition(AjustResoX * 195.0f, AjustResoY * 645.0f);
	txSoinPV.setFillColor(sf::Color::Red);

	txSoinMana.setFont(fontS);
	txSoinMana.setOrigin(txSoinMana.getGlobalBounds().height / 2, txSoinMana.getGlobalBounds().width / 2);
	txSoinMana.setPosition(AjustResoX * 470.0f, AjustResoY * 645.0f);
	txSoinMana.setFillColor(sf::Color::Red);

	txBombe.setFont(fontS);
	txBombe.setOrigin(txBombe.getGlobalBounds().height / 2, txBombe.getGlobalBounds().width / 2);
	txBombe.setPosition(AjustResoX * 851.0f, AjustResoY * 645.0f);
	txBombe.setFillColor(sf::Color::Red);

	txFilet.setFont(fontS);
	txFilet.setOrigin(txFilet.getGlobalBounds().height / 2, txFilet.getGlobalBounds().width / 2);
	txFilet.setPosition(AjustResoX * 1188.0f, AjustResoY * 645.0f);
	txFilet.setFillColor(sf::Color::Red);

	txSkill1.setFont(fontS);
	txSkill1.setOrigin(txSkill1.getGlobalBounds().height / 2, txSkill1.getGlobalBounds().width / 2);
	txSkill1.setPosition(AjustResoX * 195.0f, AjustResoY * 645.0f);
	txSkill1.setFillColor(sf::Color::Red);

	txSkill2.setFont(fontS);
	txSkill2.setOrigin(txSkill2.getGlobalBounds().height / 2, txSkill2.getGlobalBounds().width / 2);
	txSkill2.setPosition(AjustResoX * 470.0f, AjustResoY * 645.0f);
	txSkill2.setFillColor(sf::Color::Red);

	txSkill3.setFont(fontS);
	txSkill3.setOrigin(txSkill3.getGlobalBounds().height / 2, txSkill3.getGlobalBounds().width / 2);
	txSkill3.setPosition(AjustResoX * 851.0f, AjustResoY * 645.0f);
	txSkill3.setFillColor(sf::Color::Red);

	txSkill4.setFont(fontS);
	txSkill4.setOrigin(txSkill4.getGlobalBounds().height / 2, txSkill4.getGlobalBounds().width / 2);
	txSkill4.setPosition(AjustResoX * 1188.0f, AjustResoY * 645.0f);
	txSkill4.setFillColor(sf::Color::Red);

	txRetourAction.setFont(fontS);
	txRetourAction.setOrigin(txRetourAction.getGlobalBounds().height / 2, txRetourAction.getGlobalBounds().width / 2);
	txRetourAction.setPosition(AjustResoX * 1527.0f, AjustResoY * 645.0f);
	txRetourAction.setFillColor(sf::Color::Red);

	tools::ChoixLangue(tools::GetTrad(), ActionAventureS, "Choisissez votre action :", "Choose your action:");
	tools::ChoixLangue(tools::GetTrad(), AventureAttaqueS, "Attaque", "Attack");
	tools::ChoixLangue(tools::GetTrad(), AventureSkillS, "Skill", "Skill");
	tools::ChoixLangue(tools::GetTrad(), AventureObjetS, "Objet", "Item");
	tools::ChoixLangue(tools::GetTrad(), AventureFuiteS, "Fuite", "Feel");

	txSkill1.setString("Skill 1");
	txSkill2.setString("Skill 2");
	txSkill3.setString("Skill 3");
	txSkill4.setString("Skill 4");

	tools::ChoixLangue(tools::GetTrad(), txSoinPV, "Soin PV", "Healing PV");
	tools::ChoixLangue(tools::GetTrad(), txSoinMana, "Soin Mana", "Healing Mana");
	tools::ChoixLangue(tools::GetTrad(), txBombe, "Bombe", "Bomb");
	tools::ChoixLangue(tools::GetTrad(), txFilet, "Filet", "Net");
	tools::ChoixLangue(tools::GetTrad(), txSFilet, "Super Filet", "Super Net");
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
	stCatch = { "Capture reussi" };
	stNonCatch = { "Echec de la capture" };

	stBoostAtkEn = { "Your attack is increasing" };
	stBoostDefEn = { "Your defense is increase" };
	stPoisonEn = { "You have inflicted poison on the monster" };
	stImmuniteEn = { "You have put yourself immunity" };
	stCatchEn = { "Successful cath" };
	stNonCatchEn = { "Miss catch" };

	stFuiteok = "Vous avez reussi a fuire";
	stFuiteR = "Echec de la fuite";

	stFuiteokEn = "You managed to flee";
	stFuiteREn = "Flee failed";

	stElevation = "J'aimerais elever le niveau de la zone";
	stElevationEn = "I would like to raise the level of the area";

	initMonstreSafari();
}

void Safarie::initMonstreSafari() {

	ttGobelin.loadFromFile("..\\Ressources\\Textures\\MONSTRES\\GobelinSp1.png");
	spGobelin.setTexture(ttGobelin);
	rectGobelin = { 0, 0, 40,55 };
	rectCGobelin = { 40, 0, 50,55 };
	spGobelin.setTextureRect(rectGobelin);
	ttOrc.loadFromFile("..\\Ressources\\Textures\\MONSTRES\\OrcSp1.png");
	spOrc.setTexture(ttOrc);
	rectOrc = { 0, 0, 50,100 };
	rectCOrc = { 50, 0, 50,100 };
	spOrc.setTextureRect(rectOrc);
	ttOurs.loadFromFile("..\\Ressources\\Textures\\MONSTRES\\OursSp1.png");
	spOurs.setTexture(ttOurs);
	rectOurs = { 0, 0, 40,50 };
	rectCOurs = { 40, 0, 40,50 };
	spOurs.setTextureRect(rectOurs);
	ttLoup.loadFromFile("..\\Ressources\\Textures\\MONSTRES\\LoupSp1.png");
	spLoup.setTexture(ttLoup);
	rectLoup = { 0, 0, 50,40 };
	rectCLoup = { 50, 0, 55,40 };
	spLoup.setTextureRect(rectLoup);

	rsLoup.setSize(rsize);
	rsLoup.setFillColor(sf::Color::Cyan);

	rsGobelin.setSize(rsize);
	rsGobelin.setFillColor(sf::Color::Red);

	rsOurs.setSize(rsize);
	rsOurs.setFillColor(sf::Color::Yellow);

	rsOrc.setSize(rsize);
	rsOrc.setFillColor(sf::Color::Green);

	posLoup = { AjustResoX * 243, AjustResoY * 464 };
	posOurs = { AjustResoX * 1487, AjustResoY * 525 };
	posGobelin = { AjustResoX * 737, AjustResoY * 845 };
	posOrc = { AjustResoX * 885, AjustResoY * 157 };

	posCombatSafari = { AjustResoX * 349.0f, AjustResoY * 293.0f };
	posCombatMonstre = { AjustResoX * 1284.0f, AjustResoY * 293.0f };

	monstres.push_back(&Gobelin1);
	monstres.push_back(&Gobelin2);
	monstres.push_back(&Gobelin3);
	monstres.push_back(&Gobelin4);
	monstres.push_back(&Ours1);
	monstres.push_back(&Ours2);
	monstres.push_back(&Ours3);
	monstres.push_back(&Ours4);
	monstres.push_back(&Orc1);
	monstres.push_back(&Orc2);
	monstres.push_back(&Orc3);
	monstres.push_back(&Orc4);
	monstres.push_back(&Loup1);
	monstres.push_back(&Loup2);
	monstres.push_back(&Loup3);
	monstres.push_back(&Loup4);

}

void Safarie::updateSafari(Joueur& _perso1, ModeGame& _mode, Consos& _conso) {
	if (_mode == ModeGame::LIBRE) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add) || bElevation == true)
			bElevation = true;
		if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posRoiGoblein, rsize)) {
			bColRoiMonstre = true;
			stParoleSafarie = ("Roi Gobelin: Bonjour, si tu veux t'entrainer avec\nmes gobelin tu pourras drop du Cuivre");
			stParoleSafarieEn = ("Goblin King: Hello, if you want to train with\nmy goblins you can drop Copper");
		}
		else if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posRoiOurs, rsize)) {
			bColRoiMonstre = true;
			stParoleSafarie = ("Roi Ours: Bonjour, si tu veux t'entrainer avec\nmes oursons tu pourras drop du Cuire");
			stParoleSafarieEn = ("Bear King: Hello, if you want to train with\nmy cubs you can drop the Cook");
		}
		else if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posRoiLoup, rsize)) {
			bColRoiMonstre = true;
			stParoleSafarie = ("Roi Loup: Bonjour, si tu veux t'entrainer avec\nmes louveteaux tu pourras drop de le Fourrure");
			stParoleSafarieEn = ("Wolf King: Hello, if you want to train with\nmy cubs you can drop the Fur");
		}
		else if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posRoiOrc, rsize)) {
			bColRoiMonstre = true;
			stParoleSafarie = ("Roi Orc: Bonjour, si tu veux t'entrainer avec\nmes petits Orc tu pourras drop du Fer");
			stParoleSafarieEn = ("Orc King: Hello, if you want to train with\nmy little Orc you can drop Iron");
		}
		else if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posRanger, rsize)) {
			bColRoiMonstre = true;
			bColRanger = true;
			stParoleSafarie = ("Entrainez vous sans crainte, je vous soignerais");
			stParoleSafarieEn = ("Train without fear, I will treat you");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				bTimeRanger = true;
				fTmp = 0.0f;
			}

			if (bTimeRanger == true) {
				fTmp += tools::GetTimeDelta();
				if (fTmp < 2.0f)
					stParoleSafarie = ("Je verifie vos accomplissement, veuillez patientez.");
				stParoleSafarieEn = ("I check your achievements, please wait.");
				if (fTmp > 2.0 && fTmp < 4.1f) {
					if (bElevation == false) {
						stParoleSafarie = ("Veuillez vous entrainer, vous ne rempissez pas les conditions !");
						stParoleSafarieEn = ("Please train, you don't repay the conditions !");
						if (fTmp > 4.0f) {
							fTmp = 0.0f;
							bTimeRanger = false;
						}
					}
					if (bElevation == true) {
						stParoleSafarie = ("OK, vous pourrez affronter des monstres plus fort");
						stParoleSafarieEn = ("OK, you'll be able to take on stronger monsters");
						bLvlUp = true;
						if (fTmp > 4.0f) {
							iZonzSafari += 1;
							iNbGob = 0;
							iNbOrc = 0;
							iNbOurs = 0;
							iNbLoup = 0;
							fTmp = 0.0f;
							bTimeRanger = false;
						}
					}
				}
			}
		}
		else {
			bColRanger = false;
			bColRoiMonstre = false;
			bTimeRanger = false;
		}
		if (iNbGob > 0 && iNbOrc > 0 && iNbLoup > 0 && iNbOurs > 0)
			bElevation = true;
		else
			bElevation = false;

		if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posGobelin, sf::Vector2f(spGobelin.getGlobalBounds().width, spGobelin.getGlobalBounds().height)) && irsVieGobelin >= 1) {

			Gobelin1.SetName("Gobelin");
			Gobelin1.SetMonstre(gobelin);
			Gobelin1.ChangeStatNiveau(iZonzSafari, gobelin);
			stNomMonstre = { Gobelin1.GetName() };

			if (_perso1.GetTotVitesse() >= Gobelin1.GetVitesse()) {
				bAtkPerso = true;
				bAtkMonstre = false;
				iChoixCote = 1;
			}
			else {
				bAtkPerso = false;
				bAtkMonstre = true;
				iChoixCote = 2;
			}

			bColGobelin = true;
			posSavePosition = _perso1.GetPos();
			_perso1.persoPosition = posCombatSafari;
			_perso1.directionCombat();
			posSaveMonstre = posGobelin;
			posGobelin = posCombatMonstre;
			_mode = ModeGame::CHASSE;
		}
		if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posOurs, sf::Vector2f(spOurs.getGlobalBounds().width, spOurs.getGlobalBounds().height)) && irsVieOurs >= 1) {

			Ours1.SetName("Ours");
			Ours1.SetMonstre(ours);
			Ours1.ChangeStatNiveau(iZonzSafari, ours);
			stNomMonstre = { Ours1.GetName() };

			if (_perso1.GetTotVitesse() >= Ours1.GetVitesse()) {
				bAtkPerso = true;
				bAtkMonstre = false;
				iChoixCote = 1;
			}
			else {
				bAtkPerso = false;
				bAtkMonstre = true;
				iChoixCote = 2;
			}

			bColOurs = true;
			posSavePosition = _perso1.GetPos();
			_perso1.persoPosition = posCombatSafari;
			_perso1.directionCombat();
			posSaveMonstre = posOurs;
			posOurs = posCombatMonstre;
			_mode = ModeGame::CHASSE;
		}
		if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posLoup, sf::Vector2f(spLoup.getGlobalBounds().width, spLoup.getGlobalBounds().height)) && irsVieLoup >= 1) {

			Loup1.SetName("Loup");
			Loup1.SetMonstre(loup);
			Loup1.ChangeStatNiveau(iZonzSafari, loup);
			stNomMonstre = { Loup1.GetName() };

			if (_perso1.GetTotVitesse() >= Loup1.GetVitesse()) {
				bAtkPerso = true;
				bAtkMonstre = false;
				iChoixCote = 1;
			}
			else {
				bAtkPerso = false;
				bAtkMonstre = true;
				iChoixCote = 2;
			}

			bColLoup = true;
			posSavePosition = _perso1.GetPos();
			_perso1.persoPosition = posCombatSafari;
			_perso1.directionCombat();
			posSaveMonstre = posLoup;
			posLoup = posCombatMonstre;
			_mode = ModeGame::CHASSE;
		}
		if (tools::CircleRect_Collision(_perso1.persoPosition, 10, posOrc, sf::Vector2f(spOrc.getGlobalBounds().width, spOrc.getGlobalBounds().height)) && irsVieOrc >= 1) {

			Orc1.SetName("Orc");
			Orc1.SetMonstre(orc);
			Orc1.ChangeStatNiveau(iZonzSafari, orc);
			stNomMonstre = { Orc1.GetName() };

			if (_perso1.GetTotVitesse() >= Orc1.GetVitesse()) {
				bAtkPerso = true;
				bAtkMonstre = false;
				iChoixCote = 1;
			}
			else {
				bAtkPerso = false;
				bAtkMonstre = true;
				iChoixCote = 2;
			}

			bColOrc = true;
			posSavePosition = _perso1.GetPos();
			_perso1.persoPosition = posCombatSafari;
			_perso1.directionCombat();
			posSaveMonstre = posOrc;
			posOrc = posCombatMonstre;
			_mode = ModeGame::CHASSE;
		}

		rsLoup.setPosition(posLoup);
		rsGobelin.setPosition(posGobelin);
		rsOurs.setPosition(posOurs);
		rsOrc.setPosition(posOrc);
		if (_perso1.bLeveluUp == true) {
			_perso1.fTimerLevelUp += tools::GetTimeDelta();
			if (_perso1.fTimerLevelUp > 1.5f) {
				_perso1.fTimerLevelUp = 0.0f;
				_perso1.bLeveluUp = false;
			}
			tools::ChoixLangue(tools::GetTrad(), txLevelUp, "Vous avez progresse au niveau " + std::to_string(_perso1.GetNiveau()), "You have progressed at the level " + std::to_string(_perso1.GetNiveau()));
		}
	}
	if (_mode == ModeGame::CHASSE) {

		if (bColGobelin == true) {
			combatSafari(_perso1, Gobelin1, _conso, _mode);
		}
		if (bColOurs == true) {
			combatSafari(_perso1, Ours1, _conso, _mode);
		}
		if (bColLoup == true) {
			combatSafari(_perso1, Loup1, _conso, _mode);
		}
		if (bColOrc == true) {
			combatSafari(_perso1, Orc1, _conso, _mode);
		}
	}

	if (irsVieGobelin <= 0) {
		timerrsGob += tools::GetTimeDelta();
		if (timerrsGob >= 10.0f) {
			irsVieGobelin = 1;
		}
	}
	else
		timerrsGob = 0.0f;

	if (irsVieLoup <= 0) {
		timerrsLoup += tools::GetTimeDelta();
		if (timerrsLoup >= 10.0f) {
			irsVieLoup = 1;
		}
	}
	else
		timerrsLoup = 0.0f;

	if (irsVieOurs <= 0) {
		timerrsOurs += tools::GetTimeDelta();
		if (timerrsOurs >= 10.0f) {
			irsVieOurs = 1;
		}
	}
	else
		timerrsOurs = 0.0f;

	if (irsVieOrc <= 0) {
		timerrsOrc += tools::GetTimeDelta();
		if (timerrsOrc >= 10.0f) {
			irsVieOrc = 1;
		}
	}
	else
		timerrsOrc = 0.0f;

	/*TimerRespawn(timerrsLoup, irsVieLoup);
	TimerRespawn(timerrsOurs, irsVieOurs);
	TimerRespawn(timerrsGob, irsVieGobelin);
	TimerRespawn(timerrsOrc, irsVieOrc);*/
}

void Safarie::ChoixObjetAventure(Joueur& _perso1, Monstre& _monstre1, Consos& _conso) {

	int tmpint;
	timerChoixActionO += tools::GetTimeDelta();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && choixActionO > 1 && timerChoixActionO > 0.3f) {
		choixActionO -= 1;
		timerChoixActionO = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && choixActionO < 5 && timerChoixActionO > 0.3f) {
		choixActionO += 1;
		timerChoixActionO = 0.0f;
	}
	switch (choixActionO)
	{
	case 1:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Vous allez soigner vos PV", "You will heal your PV");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionO > 0.3f) {
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
			timerChoixActionO = 0.0f;
		}
		break;
	case 2:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Vous allez soigner votre Mana", "You will heal your Mana");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionO > 0.3f) {
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
			timerChoixActionO = 0.0f;
		}
		break;
	case 3:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Vous allez faire des degats au monstre", "You will do damage to the monster");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionO > 0.3f) {
			if (_perso1.BombeBuy >= 1) {
				degatFinal = (1000 - _monstre1.GetDefense());
				if (degatFinal <= 0)
					degatFinal = 0;
				PvRestant = _monstre1.GetPV() - degatFinal;
				if (PvRestant <= 0)
					PvRestant = 0;
				_monstre1.SetPV(PvRestant);
				stNomMonstre = { _monstre1.GetName() };
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
			timerChoixActionO = 0.0f;
		}
		break;
	case 4:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Permet de Capturer un monstre", "Allows you to catch a monster");
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionO > 0.3f) || bTmp == true) {
			bTmp = true;
			if (_perso1.GetFillet() >= 1) {
				if (_perso1.GetSuperFillet() >= 1) {
					tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Vous avez un super filet, A pour superFilet, ou E Filet", "You have a super net, A for superNet, or E Net");
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
						timerDescritionCombat = 0.0f;
						std::cout << "Reussi" << std::endl;
						_perso1.SetSuperFillet(_perso1.GetSuperFillet() - 1);
						_monstre1.SetPV(0);
						iDescCombat = 11;
						bDescCombat = true;
						bCatch = true;
						bTmp = false;
						_choixAttaque = 0;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
						if (tools::iRand(0, 3) >= 2) {
							timerDescritionCombat = 0.0f;
							std::cout << "Reussi" << std::endl;
							_perso1.SetFillet(_perso1.GetFillet() - 1);
							_monstre1.SetPV(0);
							iDescCombat = 11;
							bDescCombat = true;
							bCatch = true;
							bTmp = false;
							_choixAttaque = 0;
						}
						else {
							timerDescritionCombat = 0.0f;
							std::cout << "Echec" << std::endl;
							_perso1.SetFillet(_perso1.GetFillet() - 1);
							iDescCombat = 12;
							bDescCombat = true;
							bAtkPerso = false;
							bAtkMonstre = true;
							bTmp = false;
							_choixAttaque = 0;
						}
					}
				}
				else {
					if (tools::iRand(0, 3) >= 2) {
						timerDescritionCombat = 0.0f;
						std::cout << "Reussi" << std::endl;
						_perso1.SetFillet(_perso1.GetFillet() - 1);
						_monstre1.SetPV(0);
						iDescCombat = 11;
						bDescCombat = true;
						bCatch = true;
						bTmp = false;
						_choixAttaque = 0;
					}
					else {
						timerDescritionCombat = 0.0f;
						std::cout << "Echec" << std::endl;
						_perso1.SetFillet(_perso1.GetFillet() - 1);
						iDescCombat = 12;
						bDescCombat = true;
						bAtkPerso = false;
						bAtkMonstre = true;
						bTmp = false;
						_choixAttaque = 0;
					}
				}
			}
			else {
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Vous n'avez pas de Filet", "You don't have a Net");
				bChoixObjet = false;
				bDescCombat = true;
				iDescCombat = 3;
			}
			timerChoixActionO = 0.0f;
			break;
	case 5:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Retour au choix d'attaque", "Back to attack choice");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionO > 0.3f) {
			bChoixObjet = false;
			timerChoixActionO = 0.0f;
		}
		break;
	default:
		break;
		}

	}
}

void Safarie::combatSafari(Joueur& _perso1, Monstre& _monstre1, Consos& _conso, ModeGame& _mode) {
	bIsSkill = true;
	if (bDescCombat == false && bChoixObjet == false && bChoixSkill == false) {
		txDescCombat.setString("");
		bCombatMonstre = false;
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
				ChoixActionSafarie();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionS > 0.3f) {
					bChoixAction = false;
					timerChoixActionS = 0.0f;
					switch (choixActionS)
					{
					case 1:
						if (_perso1.iBoostAtk > 0) {
							degatFinal = (((_perso1.GetTotAttaque() * 1.5) - _monstre1.GetDefense()) * _perso1.ChoixElement(_perso1.GetElement(), _monstre1.GetElement()));
						}
						else {
							degatFinal = ((_perso1.GetTotAttaque() - _monstre1.GetDefense()) * _perso1.ChoixElement(_perso1.GetElement(), _monstre1.GetElement()));
						}
						if (degatFinal <= 0)
							degatFinal = 0;
						PvRestant = _monstre1.GetPV() - degatFinal;
						if (PvRestant <= 0)
							PvRestant = 0;
						_monstre1.SetPV(PvRestant);
						stNomMonstre = { _monstre1.GetName() };
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
			if (bAtkMonstre == true && bDescCombat == false && _monstre1.GetPV() > 0) {
				if (_perso1.iPoison > 0) {
					int tmp, tmp2;
					tmp = _perso1.GetTotAttaque() * 0.1;
					tmp2 = _monstre1.GettotPV() - tmp;
					if (tmp2 < 0)
						tmp2 = 0;
					_monstre1.SetPV(tmp2);
					_perso1.iPoison -= 1;
				}
				bCombatMonstre = true;
				if (_perso1.iBoostDef > 0) {
					degatFinal = ((_monstre1.GetAttaque() - (_perso1.GetTotDefense() * 1.5) * _perso1.ChoixElement(_perso1.GetElement(), _monstre1.GetElement())));
				}
				else {
					degatFinal = ((_monstre1.GetAttaque() - _perso1.GetTotDefense() * _perso1.ChoixElement(_perso1.GetElement(), _monstre1.GetElement())));
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
			if (bAtkMonstre == true && bDescCombat == false && _monstre1.GetPV() > 0) {
				if (_perso1.iPoison > 0) {
					int tmp, tmp2;
					tmp = _perso1.GetTotAttaque() * 0.5;
					tmp2 = _monstre1.GettotPV() - tmp;
					if (tmp2 < 0)
						tmp2 = 0;
					_monstre1.SetPV(tmp2);
					_perso1.iPoison -= 1;
				}
				bCombatMonstre = true;
				if (_perso1.iBoostDef > 0) {
					degatFinal = ((_monstre1.GetAttaque() - (_perso1.GetTotDefense() * 1.5) * _perso1.ChoixElement(_perso1.GetElement(), _monstre1.GetElement())));
				}
				else {
					degatFinal = ((_monstre1.GetAttaque() - _perso1.GetTotDefense() * _perso1.ChoixElement(_perso1.GetElement(), _monstre1.GetElement())));
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
				ChoixActionSafarie();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixActionS > 0.3f) {
					bChoixAction = false;
					timerChoixActionS = 0.0f;
					switch (choixActionS)
					{
					case 1:
						if (_perso1.iBoostAtk > 0) {
							degatFinal = (((_perso1.GetTotAttaque() * 1.5) - _monstre1.GetDefense()) * _perso1.ChoixElement(_perso1.GetElement(), _monstre1.GetElement()));
						}
						else {
							degatFinal = ((_perso1.GetTotAttaque() - _monstre1.GetDefense()) * _perso1.ChoixElement(_perso1.GetElement(), _monstre1.GetElement()));
						}
						if (degatFinal <= 0)
							degatFinal = 0;
						PvRestant = _monstre1.GetPV() - degatFinal;
						if (PvRestant <= 0)
							PvRestant = 0;
						_monstre1.SetPV(PvRestant);
						stNomMonstre = { _monstre1.GetName() };
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
		if (_monstre1.GetPV() <= 0 || _perso1.GetTotPv() <= 0)
		{
			bCombatMonstre = false;
			if (_monstre1.GetPV() <= 0) {
				int tmp_loot;
				if (bColGobelin == true && bLoot == false) {
					tmp_loot = _perso1.GetLootCuivre() + 1;
					_perso1.SetLootCuivre(tmp_loot);
					_perso1.SetTotPv(_perso1.GetTotPvMax());
					_perso1.Experience((15 * _monstre1.GetNiveau()));
					stLoot = { "\nVous avez obtenu : 1 Cuivre" };
					stLootEn = { "\nYou get : 1 Copper" };
					_perso1.NbMonstreBattu += 1;
					_perso1.NbGob += 1;
					iNbGob += 1;
					bLoot = true;
				}
				if (bColLoup == true && bLoot == false) {
					tmp_loot = _perso1.GetLootFourrure() + 1;
					_perso1.SetLootFourrure(tmp_loot);
					_perso1.SetTotPv(_perso1.GetTotPvMax());
					_perso1.Experience((20 * _monstre1.GetNiveau()));
					stLoot = { "\nVous avez obtenu : 1 Fourrure" };
					stLootEn = { "\nYou get : 1 Fur" };
					_perso1.NbMonstreBattu += 1;
					_perso1.NbLoup += 1;
					iNbLoup += 1;
					bLoot = true;
				}
				if (bColOurs == true && bLoot == false) {
					tmp_loot = _perso1.GetLootCuire() + 1;
					_perso1.SetLootCuire(tmp_loot);
					_perso1.SetTotPv(_perso1.GetTotPvMax());
					_perso1.NbMonstreBattu += 1;
					_perso1.NbOurs += 1;
					iNbOurs += 1;
					_perso1.Experience((30 * _monstre1.GetNiveau()));
					stLoot = { "\nVous avez obtenu : 1 Cuir" };
					stLootEn = { "\nYou get : 1 Leather" };
					bLoot = true;
				}
				if (bColOrc == true && bLoot == false) {
					tmp_loot = _perso1.GetLootFer() + 1;
					_perso1.SetLootFer(tmp_loot);
					_perso1.SetTotPv(_perso1.GetTotPvMax());
					_perso1.NbMonstreBattu += 1;
					_perso1.NbOrc += 1;
					iNbOrc += 1;
					_perso1.Experience((30 * _monstre1.GetNiveau()));
					stLoot = { "\nVous avez obtenu : 1 Fer" };
					stLootEn = { "\nYou get : 1 Iron" };
					bLoot = true;
				}
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


			if (bColGobelin == true && bDescCombat == false) {
				posGobelin = posSaveMonstre;
				_perso1.persoPosition.x = posSavePosition.x;
				_perso1.persoPosition.y = posSavePosition.y + 20;
				bColGobelin = false;
				irsVieGobelin = 0;
				bVictory = false;
				bDefaite = false;
				_mode = ModeGame::LIBRE;
				bLoot = false;
			}
			if (bColLoup == true && bDescCombat == false) {
				posLoup = posSaveMonstre;
				_perso1.persoPosition.x = posSavePosition.x;
				_perso1.persoPosition.y = posSavePosition.y + 20;
				bColLoup = false;
				irsVieLoup = 0;
				bVictory = false;
				bDefaite = false;
				_mode = ModeGame::LIBRE;
				bLoot = false;
			}
			if (bColOurs == true && bDescCombat == false) {
				posOurs = posSaveMonstre;
				_perso1.persoPosition.x = posSavePosition.x;
				_perso1.persoPosition.y = posSavePosition.y + 20;
				bColOurs = false;
				irsVieOurs = 0;
				bVictory = false;
				bDefaite = false;
				_mode = ModeGame::LIBRE;
				bLoot = false;
			}
			if (bColOrc == true && bDescCombat == false) {
				posOrc = posSaveMonstre;
				_perso1.persoPosition.x = posSavePosition.x;
				_perso1.persoPosition.y = posSavePosition.y + 20;
				bColOrc = false;
				irsVieOrc = 0;
				bVictory = false;
				bDefaite = false;
				_mode = ModeGame::LIBRE;
				bLoot = false;
			}
			_choixAttaque = 0;
			_perso1.iPoison = 0;
			_perso1.iImmunite = 0;
			_perso1.iBoostAtk = 0;
			_perso1.iBoostDef = 0;
		}
	}
	if (bChoixObjet == true && bDescCombat == false) {
		ChoixObjetAventure(_perso1, _monstre1, _conso);
	}
	if (bChoixSkill == true && bDescCombat == false) {
		ChoixActionSkill(_perso1, _monstre1, _conso);
	}
	/*if (bFuite == true) {
		DetailActionAventureS.setString(stFuiteok);

	}*/
	if (bDescCombat == true) {
		timerDescritionCombat += tools::GetTimeDelta();
		if (timerDescritionCombat > 2.0f && bDescCombat == true) {
			iDescCombat = 0;
			bVictory = false;
			bDefaite = false;
			bDescCombat = false;
			if (bFuite == true) {
				Fuite(_perso1, _monstre1, _mode);
				bFuite = false;
			}
			if (bCatch == true) {
				Catch(_perso1, _monstre1, _mode);
				bCatch = false;
			}
			bFuite = false;
		}
	}
	if (bCombatMonstre == true) {
		spGobelin.setTextureRect(rectCGobelin);
		spOrc.setTextureRect(rectCOrc);
		spOurs.setTextureRect(rectCOurs);
		spLoup.setTextureRect(rectCLoup);
	}
	else {
		spGobelin.setTextureRect(rectGobelin);
		spOrc.setTextureRect(rectOrc);
		spOurs.setTextureRect(rectOurs);
		spLoup.setTextureRect(rectLoup);
	}

}

void Safarie::drawSafari(myWindow& _window, ModeGame& _mode, Joueur& _perso1) {
	if (_mode == ModeGame::LIBRE) {
		/*_window.Draw(rsRoiGobelin);
		_window.Draw(rsRoiLoup);
		_window.Draw(rsRoiOrc);
		_window.Draw(rsRoiOurs);
		_window.Draw(rsRanger);*/
		if (irsVieGobelin >= 1) {
			//_window.Draw(rsGobelin);
			spGobelin.setPosition(posGobelin);
			_window.Draw(spGobelin);
		}
		if (irsVieLoup >= 1) {
			//_window.draw(rsLoup);
			spLoup.setPosition(posLoup);
			_window.Draw(spLoup);
		}
		if (irsVieOrc >= 1) {
			//_window.draw(rsOrc);
			spOrc.setPosition(posOrc);
			_window.Draw(spOrc);
		}
		if (irsVieOurs >= 1) {
			//_window.draw(rsOurs);
			spOurs.setPosition(posOurs);
			_window.Draw(spOurs);
		}

		_perso1.displayPerso(_window, _mode);
		if (bColRoiMonstre == true) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			txParoleSafarie.setPosition(posText);
			tools::ChoixLangue(tools::GetTrad(), txParoleSafarie, stParoleSafarie, stParoleSafarieEn);
			_window.Draw(txParoleSafarie);
			if (bColRanger == true) {
				tools::ChoixLangue(tools::GetTrad(), txElevation, stElevation, stElevationEn);
				_window.Draw(txElevation);
			}
		}
		if (_perso1.bLeveluUp == true) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			txLevelUp.setPosition(posText);
			_window.Draw(txLevelUp);
		}
	}
	if (_mode == ModeGame::CHASSE) {
		_perso1.displayPerso(_window, _mode);
		_perso1.AfficheStats(_window, txStatsPerso);
		if (bColGobelin == true) {
			Gobelin1.AfficheStatsM(_window, txStatsMonstre);
			//_window.draw(rsGobelin);
			spGobelin.setPosition(posGobelin);
			_window.Draw(spGobelin);
		}
		if (bColOurs == true) {
			Ours1.AfficheStatsM(_window, txStatsMonstre);
			//_window.draw(rsOurs);
			spOurs.setPosition(posOurs);
			_window.Draw(spOurs);
		}
		if (bColLoup == true) {
			Loup1.AfficheStatsM(_window, txStatsMonstre);
			//_window.draw(rsLoup);
			spLoup.setPosition(posLoup);
			_window.Draw(spLoup);
		}
		if (bColOrc == true) {
			Orc1.AfficheStatsM(_window, txStatsMonstre);
			//_window.draw(rsOrc);
			spOrc.setPosition(posOrc);
			_window.Draw(spOrc);
		}
		if (bChoixAction == true && bDescCombat == false && bChoixObjet == false && bChoixSkill == false) {

			switch (choixActionS)
			{
			case 1:
				AventureAttaqueS.setScale(1.2, 1.2);
				AventureSkillS.setScale(1, 1);
				AventureObjetS.setScale(1, 1);
				AventureFuiteS.setScale(1, 1);
				break;
			case 2:
				AventureAttaqueS.setScale(1, 1);
				AventureSkillS.setScale(1.2, 1.2);
				AventureObjetS.setScale(1, 1);
				AventureFuiteS.setScale(1, 1);
				break;
			case 3:
				AventureAttaqueS.setScale(1, 1);
				AventureSkillS.setScale(1, 1);
				AventureObjetS.setScale(1.2, 1.2);
				AventureFuiteS.setScale(1, 1);
				break;
			case 4:
				AventureAttaqueS.setScale(1, 1);
				AventureSkillS.setScale(1, 1);
				AventureObjetS.setScale(1, 1);
				AventureFuiteS.setScale(1.2, 1.2);
				break;
			default:
				break;
			}
			_window.Draw(ActionAventureS);
			_window.Draw(DetailActionAventureS);
			_window.Draw(AventureAttaqueS);
			_window.Draw(AventureSkillS);
			_window.Draw(AventureFuiteS);
			_window.Draw(AventureObjetS);
		}
		if (bChoixObjet == true && bDescCombat == false) {
			switch (choixActionO)
			{
			case 1:
				txSoinPV.setScale(1.2, 1.2);
				txSoinMana.setScale(1, 1);
				txBombe.setScale(1, 1);
				txFilet.setScale(1, 1);
				txRetourAction.setScale(1, 1);
				break;
			case 2:
				txSoinPV.setScale(1, 1);
				txSoinMana.setScale(1.2, 1.2);
				txBombe.setScale(1, 1);
				txFilet.setScale(1, 1);
				txRetourAction.setScale(1, 1);
				break;
			case 3:
				txSoinPV.setScale(1, 1);
				txSoinMana.setScale(1, 1);
				txBombe.setScale(1.2, 1.2);
				txFilet.setScale(1, 1);
				txRetourAction.setScale(1, 1);
				break;
			case 4:
				txSoinPV.setScale(1, 1);
				txSoinMana.setScale(1, 1);
				txBombe.setScale(1, 1);
				txFilet.setScale(1.2, 1.2);
				txRetourAction.setScale(1, 1);
				break;
			case 5:
				txSoinPV.setScale(1, 1);
				txSoinMana.setScale(1, 1);
				txBombe.setScale(1, 1);
				txFilet.setScale(1, 1);
				txRetourAction.setScale(1.2, 1.2);
				break;
			default:
				break;
			}
			_window.Draw(ActionAventureS);
			_window.Draw(DetailActionAventureS);
			_window.Draw(txSoinPV);
			_window.Draw(txSoinMana);
			_window.Draw(txBombe);
			_window.Draw(txFilet);
			_window.Draw(txRetourAction);
		}
		if (bChoixSkill == true && bDescCombat == false) {
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
			_window.Draw(ActionAventureS);
			_window.Draw(DetailActionAventureS);
			_window.Draw(txSkill1);
			_window.Draw(txSkill2);
			_window.Draw(txSkill3);
			_window.Draw(txSkill4);
			_window.Draw(txRetourAction);
		}
	}
	if (bDescCombat == true) {
		if (iDescCombat == 1) {
			if (bVictory == false) {
				tools::ChoixLangue(tools::GetTrad(), txDescCombat, stDescCombatP + stNomMonstre + stNbDegP + std::to_string((int)degatFinal), stDescCombatPEn + stNomMonstre + stNbDegPEn + std::to_string((int)degatFinal));
				_window.Draw(txDescCombat);
			}
			else {
				tools::ChoixLangue(tools::GetTrad(), txDescCombat, stDescCombatP + stNomMonstre + stNbDegP + std::to_string((int)degatFinal) + stVictory + stLoot, stDescCombatPEn + stNomMonstre + stNbDegPEn + std::to_string((int)degatFinal) + stVictoryEn + stLootEn);
				_window.Draw(txDescCombat);
			}
		}
		if (iDescCombat == 2) {
			tools::ChoixLangue(tools::GetTrad(), txDescCombat, stNomMonstre + stDescCombatM + stNbDegM + std::to_string((int)degatFinal), stNomMonstre + stDescCombatMEn + stNbDegMEn + std::to_string((int)degatFinal));
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
		if (iDescCombat == 11) {
			tools::ChoixLangue(tools::GetTrad(), txDescCombat, stCatch, stCatchEn);
			_window.Draw(txDescCombat);
		}
		if (iDescCombat == 12) {
			tools::ChoixLangue(tools::GetTrad(), txDescCombat, stNonCatch, stNonCatchEn);
			_window.Draw(txDescCombat);
		}
	}
}

void Safarie::TimerRespawn(float timer, int Vie) {
	if (Vie <= 0) {
		timer += tools::GetTimeDelta();
		if (timer >= 5.0f) {
			Vie = 1;
		}
	}
	else
		timer = 0.0f;
}

void Safarie::ChoixActionSafarie() {
	bChoixAction = true;
	timerChoixActionS += tools::GetTimeDelta();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && choixActionS > 1 && timerChoixActionS > 0.3f) {
		choixActionS -= 1;
		timerChoixActionS = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && choixActionS < 4 && timerChoixActionS > 0.3f) {
		choixActionS += 1;
		timerChoixActionS = 0.0f;
	}
	switch (choixActionS)
	{
	case 1:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Attaque : l'attaque de base prend en compte l'attaque du lanceur\n et la defense de la cible puis applique l'avantage selon l'element", "Attack: The basic attack takes into account the attack of the launchern\nand the defense of the target and then applies the advantage according to the element");
		break;
	case 2:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Skill : Permet d'utiliser une competence possede", "Skill: Allows you to use a possesssede skill");
		break;
	case 3:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Objet : Permet d'utilise un objet equipe", "Subject: Allows you to use a team object");
		break;
	case 4:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Fuite : Permet de fuir un combat, si votre vitesse est superieur a celle\n de l'adversaire fuite a 100%, sinon selon une probabilite", "Escape: Allows you to flee a fight, if your speed is higher than that\nof the opponent flight has 100%, otherwise according to a probability");
		break;
	default:
		break;
	}
}

void Safarie::ChoixActionSkill(Joueur& _perso1, Monstre& _monstre1, Consos& _conso) {
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
			tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Skill 1 : Attaque avec le double de degats", "Skill 1: Attack with double the damage");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
				degatFinal = (((_perso1.GetTotAttaque() - _monstre1.GetDefense()) * _perso1.ChoixElement(_perso1.GetElement(), _monstre1.GetElement())) * 2);
				if (degatFinal <= 0)
					degatFinal = 0;
				PvRestant = _monstre1.GetPV() - degatFinal;
				if (PvRestant <= 0)
					PvRestant = 0;
				_monstre1.SetPV(PvRestant);
				stNomMonstre = { _monstre1.GetName() };
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
			tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Vous ne posseder pas de skill 1", "You don't have skill 1");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
				bChoixSkill = false;
				timerChoixSkill = 0.0f;
			}
		}
		break;
	case 2:
		if (_perso1.SKILL[1] == true || _perso1.SKILL[2] == true) {
			if (_perso1.SKILL[1] == true) {
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Skill 2 : Attaque en ignorant les elements", "Skill 2: Attack by ignoring the elements");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
					degatFinal = (_perso1.GetTotAttaque() - _monstre1.GetDefense());
					if (degatFinal <= 0)
						degatFinal = 0;
					PvRestant = _monstre1.GetPV() - degatFinal;
					if (PvRestant <= 0)
						PvRestant = 0;
					_monstre1.SetPV(PvRestant);
					stNomMonstre = { _monstre1.GetName() };
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
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Skill 2 : Attaque en ignorant la defense", "Skill 2: Attack by ignoring defense");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
					degatFinal = (_perso1.GetTotAttaque() * _perso1.ChoixElement(_perso1.GetElement(), _monstre1.GetElement()));
					if (degatFinal <= 0)
						degatFinal = 0;
					PvRestant = _monstre1.GetPV() - degatFinal;
					if (PvRestant <= 0)
						PvRestant = 0;
					_monstre1.SetPV(PvRestant);
					stNomMonstre = { _monstre1.GetName() };
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
			tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Vous ne posseder pas de skill 2", "You don't have skill 2");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
				bChoixSkill = false;
				timerChoixSkill = 0.0f;
			}
		}
		break;
	case 3:
		if (_perso1.SKILL[3] == true || _perso1.SKILL[4] == true || _perso1.SKILL[5] == true || _perso1.SKILL[6] == true) {
			if (_perso1.SKILL[3] == true) {
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Skill 3 : Boost des degats pour 2 tour (50%)", "Skill 3: Damage boost for 2 turns (50%)");
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
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Skill 3 : Boost de la resistance aux degats pour 2 tour (50%)", "Skill 3: Damage resistance boost for 2 turns (50%)");
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
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Skill 3 : Inflige poison pendant 2 tour(50% de l'attaque)", "Skill 3: Inflicts poison for 2 turns(50% of the attack)");
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
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Skill 3 : S'octroie une immunite a tous degats (2 tour)", "Skill 3: Grants yourself an immunity to all damages (2 round)");
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
			tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Vous ne posseder pas de skill 3", "You don't have a skill 3");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
				bChoixSkill = false;
				timerChoixSkill = 0.0f;
			}
		}
		break;
	case 4:
		if (_perso1.SKILL[7] == true || _perso1.SKILL[8] == true) {
			if (_perso1.SKILL[7] == true) {
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Skill 4 : Invoque une creature !! A venir Prochainement !!", "Skill 4: Summon a creature!! Coming soon !!");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
					bChoixSkill = false;
					timerChoixSkill = 0.0f;
				}
			}
			if (_perso1.SKILL[8] == true) {
				tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Skill 4 : Invoque un villagois kidnapper !! A venir Prochainement !!", "Skill 4: Summon a villagois kidnap!! Coming soon !!");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
					bChoixSkill = false;
					timerChoixSkill = 0.0f;
				}
			}
		}
		else {
			tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Vous ne posseder pas de skill 4", "You don't have skill 4");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
				bChoixSkill = false;
				timerChoixSkill = 0.0f;
			}
		}
		break;
	case 5:
		tools::ChoixLangue(tools::GetTrad(), DetailActionAventureS, "Retour au choix d'attaque", "Back to attack choice");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerChoixSkill > 0.3f) {
			bChoixSkill = false;
			timerChoixSkill = 0.0f;
		}
		break;
	default:
		break;
	}

}

void Safarie::ChoixCote() {

}

void Safarie::Fuite(Joueur& _perso1, Monstre& _monstre1, ModeGame& _mode) {

	if (bColGobelin == true) {
		posGobelin = posSaveMonstre;
		_perso1.SetTotPv(_perso1.GetTotPvMax());
		_perso1.persoPosition = sf::Vector2f(AjustResoX * 810, AjustResoY * 507);
		bColGobelin = false;
		_mode = ModeGame::LIBRE;
	}
	if (bColLoup == true) {
		posLoup = posSaveMonstre;
		_perso1.SetTotPv(_perso1.GetTotPvMax());
		_perso1.persoPosition = sf::Vector2f(AjustResoX * 810, AjustResoY * 507);
		bColLoup = false;
		_mode = ModeGame::LIBRE;
	}
	if (bColOurs == true) {
		posOurs = posSaveMonstre;
		_perso1.SetTotPv(_perso1.GetTotPvMax());
		_perso1.persoPosition = sf::Vector2f(AjustResoX * 810, AjustResoY * 507);
		bColOurs = false;
		_mode = ModeGame::LIBRE;
	}
	if (bColOrc == true) {
		posOrc = posSaveMonstre;
		_perso1.SetTotPv(_perso1.GetTotPvMax());
		_perso1.persoPosition = sf::Vector2f(AjustResoX * 810, AjustResoY * 507);
		bColOrc = false;
		_mode = ModeGame::LIBRE;
	}
}

void Safarie::Catch(Joueur& _perso1, Monstre& _monstre1, ModeGame& _mode) {

	if (bColGobelin == true) {
		posGobelin = posSaveMonstre;
		_perso1.SetTotPv(_perso1.GetTotPvMax());
		_perso1.persoPosition.x = posSavePosition.x;
		_perso1.persoPosition.y = posSavePosition.y - 50;
		_perso1.iCatchGob += 1;
		irsVieGobelin = 0;
		bColGobelin = false;
		_mode = ModeGame::LIBRE;
	}
	if (bColLoup == true) {
		posLoup = posSaveMonstre;
		_perso1.SetTotPv(_perso1.GetTotPvMax());
		_perso1.persoPosition.x = posSavePosition.x + 50;
		_perso1.persoPosition.y = posSavePosition.y;
		_perso1.iCatchLoup += 1;
		irsVieLoup = 0;
		bColLoup = false;
		_mode = ModeGame::LIBRE;
	}
	if (bColOurs == true) {
		posOurs = posSaveMonstre;
		_perso1.SetTotPv(_perso1.GetTotPvMax());
		_perso1.persoPosition.x = posSavePosition.x - 50;
		_perso1.persoPosition.y = posSavePosition.y;
		_perso1.iCatchOurs += 1;
		irsVieOurs = 0;
		bColOurs = false;
		_mode = ModeGame::LIBRE;
	}
	if (bColOrc == true) {
		posOrc = posSaveMonstre;
		_perso1.SetTotPv(_perso1.GetTotPvMax());
		_perso1.persoPosition.x = posSavePosition.x;
		_perso1.persoPosition.y = posSavePosition.y + 50;
		_perso1.iCatchOrc += 1;
		irsVieOrc = 0;
		bColOrc = false;
		_mode = ModeGame::LIBRE;
	}
}

void Safarie::Loot(Joueur& _perso1) {

}
