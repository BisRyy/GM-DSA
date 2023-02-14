//
// Created by Administrator on 2/14/2023.
//

#ifndef GM_ADMIN_H
#define GM_ADMIN_H

#include "common.h"


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

#endif //GM_ADMIN_H
