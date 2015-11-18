#include "stdafx.h"
#include "numinput.cpp"

using namespace std;

char grid[25][80], input = '\0';
int i = 0, j = 0, k = 3, next_pipe = 3, score=0, coll=0;

class score_system
{
	int score;
	char name[11];

public:

	score_system()
	{
		score = 0;
		strcpy(name, "no_name");
	}

	void get_data()
	{
		score = ::score;
		fgets(name, 10 , stdin);
	}

	void show_data()
	{
		cout << score << ' ';
		puts(name);
	}

	int return_score()
	{
		return score;
	}
}s_obj;

void display_scores()
{
	void clear_disp(void);

	clear_disp();
	system("cls");

	/*To display H's*/
	for (i = 3; i < 8; ++i)
	{
		grid[i][20] = '*';
		grid[i][22] = '*';
		grid[i][32] = '*';
		grid[i][34] = '*';
	}
	for (i = 20; i < 23; ++i)
	{
		grid[5][i] = '*';
		grid[5][i + 12] = '*';
	}

	/*To display I*/
	for (i = 3; i < 8; ++i)
		grid[i][25] = '*';
	for (i = 24; i < 27; ++i)
	{
		grid[3][i] = '*';
		grid[7][i] = '*';
	}

	/*To display G*/
	for (i = 3; i < 8; ++i)
		grid[i][28] = '*';
	for (i = 28; i < 31; ++i)
	{
		grid[3][i] = '*';
		grid[7][i] = '*';
	}
	grid[5][30] = '*';
	grid[6][30] = '*';

	/*To display S's*/
	for (i = 37; i < 40; ++i)
	{
		grid[3][i] = '*';
		grid[5][i] = '*';
		grid[7][i] = '*';

		grid[3][i + 20] = '*';
		grid[5][i + 20] = '*';
		grid[7][i + 20] = '*';
	}
	grid[4][37] = '*';
	grid[6][39] = '*';
	grid[4][57] = '*';
	grid[6][59] = '*';

	/*To display C*/
	for (i = 3; i < 8; ++i)
		grid[i][41] = '*';
	for (i = 41; i < 44; ++i)
	{
		grid[3][i] = '*';
		grid[7][i] = '*';
	}

	/*To display O*/
	for (i = 3; i < 8; ++i)
	{
		grid[i][45] = '*';
		grid[i][47] = '*';
	}
	for (i = 45; i < 48; ++i)
	{
		grid[3][i] = '*';
		grid[7][i] = '*';
	}

	/*To display R*/
	for (i = 3; i < 8; ++i)
		grid[i][49] = '*';
	for (i = 49; i < 52; ++i)
	{
		grid[3][i] = '*';
		grid[5][i] = '*';
	}
	grid[4][51] = '*';
	grid[6][50] = '*';
	grid[7][51] = '*';

	/*To display E*/
	for (i = 3; i < 8; ++i)
		grid[i][53] = '*';
	for (i = 53; i < 56; ++i)
	{
		grid[3][i] = '*';
		grid[5][i] = '*';
		grid[7][i] = '*';
	}

	/*To display box*/
	for (i = 1; i < 10; ++i)
	{
		grid[i][18] = '*';
		grid[i][61] = '*';
	}
	for (i = 18; i < 62; ++i)
	{
		grid[1][i] = '*';
		grid[9][i] = '*';
	}

	/*To display grid*/
	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 80; ++j)
			cout << grid[i][j];
	}

	/*To display scores*/

	fstream s_file("s_file.src", ios::in | ios::binary | ios::ate);
	s_file.seekg(0);

	i = 0;
	cout << '\n';
	while ((s_file.eof()==0) && (i < 5))
	{
		s_file.read((char *)&s_obj, 13);
		cout << "\n\t\t\t\t" << i + 1 << ". ";
		s_obj.show_data();
		++i;
	}
	s_file.close();

	cout << '\n';
	system("pause");
}

void insert_score()
{
	fstream s_file("s_file.src", ios::out | ios::in | ios::binary | ios::ate);
	s_file.seekg(0);
	s_file.seekp(0);

	score_system temp;

	for (i = 0; i < 5; ++i)
	{
		s_file.read((char *)&temp, 13);
		
		if (s_obj.return_score() > temp.return_score())
			break;
	}

	if (i < 5)
	{
		fstream t_file("t_file.src", ios::out | ios::binary);
		s_file.seekg(0);
		for (j = 0; j < i; ++j)
		{
			s_file.read((char *)&temp, 13);
			t_file.write((char *)&temp, 13);
		}
		t_file.write((char *)&s_obj, 13);
		for (; j < 5; ++j)
		{
			s_file.read((char *)&temp, 13);
			t_file.write((char *)&temp, 13);
		}

		t_file.close();
		s_file.close();

		remove("s_file.src");
		rename("t_file.src", "s_file.src");	
	}
}


class bird
{
	int y_co[14];	//Y-Co-ordinates of the 14 points that make up the bird

public:

	void generator()
	{
		y_co[0] = 10;
		y_co[1] = 10;
		y_co[2] = 10;
		y_co[3] = 11;
		y_co[4] = 11;
		y_co[5] = 12;
		y_co[6] = 12;
		y_co[7] = 12;
		y_co[8] = 13;
		y_co[9] = 13;
		y_co[10] = 13;
		y_co[11] = 13;
		y_co[12] = 13;
		y_co[13] = 13;

		refresh_bird();
	}

	void refresh_bird()
	{
		grid[y_co[0]][4] = '*';
		grid[y_co[1]][5] = '*';
		grid[y_co[2]][6] = '*';
		grid[y_co[3]][3] = '*';
		grid[y_co[4]][7] = '*';
		grid[y_co[5]][3] = '*';
		grid[y_co[6]][8] = '*';
		grid[y_co[7]][9] = '*';
		grid[y_co[8]][4] = '*';
		grid[y_co[9]][5] = '*';
		grid[y_co[10]][6] = '*';
		grid[y_co[11]][7] = '*';
		grid[y_co[12]][8] = '*';
		grid[y_co[13]][9] = '*';
	}

	void move_up()
	{
		/*if ((y_co[1] - 6) > 0)
			for (i = 0; i < 14; ++i)
				y_co[i] -= 6;
		else
			for (i = 0; i < 14; ++i)
				y_co[i] -= y_co[1];*/
		for (i = 0; i < 14; ++i)
			y_co[i] -= 6;
	}

	void down_acc()
	{
		for (i = 0; i < 14; ++i)
			y_co[i] += 1;
	}

	void detect_coll()
	{
		if (y_co[13] == 23)
		{
			coll = 1;
			return;
		}
		
		for (i = 0; grid[y_co[13]][10 + i] == '*'; ++i);
		if ((i < 10) && (i > 0))
		{
			coll = 1;
			return;
		}

		for (i = 0; grid[y_co[7]][10 + i] == '*'; ++i);
		if ((i < 10) && (i > 0))
		{
			coll = 1;
			return;
		}

		for (i = 0; grid[y_co[4]][8 + i] == '*'; ++i);
		if ((i < 10) && (i > 0))
		{
			coll = 1;
			return;
		}

		for (i = 0; grid[y_co[2]][7 + i] == '*'; ++i);
		if ((i < 10) && (i > 0))
		{
			coll = 1;
			return;
		}

		for (i = 0; (grid[y_co[0]][2 - i] == '*') && (i < 3); ++i);
		if ((i < 3) && (i > 0) && (grid[y_co[0]][3] == '*'))
		{
			coll = 1;
			return;
		}

		for (i = 0; (grid[y_co[3]][2 - i]) && (i < 3); ++i);
		if ((i < 3) && (i > 0))
		{
			coll = 1;
			return;
		}

		for (i = 0; (grid[y_co[8]][2 - i] == '*') && (i < 3); ++i);
		if ((i < 3) && (i > 0))
		{
			coll = 1;
			return;
		}

		for (i = 0; (grid[y_co[5]][2 - i]) && (i < 3); ++i);
		if ((i < 3) && (i > 0))
		{
			coll = 1;
			return;
		}
	}
}b1;

class pipe
{
	int upper_l;	//Length of upper section of a pipe
	int lower_l;	//Length of lower section of a pipe
	int breadth;	//Horizontal length of a pipe
	static int mid_gap_static;	//Gap between upper and lower sections of pipe
	static int next_start_co;	
	static int first_pipe;	//Tells whether the pipe is the first one to be displayed
	int mid_gap;	//Same as mid_gap_static, different use
	int start_co;
	int end_co;
	int eop;	//End of Pipe. Whether pipe has ended or not
	int begin_end;	//Tells whether the pipe has begun to exit the screen or not
	int begin_pipe;	//Tells whether the pipe has begun to enter the screen or not

public:

	void generator()
	{
		generate_err:
		int move_gap = 0;
		srand(time(NULL));
		start_co = next_start_co;
		end_co = start_co + 10;
		breadth = 10;
		eop = 0;
		begin_end = 0;
		begin_pipe = 0;
		upper_l = 0;
		lower_l = 0;
		if (first_pipe == 0)
		{
			move_gap = rand() % 6 + 1;
			if (move_gap > 3)
			{
				if (mid_gap_static + move_gap + 7 > 22)
					goto generate_err;
				mid_gap_static = mid_gap_static + move_gap;
			}
			else
			{
				if (mid_gap_static - move_gap - 2 - 7 < 0)
					goto generate_err;
				mid_gap_static = mid_gap_static - 2 - move_gap;
			}
		}
		mid_gap = mid_gap_static;
		first_pipe = 0;
		for (i = 0; i < mid_gap - 7; ++i)
		{
			grid[i][start_co] = '*';
			grid[i][start_co + 10] = '*';
			++upper_l;
		}
		++upper_l;
		for (i = 0; i < 11; ++i)
			grid[mid_gap - 7][start_co+i] = '*';
		for (i = 0; i < 11; ++i)
			grid[mid_gap + 6][start_co + i] = '*';
		for (i = mid_gap + 7; i < 23; ++i)
		{
			grid[i][start_co] = '*';
			grid[i][start_co + 10] = '*';
			++lower_l;
		}
		++lower_l;
		next_start_co = start_co + 32;
	}

	void refresh_pipe()
	{
		if (eop == 0)
		{
			--start_co;
			if (start_co < 0)
			{
				--breadth;
				++start_co;
				begin_end = 1;
			}

			--end_co;
			if (end_co < 0)
			{
				eop = 1;
				return;
			}

			if (begin_end == 1)
			{
				for (i = 0; i < upper_l; ++i)
					grid[i][end_co] = '*';
				for (i = 0; i < breadth; ++i)
				{
					grid[upper_l - 1][i] = '*';
					grid[upper_l + 12][i] = '*';
				}
				for (i = upper_l + 12; i < 23; ++i)
					grid[i][end_co] = '*';
			}

			else if (begin_pipe == 1)
			{
				for (i = 0; i < upper_l; ++i)
					grid[i][start_co] = '*';
				for (i = upper_l + 12; i < 23; ++i)
					grid[i][start_co] = '*';
				for (i = 79; i > 79-breadth; --i)
				{
					grid[upper_l - 1][i] = '*';
					grid[upper_l + 12][i] = '*';
				}
				++breadth;
				if ((breadth+1) > 11)
					begin_pipe = 0;
			}

			else
			{
				for (i = 0; i < mid_gap - 7; ++i)
				{
					grid[i][start_co] = '*';
					grid[i][start_co + 10] = '*';
				}
				for (i = 0; i < 11; ++i)
					grid[mid_gap - 7][start_co + i] = '*';
				for (i = 0; i < 11; ++i)
					grid[mid_gap + 6][start_co + i] = '*';
				for (i = mid_gap + 7; i < 23; ++i)
				{
					grid[i][start_co] = '*';
					grid[i][start_co + 10] = '*';
				}
			}
		}
	}

	void start_pipe()
	{
	    start_err:
		int move_gap = 0;

		start_co = 80;
		end_co = 90;
		breadth = 0;
		eop = 0;
		begin_end = 0;
		begin_pipe = 1;
		upper_l = 0;
		lower_l = 0;

		move_gap = rand() % 6 + 1;
		if (move_gap > 3)
		{
			if (mid_gap_static + move_gap + 7 > 22)
				goto start_err;
			mid_gap_static = mid_gap_static + move_gap;
		}
		else
		{
			if (mid_gap_static - move_gap - 2 - 7 < 0)
				goto start_err;
			mid_gap_static = mid_gap_static - 2 - move_gap;
		}
		mid_gap = mid_gap_static;

		for (i = 0; i < mid_gap - 7; ++i)
			++upper_l;
		++upper_l;
		for (i = mid_gap + 7; i < 23; ++i)
			++lower_l;
		++lower_l;
	}

	void reset_static_variables()
	{
		mid_gap_static = 12;
		next_start_co = 34;
		first_pipe = 1;
	}
}p1, p2, p3;

int pipe::mid_gap_static = 12;
int pipe::next_start_co = 34;
int pipe::first_pipe = 1;

void enter_pipe()	//Enter new pipes in the game
{
	switch (next_pipe % 3)
	{
	case 0: p3.start_pipe();
		break;
	case 1: p1.start_pipe();
		break;
	case 2: p2.start_pipe();
		break;
	}
	++next_pipe;
}


void disp()
{
	int i = 0;

	grid[23][69] = 'S';
	grid[23][70] = 'c';
	grid[23][71] = 'o';
	grid[23][72] = 'r';
	grid[23][73] = 'e';
	grid[23][74] = '=';
	grid[23][76] = 48 + (score / 10);
	grid[23][77] = 48 + (score % 10);

	for (i = 0; i < 68; ++i)
		grid[23][i] = '*';
	for (i = 0; i < 24; ++i)
	{
		for (j = 0; j < 80; ++j)
			cout << grid[i][j];
	}
}

void clear_disp()	//Clear the grid
{
	for (i = 0; i < 25; ++i)
	{
		for (j = 0; j < 80; ++j)
			grid[i][j] = ' ';
	}
}


void countdown(int number)	//Display the countdown number as passed in the argument
{
	int k = 0;

	if (number == 0)
	{
		for (j = 7; j < 14; ++j)
		{
			for (k = 20; k < 25; ++k)
				grid[j][k] = ' ';
		}
	}

	if (number == 1)
	{
		grid[7][20] = '*';
		grid[7][21] = '*';
		grid[7][22] = '*';
		grid[8][22] = '*';
		grid[9][22] = '*';
		grid[10][22] = '*';
		grid[11][22] = '*';
		grid[12][22] = '*';
		grid[13][20] = '*';
		grid[13][21] = '*';
		grid[13][22] = '*';
		grid[13][23] = '*';
		grid[13][24] = '*';
	}

	if (number == 2)
	{
		grid[7][20] = '*';
		grid[7][21] = '*';
		grid[7][22] = '*';
		grid[7][23] = '*';
		grid[7][24] = '*';
		grid[8][24] = '*';
		grid[9][24] = '*';
		grid[10][20] = '*';
		grid[10][21] = '*';
		grid[10][22] = '*';
		grid[10][23] = '*';
		grid[10][24] = '*';
		grid[11][20] = '*';
		grid[12][20] = '*';
		grid[13][20] = '*';
		grid[13][21] = '*';
		grid[13][22] = '*';
		grid[13][23] = '*';
		grid[13][24] = '*';
	}

	if (number == 3)
	{
		grid[7][20] = '*';
		grid[7][21] = '*';
		grid[7][22] = '*';
		grid[7][23] = '*';
		grid[7][24] = '*';
		grid[8][24] = '*';
		grid[9][24] = '*';
		grid[10][21] = '*';
		grid[10][22] = '*';
		grid[10][23] = '*';
		grid[10][24] = '*';
		grid[11][24] = '*';
		grid[12][24] = '*';
		grid[13][20] = '*';
		grid[13][21] = '*';
		grid[13][22] = '*';
		grid[13][23] = '*';
		grid[13][24] = '*';
	}
}


void score_calc()	//Increment score upon successful crossing of a pipe
{
	if ((grid[0][3] == '*') && (grid[0][25] == '*'))
	{
		++score;
		cout << '\a';
	}
}


void input_function()	//Responsible for taking input from user. Used in a separate thread
{
	while ((input != 27) && (coll == 0))
		input = _getch();
}


void boom()	//Display the word BOOM when the bird crashes
{
	/*To display B*/
	grid[6][29] = '*';
	for (i = 6; i < 13; ++i)
	{
		grid[i][29] = '*';
		grid[i][33] = '*';
	}
	for (i = 29; i < 34; ++i)
	{
		grid[6][i] = '*';
		grid[9][i] = '*';
		grid[12][i] = '*';
	}

	/*To display O's*/
	for (i = 6; i < 13; ++i)
	{
		grid[i][35] = '*';
		grid[i][39] = '*';
		grid[i][41] = '*';
		grid[i][45] = '*';
	}
	for (i = 35; i < 40; ++i)
	{
		grid[6][i] = '*';
		grid[12][i] = '*';
	}
	for (i = 41; i < 46; ++i)
	{
		grid[6][i] = '*';
		grid[12][i] = '*';
	}

	/*To display M*/
	for (i = 6; i < 13; ++i)
	{
		grid[i][47] = '*';
		grid[i][49] = '*';
		grid[i][51] = '*';
	}
	for (i = 47; i < 52; ++i)
		grid[6][i] = '*';
}

void crash()	//Display crash screen and take user name as input
{
	int k = 0;

	clear_disp();
	boom();
	
	/*To display small box*/
	for (i = 4; i < 15; ++i)
	{
		grid[i][27] = '*';
		grid[i][53] = '*';
	}
	for (i = 27; i < 54; ++i)
	{
		grid[4][i] = '*';
		grid[14][i] = '*';
	}

	/*To display grid*/
	system("cls");
	for (i = 0; i < 15; ++i)
	{
		for (j = 0; j < 80; ++j)
			cout << grid[i][j];
	}

	for (k = 0; k < 2; ++k)
	{
		_sleep(500);

		clear_disp();
		boom();

		/*To display big box*/
		for (i = 2; i < 17; ++i)
		{
			grid[i][25] = '*';
			grid[i][55] = '*';
		}
		for (i = 25; i < 56; ++i)
		{
			grid[2][i] = '*';
			grid[16][i] = '*';
		}

		/*To display grid*/
		system("cls");
		for (i = 0; i < 17; ++i)
		{
			for (j = 0; j < 80; ++j)
				cout << grid[i][j];
		}

		_sleep(500);

		clear_disp();
		boom();

		/*To display small box*/
		for (i = 4; i < 15; ++i)
		{
			grid[i][27] = '*';
			grid[i][53] = '*';
		}
		for (i = 27; i < 54; ++i)
		{
			grid[4][i] = '*';
			grid[14][i] = '*';
		}

		/*To display grid*/
		system("cls");
		for (i = 0; i < 15; ++i)
		{
			for (j = 0; j < 80; ++j)
				cout << grid[i][j];
		}
	}

	/*To display score*/
	cout << "\n\n\n\n\t\t\t\t  Score: " << score;
	cout << "\n\n\t\t\t       Name: ";
	s_obj.get_data();

	insert_score();
	display_scores();
}


void flappy_bird()	//Display Flappy Bird in box
{
	/*To display F*/
	grid[5][20] = '*';
	grid[5][21] = '*';
	grid[5][22] = '*';
	grid[6][20] = '*';
	grid[7][20] = '*';
	grid[7][21] = '*';
	grid[8][20] = '*';
	grid[9][20] = '*';

	/*To display L*/
	for (i = 5; i < 10; ++i)
		grid[i][24] = '*';
	grid[9][25] = '*';
	grid[9][26] = '*';

	/*To display A*/
	for (i = 5; i < 10; ++i)
	{
		grid[i][28] = '*';
		grid[i][30] = '*';
	}
	grid[5][29] = '*';
	grid[7][29] = '*';

	/*To display P's*/
	for (i = 5; i < 10; ++i)
	{
		grid[i][32] = '*';
		grid[i][36] = '*';
	}
	for (i = 5; i < 8; ++i)
	{
		grid[i][34] = '*';
		grid[i][38] = '*';
	}
	grid[5][33] = '*';
	grid[7][33] = '*';
	grid[5][37] = '*';
	grid[7][37] = '*';

	/*To display Y*/
	for (i = 5; i < 8; ++i)
	{
		grid[i][40] = '*';
		grid[i][42] = '*';
	}
	for (i = 7; i < 10; ++i)
		grid[i][41] = '*';

	/*To display B*/
	for (i = 5; i < 10; ++i)
	{
		grid[i][45] = '*';
		grid[i][47] = '*';
	}
	grid[5][46] = '*';
	grid[7][46] = '*';
	grid[9][46] = '*';

	/*To display I*/
	for (i = 5; i < 10; ++i)
		grid[i][50] = '*';
	for (i = 49; i < 52; ++i)
	{
		grid[5][i] = '*';
		grid[9][i] = '*';
	}

	/*To display R*/
	for (i = 5; i < 10; ++i)
		grid[i][53] = '*';
	for (i = 53; i < 56; ++i)
	{
		grid[5][i] = '*';
		grid[7][i] = '*';
	}
	grid[6][55] = '*';
	grid[8][54] = '*';
	grid[9][55] = '*';

	/*To display D*/
	for (i = 5; i < 10; ++i)
	{
		grid[i][57] = '*';
		grid[i][59] = '*';
	}
	for (i = 57; i < 60; ++i)
	{
		grid[5][i] = '*';
		grid[9][i] = '*';
	}

	/*To display box*/
	for (i = 18; i < 63; ++i)
	{
		grid[3][i] = '*';
		grid[11][i] = '*';
	}
	for (i = 3; i < 12; ++i)
	{
		grid[i][18] = '*';
		grid[i][62] = '*';
	}
}

void main_menu()	//Handle the main menu of the game
{
	clear_disp();

	flappy_bird();

	/*To display Play*/
	grid[14][37] = '1';
	grid[14][38] = '.';
	grid[14][40] = 'P';
	grid[14][41] = 'l';
	grid[14][42] = 'a';
	grid[14][43] = 'y';

	/*To display High Scores*/
	grid[16][33] = '2';
	grid[16][34] = '.';
	grid[16][36] = 'H';
	grid[16][37] = 'i';
	grid[16][38] = 'g';
	grid[16][39] = 'h';
	grid[16][41] = 'S';
	grid[16][42] = 'c';
	grid[16][43] = 'o';
	grid[16][44] = 'r';
	grid[16][45] = 'e';
	grid[16][46] = 's';

	/*To display Instructions*/
	grid[18][33] = '3';
	grid[18][34] = '.';
	grid[18][36] = 'I';
	grid[18][37] = 'n';
	grid[18][38] = 's';
	grid[18][39] = 't';
	grid[18][40] = 'r';
	grid[18][41] = 'u';
	grid[18][42] = 'c';
	grid[18][43] = 't';
	grid[18][44] = 'i';
	grid[18][45] = 'o';
	grid[18][46] = 'n';
	grid[18][47] = 's';

	/*To display Exit*/
	grid[20][37] = '4';
	grid[20][38] = '.';
	grid[20][40] = 'E';
	grid[20][41] = 'x';
	grid[20][42] = 'i';
	grid[20][43] = 't';

	/*To display Choice*/
	grid[23][35] = 'C';
	grid[23][36] = 'h';
	grid[23][37] = 'o';
	grid[23][38] = 'i';
	grid[23][39] = 'c';
	grid[23][40] = 'e';
	grid[23][41] = ':';

	/*Display grid*/
	system("cls");
	for (i = 0; i < 23; ++i)
	{
		for (j = 0; j < 80; ++j)
			cout << grid[i][j];
	}
	for (i = 0; i < 43; ++i)
		cout << grid[23][i];
}

void diff_choice_disp()
{
	clear_disp();
	
	flappy_bird();

	/*To display Easy*/
	grid[13][36] = '1';
	grid[13][37] = '.';
	grid[13][39] = 'E';
	grid[13][40] = 'a';
	grid[13][41] = 's';
	grid[13][42] = 'y';

	/*To display Medium*/
	grid[15][35] = '2';
	grid[15][36] = '.';
	grid[15][38] = 'M';
	grid[15][39] = 'e';
	grid[15][40] = 'd';
	grid[15][41] = 'i';
	grid[15][42] = 'u';
	grid[15][43] = 'm';

	/*To display Hard*/
	grid[17][36] = '3';
	grid[17][37] = '.';
	grid[17][39] = 'H';
	grid[17][40] = 'a';
	grid[17][41] = 'r';
	grid[17][42] = 'd';

	/*To display Choice*/
	grid[19][35] = 'C';
	grid[19][36] = 'h';
	grid[19][37] = 'o';
	grid[19][38] = 'i';
	grid[19][39] = 'c';
	grid[19][40] = 'e';
	grid[19][41] = ':';

	/*Display grid*/
	system("cls");
	for (i = 0; i < 19; ++i)
	{
		for (j = 0; j < 80; ++j)
			cout << grid[i][j];
	}
	for (i = 0; i < 43; ++i)
		cout << grid[19][i];
}

void start_game()	//Handles the execution of the actual game
{
	start_game:
	
	void end_game(void);
	i = 0, j = 0;

	int diff = 0, diff_in_err = 0;

	diff_choice_disp();
	diff_in_err = int_num(diff);
	if (diff_in_err != 0)
		goto start_game;

	switch (diff)
	{
	case 1: diff = 40;
		break;
	case 2: diff = 34;
		break;
	case 3: diff = 28;
		break;
	default: goto start_game;
	}
	
	system("cls");
	clear_disp();

	p1.generator();
	p2.generator();
	b1.generator();

	for (i = 3; i > 0; --i)
	{
		countdown(0);
		system("cls");
		countdown(i);
		disp();
		_sleep(700);
	}

	countdown(0);
	disp();
	thread input_thread(input_function);

	while (input != 27)
	{
		if (k == 20)
		{
			k = 32;
			enter_pipe();
		}
		else if (k % 32 == 0)
			enter_pipe();

		if (input == 32)
		{
			b1.move_up();
			input = 0;
		}

		clear_disp();
		p1.refresh_pipe();
		p2.refresh_pipe();
		p3.refresh_pipe();
		b1.down_acc();
		b1.refresh_bird();
		score_calc();
		b1.detect_coll();
		if (coll == 1)
			input = 27;
		system("cls");
		disp();
		++k;
		_sleep(diff);
	}
	input_thread.detach();
	input_thread.~thread();
	
	if (coll == 0)
		end_game();
	else
		crash();

	return;
}

void instruct()		//Display the instructions
{
	system("cls");
	cout << "\t\t\t\t  Instructions\n";
	for (i = 0; i < 80; ++i)
		cout << '*';
	cout << "\n\n";
	cout << "1. The objective of this game is to get the bird across the pipes safely,\n   without it touching any pipe or the ground.\n\n";
	cout << "2. To make the bird fly up, simply press the Spacebar.\n\n";
	cout << "3. For every pipe the bird safely passes, one point is awarded.\n\n";
	cout << "4. Touching any pipe or the ground ends the game instantly.\n\n";
	cout << "5. The score is displayed in the bottom-left corner of the score.\n\n";
	cout << "6. To leave the game in the middle, simply press the Escape key.\n\n";

	system("pause");
	
	return;
}

void exit_game()	//Display the exit screen
{
	clear_disp();

	flappy_bird();

	/*To display credits*/
	grid[13][36] = 'M';
	grid[13][37] = 'a';
	grid[13][38] = 'd';
	grid[13][39] = 'e';
	grid[13][41] = 'B';
	grid[13][42] = 'y';
	grid[15][32] = 'S';
	grid[15][33] = 'u';
	grid[15][34] = 'd';
	grid[15][35] = 'h';
	grid[15][36] = 'a';
	grid[15][37] = 'n';
	grid[15][38] = 's';
	grid[15][39] = 'h';
	grid[15][40] = 'u';
	grid[15][42] = 'G';
	grid[15][43] = 'u';
	grid[15][44] = 'p';
	grid[15][45] = 't';
	grid[15][46] = 'a';

	/*Display grid*/
	system("cls");
	for (i = 0; i < 16; ++i)
	{
		for (j = 0; j < 80; ++j)
			cout << grid[i][j];
	}
	cout << "\n\n";
	system("pause");
}

void end_game()		//End the currently playing game. When the user purposely exits.
{
	clear_disp();

	flappy_bird();

	system("cls");

	for (i = 0; i < 12; ++i)
	{
		for (j = 0; j < 80; ++j)
			cout << grid[i][j];
	}

	/*To display score*/
	cout << "\n\n\t\t\t\t  Score: " << score;
	cout << "\n\n\t\t\t       Name: ";
	s_obj.get_data();

	insert_score();
	display_scores();
}



int main()
{
	int ch = 0 , in_err=0;

start:

	ch = 0, in_err = 0, i = 0, j = 0, k = 3, next_pipe = 3, score = 0, coll = 0, input = 0;
	p1.reset_static_variables();

	clear_disp();
	system("cls");

	main_menu();
	in_err = int_num(ch);
	if (in_err != 0)
		goto start;

	switch (ch)
	{
	case 1: start_game();
		goto start;
	case 2: display_scores();
		goto start;
	case 3: instruct();
		goto start;
	case 4: break;
	default: goto start;
	}

	exit_game();

	return 0;
}