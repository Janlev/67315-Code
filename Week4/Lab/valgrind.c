nan#include <stdlib.h>
#include <stdio.h>

int example1() {
  char *x = malloc(100);
  return 0;
}

int example2(char* str_index) {
  int index = atoi(str_index);
  char *x = malloc(10);
  x[index] = 'f';
  free(x);
  return 0;
}

int example3() {
  int x;
  if (x == 0) {
    printf("x is zero.");
  }
  return 0;
}

int example4() {
  char str[10];
  char x = str[11];
  str[20] = 'f';
  return 0;
}

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	char *param = "20";
	switch (n)
	{
		case 1:
			// Example 1 – Invalid read
			example1();
			break;
		case 2:
		  // Example 2 – Invalid write
		  example2(param);
		  break;
		case 3:
			  // Example 3 – Memory leak
			  example3();
			  break;
		case 4:
		  // Example 4 – Segmentation Failure
		  example4();
		  break;
	}
  return 0;
}