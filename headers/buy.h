//
// Created by Administrator on 2/14/2023.
//

#ifndef GM_BUY_H
#define GM_BUY_H

#include "common.h"

void displayProducts();

void insertNode(Product *n) {

    if (head == nullptr) {
        head = n;
    } else {
        Product *ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

void addproducttolinkedlist() {
    head = nullptr;
    string pn;
    float pp;
    float mp;
    int am;
    string mn;
    fstream file;
    file.open("products.txt", ios::in);
    while (file >> pn >> pp >> mp >> am >> mn) {
        Product *p = new Product();
        p->ProductName = pn;
        p->ProductPrice = pp;
        p->MillingPrice = mp;
        p->amount = am;
        p->millinghousename = mn;
        insertNode(p);
    }
    file.close();
}

void productlist() {
    addproducttolinkedlist();
    int option;
    do {
        clear();
        if (head == nullptr) {
            cout << "\n\n\t\tWe have no products yet." << endl;
            cont();
            return;
        }

        displayProducts();

        cout << "\n\n\t\t1. View product by name order" << endl;
        cout << "\t\t2. view products by price order" << endl;
        cout << "\t\t3. Order product" << endl;
        cout << "\t\t4. Go back" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> option;
        if (option == 1)
            sortbyname();
        else if (option == 2)
            sortbyprice();
        else if (option == 3)
            numberofitemstobuy();
        else if (option == 4)
            buyermenu();
        else {
            cout << "\t\tChoose from these options only." << endl;
        }
    } while (option != 4);

}

void displayProducts() {
    Product *temp = head;
    cout << "\n\n\t\t              Products              " << endl;
    cout << setw(20) << left << "\n\n\t\tproductName" << setw(20) << left << "productPrice" << setw(20) << left
         << "MillingPrice" << setw(10) << left << "Amount" << setw(20) << left << "MillingHouse" << endl;
    while (temp != nullptr) {
        cout << "\t\t" << setw(20) << left << temp->ProductName << setw(20) << left << temp->ProductPrice
             << setw(20) << left << temp->MillingPrice << setw(10) << left << temp->amount << setw(20) << left
             << temp->millinghousename << endl;
        temp = temp->next;
    }
}

void sortbyname() {
    int pp;
    int mp;
    string pn;
    Product *temp = head;
    Product *ptr = head;

    while (temp != NULL) {
        while (ptr->next != NULL) {
            if ((ptr->ProductName)[0] > (ptr->next->ProductName)[0]) {
                pn = ptr->ProductName;
                ptr->ProductName = ptr->next->ProductName;
                ptr->next->ProductName = pn;
                pp = ptr->ProductPrice;
                ptr->ProductPrice = ptr->next->ProductPrice;
                ptr->next->ProductPrice = pp;
                mp = ptr->MillingPrice;
                ptr->MillingPrice = ptr->next->MillingPrice;
                ptr->next->MillingPrice = mp;
            }
            ptr = ptr->next;
        }
        ptr = head;
        temp = temp->next;
    }
}

void sortbyprice() {
    int pp;
    int mp;
    string pn;
    Product *temp = head;
    Product *ptr = head;

    while (temp != NULL) {
        while (ptr->next != NULL) {
            if (ptr->ProductPrice > ptr->next->ProductPrice) {
                pp = ptr->ProductPrice;
                ptr->ProductPrice = ptr->next->ProductPrice;
                ptr->next->ProductPrice = pp;
                pn = ptr->ProductName;
                ptr->ProductName = ptr->next->ProductName;
                ptr->next->ProductName = pn;
                mp = ptr->MillingPrice;
                ptr->MillingPrice = ptr->next->MillingPrice;
                ptr->next->MillingPrice = mp;
            }
            ptr = ptr->next;
        }
        ptr = head;
        temp = temp->next;
    }
}


void numberofitemstobuy() {
    int n;
    cout << "\n\n\t\tHow many items do you want to buy: ";
    cin >> n;
    if (n >= 3 and n < 10) {
        cout << "\n\n\t\tWe Have an offer for you!" << endl;
        cout << "\n\n\t\tIf you buy more than 3 items you will get 10% discount" << endl;
        cout << "\n\n\t\tDo you want to buy more than 3 items? (y/n): ";
        char ch;
        cin >> ch;
        if (ch == 'y') {

            cout << "How many Items do you want to buy: ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                makeorder();
                discountprice();
            }
        } else {
            for (int i = 0; i < n; i++) {
                makeorder();
            }
        }
    } else if (n >= 10) {
        cout << "You have reached maximum limit of your buying capacity in a day" << endl;
        return;
    } else {
        for (int i = 0; i < n; i++) {
            makeorder();
        }
    }
}


void makeorder() {
    string p, mn;
    string pn, mhn;
    float pp, mp;
    int a, am;

    cout << "\n\n\t\tEnter the name of the product You wanna order: ";
    cin.ignore();
    getline(cin, p);
    p = replace(p, ' ', '_');
    p = changetolower(p);

    cout << "\n\n\t\tEnter millinhouse name: ";
    //   cin.ignore();
    getline(cin, mn);
    mn = replace(mn, ' ', '_');
    mn = changetolower(mn);

    if (checkp(p, mn)) {
        cout << "\n\n\t\tEnter the amount you want: ";
        cin >> a;
        if (checka(p, mn, a)) {
            ifstream file("products.txt");
            ofstream file1("temp.txt", ios::app);
            ofstream file2("order.txt", ios::app);
            while (file >> pn >> pp >> mp >> am >> mhn) {
                if (pn == p && mhn == mn) {
                    am = am - a;
                    file2 << setw(20) << left << pn << setw(20) << left << pp << setw(10) << left << mp << setw(10)
                          << left << a << setw(20) << left << mhn << setw(20) << left << currentuser.username
                          << setw(20) << left << "pending..." << endl;
                    if (am == 0) {
                        deletefromnode(p, mn);
                        continue;
                    }
                    updateNode(pn, pp, mp, am, mn, 2);
                }
                file1 << setw(20) << left << pn << setw(20) << left << pp << setw(10) << left << mp << setw(10) << left
                      << am << setw(20) << left << mhn << endl;
            }

            file.close();
            file1.close();
            file2.close();
            remove("products.txt");
            rename("temp.txt", "products.txt");
            cout << "\n\n\t\tOrder Completed." << endl;

        } else {
            cout << "\n\n\t\tThis millingHouse doesn't have that much amount of that product" << endl;
        }
    } else {
        cout << "\n\n\t\tThis milling house doesn't have a product with that name." << endl;
    }
    clear(0);
}


void discountprice() {
    float total = 0;
    fstream file;
    file.open("order.txt", ios::in);
    string name, email, address, phone, username, password, productname, millinghousename;
    int amount;
    float price, millingprice;
    while (file >> name >> email >> address >> phone >> username >> password >> productname >> millinghousename
                >> amount >> price >> millingprice) {
        if (username == currentuser.username) {
            total += (price + millingprice) * amount;
        }
    }
    file.close();
    cout << "\n\n\t\tTotal Price: " << total << endl;
    cout << "\n\n\t\tTotal Price after discount: " << total - (total * 0.1) << endl;
    cout << "\n\n\t\tPress Enter to Continue...";
    getch();
}


bool checkp(string p, string mn) {
    if (head == NULL) {
        return false;
    }
    Product *temp = head;
    while (temp != NULL) {
        if (temp->ProductName == p && temp->millinghousename == mn) {
            return true;
        }

        temp = temp->next;
    }
    return false;
}

bool checka(string p, string mn, int a) {
    Product *temp = head;
    while (temp != NULL) {
        if (temp->ProductName == p && temp->millinghousename == mn && temp->amount >= a)
            return true;
        temp = temp->next;
    }
    return false;
}


void updateNode(string pn, float pp, float mp, int am, string mn, int x) {
    if (x == 1) {
        Product *temp = head;
        while (temp != NULL) {
            if (temp->ProductName == pn && miller.name == temp->millinghousename) {
                temp->ProductPrice = pp;
                temp->MillingPrice = mp;
                temp->amount = am;
            }
            temp = temp->next;
        }
    } else {
        Product *temp = head;
        while (temp != NULL) {
            if (temp->ProductName == pn && mn == temp->millinghousename) {
                temp->ProductPrice = pp;
                temp->MillingPrice = mp;
                temp->amount = am;
            }
            temp = temp->next;
        }
    }
}

void deletefromnode(string s, string mn) {
    if (head->next == NULL) {
        head = NULL;
    } else {
        Product *temp = head->next;
        Product *ptr = head;
        while (temp != NULL) {
            if (temp->ProductName == s && mn == temp->millinghousename)
                break;
            temp = temp->next;
            ptr = ptr->next;
        }
        if (temp == NULL) {
            ptr->next = NULL;
            delete temp;
        } else {
            ptr->next = temp->next;
            delete temp;
        }
    }
}


void search() {
    if (head == NULL) {
        cout << "\n\n\t\tWe Don't Have products in our store Yet." << endl;
        cont();
        return;
    }
    string value;
    cout << "\n\n\t\tEnter the name of the product you wanna search: ";
    cin.ignore();
    getline(cin, value);

    value = replace(value, ' ', '_');
    value = changetolower(value);
    Product *temp = head;

    int a = -1;
    while (temp != NULL) {
        if (temp->ProductName == value) {
            a++;
            cout << "\n\n\t\tHere is the Product details" << endl;
            cout << "\t\t" << setw(20) << left << "productName" << setw(20) << left << "productPrice" << setw(20)
                 << left << "MillingPrice" << setw(10) << left << "amount" << setw(20) << left << "Millinhouse" << endl;
            cout << "\t\t" << setw(20) << left << temp->ProductName << setw(20) << left << temp->ProductPrice
                 << setw(20) << left << temp->MillingPrice << setw(10) << left << temp->amount << setw(20) << left
                 << temp->millinghousename << endl;
            cont();
            break;
        }
        temp = temp->next;
    }
    if (a == -1) {
        cout << "\n\n\t\tThe name of the product you Entered doesn't exist." << endl;
        cont();
    }
}

#endif //GM_BUY_H
