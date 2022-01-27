#pragma once
#ifndef _CBow_h
#define _CBow_h
#include "CWeapon.h"

class CBow : public CWeapon
{
protected:
	int m_nbArrow;
public:
	void setm_nbArrow(int p_nbArrow);
	int getm_nbArrow();
	bool haveArrows();
	void shoot();
	CBow(std::string p_nom, int p_dommage, int p_bonus, int p_criticalStrike, int p_nbArrow);
	~CBow();
private:
	CBow();
};

#endif // !_CWeapon_h
