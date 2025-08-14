#pragma once
#include <string>
#include <iostream>

class Monster;

class Player
{
public:
	
	Player(std::string nickanme);
	virtual void attack() = 0;
	virtual void printPlayerStatus();
	virtual void attack(Monster* monster) = 0;

	std::string getJobName();
	std::string getNickName();
	int getLevel();
	int getHP();
	int getMP();
	int getPower();
	int getDefence();
	int getAccuracy();
	int getSpeed();
	int getPotion();


	void setNickname(std::string nickname);
	bool setHP(int HP);
	bool setMP(int MP);
	void setPower(int power);
	void setDefence(int defence);
	void setAccuracy(int accuracy);
	void setSpeed(int speed);
	void setPotion();
	bool UsePotion();

protected:
	std::string job_name;
	std::string nickName;
	int level;
	int HP;
	int MP;
	int Power;
	int Defence;
	int accuracy;
	int speed;
	int potion;


};