#pragma once
#include "stateManager.h"

namespace Sauvegarde
{
	void SaveGame(std::string _pseudo, int _choixSexe, int _choixMap, int _choixAve, int _choixShop, int _choixMode, int _classe, int _element, int _niveau, int _NbEpee, int _NbLance, int _NbBague, int _NbLourd, int _NbLeger, int _NbBouclier, int _NbPotioPv, int _NbPotionMana, int _NbBombe, int _NbPotionMy,
		int _armeEquipe, int _armureEquipe, int _skill1, int _skill2, int _skill3, int _skill4, int _Xp, int _skillpoint, int _CatchGob, int _CatchLoup, int _CatchOurs, int _catchOrc, int _catchGobOurs, int _catchGobLoup, int _catchOursorc, int _catchLoupRoc, int _NbMonstreBattu, int _NbEnnemiBattu,
		int _NbMonstreCatch, int _NbGob, int _NbLoup, int _NbOurs, int _NbOrc, int _NbPersoBattu, int _NbMag, int _NbGuer, int _NbAss, int _NbClerc, int _iChgElem, int _iChgClass, int _iAchat, int _iFabrique, int _iBossAv, int _NivAventure, int _NivSafarie, int _Cuivre, int _cuire, int _fer, int _fourrure, int _fillet, int _Superfillet, int _Argent);
	void LoadGame();
}