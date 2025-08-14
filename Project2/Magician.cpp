#include "Magician.h"
#include "Monster.h"

Magician::Magician(std::string nickname) : Player(nickname)
{
	this->nickName = nickname;
	HP = 50;
	MP = 50;
	Defence = 25;
	Power = 18;
}

void Magician::attack()
{
	std::cout << "법사 공격!" << std::endl;
}

void Magician::printPlayerStatus()
{
	std::cout << nickName << "님의 현재 상태" << std::endl;
	std::cout << "직업 : 법사" << std::endl;
	Player::printPlayerStatus();
}

void Magician::attack(Monster* monster)
{
	int damage = Power - monster->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}

	std::cout << monster->getName() << " 에게" << damage << "만큼의 데미지를 입힙니다." << std::endl;


	if (monster->setHP(monster->getHp() - damage))
	{
		monster->PrintStatus();
	}
	else
	{
		std::cout << monster->getName() << " 를 처치했습니다!" << std::endl;
	}
}
