#include<iostream>
#include<string>
using namespace std;

#define Max 1000

struct ContactInfo {
    string cName;
    int cGender = 1;
    int cAge = 0;
    string cPhone;
    string cAdd;
};

struct ContactBook {
    ContactInfo contactList[Max];
    int count = 0;
};

void showMenu() {
    cout << "~" << endl;
    cout << "~~~  Welcome to Your Book  ~~~" << endl;
    cout << "~" << endl;
    cout << "~~~ 1. Add a new buddy      ~~~" << endl;
    cout << "~~~ 2. Show my buddies      ~~~" << endl;
    cout << "~~~ 3. Delete a buddy       ~~~" << endl;
    cout << "~~~ 4. Find a buddy         ~~~" << endl;
    cout << "~~~ 5. Update a buddy       ~~~" << endl;
    cout << "~~~ 6. Wipe all contacts    ~~~" << endl;
    cout << "~~~ 0. Exit outta here      ~~~" << endl;
    cout << "~" << endl;
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

int IsExist(ContactBook* myBook, string name) {
    for (int i = 0; i < myBook->count; i++) {
        if (myBook->contactList[i].cName == name) {
            return i;
        }
    }
    return -1;
}

void DeleteContacts(ContactBook* myBook) {
    string name;
    cout << "Who's getting the boot? (Enter name): " << endl;
    cin >> name;

    int index = IsExist(myBook, name);

    if (index > -1) {
        for (int i = index; i < myBook->count - 1; i++) {
            myBook->contactList[i] = myBook->contactList[i + 1];
        }
        myBook->count--;
        cout << "Poof! Contact deleted :)" << endl;
    } else {
        cout << "Nope, can't find that one :(" << endl;
    }
}

void GetContacts(ContactBook* myBook) {
    string name;
    cout << "Looking for? (Enter name): " << endl;
    cin >> name;

    int index = IsExist(myBook, name);
    if (index > -1) {
        cout << "Name: " << myBook->contactList[index].cName << endl;
        cout << "Gender: " << (myBook->contactList[index].cGender != 2 ? "Male" : "Female") << endl;
        cout << "Age: " << myBook->contactList[index].cAge << endl;
        cout << "Phone: " << myBook->contactList[index].cPhone << endl;
        cout << "Address: " << myBook->contactList[index].cAdd << endl;
    } else {
        cout << "Contact not found :(" << endl;
    }
}

void EditContacts(ContactBook* myBook) {
    string name;
    cout << "Who do you want to update? (Enter name): " << endl;
    cin >> name;

    int index = IsExist(myBook, name);
    if (index > -1) {
        cout << "New name? " << endl;
        cin >> name;
        myBook->contactList[index].cName = name;

        int gender;
        cout << "New gender? (1 = Male, 2 = Female)" << endl;
        while (true) {
            cin >> gender;
            if (gender == 1 || gender == 2) {
                myBook->contactList[index].cGender = gender;
                break;
            }
            cout << "Try again! :P" << endl;
        }

        int age;
        cout << "New age? " << endl;
        cin >> age;
        myBook->contactList[index].cAge = age;

        string phone;
        cout << "New phone number? " << endl;
        cin >> phone;
        myBook->contactList[index].cPhone = phone;

        string add;
        cout << "New address? " << endl;
        cin >> add;
        myBook->contactList[index].cAdd = add;

        cout << "Contact updated! :) " << endl;
    } else {
        cout << "Couldn't find them, sorry!" << endl;
    }
}

void ClearContacts(ContactBook* myBook) {
    string confirm;
    cout << "Clear the whole book? Y/N: " << endl;

    while (true) {
        cin >> confirm;
        if (confirm == "Y") {
            myBook->count = 0;
            cout << "All gone! :)" << endl;
            break;
        } else if (confirm == "N") {
            cout << "Whew! Saved it :)" << endl;
            break;
        } else {
            cout << "Oops, just type Y or N!" << endl;
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
        case 3:
            DeleteContacts(&myBook);
            break;
        case 4:
            GetContacts(&myBook);
            break;
        case 5:
            EditContacts(&myBook);
            break;
        case 6:
            ClearContacts(&myBook);
            break;
        case 0:
            cout << "Later! :) See you next time!" << endl;
            return 0;
        default:
            cout << "Invalid option, try again!" << endl;
        }
    }
    return 0;
}
