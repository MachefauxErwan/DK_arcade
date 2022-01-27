#pragma once
#ifndef _CParserCharacters_h
#define _CParserCharacters_h
#include "CArcher.h"
#include "CMage.h"
#include "CWarrior.h"
#include "CParser.h"
#include <ctime>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

class CParserCharacters : public CParser
{
protected:
std::map<std::string, CMage*> m_mapMage;
	std::map<std::string, CWarrior*> m_mapWarrior;
	std::map<std::string, CArcher*> m_mapArcher;
public:

	//getter()
	std::map<std::string, CMage*> getm_mapMage();
	std::map<std::string, CWarrior*> getm_mapWarrior();
	std::map<std::string, CArcher*> getm_mapArcher();
	//setter()
	void setm_mapMage(std::map<std::string, CMage*> p_mapMage);
	void setm_mapWarrior(std::map<std::string, CWarrior*> p_mapWarrior);
	void setm_mapArcher(std::map<std::string, CArcher*> p_mapArcher);
	// autre méthode 
	void setMapCharacters(std::string p_nomFichier);
	CParserCharacters();
	~CParserCharacters();
private:
	//	CCharacter();
};

#endif // !_CParserCharacters_h
