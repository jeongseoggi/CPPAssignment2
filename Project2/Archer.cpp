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
	std::cout << "궁수 공격!" << std::endl;
}

void Archer::printPlayerStatus()
{
	std::cout << nickName << "님의 현재 상태" << std::endl;
	std::cout << "직업 : 궁수" << std::endl;
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
		std::cout << monster->getName() << "에게 화살로" << damage << "의 피해를 입혔다!" << std::endl;
		if (monster->setHP(monster->getHp() - damage))
		{
			monster->PrintStatus();
		}
		else
		{
			std::cout << monster->getName() << "을 물리쳤다!" << std::endl;
			break;
		}

	}


}
