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
}
namespace pseudo
{
	void setpseudo1(std::string _string);
	std::string getpseudo1();
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