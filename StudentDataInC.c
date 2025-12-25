/*
 Program Description :- Program stores Students Marks in LinkedList and File
 Author Name         :- Ganesh Kamlakar Jadhav
 Date                :- 11-May-2021
 Note                :- Print to PDF application is required to Print records.(virtually without using physical printer)
                        On Ubuntu -
                        Use cups-pdf on ubuntu. Install it by using below command before executing application. 
						% sudo apt install cups-pdf
						On Windows - 
						Install PDFCreator.    
 */
#include"Header.h"

PNODE First=NULL;
int iSize=0;
char DBMSFile[]="StudentDBMS.txt";
char TempPrintFile[]="StudentsRecords.txt";

//To Do :- //Write error messages in log file to analyse the program if it crashes.
//Settings.txt
//Print records.
//http://www.falloutsoftware.com/tutorials/c/c1.htm
//https://github.com/babelouest/yder
//https://tuttlem.github.io/2012/12/08/simple-logging-in-c.html
int main()
{
 //PNODE First=NULL;
 int iChoice=1;
 int Roll=0,Marks=0;
 char Names[30];
 bool bIsExist=false;
 int fd;
 int iEncrypted;
 int iDecrypted;
// bool isTempDeleted=false;

 //system("cls");
 //char DBMSFile[] = "D:\\Windows\\CAndCPP\\C\\CPrograms\\CProgramPractiseAtHome\\StudentDBMSInC\\StudentDatabase\\StudentDBMS.txt";
 //char DBMSFile[]="StudentDBMS.txt";
 fd=open(DBMSFile,O_CREAT|O_RDWR|O_APPEND);
 if (fd==-1)
   {
    printf("\nFile Error!\n");
	close(fd);
    iChoice=0;
   }
   else
	{
	 close(fd);
	 iDecrypted=DecryptFile();
     ReadFromFile();
	 if (remove(DBMSFile)== 0)
	 {
	  //printf("Deleted successfully");
	 }
   else
		{
          //printf("\nError:Unable to delete the file\n");
        }
	 //close(fd);
    }
 while (iChoice!=0)
 {
  //printf("\n----------------------------------------\n");
  printf("\n------------Students Data------------\n");
  //printf("------------------Menu--------------------\n");
  printf("1.Insert a record\n");
  printf("2.Display all records\n");
  printf("3.Search a record\n");
  printf("4.Delete a record\n");
  printf("5.Update a record\n");
  printf("6.Print all records\n"); //Removed as not working on ubuntu. 
  printf("0.Exit the application\n");
  printf("----------------------------------------\n");
  printf("Enter your choice:- ");
  scanf("%d",&iChoice);
  switch (iChoice)
  {	
  case 1:

	  printf("\nEnter Roll Number :- ");
      scanf("%d",&Roll);
	  bIsExist=IsRollExist(&First,Roll);
	  if(bIsExist==true)
	  {
	  printf("Enter name:- ");
	  scanf(" %[^'\n']s",Names);
	  printf("Enter Marks :- ");
      scanf("%d",&Marks);
	  InsertLast(&First,Names,Roll,Marks);
	  }
	  else
	  {
	   printf("\nStudent's record already present. Please check Roll Number!\n");
	  }
	  break;
  case 2:
	  //Display(First);
	  Sort(&First);
	  Display(First);
	  break;
  case 3:
	  printf("Enter Roll Number:- ");
      scanf("%d",&Roll);
	  DisplaySingle(First,Roll);
	  break;
  case 4:
	  printf("Enter Roll Number:- ");
      scanf("%d",&Roll);
	  Delete(&First,Roll);
	  break;
  case 5:
	  printf("Enter Roll Number:- ");
      scanf("%d",&Roll);
	  Update(&First,Roll);
	  break;
  
  case 6:
	  Sort(&First);
	  SaveToTempPrint(First);
      DeleteTemp();
	  break;
  	  
  case 0:
	  Sort(&First);
      SaveToFile(First);
      iEncrypted=EncryptFile();
	  printf("Thank you for using application.\n");
	  break;
  default:
	  printf("Please enter correct option!\n");
	  break;
  
  }//End of switch
 } //End of while
 return 0;
}//End of main