#include "Warrior.h"
#include "Monster.h"

Warrior::Warrior(std::string nickname) : Player(nickname)
{
	this->nickName = nickname;
	HP = 55;
	MP = 30;
	Defence = 28;
	Power = 15;
}

void Warrior::attack()
{
	std::cout << "공격!" << std::endl;
}

void Warrior::printPlayerStatus()
{
	std::cout << nickName << "님의 현재 상태" << std::endl;
	std::cout << "직업 : 전사" << std::endl;;
	Player::printPlayerStatus();
}

void Warrior::attack(Monster* monster)
{
	int damage = Power - monster->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}

	std::cout << monster->getName() << " 에게" << damage << " 만큼의 데미지를 입힙니다." << std::endl;

	int monsterHPcount = monster->getHp() - damage;

	if (monster->setHP(monsterHPcount))
	{
		monster->PrintStatus();
	}
	else
	{
		std::cout << monster->getName() << " 를 처치했습니다!" << std::endl;
	}

}
