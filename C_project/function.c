#include"function.h"
#include <stdio.h>
#include<string.h>
#include <stdbool.h>
#include"datatype.h"

//#define maxUsers 100
//#define maxIdLenght 20

void showMenu(){
    	printf("  ***Bank Management System Using C***\n\n");
    	printf("\t  CHOOSE YOUR ROLE\n");
    	printf("\t========================\n");
    	printf("\t[1] Admin.\n");
    	printf("\t[2] User.\n");
	    printf("\t[0] Exit The Program.\n");
	    printf("\t========================\n");
        }
void adminMenu(){
    	printf("\n  ***Bank Management System Using C***\n\n");
    	printf("\t   ADMIN MENU\n");
    	printf("\t========================\n");
    	printf("\t[1] Add A New User.\n");
    	printf("\t[2] Show All users.\n");
    	printf("\t[3] Search User By Name.\n");
    	printf("\t[4] Check User Datas By ID.\n");
    	printf("\t[5] Lock/Unlock User By ID.\n");
    	printf("\t[6] Arrange Users List.\n");	
    	printf("\t[0] Return To Menu.\n");
    	printf("\t========================\n");
        }
void inputUsersData(struct User users[], int *length){
	int check=0;
	int subCheck;
	int i;
	printf("\n");
	getchar();
	while(check==0){
		printf("*Enter User ID: ");
		fgets(users[*length].userId,sizeof(users[*length].userId),stdin);
		users[*length].userId[strcspn(users[*length].userId,"\n")]='\0';
		fflush(stdin);
		if(strlen(users[*length].userId)>9 || strlen(users[*length].userId)==0 ){
			printf(" *Invalid Input.Try again!*\n");
			fflush(stdin);
		}else{
			subCheck=1;
			fflush(stdin);
			for(i=0;i<*length;i++){
				if(strcmp(users[*length].userId,users[i].userId)==0){
					printf(" *Users Information Must Not Overlap!* \n");	
					subCheck=0;
					break;
				}
			}
			if(subCheck!=0){
				break;
			}
		}
	} 
 printf("Enter Phone Number: ");
    fgets(users[*length].phoneNumber, sizeof(users[*length].phoneNumber), stdin);
    users[*length].phoneNumber[strcspn(users[*length].phoneNumber, "\n")] = '\0';  
 printf("ENTER EMAILS: ");
    fgets(users[*length].email,sizeof(users[*length].email),stdin);
    users[*length].email[strcspn(users[*length].email,"\n")]='\0';
    } 

