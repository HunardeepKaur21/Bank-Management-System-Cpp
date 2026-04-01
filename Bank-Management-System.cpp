#include <iostream>
#include <fstream>
using namespace std;

class Account
{
    string name;
    string phone;
    int acc_no;
    float balance;
    static int newacc_no;

public:

    // CREATE ACCOUNT
    void Create_account()
    {
        ofstream file("accounts.txt", ios::app);

        acc_no = newacc_no++;   // assign account number

        cout << "Enter Name = ";
        cin >> name;

        cout << "Enter phone = ";
        cin >> phone;

        cout << "Enter initial balance = ";
        cin >> balance;

        file << acc_no << " " << name << " " << phone << " " << balance << endl;

        file.close();

        cout << "Account successfully created !!!" << endl;
        cout << "Your account number is = " << acc_no << endl;
    }

    // DISPLAY ACCOUNT
    void Display_account()
    {
        ifstream file("accounts.txt");

        int acc;
        string n, p;
        float bal;

        cout << "\nAll Accounts:\n";

        while(file >> acc >> n >> p >> bal)
        {
            cout << acc << " " << n << " " << p << " " << bal << endl;
        }

        file.close();
    }


    void deposit()
{
    ifstream file("accounts.txt");
    ofstream temp("temp.txt");

    int acc, target;
    string n, p;
    float bal, amount;

    cout << "Enter account number: ";
    cin >> target;

    cout << "Enter amount to deposit: ";
    cin >> amount;

    while(file >> acc >> n >> p >> bal)
    {
        if(acc == target)
        {
            bal += amount;
            cout << "Deposit successful!\n";
        }

        temp << acc << " " << n << " " << p << " " << bal << endl;
    }

    file.close();
    temp.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
   
}
void withdraw()
{
    ifstream file("accounts.txt");
    ofstream temp("temp.txt");

    int acc, target;
    string n, p;
    float bal, amount;

    cout << "Enter account number: ";
    cin >> target;

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    while(file >> acc >> n >> p >> bal)
    {
        if(acc == target)
        {
            if(amount > bal)
            {
                cout << "Insufficient balance!\n";
            }
            else
            {
                bal -= amount;
                cout << "Withdrawal successful!\n";
            }
        }

        temp << acc << " " << n << " " << p << " " << bal << endl;
    }

    file.close();
    temp.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}


void searchAccount()
{
    ifstream file("accounts.txt");

    int acc, target;
    string n, p;
    float bal;
    int found = 0;

    cout << "Enter account number to search: ";
    cin >> target;

    while(file >> acc >> n >> p >> bal)
    {
        if(acc == target)
        {
            cout << "\nAccount Found:\n";
            cout << "Account No: " << acc << endl;
            cout << "Name: " << n << endl;
            cout << "Phone: " << p << endl;
            cout << "Balance: " << bal << endl;

            found = 1;
        }
    }

    file.close();

    if(found == 0)
    {
        cout << "Account not found!\n";
    }
}

void takeLoan()
{
    ifstream file("accounts.txt");
    ofstream temp("temp.txt");

    int acc, target;
    string n, p;
    float bal, loanAmount;
    int found = 0;

    cout << "Enter account number: ";
    cin >> target;

    cout << "Enter loan amount: ";
    cin >> loanAmount;

    // validation
    if(loanAmount <= 0)
    {
        cout << "Invalid loan amount!\n";
        return;
    }

    while(file >> acc >> n >> p >> bal)
    {
        if(acc == target)
        {
            bal += loanAmount;
            found = 1;
            cout << "Loan granted successfully!\n";
        }

        temp << acc << " " << n << " " << p << " " << bal << endl;
    }

    file.close();
    temp.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if(found == 0)
    {
        cout << "Account not found!\n";
    }
}


};



// static variable initialization
int Account::newacc_no = 1000;

  int main()
{
    Account obj;
    int choice;

    do {
        cout << "\n====== BANK MANAGEMENT SYSTEM ======\n";
        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Take Loan\n";
        cout << "6. Search Account\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                obj.Create_account();
                break;

            case 2:
                obj.Display_account();
                break;

            case 3:
                obj.deposit();
                break;

            case 4:
                obj.withdraw();
                break;

            case 5:
                obj.takeLoan();
                break;

            case 6:
                obj.searchAccount();
                break;

            case 7:
                cout << "Exiting... Thank you!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 7);

    return 0;
}