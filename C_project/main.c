#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include"datatype.h"
int main(int argc, char *argv[]) {
	int chooseMenu,chooseAdmin,chooseUser;
	int run=0;
	int length=0;
	User users[100];
	int listSize=sizeof(users)/sizeof(users[0]);
	char temp[20];
	while(run==0){
		showMenu();
		printf("\tEnter The Choice: ");
		scanf("%d", &chooseMenu);
		system("cls");
		switch(chooseMenu){
			case 1:
				while(chooseMenu==1){
					adminMenu();
					printf("\tEnter The Choice: ");
					scanf("%d", &chooseAdmin);				
					switch(chooseAdmin){
						case 1:
							inputUserData(users,&length);
							break;
						case 2:
							showUserData(users,length);
						case 3:
							searchUserName(users,length);
						case 4:
							searchUserId(users,length);	
						case 5:
						    lockAndUnlockId(users,length);
							break;	
						case 0:
							break;	
						default: 
							printf("\n\t***Invalid Choice!***\n");
					}
					if (chooseAdmin==0){
						break;
					}
				}
				break;
		
			case 0:
				printf("\n  ==========Exited Program!===========\n");
				printf("   ========Thanks for using!=========\n");
				return 1;	
			default:
				printf("Error!");		
		}
	}
	return 0;
}
