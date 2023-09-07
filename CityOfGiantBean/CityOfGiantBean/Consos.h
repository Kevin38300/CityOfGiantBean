#pragma once
#include "NonVivant.h"


class Consos :  public NonVivant
{
	int degat;
	int soinPv;
	int soinM;

public:
	Consos();
	~Consos();

	int GetDegat() {return degat;}
	void SetDegat(int _value) {	degat = _value;}
	int GetSoinPv() { return soinPv; }
	void SetSoinPv(int _value) { soinPv = _value; }
	int GetSoinM() { return soinM; }
	void SetSoinM(int _value) { soinM = _value; }
	void SetStats(std::string _nom, int _degat, int _soinPv, int _soinM, int _prix);
};

