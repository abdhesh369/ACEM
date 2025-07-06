

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>



struct student
{
    char ID[15];
    char name[20];
    char add[20];
    char parname[20];
    char Class[20];
    long unsigned int phone_no;
};

struct student stu;



struct marksheet
{
	char sub[6][20],ID[20];
	int tmt[6],tmp[6],pm[6],tm[6];
};
struct marksheet mark;


///This will set the forground color for printing in a console window.

void SetColor(int ForgC)
{
    WORD wColor;
    
    ///We will need this handle to get the current background attribute
    
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
  
    ///We use csbi for the wAttributes word.
    
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
       ///Mask out all but the background attribute, and add in the forgournd color;
       
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     
     ///Get the handle to the current output buffer...
     
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     
     ///This is used to reset the carat/cursor to the top left.
     
     COORD coord = {0, 0};
     
     ///A return value... indicating how many chars were written
     ///   not used but we need to capture this since it will be
     ///   written anyway (passing NULL causes an access violation).
     
     DWORD count;
     
     ///This is a structure containing all of the console info
     /// it is used here to find the size of the console.
     
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     
     ///Here we will set the current color
     
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          ///This fills the buffer with a given character (in this case 32=space).
          
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          
          ///This will set our cursor position for the next print statement.
          
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

COORD coord = {0,0};

 ///set the cordinate to 0, 0 (top-left corner of window);
 
void gotoxy(int x, int y)
{
    coord.X = x; coord.Y = y;
	
	 /// X and Y coordinates
	 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawRectangle()
{
    int i, j;
    gotoxy(0,0);
    printf("%c",201);
    for(i = 1; i < 110; i++)
	{
        gotoxy(i, 0);
        printf("%c",205);
    }
    gotoxy(110,0);
    printf("%c",187);
    for(i = 1; i < 25; i++)
	{
        gotoxy(110, i);
        if(i == 6)
		{
            printf("%c",185);
        }
		else
		{
            printf("%c",186);
        }
    }
    gotoxy(110, 25);
    printf("%c",188);
    for(i = 109; i > 0; i--)
	{
        gotoxy(i,25);
        if(i == 35)
		{
            printf("%c",202);
        }
		else
		{
            printf("%c",205);
        }
    }
    gotoxy(0,25);
    printf("%c",200);
    for(i = 24; i > 0; i--)
	{
        gotoxy(0,i);
        if(i == 6)
		{
            printf("%c",204);
        }
		else
		{
            printf("%c",186);
        }
    }

    for(i = 1; i < 110; i++)
	{
        gotoxy(i,6);
        if(i == 35){
            printf("%c",203);
        }
		else
		{
            printf("%c",205);
        }
    }

    for(i = 7; i < 25; i++)
	{
        gotoxy(35,i);
        printf("%c",186);
    }

}


void clearWindow()
{
    int i,j;
    for(i = 37; i < 110; i++)
	{
        for(j = 7; j < 25; j++)
		{
            gotoxy(i,j);
			printf(" ");
        }
    }
    return;
}

void window()
{
    drawRectangle();
    gotoxy(28,2);
    SetColor(50);
    printf("STUDENT RECORD SYSTEM");
    gotoxy(20,3);
    printf("Advanced collage of engineering and Management");
    gotoxy(31,4);
    printf("Estd.: 2099 A.D.");
    gotoxy(25,24);
    SetColor(17);

}



void print_heading(const char st[])
{
    SetColorAndBackground(31,28);
    gotoxy(45,8);
	printf("SRS : %s",st);
    SetColorAndBackground(17,15);
}




//for marksheet

void marksheet()
{
	clearWindow();
	print_heading("marksheet Record\n");
    SetColor(20);
	char s_id[15];
	gets(s_id);


    
	int i;
	clearWindow();
	print_heading("marksheet Record\n");
	FILE *fpp;
	fpp = fopen("marksheet.txt","ab+");
	gotoxy(37,9);
	printf("enter student id :   ");
	scanf("%s",&mark.ID);
	for(i=1;i<=6;i++)
	{
		clearWindow();
		print_heading("marksheet Record\n");
		gotoxy(37,9);
		printf("student id : %s",mark.ID);
		gotoxy(37,10);
		printf("enter the subject %d name :",i);
		scanf("%s",&mark.sub[i]);
		gotoxy(37,11);
		printf("enter total marks in theory and practical in %s  : ",mark.sub[i]);
		scanf("%d",&mark.tmt[i]);
		gotoxy(88,12);
		scanf("%d",&mark.tmp);
		gotoxy(37,13);
		printf("enter the obtain marks in theory in	 %s :  ",mark.sub[i]);
		scanf("%d",&mark.tm);
		gotoxy(37,14);
		printf("Enter the obtain marks in practical in 	%s : ",mark.sub[i]);
		scanf("%d",&mark.pm);
		
	}
	 fwrite(&mark, sizeof(mark), 1, fpp);
    gotoxy(40,22);
	 printf("The record is sucessfully added");
	fclose(fpp);
	return ;
}




//	search marksheet

void search_marksheet()
{
    clearWindow();
    print_heading("Search Record");
    SetColor(45);
   
   
    char id[15];
    int isFound = 0;
    gotoxy(37,9);
	printf("Enter ID to Search: ");
	fflush(stdin);
	scanf("%s",&id);
	printf("\n");
    FILE *fpp;
    fpp = fopen("marksheet.txt","rb");    
    
    while(fread(&mark,sizeof(mark),1,fpp) == 1)
	{
		

        if(strcmp(id,mark.ID) == 1)
		{
			
            isFound = 1;
            break;
        }
    }
    
    if(isFound == 1)
	{
        gotoxy(37,9);
		printf("The record is Found");
        gotoxy(37,10);
		printf("ID: %s",mark.ID);
        int i;
        for(i=1;i<=6;i++)
        {
        	int j;

        	if(i==1)
        	{
        		gotoxy(37,11);
				printf("%s",mark.sub[i]);
        		gotoxy(37,11);
				printf("total marks in theory is:%d total marks in practical is:%d",mark.tmt[i],mark.tmp[i]);
        		gotoxy(37,12);
				printf("obtain marks in theory is:%d   obtain marks in practical is:%d",mark.tm[i],mark.pm[i]);
			}
			if(i==2)
        	{
        		gotoxy(37,13);
				printf("%s",mark.sub[i]);
        		gotoxy(37,13);
				printf("total marks in theory is:%d total marks in practical is:%d",mark.tmt[i],mark.tmp[i]);
        		gotoxy(37,14);
				printf("obtain marks in theory is:%d   obtain marks in practical is:%d",mark.tm[i],mark.pm[i]);
			}
			if(i==3)
        	{
        		gotoxy(37,15);
				printf("%s",mark.sub[i]);
        		gotoxy(37,15);
				printf("total marks in theory is:%d total marks in practical is:%d",mark.tmt[i],mark.tmp[i]);
        		gotoxy(37,16);
				printf("obtain marks in theory is:%d   obtain marks in practical is:%d",mark.tm[i],mark.pm[i]);
			}
			if(i==4)
        	{
        		gotoxy(37,17);
				printf("%s",mark.sub[i]);
        		gotoxy(37,17);
				printf("total marks in theory is:%d total marks in practical is:%d",mark.tmt[i],mark.tmp[i]);
        		gotoxy(37,18);
				printf("obtain marks in theory is:%d   obtain marks in practical is:%d",mark.tm[i],mark.pm[i]);
			}
			if(i==5)
        	{
        		gotoxy(37,19);
				printf("%s",mark.sub[i]);
        		gotoxy(37,19);
				printf("total marks in theory is:%d total marks in practical is:%d",mark.tmt[i],mark.tmp[i]);
        		gotoxy(37,20);
				printf("obtain marks in theory is:%d   obtain marks in practical is:%d",mark.tm[i],mark.pm[i]);
			}
			if(i==6)
        	{
        		gotoxy(37,21);
				printf("%s",mark.sub[i]);
        		gotoxy(37,21);
				printf("total marks in theory is:%d total marks in practical is:%d",mark.tmt[i],mark.tmp[i]);
        		gotoxy(37,22);
				printf("obtain marks in theory is:%d   obtain marks in practical is:%d",mark.tm[i],mark.pm[i]);
			}	
		}
    }
	else
	{
        gotoxy(37,12);
		printf("Sorry, No record found in the database");
    }
    SetColor(28);
    fclose(fpp);
    return;
}




void add_student()
{
    clearWindow();
    print_heading("Add Record");
    int print = 37;
    FILE *fp;
    fp = fopen("record.txt","ab+");
    SetColor(45);
    if(fp == NULL)
	{
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }
	else
	{
        fflush(stdin);
        gotoxy(print,10);
		printf("ID: ");
		gets(stu.ID);
        gotoxy(print,12);
		printf("Name: ");
		gets(stu.name);
        gotoxy(print,14);
		printf("Address: ");
		gets(stu.add);
        gotoxy(print,16);
		printf("Parent's name: ");
		gets(stu.parname);
        gotoxy(print,18);
		printf("Class: ");
		gets(stu.Class);
        gotoxy(print,20);
		printf("Phone Number: ");
		scanf("%ld",&stu.phone_no);
        fwrite(&stu, sizeof(stu), 1, fp);
        gotoxy(40,22);
		 printf("The record is sucessfully added");
    }
    SetColor(28);
    fclose(fp);
    return;
}

void search_student()
{
    clearWindow();
    print_heading("Search Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0;
    gotoxy(37,10);
	printf("Enter ID to Search: ");
	fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp) == 1)
	{
        if(strcmp(s_id,stu.ID) == 0)
		{
            isFound = 1;
            break;
        }
    }
    if(isFound == 1)
	{
        gotoxy(37,12);
		printf("The record is Found");
        gotoxy(37,14);
		printf("ID: %s",stu.ID);
        gotoxy(37,15);
		printf("Name: %s",stu.name);
        gotoxy(37,16);
		printf("Address: %s",stu.add);
        gotoxy(37,17);
		printf("Parent's Name: %s",stu.parname);
        gotoxy(37,18);
		printf("Class: %s",stu.Class);
        gotoxy(37,19);
		printf("Phone No: %ld",stu.phone_no);
    }else{
        gotoxy(37,12);
		printf("Sory, No record found in the database");
    }
    SetColor(28);
    fclose(fp);
    return;
}

void mod_student()
{
    clearWindow();
    print_heading("Modify Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);
	printf("Enter ID to Modify: ");
	fflush(stdin);
    scanf("%s",&s_id);
    FILE *fp;
    fp = fopen("record.txt","rb+");
    while(fread(&stu, sizeof(stu),1,fp) == 1)
	{
        if(strcmp(s_id, stu.ID) == 0){
            fflush(stdin);
            gotoxy(print,12);
			printf("ID: ");
			gets(stu.ID);
            gotoxy(print,13);
			printf("Name: ");
			gets(stu.name);
            gotoxy(print,14);
			printf("Address: ");
			gets(stu.add);
            gotoxy(print,15);
			printf("Parent's name: ");
			gets(stu.parname);
            gotoxy(print,16);
			printf("Class: ");
			scanf("%s",&stu.Class);
            gotoxy(print,17);
			printf("Phone Number: ");
			scanf("%ld",&stu.phone_no);
            fseek(fp,sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound)
	{
        gotoxy(print, 12);
		printf("No Record Found");
    }
    fclose(fp);
    SetColor(28);
    return;
}



void delete_student()
{
    clearWindow();
    print_heading("Delete Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);
	printf("Enter ID to Modify: ");
	fflush(stdin);
    gets(s_id);
    FILE *fp, *temp;
    fp = fopen("record.txt","rb");
    temp = fopen("temp.txt", "wb");
    while(fread(&stu, sizeof(stu),1,fp) == 1)
	{
        if(strcmp(s_id, stu.ID) == 0)
		{
            fwrite(&stu,sizeof(stu),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);
    
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(37,12);
	printf("The record is sucessfully deleted");
    SetColor(28);
    return;
}


void main_window()
{
    int choice;
    SetColor(28);
    int x = 2;
    while(1)
	{
        gotoxy(x,8);
		printf("1. Add Student");
        gotoxy(x,10);
		printf("2. Search Student");
        gotoxy(x,12);
		printf("3. Modify Student Record");
        gotoxy(x,14);
		printf("4. Delete Student Record");
        gotoxy(x,16);
		printf("5. Generate Marksheet");
        gotoxy(x,18);
		printf("6. Search Marksheet");
        gotoxy(x,20);
		printf("7. Exit");
        gotoxy(x,22);
		printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
		{
            case 1:
                add_student();
                break;
            case 2:
                search_student();
                break;
            case 3:
                mod_student();
                break;
            case 4:
            	delete_student();
                break;
            case 5:
                marksheet();
                break;
            case 6:
            	search_marksheet();
                break;
            case 7:
            	exit(0);
//                exits();
                break;
            default:
                break;
        }

    }

}

//main function

int main()
{
    ClearConsoleToColors(17,14);
    
//    SetConsoleTitle("Student Record System");

    window();
    main_window();
    return 0;
}
