#include <stdio.h>

int board[26], i, j, player, dice[2], stay[2];

int init_board();
int print_board();
int roll_dice();
int move_sol(int player, int dice[2]);



int main() {
	init_board();
	print_board();

	while (1) {
		player = 1;
		roll_dice();
		move_sol(player, dice);
		print_board();
		
		player = 2;
		roll_dice();
		move_sol(player, dice);
		print_board();
	}
	return 0;
}

int move_sol(int player, int dice[2]) {
	printf("\n");
	int choice, move;

	for (i = 0; i < 2; i++) {
		move = dice[i];
		if (player == 1) {
			if (board[24] == 0) {
				printf("[USER INPUT] : move %d from position --> ", move);
				scanf_s("%d", &choice);
				while (board[choice - 1] <= 0) {
					printf("[ERROR] : move %d from position --> ", move);
					scanf_s("%d", &choice);
				}
				while (board[choice + move - 1] < -1 || board[choice + move - 1] > 23) {
					printf("[ERROR] : move %d from position --> ", move);
					scanf_s("%d", &choice);
				}
				if (board[choice + move - 1] == -1) {
					board[choice + move - 1] += 2;
					board[25]++;
				}
				else {
					board[choice + move - 1]++;
				}
				board[choice - 1]--;
			}
			else {
				if (board[dice[0]-1] < -1 && board[dice[1]-1] < -1)
				{
					break;
				}
				else {
					printf("[USER INPUT] : dance to %d or %d -->", dice[0], dice[1]);
					scanf_s("%d", &choice);
					while (board[choice - 1] < -1)
					{
						printf("[ERROR] : dance to %d or %d -->", dice[0], dice[1]);
						scanf_s("%d", &choice);
					}
					while (choice != dice[0] && choice != dice[1])
					{
						printf("[ERROR] : dance to %d or %d -->", dice[0], dice[1]);
						scanf_s("%d", &choice);
					}
					if (board[choice - 1] == -1) {
						board[choice - 1] += 2;
						board[25]++;
					}
					else {
						board[choice - 1]++;
					}
					board[24]--;
					int temp = dice[1];
					if (i == 0) {
						dice[1] = dice[0];
						dice[0] = temp;
					}
				}
			
			}


		}
		if (player == 2) {
			if (board[25] == 0) {
				printf("[USER INPUT] : move %d from position --> ", move);
				scanf_s("%d", &choice);
				while (board[choice - move - 1] > 1) {
					printf("[ERROR] : move %d from position --> ", dice[i]);
					scanf_s("%d", &choice);
				}
				while (board[choice - move - 1] > 1) {
					printf("[ERROR] : move %d from position --> ", dice[i]);
					scanf_s("%d", &choice);
				}
				if (board[choice - move - 1] == 1) {
					board[choice - move - 1] -= 2;
					board[24]++;
				}
				else {
					board[choice - move - 1]--;
				}
				board[choice - 1]++;
			}
			else {
				if (board[dice[0] - 1] < -1 && board[dice[1] - 1] < -1)
				{
					break;
				}
				else {
					printf("[USER INPUT] : dance to %d or %d -->", 24 - dice[0], 24 - dice[1]);
					scanf_s("%d", &choice);
					while (board[choice - 1] > 1)
					{
						printf("[ERROR] : dance to %d or %d -->", 24 - dice[0], 24 - dice[1]);
						scanf_s("%d", &choice);
					}
					while (choice != 24 - dice[0] && choice !=24 - dice[1])
					{
						printf("[ERROR] : dance to %d or %d -->",24 - dice[0],24 - dice[1]);
						scanf_s("%d", &choice);
					}
					if (board[choice - 1] == 1) {
						board[choice - 1] -= 2;
						board[24]++;
					}
					else {
						board[choice - 1]++;
					}
					board[25]--;
					int temp = dice[1];
					if (i == 0) {
						dice[1] = dice[0];
						dice[0] = temp;
					}
				}
			}
		}
		if (i == 0) {
			print_board();
		}
	}
	return 0;
}


int roll_dice() {
	dice[0] = rand() % 7;
	dice[1] = rand() % 7;
	while (dice[0] == 0 || dice[1] == 0)
	{
		dice[0] = rand() % 7;
		dice[1] = rand() % 7;
	}
	printf("\n[PLAYER %d] : The dice roll is %d, %d",player, dice[0], dice[1]);
	return 0;
}

int print_board() {
	printf("\n");
	for (j = 0; j < 12; j++) {
		if (board[j] < 0) {
			printf("\033[1;31m");
		}
		if (board[j] > 0) {
			printf("\033[0;34m");
		}
		if (board[j] == 0) {
			printf("\033[0m");
		}
		printf("%d ", abs(board[j]));
		if (j == 5 || j == 17) {
			printf("\033[0m");
			printf("| ");
		}
	}
	printf("\n\n");
	for (j = 23; j > 11; j--) {
		if (board[j] < 0) {
			printf("\033[1;31m");
		}
		if (board[j] > 0) {
			printf("\033[0;34m");
		}
		if (board[j] == 0) {
			printf("\033[0m");
		}
		printf("%d ", abs(board[j]));
		if (j == 18) {
			printf("\033[0m");
			printf("| ");
		}
	}
	printf("\n\n");
	printf("\033[0m");
	printf("[PLAYER 1] : %d | [PLAYER 2] : %d\n", board[24], board[25]);
	return 0;
}

int	init_board() {
	for (j = 0; j < 24; j++) {
		board[j] = 0;
	}
	board[0] = 2;
	board[5] = -5;
	board[7] = -3;
	board[11] = 5;
	board[23] = -2;
	board[18] = 5;
	board[16] = 3;
	board[12] = -5;
	return 0;
}
