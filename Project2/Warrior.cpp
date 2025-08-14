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
	std::cout << "����!" << std::endl;
}

void Warrior::printPlayerStatus()
{
	std::cout << nickName << "���� ���� ����" << std::endl;
	std::cout << "���� : ����" << std::endl;;
	Player::printPlayerStatus();
}

void Warrior::attack(Monster* monster)
{
	int damage = Power - monster->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}

	std::cout << monster->getName() << " ����" << damage << " ��ŭ�� �������� �����ϴ�." << std::endl;

	int monsterHPcount = monster->getHp() - damage;

	if (monster->setHP(monsterHPcount))
	{
		monster->PrintStatus();
	}
	else
	{
		std::cout << monster->getName() << " �� óġ�߽��ϴ�!" << std::endl;
	}

}
