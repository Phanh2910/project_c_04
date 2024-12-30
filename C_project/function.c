#include"function.h"
#include <stdio.h>
#include<string.h>
#include <stdbool.h>
#include "datatype.h"

//#define maxUsers 100
//#define maxIdLenght 20

void showMenu(){
    	printf("  ***Bank Management System Using C***\n\n");
    	printf("\t  CHOOSE YOUR ROLE\n");
    	printf("\t========================\n");
    	printf("\t[1] Admin.\n");
    	printf("\t[2] Users.\n");
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
        


//void inputUsersData(struct User users[], int *length){
//	int check=0;
//	int subCheck;
//	int i;
//	printf("\n");
//	getchar();
//	while(check==0){
//		printf("*Enter User ID: ");
//		fgets(users[*length].userId,sizeof(users[*length].userId),stdin);
//		users[*length].userId[strcspn(users[*length].userId,"\n")]='\0';
//		fflush(stdin);
//		if(strlen(users[*length].userId)>9 || strlen(users[*length].userId)==0 ){
//			printf(" *Invalid Input.Try again!*\n");
//			fflush(stdin);
//		}else{
//			subCheck=1;
//			fflush(stdin);
//			for(i=0;i<*length;i++){
//				if(strcmp(users[*length].userId,users[i].userId)==0){
//					printf(" *Users Information Must Not Overlap!* \n");	
//					subCheck=0;
//					break;
//				}
//			}
//			if(subCheck!=0){
//				break;
//			}
//		}
//	} 
// printf("Enter Phone Number: ");
//    fgets(users[*length].phoneNumber, sizeof(users[*length].phoneNumber), stdin);
//    users[*length].phoneNumber[strcspn(users[*length].phoneNumber, "\n")] = '\0';  		
// printf("ENTER EMAILS: ");
//    fgets(users[*length].email,sizeof(users[*length].email),stdin);
//    users[*length].email[strcspn(users[*length].email,"\n")]='\0';
//    } 
// Input user data (ID, Name, Phone, Email) and update the users array
void inputUsersData(struct User users[], int *length) {
    char temp[25];
    int subCheck;
	int i;
    while (1) {
        printf("*Enter User's ID (max 10 chars): ");
        fgets(users[*length].userId, sizeof(users[*length].userId), stdin);
        users[*length].userId[strcspn(users[*length].userId, "\n")] = 0;

        if (strlen(users[*length].userId) < 1 || strlen(users[*length].userId) > 9) {
            printf("Invalid ID. Try again.\n");
        } else {
            subCheck = 1;
            for (i = 0; i < *length; i++) {
                if (strcmp(users[*length].userId, users[i].userId) == 0) {
                    subCheck = 0;
                    printf("ID already exists. Try again.\n");
                    break;
                }
            }
            if (subCheck) break;
        }
    }
    while (1) {
        printf("*Enter User's Name (max 20 chars): ");
        fgets(users[*length].name, sizeof(users[*length].name), stdin);
        users[*length].name[strcspn(users[*length].name, "\n")] = 0;

        if (strlen(users[*length].name) < 1 || strlen(users[*length].name) > 19) {
            printf("Invalid Name. Try again.\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("*Enter Phone (max 10 chars): ");
        fgets(users[*length].phone, sizeof(users[*length].phone), stdin);
        users[*length].phone[strcspn(users[*length].phone, "\n")] = 0;

        if (strlen(users[*length].phone) < 1 || strlen(users[*length].phone) > 9) {
            printf("Invalid Phone. Try again.\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("*Enter Email (max 20 chars): ");
        fgets(users[*length].email, sizeof(users[*length].email), stdin);
        users[*length].email[strcspn(users[*length].email, "\n")] = 0;

        if (strlen(users[*length].email) < 1 || strlen(users[*length].email) > 19) {
            printf("Invalid Email. Try again.\n");
        } else {
            break;
        }
    }
    strcpy(users[*length].password, users[*length].phone);
    strcpy(users[*length].status, "Open");
    (*length)++;
    printf("\n **User Added Successfully.**\n");
}

void showUsersData(struct User users[],int length){
	int i;
	printf("\n\t\t\t**LIST OF USERS**\n");
	printf("|===========================================================================|\n");
    printf("|    ID    |       Name         |       Email        |   Phone   |  Status  |\n");
    printf("|==========|====================|====================|===========|==========|\n");
	for(i=0;i<length;i++){
		printf("|%-9s |%-19s |%-19s |%-9s  |%-9s |\n",users[i].userId,users[i].name,users[i].email,users[i].phone,users[i].status);
		printf("|----------|--------------------|--------------------|-----------|----------|\n");
	}
}
