#ifndef _MYBANK_H_
#define _MYBANK_H_
//declaration of the library
void build_acc(double accounts[2][50]);                                   //initializes the accounts array
void open(double accounts[2][50], int *size, int index, double money);    //opens a new account with the specific amount
void balance(double accounts[2][50], int id);                             //prints the balance of the account
void deposit(double accounts[2][50], int id, double money);               //deposit money to the account
void withdraw(double accounts[2][50],int id, double mouney);  	     //withdraw money from the account
void close(double accounts[2][50], int id, int *size);        	     //closes the specific account
void intrest(double accounts[2][50], int rate);               	     //increases the balance by the wanted intrest rate 
void print(double accounts[2][50]);                           	     //print all the open accounts and their balance

#endif
