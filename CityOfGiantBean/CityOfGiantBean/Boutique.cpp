#include "Boutique.h"

Armes None;
Armes Epee;
Armes Lance;
Armes Baton;
Armures NoneA;
Armures Bouclier;
Armures Lourd;
Armures Leger;
Consos SoinPv;
Consos SoinMana;
Consos Bombe;

sf::Vector2f ShopPNJsize;
sf::Vector2f ShopPNJpos;
sf::RectangleShape ShopPNJshape;

sf::Vector2f ShopEpeeSize;
sf::Vector2f ShopEpeePos;
sf::RectangleShape ShopEpeeShape;
sf::Vector2f ShopLanceSize;
sf::Vector2f ShopLancePos;
sf::RectangleShape ShopLanceShape;
sf::Vector2f ShopBatonSize;
sf::Vector2f ShopBatonPos;
sf::RectangleShape ShopBatonShape;

sf::Vector2f ShopBouclierSize;
sf::Vector2f ShopBouclierPos;
sf::RectangleShape ShopBouclierShape;
sf::Vector2f ShopLourdSize;
sf::Vector2f ShopLourdPos;
sf::RectangleShape ShopLourdShape;
sf::Vector2f ShopLegerSize;
sf::Vector2f ShopLegerPos;
sf::RectangleShape ShopLegerShape;

sf::Vector2f ShopPotionPVSize;
sf::Vector2f ShopPotionPVPos;
sf::RectangleShape ShopPotionPVShape;
sf::Vector2f ShopPotionMSize;
sf::Vector2f ShopPotionMPos;
sf::RectangleShape ShopPotionMShape;
sf::Vector2f ShopBombeSize;
sf::Vector2f ShopBombePos;
sf::RectangleShape ShopBombeShape;

sf::Font font;
sf::Text ValidationShop, OuiTexte, NonTexte, txVendeur;
int OuiNon = 3;
sf::Text PasArgentShop, ArgentRestantB;
sf::Text ObtenuObjetTexte;

int choixBoutique;
bool choixShop;
extern float timerShop;
std::string ObtenuObjet, PasDArgent, ArgentRestant, ValidationAchat, stVendeur, stNomObjet, ObtenuObjetEn, PasDArgentEn, ArgentRestantEn, ValidationAchatEn, stVendeurEn, stNomObjetEn;
int PasArgentReste = 0;
int Valid = 0;
int ValidReussiB = 0;
int achatReussi = 0;
float timerPasArgent;
float timerReussiB{ 0.0f };
int pnjAcceuil = 0;

void loadBoutique() {
	std::vector<Armes>Arme;
	std::vector<Armures>Armure;
	std::vector<Consos>Conso;

	std::ifstream BoutiqueLoad("..\\Ressources\\SAVE\\BoutiqueLoad.txt", std::ios::in);
	if (!BoutiqueLoad.is_open())
	{
		std::cout << "Impossible d'ouvrir le fichier de sauvegarde de la boutique" << std::endl;
	}
	else
	{
		std::string _TmpName;
		int _TmpValue1;
		int _TmpValue2;
		int _TmpValue3;
		int _TmpValue4;
		BoutiqueLoad >> _TmpName >> _TmpValue1 >> _TmpValue2 >> _TmpValue3;
		Epee.SetStats(_TmpName, _TmpValue1, _TmpValue2, _TmpValue3);
		BoutiqueLoad >> _TmpName >> _TmpValue1 >> _TmpValue2 >> _TmpValue3;
		Lance.SetStats(_TmpName, _TmpValue1, _TmpValue2, _TmpValue3);
		BoutiqueLoad >> _TmpName >> _TmpValue1 >> _TmpValue2 >> _TmpValue3;
		Baton.SetStats(_TmpName, _TmpValue1, _TmpValue2, _TmpValue3);
		BoutiqueLoad >> _TmpName >> _TmpValue1 >> _TmpValue2 >> _TmpValue3;
		Bouclier.SetStats(_TmpName, _TmpValue1, _TmpValue2, _TmpValue3);
		BoutiqueLoad >> _TmpName >> _TmpValue1 >> _TmpValue2 >> _TmpValue3;
		Lourd.SetStats(_TmpName, _TmpValue1, _TmpValue2, _TmpValue3);
		BoutiqueLoad >> _TmpName >> _TmpValue1 >> _TmpValue2 >> _TmpValue3;
		Leger.SetStats(_TmpName, _TmpValue1, _TmpValue2, _TmpValue3);
		BoutiqueLoad >> _TmpName >> _TmpValue1 >> _TmpValue2 >> _TmpValue3 >> _TmpValue4;
		SoinPv.SetStats(_TmpName, _TmpValue1, _TmpValue2, _TmpValue3, _TmpValue4);
		BoutiqueLoad >> _TmpName >> _TmpValue1 >> _TmpValue2 >> _TmpValue3 >> _TmpValue4;
		SoinMana.SetStats(_TmpName, _TmpValue1, _TmpValue2, _TmpValue3, _TmpValue4);
		BoutiqueLoad >> _TmpName >> _TmpValue1 >> _TmpValue2 >> _TmpValue3 >> _TmpValue4;
		Bombe.SetStats(_TmpName, _TmpValue1, _TmpValue2, _TmpValue3, _TmpValue4);

		///// Arme / Armure vide

		None.SetStats("", 0, 0, 0);
		NoneA.SetStats("", 0, 0, 0);

	}
}

void initBoutique() {


	ShopPNJsize = { AjustResoX *  60, AjustResoY * 40 };
	ShopPNJpos = { AjustResoX * 937, AjustResoY * 540};
	ShopPNJshape.setSize(ShopPNJsize);
	ShopPNJshape.setPosition(ShopPNJpos);
	ShopPNJshape.setFillColor(sf::Color::Red);

	ShopEpeeSize = { AjustResoX * 60, AjustResoY * 45 };
	ShopEpeePos = { AjustResoX * 1445, AjustResoY * 527 };
	ShopEpeeShape.setSize(ShopEpeeSize);
	ShopEpeeShape.setPosition(ShopEpeePos);
	ShopEpeeShape.setFillColor(sf::Color::Red);

	ShopLanceSize = { AjustResoX * 65, AjustResoY * 45 };
	ShopLancePos = { AjustResoX * 1540, AjustResoY * 524};
	ShopLanceShape.setSize(ShopLanceSize);
	ShopLanceShape.setPosition(ShopLancePos);
	ShopLanceShape.setFillColor(sf::Color::Cyan);

	ShopBatonSize = { AjustResoX * 60, AjustResoY * 45 };
	ShopBatonPos = { AjustResoX * 1637, AjustResoY * 522};
	ShopBatonShape.setSize(ShopBatonSize);
	ShopBatonShape.setPosition(ShopBatonPos);
	ShopBatonShape.setFillColor(sf::Color::Yellow);

	ShopBouclierSize = { AjustResoX * 60, AjustResoY * 45 };
	ShopBouclierPos = { AjustResoX * 1277, AjustResoY * 520 };
	ShopBouclierShape.setSize(ShopBouclierSize);
	ShopBouclierShape.setPosition(ShopBouclierPos);
	ShopBouclierShape.setFillColor(sf::Color::Red);

	ShopLourdSize = { AjustResoX * 62, AjustResoY * 45 };
	ShopLourdPos = { AjustResoX * 1187, AjustResoY * 523 };
	ShopLourdShape.setSize(ShopLourdSize);
	ShopLourdShape.setPosition(ShopLourdPos);
	ShopLourdShape.setFillColor(sf::Color::Cyan);

	ShopLegerSize = { AjustResoX * 60, AjustResoY * 45 };
	ShopLegerPos = { AjustResoX * 1095, AjustResoY * 521};
	ShopLegerShape.setSize(ShopLegerSize);
	ShopLegerShape.setPosition(ShopLegerPos);
	ShopLegerShape.setFillColor(sf::Color::Yellow);

	ShopPotionPVSize = { AjustResoX * 60, AjustResoY * 45 };
	ShopPotionPVPos = { AjustResoX * 374, AjustResoY * 516};
	ShopPotionPVShape.setSize(ShopPotionPVSize);
	ShopPotionPVShape.setPosition(ShopPotionPVPos);
	ShopPotionPVShape.setFillColor(sf::Color::Red);

	ShopPotionMSize = { AjustResoX * 60, AjustResoY * 45 };
	ShopPotionMPos = { AjustResoX * 453, AjustResoY * 524};
	ShopPotionMShape.setSize(ShopPotionMSize);
	ShopPotionMShape.setPosition(ShopPotionMPos);
	ShopPotionMShape.setFillColor(sf::Color::Cyan);

	ShopBombeSize = { AjustResoX * 60, AjustResoY * 45 };
	ShopBombePos = { AjustResoX * 540, AjustResoY * 516 };
	ShopBombeShape.setSize(ShopBombeSize);
	ShopBombeShape.setPosition(ShopBombePos);
	ShopBombeShape.setFillColor(sf::Color::Yellow);

	font.loadFromFile("../Ressources/Fonts/Typewriter.ttf");

	PasArgentShop.setFont(font);
	PasArgentShop.setOrigin(PasArgentShop.getGlobalBounds().height / 2, PasArgentShop.getGlobalBounds().width / 2);
	PasArgentShop.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	PasArgentShop.setFillColor(sf::Color::Black);

	ArgentRestantB.setFont(font);
	ArgentRestantB.setOrigin(ArgentRestantB.getGlobalBounds().height / 2, ArgentRestantB.getGlobalBounds().width / 2);
	ArgentRestantB.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	ArgentRestantB.setFillColor(sf::Color::Black);

	ObtenuObjetTexte.setFont(font);
	ObtenuObjetTexte.setOrigin(ObtenuObjetTexte.getGlobalBounds().height / 2, ObtenuObjetTexte.getGlobalBounds().width / 2);
	ObtenuObjetTexte.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	ObtenuObjetTexte.setFillColor(sf::Color::Black);

	ValidationShop.setFont(font);
	ValidationShop.setOrigin(ValidationShop.getGlobalBounds().height / 2, ValidationShop.getGlobalBounds().width / 2);
	ValidationShop.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	ValidationShop.setFillColor(sf::Color::Black);

	OuiTexte.setFont(font);
	OuiTexte.setOrigin(OuiTexte.getGlobalBounds().height / 2, OuiTexte.getGlobalBounds().width / 2);
	OuiTexte.setPosition(AjustResoX * 600.0f, AjustResoY * 950.0f);
	OuiTexte.setFillColor(sf::Color::Red);

	NonTexte.setFont(font);
	NonTexte.setOrigin(NonTexte.getGlobalBounds().height / 2, NonTexte.getGlobalBounds().width / 2);
	NonTexte.setPosition(AjustResoX * 700.0f, AjustResoY * 950.0f);
	NonTexte.setFillColor(sf::Color::Red);

	txVendeur.setFont(font);
	txVendeur.setOrigin(txVendeur.getGlobalBounds().height / 2, txVendeur.getGlobalBounds().width / 2);
	txVendeur.setPosition(AjustResoX * 150.0f, AjustResoY * 850.0f);
	txVendeur.setFillColor(sf::Color::Black);

	PasDArgent = "Vous n'avez pas assez d'argent!";
	ArgentRestant = "Argent restant : ";
	ValidationAchat = "Voulez vous acheter cette objet ?";
	ObtenuObjet = "Vous avez Obtenu : ";
	stVendeur = "Bonjour et bienvenue dans la boutique ! Vous pouvez acheter\ndes equipements et des consommables, vous pourrez les equipes\net voir vos quantites depuis votre inventaire";

	PasDArgentEn = "You don't have enough gold!";
	ArgentRestantEn = "nGold remaining : ";
	ValidationAchatEn = "Do you want to buy this item ?";
	ObtenuObjetEn = "You got : ";
	stVendeurEn = "Hello and welcome to the shop! You can buy\nequipment and consumables, you can equip them\nand see your quantities from your inventory";

	boiteDiscussion::initBoiteDiscussion();
	loadBoutique();

	tools::ChoixLangue(tools::GetTrad(), OuiTexte, "Oui", "Yes");
	tools::ChoixLangue(tools::GetTrad(), NonTexte, "Non", "No");
	tools::ChoixLangue(tools::GetTrad(), txVendeur, stVendeur, stVendeurEn);
	tools::ChoixLangue(tools::GetTrad(), PasArgentShop, PasDArgent, PasDArgentEn);
}

void updateBoutique(myWindow& _window, Joueur& _perso1) {
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, ShopPNJpos, ShopPNJsize))
		pnjAcceuil = 1;
	else
		pnjAcceuil = 0;
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, ShopEpeePos, ShopEpeeSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		choixBoutique = 1;
		Valid = 1;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, ShopLancePos, ShopLanceSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		choixBoutique = 2;
		Valid = 1;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, ShopBatonPos, ShopBatonSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		choixBoutique = 3;
		Valid = 1;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, ShopBouclierPos, ShopBouclierSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		choixBoutique = 4;
		Valid = 1;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, ShopLourdPos, ShopLourdSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		choixBoutique = 5;
		Valid = 1;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, ShopLegerPos, ShopLegerSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		choixBoutique = 6;
		Valid = 1;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, ShopPotionPVPos, ShopPotionPVSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		choixBoutique = 7;
		Valid = 1;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, ShopPotionMPos, ShopPotionMSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		choixBoutique = 8;
		Valid = 1;
	}
	if (tools::CircleRect_Collision(_perso1.GetPos(), 10, ShopBombePos, ShopBombeSize) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		choixBoutique = 9;
		Valid = 1;
	}

	if (choixBoutique == 1) {
		stNomObjet = " Epee";
		stNomObjetEn = " Sword";
		validationShop(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 1) {
			AchatArmes(_perso1, Epee);
			if (achatReussi == 1) {
				_perso1.EpeeBuy += 1;
				_perso1.iAchat += 1;
				achatReussi = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 2) {
			NonRetourBoutique();
		}
	}
	if (choixBoutique == 2) {
		stNomObjet = " Lance";
		stNomObjetEn = " Spear";
		validationShop(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 1) {
			AchatArmes(_perso1, Lance);
			if (achatReussi == 1) {
				_perso1.LanceBuy += 1;
				_perso1.iAchat += 1;
				achatReussi = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 2) {
			NonRetourBoutique();
		}
	}
	if (choixBoutique == 3) {
		stNomObjet = " Bague";
		stNomObjetEn = " Ring";
		validationShop(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 1) {
			AchatArmes(_perso1, Baton);
			if (achatReussi == 1) {
				_perso1.BatonBuy += 1;
				_perso1.iAchat += 1;
				achatReussi = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 2) {
			NonRetourBoutique();
		}
	}
	if (choixBoutique == 4) {
		stNomObjet = " Bouclier";
		stNomObjetEn = " Shield";
		validationShop(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 1) {
			AchatArmures(_perso1, Bouclier);
			if (achatReussi == 1) {
				_perso1.BouclierBuy += 1;
				_perso1.iAchat += 1;
				achatReussi = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 2) {
			NonRetourBoutique();
		}
	}
	if (choixBoutique == 5) {
		stNomObjet = " Armure Lourde";
		stNomObjetEn = " Heavy Armor";
		validationShop(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 1) {
			AchatArmures(_perso1, Lourd);
			if (achatReussi == 1) {
				_perso1.LourdBuy += 1;
				_perso1.iAchat += 1;
				achatReussi = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 2) {
			NonRetourBoutique();
		}
	}
	if (choixBoutique == 6) {
		stNomObjet = " Armure Legere";
		stNomObjetEn = " Light armor";
		validationShop(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 1) {
			AchatArmures(_perso1, Leger);
			if (achatReussi == 1) {
				_perso1.LegerBuy += 1;
				_perso1.iAchat += 1;
				achatReussi = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 2) {
			NonRetourBoutique();
		}
	}
	if (choixBoutique == 7) {
		stNomObjet = " Potion de soin";
		stNomObjetEn = " Healing potion";
		validationShop(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 1) {
			AchatConsos(_perso1, SoinPv);
			if (achatReussi == 1) {
				_perso1.SoinPvBuy += 1;
				_perso1.iAchat += 1;
				achatReussi = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 2) {
			NonRetourBoutique();
		}
	}
	if (choixBoutique == 8) {
		stNomObjet = " Potion de Mana";
		stNomObjetEn = " Mana potion";
		validationShop(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 1) {
			AchatConsos(_perso1, SoinMana);
			if (achatReussi == 1) {
				_perso1.SoinManaBuy += 1;
				_perso1.iAchat += 1;
				achatReussi = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 2) {
			NonRetourBoutique();
		}
	}
	if (choixBoutique == 9) {
		stNomObjet = " Bombe";
		stNomObjetEn = " Bomb";
		validationShop(_window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 1) {
			AchatConsos(_perso1, Bombe);
			if (achatReussi == 1) {
				_perso1.BombeBuy += 1;
				_perso1.iAchat += 1;
				if (save::getTutoNb() == 4)
					save::setTutoNb(5);
				achatReussi = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && OuiNon == 2) {
			NonRetourBoutique();
		}
	}
}

void NonRetourBoutique() {
	Valid = 0;
	choixBoutique = 0;
	OuiNon = 3;
}

void AchatArmes(Joueur& _perso1, Armes _armes) {
	if (_perso1.GetTotArgent() >= _armes.GetPrix()) {
		_perso1.SetTotArgent(_perso1.GetTotArgent() - _armes.GetPrix());
		tools::ChoixLangue(tools::GetTrad(), ObtenuObjetTexte, "Vous avez obtenu : " + _armes.GetName(), "You got :" + _armes.GetName());
		tools::ChoixLangue(tools::GetTrad(), ArgentRestantB, "\n\nOr restant : " + std::to_string((int)_perso1.GetTotArgent()), "\n\nGold remaining " + std::to_string((int)_perso1.GetTotArgent()));
		achatReussi = 1;
		ValidReussiB = 1;
		PasArgentReste = 0;
		NonRetourBoutique();
	}
	else {
		achatReussi = 0;
		PasArgentReste = 1;
		NonRetourBoutique();
	}
}

void EquipLeger(Joueur& _perso1) {
	if (_perso1.LegerBuy >= 1) {
		if (_perso1.armureEquipe == true) {
			std::cout << "Vous avez deja une Armure equipe " << std::endl;
		}
		else {

			_perso1.SetArmure(Leger);
			_perso1.UpdateStatsJob();
			_perso1.DisplayStat();
			_perso1.armureEquipe = true;
			_perso1.bLegerEquip = true;
			_perso1.LegerBuy -= 1;
			std::cout << "Vous avez equipe cette Armure " << std::endl;
		}
	}
	else {
		std::cout << "Vous n'avez pas cette Armure " << std::endl;
	}
}

void EquipLourd(Joueur& _perso1) {
	if (_perso1.LourdBuy >= 1) {
		if (_perso1.armureEquipe == true) {
			std::cout << "Vous avez deja une Armure equipe " << std::endl;
		}
		else {

			_perso1.SetArmure(Lourd);
			_perso1.UpdateStatsJob();
			_perso1.DisplayStat();
			_perso1.armureEquipe = true;
			_perso1.bLourdEquip = true;
			_perso1.LourdBuy -= 1;
			std::cout << "Vous avez equipe cette Armure " << std::endl;
		}
	}
	else {
		std::cout << "Vous n'avez pas cette Armure " << std::endl;
	}
}

void EquipBouclier(Joueur& _perso1) {
	if (_perso1.BouclierBuy >= 1) {
		if (_perso1.armureEquipe == true) {
			std::cout << "Vous avez deja une Armure equipe " << std::endl;
		}
		else {

			_perso1.SetArmure(Bouclier);
			_perso1.UpdateStatsJob();
			_perso1.DisplayStat();
			_perso1.armureEquipe = true;
			_perso1.bBouclierEquip = true;
			_perso1.BouclierBuy -= 1;
			std::cout << "Vous avez equipe cette Armure " << std::endl;
		}
	}
	else {
		std::cout << "Vous n'avez pas cette Armure " << std::endl;
	}
}

void EquipEpee(Joueur& _perso1) {
	if (_perso1.EpeeBuy >= 1) {
		if (_perso1.armeEquipe == true) {
			std::cout << "Vous avez deja une Arme equipe " << std::endl;
		}
		else {

			_perso1.SetArme(Epee);
			_perso1.UpdateStatsJob();
			_perso1.DisplayStat();
			_perso1.armeEquipe = true;
			_perso1.bEpeeEquip = true;
			_perso1.EpeeBuy -= 1;
			std::cout << "Vous avez equipe cette Arme " << std::endl;
		}
	}
	else {
		std::cout << "Vous n'avez pas cette Arme " << std::endl;
	}
}

void EquipLance(Joueur& _perso1) {
	if (_perso1.LanceBuy >= 1) {
		if (_perso1.armeEquipe == true) {
			std::cout << "Vous avez deja une Arme equipe " << std::endl;
		}
		else {

			_perso1.SetArme(Lance);
			_perso1.UpdateStatsJob();
			_perso1.DisplayStat();
			_perso1.armeEquipe = true;
			_perso1.bLanceEquip = true;
			_perso1.LanceBuy -= 1;
			std::cout << "Vous avez equipe cette Arme " << std::endl;
		}
	}
	else {
		std::cout << "Vous n'avez pas cette Arme " << std::endl;
	}
}

void EquipBague(Joueur& _perso1) {
	if (_perso1.BatonBuy >= 1) {
		if (_perso1.armeEquipe == true) {
			std::cout << "Vous avez deja une Arme equipe " << std::endl;
		}
		else {

			_perso1.SetArme(Baton);
			_perso1.UpdateStatsJob();
			_perso1.DisplayStat();
			_perso1.armeEquipe = true;
			_perso1.bBagueEquip = true;
			_perso1.BatonBuy -= 1;
			std::cout << "Vous avez equipe cette Arme " << std::endl;
		}
	}
	else {
		std::cout << "Vous n'avez pas cette Arme " << std::endl;
	}
}

void DesEquipLeger(Joueur& _perso1) {
		if (_perso1.armureEquipe == false) {
			std::cout << "Vous n'avez pas d'Armure equipe " << std::endl;
		}
		else {

			_perso1.SetArmure(NoneA);
			_perso1.UpdateStatsJob();
			_perso1.DisplayStat();
			_perso1.armureEquipe = false;
			_perso1.bLegerEquip = false;
			_perso1.LegerBuy += 1;
			std::cout << "Vous avez desequipe cette Armure " << std::endl;
		}
}

void DesEquipLourd(Joueur& _perso1) {
		if (_perso1.armureEquipe == false) {
			std::cout << "Vous n'avez pas d'Armure equipe " << std::endl;
		}
		else {

			_perso1.SetArmure(NoneA);
			_perso1.UpdateStatsJob();
			_perso1.DisplayStat();
			_perso1.armureEquipe = false;
			_perso1.bLourdEquip = false;
			_perso1.LourdBuy += 1;
			std::cout << "Vous avez desequipe cette Armure " << std::endl;
		}
}

void DesEquipBouclier(Joueur& _perso1) {
		if (_perso1.armureEquipe == false) {
			std::cout << "Vous n'avez pas d'Armure equipe " << std::endl;
		}
		else {

			_perso1.SetArmure(NoneA);
			_perso1.UpdateStatsJob();
			_perso1.DisplayStat();
			_perso1.armureEquipe = false;
			_perso1.bBouclierEquip = false;
			_perso1.BouclierBuy += 1;
			std::cout << "Vous avez desequipe cette Armure " << std::endl;
		}
}

void DesEquipEpee(Joueur& _perso1) {
		if (_perso1.armeEquipe == false) {
			std::cout << "Vous n'avez pas d'Arme equipe " << std::endl;
		}
		else {

			_perso1.SetArme(None);
			_perso1.UpdateStatsJob();
			_perso1.DisplayStat();
			_perso1.armeEquipe = false;
			_perso1.bEpeeEquip = false;
			_perso1.EpeeBuy += 1;
			std::cout << "Vous avez desequipe cette Arme " << std::endl;
		}
}

void DesEquipLance(Joueur& _perso1) {
		if (_perso1.armeEquipe == false) {
			std::cout << "Vous n'avez pas d'Arme equipe " << std::endl;
		}
		else {

			_perso1.SetArme(None);
			_perso1.UpdateStatsJob();
			_perso1.DisplayStat();
			_perso1.armeEquipe = false;
			_perso1.bLanceEquip = false;
			_perso1.LanceBuy += 1;
			std::cout << "Vous avez desequipe cette Arme " << std::endl;
		}
}

void DesEquipBague(Joueur& _perso1) {
		if (_perso1.armeEquipe == false) {
			std::cout << "Vous n'avez pas d'Arme equipe " << std::endl;
		}
		else {

			_perso1.SetArme(None);
			_perso1.UpdateStatsJob();
			_perso1.DisplayStat();
			_perso1.armeEquipe = false;
			_perso1.bBagueEquip = false;
			_perso1.BatonBuy += 1;
			std::cout << "Vous avez desequipe cette Arme " << std::endl;
		}
}

void AchatArmures(Joueur& _perso1, Armures _armures) {
	if (_perso1.GetTotArgent() >= _armures.GetPrix()) {
		_perso1.SetTotArgent(_perso1.GetTotArgent() - _armures.GetPrix());
		tools::ChoixLangue(tools::GetTrad(), ObtenuObjetTexte, "Vous avez obtenu : " + _armures.GetName(), "You got :" + _armures.GetName());
		tools::ChoixLangue(tools::GetTrad(), ArgentRestantB, "\n\nOr restant : " + std::to_string((int)_perso1.GetTotArgent()), "\n\nGold remaining " + std::to_string((int)_perso1.GetTotArgent()));
		achatReussi = 1;
		ValidReussiB = 1;
		PasArgentReste = 0;
		NonRetourBoutique();
	}
	else {
		achatReussi = 0;
		PasArgentReste = 1;
		NonRetourBoutique();
	}
}

void AchatConsos(Joueur& _perso1, Consos _consos) {
	if (_perso1.GetTotArgent() >= _consos.GetPrix()) {
		_perso1.SetTotArgent(_perso1.GetTotArgent() - _consos.GetPrix());
		tools::ChoixLangue(tools::GetTrad(), ObtenuObjetTexte, "Vous avez obtenu : " + _consos.GetName(), "You got :" + _consos.GetName());
		tools::ChoixLangue(tools::GetTrad(), ArgentRestantB, "\n\nOr restant : " + std::to_string((int)_perso1.GetTotArgent()), "\n\nGold remaining " + std::to_string((int)_perso1.GetTotArgent()));
		achatReussi = 1;
		ValidReussiB = 1;
		PasArgentReste = 0;
		NonRetourBoutique();
	}
	else {
		PasArgentReste = 1;
		achatReussi = 0;
		NonRetourBoutique();
	}
}

void validationShop(myWindow& _window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		OuiTexte.setScale(2, 2);
		NonTexte.setScale(1, 1);
		OuiNon = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		OuiTexte.setScale(1, 1);
		NonTexte.setScale(2, 2);
		OuiNon = 2;
	}
}

void displayValidation(myWindow& _window) {

	if (OuiNon == 3) {
		OuiTexte.setScale(1, 1);
		NonTexte.setScale(1, 1);
	}
	_window.Draw(ValidationShop );
	_window.Draw(OuiTexte);
	_window.Draw(NonTexte);
}

void displayBoutique(myWindow& _window, Joueur& _perso1) {


	//_window.Draw(ShopPNJshape);
	//_window.Draw(ShopEpeeShape);
	//_window.Draw(ShopLanceShape);
	//_window.Draw(ShopBatonShape);
	//		
	//_window.Draw(ShopBouclierShape);
	//_window.Draw(ShopLourdShape);
	//_window.Draw(ShopLegerShape);
	//		
	//_window.Draw(ShopPotionPVShape);
	//_window.Draw(ShopPotionMShape);
	//_window.Draw(ShopBombeShape);

	tools::ChoixLangue(tools::GetTrad(), ValidationShop, ValidationAchat + stNomObjet, ValidationAchatEn + stNomObjetEn);
	if (Valid == 1 || PasArgentReste == 1 || ValidReussiB == 1)	{
		boiteDiscussion::displayBoiteDiscussion(_window);
		boiteDiscussion::setBoolDiscu(true);
	}
	else
	{
		boiteDiscussion::setBoolDiscu(false);
	}
	if (Valid == 1) {
		displayValidation(_window);
	}
	if (PasArgentReste == 1) {
		timerPasArgent += tools::GetTimeDelta();
		_window.Draw(PasArgentShop);
		if (timerPasArgent >= 1.0f) {
			timerPasArgent = 0.0f;
			PasArgentReste = 0;
		}
	}
	if (ValidReussiB == 1) {
		timerReussiB += tools::GetTimeDelta();
		_window.Draw(ObtenuObjetTexte);
		_window.Draw(ArgentRestantB);
		if (timerReussiB >= 1.0f) {
			timerReussiB = 0.0f;
			ValidReussiB = 0;
		}
	}
	Vendeur(_window);
}

void Vendeur(myWindow& _window) {
	if (pnjAcceuil == 1) {
		boiteDiscussion::displayBoiteDiscussion(_window);
		_window.Draw(txVendeur);
	}
}
