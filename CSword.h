#pragma once
#ifndef _CSword_h
#define _CSword_h
#include "CWeapon.h"


class CSword : public CWeapon
{
protected:
	int m_durability;
	int m_durabilityMax;
public:
	void setm_durability(int p_durability);
	void setm_durabilityMax(const int p_durabilityMax);
	int getm_durability();
	int getm_durabilityMax();
	bool isBroken();
	void use();
	CSword(std::string p_nom, int p_dommage, int p_bonus, int p_criticalStrike, int p_durability, int p_durabilityMax);
	~CSword();
private:
	CSword();
};

#endif // !_CWeapon_h
