#include "tools.h"

sf::Clock sfclock;
sf::Time sfTime;
bool isFullScreen;
bool isDone;
sf::RenderWindow window;
std::string windowTitle;
sf::Vector2u windowSize;

int iLangueTrad, iChoixMusic, iTuto;
bool bFirstIn, bFirstInM, bDialogue, bTuto, bNew;
float SonVolume, MusicVolume;

std::string stpst1;

int iSaveSexe, iSaveMap, choixSexe, choixMap, choixAve, choixShop, choixMode, classe, element, niveau, NbEpee, NbLance, NbBague, NbLourd, NbLeger, NbBouclier, NbPotioPv, NbPotionMana, NbBombe, NbPotionMy, armeEquipe, armureEquipe, skill1, skill2, skill3,
skill4, Xp, skillpoint, CatchGob, CatchLoup, CatchOurs, catchOrc, catchGobOurs, catchGobLoup, catchOursorc, catchLoupRoc, NbMonstreBattu, NbEnnemiBattu, NbMonstreCatch, NbGob, NbLoup, NbOurs, NbOrc, NbPersoBattu, NbMag, NbGuer, NbAss, NbClerc, iChgElem,
iChgClass, iAchat, iFabrique, iBossAv, NivAventure, NivSafarie, Cuivre, cuire, fer, fourrure, fillet, superfillet, argent;

namespace boiteDiscussion
{
	sf::Texture BoiteDiscussionTexture;
	sf::Sprite BoiteDiscussionSprite;
	sf::Vector2f BoiteDiscussionPos;
	void initBoiteDiscussion() {
		BoiteDiscussionTexture.loadFromFile("..\\Ressources\\Textures\\dialogbox1.png");
		BoiteDiscussionSprite.setTexture(BoiteDiscussionTexture);
		BoiteDiscussionPos = { 0,1080 - BoiteDiscussionSprite.getGlobalBounds().height };
		BoiteDiscussionSprite.setPosition(BoiteDiscussionPos);
	}
	void displayBoiteDiscussion(myWindow& _window) {
		_window.Draw(BoiteDiscussionSprite);
	}
	bool getBoolDiscu() {
		return bDialogue;
	}
	void setBoolDiscu(bool _bool) {
		bDialogue = _bool;
	}
}
namespace save
{
	void setNewPartie(bool _True_New__False_Charge) {
		bNew = _True_New__False_Charge;
	}
	bool GetNew() {
		return bNew;
	}
	void setpseudo1(std::string _string) {
		stpst1 = _string;
	}
	std::string getpseudo1() {
		return stpst1;
	}
	void setSexe(int _choixSexe) {
		iSaveSexe = _choixSexe;
	}
	int getSexe() {
		return iSaveSexe;
	}
	void setMap(int _choixMap) {
		iSaveMap = _choixMap;
	}
	int getMap() {
		return iSaveMap;
	}
	void setTuto(bool _tuto_On_Off) {
		bTuto = _tuto_On_Off;
	}
	bool getTuto() {
		return bTuto;
	}
	void setTutoNb(int _tuto_Nb) {
		iTuto = _tuto_Nb;
	}
	int getTutoNb() {
		return iTuto;
	}
	void setAventure(int _choixAve)	{
		choixAve = _choixAve;
	}
	int getAventure() {
		return choixAve;
	}
	void setShop(int _choixShop) {
		choixShop = _choixShop;
	}
	int getShop() {
		return choixShop;
	}
	void setMode(int _choixMode) {
		choixMode = _choixMode;
	}
	int getMode() {
		return choixMode;
	}
	void setClasse(int _classe) {
		classe = _classe;
	}
	int getClasse() {
		return classe;
	}
	void setElement(int _element) {
		element = _element;
	}
	int getElement() {
		return element;
	}
	void setNiveau(int _niveau) {
		niveau = _niveau;
	}
	int getNiveau() {
		return niveau;
	}
	void setNbEpee(int _NbEpee) {
		NbEpee = _NbEpee;
	}
	int getNbEpee() {
		return NbEpee;
	}
	void setNbLance(int _NbLance) {
		NbLance = _NbLance;
	}
	int getNbLance() {
		return NbLance;
	}
	void setNbBague(int _NbBague) {
		NbBague = _NbBague;
	}
	int getNbBague() {
		return NbBague;
	}
	void setNbLourd(int _NbLourd) {
		NbLourd = _NbLourd;
	}
	int getNbLourd() {
		return NbLourd;
	}
	void setNbLeger(int _NbLeger) {
		NbLeger = _NbLeger;
	}
	int getNbLeger() {
		return NbLeger;
	}
	void setNbBouclier(int _NbBouclier) {
		NbBouclier = _NbBouclier;
	}
	int getNbBouclier() {
		return NbBouclier;
	}
	void setNbPotionPv(int _NbPotioPv) {
		NbPotioPv = _NbPotioPv;
	}
	int getNbPotionPv() {
		return NbPotioPv;
	}
	void setNbPotionMana(int _NbPotionMana) {
		NbPotionMana = _NbPotionMana;
	}
	int getNbPotionMana() {
		return NbPotionMana;
	}
	void setNbBombe(int _NbBombe) {
		NbBombe = _NbBombe;
	}
	int getNbBombe() {
		return NbBombe;
	}
	void setNbPotionMy(int _NbPotionMy) {
		NbPotionMy = _NbPotionMy;
	}
	int getNbPotionMy() {
		return NbPotionMy;
	}
	void setArmeEquipe(int _armeEquipe) {
		armeEquipe = _armeEquipe;
	}
	int getArmeEquipe() {
		return armeEquipe;
	}
	void setArmureEquipe(int _armureEquipe) {
		armureEquipe = _armureEquipe;
	}
	int getArmureEquipe() {
		return armureEquipe;
	}
	void setSkill1(int _skill1) {
		skill1 = _skill1;
	}
	int getSkill1() {
		return skill1;
	}
	void setSkill2(int _skill2) {
		skill2 = _skill2;
	}
	int getSkill2() {
		return skill2;
	}
	void setSkill3(int _skill3) {
		skill3 = _skill3;
	}
	int getSkill3() {
		return skill3;
	}
	void setSkill4(int _skill4) {
		skill4 = _skill4;
	}
	int getSkill4() {
		return skill4;
	}
	void setXp(int _Xp) {
		Xp = _Xp;
	}
	int getXp() {
		return Xp;
	}
	void setSkillpoint(int _skillpoint) {
		skillpoint = _skillpoint;
	}
	int getSkillpoint() {
		return skillpoint;
	}
	void setCatchGob(int _CatchGob) {
		CatchGob = _CatchGob;
	}
	int getCatchGob() {
		return CatchGob;
	}
	void setCatchLoup(int _CatchLoup) {
		CatchLoup = _CatchLoup;
	}
	int getCatchLoup() {
		return CatchLoup;
	}
	void setCatchOurs(int _CatchOurs) {
		CatchOurs = _CatchOurs;
	}
	int getCatchOurs() {
		return CatchOurs;
	}
	void setCatchOrc(int _catchOrc) {
		catchOrc = _catchOrc;
	}
	int getCatchOrc() {
		return catchOrc;
	}
	void setCatchGobOurs(int _catchGobOurs) {
		catchGobOurs = _catchGobOurs;
	}
	int getCatchGobOurs() {
		return catchGobOurs;
	}
	void setCatchGobLoup(int _catchGobLoup) {
		catchGobLoup = _catchGobLoup;
	}
	int getCatchGobLoup() {
		return catchGobLoup;
	}
	void setCatchOursOrc(int _catchOursorc) {
		catchOursorc = _catchOursorc;
	}
	int getCatchOursOrc() {
		return catchOursorc;
	}
	void setCatchLoupRoc(int _catchLoupRoc) {
		catchLoupRoc = _catchLoupRoc;
	}
	int getCatchLoupRoc() {
		return catchLoupRoc;
	}
	void setNbMonstreBattu(int _NbMonstreBattu) {
		NbMonstreBattu = _NbMonstreBattu;
	}
	int getNbMonstreBattu() {
		return NbMonstreBattu;
	}
	void setNbEnnemiBattu(int _NbEnnemiBattu) {
		NbEnnemiBattu = _NbEnnemiBattu;
	}
	int getNbEnnemiBattu() {
		return NbEnnemiBattu;
	}
	void setNbMonstreCatch(int _NbMonstreCatch) {
		NbMonstreCatch = _NbMonstreCatch;
	}
	int getNbMonstreCatch() {
		return NbMonstreCatch;
	}
	void setNbGob(int _NbGob) {
		NbGob = _NbGob;
	}
	int getNbGob() {
		return NbGob;
	}
	void setNbLoup(int _NbLoup) {
		NbLoup = _NbLoup;
	}
	int getNbLoup() {
		return NbLoup;
	}
	void setNbOurs(int _NbOurs) {
		NbOurs = _NbOurs;
	}
	int getNbOurs() {
		return NbOurs;
	}
	void setNbOrc(int _NbOrc) {
		NbOrc = _NbOrc;
	}
	int getNbOrc() {
		return NbOrc;
	}
	void setNbPersoBattu(int _NbPersoBattu) {
		NbPersoBattu = _NbPersoBattu;
	}
	int getNbPersoBattu() {
		return NbPersoBattu;
	}
	void setNbMag(int _NbMag) {
		NbMag = _NbMag;
	}
	int getNbMag() {
		return NbMag;
	}
	void setNbGuer(int _NbGuer) {
		NbGuer = _NbGuer;
	}
	int getNbGuer() {
		return NbGuer;
	}
	void setNbAss(int _NbAss) {
		NbAss = _NbAss;
	}
	int getNbAss() {
		return NbAss;
	}
	void setNbClerc(int _NbClerc) {
		NbClerc = _NbClerc;
	}
	int getNbClerc()	{
		return NbClerc;
	}
	void setChgElement(int _iChgElem) {
		iChgElem = _iChgElem;
	}
	int getChgElement() {
		return iChgElem;
	}
	void setChgClass(int _iChgClass) {
		iChgClass = _iChgClass;
	}
	int getChgClass() {
		return iChgClass;
	}
	void setIAchat(int _iAchat) {
		iAchat = _iAchat;
	}
	int getIAchat() {
		return iAchat;
	}
	void setIFabrique(int _iFabrique) {
		iFabrique = _iFabrique;
	}
	int getIFabrique() {
		return iFabrique;
	}
	void setIBossAv(int _iBossAv) {
		iBossAv = _iBossAv;
	}
	int getIBossAv() {
		return iBossAv;
	}
	void setNivAventure(int _NivAventure) {
		NivAventure = _NivAventure;
	}
	int getNivAventure() {
		return NivAventure;
	}
	void setNivSafarie(int _NivSafarie) {
		NivSafarie = _NivSafarie;
	}
	int getNivSafarie() {
		return NivSafarie;
	}
	void setcuivre(int _Cuivre)	{
		Cuivre = _Cuivre;
	}
	int getcuivre()	{
		return Cuivre;
	}
	void setcuire(int _cuire)	{
		cuire = _cuire;
	}
	int getcuire()	{
		return cuire;
	}
	void setfer(int _fer)	{
		fer = _fer;
	}
	int getfer()	{
		return fer;
	}
	void setFourrure(int _fourrure)	{
		fourrure = _fourrure;
	}
	int getFourrure()	{
		return fourrure;
	}
	void setfillet(int _fillet)	{
		fillet = _fillet;
	}
	int getfillet()	{
		return fillet;
	}
	void setsuperfillet(int _superfillet)	{
		superfillet = _superfillet;
	}
	int getsuperfillet()	{
		return superfillet;
	}
	void setArgent(int _argent)	{
		argent = _argent;
	}
	int getArgent()	{
		return argent;
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