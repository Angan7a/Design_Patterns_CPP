#include <iostream>
using namespace std;

class WelcomeToBank {
public:
    WelcomeToBank() {
        cout << "Welcome to Euro Bank" << endl;
    }
};

class AccountNumberCheck {
    int accountNumber;
public:
    AccountNumberCheck() : accountNumber(123456789) {}
    int getAccountNumber() {return accountNumber; }
    bool accountActive(int accNumToCheck) {
        if(accNumToCheck == getAccountNumber()) {
            return true;
        } else {
            cout << "Incorrect account number" << endl;
            return false;
        }
    }

};

class SecurityCodeCheck {
    int pin;
public:
    SecurityCodeCheck() : pin(1234) {}
    int getPin() {return pin; }
    bool isPinCorrect(int pinToCheck) {
        if(pinToCheck == getPin()) {
            return true;
        } else {
            cout << "Incorrect pin number" << endl;
            return false;
        }
    }
};

class FundsCheck {
    double cashInAccount;
public:
    FundsCheck() : cashInAccount(100.00) {}
    double getCashInAccount() {return cashInAccount; }
    void decreaseCashInAccount(double cashWithdrawn) {
        cashInAccount -= cashWithdrawn;
    }
    void increaseCashInAccount(double cashDeposited) {
        cashInAccount += cashDeposited;
    }
    bool haveEnoughMoney(double cashToWithdrawl) {
        if(cashToWithdrawl > getCashInAccount()) {
            cout << "Error: You don't have enough money" << endl;
            cout << "Current Balace: " << getCashInAccount() << endl;
            return false;
        } else {
            decreaseCashInAccount(cashToWithdrawl);
            cout << "Withdrawal Complite. Curent Balance: " << getCashInAccount() << endl;
            return true;
        }
    }
    void makeDeposit(double cashToDeposit) {
        increaseCashInAccount(cashToDeposit);
        cout << "Deposit Complite. Curent Balace: " << getCashInAccount() << endl;
    }
};

class BankAccountFacade {
    int accountNumber;
    int pin;
    WelcomeToBank *bankWelcome;
    AccountNumberCheck *acctChecker;
    SecurityCodeCheck *codeChecker;
    FundsCheck *fundChecker;
    int getSecurityCode() { return pin; }
public:
    BankAccountFacade(int accountNumber, int pin) : accountNumber(accountNumber), pin(pin) {
        bankWelcome = new WelcomeToBank();
        acctChecker = new AccountNumberCheck();
        codeChecker = new SecurityCodeCheck();
        fundChecker = new FundsCheck();
    }
    int getAccountNumber() { return accountNumber; }
    void withdrawCash(double cashToGet) {
        if (acctChecker->accountActive(getAccountNumber())&&
                 codeChecker->isPinCorrect(getSecurityCode()) &&
                 fundChecker->haveEnoughMoney(cashToGet)) {
            cout << "Transaction Complete" << endl;
        } else {
            cout << "Transaction Failed" << endl;
        }
    }
    void depositCash(double cashToDeposit) {
        if (acctChecker->accountActive(getAccountNumber())&&
                 codeChecker->isPinCorrect(getSecurityCode())) {
            fundChecker->makeDeposit(cashToDeposit);
            cout << "Transaction Complete" << endl;
        } else {
            cout << "Transaction Failed" << endl;
        }
    }
};


int main()
{
    BankAccountFacade *accessingBank = new BankAccountFacade(123456789, 1234);
    accessingBank->withdrawCash(50.00);
    cout << endl;
    accessingBank->withdrawCash(900.00);
    cout << endl;
    accessingBank->depositCash(200.00);
    cout << endl;

    delete accessingBank;
return 0;
}
