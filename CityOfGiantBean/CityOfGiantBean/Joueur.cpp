#include "Joueur.h"


extern int classeDisplay;

bool FirstClasse = true;


sf::Font fontS;
sf::Text ValidationS, SexeM, SexeF, txPseudoIntro, txOui, txNon;
std::string ValidationSexe, stValidationPseudo, stPseudo;

int degatFinal;
int PvRestant;



void Joueur::initPerso() {
	persoMTexture.loadFromFile("..\\Ressources\\Textures\\CLASSE\\PersoMale.png");
	persoFTexture.loadFromFile("..\\Ressources\\Textures\\CLASSE\\PersoFemale.png");
	persoSprite.setScale(3, 3);
	persoRect = { 192,0,16,18 };
	persoPosition = { 100,100 };
	vitessePerso = { 200,200 };
	persoFrameX = 12;
	persoFrameY = 2;
	element = None;
}

float Joueur::ChoixElement(Elements _elementAtk, Elements _elementDef) {
	switch (_elementAtk)
	{
	case Feu:
		switch (_elementDef)
		{
		case Feu:
			return 1.0;
			break;
		case Eau:
			return 0.5;
			break;
		case Terre:
			return 1.0;
			break;
		case Vent:
			return 2.0;
			break;
		case Ombre:
			return 1.0;
			break;
		case Lumiere:
			return 1.0;
			break;
		case None:
			return 1.0;
			break;
		}
		break;
	case Eau:
		switch (_elementDef) {
		case Feu:
			return 2.0;
			break;
		case Eau:
			return 1.0;
			break;
		case Terre:
			return 0.5;
			break;
		case Vent:
			return 1.0;
			break;
		case Ombre:
			return 1.0;
			break;
		case Lumiere:
			return 1.0;
			break;
		case None:
			return 1.0;
			break;
		}
		break;
	case Terre:
		switch (_elementDef) {
		case Feu:
			return 1.0;
			break;
		case Eau:
			return 2.0;
			break;
		case Terre:
			return 1.0;
			break;
		case Vent:
			return 0.5;
			break;
		case Ombre:
			return 1.0;
			break;
		case Lumiere:
			return 1.0;
			break;
		case None:
			return 1.0;
			break;
		}
		break;
	case Vent:
		switch (_elementDef) {
		case Feu:
			return 0.5;
			break;
		case Eau:
			return 1.0;
			break;
		case Terre:
			return 2.0;
			break;
		case Vent:
			return 1.0;
			break;
		case Ombre:
			return 1.0;
			break;
		case Lumiere:
			return 1.0;
			break;
		case None:
			return 1.0;
			break;
		}
		break;
	case Ombre:
		switch (_elementDef) {
		case Feu:
			return 1.0;
			break;
		case Vent:
			return 1.0;
			break;
		case Eau:
			return 1.0;
			break;
		case Terre:
			return 1.0;
			break;
		case Ombre:
			return 1.0;
			break;
		case Lumiere:
			return 2.0;
			break;
		case None:
			return 1.0;
			break;
		}
		break;
	case Lumiere:
		switch (_elementDef) {
		case Feu:
			return 1.0;
			break;
		case Vent:
			return 1.0;
			break;
		case Eau:
			return 1.0;
			break;
		case Terre:
			return 1.0;
			break;
		case Ombre:
			return 2.0;
			break;
		case Lumiere:
			return 1.0;
			break;
		case None:
			return 1.0;
			break;
		}
		break;
	case None:
		switch (_elementDef) {
		case Feu:
			return 1.0;
			break;
		case Vent:
			return 1.0;
			break;
		case Eau:
			return 1.0;
			break;
		case Terre:
			return 1.0;
			break;
		case Ombre:
			return 1.0;
			break;
		case Lumiere:
			return 1.0;
			break;
		case None:
			return 1.0;
			break;
		}
		break;
	}
	//std::cout << degatsElem << std::endl;
}

void Joueur::updatePerso(myWindow& _window, ModeGame _mode) {

	if (save::getSexe() == 1) {
		persoSprite.setTexture(persoMTexture);
	}
	if (save::getSexe() == 2) {
		persoSprite.setTexture(persoFTexture);
	}
	if (_mode == ModeGame::LIBRE) {
		if (boiteDiscussion::getBoolDiscu() == false) {
			sf::FloatRect playerfrect = persoSprite.getGlobalBounds();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
				if (persoPosition.y > 0) {
					persoPosition.y -= vitessePerso.y * tools::GetTimeDelta();
					isMoving = true;
					persoFrameY = 0;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				if (persoPosition.y < AjustResoY * 1080) {
					persoPosition.y += vitessePerso.y * tools::GetTimeDelta();
					isMoving = true;
					persoFrameY = 2;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				if (persoPosition.x < AjustResoX * 1920) {
					persoPosition.x += vitessePerso.x * tools::GetTimeDelta();
					isMoving = true;
					persoFrameY = 1;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
				if (persoPosition.x > 0) {
					persoPosition.x -= vitessePerso.x * tools::GetTimeDelta();
					isMoving = true;
					persoFrameY = 3;
				}
			}
			else
				isMoving = false;

			switch (classeDisplay)
			{
			case 0:
				persoRect = { 192,0,16,18 };
				break;
			case 1:
				persoRect = { 144,0,16,18 };
				break;
			case 2:
				persoRect = { 96,0,16,18 };
				break;
			case 3:
				persoRect = { 0,0,16,18 };
				break;
			case 4:
				persoRect = { 48,0,16,18 };
				break;
			default:
				break;
			}
			if (isMoving) {
				persoFrameX++;
				switch (classeDisplay)
				{
				case 0:
					if (persoFrameX > 14) persoFrameX = 12;
					break;
				case 1:
					if (persoFrameX > 11) persoFrameX = 9;
					break;
				case 2:
					if (persoFrameX > 8) persoFrameX = 6;
					break;
				case 3:
					if (persoFrameX > 3) persoFrameX = 0;
					break;
				case 4:
					if (persoFrameX > 5) persoFrameX = 3;
					break;
				default:
					break;
				}
				persoRect.left = persoFrameX * persoRect.width;
				persoRect.top = persoFrameY * persoRect.height;
				persoSprite.setTextureRect(persoRect);

			}
			else {
				persoRect.left = persoFrameX * persoRect.width;
				persoRect.top = persoFrameY * persoRect.height;
				persoSprite.setTextureRect(persoRect);
			}
		}
	}
}

void Joueur::displayPerso(myWindow& _window, ModeGame _mode) {
	if (_mode == ModeGame::LIBRE) {
		persoSprite.setTextureRect(persoRect);
		persoSprite.setPosition(persoPosition);
		_window.Draw(persoSprite);
	}
	if (_mode == ModeGame::CHASSE) {
		persoSprite.setTextureRect(persoRect);
		persoSprite.setPosition(persoPosition);
		_window.Draw(persoSprite);
	}
	if (_mode == ModeGame::AVE) {
		persoSprite.setTextureRect(persoRect);
		persoSprite.setPosition(persoPosition);
		_window.Draw(persoSprite);
	}
}

void Joueur::directionCombat() {
	switch (classeDisplay)
	{
	case 0:
		persoRect = { 192,18,16,18 };
		break;
	case 1:
		persoRect = { 144,18,16,18 };
		break;
	case 2:
		persoRect = { 96,18,16,18 };
		break;
	case 3:
		persoRect = { 0,18,16,18 };
		break;
	case 4:
		persoRect = { 48,18,16,18 };
		break;
	default:
		break;
	}
}

Joueur::Joueur()
{
	exp = 0;
	expDemande = 30;
	TotalExp = expDemande;
	skillPoint = 0;
	choixSkill = 1;
	niveauSkill = 0;

	choixUseObjet = 0;

	SKILL[0] = false;
	SKILL[1] = false;
	SKILL[2] = false;
	SKILL[3] = false;
	SKILL[4] = false;
	SKILL[5] = false;
	SKILL[6] = false;
	SKILL[7] = false;
	SKILL[8] = false;

	EpeeBuy = 0;
	LanceBuy = 0;
	BatonBuy = 0;
	BouclierBuy = 0;
	LourdBuy = 0;
	LegerBuy = 0;
	SoinPvBuy = 0;
	SoinManaBuy = 0;
	BombeBuy = 0;
}

Joueur::~Joueur()
{
}

void Joueur::Experience(int _xp) {
	std::cout << "XP gagner " << _xp << std::endl;
	exp += _xp;
	while (exp >= TotalExp) {
		niveau += 1;
		SetNiveau(niveau);
		ChangeStatNiveau(GetNiveau());
		expDemande *= 2.5;
		TotalExp = expDemande;
		skillPoint += 1;
		std::cout << " skillPoint : " << skillPoint << std::endl;
	}
	std::cout << "niveau : " << niveau << std::endl;
	std::cout << "exp : " << exp << std::endl;
	std::cout << "expDemande niveau suivant: " << expDemande << std::endl;

}

void Joueur::SetJob(Job& _job)
{
	job = _job;
	UpdateStatsJob();
}

void Joueur::SetEffet(Job::Effets& _effet)
{
	job.effet = _effet;
}

void Joueur::skillTree() {

	switch (GetNiveau())
	{
	case 2:
		Branche1 = true;
		break;
	case 3:
		Branche1 = true;
		Branche2 = true;
		break;
	case 4:
		Branche1 = true;
		Branche2 = true;
		Branche3 = true;
		break;
	case 5:
		Branche1 = true;
		Branche2 = true;
		Branche3 = true;
		Branche4 = true;
		break;
	default:
		break;
	}

	int _tmp;
	std::cout << "Vous voici dans l'arbre de competence " << std::endl;
	std::cout << "Voulez vous entrer la Branche " << choixSkill << " ?" << std::endl;
	std::cout << " 1 : oui   / 2 : Non " << std::endl;
	std::cin >> _tmp;
	switch (_tmp)
	{
	case 1:
		if (skillPoint >= 1) {
			switch (choixSkill)
			{
			case 1:
				int _tmp1;
				std::cout << "Voici les skillPoint que vous avez obtenu : " << skillPoint << std::endl;
				std::cout << "Voulez vous debloquer le skill 1 ?" << std::endl;
				std::cout << "l'attaque crit a 100%" << std::endl;
				std::cout << "1 : Oui   /   2 : Non" << std::endl;
				std::cin >> _tmp1;
				switch (_tmp1)
				{
				case 1:
					if (Branche1 == true) {
						if (skillPoint >= 1)
						{
							SKILL[0] = true;
							std::cout << "Vous avez obtenue le skill 1" << std::endl;
							choixSkill += 1;
							niveauSkill += 1;
							skillPoint -= 1;
							system("Pause");
						}
						else {
							std::cout << "Vous n'avez pas assez de point" << std::endl;
						}
					}
					else {
						std::cout << "Vous n'avez pas le bon niveau" << std::endl;
					}
					break;
				case 2:
					choixSkillTree = false;
					break;
				default:
					std::cout << "Vous n'avez fais de chois valide" << std::endl;
					break;
				}
				break;
			case 2:
				int _tmp2;
				std::cout << "Voici les skillPoint que vous avez obtenu : " << skillPoint << std::endl;
				std::cout << "Voulez vous debloquer le skill 2 ou 3 ?" << std::endl;
				std::cout << "Voulez vous debloquer le skill 2 ou 3 ?" << std::endl;
				std::cout << "1 : Oui   /   2 : Non" << std::endl;
				std::cin >> _tmp2;
				switch (_tmp2)
				{
				case 1:
					if (Branche2 == true) {
						if (skillPoint >= 1) {

							int _tmp3;
							std::cout << " Choisissez votre chemin" << std::endl;
							std::cout << "1 : pour le skill 2 : l'attaque ignore la defense ennemi" << std::endl;
							std::cout << "2 : pour le skill 3 : l'attaque ignore l'element ennemi" << std::endl;
							std::cout << "0 : pour annuler : " << std::endl;
							std::cin >> _tmp3;
							switch (_tmp3)
							{
							case 1:
								SKILL[1] = true;
								SKILL[2] = false;
								std::cout << "Vous avez obtenue le skill 2" << std::endl;
								niveauSkill += 1;
								skillPoint -= 1;
								break;
							case 2:
								SKILL[1] = true;
								SKILL[2] = false;
								std::cout << "Vous avez obtenue le skill 3" << std::endl;
								niveauSkill += 1;
								skillPoint -= 1;
								break;
							case 0:
								choixSkillTree = false;
								break;
							default:
								std::cout << "Vous n'avez fais de chois valide" << std::endl;
								break;
							}
						}
						else {
							std::cout << "Vous n'avez pas assez de point" << std::endl;
						}
					}
					else {
						std::cout << "Vous n'avez pas le bon niveau" << std::endl;
					}
					break;
				case 2:
					choixSkillTree = false;
					break;
				default:
					std::cout << "Vous n'avez fais de chois valide" << std::endl;
					break;
				}
				break;
			case 3:
				int _tmp4;
				std::cout << "Voulez vous debloquer le skill 4 / 5 ou 6 / 7 ?" << std::endl;
				std::cout << "1 : Oui   /   2 : Non" << std::endl;
				std::cin >> _tmp4;
				switch (_tmp4)
				{
				case 1:
					if (Branche3 == true) {
						if (skillPoint >= 1) {
							if (SKILL[1] == true) {
								int _tmp5;
								std::cout << " Choisissez votre chemin" << std::endl;
								std::cout << "1 : pour le skill 4 :" << std::endl;
								std::cout << "2 : pour le skill 5 : " << std::endl;
								std::cout << "0 : pour annuler : " << std::endl;
								std::cin >> _tmp5;
								switch (_tmp5)
								{
								case 1:
									SKILL[3] = true;
									SKILL[4] = false;
									std::cout << "Vous avez obtenue le skill 4" << std::endl;
									niveauSkill += 1;
									skillPoint -= 1;
									break;
								case 2:
									SKILL[3] = false;
									SKILL[4] = true;
									std::cout << "Vous avez obtenue le skill 5" << std::endl;
									niveauSkill += 1;
									skillPoint -= 1;
									break;
								case 0:
									choixSkillTree = false;
									break;
								default:
									std::cout << "Vous n'avez fais de chois valide" << std::endl;
									break;
								}
							}
							else if (SKILL[2] == true) {

								int _tmp5;
								std::cout << " Choisissez votre chemin" << std::endl;
								std::cout << "1 : pour le skill 6 :" << std::endl;
								std::cout << "2 : pour le skill 7 : " << std::endl;
								std::cout << "0 : pour annuler : " << std::endl;
								std::cin >> _tmp5;
								switch (_tmp5)
								{
								case 1:
									SKILL[5] = true;
									SKILL[6] = false;
									std::cout << "Vous avez obtenue le skill 6" << std::endl;
									niveauSkill += 1;
									skillPoint -= 1;
									break;
								case 2:
									SKILL[5] = false;
									SKILL[6] = true;
									std::cout << "Vous avez obtenue le skill 7" << std::endl;
									niveauSkill += 1;
									skillPoint -= 1;
									break;
								case 0:
									choixSkillTree = false;
									break;
								default:
									std::cout << "Vous n'avez fais de chois valide" << std::endl;
									break;
								}
							}
						}
						else {
							std::cout << "Vous n'avez pas assez de point" << std::endl;
						}
					}
					else {
						std::cout << "Vous n'avez pas le bon niveau" << std::endl;
					}
					break;
				case 2:
					choixSkillTree = false;
					break;
				default:
					std::cout << "Vous n'avez fais de chois valide" << std::endl;
					break;
				}
				break;
			case 4:
				int _tmp5;
				std::cout << "Voulez vous debloquer le skill 8 / 9 ?" << std::endl;
				if (SKILL[3] == true || SKILL[4] == true) {
					std::cout << "1 : pour le skill 8 : invoque une creature capture" << std::endl;
				}
				if (SKILL[5] == true || SKILL[6] == true) {
					std::cout << "1 : pour le skill 9 : invoque un villagois kidnappe" << std::endl;
				}
				std::cout << "1 : Oui   /   2 : Non" << std::endl;
				std::cin >> _tmp5;
				if (Branche4 == true) {
					if (skillPoint >= 1) {
						if (SKILL[3] == true || SKILL[4] == true) {
							SKILL[7] = true;
							niveauSkill += 1;
							skillPoint -= 1;
						}
						if (SKILL[5] == true || SKILL[6] == true) {
							SKILL[8] = true;
							niveauSkill += 1;
							skillPoint -= 1;
						}
					}
					else {
						std::cout << "Vous n'avez pas assez de point" << std::endl;
					}
				}
				else {
					std::cout << "Vous n'avez pas le bon niveau" << std::endl;
				}
				break;
			default:
				std::cout << "Vous n'avez fais de chois valide" << std::endl;
				break;
			}
		}
		else {
			std::cout << "Vous n'avez pas assez de point" << std::endl;
		}
		break;
	case 2:
		choixSkillTree = false;
		break;
	default:
		std::cout << "Vous n'avez fais de chois valide" << std::endl;
		break;
	}

}

void Joueur::UseSkill(Joueur& _perso1, Joueur& _perso2) {

	std::cout << "Choisissez votre skill : " << std::endl;
	if (SKILL[0] == true) {
		std::cout << "1 : skill 1 : l'attaque crit a 100%" << std::endl;
	}
	if (SKILL[1] == true) {
		std::cout << "2 : skill 2 : l'attaque ignore la defense ennemi " << std::endl;
	}
	if (SKILL[2] == true) {
		std::cout << "3 : skill 3 : l'attaque prend l'element fort face a l'element ennemi" << std::endl;
	}
	if (SKILL[7] == true) {
		std::cout << "8 : skill 8 : Invoque une creature" << std::endl;
	}
	if (SKILL[8] == true) {
		std::cout << "9 : skill 9 : Invoque un villagois" << std::endl;
	}
	if (SKILL[0] == false && SKILL[1] == false && SKILL[2] == false && SKILL[7] == false && SKILL[8] == false) {
		std::cout << "Vous n'avez pas de skill ! " << std::endl;
	}
	std::cout << "0 : Pour annuler l'attaque" << std::endl;
	int _skillChose;
	std::cin >> _skillChose;
	switch (_skillChose)
	{
	case 1:
		if (SKILL[0] == true) {
			degatFinal = (_perso1.GetTotAttaque() - _perso2.GetTotDefense());
			_perso1.ChoixElement(_perso1.element, _perso2.element);
			degatFinal = degatFinal *= _perso1.GetDegatElement();
			degatFinal *= 2;
			if (degatFinal <= 0)
				degatFinal = 0;
			PvRestant = _perso2.GetTotPv() - degatFinal;
			_perso2.SetTotPv(PvRestant);
			std::cout << "Vous avez attaque le " << _perso2.GetName() << std::endl;
			std::cout << "Vous avez fait un coup critique de " << degatFinal << " degat" << std::endl;
		}
		else {
			std::cout << "Vous n'avez pas le skill 1 ! " << std::endl;
			AnnulAtk = 0;
		}
		break;
	case 2:
		if (SKILL[1] == true) {
			degatFinal = (_perso1.GetTotAttaque());
			_perso1.ChoixElement(_perso1.element, _perso2.element);
			degatFinal = degatFinal *= _perso1.GetDegatElement();
			if (degatFinal <= 0)
				degatFinal = 0;
			PvRestant = _perso2.GetTotPv() - degatFinal;
			_perso2.SetTotPv(PvRestant);
			std::cout << "Vous avez attaque le " << _perso2.GetName() << std::endl;
			std::cout << "Vous avez fait " << degatFinal << " de degat ignorant la defense de l'ennemi" << std::endl;
		}
		else {
			std::cout << "Vous n'avez pas le skill 2 ! " << std::endl;
			AnnulAtk = 0;
		}
		break;
	case 3:
		if (SKILL[2] == true) {
			degatFinal = (_perso1.GetTotAttaque() - _perso2.GetTotDefense());
			degatFinal *= 2;
			if (degatFinal <= 0)
				degatFinal = 0;
			PvRestant = _perso2.GetTotPv() - degatFinal;
			_perso2.SetTotPv(PvRestant);
			std::cout << "Vous avez attaque le " << _perso2.GetName() << std::endl;
			std::cout << "Vous avez fait " << degatFinal << " de degat ignorant l'elemnt de l'ennemi" << std::endl;
		}
		else {
			std::cout << "Vous n'avez pas le skill 3 ! " << std::endl;
			//AnnulAtk = 0;
		}
		break;
	case 8:
		if (SKILL[7] == true) {
			//INVOQUE CREATURE
		}
		else {
			std::cout << "Vous n'avez pas le skill 8 ! " << std::endl;
		}
		break;
	case 9:
		if (SKILL[8] == true) {
			//INVOQUE VILLAGOIS

		}
		else {
			std::cout << "Vous n'avez pas le skill 9 ! " << std::endl;
		}
		break;
	case 0:
		//AnnulAtk = 0;
		break;
	default:
		std::cout << "Vous n'avez fais de chois valide" << std::endl;
		break;
	}
}

void Joueur::ChoixObjetCombat(Personnage& _perso1, Personnage& _perso2, Consos _conso) {
	std::cout << "Choisissez votre objet : " << std::endl;
	if (soinPvEquipe == true) {
		std::cout << "1: Objet de soin de PV" << std::endl;
	}
	if (soinManaEquipe == true) {
		std::cout << "2: Objet de soin de Mana" << std::endl;
	}
	if (bombeEquipe == true) {
		std::cout << "3: Objet Bombe equipe" << std::endl;
	}
	if (soinPvEquipe == false && soinManaEquipe == false && bombeEquipe == false) {
		std::cout << "Vous n'avez pas de objet a utilise ! " << std::endl;
	}
	std::cout << "0 : Pour annuler l'utilisation d'objet" << std::endl;

	if (choixUseObjet == 1) {
		UseSoinPvCombat(_perso1, _conso);
		choixUseObjet = 0;
	}
	if (choixUseObjet == 2) {
		UseSoinMCombat(_perso1, _conso);
		choixUseObjet = 0;
	}
	if (choixUseObjet == 3) {
		UseBombeCombat(_perso1, _perso2, _conso);
		choixUseObjet = 0;
	}
}

void Joueur::UseSoinPvCombat(Personnage& _perso1, Consos _conso) {
	if (soinPvEquipe == true) {
		_perso1.SetTotPv(_perso1.GetTotPv() + _conso.GetSoinPv());
		std::cout << "Vous vous etes soigne de " << _conso.GetSoinPv() << " PV" << std::endl;
		SoinPvBuy -= 1;
		soinPvEquipe = false;
	}
	else {
		std::cout << "Vous n'avez pas l' objet de soin de PV ! " << std::endl;
		AnnulAtk = 0;
	}
}

void Joueur::UseSoinMCombat(Personnage& _perso1, Consos _conso) {
	if (soinManaEquipe == true) {
		_perso1.SetTotMana(_perso1.GetTotMana() + _conso.GetSoinM());
		std::cout << "Vous vous etes soigne de " << _conso.GetSoinM() << " MANA" << std::endl;
		SoinManaBuy -= 1;
		soinManaEquipe = false;
	}
	else {
		std::cout << "Vous n'avez pas l' objet de soin de MANA ! " << std::endl;
		AnnulAtk = 0;
	}
}

void Joueur::UseBombeCombat(Personnage& _perso1, Personnage& _perso2, Consos _conso) {
	if (bombeEquipe == true) {
		degatFinal = _conso.GetDegat();
		PvRestant = _perso2.GetTotPv() - degatFinal;
		_perso2.SetTotPv(PvRestant);
		std::cout << "Vous avez lance la " << _conso.GetName() << " sur " << _perso2.GetName() << std::endl;
		std::cout << "La " << _conso.GetName() << " a fait " << degatFinal << " degat" << std::endl;
		BombeBuy -= 1;
		bombeEquipe = false;
	}
	else {
		std::cout << "Vous n'avez pas la bombe ! " << std::endl;
		AnnulAtk = 0;
	}
}

std::string Joueur::ArmeEquiper() {
	if (GetEquipEpee() == true)
		return "Epee, ";
	else if (GetEquipLance() == true)
		return "Lance, ";
	else if (GetEquipBague() == true)
		return "Bague, ";
	else
		return "None Arme, ";
}

std::string Joueur::ArmureEquiper() {
	if (GetEquipLeger() == true)
		return " Leger, ";
	else if (GetEquipLourd() == true)
		return " Lourd, ";
	else if (GetEquipBoucclier() == true)
		return " Bouclier, ";
	else
		return " None Armure";
}

