#include <iostream>
#include <conio.h>
#include <windows.h>
#include <locale.h>

using namespace std;

char field_char[81];
int	field_no[81];

void Get_Input();
void Draw_Input(int cursor);

void Solve_Setup() {}

int main()
{
    setlocale(LC_CTYPE, "Polish");

    for(int i = 0; i < 81; i++)
    {
    	field_no[i] = 0;
    	field_char[i] = ' ';
    }

    Get_Input();
}

void Get_Input()
{
	bool solve = false;
	int cursor = 0;

	while(!solve)
	{
		Draw_Input(cursor);
		int key = _getch();

	//CODES:
		//48			0
		//49 - 57		1 - 9
		//72			UP
		//77			RIGHT
		//80			DOWN
		//75			LEFT
		//13			ENTER
		//32			SPACE

		/*
		 0  1  2  3  4  5  6  7  8
		 9 10 11 12 13 14 15 16 17
		18 19 20 21 22 23 24 25 26
		27 28 29 30 31 32 33 34 35
		36 37 38 39 40 41 42 43 44
		45 46 47 48 49 50 51 52 53
		54 55 56 57 58 59 60 61 62
		63 64 65 66 67 68 69 70 71
		72 73 74 75 76 77 78 79 80

		81 82 83 84 85 86 87 88 89
		*/

	//CHECK IF 0 IS CLICKED:
		//If so, then clear the field
		if(key == 48)
		{
			field_char[cursor] = ' ';
			field_no[cursor] = 0;
		}

	//CHECK IF NUMBER IS CLICKED:
		//If so, then change the field in the cursor position to that number
		else if(key > 48 & key < 58)
		{
			field_char[cursor] = static_cast<char>(key);
			field_no[cursor] = key - 48;
		}

	//CHECK IF ARROW/ENTER/SPACE IS CLICKED:
		//If so, then move to cursor
		//If enter or space clicked then check if the cursor is pointed to the confirm button, if so then goto solving func
		else
		{
			switch(key)
			{
			//ARROWS
			case 72: //UP ARROW - if the cursor is less than 8 then substract 9
				if(cursor > 8) cursor -= 9;
				break;

			case 80: //DOWN ARROW - if the cursor's less than 81 the add 9
				if(cursor < 81) cursor += 9;
				break;

			case 75: //LEFT ARROW
				if(cursor % 9 > 0) cursor--;
				break;

			case 77: //RIGHT ARROW
				if(cursor % 9 < 8) cursor++;
				break;

			//ENTER/SPACE
			case 32:
			case 13:
				if(cursor > 80 & cursor < 90) Solve_Setup();
				break;

			}//switch
		}
	} //while
}

void Draw_Input(int cursor)
{
	system("cls");

//EXAMPLE:
	/*
	|-----|
	|9 1 5|
	|^    |
	|4 7 8|
	|     |
	|2 3 6|
	|-----|
	*/

	cout << "Use arrows to move the cursor" << endl
		 << "Use numbers on the keyboard to put where the cursor is" << endl
		 << "Click - 0 - to erase number where the cursor is" << endl << endl;

	cout << "  |-----|-----|-----|" << endl;

	for(int i = 0; i < 9; i++)
	{
		cout << "  ";
		for(int j = 0; j < 3; j++)
		{
			cout << "|" << field_char[9*i + 3*j] << " " << field_char[9*i + 3*j + 1] << " " << field_char[9*i + 3*j + 2];
		} //for j
		cout << "|" << endl << "  ";
		for(int j = 0; j < 3; j++)
		{
			int rest = 2;
			if(cursor == 9*i + 3*j & i % 3 == rest) cout << "|^";
			else if(cursor == 9*i + 3*j) cout << "|^";
			else if(i % 3 == rest) cout << "|-";
			else cout << "| ";

			if(cursor == 9*i + 3*j + 1 & i % 3 == rest) cout << "-^";
			else if(cursor == 9*i + 3*j + 1) cout << " ^";
			else if(i % 3 == rest) cout << "--";
			else cout << "  ";

			if(cursor == 9*i + 3*j + 2 & i % 3 == rest) cout << "-^";
			else if(cursor == 9*i + 3*j + 2) cout << " ^";
			else if(i % 3 == rest) cout << "--";
			else cout << "  ";
		}
		cout << "|" << endl;
	} //for i

}
