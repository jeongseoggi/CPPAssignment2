#pragma once
#pragma once
#include "Player.h"

class Archer : public Player
{
public:
	Archer(std::string nickname);
	virtual void attack() override;
	virtual void printPlayerStatus() override;
	virtual void attack(Monster* monster) override;
};	