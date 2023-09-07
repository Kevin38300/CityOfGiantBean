#include "Save.h"
#include "Tools.h"

namespace Sauvegarde {

	void Sauvegarde::SaveGame(std::string _pseudo, int _choixSexe, int _choixMap)
	{
		std::fstream Save("..\\Ressources\\Save\\Save.txt", std::ios::out);
		if (!Save.is_open()) {
			std::cout << "Ouvertur imposssible du fichier de sauvegarde" << std::endl;
		}
		else {
			Save << _pseudo << " " << _choixSexe << " " << _choixMap << std::endl;
		}
	}


	void Sauvegarde::LoadGame()
	{
	}
}
