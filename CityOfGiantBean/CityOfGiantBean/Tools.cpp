#include "tools.h"

sf::Clock sfclock;
sf::Time sfTime;
bool isFullScreen;
bool isDone;
sf::RenderWindow window;
std::string windowTitle;
sf::Vector2u windowSize;

int iLangueTrad, iChoixMusic;
bool bFirstIn, bFirstInM, bDialogue;
float SonVolume, MusicVolume;

std::string stpst1;

int iSaveSexe, iSaveMap;

namespace boiteDiscussion
{
	sf::Texture BoiteDiscussionTexture;
	sf::Sprite BoiteDiscussionSprite;
	sf::Vector2f BoiteDiscussionPos;
	void initBoiteDiscussion() {
		BoiteDiscussionTexture.loadFromFile("..\\Ressources\\Textures\\dialogbox1.png");
		BoiteDiscussionSprite.setTexture(BoiteDiscussionTexture);
		BoiteDiscussionPos = { 0,1080-BoiteDiscussionSprite.getGlobalBounds().height};
		BoiteDiscussionSprite.setPosition(BoiteDiscussionPos);
	}
	void displayBoiteDiscussion(myWindow& _window) {
		_window.Draw(BoiteDiscussionSprite);
	}
	bool getBoolDiscu()	{
		return bDialogue;
	}
	void setBoolDiscu(bool _bool)	{
		bDialogue = _bool;
	}
}
namespace save
{
	void setpseudo1(std::string _string) {
		stpst1 = _string;
	}
	std::string getpseudo1() {
		return stpst1;
	}
	void setSexe(int _choixSexe){
		iSaveSexe = _choixSexe;
	}
	int getSexe()	{
		return iSaveSexe;
	}
	void setMap(int _choixMap)	{
		iSaveMap = _choixMap;
	}
	int getMap()	{
		return iSaveMap;
	}
}
namespace music
{
	void SetVolSonMusBase(float _floatMusic, float _floatSon) {
		MusicVolume = _floatMusic; SonVolume = _floatSon;
	}
	void SetVolume(sf::Music& _music) {
		_music.setVolume(MusicVolume);
	}
	void SetSon(sf::Sound& _sound) {
		_sound.setVolume(SonVolume);
	}
	float GetVolumeSon() {
		return SonVolume;
	}
	void AddVolumeSon(float _Volume) {
		SonVolume += _Volume;
	}
	float GetVolumeMusique() {
		return MusicVolume;
	}
	void AddVolumeMusique(float _Volume) {
		MusicVolume += _Volume;
	}
}

namespace tools
{
	int GetTrad() {
		return iLangueTrad;
	}
	void SetTrad(int _nb) {
		iLangueTrad = _nb;
	}
	int GetChoixMu() {
		return iChoixMusic;
	}
	void SetChoixMu(int _nb) {
		iChoixMusic = _nb;
	}
	bool GetFirstIn() {
		return bFirstIn;
	}
	void SetFirstIn(bool _bool) {
		bFirstIn = _bool;
	}
	bool GetFirstInM() {
		return bFirstInM;
	}
	void SetFirstInM(bool _bool) {
		bFirstInM = _bool;
	}

	int iRand(int _min, int _max)
	{
		return rand() % (_max - _min) + _min;
	}

	double frand(float _min, float _max)
	{
		return ((rand() / (double)RAND_MAX) * ((double)_max - (double)_min) + (double)_min);
	}

	void restartClock()
	{
		sfTime = sfclock.restart();
	}

	float GetTimeDelta()
	{
		return sfTime.asSeconds();
	}

	float lerp(float v0, float v1, float t)
	{
		return (1 - t) * v0 + t * v1;
	}

	sf::Vector2f vec2f_lerp(sf::Vector2f v0, sf::Vector2f v1, float t)
	{
		sf::Vector2f tmp;
		tmp.x = (1 - t) * v0.x + t * v1.x;
		tmp.y = (1 - t) * v0.y + t * v1.y;
		return tmp;
	}

	sf::Vector3f vec3f_lerp(sf::Vector3f v0, sf::Vector3f v1, float t)
	{
		sf::Vector3f tmp;
		tmp.x = (1 - t) * v0.x + t * v1.x;
		tmp.y = (1 - t) * v0.y + t * v1.y;
		tmp.z = (1 - t) * v0.z + t * v1.z;
		return tmp;
	}

	sf::Color color_lerp(sf::Color v0, sf::Color v1, float t)
	{
		sf::Color tmp;
		tmp.r = (1 - t) * v0.r + t * v1.r;
		tmp.g = (1 - t) * v0.g + t * v1.g;
		tmp.b = (1 - t) * v0.b + t * v1.b;
		tmp.a = (1 - t) * v0.a + t * v1.a;
		return tmp;
	}

	bool Circle_Collision(sf::Vector2f _pos1, sf::Vector2f _pos2, float _rayon1, float _rayon2)
	{
		// if (sqrt(pow(_pos1.x - _pos2.x, 2) + pow(_pos1.y - _pos2.y, 2)) < _rayon1 + _rayon2) // Version non optimisé
		// Version Optimisé
		if ((_pos1.x - _pos2.x) * (_pos1.x - _pos2.x) + (_pos1.y - _pos2.y) * (_pos1.y - _pos2.y) < (_rayon1 + _rayon2) * (_rayon1 + _rayon2))
		{
			return true;
		}
		else return false;
	}

	bool Rectangle_Collision(sf::FloatRect _box1, sf::FloatRect _box2)
	{
		if ((_box2.left >= _box1.left + _box1.width)      // trop à droite
			|| (_box2.left + _box2.width <= _box1.left) // trop à gauche
			|| (_box2.top >= _box1.top + _box1.height) // trop en bas
			|| (_box2.top + _box2.height <= _box1.top))  // trop en haut
			return false;
		else
			return true;
	}

	bool CircleRect_Collision(sf::Vector2f _pos1, float _rayon1, sf::Vector2f _pos2, sf::Vector2f _size2)
	{
		if (_pos1.x + _rayon1 > _pos2.x && _pos1.x <  _pos2.x + _size2.x && _pos1.y + _rayon1 > _pos2.y && _pos1.y < _pos2.y + _size2.y)
		{
			return true;
		}
		else return false;
	}

	bool circleRect(sf::Vector2f circlePosition, sf::Vector2f rectanglePosition, float rayon, sf::Vector2f rectangleSize) {

		// cx et cy position du cercle
		 //



		 // temporarectanglePosition.y variables to set edges for testing
		float testX = circlePosition.x;
		float testY = circlePosition.y;


		// which edge is closest?
		if (circlePosition.x < rectanglePosition.x)         testX = rectanglePosition.x;      // test left edge
		else if (circlePosition.x > rectanglePosition.x + rectangleSize.x) testX = rectanglePosition.x + rectangleSize.x;   // right edge
		if (circlePosition.y < rectanglePosition.y)         testY = rectanglePosition.y;      // top edge
		else if (circlePosition.y > rectanglePosition.y + rectangleSize.y) testY = rectanglePosition.y + rectangleSize.y;   // bottom edge

		// get distance from closest edges
		float distX = circlePosition.x - testX;
		float distY = circlePosition.y - testY;
		float distance = sqrt((distX * distX) + (distY * distY));

		// if the distance is less than the radius, collision!
		if (distance <= rayon) {
			return true;
		}
		return false;
	}

	void CreateRS(sf::RectangleShape& _rs, sf::Color _color, sf::Vector2f _posRs, sf::Vector2f _sizeRs) {
		_rs.setFillColor(_color);
		_rs.setPosition(_posRs);
		_rs.setSize(_sizeRs);
	}

	void CreateRSoutline(sf::RectangleShape& _rs, sf::Color _colorFond, sf::Color _colorOutline, float _taille, sf::Vector2f _posRs, sf::Vector2f _sizeRs) {
		_rs.setOutlineThickness(_taille);
		_rs.setFillColor(_colorFond);
		_rs.setOutlineColor(_colorOutline);
		_rs.setPosition(_posRs);
		_rs.setSize(_sizeRs);
	}

	void CreateCS(sf::CircleShape& _cs, sf::Color _color, sf::Vector2f _posCs, float _radiusCs) {
		_cs.setFillColor(_color);
		_cs.setPosition(_posCs);
		_cs.setRadius(AjustReso * _radiusCs);
	}

	void CreateCSForme(sf::CircleShape& _cs, sf::Color _color, sf::Vector2f _posCs, float _radiusCs, int _nbCote) {
		_cs.setFillColor(_color);
		_cs.setPosition(_posCs);
		_cs.setRadius(AjustReso * _radiusCs);
		_cs.setPointCount(_nbCote);
	}

	void CreateCSoutline(sf::CircleShape& _cs, sf::Color _colorFond, sf::Color _colorOutline, float _taille, sf::Vector2f _posCs, float _radiusCs) {
		_cs.setOutlineThickness(_taille);
		_cs.setFillColor(_colorFond);
		_cs.setOutlineColor(_colorOutline);
		_cs.setPosition(_posCs);
		_cs.setRadius(AjustReso * _radiusCs);
	}

	void CreateCSFormeoutline(sf::CircleShape& _cs, sf::Color _colorFond, sf::Color _colorOutline, float _taille, sf::Vector2f _posCs, float _radiusCs, int _nbCote) {
		_cs.setOutlineThickness(_taille);
		_cs.setFillColor(_colorFond);
		_cs.setOutlineColor(_colorOutline);
		_cs.setPosition(_posCs);
		_cs.setRadius(AjustReso * _radiusCs);
		_cs.setPointCount(_nbCote);
	}

	void CreateTx(sf::Text& _texte, sf::Font _font, sf::Color _color, sf::Vector2f _posTx, unsigned long int _sizeTx) {
		_texte.setFont(_font);
		_texte.setFillColor(_color);
		_texte.setPosition(_posTx);
		_texte.setCharacterSize(_sizeTx);
	}

	void ChoixLangue(int _intlangue, sf::Text& _texte, std::string _txFr, std::string _txEn) {
		switch (_intlangue)
		{
		case 0:
			_texte.setString(_txFr);
			break;
		case 1:
			_texte.setString(_txEn);
			break;
		default:
			break;
		}
	}

	float CalculAngle(float p1x, float p1y, float p2x, float p2y) {
		float tmpX = p2x - p1x;
		float tmpY = p2y - p1y;

		float AngleDegre = atan2(tmpY, tmpX) * 180 / 3.1415;
		AngleDegre *= -1;
		return AngleDegre;
	}
};