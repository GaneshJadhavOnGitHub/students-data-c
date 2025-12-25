/*
Author Name :- Ganesh Kamlakar Jadhav
Date        :- 15-May-2021
Description :- This file conatins helper functions definitions for StudentDataInC.c 
*/

#include"Header.h"

extern PNODE First;
extern int iSize;
extern char DBMSFile[];

void StringCopy(char *src, char *dest)
{
 while (*src!='\0')
 {
  *dest=*src;
  src++;
  dest++;
 }
 *dest='\0'; //Most important statement.
}

void InsertLast(PPNODE Head, char Name[30],int Roll, int Marks)
{
 PNODE newn = NULL;
 newn=(PNODE)malloc(sizeof(NODE));
 newn->RollNo=Roll;
 //newn->Name=Name; //Error as one string can not be assigned to other.
 StringCopy(Name,newn->Name);
 newn->Marks=Marks;
 newn->next=NULL;
 
 PNODE temp=*Head;
 if (*Head==NULL)
 {
  *Head=newn;
 }
 else
 {
  while (temp->next!=NULL)
  {
   temp=temp->next;
  }
  temp->next=newn;
 }
 iSize++;
}

void Display(PNODE Head)
{
 PNODE temp=Head;
 int Count=0;
 int BlankSpaces=0;
 int i=0;
 int CountRoll=0;
 int BlankSpacesRoll=0;
 time_t t;

 time(&t);
 char *currentTime = ctime(&t);
 printf("\nTotal Number of Students are:- %d as on %s\n",iSize, currentTime);
   //printf("-------------------------------------------------------------\n");
   //printf("---------------------Students Records------------------------\n");
   printf("|-----------|------------------------------|----------------|\n");
   printf("|Roll Number|           Name               |      Marks     |\n");
   printf("|-----------|------------------------------|----------------|\n");

 while (temp!=NULL)
 {
  CountRoll=printf("| %d",temp->RollNo);
  //printf("%d",CountRoll);
   printf("           ");
  Count=printf("%s",temp->Name);
  BlankSpaces=30-Count;
  for(i=1;i<BlankSpaces;i++)
  {
   printf(" ");
  }
  //printf("|");
  printf("     ");
  printf("%d",temp->Marks);
  printf("\n|-----------|------------------------------|----------------|\n");
  temp=temp->next;
 }
}

void DisplaySingle(PNODE Head, int RollNo)
{
 PNODE temp=Head;
 int Count=0;
 int BlankSpaces=0;
 int i=0;
 bool flag=false;
 
 while (temp!=NULL)
 {
  if (temp->RollNo==RollNo)
  {
   //printf("-------------------------------------------------------------\n");
  // printf("---------------------Students Records------------------------\n");
   printf("|-----------|------------------------------|----------------|\n");
   printf("|Roll Number|           Name               |      Marks     |\n");
   printf("|-----------|------------------------------|----------------|\n");

    printf("| %d",temp->RollNo);
    printf("           ");
    Count=printf("%s",temp->Name);
    BlankSpaces=30-Count;
    for(i=1;i<BlankSpaces;i++)
    {
      printf(" ");
     }
    printf("|");
    printf("     ");
    printf("%d",temp->Marks);
    printf("\n|-----------|------------------------------|----------------|\n");
	flag=true;
  } //End of if
  temp=temp->next;
 } //End of while
 if (flag==false)
 {
  printf("\nRecord not found. Please check Roll Number!\n");
 }
}

void DeleteAtPosition(PPNODE Head, int iPos)
{
 int i=0;
 PNODE temp1=*Head;
 PNODE target=NULL;
 if ((iPos<1)||(iPos>iSize)) //Invalid Position
 {
  return;
 }
 if (iPos==1) //Position is one i.e First node
 {
  //DeleteFirst(Head);
    PNODE temp2= *Head;
 if (*Head==NULL) //List is empty
 {
  return;
 }
 else if ((*Head)->next==NULL) //List contains single node
 {
  free(*Head);
  *Head=NULL;
 }
 else
 {
  *Head=(*Head)->next; //Make second node as First node
  free(temp2);
 }
 } //End of if
 else if (iPos==iSize) //Position is iSize i.e. Last Position
 {
  //DeleteLast(Head);
    PNODE temp3= *Head;
 if (*Head==NULL) //List is empty
 {
  return;
 }
 else if ((*Head)->next==NULL) //List contains single node
 {
  free(*Head);
  *Head=NULL;
 }
 else
 {
  while (temp3->next->next!=NULL) //Go to last but one
  {
   temp3 = temp3 ->next;
  }
  free(temp3->next); //Free last
  temp3->next=NULL;
 }
 } //End of else if
 else //Insert at given position which is between first and last position.
 {

  for (i=1;i<iPos-1 ;i++)
  {
    temp1=temp1->next;
  }
  target=temp1->next;

  temp1->next=target->next;
  free(target);
 }
} //End of Function

void Delete(PPNODE Head, int RollNo)
{
 PNODE temp=*Head;
 //PNODE target=NULL;
 bool flag=false;
 int iPos=0;
 int iCnt=0;
 while (temp!=NULL)
 {
  iCnt++;
  if (temp->RollNo==RollNo)
  {
	iPos=iCnt;
	printf("Record is at position %d\n",iPos);
    DeleteAtPosition(Head,iPos);
	printf("\nRecord deleted successfully!\n");
	flag=true;
	iSize--;
  } //End of if
  temp=temp->next;
 } //End of while
 if (flag==false)
 {
  printf("\nRecord not found. Please check Roll Number!\n");
 }
}

void Update(PPNODE Head, int RollNo)
{
 PNODE temp=*Head;
 bool flag=false;
 char NewName[30];
 int NewMarks=0;
 while (temp!=NULL)
 {
  if (temp->RollNo==RollNo)
  {
	printf("\nEnter new Name:- ");
	scanf(" %[^'\n']s",NewName);
	printf("Enter new Marks:- ");
	scanf("%d",&NewMarks);
	StringCopy(NewName,temp->Name);
	temp->Marks=NewMarks;
	printf("\nRecord updated successfully!\n");
	flag=true;
  } //End of if
  temp=temp->next;
 } //End of while
 if (flag==false)
 {
  printf("\nRecord not found. Please check Roll Number!\n");
 }
}

bool IsRollExist(PPNODE Head, int RollNo)
{
 bool bRet=true;
 PNODE temp=*Head;
 while (temp!=NULL)
 {
  if (temp->RollNo==RollNo)
  {
	bRet=false;
	break;
  } //End of if
  temp=temp->next;
 } //End of while
  return bRet;
}
void swap(PNODE a, PNODE b) //Swaps nodes
{
	int tempRoll;
	char tempName[30];
	int tempMarks;

    tempRoll = a->RollNo;
    StringCopy(a->Name,tempName);
	tempMarks=a->Marks;

    a->RollNo = b->RollNo;
	StringCopy(b->Name,a->Name);
	a->Marks=b->Marks;
    
	b->RollNo = tempRoll;
    StringCopy(tempName,b->Name);
	b->Marks=tempMarks;
	
}
void Sort(PPNODE Head)
{
	int swapped;
	PNODE temp=NULL;
	PNODE iterator=NULL;
     
    if (*Head == NULL) // If list is empty
	{
        return;
    }
    do
    {
        swapped = 0;
        temp = *Head;
  
        while (temp->next != iterator)
        {
            if (temp->RollNo > temp->next->RollNo)
            { 
                swap(temp, temp->next);
                swapped = 1;
            }
            temp = temp->next;
        }
        iterator = temp;
    }
    while (swapped);
}

int CalculateStrSize(char str[])
  {
   int iSize=0;
   int i=0;
   while (str[i]!='\0')
   {
    iSize++;
	i++;
   }
   return iSize;
  }
  /*
  void WriteData(char str[], int iSize)
  {
   write(fd,str,iSize);
  }
  */

void SaveToFile(PNODE Head)
{
 int fd=0;
 PNODE temp=Head;
 fd=open(DBMSFile,O_CREAT|O_WRONLY|O_APPEND);
 if (fd==-1)
   {
    printf("\nFile Error!\n");
	  close(fd);
   }
 while (temp!=NULL)
 {
  int iRollNo=0;
  char cName[30];
  int iMarks=0;
  char cRollNo[5];
  char cMarks[5];
  iRollNo=temp->RollNo;
  StringCopy(temp->Name,cName);
  iMarks=temp->Marks;
  snprintf(cRollNo, sizeof(cRollNo), "%d", iRollNo); //Convert integer iRollNo to character array to write to file.
  snprintf(cMarks, sizeof(cMarks), "%d", iMarks);
  int SizeRollNo = CalculateStrSize(cRollNo);
  int SizeName=CalculateStrSize(cName);
  int SizeMarks=CalculateStrSize(cMarks);
  
  write(fd,cRollNo,SizeRollNo);
  write(fd," ",1);
  write(fd,cMarks,SizeMarks);
  write(fd," ",1);
  write(fd,cName,SizeName);
  write(fd,"\n",1);
 
  temp=temp->next;
 }
 close(fd);
}

int GetNumberOfRecords(int fd)
{
 int ret=0;
 char Arr[1]={'\0'};
 int iCnt=0;
 while ((ret=read(fd,Arr,1))!=0)
  {
   //printf("%s",Arr);
   if (Arr[0]=='\n')
   {
     iCnt++;
   }
  }
  close(fd);
  return iCnt;
}

void CreateNodeFromString(char buffer[])
{
   //printf("Node is :- %s",buffer);
   char *s=NULL;
   s=buffer;
   char name[30];
   int roll;
   int marks;
   int total_read;
   total_read=sscanf(s,"%d %d %[^'\n']s",&roll,&marks,name); //This sequence of roll,marks and name is important.
   //printf("Roll:%d Name:%s Marks:%d\n",roll,name,marks);
   //printf("\ntotal read:- %d",total_read);
   InsertLast(&First,name,roll,marks);

}
void ReadFromFile()
{
  char cNode[38];
  int ret=0;
  char Arr[1]={'\0'};
  int i=0;
  int NumberOfRecords=0;
  FILE *file = fopen(DBMSFile, "r" );
  /*
  NumberOfRecords=GetNumberOfRecords(fd);
  printf("\nTotal Number of Records are :- %d\n",NumberOfRecords);
  int SizeOfEachRecord[NumberOfRecords];
  
  for (i=0;i<NumberOfRecords;i++)
  {
    
  }
  */
     if (file!=NULL)
   {
      //char line [128]; /* or other suitable maximum line size */
	  int whilecounter=0;
      while (fgets(cNode, sizeof cNode, file) != NULL ) /* read a line */
      {
       //fputs(cNode,stdout ); /* write the line */
	   whilecounter++;
	   CreateNodeFromString(cNode);
      }
	  //printf("\nWhileCounter is %d\n",whilecounter);
      fclose(file);
   }
   else
   {
     printf("\nError reading database!\n"); 
   }
 }

int EncryptFile()
{
  char ch;
  FILE *fps, *fpt;
  fps = fopen(DBMSFile, "r");
    if(fps == NULL)
	{
     return -1;
	}
  fpt = fopen("temp.txt", "w");
  if(fpt == NULL)
	{
     return -1;
	}
   ch = fgetc(fps);
   while(ch != EOF)
    {
        ch = ch+100;
        fputc(ch, fpt);
        ch = fgetc(fps);
    }
    fclose(fps);
    fclose(fpt);
   fps = fopen(DBMSFile, "w");
   if(fps == NULL)
	{
     return -1;
	}
  fpt = fopen("temp.txt", "r");
  if(fpt == NULL)
	{
     return -1;
	}
  ch = fgetc(fpt);
  while(ch != EOF)
    {
     ch = fputc(ch, fps);
     ch = fgetc(fpt);
    }
   fclose(fps);
   fclose(fpt);
   //printf("\nFile %s Encrypted Successfully!", DBMSFile);
  return 0;
}

 int DecryptFile()
{
 char ch;
 FILE *fps, *fpt;
 fps = fopen(DBMSFile, "w");
 if(fps == NULL)
	{
     return -1;
	}
 fpt = fopen("temp.txt", "r");
 if(fpt == NULL)
	{
     return -1;
	}
 ch = fgetc(fpt);
    while(ch != EOF)
    {
        ch = ch-100;
        fputc(ch, fps);
        ch = fgetc(fpt);
    }
 fclose(fps);
 fclose(fpt);
 //printf("\nFile %s Decrypted Successfully!", DBMSFile);
 if (remove("temp.txt") == 0)
 {
  
 } 
 else
  {
   printf("Unable to delete the file");
  }

 return 0;
}
void StringConcat(char *src, char *dest)
{
 int iLength=0;
 if ((src==NULL)||(dest==NULL))
 {
  return;
 }
 while (*src!='\0')
 {
  src++;
  iLength++;
 }
 *src=' '; //To insert one space at the end of first string.
 src++;    //Increment the src after adding space. 
 while (*dest!='\0')
 {
  *src=*dest;
   dest++;
   src++;
 }
 *src='\0';
}


void PrintToTextFileWindows()
{
 int c, d;
 char PrintCommand[40]="NOTEPAD /P";
 StringConcat(PrintCommand,TempPrintFile);
 //printf("PrintCommand is:-  %s",PrintCommand);
  system(PrintCommand);
 //system("PRINT StudentDBMS.txt");
    //Delay for some time.
   for (c = 1; c <= 32767; c++)
       for (d = 1; d <= 32767; d++)
       {}
}

void PrintToTextFileLinux()
{
    char PrintCommand[256]; 

    // 'lpr' is the standard Linux command to print a file.
    // snprintf - Write a formatted string into a char array.
    // Using snprintf as it prevents buffer overflow , instead of manual string concatenation.
    // Reference - https://www.w3schools.com/c/ref_stdio_snprintf.php
    snprintf(PrintCommand, sizeof(PrintCommand), "lpr %s", TempPrintFile);

    // This sends the file to default printer.
    int status = system(PrintCommand);
    
    if (status == -1) {
        perror("Error executing print command");
    }
    // Sleep for 2 seconds (adjust as needed).
    sleep(2); 
}

void SaveToTempPrint(PNODE Head)
{
 int fd=0;
 PNODE temp=Head;
 //fd=open(TempPrintFile,O_CREAT|O_WRONLY|O_APPEND);

 fd=open(TempPrintFile,O_CREAT|O_WRONLY); //Need to create temporary file everytime user choses print option.
 if (fd==-1)
   {
    printf("\nFile Error!\n");
	close(fd);
   }
 
 //write(fd,"|-----------------------------------\n|",40);
 //write(fd,"|RollNo\t|Marks\t|        Name              |",45); //For Windows
 write(fd,"|RollNo\t|Marks\t|        Name              |",44); //Ubuntu Specific
 //write(fd,"|-----------------------------------\n|",40);
 write(fd,"\n",1);
 
 while (temp!=NULL)
 {
  int iRollNo=0;
  char cName[30];
  int iMarks=0;
  char cRollNo[5];
  char cMarks[5];
  iRollNo=temp->RollNo;
  StringCopy(temp->Name,cName);
  iMarks=temp->Marks;
  snprintf(cRollNo, sizeof(cRollNo), "%d", iRollNo); //Convert integer iRollNo to character array to write to file.
  snprintf(cMarks, sizeof(cMarks), "%d", iMarks);
  int SizeRollNo = CalculateStrSize(cRollNo);
  int SizeName=CalculateStrSize(cName);
  int SizeMarks=CalculateStrSize(cMarks);
  
  
  write(fd,cRollNo,SizeRollNo);
  write(fd,"\t",1);
  write(fd,cMarks,SizeMarks);
  write(fd,"\t",1);
  write(fd,cName,SizeName);
  write(fd,"\n",1);
 
  temp=temp->next;
 }
 close(fd);
 PrintToTextFileLinux();
 //PrintToTextFileWindows(); // For Windows
}

int Fileexists(const char* filename){
    struct stat buffer;
    int exist = stat(filename,&buffer);
    if(exist == 0)
        return 1;
    else // -1
        return 0;
}


void DeleteTemp()
{
    char* filename = TempPrintFile;
    int exist = Fileexists(filename);
    if(exist)
     //printf("File %s exist",filename);
	 remove(TempPrintFile);

    else
	{
     //printf("File %s does not exist",filename);
	}
	 
}