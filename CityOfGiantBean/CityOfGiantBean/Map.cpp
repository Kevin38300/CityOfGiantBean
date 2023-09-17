#include "Map.h"

sf::Texture ttVillage;
sf::Sprite spVillage;

///////////////////////////// Shop
sf::Texture ttShop;
sf::Sprite spShop;
sf::Vector2f ShopSize, ShopPos, ShopSizeT, ShopPosT;
sf::RectangleShape ShopShape;

///////////////////////////// Taverne
sf::Texture ttTaverne;
sf::Sprite spTaverne;
sf::Vector2f tavernePos, taverneSize, tavernePosT, taverneSizeT;
sf::RectangleShape taverneShape;

///////////////////////////// Fontaine
sf::Texture ttFontaine;
sf::Sprite spFontaine;
sf::Vector2f fontainePos, fontaineSize, fontainePosF, fontaineSizeF;
sf::RectangleShape fontaineShape, fontaineShapeF;

///////////////////////////// Alchime
sf::Texture ttAlchimie, ttForge;
sf::Sprite spAlchimie, spForge;
sf::Vector2f AlchimiePos, AlchimieSize, AlchimiePosA, AlchimieSizeA;
sf::RectangleShape AlchimieShape, AlchimieShapeA;

///////////////////////////// Tower


///////////////////////////// Hotel
sf::Texture ttHotel, ttQuete, ttSkillTree;
sf::Sprite spHotel, spQuete, spSkillTree;
sf::Vector2f hotelPos, hotelSize, hotelPosH, hotelSizeH;
sf::RectangleShape hotelShape;

///////////////////////////// GiantJack
sf::Texture ttGiantJack;
sf::Sprite spGiantJack;
sf::Vector2f GiantJackPos, GiantJackSize, GiantJackPosAv, GiantJackSizeAv;
sf::RectangleShape GiantJackShape, GiantJackShapeAv;

///////////////////////////// Aventure
sf::Texture ttAventure, ttAventureCombat;
sf::Sprite spAventure, spAventureCombat;
sf::Vector2f AventurePos, AventureSize;
sf::RectangleShape AventureShape;

///////////////////////////// Safari

sf::Texture ttSafari, ttSafariCombat;
sf::Sprite spSafari, spSafariCombat;
sf::Vector2f SafariPos, SafariSize, SafariSPos, SafariSSize;
sf::RectangleShape SafariShape, SafariSShape;


sf::Text txQuelEtage, txVille, txAventure, txAventureMage, txAventureGuerrier, txAventureAss, txAventureClerc;
sf::Vector2f posQuelEtage, posVille, posAventure, posAventureMage, posAventureGuerrier, posAventureAss, posAventureClerc;
sf::Font fontMenu;
sf::Vector2f posSouris;
sf::Vector2i mousePosition;
float fClickMenu;

extern float timerAff;
void initCarte()
{
	fontMenu.loadFromFile("../Ressources/Fonts/YOZAKURA-Regular.otf");
	ttVillage.loadFromFile("..\\Ressources\\Textures\\LIEUX\\MerDeNuageRDC.png");
	spVillage.setTexture(ttVillage);

	///////////////////////////// Shop
	ttShop.loadFromFile("..\\Ressources\\Textures\\LIEUX\\Shop.png");
	spShop.setTexture(ttShop);

	ShopSize = { AjustResoX * 205,AjustResoY * 230 };
	ShopSizeT = { AjustResoX * 150,AjustResoY * 190 };
	ShopPos = { AjustResoX * 295,AjustResoY * 520 };
	ShopPosT = { AjustResoX * 870,AjustResoY * 885 };
	ShopShape.setFillColor(sf::Color::Red);

	///////////////////////////// Taverne
	ttTaverne.loadFromFile("..\\Ressources\\Textures\\LIEUX\\Taverne.png");
	spTaverne.setTexture(ttTaverne);

	taverneSize = { AjustResoX * 220,AjustResoY * 195 };
	taverneSizeT = { AjustResoX * 150,AjustResoY * 190 };
	tavernePos = { AjustResoX * 1430,AjustResoY * 535 };
	tavernePosT = { AjustResoX * 870,AjustResoY * 885 };
	taverneShape.setFillColor(sf::Color::Cyan);

	///////////////////////////// Fontaine
	ttFontaine.loadFromFile("..\\Ressources\\Textures\\LIEUX\\Fontaine.png");
	spFontaine.setTexture(ttFontaine);

	fontaineSize = { AjustResoX * 118,AjustResoY * 80 };
	fontainePos = { AjustResoX * 1177,AjustResoY * 890 };
	fontaineShape.setSize(fontaineSize);
	fontaineShape.setPosition(fontainePos);
	fontaineShape.setFillColor(sf::Color::Yellow);

	fontaineSizeF = { AjustResoX * 111,AjustResoY * 154 };
	fontainePosF = { AjustResoX * 843,AjustResoY * 2 };
	fontaineShapeF.setSize(fontaineSizeF);
	fontaineShapeF.setPosition(fontainePosF);
	fontaineShapeF.setFillColor(sf::Color::Yellow);

	///////////////////////////// Alchime

	ttAlchimie.loadFromFile("..\\Ressources\\Textures\\LIEUX\\Alchimie.png");
	spAlchimie.setTexture(ttAlchimie);

	ttForge.loadFromFile("..\\Ressources\\Textures\\MENU\\MenuAlchimie.png");
	spForge.setTexture(ttForge);

	AlchimieSize = { AjustResoX * 253,AjustResoY * 190 };
	AlchimiePos = { AjustResoX * 637,AjustResoY * 795 };
	AlchimieShape.setSize(AlchimieSize);
	AlchimieShape.setPosition(AlchimiePos);
	AlchimieShape.setFillColor(sf::Color::Cyan);

	AlchimieSizeA = { AjustResoX * 134,AjustResoY * 84 };
	AlchimiePosA = { AjustResoX * 1160,AjustResoY * 986 };
	AlchimieShapeA.setSize(AlchimieSizeA);
	AlchimieShapeA.setPosition(AlchimiePosA);
	AlchimieShapeA.setFillColor(sf::Color::Cyan);


	///////////////////////////// Tower


	///////////////////////////// Hotel
	ttHotel.loadFromFile("..\\Ressources\\Textures\\LIEUX\\Hotel.png");
	spHotel.setTexture(ttHotel);

	ttSkillTree.loadFromFile("..\\Ressources\\Textures\\MENU\\SkillTree.png");
	spSkillTree.setTexture(ttSkillTree);

	ttQuete.loadFromFile("..\\Ressources\\Textures\\MENU\\MenuQuete.png");
	spQuete.setTexture(ttQuete);

	hotelSize = { AjustResoX * 291,AjustResoY * 150 };
	hotelPos = { AjustResoX * 355,AjustResoY * 205 };
	hotelSizeH = { AjustResoX * 150,AjustResoY * 190 };
	hotelPosH = { AjustResoX * 870,AjustResoY * 885 };
	hotelShape.setFillColor(sf::Color::Cyan);

	///////////////////////////// GiantJack
	ttGiantJack.loadFromFile("..\\Ressources\\Textures\\LIEUX\\MonteEtage.png");
	spGiantJack.setTexture(ttGiantJack);

	GiantJackSize = { AjustResoX * 135,AjustResoY * 155 };
	GiantJackPos = { AjustResoX * 880,AjustResoY * 280 };
	GiantJackShape.setSize(GiantJackSize);
	GiantJackShape.setPosition(GiantJackPos);
	GiantJackShape.setFillColor(sf::Color::Red);

	GiantJackSizeAv = { AjustResoX * 154,AjustResoY * 206 };
	GiantJackPosAv = { AjustResoX * 1000,AjustResoY * 317 };
	GiantJackShapeAv.setSize(GiantJackSizeAv);
	GiantJackShapeAv.setPosition(GiantJackPosAv);
	GiantJackShapeAv.setFillColor(sf::Color::Red);


	posQuelEtage = sf::Vector2f(AjustResoX * 130.0f, AjustResoY * 850.0f);
	posVille = sf::Vector2f(AjustResoX * 130.0f, AjustResoY * 900.0f);
	posAventure = sf::Vector2f(AjustResoX * 250.0f, AjustResoY * 900.0f);
	posAventureMage = sf::Vector2f(AjustResoX * 450.0f, AjustResoY * 900.0f);
	posAventureGuerrier = sf::Vector2f(AjustResoX * 650.0f, AjustResoY * 900.0f);
	posAventureAss = sf::Vector2f(AjustResoX * 850.0f, AjustResoY * 900.0f);
	posAventureClerc = sf::Vector2f(AjustResoX * 1050.0f, AjustResoY * 900.0f);

	txQuelEtage.setFont(fontMenu);
	txQuelEtage.setFillColor(sf::Color::Black);
	txQuelEtage.setPosition(posQuelEtage);
	txQuelEtage.setCharacterSize(40);

	txVille.setFont(fontMenu);
	txVille.setFillColor(sf::Color::Red);
	txVille.setPosition(posVille);
	txVille.setCharacterSize(40);

	txAventure.setFont(fontMenu);
	txAventure.setFillColor(sf::Color::Red);
	txAventure.setPosition(posAventure);
	txAventure.setCharacterSize(40);

	txAventureClerc.setFont(fontMenu);
	txAventureClerc.setFillColor(sf::Color::Red);
	txAventureClerc.setPosition(posAventureClerc);
	txAventureClerc.setCharacterSize(40);

	txAventureMage.setFont(fontMenu);
	txAventureMage.setFillColor(sf::Color::Red);
	txAventureMage.setPosition(posAventureMage);
	txAventureMage.setCharacterSize(40);

	txAventureGuerrier.setFont(fontMenu);
	txAventureGuerrier.setFillColor(sf::Color::Red);
	txAventureGuerrier.setPosition(posAventureGuerrier);
	txAventureGuerrier.setCharacterSize(40);

	txAventureAss.setFont(fontMenu);
	txAventureAss.setFillColor(sf::Color::Red);
	txAventureAss.setPosition(posAventureAss);
	txAventureAss.setCharacterSize(40);

	///////////////////////////// Aventure
	ttAventure.loadFromFile("..\\Ressources\\Textures\\LIEUX\\MerDeNuageAventure.png");
	spAventure.setTexture(ttAventure);
	ttAventureCombat.loadFromFile("..\\Ressources\\Textures\\LIEUX\\AventureCombat.png");
	spAventureCombat.setTexture(ttAventureCombat);

	AventureSize = { AjustResoX * 135,AjustResoY * 155 };
	AventurePos = { AjustResoX * 880,AjustResoY * 280 };
	AventureShape.setSize(AventureSize);
	AventureShape.setPosition(AventurePos);
	AventureShape.setFillColor(sf::Color::Red);

	///////////////////////////// Safari

	ttSafari.loadFromFile("..\\Ressources\\Textures\\LIEUX\\MerDeNuageSafarie.png");
	spSafari.setTexture(ttSafari);

	ttSafariCombat.loadFromFile("..\\Ressources\\Textures\\LIEUX\\SafarieCombat.png");
	spSafariCombat.setTexture(ttSafariCombat);

	SafariSize = { AjustResoX * 185,AjustResoX * 70 };
	SafariSSize = { AjustResoX * 160,AjustResoY * 133 };
	SafariPos = { AjustResoX * 1675,AjustResoY * 130 };
	SafariSPos = { AjustResoX * 57,AjustResoY * 893 };
	SafariShape.setSize(SafariSize);
	SafariShape.setPosition(SafariPos);
	SafariShape.setFillColor(sf::Color::Red);

	fClickMenu = 0.0f;
	boiteDiscussion::initBoiteDiscussion();
}
void updateCarte(myWindow& _window, MapGame& _map, ShopGame& _shop, AventureGame& _aventure, ModeGame& _mode, sf::Vector2f& _posPerso) {
	mousePosition = sf::Mouse::getPosition(_window.getRenderWindow());
	posSouris = _window.getRenderWindow().mapPixelToCoords(mousePosition);
	fClickMenu += tools::GetTimeDelta();

	//if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && fClickMenu > 0.3f)
	//{
	//	std::cout << posSouris.x << " && " << posSouris.y << std::endl;
	//	fClickMenu = 0.0f;
	//}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f)
	{
		if (_map == MapGame::RDC) {
			if (_shop == ShopGame::NONE) {
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, hotelPos, hotelSize) && (save::getTutoNb() == 2 || save::getTutoNb() == 6 || save::getTuto() == false)) {
					_posPerso = hotelPosH;
					tools::SetFirstInM(false);
					_map = MapGame::SHOP;
					_shop = ShopGame::HOTEL;
					fClickMenu = 0.0f;
					timerAff = 0.0f;
					return;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, ShopPos, ShopSize) && (save::getTutoNb() == 4 || save::getTutoNb() == 5 || save::getTuto() == false)) {
					_map = MapGame::SHOP;
					_shop = ShopGame::BOUTIQUE;
					tools::SetFirstInM(false);
					_posPerso = ShopPosT;
					fClickMenu = 0.0f;
					timerAff = 0.0f;
					return;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, AlchimiePos, AlchimieSize) && (save::getTutoNb() >= 10 || save::getTuto() == false)) {
					_map = MapGame::SHOP;
					_shop = ShopGame::ALCHIMIE;
					tools::SetFirstInM(false);
					_posPerso = AlchimiePosA;
					fClickMenu = 0.0f;
					timerAff = 0.0f;
					return;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, fontainePos, fontaineSize) && (save::getTutoNb() == 9 || save::getTuto() == false)) {
					_map = MapGame::SHOP;
					_shop = ShopGame::FONTAINE;
					tools::SetFirstInM(false);
					_posPerso = fontainePos;
					fClickMenu = 0.0f;
					timerAff = 0.0f;
					return;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, tavernePos, taverneSize) && (save::getTutoNb() == 8 || save::getTuto() == false)) {
					_map = MapGame::SHOP;
					_shop = ShopGame::TAVERNE;
					tools::SetFirstInM(false);
					_posPerso = tavernePosT;
					fClickMenu = 0.0f;
					timerAff = 0.0f;
					return;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, SafariPos, SafariSize) && (save::getTutoNb() == 3 || save::getTutoNb() == 5 || save::getTuto() == false)) {
					_map = MapGame::SAFARIE;
					tools::SetFirstInM(false);
					_posPerso = SafariSPos;
					fClickMenu = 0.0f;
					timerAff = 0.0f;
					return;
				}
				if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, GiantJackPos, GiantJackSize) && (save::getTutoNb() == 7 || save::getTuto() == false)) {
					_map = MapGame::MONTE;
					fClickMenu = 0.0f;
					timerAff = 0.0f;
					return;
				}
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fClickMenu > 0.3f) {
		if (_map == MapGame::SHOP) {
			if (tools::CircleRect_Collision(_posPerso, AjustResoX * 10.0f, hotelPosH, hotelSizeH) && _shop == ShopGame::HOTEL) {
				if (save::getTutoNb() == 2)
					save::setTutoNb(3);
				if (save::getTutoNb() == 6)
					save::setTutoNb(7);
				_map = MapGame::RDC;
				_shop = ShopGame::NONE;
				tools::SetFirstInM(false);
				fClickMenu = 0.0f;
				timerAff = 0.0f;
				return;
			}
			if (tools::CircleRect_Collision(_posPerso, AjustResoX * 10.0f, ShopPosT, ShopSizeT) && _shop == ShopGame::BOUTIQUE) {
				_map = MapGame::RDC;
				_shop = ShopGame::NONE;
				tools::SetFirstInM(false);
				fClickMenu = 0.0f;
				timerAff = 0.0f;
				return;
			}
			if (tools::CircleRect_Collision(_posPerso, AjustResoX * 10.0f, AlchimiePosA, AlchimieSizeA) && _shop == ShopGame::ALCHIMIE) {
				_map = MapGame::RDC;
				_shop = ShopGame::NONE;
				tools::SetFirstInM(false);
				fClickMenu = 0.0f;
				timerAff = 0.0f;
				return;
			}
			if (tools::CircleRect_Collision(_posPerso, AjustResoX * 10.0f, fontainePosF, fontaineSizeF) && _shop == ShopGame::FONTAINE) {
				_map = MapGame::RDC;
				_shop = ShopGame::NONE;
				tools::SetFirstInM(false);
				fClickMenu = 0.0f;
				timerAff = 0.0f;
				if (save::getTutoNb() == 10)
					save::setTutoNb(11);
				return;
			}
			if (tools::CircleRect_Collision(_posPerso, AjustResoX * 10.0f, tavernePosT, taverneSizeT) && _shop == ShopGame::TAVERNE) {
				_map = MapGame::RDC;
				_shop = ShopGame::NONE;
				tools::SetFirstInM(false);
				fClickMenu = 0.0f;
				timerAff = 0.0f;
				return;
			}
		}
		if (_map == MapGame::SAFARIE) {
			if (tools::CircleRect_Collision(_posPerso, AjustResoX * 10.0f, SafariSPos, SafariSSize)) {
				_map = MapGame::RDC;
				tools::SetFirstInM(false);
				fClickMenu = 0.0f;
				timerAff = 0.0f;
				return;
			}
		}
	}
	if (_map == MapGame::MONTE) {

		if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posVille.x, posVille.y + txVille.getGlobalBounds().height), sf::Vector2f(txVille.getGlobalBounds().width, txVille.getGlobalBounds().height))) {
			txVille.setCharacterSize(45);
			posVille = sf::Vector2f(AjustResoX * 125.0f, AjustResoY * 900.0f);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
				_map = MapGame::RDC;
				_aventure = AventureGame::NONE;
				tools::SetFirstInM(false);
				fClickMenu = 0.0f;
				timerAff = 0.0f;
				return;
			}
		}
		else {
			txVille.setCharacterSize(40);
			posVille = sf::Vector2f(AjustResoX * 130.0f, AjustResoY * 900.0f);
		}
		if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posAventure.x, posAventure.y + txAventure.getGlobalBounds().height), sf::Vector2f(txAventure.getGlobalBounds().width, txAventure.getGlobalBounds().height)) && (save::getTutoNb() == 7 || save::getTuto() == false)) {
			txAventure.setCharacterSize(45);
			posAventure = sf::Vector2f(AjustResoX * 245.0f, AjustResoY * 900.0f);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
				_map = MapGame::AVENTURE;
				_aventure = AventureGame::AVENTURE;
				tools::SetFirstInM(false);
				_posPerso = GiantJackPosAv;
				fClickMenu = 0.0f;
				timerAff = 0.0f;
				return;
			}
		}
		else {
			txAventure.setCharacterSize(40);
			posAventure = sf::Vector2f(AjustResoX * 250.0f, AjustResoY * 900.0f);
		}
		if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posAventureGuerrier.x, posAventureGuerrier.y + txAventureGuerrier.getGlobalBounds().height), sf::Vector2f(txAventureGuerrier.getGlobalBounds().width, txAventureGuerrier.getGlobalBounds().height)) && (save::getTutoNb() >= 10 || save::getTuto() == false)) {
			txAventureGuerrier.setCharacterSize(45);
			posAventureGuerrier = sf::Vector2f(AjustResoX * 645.0f, AjustResoY * 900.0f);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
				_map = MapGame::AVENTURE;
				_aventure = AventureGame::ZONE_GUERRIER;
				tools::SetFirstInM(false);
				_posPerso = GiantJackPosAv;
				fClickMenu = 0.0f;
				return;
			}
		}
		else {
			txAventureGuerrier.setCharacterSize(40);
			posAventureGuerrier = sf::Vector2f(AjustResoX * 650.0f, AjustResoY * 900.0f);
		}
		if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posAventureClerc.x, posAventureClerc.y + txAventureClerc.getGlobalBounds().height), sf::Vector2f(txAventureClerc.getGlobalBounds().width, txAventureClerc.getGlobalBounds().height)) && (save::getTutoNb() >= 10 || save::getTuto() == false)) {
			txAventureClerc.setCharacterSize(45);
			posAventureClerc = sf::Vector2f(AjustResoX * 1045.0f, AjustResoY * 900.0f);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
				_map = MapGame::AVENTURE;
				_aventure = AventureGame::ZONE_CLERC;
				tools::SetFirstInM(false);
				_posPerso = GiantJackPosAv;
				fClickMenu = 0.0f;
				return;
			}
		}
		else {
			txAventureClerc.setCharacterSize(40);
			posAventureClerc = sf::Vector2f(AjustResoX * 1050.0f, AjustResoY * 900.0f);
		}
		if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posAventureMage.x, posAventureMage.y + txAventureMage.getGlobalBounds().height), sf::Vector2f(txAventureMage.getGlobalBounds().width, txAventureMage.getGlobalBounds().height)) && (save::getTutoNb() >= 10 || save::getTuto() == false)) {
			txAventureMage.setCharacterSize(45);
			posAventureMage = sf::Vector2f(AjustResoX * 445.0f, AjustResoY * 900.0f);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
				_map = MapGame::AVENTURE;
				_aventure = AventureGame::ZONE_MAGE;
				tools::SetFirstInM(false);
				_posPerso = GiantJackPosAv;
				fClickMenu = 0.0f;
				return;
			}
		}
		else {
			txAventureMage.setCharacterSize(40);
			posAventureMage = sf::Vector2f(AjustResoX * 450.0f, AjustResoY * 900.0f);
		}
		if (tools::CircleRect_Collision(posSouris, AjustResoX * 10.0f, sf::Vector2f(posAventureAss.x, posAventureAss.y + txAventureAss.getGlobalBounds().height), sf::Vector2f(txAventureAss.getGlobalBounds().width, txAventureAss.getGlobalBounds().height)) && (save::getTutoNb() >= 10 || save::getTuto() == false)) {
			txAventureAss.setCharacterSize(45);
			posAventureAss = sf::Vector2f(AjustResoX * 845.0f, AjustResoY * 900.0f);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fClickMenu > 0.3f) {
				_map = MapGame::AVENTURE;
				_aventure = AventureGame::ZONE_ASSASSIN;
				tools::SetFirstInM(false);
				_posPerso = GiantJackPosAv;
				fClickMenu = 0.0f;
				return;
			}
		}
		else {
			txAventureAss.setCharacterSize(40);
			posAventureAss = sf::Vector2f(AjustResoX * 850.0f, AjustResoY * 900.0f);
		}
		tools::ChoixLangue(tools::GetTrad(), txQuelEtage, "A quel zone voulez vous vous rendre ?", "Which area do you want to go to ?");
		tools::ChoixLangue(tools::GetTrad(), txVille, " Ville ", " Town ");
		tools::ChoixLangue(tools::GetTrad(), txAventure, " Aventure ", " Adventure ");
		tools::ChoixLangue(tools::GetTrad(), txAventureAss, " Zone d'or ", " Gold area ");
		tools::ChoixLangue(tools::GetTrad(), txAventureClerc, " Zone potion ", " Potion area ");
		tools::ChoixLangue(tools::GetTrad(), txAventureGuerrier, " Zone armure ", " Armor area ");
		tools::ChoixLangue(tools::GetTrad(), txAventureMage, " Zone arme ", " Weapon area");
	}
	if (_map == MapGame::AVENTURE) {
		if (_aventure == AventureGame::AVENTURE) {
			if (tools::CircleRect_Collision(_posPerso, AjustResoX * 10.0f, GiantJackPosAv, GiantJackSizeAv) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fClickMenu > 0.3f) {
				_map = MapGame::MONTE;
				fClickMenu = 0.0f;
				return;
			}
		}
		if (_aventure == AventureGame::ZONE_MAGE) {
			if (tools::CircleRect_Collision(_posPerso, AjustResoX * 10.0f, GiantJackPosAv, GiantJackSizeAv) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fClickMenu > 0.3f) {
				_map = MapGame::MONTE;
				fClickMenu = 0.0f;
				return;
			}
		}
		if (_aventure == AventureGame::ZONE_ASSASSIN) {
			if (tools::CircleRect_Collision(_posPerso, AjustResoX * 10.0f, GiantJackPosAv, GiantJackSizeAv) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fClickMenu > 0.3f) {
				_map = MapGame::MONTE;
				fClickMenu = 0.0f;
				return;
			}
		}
		if (_aventure == AventureGame::ZONE_GUERRIER) {
			if (tools::CircleRect_Collision(_posPerso, AjustResoX * 10.0f, GiantJackPosAv, GiantJackSizeAv) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fClickMenu > 0.3f) {
				_map = MapGame::MONTE;
				fClickMenu = 0.0f;
				return;
			}
		}
		if (_aventure == AventureGame::ZONE_CLERC) {
			if (tools::CircleRect_Collision(_posPerso, AjustResoX * 10.0f, GiantJackPosAv, GiantJackSizeAv) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fClickMenu > 0.3f) {
				_map = MapGame::MONTE;
				fClickMenu = 0.0f;
				return;
			}
		}
	}
}
void displayCarte(myWindow& _window, MapGame& _map, ShopGame& _shop, AventureGame& _aventure, ModeGame& _mode) {

	if (_map == MapGame::RDC) {
		_window.Draw(spVillage);
		ShopShape.setPosition(ShopPos);
		ShopShape.setSize(ShopSize);
		//_window.Draw(AlchimieShape);
		//_window.Draw(ShopShape);
		//_window.Draw(fontaineShape);
		//_window.Draw(GiantJackShape);
		hotelShape.setSize(hotelSize);
		hotelShape.setPosition(hotelPos);
		//_window.Draw(hotelShape);
		taverneShape.setPosition(tavernePos);
		taverneShape.setSize(taverneSize);
		//_window.Draw(taverneShape);
		SafariShape.setPosition(SafariPos);
		SafariShape.setSize(SafariSize);
		//_window.Draw(SafariShape);
	}
	if (_map == MapGame::SHOP) {

		if (_shop == ShopGame::ALCHIMIE) {
			if (_mode == ModeGame::LIBRE) {
				_window.Draw(spAlchimie);
				//_window.Draw(AlchimieShapeA);
			}
			if (_mode == ModeGame::FORGE) {
				_window.Draw(spAlchimie);
				_window.Draw(spForge);

			}
		}
		if (_shop == ShopGame::TAVERNE) {
			_window.Draw(spTaverne);
			taverneShape.setPosition(tavernePosT);
			taverneShape.setSize(taverneSizeT);
			//_window.Draw(taverneShape);
		}
		if (_shop == ShopGame::BOUTIQUE) {
			_window.Draw(spShop);
			ShopShape.setPosition(ShopPosT);
			ShopShape.setSize(ShopSizeT);
			//_window.Draw(ShopShape);
		}
		if (_shop == ShopGame::FONTAINE) {
			_window.Draw(spFontaine);
			//_window.Draw(fontaineShapeF);
		}
		if (_shop == ShopGame::HOTEL) {
			if (_mode == ModeGame::LIBRE) {
				hotelShape.setSize(hotelSizeH);
				hotelShape.setPosition(hotelPosH);
				_window.Draw(spHotel);
				//_window.Draw(hotelShape);
			}
			if (_mode == ModeGame::SKILL_TREE) {
				_window.Draw(spSkillTree);

			}
			if (_mode == ModeGame::QUETE) {
				_window.Draw(spQuete);

			}
		}
	}
	if (_map == MapGame::MONTE) {
		_window.Draw(spGiantJack);
		//_window.Draw(GiantJackShape);
		boiteDiscussion::displayBoiteDiscussion(_window);
		_window.Draw(txQuelEtage);
		_window.Draw(txVille);
		_window.Draw(txAventure);
		_window.Draw(txAventureMage);
		_window.Draw(txAventureGuerrier);
		_window.Draw(txAventureAss);
		_window.Draw(txAventureClerc);
	}
	if (_map == MapGame::AVENTURE) {
		_window.Draw(spAventure);
		//_window.Draw(GiantJackShapeAv);
		if (_aventure == AventureGame::AVENTURE) {

		}
		if (_aventure == AventureGame::ZONE_MAGE) {

		}
		if (_aventure == AventureGame::ZONE_ASSASSIN) {

		}
		if (_aventure == AventureGame::ZONE_GUERRIER) {

		}
		if (_aventure == AventureGame::ZONE_CLERC) {

		}
		if (_mode == ModeGame::AVE) {
			_window.Draw(spSafariCombat);

		}
	}
	if (_map == MapGame::SAFARIE) {
		if (_mode == ModeGame::LIBRE) {
			_window.Draw(spSafari);
			SafariShape.setPosition(SafariSPos);
			SafariShape.setSize(SafariSSize);
			//_window.Draw(SafariShape);
		}
		if (_mode == ModeGame::CHASSE) {
			_window.Draw(spSafariCombat);

		}
	}
}
