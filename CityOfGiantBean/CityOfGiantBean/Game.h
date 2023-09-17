#pragma once
#include "stateManager.h"


enum class MapGame {
	RDC,
	SAFARIE,
	MONTE,
	AVENTURE,
	SHOP
};

enum class AventureGame {
	ZONE_MAGE,
	ZONE_GUERRIER,
	ZONE_ASSASSIN,
	ZONE_CLERC,
	AVENTURE,
	NONE
};

enum class ModeGame {
	LIBRE,
	AVE,
	LOOT,
	SKILL_TREE,
	QUETE,
	FORGE,
	CHASSE,
	DUEL,
	MENU,
	TUTO
};

enum class ShopGame {
	HOTEL,
	BOUTIQUE,
	ALCHIMIE,
	FONTAINE,
	TAVERNE,
	NONE
};

class Joueur;
class Alchimie;
class MenuGame;
class Game : public State
{
private:
	sf::Texture ttMenu;
	sf::Sprite spMenu;
	sf::Vector2f posTitre, posSouris, posJoueur;
	sf::Vector2i mousePosition;
	float fClickMenu;
	sf::Font fontMenu;

	sf::Text txMTitre;
	sf::Vector2f posMTitre;

	sf::Color _white, _black, _green, _red, _transparent, _blue, _cyan;

	sf::SoundBuffer SonG_wooshBuff, SonG_AktPBuff, SonG_AtkMBuff, SonG_PVpBuff, SonG_PVmBuff, SonG_LvlUpBuff;

	sf::Sound SonG_woosh, SonG_AktP, SonG_AtkM, SonG_PVp, SonG_PVm, SonG_LvlUp;

	sf::Music musiqueGame, musiqueCombatAv, musiqueCombatSa, musiqueShop;

	MapGame mapGame;
	ModeGame modeGame;
	AventureGame aventureGame;
	ShopGame shopGame;

	std::vector<Joueur*> persos;
public:
	Game();
	Game(MapGame _mapGame, ModeGame _modeGame, AventureGame _aventureGame, ShopGame _shopGame, myWindow& _window);
	void init(myWindow& _window) override;
	void update(myWindow& _window) override;
	void updateEvent(myWindow& _window) override;
	void draw(myWindow& _window) override;
	void destroy() override;
	void initSave();
};

