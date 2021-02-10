#include <iostream>
using namespace std;
char Board[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
bool gameOver = false, tie = false;
int player = 0, moves = 0;
const int CHECKSIZE = 3, BOARDSIZE = 3;

bool checkBoard(bool& gameOver, bool& tie, int x, int y, char mark) {
	//check duong cheo
	for (int n = 0; n <= CHECKSIZE - 1; ++n) {
		int xmin = x + 1 - CHECKSIZE + n, xmax = x + n;
		int ymin = y + 1 - CHECKSIZE + n, ymax = y + n;
		if (xmax >= BOARDSIZE || ymax >= BOARDSIZE || xmin < 0 || ymin < 0) continue;
		bool flag = true;
		for (int m = 1; m <= CHECKSIZE; m++) {
			if (Board[x][y] != Board[x + m + n - CHECKSIZE][y + m + n - CHECKSIZE]) flag = false;
		}
		if (flag) {
			gameOver = true; break;
		}
	}
	//check hang, cot
	bool flag1 = true, flag2 = true;
	for (int i = 0; i < 3; i++) {
		if (Board[i][y] != Board[x][y]) flag1 = false;
		if (Board[x][i] != Board[x][y]) flag2 = false;
	}
	if (flag1 || flag2) gameOver = true;
	if (moves == 9 && !gameOver) tie = true;

	return true;
}

void printBoard() {
	cout << "--------------" << endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << "| " << Board[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "--------------" << endl;
}

void update() {
	
	int x, y;
	player = player % 2;
	char mark = (player % 2 == 0) ? 'X' : 'O';
	cout << "It's Player " << player + 1 << " turn!" << endl;
	do {
		cout << "Player " << player + 1 << " please enter your move (x y): ";
		cin >> x >> y;
	} while (x > 2 || y > 2 || x < 0 || y < 0 || Board[x][y] != ' ');
	Board[x][y] = mark;
	player++;
	moves++;
	checkBoard(gameOver, tie, x, y, mark);
}

int main() {
	cout << "\t GAME CARO C++" << endl;
	cout << "Player 1 : [X] \t Player 2 : [O]" << endl;
	while (!gameOver && !tie) {
		update();
		printBoard();
	}
	if (tie) cout << "DRAW!" << endl;
	else cout << "PLAYER " << player << " WON!" << endl;
	return 0;
}