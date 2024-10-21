#include<iostream>
#include<string>
using namespace std;

#define Max 1000

struct ContactInfo {
    string cName;
    int cGender = 1;
};

struct ContactBook {
    ContactInfo contactList[Max];
    int count = 0;
};

void showMenu() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~  Welcome to Your Book  ~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void AddContacts(ContactBook* myBook) {
    if (myBook->count == Max) {
        cout << "Yo! Book's full, no more space! :(" << endl;
        return;
    }
}

int main() {
    int option = 0;
    ContactBook myBook;
    myBook.count = 0;

    while (true) {
        showMenu();
        cin >> option;

        switch (option) {
        case 1:
            AddContacts(&myBook);
            break;
        }
    }
    return 0;
}
