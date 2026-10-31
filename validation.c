#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

// Validate whether the contact name contains at least 4 characters and only alphabets/spaces

int name(Contact *name_check)
{
    int i = 0;

    if (strlen(name_check->name) < 4)
    {
        printf("Name must contain at least 4 characters.\n");
        return 0;
    }

    while (name_check->name[i] != '\0')
    {
        if (name_check->name[i] == ' ') // Allow spces between name parts
        {
            i++;
            continue;
        }

        // Check whether every non-space character is an alphabet

        if (!isalpha(name_check->name[i]))
        {
            printf("Name should contain only alphabets\n");
            return 0;
        }
        i++;
    }
    return 1;
}
// Validate whether the phone number contains exactly 10 digits and starts from 6 to 9

int phone(Contact *phone_check)
{
    int i = 0;

    while (phone_check->phone[i] != '\0')
    {
        if (isdigit(phone_check->phone[i]) == 0) // // Check whether every character is a digit
        {
            printf("Phone number should contain only digits.\n");
            return 0;
        }
        i++;
    }

    // Check whether the phone number contains exactly 10 digits
    if (strlen(phone_check->phone) != 10)
    {
        printf("Phone number contain exactly 10 digits.\n");
        return 0;
    }

    // Check whether the first digit is between 6 and 9
    if (phone_check->phone[0] < '6' || phone_check->phone[0] > '9')
    {
        printf("First digit must be between 6 & 9\n");
        return 0;
    }

    return 1;
}

// Validate whether the email contains lowercase letters, digits, one @, and one dot in the correct positions
int email(Contact *email_check)
{
    int i = 0, at_count = 0, dot_count = 0, at_position = 0, dot_position = 0;

    while (email_check->email[i] != '\0')
    {
        // Record the position of the @ symbol
        if (email_check->email[i] == '@')
        {
            at_position = i;
            at_count++;
        }

        // Record the position of the dot
        if (email_check->email[i] == '.')
        {
            dot_position = i;
            dot_count++;
        }

        // Allow only lowercase letters, digits, @ and dot
        if (!islower(email_check->email[i]) && !isdigit(email_check->email[i]) &&
            email_check->email[i] != '@' && email_check->email[i] != '.')
        {
            printf("Email should contain only lowercase letters and digits.\n");
            return 0;
        }
        i++;
    }

    // Check whether exactly one @ symbol is present
    if (at_count == 0)
    {
        printf("Missing @ symbol.\n");
        return 0;
    }

    if (at_count > 1)
    {
        printf("More than one @ symbol is present.\n");
        return 0;
    }

    // Check whether exactly one dot is present
    if (dot_count == 0)
    {
        printf("Missing '.' symbol.\n");
        return 0;
    }

    if (dot_count > 1)
    {
        printf("More than one '.' symbol is present.\n");
        return 0;
    }

    // Dot must appear after the @ symbol
    if (dot_position <= at_position)
    {
        printf("'.'(dot) should be present after @.\n");
        return 0;
    }

    // At least one character must exist between @ and dot
    if ((dot_position - at_position-1) == 0)
    {
        printf("There must be at least one character between '@' and '.' \n");
        return 0;
    }

    // Validates that the email contains a domain and ends strictly with ".com".
    char *s = strrchr(email_check->email, '.');
    if (s == NULL)
    {
        printf("Domain must be provided for an e-mail.\n");
        return 0;
    }
    if (strcmp(s, ".com") != 0)
    {
        printf("Invalid domain! Only '.com' is allowed.\n");
        return 0;
    }
    return 1;
}

// Check whether the contact phone number is unique in the address book
int unique_phone(AddressBook *addressbook, Contact *check_unique)
{
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        // Compare the new phone number with every existing phone number
        if (strcmp(addressbook->contacts[i].phone, check_unique->phone) == 0)
        {
            printf("Phone number must be unique.\n");
            return 0;
        }
    }
    return 1;
}

// Check whether the contact email is unique in the address book
int unique_email(AddressBook *addressbook, Contact *check_unique)
{
    for (int i = 0; i < addressbook->contactCount; i++)
    {
        // Compare the new email with every existing email
        if (strcmp(addressbook->contacts[i].email, check_unique->email) == 0)
        {
            printf("Email must be unique.\n");
            return 0;
        }
    }
    return 1;
}