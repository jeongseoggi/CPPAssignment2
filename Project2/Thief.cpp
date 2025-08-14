#include "Thief.h"
#include "Monster.h"

Theif::Theif(std::string nickname) : Player(nickname)
{
	this->nickName = nickname;
	HP = 40;
	MP = 30;
	Defence = 20;
	Power = 25;
}

void Theif::attack()
{
	std::cout << "���� ����!" << std::endl;
}

void Theif::printPlayerStatus()
{
	std::cout << nickName << "���� ���� ����" << std::endl;
	std::cout << "���� : ����" << std::endl;
	Player::printPlayerStatus();
}

void Theif::attack(Monster* monster)
{
	int totaldamage = Power - monster->getDefence();
	if (totaldamage <= 0)
	{
		totaldamage = 1;
	}

	int damage = totaldamage / 5;

	if (damage <= 0)
	{
		damage = 1;
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << monster->getName() << "���� ǥâ����" << damage << "�� ���ظ� ������!" << std::endl;
		if (monster->setHP(monster->getHp() - damage))
		{
			monster->PrintStatus();
		}
		else
		{
			std::cout << monster->getName() << "�� �����ƴ�!" << std::endl;
			break;
		}

	}

}
