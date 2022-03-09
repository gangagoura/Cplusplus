#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
void main_menu();
void add();  //FUNCTIONS
void list();
void edit();  //GLOBALLY DECLARED FUNCTIONS N VARIABLE
void delete1();
void search();

void gotoxy(int x, int y)//function used for cursor positioning
{
	COORD CR;
	CR.X=x;
	CR.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CR);
}

void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
	wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
//	SetConsoleTextAttributes(hStdOut,wColor);
	SetConsoleTextAttribute(hStdOut,wColor);
	
}
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	
    printf("\n  <<<<<<<<<<<<<<<<<<<<<<<<<  LOGIN FORM  >>>>>>>>>>>>>>>>>>>>>>>>>>  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       NOW YOU ARE LOGGED IN. WELCOME TO OUR SYSTEM !!");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();//holds the screen
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
}

struct CustomerDetails   //STRUCTURE DECLARATION
{
	int bikenumber;
	char name[20];
	char address[20];
	char phonenumber[15];
	char nationality[15];	
	char email[35];
	int period;
}s;

int main()   //MAIN FUNCTION
{
	int i=0;
	
	time_t t;
	time(&t);
	system("cls");   // FOR CLEARING SCREEN
	setcolor(55);

 	printf("\t\t|------------------------------------------------|\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|       -----------------------------            |\n");
	printf("\t\t|       WELCOME TO BIKE RENTAl SYSTEM            |\n");
	printf("\t\t|       -----------------------------            |\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|                 Lakeside                       |\n");
	printf("\t\t|                   NEPAL                        |\n");
	printf("\t\t|          CONTACT US:98765432100                |\n");
	printf("\t\t|------------------------------------------------|\n\n\n");
		for(i=0;i<80;i++)
		printf(">");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("<");
	printf(" \n Press any key to continue:");
	
	getch();	
    system("cls");
    login();
    main_menu();
}
void main_menu()
{
	int i=0;
	
	time_t t;
	time(&t);
	char customername;
	char choice;
    system("cls");
	while (1)      // INFINITE LOOP
	{
		system("cls");
		setcolor(55);
		 for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ---------------------->>>>  |MAIN MENU|  <<<<------------------------ \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		setcolor(55);
		printf("\t\t *Select and Enter Your Choice From Menu*:");
		printf("\n\n");
		printf("\n==========================");
		printf(" \n Enter 1 ->> Rent a bike");
		printf("\n==========================");
		printf(" \n Enter 2 ->> View Rental Record");
		printf("\n=================================");
		printf(" \n Enter 3 ->> Remove Rental Record");
		printf("\n===================================");
		printf(" \n Enter 4 ->> Search Rental Record");
		printf("\n===================================");
		printf(" \n Enter 5 ->> Edit Record");
		printf("\n=======================");
		printf(" \n Enter 6 ->> Exit");
		printf("\n=================");
		printf("\n \n");
		for(i=0;i<80;i++)
		printf(">");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("<");
		
		choice=getche();
		choice=toupper(choice);
		switch(choice)           // SWITCH STATEMENT
		{	
			case '1':
				add();break;
			case '2':
				list();break;
			case '3':
				delete1();break;
			case '4':
				search();break;
			case '5':
				edit();break;
			case '6':
				system("cls");
				printf("\n\n\t >>>>>THANK YOU<<<<<");
				printf("\n\t FOR USING OUR SERVICE");
			//	Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}
void add()
{
	FILE *f;
	int bikenumber, n, i, valid=0;
	char test;
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	system("cls");
	printf("\n Enter Customer Details:");
	printf("\n-------------------------");
	
	if((f = fopen("add.txt","r+"))!=NULL)
	{
		ADD:
		printf("\n Enter bike number\t: ");
		scanf(" i%",&bikenumber);
		while(fscanf(f,"%i %s %s %s %s %s %i\n", &s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
	    {
	    	if(bikenumber == s.bikenumber)
	    	{
	    		printf("\n\tTHIS BIKE IS ALREADY ON RENT.");
	    		goto ADD;
			}
		}
		s.bikenumber == bikenumber;
	
		//printf("\n Enter Bike number\t: ");
		//scanf("%i",&s.bikenumber);
		Q:
		printf("\n Enter Name\t\t: ");
		fflush(stdin);
		gets(s.name);
		if(strlen(s.name)>20||strlen(s.name)<2)
		{
			printf("\nInvalid!!\n\tThe maximum number for customer's name is less than 21 and more than 1.\n");
			goto Q;
		}
		else
		{
			for (i=0;i<strlen(s.name);i++)
			{
				if(isalpha(s.name[i]))
				{
					valid = 1;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\nName contain invalid character. Please enter again.\n");
				goto Q;
			}
		}
		do
		{
			A:
			printf("\n Enter Address\t\t:");
			scanf("%s",s.address);
			if(strlen(s.address)>20 || strlen(s.address)<2)
			{
				printf("\nInvalid!!\n\tThe maximum number for customer's name is less than 21 and more than 1.\n");
				goto A;
			}
			else
			{
				for (i=0;i<strlen(s.address); ++i)
				{
					if(isalpha(s.address[i]))
					{
						valid = 1;
					}
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nName contain invalid character. Please enter again.\n");
				}
				}
		}while(!valid);
		do
		{
			P:
			printf("\n Enter Phone Number\t: ");
			scanf("%s",s.phonenumber);		
			if (strlen(s.phonenumber)!=10 || strlen(s.phonenumber)>10)
			{
				printf("\nPhone number should be of 10 numbers from 0-9. Please, enter valid number.\n");
				goto P;
			}
			for(i=0;i<strlen(s.phonenumber); i++)
			{
				if(!isalpha(s.phonenumber[i]))
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\nThe phone number is invalid. Please, enter numbers only.\n");
			}
		}while(!valid);
		do
		{
			X:
			printf("\nEnter Nationality\t: ");		
			scanf("%s",s.nationality);
			if(strlen(s.nationality)>10 || strlen(s.nationality)<2)
			{
				printf("\nInvalid!!\n\tThe maximum name can be upto 15 and and more than 1.\n");
				goto X;
			}
			for(i=0;i<strlen(s.nationality); i++)
			{
				if(isalpha(s.nationality[i]))
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\nThe nationality name contains only character. Please, enter again.\n");
			}
		}while(!valid);
		do
		{
			printf("\nEnter Email\t\t: ");
			scanf(" %s",s.email);
			if(strlen(s.email)>35||strlen(s.email)<10)
			{
				printf("\nInvalid!!\n\tThe maximum number for customer's email is less than 31 and more than 10.\n");
			}
		}while(strlen(s.email)>35||strlen(s.email)<2);	
		do
		{
			printf("\nEnter Time Period(\'x\'days)\t: ");
			scanf("%i",&s.period);
			if(s.period>10 || s.period<=0)
			{
				printf("\tInvalid!!\n\tThe maximum bike rental days for customer  is upto 10 days .\n");
			}
		}while(s.period>10 || s.period<=0);
		
		
		fprintf(f,"%i %s %s %s %s %s %i\n", s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period);
		printf("\n\n Your Desired Bike is rented successfully!!");
		fclose(f);
	}
	printf("\n Press esc key to exit,  any other key to add another customer detail:");
	test=getche();
	if(test==27)
		main_menu();
	else
		add();
}

void list()
{
	FILE *f;
	int i, q;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");
	gotoxy(1,6);
	printf("BIKENUMBER ");
	gotoxy(15,6);
	printf("NAME ");
	gotoxy(30,6);
	printf("ADDRESS ");
	gotoxy(45,6);
	printf("PHONENUMBER ");
	gotoxy(60,6);
	printf("NATIONALITY ");
	gotoxy(75,6);
	printf("EMAIL ");
	gotoxy(100,6);
	printf("PERIOD \n");
	
	for(i=0;i<110;i++)
	{
		printf("-");
	}
	q=9;
	while(fscanf(f,"%i %s %s %s %s %s %i\n", &s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
	{
		/*printf("BIKENUMBER :\t%s\n",s.bikenumber);
		printf("NAME:\t%s\n",,s.name);
		printf("ADDRESS:\t%s\n",s.address);
		printf("PHONENUMBER:\t%s\n",s.phonenumber);
		printf("NATIONALITY \n");*/
		gotoxy(1,q);
		printf("%i",s.bikenumber);
		gotoxy(16,q);
		printf("%s",s.name);
		gotoxy(31,q);
		printf("%s",s.address);
		gotoxy(46,q);
		printf("%s",s.phonenumber);
		gotoxy(61,q);
		printf("%s",s.nationality);
		gotoxy(76,q);
		printf("%s",s.email);
		gotoxy(101,q);
		printf("%i",s.period);
		q++;
	}
	printf("\n");
	for(i=0;i<110;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	FILE *f,*t;
	int i=0;
	int bikenumb;
	t=fopen("temp.txt","w");
	if ((f=fopen("add.txt","r"))==NULL)
	{
		printf("NO RECORD ADDED.");
		main_menu();
	}
	else
	{
		system("cls");
		printf("Enter the Bike Number to be deleted from the database: ");
		fflush(stdin);
		scanf("%i",&bikenumb);
		while(fscanf(f,"%i %s %s %s %s %s %i\n", &s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
		{
			if(bikenumb != s.bikenumber)
			{
				fprintf(t,"%i %s %s %s %s %s %i\n", s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period);
			}
			else
			{
				i=1;
			}
		}
		if(!i)
		{
			printf("\n\n Records of Customer in this  bike number not found!!");
			//remove("E:/file.txt");
		   //rename("E:/temp.txt","E:/file.txt");
			getch();
			fclose(f);
			fclose(t);
			main_menu();
		}
		else
		{
			printf("\n\tSuccessfully deleted.\n");
		}
		fclose(f);
		fclose(t);
		remove("add.txt");
		rename("temp.txt","add.txt");
		getch();
	}
}

void search()
{
system("cls");
	FILE *f;
	int bikenumber;
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
	{
		printf("NO RECORD ADDED.");
		main_menu();
	}
	else
	{
		fflush(stdin);
		printf("Enter bike number of the customer to search its details: \n");
		scanf("%i", &bikenumber);
		while(fscanf(f,"%i %s %s %s %s %s %i\n", &s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
		{
			if(bikenumber==s.bikenumber)
			{
				flag=0;
				printf("\n\tRecord Found\n");
				printf("\nBike Number\t: %i",s.bikenumber);
				printf("\nName\t\t: %s",s.name);
				printf("\nAddress\t\t: %s",s.address);
				printf("\nPhone number\t: %s",s.phonenumber);
				printf("\nNationality\t: %s",s.nationality);
				printf("\nEmail\t\t: %s",s.email);
				printf("\nPeriod\t\t: %i",s.period);
				break;
			}
		}
		if(flag==1){	
			printf("\n\tRequested Customer could not be found!");
		}
		getch();
		fclose(f);
		main_menu();
	}
	
}

void edit()
{
	FILE *f, *r;
	int k=0;
	char ed;
	int bikenumber;
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
	{
		printf("NO RECORD ADDED.");
		main_menu();
	}
	else
	{
		r = fopen("temp.txt","a");
		system("cls");
		printf("Enter bike number of the customer to edit:\n\n");
		scanf("%i",&bikenumber);
		fflush(stdin);
		while(fscanf(f,"%i %s %s %s %s %s %i\n", &s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
		{
			if(bikenumber==s.bikenumber)
			{
				
				k=1;
				printf("\n\t*** Existing Record ***");
				printf("\nBike Number\t: %i",s.bikenumber);
				printf("\nName\t\t: %s",s.name);
				printf("\nAddress\t\t: %s",s.address);
				printf("\nPhone number\t: %s",s.phonenumber);
				printf("\nNationality\t: %s",s.nationality);
				printf("\nEmail\t\t: %s",s.email);
				printf("\nPeriod\t\t: %i",s.period);
				printf("\n\n\t*** New Record ***");
				printf("\nEnter New Name           : ");
				fflush(stdin);
				scanf("%s",s.name);
				printf("\nEnter New Address        : ");
				scanf("%s",s.address);
				printf("\nEnter New Phone number   : ");
				scanf("%s",s.phonenumber);
				printf("\nEnter New Nationality    : ");
				scanf("%s",s.nationality);
				printf("\nEnter New Email          : ");
				scanf("%s",s.email);
				printf("\nEnter New Period         : ");
				scanf("%i",&s.period);
				printf("Press 'm' to edit the existing record or any key to cancel...");
				ed=getche();
				if(ed=='m' || ed=='M')
				{
					fprintf(r,"%i %s %s %s %s %s %i\n", s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period);
					fflush(stdin);
					printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
				}
			}
			else
			{
				fprintf(r,"%i %s %s %s %s %s %i\n", s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period);
				fflush(stdin);
			}
			
		}
		if(!k)
		{
			printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		}
		fclose(r);
		fclose(f);
		remove("add.txt");
		rename("temp.txt","add.txt");
		getch();
	}
	main_menu();
}

