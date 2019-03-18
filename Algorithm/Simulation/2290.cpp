#include <iostream>
#include <string>
#include <vector>
using namespace std;

void first(vector<vector<char>> &M, int start, int row, int col) {

	int r_mid = (start + row) / 2;
	int h_mid = col / 2;



	for (int y = 1; y < h_mid; y++) {
		M[y][row-1] = '|';

	}

	for (int y = h_mid + 1; y < col - 1; y++) {
		M[y][row - 1] = '|';

	}

}

void second(vector<vector<char>> &M, int start, int row, int col) {

	int r_mid = (start + row) / 2;
	int h_mid = col / 2;



	for (int x = start + 1; x < row - 1; x++) {
		M[0][x] = '-';
		M[h_mid][x] = '-';
		M[col - 1][x] = '-';

	}



	for (int y = 1; y < h_mid; y++) {
		M[y][row - 1] = '|';

	}

	for (int y = h_mid + 1; y < col - 1; y++) {
		M[y][start] = '|';

	}

}

void third(vector<vector<char>> &M, int start, int row, int col) {

	int r_mid = (start + row) / 2;
	int h_mid = col / 2;



	for (int x = start + 1; x < row - 1; x++) {
		M[0][x] = '-';
		M[h_mid][x] = '-';
		M[col - 1][x] = '-';

	}



	for (int y = 1; y < h_mid; y++) {
		M[y][row - 1] = '|';

	}

	for (int y = h_mid + 1; y < col - 1; y++) {
		M[y][row - 1] = '|';

	}
}


void fourth(vector<vector<char>> &M, int start, int row, int col) {

	int r_mid = (start + row) / 2;
	int h_mid = col / 2;



	for (int x = start + 1; x < row - 1; x++) {
		M[h_mid][x] = '-';

	}



	for (int y = 1; y < h_mid; y++) {
		M[y][row - 1] = '|';
		M[y][start] = '|';

	}

	for (int y = h_mid + 1; y < col - 1; y++) {
		M[y][row - 1] = '|';

	}
}


void fifth(vector<vector<char>> &M, int start, int row, int col) {


	int r_mid = (start + row) / 2;
	int h_mid = col / 2;



	for (int x = start + 1; x < row - 1; x++) {
		M[0][x] = '-';
		M[h_mid][x] = '-';
		M[col - 1][x] = '-';

	}



	for (int y = 1; y < h_mid; y++) {
		M[y][start] = '|';

	}

	for (int y = h_mid + 1; y < col - 1; y++) {
		M[y][row-1] = '|';

	}
}

void sixth(vector<vector<char>> &M, int start, int row, int col) {


	int r_mid = (start + row) / 2;
	int h_mid = col / 2;



	for (int x = start + 1; x < row - 1; x++) {
		M[0][x] = '-';
		M[h_mid][x] = '-';
		M[col - 1][x] = '-';

	}



	for (int y = 1; y < h_mid; y++) {
		M[y][start] = '|';

	}


	
	for (int y = h_mid + 1; y < col - 1; y++) {
		M[y][start] = '|';
		M[y][row - 1] = '|';

	}
	
}



void seventh(vector<vector<char>> &M, int start, int row, int col) {

	int r_mid = (start + row) / 2;
	int h_mid = col / 2;



	for (int x = start + 1; x < row - 1; x++) {
		M[0][x] = '-';

	}



	for (int y = 1; y < h_mid; y++) {
		M[y][row - 1] = '|';

	}

	for (int y = h_mid + 1; y < col - 1; y++) {
		M[y][row - 1] = '|';

	}
}



void eighth(vector<vector<char>> &M, int start, int row, int col) {


	int r_mid = (start + row) / 2;
	int h_mid = col / 2;



	for (int x = start + 1; x < row - 1; x++) {
		M[0][x] = '-';
		M[h_mid][x] = '-';
		M[col - 1][x] = '-';

	}



	for (int y = 1; y < h_mid; y++) {
		M[y][start] = '|';
		M[y][row-1] = '|';

	}



	for (int y = h_mid + 1; y < col - 1; y++) {
		M[y][start] = '|';
		M[y][row - 1] = '|';

	}

}


void nineth(vector<vector<char>> &M, int start, int row, int col) {


	int r_mid = (start + row) / 2;
	int h_mid = col / 2;



	for (int x = start + 1; x < row - 1; x++) {
		M[0][x] = '-';
		M[h_mid][x] = '-';
		M[col - 1][x] = '-';

	}



	for (int y = 1; y < h_mid; y++) {
		M[y][start] = '|';
		M[y][row - 1] = '|';

	}



	for (int y = h_mid + 1; y < col - 1; y++) {
		M[y][row - 1] = '|';

	}

}



void zero(vector<vector<char>> &M, int start, int row, int col) {


	int r_mid = (start + row) / 2;
	int h_mid = col / 2;



	for (int x = start + 1; x < row - 1; x++) {
		M[0][x] = '-';
		M[col - 1][x] = '-';

	}



	for (int y = 1; y < h_mid; y++) {
		M[y][start] = '|';
		M[y][row - 1] = '|';

	}



	for (int y = h_mid + 1; y < col - 1; y++) {
		M[y][start] = '|';
		M[y][row - 1] = '|';

	}

}
void output(vector<vector<char>> &M, int row, int col) {

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cout << M[i][j];
		}
		cout << "\n";
	}
}


int main(void) {
	int s;
	string str;
	cin >> s >> str;


	int row = (s + 2) * str.size()+str.size()-1;
	int col = (2 * s + 3);
	vector<vector<char>> M(col, vector<char>(row,' '));
	
	int start = -(s + 2);


	for (int i = 0; i < str.size(); i++) {
		start = start + (s + 2);
		int end = start + (s + 2);
		switch (str[i])
		{

		case '1':
			first(M, start, end, col);
			
			break;

		case '2':
			second(M, start, end, col);
			
			break;

		case '3':
			third(M, start, end, col);
			break;

		case '4':
			fourth(M, start, end, col);
			break;

		case '5':
			fifth(M, start, end, col);
			break;

		case '6':
			sixth(M, start, end, col);
			break;

		case '7':
			seventh(M, start, end, col);
			break;

		case '8':
			eighth(M, start, end, col);
			break;

		case '9':
			nineth(M, start, end, col);
			break;

		case '0':
			zero(M, start, end, col);
			break;

		}

		start++;
	}
	
	output(M, row, col);
	
	return 0;

}




