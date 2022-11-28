// program to implement sleeping barber problem
#include <conio.h>
#include <stdio.h>

void customerentry();
void customerexit();
void display();
int c[11], mutex = 0, i = 0;
void main()
{
	int n;
	// clrscr();
	printf("\nbarber is sleeping and the capacity of the waiting room is 10\n");
	do
	{
		printf("\n\nMAIN MENU\n1.INSERT CUSTOMER\n2.EXIT CUSTOMER\n3.EXIT\nenter ur choice:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			customerentry();
			display();
			break;

		case 2:
			customerexit();
			display();
			break;

		case 3:
			exit(0);

		default:
			printf("\n\ninvalid choice\n\n");
		}
	} while (n <= 3 && n != 0);
	getch();
}

void customerentry()
{
	int num;
	if (i == 0 || i < 11)
	{
		mutex = 1;
		printf("\nenter the process no that want 2 enter\n");
		scanf("%d", &num);
		c[i] = num;
		i++;
	}
	else
		printf("\nprocess can't enter\n");
}

void customerexit()
{
	int l;
	if (i != 0)
	{
		printf("\n\nthe process exited is:%d", c[0]);
		for (l = 0; l < i - 1; l++)
			c[l] = c[l + 1];
		i--;
		if (i == 0)
		{
			mutex = 0;
		}
	}
}

void display()
{
	int k = 10 - i + 1, l;
	if (i == 0)
		printf("\n\n10 processes can enter in waiting room\n0 processes are already in waiting room");
	else
		printf("\n%d more processes can enter in the waiting room\n%d processes are already in waiting room", k, i - 1);
	if (mutex == 1)
		printf("\n%d process is being served by barber", c[0]);
	else
		printf("\nbarber is sleeping\n");
	if (i > 1)
	{
		printf("\nprocess in waiting room:\n");
		for (l = 1; l < i; l++)
			printf("%d ", c[l]);
	}
}