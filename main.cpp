#include <iomanip>
#include <cstdlib>
#include <cmath>
// This program takes a character choice provided by the user, and then 
// asks the user for a series of predetermined unit values, depending on 
// the choice.
// 
// Programmer:    Andrew Coviello
// Module 8
// Project 3
// Problem Statement: Write a program that calculates the balance of a 
// savings account at the end of a three-month period.  It should ask the 
// user for the starting balance and the annual interest rate.  A loop 
// should then iterate once for every month in the period, performing the // following steps:
// 
// 1. Ask the user for the total amount deposited into the account during 
// that month and add it to the balance.  Do not accept negative numbers.
// Ask the user for the total amount withdrawn from the account during 
// the month and subtract it from the balance.  Do not accept negative 
// numbers or numbers greater than the balance after the deposits for the 
// month have been added.
// Calculate the interest for that month. The monthly interest rate is 
// the annual interest rate divided by 12. Multiply the monthly interest 
// rate by the average of that month's starting and ending balance to get 
// the interest amount for that month.  This amount should be added to 
// the balance.
//
#include <iostream>
using namespace std;

int main() {

  // double values
  double annualInterestRate, balance, deposits, endingBalance, finalBalance, interestPosted, monthlyInterestRate, startingBalance, totalDeposits, totalInterestPosted, totalWithdrawals, withdrawals;
  // monthly interest rate = annual interest rate / 12
  // monthly interest amount = (starting balance + ending balance) / 2
  // balance = balance + monthly interest amount

  // beginning display prompts user 
  cout << setw(30) << setprecision(2) << fixed << showpoint << "****** Savings Account ******\n" << endl;
  cout << setw(30) << "Please enter the beginning balance: " << endl;
  cin >> startingBalance;
  cout << setw(30) << "Please enter the annual interest rate: " << endl;
  cin >> annualInterestRate;
  
  balance = startingBalance;
  monthlyInterestRate = (double) (0.01 *annualInterestRate) / 12.0;
  // monthlyInterestAmount = (startingBalance + endingBalance) / 2;
  // PROBLEM: i don't know how to register total interest posted or final
  // balance
  for(int i = 1; i < 4; i++)
  {
    cout << "\nEnter the deposits for month " << i << ": " << endl;
    cin >> deposits;
    totalDeposits = totalDeposits + deposits;
    balance = balance + deposits;
    cout << "Enter the withdrawals for month " << i << ": " << endl;
    cin >> withdrawals;
    if(withdrawals > balance)
    {
      cout << "Sorry, can't let you overdraw. Try again." << endl;
    }
    else if(withdrawals < 0)
    {
      cout << "Not a valid entry. Try again." << endl;
    }
    else
    {
      totalWithdrawals = totalWithdrawals + withdrawals;
      balance = balance - withdrawals;
    }
    endingBalance = balance;
    interestPosted = ((startingBalance + endingBalance) / 2) * (monthlyInterestRate);
    totalInterestPosted = totalInterestPosted + interestPosted;
    if(i == 3)
    {
      finalBalance = endingBalance + totalInterestPosted;
    }
  }
  // the easiest way to do that is to right justify the values
  // be careful: you want to right justify parts of the message,
  // not the whole thing

  cout << setw(30) << "****** MONTHLY ACTIVITY ******\n" << endl;
  cout << setw(30) << " Starting Balance: $"  << setw(10) << right << startingBalance << endl;
  cout << setw(30) << " Total Deposits Made: $" << setw(10) << right << totalDeposits << endl;
  cout << setw(30) << " Total Withdrawals Made: $" << setw(10) << right << totalWithdrawals << endl;
  cout << setw(30) << " Total Interest Posted: $" << setw(10) << right << totalInterestPosted << endl;
  cout << setw(30) << " Final Balance: $" << setw(10) << right << finalBalance << endl;
}
