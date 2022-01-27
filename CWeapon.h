#pragma once
#ifndef _CWeapon_h
#define _CWeapon_h
#include <string>
#include <iostream>
#include <ctime>

class CWeapon
{
protected:
	std::string m_nom;
	int m_dommage;
	int m_bonus;
	int m_criticalStrike;
public:
	//getter()
	std::string getm_nom();
	int getm_dommage();
	int getm_bonus();
	int getm_criticalStrike();
	//setter()
	void setm_nom(std::string p_nom);
	void setm_dommage(int p_dommage);
	void setm_bonus(int p_bonus);
	void setm_criticalStrike(int p_criticalStrike);
	//autre méthode
	bool criticalStrike();
	CWeapon(std::string p_nom, int p_dommage, int p_bonus, int p_criticalStrike);
	~CWeapon();
private:
	CWeapon();
};

#endif // !_CWeapon_h
