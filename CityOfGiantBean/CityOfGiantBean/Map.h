#pragma once
#include "Game.h"

void initCarte();
void updateCarte(myWindow& _window, MapGame& _map, ShopGame& _shop, AventureGame& _aventure, ModeGame& _mode, sf::Vector2f _posPerso);
void displayCarte(myWindow& _window, MapGame& _map, ShopGame& _shop, AventureGame& _aventure, ModeGame& _mode);
