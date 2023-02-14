#include "headers/common.h"
#include "headers/signup.h"
#include "headers/login.h"


void mainmenu() {
    system("cls");
    int choice, pass, pin = 1234;
    do {
        cout << "\n\n\t\tWelcome to the Grain Market and Delivery System";
        cout << " \n\n\t\t>> I'm a." << endl;
        cout << "\n\n\t\t1. Buyer" << endl;
        cout << "\n\n\t\t2. Seller" << endl;
        cout << "\n\n\t\t3. Admin" << endl;
        cout << "\n\n\t\t0. Exit" << endl;
        cout << "\n\n\t\tPlease enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                menuchoice(choice);
                break;
            case 2:
                menuchoice(choice);
                break;
            case 3:
                cout << "\n\n\t\tEnter Pin Please: ";
                cin >> pass;

                if (pass == pin) {
                    adminMenu();
                } else
                    cout << "\n\n\t\tIncorrect pin" << endl;
                break;
            case 0:
                exit(0);
                break;
            default:
                cout << "\n\n\t\tInvalid choice" << endl;
                break;
        }
    } while (choice != 0);
}

void menuchoice(int user) {
    int option;

    do {
        system("cls");
        cout << "\n\n\t\tWelcome to the GM!" << endl;
        cout << "\n\n\t\t1. Login" << endl;
        cout << "\n\n\t\t2. Sign up" << endl;
        cout << "\n\n\t\t3. back" << endl;
        cout << "\n\n\t\t0. Exit" << endl;
        cout << "\n\n\t\tPlease enter your choice: ";
        cin >> option;
        if (option == 1) {

            login(user);
        }
        if (option == 2) {
            signup(user);
        }
        if (option == 3)
            mainmenu();
        if (option == 0) {
            exit(0);
        }
    } while (option != 0);
}

int main() {


    mainmenu();

    return 0;
}
