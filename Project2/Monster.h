#pragma once
#include <string>

class Player;

class Monster
{
public:
	Monster(std::string name);
	void attack(Player* player);
	void PrintStatus();
	
	std::string getName();
	int getHp();
	int getPower();
	int getDefence();
	int getSpeed();

	void setName(std::string name);
	bool setHP(int HP);
	void setPower(int power);
	void setDefence(int defence);
	void setSpeed(int speed);

protected:
	std::string name;
	int HP;
	int Power;
	int Defence;
	int Speed;

};