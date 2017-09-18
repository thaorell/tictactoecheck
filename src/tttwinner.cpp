// Name        : tttwinner.cpp
// Author1      Charles Thao cthao19@bu.edu
// Author2		Priyal Verma priyalv@bu.edu
// Version     :0.0.112
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style

#include <iostream>
#include <cstddef>
using namespace std;
bool CheckWinner(char board[3][3],char player);
int occurrences (char board [3][3], char player);
bool invalid (char board[3][3]);
int main() {
	while (true)	{
	string input;
	cin>>input;
	char board [3][3];
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			board[i][j]=input[3*i+j];
			}
		}
	if (input.length() < 9 ) break;
	if (CheckWinner(board,'o')== true and CheckWinner(board,'x')==true)
		cout <<"invalid"<<endl;
	else if (invalid(board) == true)
		cout <<"invalid"<<endl;
	else if (CheckWinner(board,'x')== true)
		cout << "x wins"<< endl;
	else if (CheckWinner(board,'o')== true)
		cout << "o wins"<<endl;
	else if (occurrences(board,'#')==0)
		cout <<"tie game"<<endl;
	else
		cout<< "continue"<<endl;
	}
	return 0;

}

bool CheckWinner(char board[3][3],char player) {
	for (int i = 0; i < 3; i++){
	    if (board[i][0] == player and  board [i][1] == player and board [i][2]== player)
	        return true;
	    if (board[0][i] == player and board[1][i] == player and board[2][i]==player)
	        return true;
	    if ((board[0][0] == player and board[1][1] == player and board[2][2]== player) or
	    	    (board[0][2] == player and board[1][1] == player and board[2][0]== player))
	    	return true;
	}
	return false;
}

int occurrences (char board [3][3], char player) {
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == player)
				count++; }
	}
	return count;
}

bool invalid (char board[3][3])
{
	if (occurrences (board, 'x') > occurrences(board,'o')+1)
		return true;
	if (occurrences (board,'o') > occurrences(board,'x'))
		return true;
	return false;
}
