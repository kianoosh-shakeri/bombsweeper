#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <string>
using namespace std;
int board[10][10];
void add_bombs()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int num = rand() % 10 + 1;
		board[i][num] = 1;
		cout << "A bomb is on x " << i << ", y " << num << endl;
	} //for loop
}
int main()
{
	int x=0, y=0;

	int score = 0;
	cout << "hi" << endl;
	cout << "Welcome to bomb sweeper" << endl;
	cout << "I think I have to know you first. Whatcha name? " << endl;
	string name = "";
	getline(cin,	 name);
	cout << "hmm! Good to know ya. Let's get on to the show! \r\nSo I have to let you know of a thing, That this version of bombsweeper isn't what you have in your mind. In this version, You have to get the bombs not avoiding them. Depending on your correct or wrong grabs, your score is calculated. Have fun! " << endl;
	add_bombs();
	while (true)
	{
		cout << "Enter Command" << endl;
		string command = "";
		getline(cin, command);
		if (command == "take"||command=="t"||command=="get"||command=="grab"||command=="pick"||command=="pickup"||command=="find")
		{
			if (board[x][y] == 1)
			{
//Here the player has found a bomb. We're gonna award them!
				score += 2;
				cout << "You found a bomb! For that, you are rewarded with a good two points" << endl;
				//let's not forget the next line. Doing so results making the player be able to stay on a square and spam "take" and get as much as points they want.
				board[x][y] = 0;
				bool completed = true;
				for (int i = 0; i < 10; ++i)
				{
					for (int i2 = 0; i2 < 10; ++i2)
					{
						if (board[i][i2] == 1)
						{
							completed = false;
							break;
						}
					}
				}
				if (completed)
				{
					cout << "Complete! Victory is yours! Your total score was " << score << ". Good bye! " << endl;
					break;
			}
			}
			else
			{
				//uwwuawwa, Player couldn't find any bombs on this square! And here comes their punishment.
				score -= 1;
				cout << "Oh, Did someone failed finding a ball-shaped little bomb? I guess so! One point taken! " << endl;
							}
					}
		if (command == "score"||command=="score")
		{
			cout << "you have a total of " << score << " score" << endl;
		}
		if (command == "up" || command == "north"||command=="u"||command=="n")
		{
			if (y < 9)
			{
				y += 1;
				cout << "x: " << x << "y: " << y << endl;
			}
			else cout << "alass, You bump the border" << endl;
		}
		if (command == "south" || command == "down"||command=="s"||command=="d")
		{
			if (y > 0)
			{
				y -= 1;
				cout << "x: " << x << "y: " << y << endl;
			}
			else cout << "alass, You bump the border " << endl;
					}
		if (command == "left" || command == "west"||command=="w"||command=="l")
		{
			if (x > 0)
			{
				x -= 1;
				cout << "x: " << x << "y: " << y << endl;
			}
			else cout << "alass, You bump the border " << endl;
		}
		if (command == "right" || command == "east"||command=="e"||command=="r")
		{
			if (x < 9)
			{
				x += 1;
				cout << "x: " << x << "y: " << y << endl;
			}
			else cout << "alass, You bump the border " << endl;
		}
		if (command == "coordinates" || command == "coords" || command == "location" || command == "loc")
		{
			cout << "x: " << x << "y: " << y << endl;
		}
		if (command == "exit")
		{
			break;
		}
	} //loop
	cout << "Good bye " + name + ". Hope to see you soon! " << endl;
	return 0;
}