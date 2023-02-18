/* D.S. Malik - C++ Programming, capitolo 11, esercizio 13

a. Define the class bankAccount to store a bank customer’s account
number and balance. Suppose that account number is of type int,
and balance is of type double. Your class should, at least, provide the
following operations: set the account number, retrieve the account
number, retrieve the balance, deposit and withdraw money, and print
account information. Add appropriate constructors.

b. Every bank offers a checking account. Derive the class
checkingAccount from the class bankAccount (designed in part a).
This class inherits members to store the account number and the
balance from the base class. A customer with a checking account
typically receives interest, maintains a minimum balance, and pays
service charges if the balance falls below the minimum balance. Add
member variables to store this additional information. In addition to
the operations inherited from the base class, this class should pro-
vide the following operations: set interest rate, retrieve interest rate,
set minimum balance, retrieve minimum balance, set service charges,
retrieve service charges, post interest, verify if the balance is less than
the minimum balance, write a check, withdraw (override the method
of the base class), and print account information. Add appropriate
constructors. */

#include <iostream>
using namespace std;


// DEFINIZIONE CLASSI
class bankAccount{
public:
	int getNumber();
	double getBalance();
	void setNumber(int num);
	void deposit(double q);
	void withdraw(double q);
	virtual void getInfo();
	bankAccount(int num, double bal);
	bankAccount();

private:
	int accNumber;
	double accBalance;
};

class checkAccount:public bankAccount{
public:
	void setInterestRate(double rate);
	void setMinBalance(double bal);
	void setServiceRate(double rate);
	double getInterestRate();
	double getMinBalance();
	double getServiceRate();
    void postInterest();
    void withdraw(double q);
	bool isDebit();
	void getInfo();
    checkAccount(int num, double bal, double mb, double ir, double sr);
    checkAccount();

private:
	double interestRate;
	double minBalance;
	double serviceRate;
};


// IMPLEMENTAZIONE CLASSI
// bankAccount
int bankAccount::getNumber(){
	return accNumber;
}

double bankAccount::getBalance(){
	return accBalance;
}

void bankAccount::setNumber(int num){
	accNumber=num;
}

void bankAccount::deposit(double q){
	accBalance+=q;
}

void bankAccount::withdraw(double q){
	if(accBalance>0 && accBalance>=q)
		accBalance-=q;
	else
		cout<<"non puoi ritirare"<<endl;
}

void bankAccount::getInfo(){
	cout<<"number: "<<accNumber<<"  balance: "<<accBalance;
}

bankAccount::bankAccount(int num, double bal){
	accNumber=num;
	accBalance=bal;
}

bankAccount::bankAccount(){
	accNumber=0;
	accBalance=0.0;
}

//checkAccount
double checkAccount::getInterestRate(){
	return interestRate;
}

double checkAccount::getMinBalance(){
	return minBalance;
}

double checkAccount::getServiceRate(){
	return serviceRate;
}

void checkAccount::setInterestRate(double rate){
	interestRate=rate;
}

void checkAccount::setMinBalance(double bal){
	minBalance=bal;
}

void checkAccount::setServiceRate(double rate){
	serviceRate=rate;
}

void checkAccount::postInterest(){
    bankAccount::deposit(bankAccount::getBalance()*interestRate);
}

void checkAccount::withdraw(double q){
    if(isDebit()==false)
        bankAccount::withdraw(q);
    else
        cout<<"debito"<<endl;
}

bool checkAccount::isDebit(){
	if(getBalance()<minBalance)
		return true;
	else
		return false;
}

void checkAccount::getInfo(){
	bankAccount::getInfo();
	cout<<"  min balance: "<<minBalance<<"  interest: "<<interestRate<<"  service: "<<serviceRate;
}

checkAccount::checkAccount(int num, double bal, double mb, double ir, double sr):bankAccount(num, bal){
    interestRate=ir;
    minBalance=mb;
    serviceRate=sr;
}

checkAccount::checkAccount(){
    interestRate=0.0;
    minBalance=0.0;
    serviceRate=0.0;
}


// MAIN PROGRAM
int main(){
    bankAccount acc1=bankAccount(1, 100.0); acc1.getInfo(); cout<<endl;
    acc1.withdraw(120); acc1.getInfo(); cout<<endl;
    acc1.withdraw(80); acc1.getInfo(); cout<<endl;
    acc1.withdraw(50); acc1.getInfo(); cout<<endl;

    checkAccount acc2=checkAccount(2, 1000.0, 100.00, 0.01, 0.05); acc2.getInfo(); cout<<endl;
    acc2.postInterest(); acc2.getInfo(); cout<<endl;
    acc2.withdraw(950); acc2.getInfo(); cout<<endl;
    acc2.withdraw(100); acc2.getInfo(); cout<<endl;

	bankAccount* a1=new bankAccount(3, 500.50);
	a1->getInfo(); cout<<endl;

	checkAccount* a2=new checkAccount(4, 10000.00, 100, 0.01, 0.05);
	a2->getInfo(); cout<<endl;
	a2->withdraw(500); a2->getInfo(); cout<<endl;
	a2->postInterest(); a2->getInfo(); cout<<endl;

	bankAccount* a3=new checkAccount(5, 2500.00, 100, 0.01, 0.05);
	a3->getInfo();
}
