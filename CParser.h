#pragma once
#ifndef _CParser_h
#define _CParser_h
#include "CArcher.h"
#include "CMage.h"
#include "CWarrior.h"
#include <ctime>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

class CParser
{
protected:
	std::vector<std::string> m_ligneFichier;
public:

	//getter()
	std::vector<std::string> getm_ligneFichier();
	//setter()
	void setm_ligneFichier(std::vector<std::string> p_ligneFichier);
	// autre méthode 
	std::string enleverEspaceChaine(std::string chaine);
	void lireFichier(std::string p_nomFichier);
	void afficherContenufichier(std::string p_nomFichier);
	CParser();
	~CParser();
private:
	//	CCharacter();
};

#endif // !_CParser_h
