#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
}Person;

int main() {
    int n;
    printf("Enter the Size of the array: ");
    scanf("%d", &n);
    printf("-----------------------------\n");

    Person *ptr = (Person *)malloc(n * sizeof(Person));

    for(int i = 0; i < n; i++) {
        printf("Person %d\n", i+1);
        getchar();
        
        printf("Enter the name: ");
        fgets(ptr[i].name, sizeof(ptr[i].name), stdin);
        
        printf("Enter the age: ");
        scanf("%d", &ptr[i].age);
        printf("-----------------------------\n");
    }

    printf("--------------Result-------------\n");

    
    for(int i = 0; i < n; i++) {
        printf("Enter the name: %s", ptr[i].name);
        printf("Enter the age: %d\n", ptr[i].age);
    }

    free(ptr);
    return 0;
}