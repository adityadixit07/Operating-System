// program to implement consumer and producer problem using values
#include <conio.h>
#include <stdio.h>
void consumer();
void producer();
void display();
int a[10], i = 0, j = 0;
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
	int num, count = 0, l;
	if (i == 0)
		printf("\n\n\nconsumer cannot consume data item");

	else
	{
		printf("\nenter the data u want 2 consume\n");
		scanf("%d", &num);
		for (l = 1; l <= j; l++)
		{
			if (a[l] == num)
			{
				count = 1;
				break;
			}
		}
		if (count == 0)
			printf("Producer have not produced %d data item", num);
		else
		{
			printf("\n\nconsumer have consumed %d data item", num);
			i--;
		}
	}
}

void producer()
{
	int num;
	if (i == 10)
		printf("\n\nproducer cannot produce data item");
	else
	{
		printf("\nenter the data 2 be inserted in buffer:");
		scanf("%d", &num);
		j++;
		a[j] = num;
		printf("\n\nproducer can produce data item");
		i++;
	}
}

void display()
{
	int k = 10 - i, l;
	printf("\n\nproducer can produce %d data item and consumer can consume %d data item", k, i);
	printf("\ndata in common buffer:\n");
	for (l = 1; l <= j; l++)
		printf("%d ", a[l]);
}