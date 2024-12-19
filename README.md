# 📒 Address Book CLI

This is a simple **Address Book** application built using **C++**. It allows you to add, display, delete, search, edit, and clear contacts. All operations are performed through a terminal interface.

## 📋 Features

- **Add Contact**: Store personal information such as name, gender, age, phone number, and address.
- **View Contacts**: Display all contacts stored in the address book.
- **Delete Contact**: Remove an individual contact from the address book.
- **Search Contact**: Look up contact details by name.
- **Edit Contact**: Modify existing contact details.
- **Clear Contacts**: Erase all contacts in one go.
- **Exit**: Safely exit the application when you're done.

## 🚀 How to Run

1. **Clone this repository**:
   ```bash
   git clone https://github.com/yourusername/address-book-cli.git
   ```
2. **Navigate to the project directory**:
   ```bash
   cd address-book-cli
   ```
3. **Compile the program** (Ensure you have a C++ compiler like `g++`):
   ```bash
   g++ address_book.cpp -o address_book
   ```
4. **Run the executable**:
   ```bash
   ./address_book
   ```

## 📖 Usage

After launching the program, you’ll see a menu with options:

```bash
********************************
*****    Address Book     *****
********************************
*****    1. Add Contact   *****
*****    2. Show Contacts *****
*****    3. Delete Contact *****
*****    4. Search Contact *****
*****    5. Edit Contact   *****
*****    6. Clear Contacts *****
*****    0. Exit           *****
********************************
```

- **1. Add Contact**: Enter the contact details when prompted. 😊
- **2. Show Contacts**: View all contacts in the system. 📜
- **3. Delete Contact**: Remove a contact by entering their name. ❌
- **4. Search Contact**: Enter a name to find the corresponding contact. 🔍
- **5. Edit Contact**: Modify an existing contact's details. ✏️
- **6. Clear Contacts**: Wipe out the entire address book in one go. 💥
- **0. Exit**: Quit the program and wave goodbye! 👋

## 🛠️ Technologies Used

- **C++**: Core programming language used to implement the application.
- **g++**: GNU C++ compiler for building the executable.
- **CLI**: Command Line Interface for user interaction.

## 🧩 Future Enhancements

- **File Storage**: Persist contacts between sessions by saving them to a file.
- **Validation**: Add stricter validation for user inputs.
- **Sorting**: Sort contacts alphabetically or by other criteria

---
