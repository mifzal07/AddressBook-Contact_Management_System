#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);

// Defining Functions for Sorting
void sortname(AddressBook *addressBook);
void sortphone(AddressBook *addressBook);
void sortemail(AddressBook *addressBook);

//Defining Functions for Validation
int name(Contact *name_check);
int phone(Contact *phone_check);
int email(Contact *email_check);

// Defining Function for Unique Email and Phone number
int unique_phone(AddressBook *addressbook,Contact *check_unique);
int unique_email(AddressBook *addressbook,Contact *check_unique);

//Defining Function for Searching
int searchname(AddressBook *addressBook, Contact *search);
int searchphone(AddressBook *addressBook, Contact *serach);
int searchemail(AddressBook *addressBook, Contact *serach);

//Defining Functions for Designing
void loading(void);
void printTableTop(void); 
void printContactRow(int contactNumber, Contact *contact); 
void printTablebottom(int totalContacts);

#endif
