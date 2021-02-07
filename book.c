
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct book
{
	char code[20];
	char name[20];
	char date[20];
	int cost;


}b;

void insert_details();
void viewAll();
void find();
void book_ticket();
void old_record();

void main()
{
	 int ch;
 	do{
            for(int l=0;l<75;l++)
            {
                printf("*");
            }
	printf("");
	printf("\n\t Moive Ticket booking \n");
	for(int l=0;l<75;l++)
            {
                printf("*");
            }

	printf("\n\tEnter 1 To Insert Movie");
   	printf("\n\tEnter 2 To View All Movie");
	printf("\n\tEnter 3 To Find Movie ");
	printf("\n\tEnter 4 To Book Tickets");
	printf("\n\tEnter 5 To View All Transactions");
   	printf("\n\tEnter 0 To Exit \n");
   	for(int l=0;l<75;l++)
            {
                printf("*");
            }

   	printf("\n\nEnter your Choice ::\n\n");

   	scanf("%d",&ch);
   	int l;

            for(int l=0;l<1;l++)
            {
                 printf("\nWait for next PAge");
            }
            for(l=0;l<100000000;l++)
            {
            printf("");
            }
            for(l=0;l<100000000;l++)
            {
            printf("");
            }
            for(l=0;l<1;l++)
            {
                 printf("!");
            }
            for(l=0;l<100000000;l++)
            {
            printf("");
            }
            for(l=0;l<1;l++)
            {
                 printf("!");
            }
            for(l=0;l<1000000000;l++)
            {
            printf("");
            }
            for(l=0;l<1;l++)
            {
                 printf("!");
            }
            for(l=0;l<1000000000;l++)
            {
            printf("");
            }

	   system("cls");

   	switch (ch)
   	{
    		case 1 :
    		insert_details();
   		break;
		case 2:
    		viewAll();
   		break;

		case 3:
    		find();
   		break;

		case 4:
		book_ticket();
		break;

		case 5:
		old_record();
		break;

    		case 0:
    		exit(0);
    		break;

    		default:
    		printf("Wrong choice !");
    		break;
   	}
 }
 while(ch!=0);

}
void insert_details()
{

	FILE *fp;
	struct book b;
	printf("Enter movie code :- ");
	scanf("%s",b.code);
	printf("Enter  name :- ");
	scanf("%s",b.name);
	printf("Enter Release Date:- ");
	scanf("%s",b.date);
	printf("Enetr Ticket Price:- ");
	scanf("%d",&b.cost);

	fp=fopen("data.txt","a");

	if(fp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
		printf("Recorded Successfully");
	}
		printf("\n");
	fclose(fp);

}
void find()
{
	struct book b;
	FILE *fp;

	char ch[20];
	printf("Enter movie code :");
	scanf("%s",ch);

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,ch) == 0)
			{

				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tmovie name ::%s",b.name);
				printf("\n\t\tmovie date ::%s",b.date);
				printf("\n\t\tprice of ticket ::%d",b.cost);
			}
		}

	}

	fclose(fp);

}
void viewAll()
{

	char ch;
	FILE *fp;

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);

	}

	fclose(fp);

}
void book_ticket()
{
 struct book b;
	FILE *fp;

	FILE *ufp;

	int total_seat,mobile,total_amount;
	char name[20];


	char ch;
	char movie_code[20];


	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);

	}
	fclose(fp);
	printf("\n For Book ticket Choice Movie(Enter Movie Code First Latter Of Movie)\n");
	printf("\n Enter movie code :");
	scanf("%s",movie_code);
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,movie_code) == 0)
			{

				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tMovie name ::%s",b.name);
				printf("\n\t\tdate name ::%s",b.date);
				printf("\n\t\tPrice of ticket::%d",b.cost);
			}
		}
	}
	printf("\n* Fill Deatails  *");
	printf("\n your name :");
	scanf("%s",name);
	printf("\n mobile number :");
	scanf("%d",&mobile);
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);


	total_amount = b.cost * total_seat;

	printf("\n ENJOY MOVIE \n");
	printf("\n\t\tname : %s",name);
	printf("\n\t\tmobile Number : %d",mobile);
	printf("\n\t\tmovie name : %s",b.name);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tcost per ticket : %d",b.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);


	ufp=fopen("oldTransection.txt","a");
	if(ufp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(ufp,"%s %d %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
		printf("\n Record insert Sucessfull to the old record file");
	}
		printf("\n");
	fclose(ufp);
	fclose(fp);

}
void old_record()
{
	char ch;
	FILE *fp;

	fp = fopen("oldTransection.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);

	}
	fclose(fp);
}
