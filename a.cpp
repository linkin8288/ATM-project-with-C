/* ATM - project
-> Check Balance
-> Cash withdraw
-> User Details
-> Update Mobile Number
*/

////////////////////////////////////////////

/* 

1. Setting private and public variables to protect information.
2. Setting each functions for taking user's inputs and outputs.
3. Setting main function to varify user and handle user's choice on the interface.
4. Setting switch condition to handle user's choice and input, calling 
the function I set before.

*/

#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

class atm {

    // private
    private:
        long int account_No;
        string name;
        int PIN;
        double balance;
        string mobile_No;

    // public
    public:
        // setData function is setting the Data into the private member variables
        void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a) {
            // Assigning the formal arguments to the private member
            account_No = account_No_a;
            name = name_a;
            PIN = PIN_a;
            balance = balance_a;
            mobile_No = mobile_No_a;
        }

        // getAccountNo function is returning the user's account no.
        long int getAccountNo()
        {
            return account_No;
        }

        // getName function is returing user's name
        string getName()
        {
            return name;
        }

        // getPIN function in returning the user's PIN
        int getPIN()
        {
            return PIN;
        }

        // getBalance function is returning the user's balance
        double getBalance()
        {
            return balance;
        } 

        // getMobileNo is returning the user's mobile No
        string getMobileNo()
        {
            return mobile_No;
        }

        // setMobile function is Updating the user's new mobile No
        void setMobile(string mob_prev, string mob_new)                 
        {
            // it will check old Mobile No
            if (mob_prev == mobile_No)
            {   // and Update with new phone
                mobile_No = mob_new;
                cout << endl << "Successfully Updated the Mobile no.";
                // getch is to hold the screen until user press any key
                _getch();
            }
        }

        // cashWithDraw function is used to withdraw money from ATM
        void cashWithDraw(int amount_a)
        {
            // check entered amount validity
            if (amount_a > 0 && amount_a < balance)
            {
                balance = balance - amount_a;
                cout << endl << "Please Collect Your Cash";
                cout << endl << "Availabe Balance: " << balance;
                _getch();
            }

            else
            {
                cout << endl << "Invalid Input or Insufficient Balnce";
                _getch();
            }
        }

};

//////////////////////////////////////////////////////////////////////////

int main()
{   
    // enterPIN and enterAccountNo are used to user authentication
    int choice = 0, enterPIN;
    long int enterAccountNo;

    // system function is used to clean the screen
    system("cls");

    // created User (object)
    atm user1;
    // Set User Details (into object) (Setting Default Data)
    user1.setData(123456, "Jakob", 1111, 9999999.99, "654321");

    do
    {
        /* code */

        // system function is used to clean the screen
        system("cls");

        // Take user's account No and PIN
        cout << endl << "**** Welcome to ATM ****" << endl;
        cout << endl << "Enter Your Account Nuber: ";
        cin >> enterAccountNo;

        // Check whether enter values matches with user details
        if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                /* code */
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");

                // user Interface
                cout << endl << "**** Welcome to ATM *****" << endl;
				cout << endl << "Select Options ";
				cout << endl << "1. Check Balance";
				cout << endl << "2. Cash withdraw";
				cout << endl << "3. Show User Details";
				cout << endl << "4. Update Mobile no.";
				cout << endl << "5. Exit" << endl;

                // taking user choice
				cin >> choice;
                // switch condition
                switch (choice)
                {   
                    // If user presses 1
                    // getBalance is ... pring the user's bank balance
                    case 1:
                        cout << endl << "Your Bank balance is: " << user1.getBalance();
                        _getch();
                        break;

                    // If user presses 2
                    case 2:
                        cout << endl << "Enter the amount: ";
                        // Store the amount of money to the input to amount variable
                        cin >> amount;
                        // Passing amount variable to the caseWithDraw function
                        user1.cashWithDraw(amount);

                        break;

                    // If user presses 3
                    case 3:
                        cout << endl << "*** User Details are :- ";
                        cout << endl << "-> Account no" << user1.getAccountNo();
                        cout << endl << "-> Name      " << user1.getName();
                        cout << endl << "-> Balance   " << user1.getBalance();
                        cout << endl << "-> Mobile No." << user1.getMobileNo();
                         // getting and printing user details
                        _getch();
                        break;

                    // If user presses 4
                    case 4:								   
                        cout << endl << "Enter Old Mobile No. ";
                        // take old mobile no
                        cin >> oldMobileNo;

                        cout << endl << "Enter New Mobile No. ";
                        // take new mobile no
                        cin >> newMobileNo;
                        // now set new mobile no
                        user1.setMobile(oldMobileNo, newMobileNo);
                        break;

					// if user presses 5
				    case 5:
                        // exit application
					    exit(0);

                    // handle invalid user inputs
				    default:
					    cout << endl << "Enter Valid Data !!!";
                }

            } while (/* condition */ 1);
            
		}

		else
		{
			cout << endl << "User Details are Invalid !!! ";
			_getch();
        }

    } while (/* condition */  1);

    return 0;
}
