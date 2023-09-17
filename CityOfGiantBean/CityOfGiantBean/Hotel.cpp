#include "Hotel.h"
#include "Joueur.h"
#include "Safarie.h"
#include "Aventure.h"

void Hotel::initSkillTree() {
	posSkill1 = { AjustResoX * 949, AjustResoY * 203 };
	posSkill21 = { AjustResoX * 1203, AjustResoY * 149 };
	posSkill22 = { AjustResoX * 775, AjustResoY * 168 };
	posSkill31 = { AjustResoX * 1278, AjustResoY * 255 };
	posSkill32 = { AjustResoX * 1278, AjustResoY * 330 };
	posSkill33 = { AjustResoX * 725, AjustResoY * 274 };
	posSkill34 = { AjustResoX * 725, AjustResoY * 358 };
	posSkill41 = { AjustResoX * 1487, AjustResoY * 197 };
	posSkill42 = { AjustResoX * 448, AjustResoY * 204 };

	csSkill1.setRadius(AjustReso * 30);
	csSkill1.setPosition(posSkill1);
	csSkill21.setRadius(AjustReso * 30);
	csSkill21.setPosition(posSkill21);
	csSkill22.setRadius(AjustReso * 30);
	csSkill22.setPosition(posSkill22);
	csSkill31.setRadius(AjustReso * 30);
	csSkill31.setPosition(posSkill31);
	csSkill32.setRadius(AjustReso * 30);
	csSkill32.setPosition(posSkill32);
	csSkill33.setRadius(AjustReso * 30);
	csSkill33.setPosition(posSkill33);
	csSkill34.setRadius(AjustReso * 30);
	csSkill34.setPosition(posSkill34);
	csSkill41.setRadius(AjustReso * 30);
	csSkill41.setPosition(posSkill41);
	csSkill42.setRadius(AjustReso * 30);
	csSkill42.setPosition(posSkill42);

	txDescSkillTree.setFillColor(sf::Color::Black);
	txDescSkillTree.setPosition(AjustResoX * 200, AjustResoY * 800);
	txDescSkillTree.setFont(fontS);

	stDebutDecr = { "Skill point obtenu : " };
	stDecrValid = { "\nVoulez vous choisir ce skill ?\n" };
	stPasPoint = { "Vous n'avez pas assez de point" };
	stPasNiveau = { "Vous n'avez pas le niveau necessaire" };
	stInfoValid = { "\n" };

	stDebutDecrEn = { "Skill point get : " };
	stDecrValidEn = { "\nDo you want to choose this skill?\n" };
	stPasPointEn = { "You don't have enough points" };
	stPasNiveauEn = { "You do not have the necessary level" };
	stInfoValidEn = { "\n" };
}

void Hotel::initQuete() {
	rsOnglet.setSize(sf::Vector2f(AjustResoX * 245, AjustResoY * 50));
	rsOnglet.setFillColor(sf::Color(255, 255, 255, 50));

	rsDepQuete.setSize(sf::Vector2f(AjustResoX * 150, AjustResoY * 50));
	rsDepQuete.setFillColor(sf::Color(255, 255, 255, 50));

	txDescQuete.setFillColor(sf::Color::Black);
	txDescQuete.setPosition(AjustResoX * 200, AjustResoY * 800);
	txDescQuete.setFont(fontS);

	txInfoQuete.setFillColor(sf::Color::Black);
	txInfoQuete.setPosition(AjustResoX * 200, AjustResoY * 850);
	txInfoQuete.setFont(fontS);

	txQFontaine.setPosition(AjustResoX * 250, AjustResoY * 200);
	txQFontaine.setFont(fontS);
	tools::ChoixLangue(tools::GetTrad(), txQFontaine, "Fontaine", "Fountain");

	txQTaverne.setPosition(AjustResoX * 250, AjustResoY * 250);
	txQTaverne.setFont(fontS);
	tools::ChoixLangue(tools::GetTrad(), txQTaverne, "Taverne", "Tavern");

	txQShop.setPosition(AjustResoX * 250, AjustResoY * 300);
	txQShop.setFont(fontS);
	tools::ChoixLangue(tools::GetTrad(), txQShop, "Shop", "Shop");

	txQForge.setPosition(AjustResoX * 250, AjustResoY * 350);
	txQForge.setFont(fontS);
	tools::ChoixLangue(tools::GetTrad(), txQForge, "Forge", "Forge");

	txQChasseur.setPosition(AjustResoX * 250, AjustResoY * 200);
	txQChasseur.setFont(fontS);
	tools::ChoixLangue(tools::GetTrad(), txQChasseur, "Chasseur", "Hunter");

	txQPasDeQuartier.setPosition(AjustResoX * 250, AjustResoY * 250);
	txQPasDeQuartier.setFont(fontS);
	tools::ChoixLangue(tools::GetTrad(), txQPasDeQuartier, "Pas de Quartier", "No Neighborhood");

	txQCapture.setPosition(AjustResoX * 250, AjustResoY * 300);
	txQCapture.setFont(fontS);
	tools::ChoixLangue(tools::GetTrad(), txQCapture, "Capture", "Catch");

	txQElevation.setPosition(AjustResoX * 250, AjustResoY * 350);
	txQElevation.setFont(fontS);
	tools::ChoixLangue(tools::GetTrad(), txQElevation, "Elevation", "Elevation");

	txQElimination.setPosition(AjustResoX * 250, AjustResoY * 200);
	txQElimination.setFont(fontS);
	txQElimination.setString("Elimination");
	tools::ChoixLangue(tools::GetTrad(), txQElimination, "Elimination", "Elimination");

	txQDetrousseur.setPosition(AjustResoX * 250, AjustResoY * 250);
	txQDetrousseur.setFont(fontS);
	tools::ChoixLangue(tools::GetTrad(), txQDetrousseur, "Detrousseur", "Spoiler");

	txQBoss.setPosition(AjustResoX * 250, AjustResoY * 300);
	txQBoss.setFont(fontS);
	tools::ChoixLangue(tools::GetTrad(), txQBoss, "Boss", "Boss");

	txQEtage.setPosition(AjustResoX * 250, AjustResoY * 350);
	txQEtage.setFont(fontS);
	tools::ChoixLangue(tools::GetTrad(), txQEtage, "Etage", "Floor");

	txQRetour.setPosition(AjustResoX * 250, AjustResoY * 400);
	txQRetour.setFont(fontS);
	tools::ChoixLangue(tools::GetTrad(), txQRetour, "Retour", "Back");

	txQQuit.setPosition(AjustResoX * 200, AjustResoY * 850);
	txQQuit.setFont(fontS);
	tools::ChoixLangue(tools::GetTrad(), txQQuit, "Echap pour quitter", "Escape to leave");

	if (save::getTutoNb() == 2)
		save::setTutoNb(3);
}

void Hotel::initHotel() {
	fontS.loadFromFile("../Ressources/Fonts/YOZAKURA-Regular.otf");

	posrsPNJquete = { AjustResoX * 323, AjustResoY * 270 };
	rsPNJquete.setSize(sf::Vector2f(AjustResoX * 58, AjustResoY * 49));
	rsPNJquete.setPosition(posrsPNJquete);
	rsPNJquete.setFillColor(sf::Color::Cyan);

	posrsPNJskill = { AjustResoX * 1406, AjustResoY * 269 };
	rsPNJskill.setSize(sf::Vector2f(AjustResoX * 81, AjustResoY * 44));
	rsPNJskill.setPosition(posrsPNJskill);
	rsPNJskill.setFillColor(sf::Color::Cyan);

	posrsPNJversus = { AjustResoX * 598, AjustResoY * 747 };
	rsPNJversus.setSize(sf::Vector2f(AjustResoX * 155, AjustResoY * 128));
	rsPNJversus.setPosition(posrsPNJversus);
	rsPNJversus.setFillColor(sf::Color::Cyan);

	posrsPNJ1 = { AjustResoX * 820, AjustResoY * 411 };
	rsPNJ1.setSize(sf::Vector2f(AjustResoX * 55, AjustResoY * 62));
	rsPNJ1.setPosition(posrsPNJ1);
	rsPNJ1.setFillColor(sf::Color::Cyan);

	posrsPNJ2 = { AjustResoX * 1066, AjustResoY * 398 };
	rsPNJ2.setSize(sf::Vector2f(AjustResoX * 51, AjustResoY * 80));
	rsPNJ2.setPosition(posrsPNJ2);
	rsPNJ2.setFillColor(sf::Color::Cyan);

	posrsPNJ3 = { AjustResoX * 917, AjustResoY * 362 };
	rsPNJ3.setSize(sf::Vector2f(AjustResoX * 86, AjustResoY * 45));
	rsPNJ3.setPosition(posrsPNJ3);
	rsPNJ3.setFillColor(sf::Color::Cyan);

	posText = { AjustResoX * 150, AjustResoY * 850 };
	txBasePNJ.setFont(fontS);
	txBasePNJ.setFillColor(sf::Color::Black);

	txReponseBase.setFont(fontS);
	txReponseBase.setOrigin(txReponseBase.getGlobalBounds().height / 2, txReponseBase.getGlobalBounds().width / 2);
	txReponseBase.setPosition(AjustResoX * 150, AjustResoY * 900);
	txReponseBase.setFillColor(sf::Color::Red);

	txLevelUpH.setFont(fontS);
	txLevelUpH.setOrigin(txLevelUpH.getGlobalBounds().height / 2, txLevelUpH.getGlobalBounds().width / 2);
	txLevelUpH.setPosition(posText);
	txLevelUpH.setFillColor(sf::Color::Black);

	txReponse1.setFont(fontS);
	txReponse1.setOrigin(txReponse1.getGlobalBounds().height / 2, txReponse1.getGlobalBounds().width / 2);
	txReponse1.setPosition(AjustResoX * 150, AjustResoY * 950);
	txReponse1.setFillColor(sf::Color::Red);

	txReponse2.setFont(fontS);
	txReponse2.setOrigin(txReponse2.getGlobalBounds().height / 2, txReponse2.getGlobalBounds().width / 2);
	txReponse2.setPosition(AjustResoX * 150, AjustResoY * 1050);
	txReponse2.setFillColor(sf::Color::Red);

	txReponse3.setFont(fontS);
	txReponse3.setOrigin(txReponse3.getGlobalBounds().height / 2, txReponse3.getGlobalBounds().width / 2);
	txReponse3.setPosition(AjustResoX * 150, AjustResoY * 1100);
	txReponse3.setFillColor(sf::Color::Red);

	initQuete();
	initSkillTree();
	boiteDiscussion::initBoiteDiscussion();

}

void Hotel::update(Joueur& _perso1, ModeGame& _modeGame, Safarie& safarie, Aventure& aventure) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) {
		_perso1.Experience(50);
		_perso1.SetSkillPoint(10);
	}
	timerState += tools::GetTimeDelta();
	if (_modeGame == ModeGame::LIBRE) {
		if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posrsPNJquete, sf::Vector2f(rsPNJquete.getGlobalBounds().width, rsPNJquete.getGlobalBounds().height)) && (save::getTutoNb() == 2 || save::getTuto() == false)) {
			bPNJBase = true;
			stBasePNJ = ("Bonjour, bienvenu au bureau des quetes.");
			stBasePNJEn = ("Hello, welcome to the quest office.");
			stReponseBase = ("(Espace) Bonjour, montrez moi ce que vous avez.");
			stReponseBaseEn = ("(Space) Hello, show me what you have.");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				_modeGame = ModeGame::QUETE;
			}
		}
		else if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posrsPNJskill, sf::Vector2f(rsPNJskill.getGlobalBounds().width, rsPNJskill.getGlobalBounds().height)) && (save::getTutoNb() == 6 || save::getTuto() == false)) {
			bPNJBase = true;
			stBasePNJ = ("Bonjour, je suis le maitre des competences, puis-je vous aider ?\n\n\nR : reset des skill (les skillpoint utiliser seront perdu) ");
			stBasePNJEn = ("Hello, I am the master of skills, can I help you ?\n\n\nR : Skill reset (SkillPoint use will be lost) ");
			stReponseBase = ("(Espace) Bonjour, que pouvez vous m'enseigner ?");
			stReponseBaseEn = ("(Space) Hello, what can you teach me ?");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				_modeGame = ModeGame::SKILL_TREE;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && timerState > 0.3f ) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					ResetSkill(_perso1);
					timerState = 0.0f;
				}
			}
		}
		else if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posrsPNJversus, sf::Vector2f(rsPNJversus.getGlobalBounds().width, rsPNJversus.getGlobalBounds().height)) && (save::getTutoNb() >= 11 || save::getTuto() == false)) {
			bPNJBase = true;
			stBasePNJ = ("''Ca chauffe, on ferait mieux de ne pas intervenir''");
			stBasePNJEn = ("''It's heating up, we'd better not intervene''");
			stReponseBase = ("");
			stReponseBaseEn = ("");
		}
		else if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posrsPNJ1, sf::Vector2f(rsPNJ1.getGlobalBounds().width, rsPNJ1.getGlobalBounds().height)) && (save::getTutoNb() >= 11 || save::getTuto() == false)) {
			bPNJBase = true;
			stBasePNJ = ("Hey !");
			stBasePNJEn = ("Hey !");
			stReponseBase = ("1: Ho ?");
			stReponseBaseEn = ("1: Ho ?");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1) || bPNJ1 == true) {
				bPNJ1 = true;
				ChoixActionPNJ1();
			}
		}
		else if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posrsPNJ2, sf::Vector2f(rsPNJ2.getGlobalBounds().width, rsPNJ2.getGlobalBounds().height)) && (save::getTutoNb() >= 11 || save::getTuto() == false)) {
			bPNJBase = true;
			stBasePNJ = ("Yo !");
			stBasePNJEn = ("Yo !");
			stReponseBase = ("1: Salut");
			stReponseBaseEn = ("1: Hi");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1) || bPNJ2 == true) {
				bPNJ2 = true;
				ChoixActionPNJ1();
			}
		}
		else if (tools::CircleRect_Collision(_perso1.persoPosition, 20, posrsPNJ3, sf::Vector2f(rsPNJ3.getGlobalBounds().width, rsPNJ3.getGlobalBounds().height)) && (save::getTutoNb() >= 11 || save::getTuto() == false)) {
			bPNJBase = true;
			stBasePNJ = ("...");
			stBasePNJEn = ("...");
			stReponseBase = ("1: Heu .. Bonjour ?");
			stReponseBaseEn = ("1: Heu .. Hello ?");
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1) || bPNJ3 == true) {
				bPNJ3 = true;
				ChoixActionPNJ1();
			}
		}
		else {
			bPNJBase = false;
			bChoixAction = false;
			bChoixAction2 = false;
			bChoixAction3 = false;
			bPNJBase = false;
			choixActionH = 0;
			choixActionH2 = 0;
			choixActionH3 = 0;
		}
		if (_perso1.bLeveluUp == true) {
			_perso1.fTimerLevelUp += tools::GetTimeDelta();
			if (_perso1.fTimerLevelUp > 1.5f) {
				_perso1.fTimerLevelUp = 0.0f;
				_perso1.bLeveluUp = false;
			}
			tools::ChoixLangue(tools::GetTrad(), txLevelUpH, "Vous avez progresse au niveau " + std::to_string(_perso1.GetNiveau()), "You have progressed at the level " + std::to_string(_perso1.GetNiveau()));
		}
	}
	if (_modeGame == ModeGame::SKILL_TREE) {
		timerSkill += tools::GetTimeDelta();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && iSkill124 > 1 && timerSkill > 0.3f && iSkill3 == 0) {
			iSkill124 -= 1;
			timerSkill = 0.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && iSkill124 < 5 && timerSkill > 0.3f && iSkill3 == 0) {
			iSkill124 += 1;
			timerSkill = 0.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && iSkill3 > 0 && timerSkill > 0.3f && (iSkill124 == 2 || iSkill124 == 4)) {
			iSkill3 -= 1;
			timerSkill = 0.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && iSkill3 < 2 && timerSkill > 0.3f && (iSkill124 == 2 || iSkill124 == 4)) {
			iSkill3 += 1;
			timerSkill = 0.0f;
		}

		switch (_perso1.GetNiveau())
		{
		case 0:
			_perso1.Branche1 = false;
			_perso1.Branche2 = false;
			_perso1.Branche3 = false;
			_perso1.Branche4 = false;
			break;
		case 1:
			_perso1.Branche1 = false;
			_perso1.Branche2 = false;
			_perso1.Branche3 = false;
			_perso1.Branche4 = false;
			break;
		case 2:
			_perso1.Branche1 = true;
			_perso1.Branche2 = false;
			_perso1.Branche3 = false;
			_perso1.Branche4 = false;
			break;
		case 3:
			_perso1.Branche1 = true;
			_perso1.Branche2 = true;
			_perso1.Branche3 = false;
			_perso1.Branche4 = false;
			break;
		case 4:
			_perso1.Branche1 = true;
			_perso1.Branche2 = true;
			_perso1.Branche3 = true;
			_perso1.Branche4 = false;
			break;
		case 5:
			_perso1.Branche1 = true;
			_perso1.Branche2 = true;
			_perso1.Branche3 = true;
			_perso1.Branche4 = true;
			break;
		default:
			_perso1.Branche1 = true;
			_perso1.Branche2 = true;
			_perso1.Branche3 = true;
			_perso1.Branche4 = true;
			break;
		}
#pragma region skillColor
		if (iSkill124 == 3) {
			csSkill1.setScale(1.2, 1.2);
			if (_perso1.SKILL[0] == true)
				csSkill1.setFillColor(sf::Color::Green);
			else
				csSkill1.setFillColor(sf::Color::Blue);
		}
		else {
			csSkill1.setScale(1, 1);
			csSkill1.setFillColor(sf::Color::White);
		}

		if (iSkill124 == 4 && iSkill3 == 0) {
			csSkill21.setScale(1.2, 1.2);
			if (_perso1.SKILL[1] == true)
				csSkill21.setFillColor(sf::Color::Green);
			else if (_perso1.SKILL[2] == true)
				csSkill21.setFillColor(sf::Color::Red);
			else
				csSkill21.setFillColor(sf::Color::Blue);
		}
		else {
			csSkill21.setScale(1, 1);
			csSkill21.setFillColor(sf::Color::White);
		}
		if (iSkill124 == 2 && iSkill3 == 0) {
			csSkill22.setScale(1.2, 1.2);
			if (_perso1.SKILL[2] == true)
				csSkill22.setFillColor(sf::Color::Green);
			else if (_perso1.SKILL[1] == true)
				csSkill22.setFillColor(sf::Color::Red);
			else
				csSkill22.setFillColor(sf::Color::Blue);
		}
		else {
			csSkill22.setScale(1, 1);
			csSkill22.setFillColor(sf::Color::White);
		}
		if (iSkill124 == 4 && iSkill3 == 1) {
			csSkill31.setScale(1.2, 1.2);
			if (_perso1.SKILL[3] == true)
				csSkill31.setFillColor(sf::Color::Green);
			else if (_perso1.SKILL[2] == true)
				csSkill31.setFillColor(sf::Color::Red);
			else if (_perso1.SKILL[4] == true)
				csSkill31.setFillColor(sf::Color::Red);
			else
				csSkill31.setFillColor(sf::Color::Blue);
		}
		else {
			csSkill31.setScale(1, 1);
			if (_perso1.SKILL[3] == false)
				csSkill31.setFillColor(sf::Color::White);
			else if (_perso1.SKILL[4] == true)
				csSkill31.setFillColor(sf::Color::Red);
		}
		if (iSkill124 == 4 && iSkill3 == 2) {
			csSkill32.setScale(1.2, 1.2);
			if (_perso1.SKILL[4] == true)
				csSkill32.setFillColor(sf::Color::Green);
			else if (_perso1.SKILL[2] == true)
				csSkill32.setFillColor(sf::Color::Red);
			else if (_perso1.SKILL[3] == true)
				csSkill32.setFillColor(sf::Color::Red);
			else
				csSkill32.setFillColor(sf::Color::Blue);
		}
		else {
			csSkill32.setScale(1, 1);
			if (_perso1.SKILL[3] == false)
				csSkill32.setFillColor(sf::Color::White);
			else if (_perso1.SKILL[3] == true)
				csSkill32.setFillColor(sf::Color::Red);
		}
		if (iSkill124 == 2 && iSkill3 == 1) {
			csSkill33.setScale(1.2, 1.2);
			if (_perso1.SKILL[5] == true)
				csSkill33.setFillColor(sf::Color::Green);
			else if (_perso1.SKILL[1] == true)
				csSkill33.setFillColor(sf::Color::Red);
			else if (_perso1.SKILL[5] == true)
				csSkill33.setFillColor(sf::Color::Red);
			else
				csSkill33.setFillColor(sf::Color::Blue);
		}
		else {
			csSkill33.setScale(1, 1);
			if (_perso1.SKILL[3] == false)
				csSkill33.setFillColor(sf::Color::White);
			else if (_perso1.SKILL[5] == true)
				csSkill33.setFillColor(sf::Color::Red);
		}
		if (iSkill124 == 2 && iSkill3 == 2) {
			csSkill34.setScale(1.2, 1.2);
			if (_perso1.SKILL[6] == true)
				csSkill34.setFillColor(sf::Color::Green);
			else if (_perso1.SKILL[1] == true)
				csSkill34.setFillColor(sf::Color::Red);
			else if (_perso1.SKILL[4] == true)
				csSkill34.setFillColor(sf::Color::Red);
			else
				csSkill34.setFillColor(sf::Color::Blue);
		}
		else {
			csSkill34.setScale(1, 1);
			if (_perso1.SKILL[3] == false)
				csSkill34.setFillColor(sf::Color::White);
			else if (_perso1.SKILL[4] == true)
				csSkill34.setFillColor(sf::Color::Red);
		}
		if (iSkill124 == 5) {
			csSkill41.setScale(1.2, 1.2);
			if (_perso1.SKILL[7] == true)
				csSkill41.setFillColor(sf::Color::Green);
			else if (_perso1.SKILL[2] == true)
				csSkill41.setFillColor(sf::Color::Red);
			else
				csSkill41.setFillColor(sf::Color::Blue);
		}
		else {
			csSkill41.setScale(1, 1);
			csSkill41.setFillColor(sf::Color::White);
		}
		if (iSkill124 == 1) {
			csSkill42.setScale(1.2, 1.2);
			if (_perso1.SKILL[8] == true)
				csSkill42.setFillColor(sf::Color::Green);
			else if (_perso1.SKILL[1] == true)
				csSkill42.setFillColor(sf::Color::Red);
			else
				csSkill42.setFillColor(sf::Color::Blue);
		}
		else {
			csSkill42.setScale(1, 1);
			csSkill42.setFillColor(sf::Color::White);
		}

		if (_perso1.SKILL[0] == true) {
			csSkill1.setFillColor(sf::Color::Green);
		}
		if (_perso1.SKILL[1] == true) {
			csSkill21.setFillColor(sf::Color::Green);
			csSkill22.setFillColor(sf::Color::Red);
			csSkill33.setFillColor(sf::Color::Red);
			csSkill34.setFillColor(sf::Color::Red);
			csSkill42.setFillColor(sf::Color::Red);
		}
		if (_perso1.SKILL[2] == true) {
			csSkill21.setFillColor(sf::Color::Red);
			csSkill22.setFillColor(sf::Color::Green);
			csSkill31.setFillColor(sf::Color::Red);
			csSkill32.setFillColor(sf::Color::Red);
			csSkill41.setFillColor(sf::Color::Red);
		}
		if (_perso1.SKILL[3] == true) {
			csSkill31.setFillColor(sf::Color::Green);
		}
		if (_perso1.SKILL[4] == true) {
			csSkill32.setFillColor(sf::Color::Green);
		}
		if (_perso1.SKILL[5] == true) {
			csSkill33.setFillColor(sf::Color::Green);
		}
		if (_perso1.SKILL[6] == true) {
			csSkill34.setFillColor(sf::Color::Green);
		}
		if (_perso1.SKILL[7] == true) {
			csSkill41.setFillColor(sf::Color::Green);
		}
		if (_perso1.SKILL[8] == true) {
			csSkill42.setFillColor(sf::Color::Green);
		}
#pragma endregion skillColor

		switch (iSkill124)
		{
		case 1:
			stDescSkillTree = { "skill 42: Invocation de monstre" };
			stDescSkillTreeEn = { "skill 42: Summon monster" };
			stInfoValid = { "\n" };
			stInfoValidEn = { "\n" };
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerSkill > 0.3f) {
				if (_perso1.SKILL[8] == false) {
					if (_perso1.Branche4 == true) {
						if (_perso1.GetSkillPoint() >= 1) {
							if (_perso1.SKILL[1] == false) {
								if (_perso1.SKILL[5] == true || _perso1.SKILL[6] == true) {
									stInfoValid = { "" };
									stInfoValidEn = { "" };
									_perso1.SetSkillPoint(_perso1.GetSkillPoint() - 1);
									_perso1.SKILL[8] = true;
									save::setSkill4(2);
								}
								else {
									stInfoValid = { "\nVous n'avez pas le skill precedent" };
									stInfoValidEn = { "\nYou don't have the previous skill" };
								}
							}
							else {
								stInfoValid = { "\nVous n'avez pas pris la branche correspondante" };
								stInfoValidEn = { "\nYou have not taken the corresponding branch" };
							}
						}
						else {
							stInfoValid = { "\nVous n'avez pas assez de point" };
							stInfoValidEn = { "\nYou don't have enough points" };
						}
					}
					else {
						stInfoValid = { "\nVous n'avez pas le niveau necessaire" };
						stInfoValidEn = { "\nYou do not have the necessary level" };
					}
				}
				else {
					stInfoValid = { "\nVous posseder deja ce skill" };
					stInfoValidEn = { "\nYou already have this skill" };
				}
			}
			break;
		case 2:
			stDescSkillTree = { "skill 22 : Attaque ignorant la defense" };
			stDescSkillTreeEn = { "skill 22 : Attack ignoring defense" };
			stInfoValid = { "\n" };
			stInfoValidEn = { "\n" };
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerSkill > 0.3f) {
				if (_perso1.SKILL[2] == false) {
					if (_perso1.Branche2 == true) {
						if (_perso1.GetSkillPoint() >= 1) {
							if (_perso1.SKILL[1] == false) {
								if (_perso1.SKILL[0] == true) {
									_perso1.SetSkillPoint(_perso1.GetSkillPoint() - 1);
									_perso1.SKILL[2] = true;
									save::setSkill2(2);
								}
								else {
									stInfoValid = { "\nVous n'avez pas le skill precedent" };
									stInfoValidEn = { "\nYou don't have the previous skill" };
								}
							}
							else {
								stInfoValid = { "\nVous avez deja un skill de ce niveau" };
								stInfoValidEn = { "\nYou already have a skill of this level" };
							}
						}
						else {
							stInfoValid = { "\nVous n'avez pas assez de point" };
							stInfoValidEn = { "\nYou don't have enough points" };
						}
					}
					else {
						stInfoValid = { "\nVous n'avez pas le niveau necessaire" };
						stInfoValidEn = { "\nYou do not have the necessary level" };
					}
				}
				else {
					stInfoValid = { "\nVous posseder deja ce skill" };
					stInfoValidEn = { "\nYou already have this skill" };
				}
			}
			break;
		case 3:
			stDescSkillTree = { "skill 1: Attaque puissante (degats x2)" };
			stDescSkillTreeEn = { "skill 1:  Powerful attack (dammage x2)" };
			stInfoValid = { "\n" };
			stInfoValidEn = { "\n" };
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerSkill > 0.3f) {
				if (_perso1.SKILL[0] == false) {
					if (_perso1.Branche1 == true) {
						if (_perso1.GetSkillPoint() >= 1) {
							stInfoValid = { "" };
							stInfoValidEn = { "" };
							_perso1.SetSkillPoint(_perso1.GetSkillPoint() - 1);
							if (save::getTutoNb() == 6)
								save::setTutoNb(7);
							save::setSkill1(1);
							_perso1.SKILL[0] = true;
						}
						else {
							stInfoValid = { "\nVous n'avez pas assez de point" };
							stInfoValidEn = { "\nYou don't have enough points" };
						}
					}
					else {
						stInfoValid = { "\nVous n'avez pas le niveau necessaire" };
						stInfoValidEn = { "\nYou do not have the necessary level" };
					}
				}
				else {
					stInfoValid = { "\nVous posseder deja ce skill" };
					stInfoValidEn = { "\nYou already have this skill" };
				}
			}
			break;
		case 4:
			stDescSkillTree = { "skill 21 : Attaque ignorant l'element" };
			stDescSkillTreeEn = { "skill 21 : Attack ignoring the element" };
			stInfoValid = { "\n" };
			stInfoValidEn = { "\n" };
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerSkill > 0.3f) {
				if (_perso1.SKILL[1] == false) {
					if (_perso1.Branche2 == true) {
						if (_perso1.GetSkillPoint() >= 1) {
							stInfoValid = { "" };
							stInfoValidEn = { "" };
							if (_perso1.SKILL[2] == false) {
								if (_perso1.SKILL[0] == true) {
									_perso1.SetSkillPoint(_perso1.GetSkillPoint() - 1);
									_perso1.SKILL[1] = true;
									save::setSkill2(1);
								}
								else {
									stInfoValid = { "\nVous n'avez pas le skill precedent" };
									stInfoValidEn = { "\nYou don't have the previous skill" };
								}
							}
							else {
								stInfoValid = { "\nVous avez deja un skill de ce niveau" };
								stInfoValidEn = { "\nYou already have a skill of this level" };
							}
						}
						else {
							stInfoValid = { "\nVous n'avez pas assez de point" };
							stInfoValidEn = { "\nYou don't have enough points" };
						}
					}
					else {
						stInfoValid = { "\nVous n'avez pas le niveau necessaire" };
						stInfoValidEn = { "\nYou do not have the necessary level" };
					}
				}
				else {
					stInfoValid = { "\nVous posseder deja ce skill" };
					stInfoValidEn = { "\nYou already have this skill" };
				}
			}
			break;
		case 5:
			stDescSkillTree = { "skill 41: invocation de villagois kidnappe" };
			stDescSkillTreeEn = { "skill 41: Summon of Villagois kidnaps" };
			stInfoValid = { "\n" };
			stInfoValidEn = { "\n" };
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerSkill > 0.3f) {
				if (_perso1.SKILL[7] == false) {
					if (_perso1.Branche4 == true) {
						if (_perso1.GetSkillPoint() >= 1) {
							if (_perso1.SKILL[2] == false) {
								if (_perso1.SKILL[3] == true || _perso1.SKILL[4] == true) {
									stInfoValid = { "" };
									stInfoValidEn = { "" };
									_perso1.SetSkillPoint(_perso1.GetSkillPoint() - 1);
									_perso1.SKILL[7] = true;
									save::setSkill4(1);
								}
								else {
									stInfoValid = { "\nVous n'avez pas le skill precedent" };
									stInfoValidEn = { "\nYou don't have the previous skill" };
								}
							}
							else {
								stInfoValid = { "\nVous n'avez pas pris la branche correspondante" };
								stInfoValidEn = { "\nYou have not taken the corresponding branch" };
							}
						}
						else {
							stInfoValid = { "\nVous n'avez pas assez de point" };
							stInfoValidEn = { "\nYou don't have enough points" };
						}
					}
					else {
						stInfoValid = { "\nVous n'avez pas le niveau necessaire" };
						stInfoValidEn = { "\nYou do not have the necessary level" };
					}
				}
				else {
					stInfoValid = { "\nVous posseder deja ce skill" };
					stInfoValidEn = { "\nYou already have this skill" };
				}
			}
			break;
		default:
			break;
		}
		switch (iSkill3)
		{
		case 1:
			if (iSkill124 == 2) {
				stDescSkillTree = { "skill 33: Poison (2 tour)" };
				stDescSkillTreeEn = { "skill 33: Poison (2 laps)" };
				stInfoValid = { "\n" };
				stInfoValidEn = { "\n" };
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerSkill > 0.3f) {
					if (_perso1.SKILL[5] == false) {
						if (_perso1.Branche3 == true) {
							if (_perso1.GetSkillPoint() >= 1) {
								if (_perso1.SKILL[4] == true || _perso1.SKILL[3] == true || _perso1.SKILL[6] == true) {
									stInfoValid = { "\nVous avez deja un skill de ce niveau" };
									stInfoValidEn = { "\nYou already have a skill of this level" };
								}
								else {
									if (_perso1.SKILL[1] == false) {
										if (_perso1.SKILL[2] == true) {
											stInfoValid = { "" };
											stInfoValidEn = { "" };
											_perso1.SetSkillPoint(_perso1.GetSkillPoint() - 1);
											_perso1.SKILL[5] = true;
											save::setSkill3(3);
										}
										else {
											stInfoValid = { "\nVous n'avez pas le skill precedent" };
											stInfoValidEn = { "\nYou don't have the previous skill" };
										}
									}
									else {
										stInfoValid = { "\nVous n'avez pas pris la branche correspondante" };
										stInfoValidEn = { "\nYou have not taken the corresponding branch" };
									}
								}
							}
							else {
								stInfoValid = { "\nVous n'avez pas assez de point" };
								stInfoValidEn = { "\nYou don't have enough points" };
							}
						}
						else {
							stInfoValid = { "\nVous n'avez pas le niveau necessaire" };
							stInfoValidEn = { "\nYou do not have the necessary level" };
						}
					}
					else {
						stInfoValid = { "\nVous posseder deja ce skill" };
						stInfoValidEn = { "\nYou already have this skill" };
					}
				}
			}
			if (iSkill124 == 4) {
				stDescSkillTree = { "skill 31: Boost des degats (2 tour)" };
				stDescSkillTreeEn = { "skill 31: Dammage boosted (2 laps)" };
				stInfoValid = { "\n" };
				stInfoValidEn = { "\n" };
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerSkill > 0.3f) {
					if (_perso1.SKILL[3] == false) {
						if (_perso1.Branche3 == true) {
							if (_perso1.GetSkillPoint() >= 1) {
								if (_perso1.SKILL[4] == true || _perso1.SKILL[5] == true || _perso1.SKILL[6] == true) {
									stInfoValid = { "\nVous avez deja un skill de ce niveau" };
									stInfoValidEn = { "\nYou already have a skill of this level" };
								}
								else {
									if (_perso1.SKILL[2] == false) {
										if (_perso1.SKILL[1] == true) {
											stInfoValid = { "" };
											stInfoValidEn = { "" };
											_perso1.SetSkillPoint(_perso1.GetSkillPoint() - 1);
											_perso1.SKILL[3] = true;
											save::setSkill3(1);
										}
										else {
											stInfoValid = { "\nVous n'avez pas le skill precedent" };
											stInfoValidEn = { "\nYou don't have the previous skill" };
										}
									}
									else {
										stInfoValid = { "\nVous n'avez pas pris la branche correspondante" };
										stInfoValidEn = { "\nYou have not taken the corresponding branch" };
									}
								}
							}
							else {
								stInfoValid = { "\nVous n'avez pas assez de point" };
								stInfoValidEn = { "\nYou don't have enough points" };
							}
						}
						else {
							stInfoValid = { "\nVous n'avez pas le niveau necessaire" };
							stInfoValidEn = { "\nYou do not have the necessary level" };
						}
					}
					else {
						stInfoValid = { "\nVous posseder deja ce skill" };
						stInfoValidEn = { "\nYou already have this skill" };
					}
				}

			}
			break;
		case 2:
			if (iSkill124 == 2) {
				stDescSkillTree = { "skill 34 : immunite (2 tour) " };
				stDescSkillTreeEn = { "skill 34 : immunity (2 laps) " };
				stInfoValid = { "\n" };
				stInfoValidEn = { "\n" };
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerSkill > 0.3f) {
					if (_perso1.SKILL[6] == false) {
						if (_perso1.Branche3 == true) {
							if (_perso1.GetSkillPoint() >= 1) {
								if (_perso1.SKILL[3] == false && _perso1.SKILL[4] == false && _perso1.SKILL[5] == false) {
									if (_perso1.SKILL[1] == false) {
										if (_perso1.SKILL[2] == true) {
											stInfoValid = { "" };
											stInfoValidEn = { "" };
											_perso1.SetSkillPoint(_perso1.GetSkillPoint() - 1);
											_perso1.SKILL[6] = true;
											save::setSkill3(4);
										}
										else {
											stInfoValid = { "\nVous n'avez pas le skill precedent" };
											stInfoValidEn = { "\nYou don't have the previous skill" };
										}
									}
									else {
										stInfoValid = { "\nVous n'avez pas pris la branche correspondante" };
										stInfoValidEn = { "\nYou have not taken the corresponding branch" };
									}
								}
								else {
									stInfoValid = { "\nVous avez deja un skill de ce niveau" };
									stInfoValidEn = { "\nYou already have a skill of this level" };
								}
							}
							else {
								stInfoValid = { "\nVous n'avez pas assez de point" };
								stInfoValidEn = { "\nYou don't have enough points" };
							}
						}
						else {
							stInfoValid = { "\nVous n'avez pas le niveau necessaire" };
							stInfoValidEn = { "\nYou do not have the necessary level" };
						}
					}
					else {
						stInfoValid = { "\nVous posseder deja ce skill" };
						stInfoValidEn = { "\nYou already have this skill" };
					}
				}

			}
			if (iSkill124 == 4) {
				stDescSkillTree = { "skill 32: Boost de la resistance aux degats (2 tour)" };
				stDescSkillTreeEn = { "skill 32: Damage resistance boost (2 laps)" };
				stInfoValid = { "\n" };
				stInfoValidEn = { "\n" };
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerSkill > 0.3f) {
					if (_perso1.SKILL[4] == false) {
						if (_perso1.Branche3 == true) {
							if (_perso1.GetSkillPoint() >= 1) {
								if (_perso1.SKILL[3] == false && _perso1.SKILL[4] == false && _perso1.SKILL[5] == false) {
									if (_perso1.SKILL[2] == false) {
										if (_perso1.SKILL[1] == true) {
											stInfoValid = { "" };
											stInfoValidEn = { "" };
											_perso1.SetSkillPoint(_perso1.GetSkillPoint() - 1);
											_perso1.SKILL[4] = true;
											save::setSkill3(2);
										}
										else {
											stInfoValid = { "\nVous n'avez pas le skill precedent" };
											stInfoValidEn = { "\nYou don't have the previous skill" };
										}
									}
									else {
										stInfoValid = { "\nVous n'avez pas pris la branche correspondante" };
										stInfoValidEn = { "\nYou have not taken the corresponding branch" };
									}
								}
								else {
									stInfoValid = { "\nVous avez deja un skill de ce niveau" };
									stInfoValidEn = { "\nYou already have a skill of this level" };
								}
							}
							else {
								stInfoValid = { "\nVous n'avez pas assez de point" };
								stInfoValidEn = { "\nYou don't have enough points" };
							}
						}
						else {
							stInfoValid = { "\nVous n'avez pas le niveau necessaire" };
							stInfoValidEn = { "\nYou do not have the necessary level" };
						}
					}
					else {
						stInfoValid = { "\nVous posseder deja ce skill" };
						stInfoValidEn = { "\nYou already have this skill" };
					}
				}

			}
			break;
		default:
			break;
		}
	}

	if (_modeGame == ModeGame::QUETE) {
		if (bQLieux == false && bQAventure == false && bQSafari == false) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && iDepOnglet > 0 && timerState > 0.3f) {
				iDepOnglet -= 1;
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && iDepOnglet < 2 && timerState > 0.3f) {
				iDepOnglet += 1;
				timerState = 0.0f;
			}
			switch (iDepOnglet)
			{
			case 0:
				posrsOnglet = sf::Vector2f(AjustResoX * 226, AjustResoY * 102);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
					bQLieux = true;
					timerState = 0.0f;
				}
				break;
			case 1:
				posrsOnglet = sf::Vector2f(AjustResoX * 764, AjustResoY * 107);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
					bQSafari = true;
					timerState = 0.0f;
				}
				break;
			case 2:
				posrsOnglet = sf::Vector2f(AjustResoX * 1405, AjustResoY * 109);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
					bQAventure = true;
					timerState = 0.0f;
				}
				break;
			default:
				break;
			}

			stInfoValid = "";
			stInfoValidEn = "";
			stInfoQuete = "";
			stInfoQueteEn = "";
		}
		if (bQLieux == true) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && iVertiOnglet > 0 && timerState > 0.3f) {
				iVertiOnglet -= 1;
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && iVertiOnglet < 4 && timerState > 0.3f) {
				iVertiOnglet += 1;
				timerState = 0.0f;
			}
			switch (iVertiOnglet)
			{
			case 0:
				stInfoValid = "Changer d'element";
				stInfoValidEn = "Switch element";
				stInfoQuete = "Element changer : " + std::to_string(_perso1.iChgElem);
				stInfoQueteEn = "Element change : " + std::to_string(_perso1.iChgElem);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f && bQL1 == false) {
					if (_perso1.iChgElem >= 1) {
						bQL1 = true;
						_perso1.Experience(50);
						_perso1.AjoutAArgent(500);
					}
				}
				break;
			case 1:
				stInfoValid = "Changer de classe";
				stInfoValidEn = "Switch classe";
				stInfoQuete = "Classe changer : " + std::to_string(_perso1.iChgClasse);
				stInfoQueteEn = "Classe change : " + std::to_string(_perso1.iChgClasse);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f && bQL2 == false) {
					if (_perso1.iChgClasse >= 1) {
						bQL2 = true;
						_perso1.Experience(50);
						_perso1.AjoutAArgent(500);
					}
				}
				break;
			case 2:
				stInfoValid = "Acheter un Objet";
				stInfoValidEn = "Buy a item";
				stInfoQuete = "Objet acheter : " + std::to_string(_perso1.iAchat);
				stInfoQueteEn = "item bought : " + std::to_string(_perso1.iAchat);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f && bQL3 == false) {
					if (_perso1.iAchat >= 1) {
						bQL3 = true;
						_perso1.Experience(50);
						_perso1.AjoutAArgent(500);
					}
				}
				break;
			case 3:
				stInfoValid = "Fabrique un objet";
				stInfoValidEn = "make a item";
				stInfoQuete = "Objet fabrique : " + std::to_string(_perso1.iFabrique);
				stInfoQueteEn = "Item craft : " + std::to_string(_perso1.iFabrique);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f && bQL4 == false) {
					if (_perso1.iFabrique >= 1) {
						bQL4 = true;
						_perso1.Experience(50);
						_perso1.AjoutAArgent(500);
					}
				}
				break;
			case 4:
				stInfoValid = "Retour";
				stInfoValidEn = "Back";
				stInfoQuete = "";
				stInfoQueteEn = "";
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
					bQLieux = false;
					iVertiOnglet = 0;
					timerState = 0.0f;
				}
				break;
			default:
				break;
			}
		}
		if (bQSafari == true) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && iVertiOnglet > 0 && timerState > 0.3f) {
				iVertiOnglet -= 1;
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && iVertiOnglet < 4 && timerState > 0.3f) {
				iVertiOnglet += 1;
				timerState = 0.0f;
			}
			switch (iVertiOnglet)
			{
			case 0:
				stInfoValid = "Battre 5 monstre";
				stInfoValidEn = "Defeat 5 monster";
				stInfoQuete = "Monstre battu : " + std::to_string(_perso1.NbMonstreBattu);
				stInfoQueteEn = "Monster defeated : " + std::to_string(_perso1.NbMonstreBattu);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f && bQS1 == false) {
					if (_perso1.NbMonstreBattu >= 5) {
						bQS1 = true;
						_perso1.Experience(50);
						_perso1.AjoutAArgent(500);
					}
				}
				break;
			case 1:
				stInfoValid = "Battre 1 monstre de chaque type";
				stInfoValidEn = "Defeate 1 monster each type";
				stInfoQuete = "Gobelin battu : " + std::to_string(_perso1.NbGob) + "Orc battu : " + std::to_string(_perso1.NbOrc) + "Loup battu : " + std::to_string(_perso1.NbLoup) + "Ours battu : " + std::to_string(_perso1.NbOurs);
				stInfoQueteEn = "Gobelin defeated : " + std::to_string(_perso1.NbGob) + "Orc defeated : " + std::to_string(_perso1.NbOrc) + "Wolf defeated: " + std::to_string(_perso1.NbLoup) + "Bear defeated: " + std::to_string(_perso1.NbOurs);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f && bQS2 == false) {
					if (_perso1.NbGob >= 1 && _perso1.NbOrc >= 1 && _perso1.NbLoup >= 1 && _perso1.NbOurs >= 1) {
						bQS2 = true;
						_perso1.Experience(50);
						_perso1.AjoutAArgent(500);
					}
				}
				break;
			case 2:
				stInfoValid = "Capturer 1 monstre";
				stInfoValidEn = "Catch 1 monster";
				stInfoQuete = "Monstre capturer : " + std::to_string(_perso1.NbMonstreCapture);
				stInfoQueteEn = "Monster catched : " + std::to_string(_perso1.NbMonstreCapture);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f && bQS3 == false) {
					if (_perso1.NbMonstreCapture >= 1) {
						bQS3 = true;
						_perso1.Experience(50);
						_perso1.AjoutAArgent(500);
					}
				}
				break;
			case 3:
				stInfoValid = "Monter jusqu'a l'elevation 3";
				stInfoValidEn = "Climb to the elevation 3";
				stInfoQuete = "Elevation actuel : " + std::to_string(safarie.iZonzSafari);
				stInfoQueteEn = "Current elevation : " + std::to_string(safarie.iZonzSafari);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f && bQS4 == false) {
					if (safarie.iZonzSafari >= 3) {
						bQS4 = true;
						_perso1.Experience(50);
						_perso1.AjoutAArgent(500);
					}
				}
				break;
			case 4:
				stInfoValid = "Retour";
				stInfoValidEn = "Back";
				stInfoQuete = "";
				stInfoQueteEn = "";
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
					bQSafari = false;
					iVertiOnglet = 0;
					timerState = 0.0f;
				}
				break;
			default:
				break;
			}
		}
		if (bQAventure == true) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && iVertiOnglet > 0 && timerState > 0.3f) {
				iVertiOnglet -= 1;
				timerState = 0.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && iVertiOnglet < 4 && timerState > 0.3f) {
				iVertiOnglet += 1;
				timerState = 0.0f;
			}
			switch (iVertiOnglet)
			{
			case 0:
				stInfoValid = "Vaincre 10 ennemis en aventure";
				stInfoValidEn = "Defeat 10 enemies on an adventure";
				stInfoQuete = "Ennemi battu : " + std::to_string(_perso1.NbEnnemiBattu);
				stInfoQueteEn = "Ennemi defeated : " + std::to_string(_perso1.NbEnnemiBattu);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f && bQA1 == false) {
					if (_perso1.NbEnnemiBattu >= 10) {
						bQA1 = true;
						_perso1.Experience(50);
						_perso1.AjoutAArgent(500);
					}
				}
				break;
			case 1:
				stInfoValid = "Vaincre un ennemi de chaque classe";
				stInfoValidEn = "Defeat a ennemi of each classe";
				stInfoQuete = "Guerrier battu : " + std::to_string(_perso1.NbGuer) + "Assassin battu : " + std::to_string(_perso1.NbAss) + "Clerc battu : " + std::to_string(_perso1.NbClerc) + "Magicien battu : " + std::to_string(_perso1.NbMag);
				stInfoQueteEn = "Warrior defeated : " + std::to_string(_perso1.NbGuer) + "Murderer defeated : " + std::to_string(_perso1.NbAss) + "Cleric defeated : " + std::to_string(_perso1.NbClerc) + "Magician defeated : " + std::to_string(_perso1.NbMag);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f && bQA2 == false) {
					if (_perso1.NbClerc >= 1 && _perso1.NbAss >= 1 && _perso1.NbGuer >= 1 && _perso1.NbMag >= 1) {
						bQA2 = true;
						_perso1.Experience(50);
						_perso1.AjoutAArgent(500);
					}
				}
				break;
			case 2:
				stInfoValid = "Battez un boss d'etage";
				stInfoValidEn = "Defeat a floor boss";
				stInfoQuete = "Boss battu : " + std::to_string(_perso1.iBossAv);
				stInfoQueteEn = "Boss defeated : " + std::to_string(_perso1.iBossAv);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f && bQA3 == false) {
					if (_perso1.iBossAv >= 1) {
						bQA3 = true;
						_perso1.Experience(50);
						_perso1.AjoutAArgent(500);
					}
				}
				break;
			case 3:
				stInfoValid = "Grimper jusqu'a l'etage 10";
				stInfoValidEn = "Climb to floor 10";
				stInfoQuete = "Etage actuel : " + std::to_string(aventure.iZoneAv);
				stInfoQueteEn = "Etage actuel : " + std::to_string(aventure.iZoneAv);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f && bQA4 == false) {
					if (aventure.iZoneAv >= 10) {
						bQA4 = true;
						_perso1.Experience(50);
						_perso1.AjoutAArgent(500);
					}
				}
				break;
			case 4:
				stInfoValid = "Retour";
				stInfoValidEn = "Back";
				stInfoQuete = "";
				stInfoQueteEn = "";
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timerState > 0.3f) {
					bQAventure = false;
					iVertiOnglet = 0;
					timerState = 0.0f;
				}
				break;
			default:
				break;
			}
		}
		if (iVertiOnglet == 0) {
			txQFontaine.setScale(1.2, 1.2);
			txQChasseur.setScale(1.2, 1.2);
			txQElimination.setScale(1.2, 1.2);
		}
		else {
			txQFontaine.setScale(1, 1);
			txQChasseur.setScale(1, 1);
			txQElimination.setScale(1, 1);
		}
		if (iVertiOnglet == 1) {
			txQTaverne.setScale(1.2, 1.2);
			txQPasDeQuartier.setScale(1.2, 1.2);
			txQDetrousseur.setScale(1.2, 1.2);

		}
		else {
			txQTaverne.setScale(1, 1);
			txQPasDeQuartier.setScale(1, 1);
			txQDetrousseur.setScale(1, 1);
		}
		if (iVertiOnglet == 2) {
			txQShop.setScale(1.2, 1.2);
			txQCapture.setScale(1.2, 1.2);
			txQBoss.setScale(1.2, 1.2);
		}
		else {
			txQShop.setScale(1, 1);
			txQCapture.setScale(1, 1);
			txQBoss.setScale(1, 1);
		}
		if (iVertiOnglet == 3) {
			txQForge.setScale(1.2, 1.2);
			txQElevation.setScale(1.2, 1.2);
			txQEtage.setScale(1.2, 1.2);
		}
		else {
			txQForge.setScale(1, 1);
			txQElevation.setScale(1, 1);
			txQEtage.setScale(1, 1);
		}
		if (iVertiOnglet == 4)
			txQRetour.setScale(1.2, 1.2);
		else
			txQRetour.setScale(1, 1);
		rsOnglet.setPosition(posrsOnglet);

		if (bQL1)
			txQFontaine.setFillColor(sf::Color::Green);
		if (bQL2)
			txQTaverne.setFillColor(sf::Color::Green);
		if (bQL3)
			txQShop.setFillColor(sf::Color::Green);
		if (bQL4)
			txQForge.setFillColor(sf::Color::Green);

		if (bQS1)
			txQChasseur.setFillColor(sf::Color::Green);
		if (bQS2)
			txQPasDeQuartier.setFillColor(sf::Color::Green);
		if (bQS3)
			txQCapture.setFillColor(sf::Color::Green);
		if (bQS4)
			txQElevation.setFillColor(sf::Color::Green);

		if (bQA1)
			txQElimination.setFillColor(sf::Color::Green);
		if (bQA2)
			txQDetrousseur.setFillColor(sf::Color::Green);
		if (bQA3)
			txQBoss.setFillColor(sf::Color::Green);
		if (bQA4)
			txQEtage.setFillColor(sf::Color::Green);
	}

}

void Hotel::displayHotel(myWindow& _window, ModeGame& _modeGame, Joueur& _perso1) {

	if (_modeGame == ModeGame::LIBRE) {
		/*_window.Draw(rsPNJquete);
		_window.Draw(rsPNJskill);
		_window.Draw(rsPNJversus);
		_window.Draw(rsPNJ1);
		_window.Draw(rsPNJ2);
		_window.Draw(rsPNJ3);*/
		if (bPNJBase == true /*&& (bPNJquete == false && bPNJskill == false && bPNJversus == false && bPNJ1 == false && bPNJ2 == false && bPNJ3 == false)*/) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			txBasePNJ.setPosition(posText);
			tools::ChoixLangue(tools::GetTrad(), txBasePNJ, stBasePNJ, stBasePNJEn);
			_window.Draw(txBasePNJ);
			tools::ChoixLangue(tools::GetTrad(), txReponseBase, stReponseBase, stReponseBaseEn);
			_window.Draw(txReponseBase);
		}
		if (_perso1.bLeveluUp == true) {
			boiteDiscussion::displayBoiteDiscussion(_window);
			txLevelUpH.setPosition(posText);
			_window.Draw(txLevelUpH);
		}

	}
	if (_modeGame == ModeGame::SKILL_TREE) {
		displaySkillTree(_window, _perso1);
	}
	if (_modeGame == ModeGame::QUETE) {
		displayQuete(_window, _perso1);
	}
}
void Hotel::displaySkillTree(myWindow& _window, Joueur& _perso1) {
	_window.Draw(csSkill1);
	_window.Draw(csSkill21);
	_window.Draw(csSkill22);
	_window.Draw(csSkill31);
	_window.Draw(csSkill32);
	_window.Draw(csSkill33);
	_window.Draw(csSkill34);
	_window.Draw(csSkill41);
	_window.Draw(csSkill42);
	tools::ChoixLangue(tools::GetTrad(), txDescSkillTree, stDebutDecr + std::to_string(_perso1.GetSkillPoint()) + stDecrValid + stDescSkillTree + stInfoValid, stDebutDecrEn + std::to_string(_perso1.GetSkillPoint()) + stDecrValidEn + stDescSkillTreeEn + stInfoValidEn);
	_window.Draw(txDescSkillTree);
}
void Hotel::displayQuete(myWindow& _window, Joueur& _perso1) {
	_window.Draw(rsOnglet);
	_window.Draw(rsDepQuete);
	tools::ChoixLangue(tools::GetTrad(), txDescQuete, stInfoValid, stInfoValidEn);
	tools::ChoixLangue(tools::GetTrad(), txInfoQuete, stInfoQuete, stInfoQueteEn);
	_window.Draw(txDescQuete);
	if (bQLieux == false && bQAventure == false && bQSafari == false)
		_window.Draw(txQQuit);

	if (bQLieux == true) {
		_window.Draw(txQFontaine);
		_window.Draw(txQTaverne);
		_window.Draw(txQShop);
		_window.Draw(txQForge);
		_window.Draw(txQRetour);
		_window.Draw(txInfoQuete);
	}
	if (bQAventure == true) {
		_window.Draw(txQElimination);
		_window.Draw(txQDetrousseur);
		_window.Draw(txQBoss);
		_window.Draw(txQEtage);
		_window.Draw(txQRetour);
		_window.Draw(txInfoQuete);
	}
	if (bQSafari == true) {
		_window.Draw(txQChasseur);
		_window.Draw(txQPasDeQuartier);
		_window.Draw(txQCapture);
		_window.Draw(txQElevation);
		_window.Draw(txQRetour);
		_window.Draw(txInfoQuete);
	}

}

void Hotel::ResetSkill(Joueur& _perso1) {

	_perso1.SKILL[0] = false;
	_perso1.SKILL[1] = false;
	_perso1.SKILL[2] = false;
	_perso1.SKILL[3] = false;
	_perso1.SKILL[4] = false;
	_perso1.SKILL[5] = false;
	_perso1.SKILL[6] = false;
	_perso1.SKILL[7] = false;
	_perso1.SKILL[8] = false;


	save::setSkill1(0);
	save::setSkill2(0);
	save::setSkill3(0);
	save::setSkill4(0);
}

void Hotel::ChoixActionPNJ1() {
	if (bChoixAction2 == false) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) {
			choixActionH = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
			choixActionH = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) {
			choixActionH = 3;
		}
	}
	switch (choixActionH)
	{
	case 1:
		stReponseBase = ("Comment allez-vous?");
		stReponseBaseEn = ("How are you?");
		stBasePNJ = ("Je vais bien, merci");
		stBasePNJEn = ("I'm fine, thank you");

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			bChoixAction2 = true;
			stBasePNJ = "";
			stBasePNJEn = "";
		}
		if (bChoixAction2 == true) {
			stReponseBase = ("Que faites vous aujourd'hui ?");
			stReponseBaseEn = ("What are you doing today ?");

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) {
				choixActionH2 = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
				choixActionH2 = 2;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) {
				choixActionH2 = 3;
			}
			switch (choixActionH2)
			{
			case 1:
				stBasePNJ = ("Je decouvre un nouveau monde");
				stBasePNJEn = ("I discover a new world");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					bChoixAction = false;
					bChoixAction2 = false;
					bChoixAction3 = false;
					bPNJBase = false;
					choixActionH = 0;
					choixActionH2 = 0;
					choixActionH3 = 0;
				}
				break;
			case 2:
				stBasePNJ = ("Je rencontre de nouvelle personne");
				stBasePNJEn = ("I meet a new person");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					bChoixAction = false;
					bChoixAction2 = false;
					bChoixAction3 = false;
					bPNJBase = false;
					choixActionH = 0;
					choixActionH2 = 0;
					choixActionH3 = 0;
				}
				break;
			case 3:
				stBasePNJ = ("Pourquoi tu veux savoir ?");
				stBasePNJEn = ("Why you want to know ?");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					bChoixAction = false;
					bChoixAction2 = false;
					bChoixAction3 = false;
					bPNJBase = false;
					choixActionH = 0;
					choixActionH2 = 0;
					choixActionH3 = 0;
				}
				break;
			default:
				break;
			}
		}
		break;
	case 2:
		stReponseBase = ("Comment allez-vous?");
		stReponseBaseEn = ("How are you?");
		stBasePNJ = ("Non ca va pas.");
		stBasePNJEn = ("No it's not okay.");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			bChoixAction2 = true;
			stBasePNJ = "";
			stBasePNJEn = "";
		}
		if (bChoixAction2 == true) {
			stReponseBase = ("Que c'est t-il passer ?");
			stReponseBaseEn = ("What's to happen ?");

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) {
				choixActionH2 = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
				choixActionH2 = 2;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) {
				choixActionH2 = 3;
			}
			switch (choixActionH2)
			{
			case 1:
				stBasePNJ = ("Je suis malade");
				stBasePNJEn = ("I'm sick");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					bChoixAction = false;
					bChoixAction2 = false;
					bChoixAction3 = false;
					bPNJBase = false;
					choixActionH = 0;
					choixActionH2 = 0;
					choixActionH3 = 0;
				}
				break;
			case 2:
				stBasePNJ = ("Tu me parle !");
				stBasePNJEn = ("You talk to me !");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					bChoixAction = false;
					bChoixAction2 = false;
					bChoixAction3 = false;
					bPNJBase = false;
					choixActionH = 0;
					choixActionH2 = 0;
					choixActionH3 = 0;
				}
				break;
			case 3:
				stBasePNJ = ("Qu'est ce que ca peut faire ?");
				stBasePNJEn = ("What it can do ?");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					bChoixAction = false;
					bChoixAction2 = false;
					bChoixAction3 = false;
					bPNJBase = false;
					choixActionH = 0;
					choixActionH2 = 0;
					choixActionH3 = 0;
				}
				break;
			default:
				break;
			}
		}
		break;
	case 3:
		stBasePNJ = ("Qu'est ce que ca peut faire !");
		stBasePNJEn = ("What it can do !");
		stReponseBase = ("Comment allez-vous?");
		stReponseBaseEn = ("How are you?");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			bChoixAction2 = true;
			stBasePNJ = "";
			stBasePNJEn = "";
		}
		if (bChoixAction2 == true) {
			stReponseBase = ("Mais tu es mechant !?");
			stReponseBaseEn = ("But you're mean !?");

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) {
				choixActionH2 = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
				choixActionH2 = 2;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) {
				choixActionH2 = 3;
			}
			switch (choixActionH2)
			{
			case 1:
				stBasePNJ = ("Oui au revoir");
				stBasePNJEn = ("Yes goodbye");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					bChoixAction = false;
					bChoixAction2 = false;
					bChoixAction3 = false;
					bPNJBase = false;
					choixActionH = 0;
					choixActionH2 = 0;
					choixActionH3 = 0;
				}
				break;
			case 2:
				stBasePNJ = ("Nooon tu crois ?");
				stBasePNJEn = ("Nooo you think ?");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					bChoixAction = false;
					bChoixAction2 = false;
					bChoixAction3 = false;
					bPNJBase = false;
					choixActionH = 0;
					choixActionH2 = 0;
					choixActionH3 = 0;
				}
				break;
			case 3:
				stBasePNJ = ("Mais quel genie !!");
				stBasePNJEn = ("Oh a genius !!");
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					bChoixAction = false;
					bChoixAction2 = false;
					bChoixAction3 = false;
					bPNJBase = false;
					choixActionH = 0;
					choixActionH2 = 0;
					choixActionH3 = 0;
				}
				break;
			default:
				break;
			}
		}
		break;
	default:
		break;
	}
}


void Hotel::ChoixActionPNJQuete() {
	bChoixAction = true;
	timerChoixActionH += tools::GetTimeDelta();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && choixActionH > 1 && timerChoixActionH > 0.3f) {
		choixActionH -= 1;
		timerChoixActionH = 0.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && choixActionH < 3 && timerChoixActionH > 0.3f) {
		choixActionH += 1;
		timerChoixActionH = 0.0f;
	}
	switch (choixActionH)
	{
	case 1:
		tools::ChoixLangue(tools::GetTrad(), txDetailReponse, "Attaque : l'attaque de base prend en compte l'attaque du lanceur\net la defense de la cible puis applique l'avantage selon l'element", "Attack: The basic attack takes into account the attack of the launcher\nand the defense of the target and then applies the advantage according to the element");
		break;
	case 2:
		tools::ChoixLangue(tools::GetTrad(), txDetailReponse, "Skill : Permet d'utiliser une competence possede", "Item: Allows you to use a skill owned");
		break;
	case 3:
		tools::ChoixLangue(tools::GetTrad(), txDetailReponse, "Objet : Permet d'utilise un objet equipe", "Item: Allows you to use a team item");
		break;
	default:
		break;
	}
}

void Hotel::ChoixActionPNJSkill() {
}