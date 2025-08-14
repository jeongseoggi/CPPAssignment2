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
		cout << "직업을 선택해주세요 : ";
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
			cout << "다시 선택해주세요" << endl;
			continue;
		}

		break;
	}

	return player;
}

Monster* MonsterCreate(Monster* monster)
{
	monster = new Monster("슬라임");
	cout << monster->getName() << " 이 필드에 스폰됩니다." << endl;
	cout << endl;

	return monster;
}

void GameStart(string job_arr[], string* nickName)
{
	cout << "닉네임을 입력해주세요 : ";
	cin >> *nickName;


	cout << "<직업 선택>" << endl;
	for (int i = 0; i < job_arr->size(); i++)
	{
		cout << i + 1 << ". " << job_arr[i] << endl;
	}
}

int SeleteUserBehavior()
{
	cout << "행동 선택" << endl;
	int inputValue;
	while (true)
	{
		cout << "1. 공격" << endl;
		cout << "2. HP 회복" << endl;
		cout << "3. 종료하기" << endl;

		cout << "행동을 선택하세요 : ";
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
			cout << "다시 선택해주세요!" << endl;
			continue;
		}
	}

}



int main()
{
	string job_arr[4] = { "전사", "법사", "도적", "궁수" };

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
			cout << monster->getName() << "과의 전투!" << endl;
			
			
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
				cout << "게임이 종료됩니다.." << endl;
				break;
			}
		}
		
		if (monster != nullptr)
		{
			cout << monster->getName() << "이 플레이어를 공격합니다." << endl;
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
