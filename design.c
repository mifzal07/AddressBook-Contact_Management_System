#include <stdio.h>
#include <unistd.h>
#include "contact.h"

// Displays animated loading bar with a success message upon saving contacts.
void loading()
{
    int i, delay;
    char *ch = "#";
    for (i = 0; i <= 100; i++)
    {
        printf("\r[");
        for (int j = 0; j < 50; j++)
        {
            2 * j <= i ? printf("%s", ch) : printf(" ");
        }
        printf("] %i%%", i);
        fflush(stdout);
        for (delay = 0x4ffffff; delay--;);
    }
    printf("\n💾 Contacts saved successfully! ✅\n");

    return;
}

// Print the heading and column names of the contact table
void printTableTop(void)
{
    printf("\n+------+----------------------+-----------------+----------------------+\n");
    printf("| %-4s | %-20s | %-15s | %-20s |\n", "No.", "Name", "Phone", "Email");
    printf("+------+----------------------+-----------------+----------------------+\n");
}

// Print one contact as a row in the contact table
void printContactRow(int contactNumber, Contact *contact)
{
    printf("| %-4d | %-20s | %-15s | %-20s |\n", contactNumber, contact->name, contact->phone, contact->email);
}

// Print the bottom border and total number of contacts
void printTablebottom(int totalContacts)
{
    printf("+------+----------------------+-----------------+----------------------+\n");
    printf("| Total Contacts: %-52d |\n", totalContacts);
    printf("+----------------------------------------------------------------------+\n");
}