#include <stdio.h>
#include <string.h>

char booktitles[5][20];
char bookauthors[5][20];
int able[5] = {0, 0, 0, 0, 0}; // to store book
int bookcount = 0;

void addbook();
void display();
void issue();
void returnbook();
// void searchbookbytitle();
// void searchbookbyauthor();
int main() {
  int choice;
  do {
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

    switch (choice) {
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
  int availableBooks = 0;

  if (bookcount == 0) {
    printf("No books available.\n");
    return;
  }

  printf("\nAvailable books:\n");
  for (int i = 0; i < bookcount; i++) {
    if (able[i] == 0) {
      printf("Serial No: %d\n", i + 1);
      printf("Title: %s\n", booktitles[i]);
      printf("Author: %s\n", bookauthors[i]);

      availableBooks++;
    }
  }

  if (availableBooks == 0) {
    printf("No books available for issue.\n");
  }
}

void issue() {
  if (bookcount == 0) {
    printf("No books available to issue.\n");
    return;
  }

  display();
  printf("Enter the Serial No of the book to issue: ");
  int bookno;
  scanf("%d", &bookno);

  if (bookno < 1 || bookno > bookcount) {
    printf("Invalid Serial No.\n");
    return;
  }

  if (able[bookno - 1] == 1) {
    printf("The book '%s' is already issued.\n", booktitles[bookno - 1]);
    return;
  }

  able[bookno - 1] = 1;
  printf("You have issued the book '%s'.\n", booktitles[bookno - 1]);
}
void returnbook() {
  if (bookcount == 0) {
    printf("No books available to return.\n");
    return;
  }

  display();
  printf("Enter the Serial No of the book to return: ");
  int bookno;
  scanf("%d", &bookno);

  if (bookno < 1 || bookno > bookcount) {
    printf("Invalid Serial No.\n");
    return;
  }

  if (able[bookno - 1] == 0) {
    printf("The book '%s' is already available.\n", booktitles[bookno - 1]);
    return;
  }

  able[bookno - 1] = 0;
  printf("You have returned the book '%s'.\n", booktitles[bookno - 1]);
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
//        printf("NO: %d, Title %s, author %s, status:%s \n", i=1, booktitle[i],
//        bookauthor[i], able[i]==0 ? "available" :"issued" );
//    }
//}
//}
