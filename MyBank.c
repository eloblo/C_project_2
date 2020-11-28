#include <stdio.h>
#include "MyBank.h"
//initalizing the library's functions
void build_acc(double accounts[2][50]){                                     //initializes the accounts array
	int row,col;
	accounts[0][0] = 0;                                                 //account 901 will start open with 0 balance
	accounts[1][0] = 1;
	for(row = 0, col = 1; col < 50; col++){                             //set the accounts balance as 0
		accounts[row][col] = 0;}
	for(row = 1, col = 1; col < 50; col++){                             //set the rest of the account as closed
		accounts[row][col] = 0;}
	}
void open(double accounts[2][50], int *size, int index, double money){      //opens a new account with the specific amount
	if(*size >= 50){                                                    //check if there is space left to open an account
		printf("not enough space, can't create more accounts.\n");  //print error message if there is no space
		return;}
	if(money < 0){                                                      //check if the deposit is a valid number
		printf("the amount must be positive\n");                    //print error message 
		return;}
	accounts[1][index] = 1;                                             //set the account as open
	accounts[0][index] = money;                                         //set the slected amount of money
	(*size)++;                                                          //increase the number of accounts
	printf("account %d succesfully opend\n", index+901);                //print which account was opened
	}
void balance(double accounts[2][50], int id){                               //prints the balance of the account
	if((id < 901) || (id > 950)){                                       //check if the account id is valid
		printf("Failed to read account number\n");                  //print error message
		return;}
	int real_id = id - 901;                                             //convert the id to an array index
	if(accounts[1][real_id] == 0){                                      //check if the account is open
		printf("the account is closed\n");                          //print error message
		return;}
	printf("the balance of account %d is %0.2lf\n", id, accounts[0][real_id]);  //print account balance
	}
void deposit(double accounts[2][50], int id, double money){                  //deposit money to the account
	if((id < 901) || (id > 950)){                                        //check if the account id is valid
		printf("sorry please enter a valid id\n");                   //print error message
		return;}
	if(money < 0){                                                       //check if the deposit is a valid number
		printf(" Invalid Amount."); //print error message
		return;}
	int real_id = id - 901;                                              //convert the id to an array index
	if(accounts[1][real_id] == 0){                                       //check if the account is open
		printf("account is closed please try again.\n");             //print error message
		return;}
	accounts[0][real_id] += money;                                       //adds the dposit to the account
	printf("%0.2lf\n", accounts[0][real_id]);
	}
void withdraw(double accounts[2][50], int id, double money){                //withdraw money from the account
	if((id < 901) || (id > 950)){                                       //check if the account id is valid
		printf("sorry please enter a valid id\n");                  //print error message
		return;}
	if(money < 0){                                                      //checks if the withdraw amount is valid
		printf(" sorry the amount must positive, please try again.\n");//print error message
		return;}
	int real_id = id - 901;                                             //convert the id to an array index
	if(accounts[1][real_id] == 0){                                      //checks if the account is open
		printf(" account is closed please try again.\n");            //print error message
		return;}
	if((accounts[0][real_id] - money) < 0){                             //checks if the withdraw is not over the account balance
		printf("cannot withdraw more than the balance.\n");         //print error message
		return;}
	accounts[0][real_id] -= money;                                      //deacrese the balance by the wanted amount
	printf("%0.2lf\n", accounts[0][real_id]);
	}
void close(double accounts[2][50], int id, int *size){                      //closes the specific account
	if((id < 901) || (id > 950)){                                       //check if the account id is valid
		printf("Failed to read account number\n");                  //print error message
		return;}
	int real_id = id - 901;                                             //convert the id to an array index
	accounts[1][real_id] = 0;                                           //set the account to closed
	(*size)--;                                                          //deacrese number of open accounts
	printf("closed account number %d \n", id);                          //print that the account was closed
	}
void intrest(double accounts[2][50], int rate){                             //increases the balance by the wanted intrest rate 
	if(rate < 0){                                                       //check if the inrest rate is valid
		printf("the intrsest rate must be positive.\n");            //print error message
		return;}
	float perc = rate;                                                  //convert the rate to a float
	perc /= 100;                                                        //calculate the rate to percentage
	perc++;                                                             //set the percentage to how many times the balance will increase
	int i;                                                              
	for(i = 0; i < 50; i++){                                            //for every account
		if(accounts[1][i] != 0){                                    //if the account is open
			accounts[0][i] *= perc;}                            //multiply the amount by the intrest rate
		}
	printf("%d\n", rate);
	}
void print(double accounts[2][50]){                                        //print all the open accounts and their balance
	int i;
	for(i = 0; i < 50; i++){                                                       //for every account
		if(accounts[1][i] != 0){                                               //if the accpunt is open
			printf("current balance: %d %0.2lf\n", i+901, accounts[0][i]);}//print it's balance
		}
	}	
