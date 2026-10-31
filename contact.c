#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

// Display all contacts after sorting according to the selected criteria
void listContacts(AddressBook *addressBook, int sortCriteria)
{
    // Sort contacts based on the chosen criteria
    int i;
    if (sortCriteria == 1)
    {
        sortname(addressBook);
    }
    else if (sortCriteria == 2)
    {
        sortphone(addressBook);
    }
    else if (sortCriteria == 3)
    {
        sortemail(addressBook);
    }
    else
    {
        printf("Invalid sort choice\n");
        return;
    }

    // Print the table heading
    printTableTop();

    // Print every contact as a table row
    for (i = 0;
         i < addressBook->contactCount;
         i++)
    {
        printContactRow(i + 1,
                        &addressBook->contacts[i]);
    }

    // Print the table bottom and total count
    printTablebottom(addressBook->contactCount);
}

// Initialize the address book and load existing contacts from the file
void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
    // populateAddressBook(AddressBook* addressBook);

    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

// Save all contacts to the file and exit the program
void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);              // Exit the program
}

// Create a new contact after validating and checking uniqueness of contacts
void createContact(AddressBook *addressBook)
{
    /* Define the logic to create a Contacts */
    Contact tempcontact;
    int validationresult;

    // Check whether the address book has reached its maximum capacity
    if (addressBook->contactCount >= MAX_CONTACTS)
    {
        printf("Address Book is Full\n");
        return;
    }

    printf("Enter the name : ");
    scanf(" %[^\n]", tempcontact.name);
    validationresult = name(&tempcontact);
    if (validationresult == 1)
    {
        strcpy(addressBook->contacts[addressBook->contactCount].name, tempcontact.name);
    }
    else
    {
        return;
    }

    printf("Enter the Phone No : ");
    scanf(" %[^\n]", tempcontact
                         .phone);
    validationresult = phone(&tempcontact);
    if (validationresult == 1)
    {
        int check_unique = unique_phone(addressBook, &tempcontact); // Check whether the entered phone number already exists

        if (check_unique == 1)
        {
            strcpy(addressBook->contacts[addressBook->contactCount].phone, tempcontact

                                                                               .phone);
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }

    printf("Enter the e-mail - id : ");
    scanf(" %[^\n]", tempcontact
                         .email);
    validationresult = email(&tempcontact);
    if (validationresult == 1)
    {
        int check_unique = unique_email(addressBook, &tempcontact); // Check whether the entered email already exists

        if (check_unique == 1)
        {
            strcpy(addressBook->contacts[addressBook->contactCount].email, tempcontact

                                                                               .email);
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }

    addressBook->contactCount++;

    printf("\nContact created successfully.\n");
}

// Search for a contact using the selected search criteria
void searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */
    Contact search;
    printf("\nSelect Search criteria:\n");
    printf("1. Search by name\n");
    printf("2. Search by phone\n");
    printf("3. Search by email\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    int select_choice;
    scanf("%d", &select_choice);
    getchar(); // Clears invalid characters

    switch (select_choice)
    {
    case 1:
        printf("Enter name to search : ");
        scanf(" %[^\n]", search.name);
        searchname(addressBook, &search); // Search using the name

        break;

    case 2:
        printf("Enter phone number to search : ");
        scanf(" %[^\n]", search.phone);
        searchphone(addressBook, &search); // Search using phone number

        break;

    case 3:
        printf("Enter email to search : ");
        scanf(" %[^\n]", search.email);
        searchemail(addressBook, &search); // Search using email

        break;
    case 4:
        return;

    default:
        printf("Invalid Input\n");
        return;
    }
}

// Edit an existing contact selected by the user
void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
    Contact search;
    int contact_index;
    int search_choice;
    int edit_choice;
    int validationresult;
    printf("\nSelect Search criteria:\n");
    printf("1. Search by name\n");
    printf("2. Search by phone\n");
    printf("3. Search by email\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &search_choice);
    getchar();

    switch (search_choice)
    {
    case 1:
        printf("Enter name to search : ");
        scanf(" %[^\n]", search.name);
        if (!searchname(addressBook, &search))
        {
            return;
        }

        break;

    case 2:
        printf("Enter phone number to search : ");
        scanf(" %[^\n]", search.phone);
        if (!searchphone(addressBook, &search))
        {
            printf("Select valid phone\n");
            return;
        }

        break;

    case 3:
        printf("Enter email to search : ");
        scanf(" %[^\n]", search.email);
        if (!searchemail(addressBook, &search))
        {
            printf("Select valid email\n");
            return;
        }
        break;
    case 4:
        return;

    default:
        printf("Invalid Input\n");
        return;
    }

    printf("Select a contact to edit (contact number) : ");
    scanf("%d", &contact_index);

    if (contact_index < 1 || contact_index > addressBook->contactCount)
    {
        printf("Enter the valid contact number\n");
        return;
    }

    printTableTop();

    printContactRow(contact_index,
                    &addressBook->contacts[contact_index - 1]);

    printTablebottom(1);

    printf("\nSelect Edit criteria:\n");
    printf("1. Edit by name\n");
    printf("2. Edit by phone\n");
    printf("3. Edit by email\n");
    printf("4. Exit\n");
    printf("Enter your Choice : ");
    scanf("%d", &edit_choice);

    switch (edit_choice)
    {
    case 1:
        printf("Edit name : ");
        scanf(" %[^\n]", search.name);
        validationresult = name(&search);
        if (validationresult == 1)
        {
            strcpy(addressBook->contacts[contact_index - 1].name, search.name);
        }
        else
        {
            return;
        }

        break;

    case 2:
        printf("Edit phone : ");
        scanf(" %[^\n]", search.phone);
        validationresult = phone(&search);
        if (validationresult == 1)
        {
            int check_unique = unique_phone(addressBook, &search); // Check the new phone number is unique

            if (check_unique == 1)
            {
                strcpy(addressBook->contacts[contact_index - 1].phone, search.phone);
            }
            else
            {
                return;
            }
        }
        else
        {
            return;
        }
        break;
    case 3:
        printf("Edit email : ");
        scanf(" %[^\n]", search.email);
        validationresult = email(&search);
        if (validationresult == 1)
        {
            int check_unique = unique_email(addressBook, &search); // Check whether the new email is unique

            if (check_unique == 1)
            {
                strcpy(addressBook->contacts[contact_index - 1].email, search.email);
            }
            else
            {
                return;
            }
        }
        else
        {
            return;
        }
        break;

    case 4:
        return;

    default:
        printf("Invalid edit choice\n");
        return;
    }

    printf("\nContact updated successfully.\n");
}

// Delete an existing contact after confirmation from the user
void deleteContact(AddressBook *addressBook)
{
    /* Define the logic for deletecontact */
    if (addressBook->contactCount == 0)
    {
        printf("No Contacts to delete\n");
        return;
    }

    Contact delete;
    int contact_index;
    char confirm[10];
    printf("\nSelect Search criteria:\n");
    printf("1. Delete by name\n");
    printf("2. Delete by phone\n");
    printf("3. Delete by email\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    int search_choice;

    scanf("%d", &search_choice);

    switch (search_choice)
    {
    case 1:
        printf("Enter name to search : ");
        scanf(" %[^\n]", delete.name);
        if (!searchname(addressBook, &delete))
        {
            return;
        }

        break;

    case 2:
        printf("Enter phone to search : ");
        scanf(" %[^\n]", delete.phone);
        if (!searchphone(addressBook, &delete))
        {
            printf("Select valid phone\n");
            return;
        }

        break;

    case 3:
        printf("Enter email to search : ");
        scanf(" %[^\n]", delete.email);
        if (!searchemail(addressBook, &delete))
        {
            printf("Select valid email\n");
            return;
        }
        break;
    case 4:
        return;

    default:
        printf("Invalid Input\n");
        return;
    }

    printf("Select a contact to delete (contact number) : ");
    scanf("%d", &contact_index);

    if (contact_index < 1 || contact_index > addressBook->contactCount)
    {
        printf("Enter the valid contact number\n");
        return;
    }
    printTableTop();

    printContactRow(contact_index,
                    &addressBook->contacts[contact_index - 1]);

    printTablebottom(1);

    printf("\nAre you sure you want to delete this contact? (yes/no): ");
    scanf("%9s", confirm);

    if (strcmp(confirm, "yes") == 0)
    {
        // Shift all contacts after the deleted contact one position to the left
        for (int i = contact_index; i < addressBook->contactCount - 1; i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }
        addressBook->contactCount--;
        printf("Contact deleted Successfully\n");
    }
    else
    {
        printf("Deletion is Cancelled\n");
        return;
    }
}