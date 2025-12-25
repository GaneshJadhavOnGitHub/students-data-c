/*
Author Name :- Ganesh Kamlakar Jadhav
Date        :- 15-May-2021
Description :- This header file includes header files required for project
               and it also contains helper functions declarations/prototypes.
*/

#ifndef HEADER
#define HEADER

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<fcntl.h>
#include <time.h>
#include <sys/stat.h>
#pragma pack(1)
#include <unistd.h> // Linux Specific Not required in Windows.


typedef struct student
{
 int RollNo;
 char Name[30];
 int Marks;
 struct student* next;
}NODE, *PNODE, **PPNODE;


extern PNODE First;
extern int iSize;
extern char DBMSFile[];
extern char TempPrintFile[];

void StringCopy(char*, char*);

void InsertLast(PPNODE Head, char[30], int , int);

void Display(PNODE Head);

void DisplaySingle(PNODE Head, int);

void DeleteAtPosition(PPNODE Head, int);

void Delete(PPNODE Head, int);

void Update(PPNODE Head, int);

bool IsRollExist(PPNODE Head, int);

void swap(PNODE a, PNODE b); //Swaps nodes

void Sort(PPNODE Head);

int CalculateStrSize(char[]);

void SaveToFile(PNODE Head);

int GetNumberOfRecords(int);

void CreateNodeFromString(char[]);

void ReadFromFile();

int EncryptFile();

int DecryptFile();

void StringConcat(char *, char *);

void PrintToPDF();

void SaveToTempPrint();

void DeleteTemp();

int Fileexists(const char*);

#endif
