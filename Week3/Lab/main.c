#include <stdio.h>
#include <stdlib.h>

# define ALLOC_SIZE 10
# define MAX_LINE_LEN 19


typedef struct Triangle {
    int a, b, c;
} Triangle;


int main() {
    int a = 0, b = 0, c = 0;
    char some_str[MAX_LINE_LEN];
    int counter = 0;
    int capacity = ALLOC_SIZE;
    int sum = 0;

    Triangle *data = (Triangle*) malloc(capacity * sizeof(Triangle));

    if (data == NULL) {
        return 0;
    }

    while (fgets(some_str, MAX_LINE_LEN, stdin) != NULL) {
        sscanf(some_str, "%d %d %d", &a, &b, &c);
        data[counter].a = a;
        data[counter].b = b;
        data[counter].c = c;

        sum += a + b + c;
        counter++;

        if (counter == capacity) {
            capacity += ALLOC_SIZE;
            data = (Triangle *) realloc(data, capacity * sizeof(struct Triangle));
        }
    }
    for (int i = counter -1; i >= 0; --i) {
        printf("%d %d %d\n", data[i].a, data[i].b, data[i].c);
    }
    printf("sum = %d", sum);
    free(data);

    return 0;
}
