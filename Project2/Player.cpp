#include "Player.h"

Player::Player(std::string nickanme)
{
	this->nickName = nickanme;
	potion = 5;
}

void Player::printPlayerStatus()
{
	std::cout << "HP : " << HP << std::endl;
	std::cout << "남은 포션 : " << potion << std::endl;
	std::cout << std::endl;
}

std::string Player::getJobName()
{
	return job_name;
}

std::string Player::getNickName()
{
	return nickName;
}

int Player::getLevel()
{
	return level;
}

int Player::getHP()
{
	return HP;
}

int Player::getMP()
{
	return MP;
}

int Player::getPower()
{
	return Power;
}

int Player::getDefence()
{
	return Defence;
}

int Player::getAccuracy()
{
	return accuracy;
}

int Player::getSpeed()
{
	return speed;
}

int Player::getPotion()
{
	return potion;
}

void Player::setNickname(std::string nickname)
{
	this->nickName = nickname;
}

bool Player::setHP(int HP)
{
	this->HP = HP;
	if (HP <= 0)
	{
		return false;
	}

	return true;
}

bool Player::setMP(int MP)
{
	return false;
}

void Player::setPower(int power)
{
	this->Power = power;
}

void Player::setDefence(int defence)
{
	this->Defence = defence;
}

void Player::setAccuracy(int accuracy)
{
	this->accuracy = accuracy;
}

void Player::setSpeed(int speed)
{
	this->speed = speed;
}

void Player::setPotion()
{
	potion--;
}

bool Player::UsePotion()
{
	if (potion <= 0)
	{
		std::cout << "물약이 없습니다." << std::endl;
		return false;
	}
	else
	{
		std::cout << "체력을 회복합니다." << std::endl;
		HP += 20;
		potion--;
		return true;
	}

}



