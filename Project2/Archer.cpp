#include "Archer.h"
#include "Monster.h"

Archer::Archer(std::string nickname) : Player(nickname)
{
	this->nickName = nickname;
	HP = 45;
	MP = 30;
	Defence = 23;
	Power = 20;
}

void Archer::attack()
{
	std::cout << "�ü� ����!" << std::endl;
}

void Archer::printPlayerStatus()
{
	std::cout << nickName << "���� ���� ����" << std::endl;
	std::cout << "���� : �ü�" << std::endl;
	Player::printPlayerStatus();
}

void Archer::attack(Monster* monster)
{
	int totaldamage = Power - monster->getDefence();
	if (totaldamage <= 0)
	{
		totaldamage = 1;
	}

	int damage = totaldamage / 3;

	if (damage <= 0)
	{
		damage = 1;
	}

	for (int i = 0; i < 3; i++)
	{
		std::cout << monster->getName() << "���� ȭ���" << damage << "�� ���ظ� ������!" << std::endl;
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
