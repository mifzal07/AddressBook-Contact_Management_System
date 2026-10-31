#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

// Sort all contacts alphabetically according to their names
void sortname(AddressBook *addressbook)
{
    int i, j, s;
    Contact temp;
    for (i = 0; i < addressbook->contactCount - 1; i++)
    {
        for (j = 0; j < addressbook->contactCount - 1 - i; j++)
        {
            s = strcasecmp(addressbook->contacts[j].name,
                       addressbook->contacts[j + 1].name);
            if (s > 0)
            {
                temp = addressbook->contacts[j];
                addressbook->contacts[j] = addressbook->contacts[j + 1];
                addressbook->contacts[j + 1] = temp;
            }
        }
    }
}

// Sort all contacts in ascending order according to their phone numbers
void sortphone(AddressBook *addressbook)
{
    int i, j, s;
    Contact temp;
    for (i = 0; i < addressbook->contactCount - 1; i++)
    {
        for (j = 0; j < addressbook->contactCount - 1 - i; j++)
        {
            s = strcmp(addressbook->contacts[j].phone,
                       addressbook->contacts[j + 1].phone);
            if (s > 0)
            {
                temp = addressbook->contacts[j];
                addressbook->contacts[j] = addressbook->contacts[j + 1];
                addressbook->contacts[j + 1] = temp;
            }
        }
    }
}

// Sort all contacts in ascending order according to their email addresses
void sortemail(AddressBook *addressbook)
{
    int i, j, s;
    Contact temp;
    for (i = 0; i < addressbook->contactCount - 1; i++)
    {
        for (j = 0; j < addressbook->contactCount - 1 - i; j++)
        {
            s = strcmp(addressbook->contacts[j].email,
                       addressbook->contacts[j + 1].email);
            if (s > 0)
            {
                temp = addressbook->contacts[j];
                addressbook->contacts[j] = addressbook->contacts[j + 1];
                addressbook->contacts[j + 1] = temp;
            }
        }
    }
}