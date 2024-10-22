#include<iostream>
#include<string>
using namespace std;

#define Max 1000

struct ContactInfo {
    string cName;
    int cGender = 1;
    int cAge = 0;     // Added cAge
    string cPhone;    // Added cPhone
    string cAdd;      // Added cAdd
};

struct ContactBook {
    ContactInfo contactList[Max];
    int count = 0;
};

void showMenu() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~  Welcome to Your Book  ~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~ 1. Add a new buddy      ~~~" << endl;  // Added menu option
    cout << "~~~ 2. Show my buddies      ~~~" << endl;  // Added another option
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void AddContacts(ContactBook* myBook) {
    if (myBook->count == Max) {
        cout << "Yo! Book's full, no more space! :(" << endl;
        return;
    } else {
        string name;
        cout << "What's the name? " << endl;
        cin >> name;
        myBook->contactList[myBook->count].cName = name;

        int gender;
        cout << "Gender? (1 = Male, 2 = Female)" << endl;
        while (true) {
            cin >> gender;
            if (gender == 1 || gender == 2) {
                myBook->contactList[myBook->count].cGender = gender;
                break;
            }
            cout << "C'mon, enter a valid gender! :P" << endl;
        }

        int age;
        cout << "Age? " << endl;
        cin >> age;
        myBook->contactList[myBook->count].cAge = age;

        string phone;
        cout << "Phone number? " << endl;
        cin >> phone;
        myBook->contactList[myBook->count].cPhone = phone;

        string add;
        cout << "Address? " << endl;
        cin >> add;
        myBook->contactList[myBook->count].cAdd = add;

        myBook->count++;
        cout << "Sweet! Added your buddy! :)" << endl;
    }
}

void ShowContacts(ContactBook* myBook) {
    if (myBook->count == 0) {
        cout << "Oops, you got no friends here... Add some first! :D" << endl;
    } else {
        for (int i = 0; i < myBook->count; i++) {
            cout << "Name: " << myBook->contactList[i].cName
                 << " Gender: " << (myBook->contactList[i].cGender != 2 ? "Male" : "Female")
                 << " Age: " << myBook->contactList[i].cAge
                 << " Phone: " << myBook->contactList[i].cPhone
                 << " Address: " << myBook->contactList[i].cAdd << endl;
        }
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
        case 2:
            ShowContacts(&myBook);
            break;
        }
    }
    return 0;
}
