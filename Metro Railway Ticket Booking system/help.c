#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


void main()
{
	//char a;
	//a=getchar();
	//printf("%d",a);
	FILE *fp2=fopen("D:/Desktop/Projects/C/copyroutinerouteuserlog.csv","r+");
		char line[200];
		char *var1;
		if(fp2==NULL)
		{
			printf("error in opening the file\n");
		}
		else
		{
			while(fgets(line,200,fp2)!=NULL)
			{
				int i=0;
				for(i=0;i<strlen(line);i++)
				{
					
					printf("%c",line[i]);
				}
				//fseek(fp2,619,0);
			//fprintf(fp2,"%s,%s,%s,%s\n","cana","tur","barhjk","9070842121");
			}
		
		
		}
			fclose(fp2);
			//fseek(fp2,620,0);
		//rename("D:/Desktop/Projects/C/1.csv","D:/Desktop/Projects/C/2.csv");
}