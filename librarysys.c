#include <stdio.h>
#include <string.h>

char booktitles[5][20];
char bookauthors[5][20];
int able[5] = {0, 0, 0, 0, 0};
int bookcount = 0;

void addbook();
void display();
void borrow();
void returnbook();
void errorcolor();
void searchbookbytitle();
void searchbookbyauthor();
void yellow();

void resetcolor();
void green();
void blue();
void pink();
void black();

int main()
{
    int choice;
    do
    {
        yellow();

        printf("\n**LIBRARY MANAGEMENT SYSTEM\n");
        printf("1. Add new book\n");
        printf("2. Display available books\n");
        printf("3. Borrow book\n");
        printf("4. Return book\n");
        printf("5. Search book by title\n");
        printf("6. Search book by author\n");
        printf("0. Exit program\n");
        resetcolor();

        blue();
        printf("Enter your choice: ");
        resetcolor();

        scanf("%d", &choice);

        getchar();

        switch (choice)
        {
        case 1:
            addbook();
            break;
        case 2:
            display();
            break;
        case 3:
            borrow();
            break;
        case 4:
            returnbook();
            break;
        case 5:
            searchbookbytitle();
            break;
        case 6:
            searchbookbyauthor();
            break;
        case 0:
            resetcolor();
            printf("Exit the program\n");
            errorcolor();
            break;
        default:

            printf("Invalid choice, try again\n");
        }
    } while (choice != 0);
    return 0;
}

void addbook()
{
    if (bookcount >= 5)
    {
        errorcolor();
        printf("Library is full.\n");
        resetcolor();

        return;
    }

    char title[20];
    char author[20];
    int isNumeric;

    do
    {
        pink();
        printf("Enter the book title: \n");
        resetcolor();

        scanf("%s", &title);

        isNumeric = 1;
        for (int i = 0; i < strlen(title); i++)
        {
            if (title[i] < '0' || title[i] > '9')
            {
                isNumeric = 0;
                break;
            }
        }

        if (isNumeric)
        {
            errorcolor();

            printf(" Number can not be allowed\n");
            resetcolor();
        }
    } while (isNumeric);
    do
    {
        pink();

        printf("Enter the author name: \n");
        resetcolor();
        scanf("%s", &author);

        isNumeric = 1;
        for (int i = 0; i < strlen(author); i++)
        {
            if (author[i] < '0' || author[i] > '9')
            {
                isNumeric = 0;
                break;
            }
        }

        if (isNumeric)
        {
            errorcolor();
            printf("Numbers can no alllowed\n");
            resetcolor();
        }
    } while (isNumeric);
    for (int i = 0; i < 20; i++)
    {
        booktitles[bookcount][i] = title[i];
        bookauthors[bookcount][i] = author[i];
    }

    able[bookcount] = 0;
    bookcount++;
    green();
    printf("Book added successfully\n");
    resetcolor();
}
void display()
{
    if (bookcount == 0)
    {
        errorcolor();
        printf("No books available.\n");
        resetcolor();

        return;
    }
    black();
    printf("\nAvailable books:\n");
    resetcolor();

    int availableBooks = 0;
    for (int i = 0; i < bookcount; i++)
    {
        if (able[i] == 0)
        {
            printf("Title: %s\t", booktitles[i]);
            printf("Author: %s\t   \n", bookauthors[i]);
            availableBooks++;
        }
    }

    if (availableBooks == 0)
    {
        errorcolor();
        printf("No books available.\n");
        resetcolor();
    }
}

void borrow()
{
    if (bookcount == 0)
    {
        errorcolor();
        printf("No books available to borrow.\n");
        resetcolor();

        return;
    }

    char title[20];
    pink();
    printf("Enter the title of the book to borrow: ");
    resetcolor();

    scanf("%s", &title);

    for (int i = 0; i < bookcount; i++)
    {
        if (strcmp(booktitles[i], title) == 0)
        {
            if (able[i] == 1)
            {
                errorcolor();
                printf("The book '%s' is already borrowed.\n", booktitles[i]);
                resetcolor();
                return;
            }
            able[i] = 1;
            pink();
            printf("You have borrowed the book '%s'.\n", booktitles[i]);
            resetcolor();

            return;
        }
    }
    errorcolor();
    printf("Book with title '%s' not found.\n", title);
    resetcolor();
}

void returnbook()
{
    if (bookcount == 0)
    {
        errorcolor();
        printf("Please add a book first. No books are available in the library.\n");
        resetcolor();

        return;
    }

    int borrowedBooks = 0;
    for (int i = 0; i < bookcount; i++)
    {
        if (able[i] == 1)
        {
            borrowedBooks = 1;
            break;
        }
    }

    if (!borrowedBooks)
    {
        errorcolor();
        printf("No book is borrowed to return.\n");
        resetcolor();

        return;
    }

    char title[20];
    pink();
    printf("Enter the title of the book to return: ");
    resetcolor();

    scanf("%s", &title);

    for (int i = 0; i < bookcount; i++)
    {
        if (strcmp(booktitles[i], title) == 0)
        {
            if (able[i] == 0)
            {
                green();
                printf("The book '%s' is already available in the library.\n", booktitles[i]);
                resetcolor();
                return;
            }
            able[i] = 0;
            green();
            printf("You have successfully returned the book '%s'.\n", booktitles[i]);
            resetcolor();
            return;
        }
    }
    errorcolor();
    printf("Book with title '%s' not found.\n", title);
    resetcolor();
}

void searchbookbytitle() {
    if (bookcount == 0) {
        errorcolor();
        printf("No books are available.\n");
        resetcolor();
        return;
    }

    char title[20];
    int validInput = 0;

    while (!validInput) {
        pink();
        printf("Enter title name to search or type exit for menu : ");
        
        resetcolor();
        scanf("%s", title);

        if (strcmp(title, "wapis") == 0) {
            printf("Exiting search by author.\n");
            return;
        }

        validInput = 1; 
        printf("Search results:\n");
        int found = 0;
        for (int i = 0; i < bookcount; i++) {
            if (strncmp(booktitles[i], title, 3) == 0) { 
                printf("Title: %s, Author: %s, Status: %s\n", booktitles[i],
                       bookauthors[i], able[i] );
                found = 1;
            }
        }

        if (!found) {
            errorcolor();
            printf("No book found matching the author '%s'.\n", title);
            resetcolor();
            validInput = 0; 
        }
    }
}

void searchbookbyauthor() {
    if (bookcount == 0) {
        errorcolor();
        printf("No books are available.\n");
        resetcolor();
        return;
    }

    char author[20];
    int validInput = 0;

    while (!validInput) {
        pink();
        printf("Enter author name to search or type exit for menu: ");
        
        resetcolor();
        scanf("%s", author);

        if (strcmp(author, "exit") == 0) {
            printf("Exiting search by author.\n");
            return;
        }

        validInput = 1; 
        printf("Search results:\n");
        int found = 0;
        for (int i = 0; i < bookcount; i++) {
            if (strncmp(bookauthors[i], author, 3) == 0) { 
                printf("Title: %s, Author: %s, Status: %s\n", booktitles[i],
                       bookauthors[i], able[i] == 0 ? "Available" : "Borrowed");
                found = 1;
            }
        }

        if (!found) {
            errorcolor();
            printf("No book found matching the author '%s'.\n", author);
            resetcolor();
            validInput = 0; 
        }
    }
}

void resetcolor()
{
    printf("\033[0m");
}
void errorcolor()
{
    printf("\033[1;31m");
}
void green()
{
    printf("\033[0;32m");
}
void yellow()
{
    printf("\033[0;33m");
}
void blue()
{
    printf("\033[0;34m");
}
void pink()
{
    printf("\033[0;35m");
}
void black()
{
    printf("\033[0;36m");
}