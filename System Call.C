// program to implement system call
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <dir.h> //for MAXPATH
int list_file();
int directory();
int change_dir();
int subfun(char[]);
void main()
{
	int ch;
	// clrscr();
	do
	{
		printf("\n***********************************MAIN MENU************************************\n");
		printf("1.TO DISPLAY LIST OF FILES\n");
		printf("2.TO CREATE DIRECTORY\n");
		printf("3.TO CHANGE THE WORKING DIRECTORY\n");
		printf("4.EXIT\n");

		printf("\nenter yr choice:");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			list_file();
			break;
		case 2:
			directory();
			break;
		case 3:
			change_dir();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("\n invalid choice\n");
		}
	} while (ch <= 4);
}

int list_file()
{
	int l;
	char e[] = "*.*";
	clrscr();
	printf("\n********************************LIST FILE DETAIL********************************\n");
	printf("\n1.list all files\n");
	printf("2.list of given extension files\n");
	printf("3.list of named files\n");
	scanf("%d", &l);
	switch (l)
	{
	case 1:
		printf("\nlist of all (*.*) files\n");
		subfun(e);
		break;
	case 2:
		printf("\nenter the extention\n");
		scanf("%s", &e);
		subfun(e);
		break;
	case 3:
		printf("\nenter the name of file\n");
		scanf("%s", &e);
		subfun(e);
		break;
	default:
		printf("\ninvalid choice\n\n\n");
	}
	return 0;
}

int subfun(s)
char s[10];
{
	struct ffblk ffblk;
	int d, p = 0, i = 0;
	d = findfirst(s, &ffblk, 0);
	while (!d)
	{
		printf("%s\n", ffblk.ff_name);
		d = findnext(&ffblk);
		i++;
		p = p + 1;
		if (p >= 32)
		{

			printf("\npress any key to continue\n");
			getch();
			p = 0;
		}
	}
	printf("\ntotal no. of files:%d\n", i);
	return 0;
}

int directory() // always returns value -28
{
	unsigned attrib;
	char name[10], buffer[MAXPATH];
	printf("\n enter the directory name\n");
	scanf("%s", &name);
	getcwd(buffer, MAXPATH);
	printf("\ncurrent directory:%s\n", buffer);
	if (_dos_getfileattr(name, &attrib) == 0)
	{
		printf("\n%s is already availaible", name);
	}
	else
	{
		mkdir(name);
		printf("\n%s directory succesfully created", name);
	}
	return 0;
}

int change_dir()
{
	char buffer[MAXPATH];
	int d;
	printf("\ncurrent directory=%s\n", getcwd(buffer, MAXPATH));
	printf("\nCHANGE DIRECTORY\n");
	printf("\n1.step by step backward\n");
	printf("2.goto root\n");
	printf("3.forward directory\nenter ur choice:");
	scanf("%d", &d);
	switch (d)
	{
	case 1:
		chdir("..");
		break;

	case 2:
		chdir("\\");
		break;

	case 3:
		printf("\nplease enter the directory name:");
		scanf("%s", &buffer);
		chdir(buffer);
		break;
	}
	printf("\ncurrent directory:%s", getcwd(buffer, MAXPATH));
	return 0;
}
