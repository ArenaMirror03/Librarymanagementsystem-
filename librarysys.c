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
void searchbookbytitle();
void searchbookbyauthor();

int main() {
    int choice;
    do {
        printf("\n*****LIBRARY MANAGEMENT SYSTEM*****\n");
        printf("1. Add new book\n");
        printf("2. Display available books\n");
        printf("3. Borrow book\n");
        printf("4. Return book\n");
        printf("5. Search book by title\n");
        printf("6. Search book by author\n");
        printf("0. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
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
                printf("Exit the program\n");
                break;
            default:
                printf("Invalid choice, try again\n");
        }
    } while (choice != 0);
    return 0;
}

void addbook() {
    if (bookcount >= 5) {
        printf("Library is full.\n");
        return;
    }

    printf("Enter the book title: ");
    scanf("%s", booktitles[bookcount]);
    printf("Enter the author name: ");
    scanf("%s", bookauthors[bookcount]);

    able[bookcount] = 0;
    bookcount++;

    printf("Book added successfully\n");
}

void display() {
    if (bookcount == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\nAvailable books:\n");
    int availableBooks = 0;
    for (int i = 0; i < bookcount; i++) {
        if (able[i] == 0) {
            printf("Title: %s\n", booktitles[i]);
            printf("Author: %s\n", bookauthors[i]);
            availableBooks++;
        }
    }

    if (availableBooks == 0) {
        printf("No books available to borrow.\n");
    }
}

void borrow() {
    if (bookcount == 0) {
        printf("No books available to borrow.\n");
        return;
    }

    char title[20];
    printf("Enter the title of the book to borrow: ");
    scanf("%s", title);

    for (int i = 0; i < bookcount; i++) {
        if (strcmp(booktitles[i], title) == 0) {
            if (able[i] == 1) {
                printf("The book '%s' is already borrowed.\n", booktitles[i]);
                return;
            }
            able[i] = 1;
            printf("You have borrowed the book '%s'.\n", booktitles[i]);
            return;
        }
    }

    printf("Book with title '%s' not found.\n", title);
}

void returnbook() {
    if (bookcount == 0) {
        printf("Please add a book first. No books are available in the library.\n");
        return;
    }

    int borrowedBooks = 0;
    for (int i = 0; i < bookcount; i++) {
        if (able[i] == 1) {
            borrowedBooks = 1;
            break;
        }
    }

    if (!borrowedBooks) {
        printf("No book is borrowed to return.\n");
        return;
    }

    char title[20];
    printf("Enter the title of the book to return: ");
    scanf("%s", title);

    for (int i = 0; i < bookcount; i++) {
        if (strcmp(booktitles[i], title) == 0) {
            if (able[i] == 0) {
                printf("The book '%s' is already available in the library.\n", booktitles[i]);
                return;
            }
            able[i] = 0;
            printf("You have successfully returned the book '%s'.\n", booktitles[i]);
            return;
        }
    }

    printf("Book with title '%s' not found.\n", title);
}

void searchbookbytitle() {
    if (bookcount == 0) {
        printf("No books are available.\n");
        return;
    }

    char title[20];
    printf("Enter title to search: ");
    scanf("%s", title);

    printf("Search results:\n");
    int found = 0;
    for (int i = 0; i < bookcount; i++) {
        if (strncmp(booktitles[i], title, 3) == 0) {
            printf("Title: %s, Author: %s, Status: %s\n", booktitles[i],
                   bookauthors[i], able[i] == 0 ? "available" : "borrowed");
            found = 1;
        }
    }

    if (!found) {
        printf("No book found matching the title '%s'.\n", title);
    }
}

void searchbookbyauthor() {
    if (bookcount == 0) {
        printf("No books are available.\n");
        return;
    }

    char author[20];
    printf("Enter author name to search: ");
    scanf("%s", author);

    printf("Search results:\n");
    int found = 0;
    for (int i = 0; i < bookcount; i++) {
        if (strncmp(bookauthors[i], author, 3) == 0) {
            printf("Title: %s, Author: %s, Status: %s\n", booktitles[i],
                   bookauthors[i], able[i] == 0 ? "available" : "borrowed");
            found = 1;
        }
    }

    if (!found) {
        printf("No book found matching the author '%s'.\n", author);
    }
}
