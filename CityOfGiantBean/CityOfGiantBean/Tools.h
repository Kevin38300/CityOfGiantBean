#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <iostream>
#include "fstream"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <SFML/Window.hpp>
#include <string>
#include "myWindow.h"

#define AjustResoX ((float)GetSystemMetrics(SM_CXFULLSCREEN) / 1920.0f)
#define AjustResoY (((float)GetSystemMetrics(SM_CYFULLSCREEN) + 63) / 1080.0f)
#define AjustReso ((((float)GetSystemMetrics(SM_CYFULLSCREEN) + 63) / 1080.0f + (float)GetSystemMetrics(SM_CXFULLSCREEN) / 1920.0f) / 2 )

namespace boiteDiscussion
{
	void initBoiteDiscussion();
	void displayBoiteDiscussion(myWindow& _window);
	bool getBoolDiscu();
	void setBoolDiscu(bool _bool);
}
namespace save
{
	void setNewPartie(bool _True_New__False_Charge);
	bool GetNew();

	void setTuto(bool _tuto_On_Off);
	bool getTuto();
	void setTutoNb(int _tuto_Nb);
	int getTutoNb();

	void setpseudo1(std::string _string);
	std::string getpseudo1();
	void setSexe(int _choixSexe);
	int getSexe();
	void setMap(int _choixMap);
	int getMap();
	void setAventure(int _choixAve);
	int getAventure();
	void setShop(int _choixShop);
	int getShop();
	void setMode(int _choixMode);
	int getMode();
	void setClasse(int _classe);
	int getClasse();
	void setElement(int _element);
	int getElement();
	void setNiveau(int _niveau);
	int getNiveau();
	void setNbEpee(int _NbEpee);
	int getNbEpee();
	void setNbLance(int _NbLance);
	int getNbLance();
	void setNbBague(int _NbBague);
	int getNbBague();
	void setNbLourd(int _NbLourd);
	int getNbLourd();
	void setNbLeger(int _NbLeger);
	int getNbLeger();
	void setNbBouclier(int _NbBouclier);
	int getNbBouclier();
	void setNbPotionPv(int _NbPotioPv);
	int getNbPotionPv();
	void setNbPotionMana(int _NbPotionMana);
	int getNbPotionMana();
	void setNbBombe(int _NbBombe);
	int getNbBombe();
	void setNbPotionMy(int _NbPotionMy);
	int getNbPotionMy();
	void setArmeEquipe(int _armeEquipe);
	int getArmeEquipe();
	void setArmureEquipe(int _armureEquipe);
	int getArmureEquipe();
	void setSkill1(int _skill1);
	int getSkill1();
	void setSkill2(int _skill2);
	int getSkill2();
	void setSkill3(int _skill3);
	int getSkill3();
	void setSkill4(int _skill4);
	int getSkill4();
	void setXp(int _Xp);
	int getXp();
	void setSkillpoint(int _skillpoint);
	int getSkillpoint();
	void setCatchGob(int _CatchGob);
	int getCatchGob();
	void setCatchLoup(int _CatchLoup);
	int getCatchLoup();
	void setCatchOurs(int _CatchOurs);
	int getCatchOurs();
	void setCatchOrc(int _catchOrc);
	int getCatchOrc();
	void setCatchGobOurs(int _catchGobOurs);
	int getCatchGobOurs();
	void setCatchGobLoup(int _catchGobLoup);
	int getCatchGobLoup();
	void setCatchOursOrc(int _catchOursorc);
	int getCatchOursOrc();
	void setCatchLoupRoc(int _catchLoupRoc);
	int getCatchLoupRoc();
	void setNbMonstreBattu(int _NbMonstreBattu);
	int getNbMonstreBattu();
	void setNbEnnemiBattu(int _NbEnnemiBattu);
	int getNbEnnemiBattu();
	void setNbMonstreCatch(int _NbMonstreCatch);
	int getNbMonstreCatch();
	void setNbGob(int _NbGob);
	int getNbGob();
	void setNbLoup(int _NbLoup);
	int getNbLoup();
	void setNbOurs(int _NbOurs);
	int getNbOurs();
	void setNbOrc(int _NbOrc);
	int getNbOrc();
	void setNbPersoBattu(int _NbPersoBattu);
	int getNbPersoBattu();
	void setNbMag(int _NbMag);
	int getNbMag();
	void setNbGuer(int _NbGuer);
	int getNbGuer();
	void setNbAss(int _NbAss);
	int getNbAss();
	void setNbClerc(int _NbClerc);
	int getNbClerc();
	void setChgElement(int _iChgElem);
	int getChgElement();
	void setChgClass(int _iChgClass);
	int getChgClass();
	void setIAchat(int _iAchat);
	int getIAchat();
	void setIFabrique(int _iFabrique);
	int getIFabrique();
	void setIBossAv(int _iBossAv);
	int getIBossAv();
	void setNivAventure(int _NivAventure);
	int getNivAventure();
	void setNivSafarie(int _NivSafarie);
	int getNivSafarie();
	void setcuivre(int _Cuivre);
	int getcuivre();
	void setcuire(int _cuire);
	int getcuire();
	void setfer(int _fer);
	int getfer();
	void setFourrure(int _fourrure);
	int getFourrure();
	void setfillet(int _fillet);
	int getfillet();
	void setsuperfillet(int _superfillet);
	int getsuperfillet();
	void setArgent(int _argent);
	int getArgent();

}
namespace music
{
	void SetVolSonMusBase(float _floatMusic, float _floatSon);

	void SetVolume(sf::Music& _music);
	void SetSon(sf::Sound& _sound);

	float GetVolumeSon();
	void AddVolumeSon(float _Volume);

	float GetVolumeMusique();
	void AddVolumeMusique(float _Volume);
}
namespace tools
{

	int GetTrad();

	void SetTrad(int _nb);

	int GetChoixMu();

	void SetChoixMu(int _nb);

	bool GetFirstIn();

	void SetFirstIn(bool _bool);

	bool GetFirstInM();

	void SetFirstInM(bool _bool);

	int iRand(int _min, int _max);

	double frand(float _min, float _max);

	void restartClock();

	float GetTimeDelta();

	float lerp(float v0, float v1, float t);

	sf::Vector2f vec2f_lerp(sf::Vector2f v0, sf::Vector2f v1, float t);

	sf::Vector3f vec3f_lerp(sf::Vector3f v0, sf::Vector3f v1, float t);

	sf::Color color_lerp(sf::Color v0, sf::Color v1, float t);

	bool Circle_Collision(sf::Vector2f _pos1, sf::Vector2f _pos2, float _rayon1, float _rayon2);

	bool Rectangle_Collision(sf::FloatRect _box1, sf::FloatRect _box2);

	bool CircleRect_Collision(sf::Vector2f _pos1, float _rayon1, sf::Vector2f _pos2, sf::Vector2f _size2);

	bool circleRect(sf::Vector2f circlePosition, sf::Vector2f rectanglePosition, float rayon, sf::Vector2f rectangleSize);

	void CreateRS(sf::RectangleShape& _rs, sf::Color _color, sf::Vector2f _posRs, sf::Vector2f _sizeRs);

	void CreateRSoutline(sf::RectangleShape& _rs, sf::Color _colorFond, sf::Color _colorOutline, float _taille, sf::Vector2f _posRs, sf::Vector2f _sizeRs);

	void CreateCS(sf::CircleShape& _cs, sf::Color _color, sf::Vector2f _posCs, float _radiusCs);

	void CreateCSForme(sf::CircleShape& _cs, sf::Color _color, sf::Vector2f _posCs, float _radiusCs, int _nbCote);

	void CreateCSoutline(sf::CircleShape& _cs, sf::Color _colorFond, sf::Color _colorOutline, float _taille, sf::Vector2f _posCs, float _radiusCs);

	void CreateCSFormeoutline(sf::CircleShape& _cs, sf::Color _colorFond, sf::Color _colorOutline, float _taille, sf::Vector2f _posCs, float _radiusCs, int _nbCote);

	void CreateTx(sf::Text& _texte, sf::Font _font, sf::Color _color, sf::Vector2f _posTx, unsigned long int _sizeTx);

	void ChoixLangue(int _intlangue, sf::Text& _texte, std::string _txFr, std::string _txEn);

	float CalculAngle(float p1x, float p1y, float p2x, float p2y);
};