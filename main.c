#include <stdio.h>
#include "MyBank.h"
//the main program to run the accounts
int main(){
	double accounts[2][50];   //the array that will hold the accounts. first row holds the balance, second row hold if the account is open
	int index = 1;            //index of the next account to be opend
	int size = 1;             //number of open accounts     
	char com;                 //char to hold the commands
	int id;                   //the id of the iputed account
	double money;             //the amount of the inputed deposit or withdraw
	_Bool dup = 1;            //a bool value to debug the while as the loop runs multyple time before reading the command line
	build_acc(accounts);      //intializing the account array
	printf("\nplease choose a transaction type:\n");  //opening message with instructions
	printf(" O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
	while(scanf("%c", &com)){                                           //the loop which hold the command line 
		switch(com){                                                //a switch to read the command line
			case 'O':                                            //case for the O(open) command
				scanf("%lf", &money);                        //input starting deposit amount
				if(size != 50){                              //check if there is space to open an account
					while(accounts[1][index] != 0){      //a loop that runs until it finds next index of a closed account
						index++;                     //sets the index to that of the closed account
						if(index == 50){             //if the index is out of bound
							index = 0;}          //set it to 0
						}
					}
				open(accounts, &size, index, money);        //open the account
				break;
			case 'B':                                           //case for B(balance) command
				scanf("%d", &id);                           //input the id of the account
				balance(accounts, id);                      //print the current balance
				break;
			case 'D':                                           //case for D(deposit) command 
				scanf("%d", &id);                           //input the id of the account
				scanf("%lf", &money);                       //input the amount for the deposit
				deposit(accounts, id, money);               //add the amount
				break;
			case 'W':                                           //case for W(withdraw) command
				scanf("%d", &id);                           //input the id of the account
				scanf("%lf", &money);                       //input the amount for the withdraw
				withdraw(accounts, id, money);              //subtract the amount
				break;
			case 'C':                                           //case for C(close) command
				scanf("%d", &id);                           //input the id of the account
				close(accounts, id, &size);                 //close the account
				break;
			case 'I':                                           //case for I(intrest) command
				scanf("%d", &id);                           //input the id of the account
				intrest(accounts, id);                      //increase the balance by the intrest
				break;
			case 'P':                                           //case for P(print) command
				print(accounts);                            //prints the accounts
				break;
			case 'E':                                           //case for E(exit) command
				printf("GoodBye\n");                        //print closing message
				return 0;                                   //exist the function
			}
			id = 0;                                             //reset the id 
			money = 0;                                          //reset the omney amount
			if(dup == 1){                                       //if not a duplicate run print the opening message
				printf("\nplease choose a transaction type:\n");
				printf(" O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");}
			dup = !dup;  //tag the duplicate flag
		}
	return 0;
	}
