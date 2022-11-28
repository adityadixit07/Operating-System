// program to implement consumer and producer problem
#include <conio.h>
#include <stdio.h>
void consumer();
void producer();
void display();
int a[10], i = 0;
void main()
{
	int n;
	clrscr();
	do
	{
		printf("\n\nMAIN MENU\n1.CONSUMER\n2.PRODUCER\n3.EXIT\nentre ur choice:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			consumer();
			display();
			break;

		case 2:
			producer();
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

void consumer()
{

	if (i == 0)
		printf("\n\n\nconsumer cannot consume data item");

	else
	{
		printf("\n\nconsumer have consumed one data item");
		i--;
	}
}

void producer()
{
	if (i == 10)
		printf("\n\nproducer cannot produce data item");
	else
	{
		printf("\n\nproducer can produce data item");
		i++;
	}
}

void display()
{
	int j = 10 - i;
	printf("\n\nproducer can produce %d data item and consumer can consume %d data item", j, i);
}