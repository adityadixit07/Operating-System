// program to implement dining philospher problem
#include <conio.h>
#include <stdio.h>
void wait(int);
void signal(int);
void display();
int lchop[] = {1, 1, 1, 1, 1}, rchop[] = {1, 1, 1, 1, 1};
char status[] = {'T', 'T', 'T', 'T', 'T'};
void main()
{
	int ph, n;
	// clrscr();
	do
	{
		printf("\n\nMAIN MENU\n1.HUNGARY\n2.THINKING\n3.EXIT\nentre ur choice:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("\n\n\nenter the philosopher number(0-4)");
			scanf("%d", &ph);
			wait(ph);
			display();
			break;

		case 2:
			printf("\n\nenter the philosopher number(0-4)");
			scanf("%d", &ph);
			signal(ph);
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

void wait(int ph)
{
	if (status[ph] == 'E')
		printf("\n\n\nphilosopher %d is already eating", ph);

	else if (lchop[(ph + 1) % 5] == 1 && rchop[(ph - 1) % 5] == 1)
	{
		printf("\n\nphilosopher %d starts eating", ph);
		status[ph] = 'E';
		lchop[ph] = 0;
		rchop[ph] = 0;
		lchop[(ph + 1) % 5] = 0;
		rchop[(ph - 1) % 5] = 0;
	}

	else
		printf("\n\nphilosopher %d cannot start eating", ph);
}

void display()
{
	int i;
	printf("\n\nphno  status  lchop  rchop\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d     %c        %d       %d\n", i, status[i], lchop[i], rchop[i]);
	}
}

void signal(int ph)
{
	if (status[ph] == 'T')
		printf("\n\nphilosopher %d is already thinking", ph);

	else
	{
		printf("\n\nphilosopher %d started thinking", ph);
		status[ph] = 'T';
		lchop[ph] = 1;
		rchop[ph] = 1;
		lchop[(ph + 1) % 5] = 1;
		rchop[(ph - 1) % 5] = 1;
	}
}
