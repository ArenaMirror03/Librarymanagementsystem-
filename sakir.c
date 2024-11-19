#include <stdio.h>

void library();

char aadbook[5], available[20], borrow[5], returnbooks[5], title[20], author[20];

int main()
{
    library();
}
void library()
{

    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. Display All Books\n");
    printf("3. Search Book\n");
    printf("4. Issue Book\n");
    printf("5. Return Book\n");
    printf("6. Exit\n");
    printf("Enter your choice:\n");

    printf("Enter the book:\n");
    scanf("%s", &aadbook);
    printf("The books are available\n");
    scanf("%S", &available);
    printf(" The books are borrow: \n");
    scanf("%s", &borrow);
    printf("The book is return:\n");
    scanf("%s", &returnbooks);
    printf("Search by title:\n");
    scanf("%s", &title);
    printf("Search by author:\n");
    scanf("%s", &author);

    return 0;
}