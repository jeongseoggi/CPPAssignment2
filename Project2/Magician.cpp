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
	std::cout << "���� ����!" << std::endl;
}

void Magician::printPlayerStatus()
{
	std::cout << nickName << "���� ���� ����" << std::endl;
	std::cout << "���� : ����" << std::endl;
	Player::printPlayerStatus();
}

void Magician::attack(Monster* monster)
{
	int damage = Power - monster->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}

	std::cout << monster->getName() << " ����" << damage << "��ŭ�� �������� �����ϴ�." << std::endl;


	if (monster->setHP(monster->getHp() - damage))
	{
		monster->PrintStatus();
	}
	else
	{
		std::cout << monster->getName() << " �� óġ�߽��ϴ�!" << std::endl;
	}
}
