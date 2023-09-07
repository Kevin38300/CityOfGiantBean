#pragma once
#include "stateManager.h"

namespace Sauvegarde
{
	void SaveGame(std::string _pseudo, int _choixSexe, int _choixMap);
	void LoadGame();
}