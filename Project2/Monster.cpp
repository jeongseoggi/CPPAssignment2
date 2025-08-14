#include "Monster.h"
#include "Player.h"

Monster::Monster(std::string name)
{
	this->name = name;
	HP = 10;
	Power = 30;
	Defence = 10; 
	Speed = 10;
}

void Monster::attack(Player* player)
{
	int damage = Power - player->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}

	std::cout << name << "��" << damage << " ��ŭ�� �������� ���ظ� �����ϴ�!" << std::endl;
	if (player->setHP(player->getHP() - damage))
	{
		player->printPlayerStatus();
	}
	else
	{
		player->setHP(player->getHP() - damage);
		std::cout << "����߽��ϴ�. �÷��̾� �й�.." << std::endl;
	}
}

void Monster::PrintStatus()
{
	std::cout << "���� �̸� : " << name << std::endl;
	std::cout << "���� HP : " << HP << std::endl;
	std::cout << std::endl;
}

std::string Monster::getName()
{
	return name;
}

int Monster::getHp()
{
	return HP;
}

int Monster::getPower()
{
	return Power;
}

int Monster::getDefence()
{
	return Defence;
}

int Monster::getSpeed()
{
	return Speed;
}

void Monster::setName(std::string name)
{
	this->name = name;
}

bool Monster::setHP(int HP)
{
	this->HP = HP;
	if (HP <= 0)
	{
		return false;
	}

	return true;
}

void Monster::setPower(int power)
{
	this->Power = power;
}

void Monster::setDefence(int defence)
{
	this->Defence = defence;
}

void Monster::setSpeed(int speed)
{
	this->Speed = speed;
}
