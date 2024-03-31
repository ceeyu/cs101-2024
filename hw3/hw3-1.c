#include <stdio.h>

void replace_all(char *str, char oldChar, char newChar) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == oldChar) {
      str[i] = newChar;
    }
  }
}

int main() {
  char str[100], oldChar = 'a', newChar = 'A';

  printf("Enter any string: ");
  scanf("%s", str);

  printf("\nString before replacing: \n%s", str);
  replace_all(str, oldChar, newChar);
  printf("\n\nString after replacing %c with %c : \n%s",oldChar,newChar,str);
  return 0;
}
