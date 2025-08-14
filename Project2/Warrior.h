#pragma once

#include "Player.h"

class Warrior : public Player
{
public:
	Warrior(std::string nickname);

	virtual void attack() override;
	virtual void printPlayerStatus() override;
	virtual void attack(Monster* monster) override;
};