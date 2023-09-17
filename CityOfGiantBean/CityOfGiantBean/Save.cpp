#include "Save.h"
#include "Tools.h"

namespace Sauvegarde {

	void Sauvegarde::SaveGame(std::string _pseudo, int _choixSexe, int _choixMap, int _choixAve, int _choixShop, int _choixMode, int _classe, int _element, int _niveau, int _NbEpee, int _NbLance, int _NbBague, int _NbLourd, int _NbLeger, int _NbBouclier, int _NbPotioPv, int _NbPotionMana, int _NbBombe, int _NbPotionMy,
		int _armeEquipe, int _armureEquipe, int _skill1, int _skill2, int _skill3, int _skill4, int _Xp, int _skillpoint, int _CatchGob, int _CatchLoup, int _CatchOurs, int _catchOrc, int _catchGobOurs, int _catchGobLoup, int _catchOursorc, int _catchLoupRoc, int _NbMonstreBattu, int _NbEnnemiBattu,
		int _NbMonstreCatch, int _NbGob, int _NbLoup, int _NbOurs, int _NbOrc, int _NbPersoBattu, int _NbMag, int _NbGuer, int _NbAss, int _NbClerc, int _iChgElem, int _iChgClass, int _iAchat, int _iFabrique, int _iBossAv, int _NivAventure, int _NivSafarie, int _Cuivre, int _cuire, int _fer, int _fourrure, int _fillet, int _Superfillet, int _Argent)
	{
		std::fstream Save("..\\Ressources\\Save\\Save.txt", std::ios::out);
		if (!Save.is_open()) {
			std::cout << "Ouvertur imposssible du fichier de sauvegarde" << std::endl;
		}
		else {
			Save << _pseudo << " " << _choixSexe << " " << _choixMap << " " << _choixAve << " " << _choixShop << " " << _choixMode << " " << _classe << " " << _element << " " << _niveau << " " << _NbEpee << " " << _NbLance << " " << _NbBague
				<< " " << _NbLourd << " " << _NbLeger << " " << _NbBouclier << " " << _NbPotioPv << " " << _NbPotionMana << " " << _NbBombe<< " " << _NbPotionMy << " " << _armeEquipe << " " << _armureEquipe << " " << _skill1 << " " <<_skill2 << " " << 
				_skill3 << " " << _skill4 << " " << _Xp << " " << _skillpoint << " " << _CatchGob << " " << _CatchLoup << " " << _CatchOurs << " " << _catchOrc << " " << _catchGobOurs << " " << _catchGobLoup << " " << _catchOursorc << " " << 
				_catchLoupRoc << " " << _NbMonstreBattu << " " << _NbEnnemiBattu << " " << _NbMonstreCatch << " " << _NbGob << " " << _NbLoup << " " << _NbOurs << " " << _NbOrc << " " << _NbPersoBattu << " " << _NbMag << " " << _NbGuer << " " << 
				_NbAss << " " << _NbClerc << " " << _iChgElem << " " << _iChgClass << " " << _iAchat << " " << _iFabrique << " " << _iBossAv << " " << _NivAventure << " " << _NivSafarie << " " << _Cuivre << " " << _cuire << " " << _fer << " " << _fourrure << " " << _fillet << " " << _Superfillet << " " << _Argent << std::endl;
		}
	}


	void Sauvegarde::LoadGame()
	{
		std::string tmp_pseudo;
		int tmp_choixSexe, tmp_choixMap, tmp_choixAve, tmp_choixShop, tmp_choixMode, tmp_classe, tmp_element, tmp_niveau, tmp_NbEpee, tmp_NbLance, tmp_NbBague, tmp_NbLourd, tmp_NbLeger, tmp_NbBouclier, tmp_NbPotioPv, tmp_NbPotionMana, tmp_NbBombe, tmp_NbPotionMy,
			tmp_armeEquipe, tmp_armureEquipe, tmp_skill1, tmp_skill2, tmp_skill3, tmp_skill4, tmp_Xp, tmp_skillpoint, tmp_CatchGob, tmp_CatchLoup, tmp_CatchOurs, tmp_catchOrc, tmp_catchGobOurs, tmp_catchGobLoup, tmp_catchOursorc, tmp_catchLoupRoc, tmp_NbMonstreBattu, tmp_NbEnnemiBattu,
			tmp_NbMonstreCatch, tmp_NbGob, tmp_NbLoup, tmp_NbOurs, tmp_NbOrc, tmp_NbPersoBattu, tmp_NbMag, tmp_NbGuer, tmp_NbAss, tmp_NbClerc, tmp_iChgElem, tmp_iChgClass, tmp_iAchat, tmp_iFabrique, tmp_iBossAv, tmp_NivAventure, tmp_NivSafarie, tmp_Cuivre, tmp_cuire, tmp_fer, tmp_fourrure, tmp_fillet, tmp_Superfillet, tmp_argent;

		std::fstream Save("..\\Ressources\\Save\\Save.txt", std::ios::in);
		if (!Save.is_open()) {
			std::cout << "Ouvertur imposssible du fichier de sauvegarde" << std::endl;
		}
		else {
			Save >> tmp_pseudo >> tmp_choixSexe >> tmp_choixMap >> tmp_choixAve >> tmp_choixShop >> tmp_choixMode >> tmp_classe >> tmp_element >> tmp_niveau >> tmp_NbEpee >> tmp_NbLance >> tmp_NbBague >> tmp_NbLourd >> tmp_NbLeger >> tmp_NbBouclier >> tmp_NbPotioPv >> tmp_NbPotionMana >> tmp_NbBombe >>
				tmp_NbPotionMy >> tmp_armeEquipe >> tmp_armureEquipe >> tmp_skill1 >> tmp_skill2 >> tmp_skill3 >> tmp_skill4 >> tmp_Xp >> tmp_skillpoint >> tmp_CatchGob >> tmp_CatchLoup >> tmp_CatchOurs >> tmp_catchOrc >> tmp_catchGobOurs >> tmp_catchGobLoup >> tmp_catchOursorc >> tmp_catchLoupRoc >> 
				tmp_NbMonstreBattu >> tmp_NbEnnemiBattu >> tmp_NbMonstreCatch >> tmp_NbGob >> tmp_NbLoup >> tmp_NbOurs >> tmp_NbOrc >> tmp_NbPersoBattu >> tmp_NbMag >> tmp_NbGuer >> tmp_NbAss >> tmp_NbClerc >> tmp_iChgElem >> tmp_iChgClass >> tmp_iAchat >> tmp_iFabrique >> tmp_iBossAv >> tmp_NivAventure >>
				tmp_NivSafarie >> tmp_Cuivre >> tmp_cuire >> tmp_fer >> tmp_fourrure >> tmp_fillet >> tmp_Superfillet >> tmp_argent;

			save::setpseudo1(tmp_pseudo);
			save::setSexe(tmp_choixSexe);

			save::setMap(tmp_choixMap);
			save::setAventure(tmp_choixAve);
			save::setShop(tmp_choixShop);
			save::setMode(tmp_choixMode);

			save::setClasse(tmp_classe);
			save::setElement(tmp_element);

			save::setNiveau(tmp_niveau);
			save::setNbEpee(tmp_NbEpee);
			save::setNbLance(tmp_NbLance);
			save::setNbBague(tmp_NbBague);
			save::setNbLourd(tmp_NbLourd);
			save::setNbLeger(tmp_NbLeger);
			save::setNbBouclier(tmp_NbBouclier);
			save::setNbPotionPv(tmp_NbPotioPv);
			save::setNbPotionMana(tmp_NbPotionMana);
			save::setNbBombe(tmp_NbBombe);
			save::setNbPotionMy(tmp_NbPotionMy);

			save::setArmeEquipe(tmp_armeEquipe);
			save::setArmureEquipe(tmp_armureEquipe);

			save::setSkill1(tmp_skill1);
			save::setSkill2(tmp_skill2);
			save::setSkill3(tmp_skill3);
			save::setSkill4(tmp_skill4);
			save::setXp(tmp_Xp);
			save::setSkillpoint(tmp_skillpoint);

			save::setCatchGob(tmp_CatchGob);
			save::setCatchLoup(tmp_CatchLoup);
			save::setCatchOurs(tmp_CatchOurs);
			save::setCatchOrc(tmp_catchOrc);
			save::setCatchGobOurs(tmp_catchGobOurs);
			save::setCatchGobLoup(tmp_catchGobLoup);
			save::setCatchOursOrc(tmp_catchOursorc);
			save::setCatchLoupRoc(tmp_catchLoupRoc);

			save::setNbMonstreBattu(tmp_NbMonstreBattu);
			save::setNbEnnemiBattu(tmp_NbEnnemiBattu);
			save::setNbMonstreCatch(tmp_NbMonstreCatch);

			save::setNbGob(tmp_NbGob);
			save::setNbLoup(tmp_NbLoup);
			save::setNbOurs(tmp_NbOurs);
			save::setNbOrc(tmp_NbOrc);

			save::setNbPersoBattu(tmp_NbPersoBattu);

			save::setNbMag(tmp_NbMag);
			save::setNbGuer(tmp_NbGuer);
			save::setNbAss(tmp_NbAss);
			save::setNbClerc(tmp_NbClerc);

			save::setChgElement(tmp_iChgElem);
			save::setChgClass(tmp_iChgClass);

			save::setIAchat(tmp_iAchat);
			save::setIFabrique(tmp_iFabrique);
			save::setIBossAv(tmp_iBossAv);
			save::setNivAventure(tmp_NivAventure);
			save::setNivSafarie(tmp_NivSafarie);

			save::setcuivre(tmp_Cuivre);
			save::setcuire(tmp_cuire);
			save::setfer(tmp_fer);
			save::setFourrure(tmp_fourrure);

			save::setfillet(tmp_fillet);
			save::setsuperfillet(tmp_Superfillet);

			save::setArgent(tmp_argent);
		}

	}
}
