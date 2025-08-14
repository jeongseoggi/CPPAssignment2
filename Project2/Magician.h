#pragma once
#include "Player.h"

class Magician : public Player
{
public:
	Magician(std::string nickname);
	virtual void attack() override;
	virtual void printPlayerStatus() override;
	virtual void attack(Monster* monster) override;

};