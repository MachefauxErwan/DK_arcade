#ifndef _CParserWeapons_h
#define _CParserWeapons_h
#include <string>
#include <iostream>
#include "CWeapon.h"
#include "CBow.h"
#include "CStaff.h"
#include "CSword.h"
#include "CWarrior.h"
#include "CArcher.h"
#include "CMage.h"
#include "CParser.h"
#include <ctime>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

class CParserWeapons : public CParser
{
protected:
	std::map<std::string, CStaff*> m_mapStaff;
	std::map<std::string, CSword*> m_mapSword;
	std::map<std::string, CBow*> m_mapBow;
	
public:

	//getter()
	std::map<std::string, CStaff*> getm_mapStaff();
	std::map<std::string, CSword*> getm_mapSword();
	std::map<std::string, CBow*> getm_mapBow();
	//setter()
	void setm_mapStaff(std::map<std::string, CStaff*> p_mapStaff);
	void setm_mapSword(std::map<std::string, CSword*> p_mapSword);
	void setm_mapBow(std::map<std::string, CBow*> p_mapBow);
	// autre méthode 
	void setMapWeapons(std::string p_nomFichier);

	CParserWeapons();
	~CParserWeapons();
private:
	//	CCharacter();
};

#endif // !_CParserWeapons_h
