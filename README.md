# Address Book

A console-based Address Book application developed using C.

The application allows users to store and manage contact information.
It provides features to add, search, edit, delete, list, and sort contacts.
The project also uses file handling to store contact information in a CSV file.

## Features

- Add new contacts
- Search contacts
- Edit existing contacts
- Delete contacts
- List all contacts
- Sort contacts
- Validate contact information
- Prevent duplicate contacts
- Save contacts to a CSV file
- Load contacts from a CSV file
- Display contacts in a formatted table

## Technologies Used

- C Programming
- GCC
- Linux / WSL
- VS Code

## C Concepts Used

- Functions
- Structures
- Arrays
- Pointers
- Strings
- File Handling
- Dynamic Memory
- Searching
- Sorting
- Modular Programming
- Input Validation

## Project Structure

- File Description

- `main.c` - Contains the main function and program menu 
- `contact.c` - Implements contact management operations 
- `contact.h` - Contains contact structures and declarations 
- `search.c` - Implements contact searching 
- `sort.c` - Implements contact sorting 
- `validation.c` - Handles input validation 
- `file.c` - Handles file read/write operations 
- `file.h` - File handling declarations 
- `populate.c` - Handles initial/sample contact population 
- `populate.h` - Population function declarations 
- `design.c` - Handles formatted table and display design 
- `contacts.csv` - Sample contact data for testing 

## Compilation

Compile all source files using GCC:

```bash
gcc main.c contact.c search.c sort.c validation.c file.c populate.c design.c -o addressbook