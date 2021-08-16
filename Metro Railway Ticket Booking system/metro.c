#include<stdio.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>

void  user(int );
void routinerouteuser();
void nonroutinerouteuser();


//strindex: return intdex of p in q ,-1 if none.
int strindex(char p[][25], char q[])
{
	int i;
	for (i=0;i<=14;i++)
	{
		if((strcmp(q, p[i]))==0)
			return i;
	}
	return -1;
	
	
	
}

void welcome();
void Newuser();
void Registereduser();
void Metrostations();
void Tariffdetails();

void main()
{
	welcome();
	
}

void welcome()
{
	int n=6;
	while((n>5)||(n<1))
	{
		
		//present time:
		time_t mytime = time(NULL);
		char * time_str = ctime(&mytime);
		time_str[strlen(time_str)-1]='\0';
		
		//welcome
		printf("\n\n\t\t\t\tWelcome to Namma Metro Transport Corporation \n\
		--------------------------------------------------------------------------\
		\n\t\t\t\t\t\t\t\t  ");
		printf("%s\
		\n     Reservation system is currently avaiable for Yellow line only[Bommansandra - Rastriya Vidhyalaya Road]\
		\n\t\t\tEnter:\
		\n\t\t\t\t1.If you are a New User.\
		\n\t\t\t\t2.If you are a Registered User.\
		\n\t\t\t\t3.To know Metro Stations.\
		\n\t\t\t\t4.Tariff Details.\
		\n\t\t\t\t5.To QUIT\
		\n",time_str);
		
		scanf("%d",&n);
		
		switch (n)
		{
			case 1:
			{
				Newuser();
				n=6;
				break;
			}
			case 2:
			{
				Registereduser();
				n=6;
				break;
			}
			case 3:
			{
				Metrostations();
				n=6;
				break;
			}
			case 4:
			{
				Tariffdetails();
				n=6;
				break;
			}
			case 5:
			{
				break;
			}
			default :
			{
				printf("\t\t\t\tYou have choosen a wrong entry.Please choose it again\n\n");
			}
		}
	}
}


//new user :- data entry , storage of data spliiting into routine and non routine user.
void Newuser()
{
	printf("Enter:\
				\n1 to create Routine Route User.\
				\n2 to create Non-Routine Route User.\n\n");
	int choice;
	scanf("%d",&choice);
	
	while(!(choice==0 ) && !(choice==1))
	{
		printf("You have entered a wrong choice.\
					\nEnter:\
					\n1 to create Routine Route User Account.\
					\n2 to create Non-Routine Route User Account.\n");
		scanf(" %d", &choice);
	}
	
	//Creates routinerouteuser account.
	if(choice==1)
	{
		user(choice);
		
	}
	
	//creates nonroutinerouteuser account.
	if(choice==2)
	{
		user(choice);
	}
}

void user(int choice)
{
	FILE *fp2;
		fp2=fopen("D:/Desktop/Projects/C/copyroutinerouteuserlog.csv","r+");
		char  line[1000],line1[1000],ch,ch1;
		int count=0,no=0,q,no1=0;
		
		if(fp2==NULL)
		{
			printf("error in opening the file\n");
		}
		else
		{
			while(fgets(line,1000,fp2)!=NULL)
			{
				if(count==0)
						count+=strlen(line)+1;
					else
						count+=strlen(line)+4;
					printf("%d\n", count);
					
				ch=fgetc(fp2);
				ch=fgetc(fp2);
				ch1=fgetc(fp2);
				no+=1;
			
				
				
				while(ch==',' && ch1==',')
				{
					fseek(fp2, count,0);
					char metroid[15], name[40], gender[10],email[30],from[30],to[30],phoneno[20];
					
					
					printf("Enter your name:\n");
					gets(name);
					gets(name);
					for(q=0;q<strlen(name);q++)
					{
						if((name[q]<65 ||(name[q]>90 && name[q]<97)||name[q]>122) && name[q]!=32)
						{	
							
							printf("Your Name is Invalid:\
									\nPlease enter only letters.\n");q=-1;
							gets(name);
						}
					}
					
					printf("Enter your gender:\n");
					gets(gender);
					while(strcmp(gender,"Female")!=0 && strcmp(gender,"Male")!=0 && strcmp(gender,"Other")!=0)
					{
						printf("Please enter as per given below: \
									\n1.Female.\
									\n2.Male.\
									\n3.Other.\n");
						gets(gender);
					}
					
					printf("Enter your email:\n");
					gets(email);
					int o=0,d=0,oe=0,de=0;
					for(q=0;q<strlen(email);q++)
					{
						if(email[q]=='@')
							o+=1, oe=q;
						if(email[q]=='.')
							d+=1 , de=q;
						if(o>1 || d>1 || (oe>de  && q==(strlen(email)-1)))
						{
							printf("%d",o);
							printf("%d",d);
							printf("%d",oe);
							printf("%d",de);
							o=0;
							d=0;
							q=-1;
							printf("The email you entered is invalid:\
										\nPlease enter as per given format:qqq@www.eee\n");
										
							gets(email);
						}
						
					}
					if(choice==1)
					{
						char l[15][25]={"Bommasandra","Hebbagodi","Hoskur Road","Electronics city phase-2","Electronics city phase-1","Hosa Road","Basapura Road","Chikkabegur","Muneshwara Road","Oxford Road","Silkboard","Btm Layout","Jayadeva","Ragiguda","Rastriya Vidhyalaya Road"};
						int y;
						printf("Enter  starting point:\n");
						gets(from);
						while((y=strindex(l,from))==-1)
						{
							printf("You have entered Invalid Starting point name.\
										\nEnter as per the given list:\n");
										Metrostations();
										gets(from);
						}
					
						printf("Enter end point:\n");
						gets(to);
						while((y=strindex(l,to))==-1)
						{
							printf("You have entered Invalid Starting point name.\
										\nEnter as per the given list:\n");
							Metrostations();
							gets(to);
						}
					}
					
					printf("Enter your phone number:\n");
					gets(phoneno);
					while(strlen(phoneno)!=10 || (phoneno[0]!='7' && phoneno[0]!='8' && phoneno[0]!='9'))
					{
						printf("Your phone number doesn't support this.\
									\nPlease enter a ten digit number which starts with either 7, 8 or9  ");
									gets(phoneno);
					}
					if(no>0 &&  no<10)
						strcpy(metroid,"METRO000000");
					if(no>9 &&  no<100)
						strcpy(metroid,"METRO00000");
					if(no>99 &&  no<1000)
						strcpy(metroid,"METRO0000");
					if(no>999 &&  no<10000)
						strcpy(metroid,"METRO000");
					if(no>9999 &&  no<100000)
						strcpy(metroid,"METRO00");
					if(no>99999 &&  no<1000000)
						strcpy(metroid,"METRO0");
					if(no>999999 &&  no<10000000)
						strcpy(metroid,"METRO");
					char con[20];
					itoa(no,con,10);
					strcat (metroid,con );
					if(choice==1)
					{
						fseek(fp2,count,0);
						fprintf(fp2,"%s,%s,%s,%s,%s,%s,%s,%s\n",metroid,name,name,gender,phoneno,email,from,to);
						
						count+=strlen(metroid)+strlen(name)+strlen(name)+strlen(gender)+strlen(phoneno)+strlen(email)+strlen(from)+strlen(to)+2+7;
					}
					if(choice==2)
					{
						fseek(fp2,count,0);
						fprintf(fp2,"%s,%s,%s,%s,%s,%s\n",metroid,name,name,gender,phoneno,email);
						count+=strlen(metroid)+strlen(name)+strlen(name)+strlen(gender)+strlen(phoneno)+strlen(email)+2+5;						
					}
					
					printf("You have Successfully created Metroaccount. It is ready for use.\
								\nYour Metroid is:%s\n\
								\nYour default password is:%s\n", metroid,name);
					FILE *fp1=fopen("D:/Desktop/Projects/C/1.csv","r+");
					if(fp1==NULL)
					{
						printf("\nopen could not open.\
									\nclose the file if open or check mode.");
					}
					while(fgets(line1,1000,fp1)!=NULL)
					{
						no1+=1;
						if(no1<=no)
						{
							continue;
						}
						if(no1=no+1)
						{
							fseek(fp2,count,0);
						}
						fprintf(fp2,"%s",line1);
						
						}
						fprintf(fp2,",,,,,,,");
						rewind(fp1);
						rewind(fp2);
						if(fp1==NULL && fp2==NULL)
						{
							printf("\nopen could not open.\
										\nclose the file if open or check mode.");
						}
					
						char g;
						g=fgetc(fp2);
						while(g!=EOF)
						{
							fputc(g,fp1);
							g=fgetc(fp2);
						}
						fclose(fp1);
						break;
					}
					
					
				}
			
		}
		
	fclose(fp2);
	
}



//registered user:- check routine or non routine user . if routine fill all details automatically.
void Registereduser()
{
	int i=5;
	char type[20];
	gets(type);
	char account[5][20]={"Administrative","Routine Route User","Non-Route User","Go Back"};
	while(i>4 ||i<1)
	{
		printf("\t\tEnter the type of Account you have in Namma Metro Transport Corporation:\
					\n\t\t\t\t1.Administrative\
					\n\t\t\t\t2.Routine Route User\
					\n\t\t\t\t3.Non-Routine Route User\
					\n\t\t\t\t4.Go Back\n\n");
		
			gets(type);
	
	
		if (strcmp(type, account[0])==0)
		{
			i=1;
		}
		if (strcmp(type, account[1])==0)
		{
			i=2;
		}
		if (strcmp(type, account[2])==0)
		{
			i=3;
		}
		if (strcmp(type, account[3])==0)
		{
			i=4;
		}
	
	
		switch(i)
		{
			case 1:
			{
				printf("\n\t\t\t\tPresently Administrative options are ceased\n\n");
				break;
			}
			case 2:
			{
				routinerouteuser();
				break;
			}
			case 3:
			{
				nonroutinerouteuser();
				break;
			}
			case 4:
			{
				i=1;
				continue;
			}
			default:
			{
				printf("\t  You have choosen a wrong entry.Please enter your Account type as per given in the list.\n\n");
			}
		}
		i=5;
	}
	//system("D:/Desktop/Projects/C/bookcopy.html");
}

//displays metrostations.
void Metrostations()
{
	printf("\n\t\t\t\t\t  01.Bommasandra\
				\n\t\t\t\t\t  02.Hebbagodi\
				\n\t\t\t\t\t  03.Hoskur Road\
				\n\t\t\t\t\t  04.Electronics city phase-2\
				\n\t\t\t\t\t  05.Electronics city phase-1\
				\n\t\t\t\t\t  06.Hosa Road\
				\n\t\t\t\t\t  07.Basapura Road\
				\n\t\t\t\t\t  08.Chikkabegur\
				\n\t\t\t\t\t  09.Muneshwara Road\
				\n\t\t\t\t\t  10.Oxford Road\
				\n\t\t\t\t\t  11.Silkboard\
				\n\t\t\t\t\t  12.Btm Layout\
				\n\t\t\t\t\t  13.Jayadeva\
				\n\t\t\t\t\t  14.Ragiguda\
				\n\t\t\t\t\t  15.Rastriya Vidhyalaya Road\n\n\n");
}

//Calculates the tariff
void Tariffdetails()
{
	printf("\t\t  For first two stops next to your boarding station the cost is 10 Rupees.\
			\n\t\t Then for each of next two stations there will be an increase of 2 Rupees.\n\n");
	
	char a[15][25]={"Bommasandra","Hebbagodi","Hoskur Road","Electronics city phase-2","Electronics city phase-1","Hosa Road","Basapura Road","Chikkabegur","Muneshwara Road","Oxford Road","Silkboard","Btm Layout","Jayadeva","Ragiguda","Rastriya Vidhyalaya Road"};
	int i=0, j=0, tariff=0;
	
	char b[25], c[25];
	printf("Enter the starting point name :\n");
	gets(b);
	gets(b);

	while((i=strindex(a, b))==-1)
	{
		printf("\n\t\t\t\tThe station name you entered is incorrect.\
					\n\t\t\t\t Enter the station as per the list given:\
					 \n");
		Metrostations();
		printf("Enter the starting point name correctly:\n");
		gets(b);
	}
	
	printf("Enter the end point name :\n");
	gets(c);
	while ((j=strindex(a, c))==-1)
	{
		printf("\n\t\t\t\tThe station name you entered is incorrect.\
					\n\t\t\t\t Enter the station as per the list given:\
					 \n");
		Metrostations();
		printf("Enter the end point name correctly:\n");
		gets(c);
	}
	
	if(i!=j)
	{
		if (fabs(j - i)<2)
			tariff=10;
		else
			tariff=ceil((fabs(j - i )- 1)/2)*2 +10;
	}
	printf("Tariff for your journey is:%d\n\n\n", tariff);
	
}


//checks routinerouteuserlog file and fills the data.
void routinerouteuser()
{
	printf("1.Enter your Metro ID:\n");
	
}

//checks nonroutinerouteuserlog file and fills the data.
void nonroutinerouteuser()
{
	printf("nonroutine\n\n");
}

