#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitGame()
{
	printf("          欢迎来到猜字游戏          \n");
	printf(" ---------------------------------  \n");
	printf("|           1.StartGame.          | \n");
	printf("|           0.ExitGame .          | \n");
	printf(" ---------------------------------  \n");
}

void StartGame()
{
	int input = 0;
	int num = rand()%50+1;
	printf(" ------------StartGame------------ \n");
	while(1)
	{
		static int count = 0;
		printf("  Please guess a number(1--50): ");
		scanf("%d",&input);
		if(input > num)
		{
			printf("  Your guesses is bigger! \n");count++;
		}
		else
		{
			if(input < num)
			{
				printf("  Your guesses is smaller! \n");count++;
			}
			else
			{
				count;
				printf("  Your guesses is right \n  congratulations!!!\n");
				printf("  你猜了%d次\n",count+1);
				printf(" ------------FinishGame----------- \n");
				break;
			}
		}
	}
}

int main()
{
	int select = 0;
	srand((unsigned)time(NULL));
	do
	{
		select = 0;
		InitGame();
		printf("  Please select:");
		scanf("%d", &select);
		switch(select)
		{
			case 1:StartGame();break;
			case 0:printf("  ExitGame...\n");break;
			default:printf("  Error select \n");break;
		}
	}
	while(select);
	
	return 0;
}