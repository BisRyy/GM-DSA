//
// Created by Administrator on 2/14/2023.
//

#ifndef GM_ADMIN_H
#define GM_ADMIN_H

#include "common.h"

string files[4] = {"buyerinfo.txt", "sellerinfo.txt", "productinfo.txt", "orderinfo.txt"};

void userlist() {
    fstream file;
    file.open("buyerinfo.txt", ios::in);
    string name, email, address, phone, username, password;
    cout << "\n\n\t\t>> Buyer List" << endl;
    cout << "\n\n\t\tName\t\temail\t\taddress\t\tphone\t\tusername\t\tpassword" << endl;
    while (file >> name >> email >> address >> phone >> username >> password) {
        cout << "\n\n\t\t" << name << "\t\t" << username << "\t\t" << password << "\t\t" << address << "\t\t" << phone
             << "\t\t" << email << endl;
    }
    file.close();
}

void sellerlist() {
    fstream file;
    file.open("sellerinfo.txt", ios::in);
    string name, password, address, phone, email;
    cout << "\n\n\t\t>> Seller List" << endl;
    cout << "\n\n\t\tName\t\temail\t\taddress\t\tphone\t\tpassword" << endl;
    while (file >> name >> email >> address >> phone >> password) {
        cout << "\n\n\t\t" << name << "\t\t" << email << "\t\t" << address << "\t\t" << phone << "\t\t" << password
             << endl;
    }
    file.close();
}

int counter(int t = 0) {
    int count = -1;
    string getcontent;
    ifstream openfile(files[t]);
    if (openfile.is_open()) {
        while (!openfile.eof()) {
            getline(openfile, getcontent);
            count++;
        }
        openfile.close();
    }
    return count;
}

void inventory(int t = 1) {
    clear();
    cout << "\n\n\t\t----------------- CURRENT INVENTORY AND USER STATUS -----------------\n";
    cout << "\n\t\t   Total Buyers: " << counter(0);
    cout << "\n\t\t  Total Sellers: " << counter(1);
    cout << "\n\t\t Total Products: " << counter(2);
    cout << "\n\t\t   Total Orders: " << counter(3);
    cout << endl;
    cont();
}

#endif //GM_ADMIN_H
