#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define MAX  100

void main()
{
	FILE *fp;
	char str[MAX]="input.txt";
	int state=0;
	int i=0, j, startid=0, endid, startcon, endcon;

	clrscr();

	for(j=0; j<MAX; j++)
		str[j]=NULL;

	  printf("File to open: \n", &str );
	  gets(str);
	  fp = fopen(str, "r");


	  if (fp)
			 {
			fgets(str, 60, fp);
			str[strlen(str)] = '\0';
			printf("The name read from the file is %s.\n", str );
		  }
	  else
		  {
		  printf("An error occurred while opening the file.\n");
		  }


	printf("\n Analysis: \n");

	while(str[i]!=NULL)
	{
		while(str[i]==' ')
			i++;
		switch(state)
		{
			case 0: if(str[i]=='i') state=1;
					  else if(str[i]=='w') state=3;
					  else if(str[i]=='d') state=8;
					  else if(str[i]=='e') state=10;
					  else if(str[i]=='f') state=14;
					  else if(isalpha(str[i]) || str[i]=='_')
					  {
						state=17;
						startid=i;
					  }

					  else if(str[i]=='<') state=19;

					  else if(str[i]=='>') state=21;

					  else if(str[i]=='=') state=23;

					  else if(isdigit(str[i]))
					  {
						state=25; startcon=i;
					  }

					  else if(str[i]=='(') state=26;

					  else if(str[i]==')') state=27;

					  else if(str[i]==';') state=28;

					  else if(str[i]=='+') state=29;

					  else if(str[i]=='-') state=30;

					  break;

			case 1: if(str[i]=='f') state=2;
					  else { state=17; startid=i-1; i--; }
					  break;
			case 2: if(str[i]=='(' || str[i]==NULL)
					  {
						  printf("\nif : Keyword \n");
						  state=0;
						  i--;
					  }
					  else { state=17; startid=i-2; i--; }
					  break;

			case 3: if(str[i]=='h') state=4;
					  else { state=17; startid=i-1; i--; }
					  break;
			case 4: if(str[i]=='i') state=5;
					  else { state=17; startid=i-2; i--; }
					  break;
			case 5: if(str[i]=='l') state=6;
					  else { state=17; startid=i-3; i--; }
					  break;
			case 6: if(str[i]=='e') state=7;
					  else { state=17; startid=i-4; i--; }
					  break;
			case 7: if(str[i]=='(' || str[i]==NULL)
					  {
						  printf("\nwhile : Keyword \n");
						  state=0;
						  i--;
					  }
					  else { state=17; startid=i-5; i--; }
					  break;

			case 8: if(str[i]=='o') state=9;
					  else { state=17; startid=i-1; i--; }
					  break;
			case 9: if(str[i]=='{' || str[i]==' ' || str[i]==NULL || str[i]=='(')
					  {
						  printf("\ndo : Keyword \n");
						  state=0;
						  i--;
					  }
					  break;

			case 10: if(str[i]=='l') state=11;
						else { state=17; startid=i-1; i--; }
						break;
			case 11: if(str[i]=='s') state=12;
						else { state=17; startid=i-2; i--; }
						break;
			case 12: if(str[i]=='e') state=13;
						else { state=17; startid=i-3; i--; }
						break;
			case 13: if(str[i]=='{' || str[i]==NULL)
						{
							printf("\nelse : Keyword \n");
							state=0;
							i--;
						}
						else { state=17; startid=i-4; i--; }
						break;

			case 14: if(str[i]=='o') state=15;
						else { state=17; startid=i-1; i--; }
						break;
			case 15: if(str[i]=='r') state=16;
						else { state=17; startid=i-2; i--; }
						break;
	 case 16: if(str[i]=='(' || str[i]==NULL)
						{
							printf("\nfor : Keyword \n");
							state=0;
							i--;
						}
						else { state=17; startid=i-3; i--; }
						break;

			case 17:

			if(isalnum(str[i]) || str[i]=='_')
			{
				state=18; i++;
			}
else if(str[i]==NULL||str[i]=='<'||str[i]=='>'||str[i]=='('||str[i]==')'||str[i]==';'||str[i]=='='||str[i]=='+'||str[i]=='-') state=18;
						i--;
						break;

			case 18:

if(str[i]==NULL || str[i]=='<' || str[i]=='>' || str[i]=='(' || str[i]==')' || str[i]==';' || str[i]=='=' || str[i]=='+' ||str[i]=='-')
						{
							endid=i-1;
							printf("\n");
							for(j=startid; j<=endid; j++)
								printf("%c", str[j]);
							printf(" : indentifier ",str[j]);
							state=0;
							i--;
						}
						break;


			case 19: if(str[i]=='=') state=20;
						else if(isalnum(str[i]) || str[i]=='_')
						{
							printf("\n< : Relational operator \n");
							i--;
							state=0;
						}
						break;
			case 20: if(isalnum(str[i]) || str[i]=='_')
						{
							printf("\n\n<= : Relational operator \n\n");
							i--;
							state=0;
						}
						break;


			case 21: if(str[i]=='=') state=22;
						else if(isalnum(str[i]) || str[i]=='_')
						{
							printf("\n\n> : Relational operator \n\n");
							i--;
							state=0;
						}
						break;
			case 22: if(isalnum(str[i]) || str[i]=='_')
						{
							printf("\n\n>= : Relational operator \n\n");
							i--;
							state=0;
						}
						break;

			case 23: if(str[i]=='=') state=24;
						else
						{
							printf("\n\n= : Assignment operator \n\n");
							i--;
							state=0;
						}
						break;
			case 24: if(isalnum(str[i]))
						{
							printf("\n\n== : Relational operator \n\n");
							state=0;
							i--;
						}
						break;

			case 25: if(isalpha(str[i]))
						{
							printf("*** ERROR ***");
							puts(str);
							for(j=0; j<i; j++)
							printf(" ");
							printf("^");
							printf("\n Error at position %d Alphabet cannot follow digit \n", i);
							state=99;
						}
else if(str[i]=='(' || str[i]==')' || str[i]=='<' || str[i]=='>' || str[i]==NULL || str[i]==';' || str[i]=='=')
						{
							endcon=i-1;
							printf("\n");
							for(j=startcon; j<=endcon; j++)
								printf("%c", str[j]);
							printf(" : Constant ",str[j]);
							state=0;
							i--;
						}
						break;

			case 26: printf("\n\n( : Special character \n\n");
						startid=i;
						state=0;
						i--;
						break;

			case 27: printf("\n\n) : Special character \n\n");
						state=0;
						i--;
						break;

			case 28: printf("\n\n;  : Special character \n\n");
						state=0;
						i--;
						break;

			case 29: printf("\n\n+ : Operator \n\n");
						state=0;
						i--;
						break;

			case 30: printf("\n\n- : Operator \n\n");
						state=0;
						i--;
						break;

			case 99: goto END;
		}
		i++;
	}
	printf("\n End of program \n");
	END:

   fclose(fp);
	getch();
}