#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
#include <windows.h>
#include <iostream>

using namespace std;


Player* SelectJob(Player* player, string userNickname)
{
	int userInput;


	while (true)
	{
		cout << "������ �������ּ��� : ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
			player = new Warrior(userNickname);
			break;
		case 2:
			player = new Magician(userNickname);
			break;
		case 3:
			player = new Theif(userNickname);
			break;
		case 4:
			player = new Archer(userNickname);
			break;
		default:
			cout << "�ٽ� �������ּ���" << endl;
			continue;
		}

		break;
	}

	return player;
}

Monster* MonsterCreate(Monster* monster)
{
	monster = new Monster("������");
	cout << monster->getName() << " �� �ʵ忡 �����˴ϴ�." << endl;
	cout << endl;

	return monster;
}

void GameStart(string job_arr[], string* nickName)
{
	cout << "�г����� �Է����ּ��� : ";
	cin >> *nickName;


	cout << "<���� ����>" << endl;
	for (int i = 0; i < job_arr->size(); i++)
	{
		cout << i + 1 << ". " << job_arr[i] << endl;
	}
}

int SeleteUserBehavior()
{
	cout << "�ൿ ����" << endl;
	int inputValue;
	while (true)
	{
		cout << "1. ����" << endl;
		cout << "2. HP ȸ��" << endl;
		cout << "3. �����ϱ�" << endl;

		cout << "�ൿ�� �����ϼ��� : ";
		cin >> inputValue;
		cout << endl;
		switch (inputValue)
		{
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		default:
			cout << "�ٽ� �������ּ���!" << endl;
			continue;
		}
	}

}



int main()
{
	string job_arr[4] = { "����", "����", "����", "�ü�" };

	Player* player = nullptr;
	Monster* monster = nullptr;
	string userNickname;



	GameStart(job_arr, &userNickname);
	player = SelectJob(player, userNickname);
	monster = MonsterCreate(monster);


	system("cls");

	while (true)
	{
		if (player != nullptr)
		{
			cout << monster->getName() << "���� ����!" << endl;
			
			
			int select = SeleteUserBehavior();

			if (select == 1)
			{
				player->attack(monster);
				if (monster->getHp() <= 0)
				{
					delete monster;
					monster = nullptr;
					break;
				}
			}
			else if(select == 2)
			{
				if (player->UsePotion())
				{
					player->printPlayerStatus();
				}
				else
				{
					continue;
				}
			}
			else
			{
				cout << "������ ����˴ϴ�.." << endl;
				break;
			}
		}
		
		if (monster != nullptr)
		{
			cout << monster->getName() << "�� �÷��̾ �����մϴ�." << endl;
			monster->attack(player);
			if (player->getHP() <= 0)
			{
				delete player;
				player = nullptr;
				break;
			}
		}
	}
	return 0;
	
}
