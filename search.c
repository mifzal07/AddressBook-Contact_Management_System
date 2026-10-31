#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

// Search contacts by matching the beginning of any name part
int searchname(AddressBook *addressBook, Contact *search)
{
    int i, j, found = 0;
    char name_lower[50];
    char *name_start;

    // Convert the search name to lowercase for case-insensitive searching
    for (i = 0; search->name[i] != '\0'; i++)
    {
        search->name[i] = tolower(search->name[i]);
    }
    search->name[i] = '\0';

    // Check the search name against every contact
    for (i = 0; i < addressBook->contactCount; i++)
    {
        // Convert the stored contact name to lowercase.
        for (j = 0; addressBook->contacts[i].name[j] != '\0'; j++)
        {
            name_lower[j] = tolower(addressBook->contacts[i].name[j]);
        }
        name_lower[j] = '\0';

        // Start searching from the beginning of the complete name
        name_start = name_lower;

        while (*name_start != '\0')
        {

            // Check whether the search text matches the beginning of this name part
            if (strncmp(name_start, search->name, strlen(search->name)) == 0)
            {
                if (found == 0)
                {
                    // Print the table heading
                    printf("\nSearch Results Found:\n");
                    printTableTop();
                }

                // Print every contact as a table row
                printContactRow(i + 1,
                                &addressBook->contacts[i]);
                found++;

                break;
            }

            // Find the next space to check the next name is present in search name.
            name_start = strchr(name_start, ' ');
            if (name_start == NULL)
            {
                break;
            }

            // Move to the first character after the space
            name_start++;
        }
    }
    if (found == 0)
    {
        printf("Contact Name not found\n");
        return 0;
    }

    // Print the table footer and number of matching contacts
    printTablebottom(found);

    return 1;
}

// Search contacts by matching part of the phone number
int searchphone(AddressBook *addressBook, Contact *serach)
{
    int i, found = 0;

    // Check the search phone number against every contact
    for (i = 0; i < addressBook->contactCount; i++)
    {
        // Check whether the search text exists in the phone number
        if (strstr(addressBook->contacts[i].phone, serach->phone) != NULL)
        {
            if (found == 0)
            {
                // Print the table heading
                printf("\nSearch Results Found:\n");
                printTableTop();
            }
            // Print every contact as a table row
            printContactRow(i + 1,
                            &addressBook->contacts[i]);
            found++;
        }
    }
    if (found == 0)
    {
        printf("Contact phone number not found.\n");
        return 0;
    }

    // Print the table footer and number of matching contacts
    printTablebottom(found);

    return 1;
}
// Search contacts by matching part of the email address
int searchemail(AddressBook *addressBook, Contact *search)
{
    int i, found = 0;

    // Check the search email against every contact
    for (i = 0; i < addressBook->contactCount; i++)
    {
        // Check whether the search text exists in the email address
        if (strstr(addressBook->contacts[i].email, search->email) != NULL)
        {
            if (found == 0)
            {
                // Print the table heading
                printf("\nSearch Results Found:\n");
                printTableTop();
            }
            // Print every contact as a table row
            printContactRow(i + 1,
                            &addressBook->contacts[i]);
            found++;
        }
    }
    if (found == 0)
    {
        printf("Contact email not found\n");
        return 0;
    }

    // Print the table footer and number of matching contacts
    printTablebottom(found);

    return 1;
}