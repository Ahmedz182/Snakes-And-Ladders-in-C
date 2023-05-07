#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
using namespace std;

class Name
{

private:
	string name1, name2;
	int remenu;

public:
	bool p1 = true;
	int counter = 1;
	bool start1 = false;
	bool start2 = false;
	int score1;
	int score2;
	int run;

	void getname(string n1, string n2)
	{

		name1 = n1;
		name2 = n2;
	}

	void setname()
	{

		cout << endl
			 << "Players are : " << name1 << " & " << name2 << endl
			 << endl;
	}

	void menu()
	{
		int n;

		cout << "********** Main Menu *************" << endl;
		cout << "Press 1 to start new Game" << endl;
		cout << "Press 2 to Clear Screen" << endl;
		cout << "Press 3 to Close Game" << endl;
		cout << "------------------------------------->" << endl;
		cin >> n;
		cout << endl
			 << endl;
		remenu = n;
	}

	void againturn()
	{

		if (p1 == true)

			cout << name1 << " Turn" << endl
				 << endl;
		else
			cout << name2 << " Turn" << endl
				 << endl;
	}

	void scoreandturnchnage()
	{

		if (counter % 2 == 0)
		{
			p1 = false;
			if (run == 6)
			{
				start2 = true;
			}

			if (start2)
			{
				if (score2 == 26)
				{
					score2 += 32;
				}
				else if (score2 == 97)
				{
					score2 -= 62;
				}

				if (score2 + run > 100)
				{
					score2 -= run;
				}
				else
				{
					score2 += run;
				}
			}
		}
		else
		{
			p1 = true;
			if (run == 6)
			{
				start1 = true;
			}

			if (start1)
			{
				if (score1 == 26)
				{
					score1 += 32;
				}
				else if (score1 == 97)
				{
					score1 -= 62;
				}

				if (score1 + run > 100)
				{
					score1 -= run;
				}
				else
				{
					score1 += run;
				}
			}
		}
	}

	void turn()
	{

		int z;
		srand(time(0)); // Initialize random number generator.
		run = (rand() % 6) + 1;
		cout << "Press 0 to take turn :" << endl;
		cout << "Press 1 to Go back to menu" << endl;
		cin >> z;

		if (run == 6)
		{
			cout << "Take one more Turn due to 6" << endl;
		}
		else
		{
			counter++;
		}
		switch (z)
		{
		case 0:
			system("CLS");
			cout << name1 << "\x1b[5m Score is: \x1b[0m" << score1 << " || " << name2 << "\x1b[5m Score is: \x1b[0m" << score2 << endl;
			cout << "------------------------------------->" << endl;

			cout << "You Got: " << run << "." << endl
				 << endl;
			if (run == 6)
			{
				cout << "Take one more Turn due to you got 6 in last turn." << endl;
			}
			break;
		case 1:
			menu();
			menuselect();
			break;
		default:
			cout << "Wrong Selection" << endl;
			//			cout << "program closed";
			turn();
			//			exit(3);
			break;
		}
		scoreandturnchnage();

		if (score1 == 100)
		{
			system("CLS");
			cout << name1 << "\x1b[5m is WINNER \x1b[0m" << endl;
			setscore();
			menu();
			menuselect();
		}
		if (score2 == 100)
		{
			system("CLS");
			cout << name2 << "\x1b[5m is WINNER \x1b[0m" << endl;
			setscore();
			menu();
			menuselect();
		}

		againturn();
		startgame();
	}
	void startgame()
	{

		int row, col, number = 100, temp = 0;
		cout << "#  #  #  #  #   #  #  #  #  #  #  #" << endl;
		cout << "#                                 #" << endl;
		for (row = 10; row > 0; row--)
		{

			cout << "#  ";
			for (col = 10; col > 0; col--)
			{

				number--;

				if (number < 10)
				{
					cout << temp + number << " ";
				}
				else
				{
					if (number == 26)
					{
						cout << "\x1b[7m26\x1b[0m ";
						continue;
					}
					if (number == 58)
					{
						cout << "\x1b[7m58\x1b[0m ";
						continue;
					}
					if (number == 35)
					{
						cout << "\x1b[41m35\x1b[0m ";
						continue;
					}
					if (number == 97)
					{
						cout << "\x1b[41m97\x1b[0m ";
						continue;
					}
					else
					{
						cout << number << " ";
					}
				}
			}
			if (row == 1)
			{
				cout << "           #" << endl;
			}
			else
			{
				cout << " #" << endl;
			}
		}

		cout << "#                                 #" << endl;
		cout << "#  #  #  #  #   #  #  #  #  #  #  #" << endl
			 << endl;

		cout << "\x1b[1mNOTE:\x1b[0m" << endl;
		cout << "1. \x1b[3mJump: 26 -> 58 \x1b[0m" << endl;
		cout << "2. \x1b[3mSnake Bite: 97 -> 35 \x1b[0m" << endl;
		cout << "----------------------------->" << endl;

		turn();
	}

	void menuselect()
	{
		switch (remenu)
		{

		case 1:
			setscore();
			startgame();
			break;
		case 2:
			setscore();
			system("CLS");
			menu();
			break;
		case 3:
			cout << "program closed";
			exit(3);
			break;

		default:
			cout << "Wrong Selection" << endl;
			menuselect();
			break;
		}
	}

	void setscore()
	{
		score1 = 0;
		score2 = 0;
		start1 = false;
		start2 = false;
	}
};

int main()
{
	string n1, n2;
	cout << "Enter player 1 Name : ";
	cin >> n1;
	cout << "Enter player 2 Name : ";
	cin >> n2;
	Name s;
	s.getname(n1, n2);
	s.setname();
	s.menu();
	s.menuselect();
}
