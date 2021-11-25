#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUM(x, y) ((x) + (y))

struct Book {
	int number;
	char title[100];
};

int main() {
	struct Book* book;
	book = (struct Book*)malloc(2 * sizeof(struct Book));

	book[0].number = SUM(5, 10);
	strcpy(book[0].title, "C Programming");

	book[1].number = 2;
	strcpy(book[1].title, "°¢Æø ¿¬½À");

	free(book);
}