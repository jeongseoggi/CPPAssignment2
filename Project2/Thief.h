#pragma once
#include "Player.h"

class Theif : public Player
{
public:
	Theif(std::string nickname);
	virtual void attack() override;
	virtual void printPlayerStatus() override;
	virtual void attack(Monster* monster) override;
};