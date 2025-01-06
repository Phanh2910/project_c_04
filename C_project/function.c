#include"function.h"
#include <stdio.h>
#include<string.h>
#include <stdbool.h>

//#define maxUsers 100
//#define maxIdLenght 20

void showMenu(){
    	printf("  ***Bank Management System***\n\n");
    	printf("\t  LUA CHON VAI TRO\n");
    	printf("\t========================\n");
    	printf("\t[1] Admin.\n");
    	printf("\t[2] Users.\n");
	    printf("\t[0] Exit.\n");
	    printf("\t========================\n");
        }
void adminMenu(){
    	printf("\n  ***Bank Management System Using C***\n\n");
    	printf("\t   ADMIN MENU\n");
    	printf("\t========================\n");
    	printf("\t[1] Them nguoi dung moi.\n");
    	printf("\t[2] Hien tat ca nguoi su dung.\n");
    	printf("\t[3] Tim kiem nguoi dung bang ten.\n");
    	printf("\t[4] Kiem tra nguoi dung bang ID.\n");
    	printf("\t[5] Mo/Vo hieu hoa nguoi dung bang ID.\n");
    	printf("\t[6] About us???\n");	
    	printf("\t[0] Tro ve trang chu.\n");
    	printf("\t========================\n");
        }
void inputUserData(User users[], int *length){
    char temp[25];
    int subCheck;
	int i;
    while (1) {
        printf("*Nhap ID nguoi dung: ");
        fgets(users[*length].userId, sizeof(users[*length].userId), stdin);
        users[*length].userId[strcspn(users[*length].userId, "\n")] = 0;

        if (strlen(users[*length].userId) < 1 || strlen(users[*length].userId) > 9) {
            printf("ID khong hop le, hay thu lai.\n");
        } else {
            subCheck = 1;
            for (i = 0; i < *length; i++) {
                if (strcmp(users[*length].userId, users[i].userId) == 0) {
                    subCheck = 0;
                    printf("ID da ton tai, hay thu lai.\n");
                    break;
                }
            }
            if (subCheck) break;
        }
    }
    while (1) {
        printf("*Nhap ten nguoi dung (Toi da 20 ky tu): ");
        fgets(users[*length].userName, sizeof(users[*length].userName), stdin);
        users[*length].userName[strcspn(users[*length].userName, "\n")] = 0;

        if (strlen(users[*length].userName) < 1 || strlen(users[*length].userName) > 19) {
            printf("Ten khong hop le, hay thu lai.\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("*Nhap sdt (Toi da 10 ky tu): ");
        fgets(users[*length].phoneNumber, sizeof(users[*length].phoneNumber), stdin);
        users[*length].phoneNumber[strcspn(users[*length].phoneNumber, "\n")] = 0;

        if (strlen(users[*length].phoneNumber) < 1 || strlen(users[*length].phoneNumber) > 9) {
            printf("Sdt khong hop le, hay thu lai.\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("*Nhap email(Toi da 20 ky tu): ");
        fgets(users[*length].email, sizeof(users[*length].email), stdin);
        users[*length].email[strcspn(users[*length].email, "\n")] = 0;

        if (strlen(users[*length].email) < 1 || strlen(users[*length].email) > 19) {
            printf("Email khong hop le, hay thu lai.\n");
        } else {
            break;
        }
    }
    strcpy(users[*length].password, users[*length].phoneNumber);
    strcpy(users[*length].status, "Open");
    (*length)++;
    printf("\n **Da them nguoi dung thanh cong.**\n");
}

void showUserData(User users[],int length){
	int i;
	printf("\n\t\t\t**LIST OF USERS**\n");
	printf("|===========================================================================|\n");
    printf("|    ID    |       Ten         |       Email        |   Sdt   |  Trang Thai  |\n");
    printf("|==========|====================|====================|===========|==========|\n");
	for(i=0;i<length;i++){
		printf("|%-9s |%-19s |%-19s |%-9s  |%-9s |\n",users[i].userId,users[i].userName,users[i].email,users[i].phoneNumber,users[i].status);
		printf("|----------|--------------------|--------------------|-----------|----------|\n");
	}
}   
  
void searchUserName(User users[],int length){
	int i;
	int check=0;
	getchar();
	char temp[25];
	while(1){
		printf("*Nhap ten nguoi dung de tim kiem: ");
		fgets(temp,25,stdin);
   		temp[strcspn(temp,"\n")]='\0';	
   		fflush(stdin);
   		if(strlen(temp)>19||strlen(temp)==0){
   			printf("\n *Ten nguoi dung khong hop le, hay thu lai!*\n\n");
		}else{
			break;
		}
	}
	
	for(int i=0;i<length;i++){
		if(strstr(users[i].userName,temp)){
			for(i=0;i<length;i++){
		if (strstr(users[i].userName, temp) != NULL){
				printf("|===========================================================================|\n");
    			printf("|  ID      | Ten               | Email              | Sdt     | Trang Thai   |\n");
    			printf("|==========|====================|====================|===========|==========|\n");
			printf("|%-9s |%-19s |%-19s |%-9s  |%-9s |\n",users[i].userId,users[i].userName,users[i].email,users[i].phoneNumber,users[i].status);
			printf("|----------|--------------------|--------------------|-----------|----------|\n");
			check++;
		}	
	}
	if(check==0){
		printf("\n **Nguoi dung khong ton tai.**\n\n");
	}
		}
	}
        }
void searchUserId(User users[],int length){
	system("cls");
	int i;
	int check=0;
	char temp[15];
	getchar();
	while(1){
		printf("*Nhap ID cua nguoi dung de kiem tra (Duoi 10 ki tu): ");
		fgets(temp,15,stdin);
   		temp[strcspn(temp,"\n")]='\0';	
   		fflush(stdin);
   		if(strlen(temp)>9 || strlen(temp)==0){
   			printf("\n *ID khong hop le, hay thu lai!*\n\n");
   			continue;
		}else{
			break;
		}
	}
	for(i=0;i<length;i++){
		if(strcmp(temp,users[i].userId)==0){
				printf("\t\t\t**Tim thay nguoi dung!**\n");
				check++;
					printf("|===============================================================================================|\n");
    				printf("|    ID    |       Ten         |       Email        |   Sdt  |      Ten Nguoi Dung      |  Trang Thai |\n");
   					printf("|==========|====================|====================|===========|====================|=========|\n");
    			printf("|%-9s |%-19s |%-19s |%-9s  |%-19s |%-9s|\n",users[i].userId,users[i].userName,users[i].email,users[i].phoneNumber,users[i].userName,users[i].status);
				printf("|----------|--------------------|--------------------|-----------|--------------------|---------|\n");
				break;
		}
	}
	int idCheck=0;
	   if(check==0){
		printf("\n **ID Khong ton tai.**\n\n");
					int choice;
					while(1){
						printf("\n\tQuay lai(0)? hoac Thoat(1): ");
						scanf("%d", &choice);
						if(choice==0){
							idCheck++;
							break;
						}else if(choice==1){
							return;
						}else{
							printf("\n\t*Nhap vao khong hop le, hay thu lai!*\n\n");
							fflush(stdin);
							continue;
						}
					}
	}
	  if(idCheck==0){
					int choice;
					while(1){
						printf("\n\tQuay lai(0)? hoac Thoat(1): ");
						scanf("%d", &choice);
						if(choice==0){
							break;
						}else if(choice==1){
							return;
						}else{
							printf("\n\t*Nhap vao khong hop le, hay thu lai!*\n\n");
							fflush(stdin);
							continue;
						}
					}
	}				
}
void lockAndUnlockId(User users[],int length){
system("cls");
	printf("\n");
	int i;
	int check2=0;
	int check=0;
	char temp[15];
	int confirm=99;
	getchar();
	while(1){
		printf("*Nhap ID nguoi dung(duoi 10 ki tu): ");
		fgets(temp,15,stdin);
   		temp[strcspn(temp,"\n")]='\0';	
   		fflush(stdin);
   		if(strlen(temp)>9 || strlen(temp)==0){
   			printf("\n *Id khong hop le, hay thu lai*\n\n");
		}else{
			break;
		}
	}
		for(i=0;i<length;i++){
			if(strcmp(temp,users[i].userId)==0){
				printf("\t\t\t**Tim thay nguoi dung!**\n");
				check++;
				break;
			}
		}
		if(check==0){
			printf("\n\t***ID ko ton tai.***\n\n");
			printf(" \n      **Kiem tra danh sach nguoi dung [1]**\n");
			printf(" =======================================\n");
			int choice;
					while(0){
						printf("\n\tquay lai(0) hoac thoat(1): ");
						scanf("%d", &choice);
						if(choice==0){
							check2++;
							break;
						}else if(choice==1){
							printf("\n  ==========Exited Program!===========\n");
							printf("   ========Thanks For Using Our App!=========\n");
							exit (1);
						}else{
							printf("\n\t*Invalid Input.Try again!*\n\n");
							fflush(stdin);
							continue;
						}
					}
		}else if(strcmp(users[i].status, "Mo")==0){
			while(1){
				if (check2!=0){
					break;
				}
				printf("*This User's Account Is Currently Open, Do You Wish To Lock?(Press [1] To Confirm, [0] To Cancel): ");
				scanf("%d", &confirm);	
				if(confirm==1){
					strcpy(users[i].status, "Locked");
					printf(" **Successfully Locked.**\n");
						int choice;
					while(1){
						printf("\n\tGo back(1)? or Exit(2): ");
						scanf("%d", &choice);
						if(choice==0){
							check2++;
							break;
						}else if(choice==1){
							printf("\n  ==========Exited Program!===========\n");
							printf("   ========Thanks For Using Our App!=========\n");
							exit (1);
						}else{
							printf("\n\t*Invalid Input.Try again!*\n\n");
							fflush(stdin);
							continue;
						}
					}
				}else if(confirm==0){
					printf(" **Cancelled.**\n");
						int choice;
						while(1){
						printf("\n\tQuay lai(0)? hoac thoat(1): ");
						scanf("%d", &choice);
						if(choice==0){
							check2++;
							break;
						}else if(choice==1){
							printf("\n  ==========Chuong trinh da thoat==========\n");
							printf("   ========Cam on vi da dung dung dung cua chung toi=========\n");
							exit (1);
						}else{
							printf("\n\t*Nhap vao khong hop le, hay thu lai*\n\n");
							fflush(stdin);
							continue;
						}
					}
				}else{
					printf("**Lua chon khong hop le**\n");
					fflush(stdin);
				}
			}
		}else{
			while(1){
					if (check2!=0){
					break;
				}
				printf("*Nguoi dung dang khoa,ban co muon mo khong(Press [1] To Confirm, [0] To Cancel): ");
				scanf("%d", &confirm);	
			if(confirm==1){
					strcpy(users[i].status, "Mo khoa");
					printf(" **Successfully Opened.**\n");
					int choice;
					while(1){
						printf("\n\tQuay lai(0) hoac thoat(1): ");
						scanf("%d", &choice);
						if(choice==0){
							check2++;
							break;
						}else if(choice==1){
							printf("\n  ==========Chuong trinh da thoat===========\n");
							printf("   ========Cam on vi da dung dung dung cua chung toi=========\n");
							exit (1);
						}else{
							printf("\n\t*Invalid Input.Try again!*\n\n");
							fflush(stdin);
							continue;
						}
					}
			}else if(confirm==0){
					printf("**Huy bo**\n");
						int choice;
					while(1){
						printf("\n\tQuay lai(0) hoac thoat(1): ");
						scanf("%d", &choice);
						if(choice==0){
							check2++;
							break;
						}else if(choice==1){
							printf("\n  ==========Chuong trinh da thoat===========\n");
							printf("   ========Cam on vi da dung dung dung cua chung toi=========\n");
							exit (1);
						}else{
							printf("\n\t*Nhap vao khong hop le, hay thu lai*\n\n");
							fflush(stdin);
							continue;
						}
					}
			}else{
					printf(" **Lua chon khong phu hop**\n");
					fflush(stdin);
				}
			}
		}
}


