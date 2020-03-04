#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//colors
	//=================== Input Cipher Text File =======================
	ifstream infile;
	infile.open("cipher.txt");
	//============= Store Text File in String Array ==========
	string str[100];

	cout << "============== CIPHER TEXT ====================" << endl;

	for (int x = 0; x < 100; x++)
	{
		infile >> str[x];
		if (str[x] != "")
		{
			cout << str[x] << " ";
		}
	}
	cout << endl << "=========================" << endl;
	//===================== Copy Strings into Char Array ==================
	char char_array[100][15];

	for (int x = 0; x < 100; x++)
	{
		strcpy_s(char_array[x], str[x].c_str());
	}
//=================== Output All Possible Shifts ==========
	for (int z = 1, a = -25; z < 25; z++, a++)
	{
		SetConsoleTextAttribute(hConsole, 15);
		for (int x = 0; x < 100; x++)
		{
			for (int y = 0; y < 15; y++)
			{
				if (int(char_array[x][y]) == 44 || int(char_array[x][y]) == 40 || int(char_array[x][y]) == 41 || int(char_array[x][y]) == 46)//punctuations
				{
					cout << (char_array[x][y]);
				}
				if (int(char_array[x][y]) >= 97 && int(char_array[x][y]) <= 122)//lowercase letters
				{
					if (int(char_array[x][y]) + z <= 122)
					{
						cout << char(int(char_array[x][y]) + z);
					}
					if (int(char_array[x][y]) + z > 122)
					{
						cout << char(int(char_array[x][y]) + a);
					}
				}
				if (int(char_array[x][y]) >= 65 && int(char_array[x][y]) <= 90)//uppercase letters
				{
					if (int(char_array[x][y]) + z <= 90)
					{
						cout << char(int(char_array[x][y]) + z);
					}
					if (int(char_array[x][y]) + z > 90)
					{
						cout << char(int(char_array[x][y]) + a);
					}
				}
			}
			cout << " ";
		}
		SetConsoleTextAttribute(hConsole, 4);
		cout << "# of Shift(s) = " << z << " times" << endl;
		SetConsoleTextAttribute(hConsole, 2);
		cout << endl << "=====================================================================================" << endl;
	}
	system("pause");
}