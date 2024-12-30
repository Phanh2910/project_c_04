#include<stdbool.h>
struct Date{
	int day,month,year;
};
struct User{
	char userId[15];
	char userName[25];
	char phoneNumber[15];
	char email[25];
	char password[15];
	char status[15];
};
struct User users[100];
//struct transation;
