#pragma once
#include "Tools.h"

class NonVivant
{
protected:

	std::string nom;
	int prix;

public:

	inline std::string GetName() {	return nom;}
	inline void SetName(std::string _name) {nom = _name;}
	inline int GetPrix() {return prix;}
	inline void SetPrix(int _value){prix = _value;}

};

