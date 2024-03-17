#include <stdio.h>

#define MAX_BOOKS 10

typedef struct Books {
  int id;
  int price;
  char title[100];
} book_t;

int total_price(const book_t *books, int count) {
  int total = 0;

  for (int i = 0; i < count; ++i) {
    if (books[i].price < 0) {
      printf("Error: The price of book %d is negative.\n", i + 1);
      return -1;
    }
    total += books[i].price;
  }

  return total;
}

void list_book(const book_t *books, int count, int id) {
  for (int i = 0; i < count; ++i) {
    if (books[i].id == id) {
      printf("%d %s\n", books[i].price, books[i].title);
      return;
    }
  }
  printf("Book with id %d not found.\n", id);
}

int main() {
  // Define the books
  book_t books[] = {
    {1, 1000, "All the Light We Cannot See"},
    {2, 300, "The 38 Letters from J.D. Rockefeller to his son"},
    {3, 1000, "The Ballad of Songbirds and Snakes"},
    {4, 550, "Killers of the Flower Moon"},
    {5, 870, "Elon Musk"},
    {6,1344, "Milk and Honey 12-Month 2024"},
  };

  int n;

  // Prompt the user to enter a number
  //printf("Enter a number (0 to calculate total price, 1 to 6 to list book by ID): ");
  scanf("%d", &n);

  // Check the number
  if (n < 0 || n > 6) {
    printf("Error: The number must be between 0 and 6.\n");
    return 1;
  }

  // Call the total_price() function
  if (n == 0) {
    int total = total_price(books, sizeof(books) / sizeof(books[0]));

    // Check the total price
    if (total < 0) {
      return 1;
    }

    // Print the total price
    printf("%d\n", total);
  }

  // Call the list_book() function
  if (n > 0 && n <= 6) {
    list_book(books, sizeof(books) / sizeof(books[0]), n);
  }

  return 0;
}
