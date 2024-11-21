#include <stdio.h>
#include <string.h>

char booktitle[20];
char bookauthor[20];
int able =0 ;


void addbook();
void display();
void issue();
void returnbook();
//void searchbookbytitle();
//void searchbookbyauthor();
int main()
{
    int choice;
    do
    {
        printf("\n*****LIBRARY MANAGEMENT SYSTEM*****\n");
        printf("1 add new book \n");
        printf("2 display  available books  \n");
        printf("3  issue books\n");
        printf("4 return book \n");
        printf("5 search book by title \n");
        printf("6 search book by author \n");
        printf("0 exit program \n");
        printf("enter your choice:");
        scanf("%d", &choice);
        getchar();

        switch (choice){
        case 1:
            addbook();
            break;
        case 2:
            display();
            break;
        case 3:
            issue();
            break;
        case 4:
            returnbook();
            break;
        /*case 5:
            searchbookbytitle();
            break;
        case 6:
            searchbookbyauthor();
            break; */
        case 0:
            printf("Exit the program \n");
            break;
        default:
            printf("invalid choice try again \n");
        }
    } while (choice != 0);
    return 0;
}
void addbook()
{
    printf("enter the book title: ");
    gets(booktitle);

    printf("enter the author name: ");
    gets(bookauthor);

    able =0;
    printf("book added successfully \n");
}
void display()
{
    if (strlen(booktitle)==0){
        printf("no book is available \n");
        return;
    }
    printf("\n book details:\n");
    printf("Title: %s\n", booktitle);
    printf("Author: %s\n", bookauthor);
    printf("Status: %s\n", able == 0 ? "Available" : "Issued");

}
void issue()
{
    
    if (strlen(booktitle) == 0) {
        printf("No book is available to issue.\n");
        return;
    }

    if (able == 1) {
        printf("The book '%s' is already issued.\n", booktitle);
        return;
    }

    able = 1; 
    printf("You have issued the book '%s'.\n", booktitle);

}

void returnbook(){
    if (strlen(booktitle) == 0) {
        printf("No book is available to return.\n");
        return;
    }

    if (able == 0) {
        printf("The book '%s' is already available.\n", booktitle);
        return;
    }

    able = 0; // Mark as available
    printf("You have returned the book '%s'.\n", booktitle);

    }

// void searchbookbytitle()
// {
   // char title[20];
   // printf("enter title to search \n");
   // scanf("%s", &title);
//
   // printf("search books result: \n");
   // for (int i = 0; i < bookcount; i++)
   // {
    //    if(strstr(booktitle[i], title))
    //    {
    //        printf("NO: %d, Title %s, author %s, status:%s \n", i=1, booktitle[i], bookauthor[i], able[i]==0 ? "available" :"issued" );
    //    }
    //}
//}


