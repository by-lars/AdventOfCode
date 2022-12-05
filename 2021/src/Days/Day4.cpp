#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

#include "Core/Reflection.h"
#include "Core/Logging.h"

struct BingoBoard
{
	int Cells[5][5];
	bool didWin = false;

	bool MarkIfPresent(int number) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (Cells[i][j] == number) {
					Cells[i][j] = -1;
					return true;
				}
			}
		}

		return false;
	}

	int GetRemainingSum() {
		int sum = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (Cells[i][j] > 0) {
					sum += Cells[i][j];
				}
			}
		}
		return sum;
	}

	bool DidWin() {
		for (int i = 0; i < 5; i++) {
			if (Cells[i][0] < 0 && Cells[i][1] < 0 && Cells[i][2] < 0 && Cells[i][3] < 0 && Cells[i][4] < 0) {
				didWin = true;
				return true;
			}
		}
		for (int j = 0; j < 5; j++) {
			if (Cells[0][j] < 0 && Cells[1][j] < 0 && Cells[2][j] < 0 && Cells[3][j] < 0 && Cells[4][j] < 0) {
				didWin = true;
				return true;
			}
		}

		return false;
	}

	void Print() {
		std::cout << std::endl;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				std::cout << std::setw(3) << Cells[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};


void GetWinnerBoard(std::vector<BingoBoard>& Boards, std::vector<int>& Numbers, BingoBoard* Out_WinnerBoard, int* Out_WinnerNumber, BingoBoard* Out_LoserBoard, int* Out_LoserNumber){
	int nBoardsLeft = Boards.size();
	bool firstWin = true;

	for (int num : Numbers) {
		for (auto& board : Boards) {
			if (board.didWin) {
				continue;
			}

			board.MarkIfPresent(num);

			if (board.DidWin()) {
				nBoardsLeft--;
				if (nBoardsLeft == 0) {
					*Out_LoserBoard = board;
					*Out_LoserNumber = num;
					return;
				}

				if (firstWin) {
					*Out_WinnerBoard = board;
					*Out_WinnerNumber = num;
					firstWin = false;
				}
			}
		}
	}
}

AOC_DAY(4A) {
	std::vector<BingoBoard> Boards;
	std::vector<int> Numbers;
	
	std::string instStr;
	file >> instStr;
	file.ignore(1, '\n');

	std::stringstream ss(instStr);
	for (int i; ss >> i;) {
		Numbers.push_back(i);
		if (ss.peek() == ',')
			ss.ignore();
	}

	BingoBoard tmpBoard;

	int row = 0;
	while (file >> tmpBoard.Cells[row][0] >> tmpBoard.Cells[row][1] >> tmpBoard.Cells[row][2] >> tmpBoard.Cells[row][3] >> tmpBoard.Cells[row][4]) {
		row++;
		if (row > 4) {
			row = 0;
			Boards.push_back(tmpBoard);
		}
	}

	BingoBoard winner;
	BingoBoard loser;
	int winnerNumber = 0;
	int loserNumber = 0;
	GetWinnerBoard(Boards, Numbers, &winner, &winnerNumber, &loser, &loserNumber);

	int winnerSum = winner.GetRemainingSum();
	int loserSum = loser.GetRemainingSum();

	return winnerSum * winnerNumber;
}

AOC_DAY(4B) {
	std::vector<BingoBoard> Boards;
	std::vector<int> Numbers;

	std::string instStr;
	file >> instStr;
	file.ignore(1, '\n');

	std::stringstream ss(instStr);
	for (int i; ss >> i;) {
		Numbers.push_back(i);
		if (ss.peek() == ',')
			ss.ignore();
	}

	BingoBoard tmpBoard;

	int row = 0;
	while (file >> tmpBoard.Cells[row][0] >> tmpBoard.Cells[row][1] >> tmpBoard.Cells[row][2] >> tmpBoard.Cells[row][3] >> tmpBoard.Cells[row][4]) {
		row++;
		if (row > 4) {
			row = 0;
			Boards.push_back(tmpBoard);
		}
	}

	BingoBoard winner;
	BingoBoard loser;
	int winnerNumber = 0;
	int loserNumber = 0;
	GetWinnerBoard(Boards, Numbers, &winner, &winnerNumber, &loser, &loserNumber);

	int winnerSum = winner.GetRemainingSum();
	int loserSum = loser.GetRemainingSum();

	return loserSum * loserNumber;
}