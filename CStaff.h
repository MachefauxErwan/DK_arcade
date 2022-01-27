#pragma once
#ifndef _CStaff_h
#define _CStaff_h
#include "CWeapon.h"


class CStaff : public CWeapon
{
protected:
	int m_manaCost;
public:
	void setm_manaCost(int p_manaCost);
	int getm_manaCost();
	CStaff(std::string p_nom, int p_dommage, int p_bonus, int p_criticalStrike, int p_manaCost);
	~CStaff();
private:
	CStaff();
};

#endif // !_CWeapon_h
