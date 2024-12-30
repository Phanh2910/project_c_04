#include<stdbool.h>
/*struct Date{
	int day;
	int month;
	int year;
};*/
struct Users{
	char userId[15];
	char userName[25];
	char phoneNumber[15];
	char email[25];
	char password[15];
	char status[15];
};
struct Users users[100];
//struct transation;
struct Transaction;
