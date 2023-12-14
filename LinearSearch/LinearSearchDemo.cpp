#include <iostream>
#include <string>

using namespace std;

// Contact structure
struct Contact {
     string name;
     string phoneNumber;
};

// Phonebook class
class Phonebook {
private:
    static const int MAX_CONTACTS = 100;
    Contact contacts[MAX_CONTACTS];
    int numContacts;

public:
    Phonebook() : numContacts(0) {}

    // Add a new contact to the phonebook
    void addContact(const  string& name, const  string& phoneNumber) {
        if (numContacts < MAX_CONTACTS) {
            contacts[numContacts].name = name;
            contacts[numContacts].phoneNumber = phoneNumber;
            numContacts++;
             cout << "Contact added successfully!\n";
        } else {
             cout << "Phonebook is full. Cannot add more contacts.\n";
        }
    }

    // Search for a contact by name using linear search
    void searchContact(const  string& name) {
        for (int i = 0; i < numContacts; ++i) {
            if (contacts[i].name == name) {
                 cout << "Contact found!\n";
                 cout << "Name: " << contacts[i].name << "\n";
                 cout << "Phone Number: " << contacts[i].phoneNumber << "\n";
                return; // Contact found, no need to continue searching
            }
        }
         cout << "Contact not found.\n";
    }

    // Display all contacts in the phonebook
    void displayContacts() {
        if (numContacts == 0) {
             cout << "Phonebook is empty.\n";
        } else {
             cout << "Contacts in the phonebook:\n";
            for (int i = 0; i < numContacts; ++i) {
                 cout << "Name: " << contacts[i].name << ", Phone Number: " << contacts[i].phoneNumber << "\n";
            }
        }
    }
};

int main() {
    Phonebook phonebook;

    // Menu
    int choice;
     string name, phoneNumber;

    do {
         cout << "\nPhonebook Menu:\n";
         cout << "1. Add Contact\n";
         cout << "2. Search Contact\n";
         cout << "3. Display Contacts\n";
         cout << "4. Exit\n";
         cout << "Enter your choice: ";
         cin >> choice;

        switch (choice) {
            case 1:
                 cout << "Enter contact name: ";
                 cin >> name;
                 cout << "Enter phone number: ";
                 cin >> phoneNumber;
                phonebook.addContact(name, phoneNumber);
                break;
            case 2:
                 cout << "Enter contact name to search: ";
                 cin >> name;
                phonebook.searchContact(name);
                break;
            case 3:
                phonebook.displayContacts();
                break;
            case 4:
                 cout << "Exiting Phonebook. Goodbye!\n";
                break;
            default:
                 cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
