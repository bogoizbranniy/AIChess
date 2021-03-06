#include <iostream>
#include <string>
#include <vector>
#include "chess.h"

float blackKingScore[8][8] = { 0.5,  0.0 , 0.7,  0.0,  0.0,  0.0,  0.7,  0.5,
                                 0.5,  0.5,  0.0,  0.0,  0.0,  0.0,  0.5,  0.5,
                                -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
                                -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
                                -1.0, -1.0, -2.0, -2.0, -2.0, -2.0, -1.0, -1.0,
                                -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
                                -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
                                -2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0 };

float whiteKingScore[8][8] = { -1.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0,
                                -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
                                -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
                                -1.0, -1.0, -2.0, -2.0, -2.0, -1.0, -1.0, -1.0,
                                -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
                                -1.0, -1.0, -1.0, -1.0, -2.0, -1.0, -1.0, -1.0,
                                 0.5,  0.5,  0.0,  0.0,  0.0,  0.0,  0.5,  0.5,
                                 0.5,  0.0,  0.7,  0.0,  0.0,  0.0,  0.7,  0.5 };

float blackBishopScore[8][8] = { -2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0,
                                -1.0,  0.5,  0.0,  0.0,  0.0,  0.0,  0.5, -1.0,
                                -1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, -1.0,
                                -1.0,  0.0,  1.0,  1.0,  1.0,  1.0,  0.0, -1.0,
                                -1.0,  0.5,  0.5,  1.0,  1.0,  0.5,  0.5, -1.0,
                                -1.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -1.0,
                                -1.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -1.0,
                                -2.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -2.0 };

float whiteBishopScore[8][8] = { -2.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -2.0,
                                -1.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -1.0,
                                -1.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -1.0,
                                -1.0,  0.5,  0.5,  1.0,  1.0,  0.5,  0.5, -1.0,
                                -1.0,  0.0,  1.0,  1.0,  1.0,  1.0,  0.0, -1.0,
                                -1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, -1.0,
                                -1.0,  0.5,  0.0,  0.0,  0.0,  0.0,  0.5, -1.0,
                                -2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0 };

float blackKnightScore[8][8] = { -5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0,
                                -4.0, -2.0,  0.0,  0.5,  0.5,  0.0, -2.0, -4.0,
                                -3.0,  0.0,  1.5,  1.0,  1.0,  1.5,  0.0, -3.0,
                                -3.0,  0.5,  1.0,  1.5,  1.5,  1.0,  0.5, -3.0,
                                -3.0,  0.0,  1.0,  1.5,  1.5,  1.0,  0.0, -3.0,
                                -3.0,  0.5,  0.5,  1.0,  1.0,  0.5,  0.5, -3.0,
                                -4.0, -2.0,  0.0,  0.5,  0.5,  0.0, -2.0, -4.0,
                                -5.0, -4.0, -3.0, -3.0, -3.0, -3.0,  4.0, -5.0 };

float whiteKnightScore[8][8] = { -5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0,
                                -4.0, -2.0,  0.0,  0.0,  0.0,  0.0, -2.0, -4.0,
                                -3.0,  0.0,  0.5,  1.0,  1.0,  0.5,  0.5, -3.0,
                                -3.0,  0.0,  1.0,  1.5,  1.5,  1.0,  0.0, -3.0,
                                -3.0,  0.0,  1.0,  1.5,  1.5,  1.0,  0.0, -3.0,
                                -3.0,  0.5,  1.5,  1.0,  1.0,  1.5,  0.5, -3.0,
                                -4.0, -2.0,  0.0,  0.5,  0.5,  0.0, -2.0, -4.0,
                                -5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0 };

float QueenScore[8][8] = { -2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0,
                           -1.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -1.0,
                           -1.0,  0.0,  0.5,  0.5,  0.5,  0.5,  0.0, -1.0,
                           -0.5,  0.0,  0.5,  0.5,  0.5,  0.5,  0.0, -0.5,
                            0.0,  0.0,  0.5,  0.5,  0.5,  0.5,  0.0, -0.5,
                           -1.0,  0.5,  0.5,  0.5,  0.5,  0.5,  0.0, -1.0,
                           -1.0,  0.0,  0.5,  0.0,  0.0,  0.0,  0.0, -1.0,
                           -2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0 };

float blackRookScore[8][8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                               -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
                               -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
                               -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
                               -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
                               -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
                                0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5,
                                0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

float whiteRookScore[8][8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5,
                               -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
                               -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
                               -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
                               -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
                               -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
                                0.0, 0.0, 0.0, 0.5, 0.5, 0.0, 0.0, 0.0 };

float blackPawnScore[8][8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                               0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                               0.5,-0.5,-1.0, 1.0, 0.0,-1.0,-0.5, 0.5,
                               0.0, 0.0, 0.0, 2.0, 3.0, 0.0, 0.0, 0.0,
                               0.5, 0.5, 1.0, 1.5, 1.5, 1.0, 0.5, 0.5,
                               0.5, 0.5, 1.0, 2.0, 2.0, 1.0, 0.5, 0.5,
                               5.0, 5.0, 6.0, 6.0, 6.0, 6.0, 5.0, 5.0,
                               9.0, 9.0, 9.0, 9.0, 9.0, 9.0, 9.0, 9.0 };

float whitePawnScore[8][8] = { 9.0, 9.0, 9.0, 9.0, 9.0, 9.0, 9.0,  9.0,
                              5.0, 5.0, 6.0, 6.0, 6.0, 6.0, 5.0,  5.0,
                              0.5, 0.5, 1.0, 2.0, 2.0, 1.0, 0.5,  0.5,
                              0.5, 0.5, 1.0, 1.5, 1.5, 1.0, 0.5,  0.5,
                              0.0, 0.0, 0.0, 2.0, 3.0, 0.0, 0.0,  0.0,
                              0.5,-0.5,-1.0, 1.0, 0.0,-1.0,-0.5,  0.5,
                              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0,
                              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0 };

float rateMove(Chess& game, const int& x_pos, const int& y_pos) {
	if (game.chessBoard[8 - y_pos][x_pos - 1] == 'p')
		return 10.0 + blackPawnScore[8 - y_pos][x_pos - 1];
	else if (game.chessBoard[8 - y_pos][x_pos - 1] == 'P')
		return -10.0 + whitePawnScore[8 - y_pos][x_pos - 1];
	else if (game.chessBoard[8 - y_pos][x_pos - 1] == 'b')
		return 35.0 + blackBishopScore[8 - y_pos][x_pos - 1];
	else if (game.chessBoard[8 - y_pos][x_pos - 1] == 'B')
		return -35.0 + whiteBishopScore[8 - y_pos][x_pos - 1];
	else if (game.chessBoard[8 - y_pos][x_pos - 1] == 'n')
		return 30.0 + blackKnightScore[8 - y_pos][x_pos - 1];
	else if (game.chessBoard[8 - y_pos][x_pos - 1] == 'N')
		return -30.0 + whiteKnightScore[8 - y_pos][x_pos - 1];
	else if (game.chessBoard[8 - y_pos][x_pos - 1] == 'r')
		return 50.0 + blackRookScore[8 - y_pos][x_pos - 1];
	else if (game.chessBoard[8 - y_pos][x_pos - 1] == 'R')
		return -50.0 + whiteRookScore[8 - y_pos][x_pos - 1];
	else if (game.chessBoard[8 - y_pos][x_pos - 1] == 'q')
		return 70.0 + QueenScore[8 - y_pos][x_pos - 1];
	else if (game.chessBoard[8 - y_pos][x_pos - 1] == 'Q')
		return -70.0 + QueenScore[8 - y_pos][x_pos - 1];
	else if (game.chessBoard[8 - y_pos][x_pos - 1] == 'k')
		return 1000.0 + blackKingScore[8 - y_pos][x_pos - 1];
	else if (game.chessBoard[8 - y_pos][x_pos - 1] == 'K')
		return -1000.0 + whiteKingScore[8 - y_pos][x_pos - 1];
}

inline float evaluatingBoard(Chess& game) {
    float totalScore = 0.0;
    for (int y_pos = 1; y_pos <= 8; y_pos++) {
        for (int x_pos = 1; x_pos <= 8; x_pos++) {
            if (game.chessBoard[8 - y_pos][x_pos - 1] != '.')
                totalScore = totalScore + rateMove(game, x_pos, y_pos);
        }
    }
    return totalScore;
}

float minimax(Chess game, int depth, float alpha, float beta, bool isWhiteMove) {
    std::string move;

    if (depth == 0)
        return evaluatingBoard(game);

    std::vector <std::string> allMove = game.getAllMove();
    
    if (isWhiteMove) {
        float bestMove = -100000;
        for (int i = 0; i < allMove.size(); i++) {
            move = allMove[i];
            game.makeMove(move);
            bestMove = fmax(bestMove, minimax(game, depth - 1, alpha, beta, !isWhiteMove));
            game.undoMove();

            alpha = fmax(alpha, bestMove);
            if (beta <= alpha) 
                return bestMove;

        }
        return bestMove;
    }
    else {
        float bestMove = 100000;
        for (int i = 0; i < allMove.size(); i++) {
            move = allMove[i];
            game.makeMove(move);
            bestMove = fmin(bestMove, minimax(game, depth - 1, alpha, beta, !isWhiteMove));
            game.undoMove();

            beta = fmin(beta, bestMove);

            if (beta <= alpha) 
                return bestMove;
        }
        return bestMove;
    }
}

std::string botMove(Chess game) {
	std::vector <std::string> allMove = game.getAllMove();
	std::string move;
	std::string bestMove;
	float bestScore = -100000;
	float score = 0;

	for (int i = 0; i < allMove.size(); i++) {
		move = allMove[i];
		game.makeMove(move);
        score = minimax(game, 3, -100000, 100000, false);
		game.undoMove();

		if (score >= bestScore) {
			bestScore = score;
			bestMove = move;
		}
	}
    return bestMove;
}

int main() {

	Chess game;
	std::string str;
    int move = 0;

	game.printBoard();

	while (!game.checkMate() && !game.checkMate()) {

        std::vector <std::string> allMove = game.getAllMove();

        if (game.isWhiteMove) {
            std::cin >> str;
            try {
                game.makeMove(str);
            }
            catch (std::exception& ex) {

            }
        }
        else {
            str = botMove(game);
            game.makeMove(str);
        }

        system("cls");
		game.printBoard();
	}
}
