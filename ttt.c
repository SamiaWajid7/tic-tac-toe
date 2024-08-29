#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[SIZE][SIZE])
{
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1)
            printf("---|---|---\n");
    }
    printf("\n");
}

bool isValidMove(char board[SIZE][SIZE], int row, int col)
{
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ';
}

bool checkWinner(char board[SIZE][SIZE], char player)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool checkDraw(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void getPlayerMove(char board[SIZE][SIZE], char player)
{
    int row, col;
    while (true)
    {
        printf("Player %c, enter your move (row and column): ", player);
        if (scanf("%d %d", &row, &col) != 2)
        {
            printf("Invalid input. Please enter numbers.\n");
            clearBuffer();
            continue;
        }
        row--;
        col--;
        if (isValidMove(board, row, col))
        {
            board[row][col] = player;
            break;
        }
        else
        {
            printf("Invalid move. Try again.\n");
        }
    }
    clearBuffer();
}

void playGame()
{
    char board[SIZE][SIZE];
    char currentPlayer = 'X';

    initializeBoard(board);

    while (true)
    {
        displayBoard(board);
        getPlayerMove(board, currentPlayer);

        if (checkWinner(board, currentPlayer))
        {
            displayBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        else if (checkDraw(board))
        {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main()
{
    char playAgain;
    do
    {
        playGame();
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        clearBuffer();
    } while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}
