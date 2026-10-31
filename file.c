#include <stdio.h>
#include "file.h"

// Save all contacts from the address book into the CSV file
void saveContactsToFile(AddressBook *addressBook)
{

    int i;
    FILE *fp;
    fp = fopen("contacts.csv", "w");
    if (fp == NULL)
    {
        perror("Error ");
        return;
    }
    for (i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fp);
}

// Load contacts from the CSV file into the address book
void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fp;
    fp = fopen("contacts.csv", "r");
    if (fp == NULL)
    {
        perror("Error : ");
        return;
    }
    while (addressBook->contactCount < MAX_CONTACTS &&
           fscanf(fp, " %49[^,],%19[^,],%49[^\n]",
            addressBook->contacts[addressBook->contactCount].name,
            addressBook->contacts[addressBook->contactCount].phone,
            addressBook->contacts[addressBook->contactCount].email) == 3)
    {
        addressBook->contactCount++;
    }
    fclose(fp);
}
