#include <stdio.h>
#include <string.h>

char booktitle[20];
char bookauthor[20];
int able[5];
int bookcount = 0;

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
        printf("*****LIBRARY MANAGEMENT SYSTEM*****\n");
        printf("1 add new book \n");
        printf("2 display  available books  \n");
        printf("3  issue books\n");
        printf("4 return book \n");
        printf("5 search book by title \n");
        printf("6 search book by author \n");
        printf("0 exit program \n");
        scanf("%d", &choice);

        switch (choice)
        {
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
            printf("Exit the program");
            break;
        default:
            printf("invalid choice try again");
        }
    } while (choice != 0);
    return 0;
}
void addbook()
{
    if (bookcount >= 5)
    {
        printf("library is full ");
        return;
    }

    printf("Enter the book title: ");
    scanf("%s", booktitle[bookcount]);
    printf("Enter the book author: ");
    scanf("%s", bookauthor[bookcount]);

    able[bookcount] = 0;
    bookcount++;

    printf("book addedsucessfully \n");
}
void display()
{
    printf(" Available books are: \n");
    for (int i = 0; i < bookcount; i++)
    {
        if (able[i] == 0)
        {
            printf("NO: %d \n, booktitle: '%s'\n, bookauthor: '%s' \n", i + 1, booktitle[i], bookauthor[i]);
        }
    }
}
void issue()
{
    if (bookcount == 0)
    {
        printf("NO books are available \n");
        return;
    }
    display();
    printf(" enter the NO of book for issue book:");
    int bookno;
    scanf("%d", bookno);

    able[bookno - 1] = 1;
    printf("book issue successfully '%s' \n");
    booktitle[bookno - 1];
}

void returnbook()
{
    printf("issue book:\n");
    for (int i = 0; i < bookcount; i++)
    {
        printf("NO: %d \n, booktitle: '%s'\n, bookauthor: '%s' \n", i + 1, booktitle[i], bookauthor[i]);
    }
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


