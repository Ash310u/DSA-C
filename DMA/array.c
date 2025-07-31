#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
}Person;

void printPerson(Person *arr, int n);
void makePerson(Person *arr, int n);

int main() {
    int n;
    printf("Enter the Size of the array: ");
    scanf("%d", &n);
    printf("-----------------------------\n");

    Person *ptr = (Person *)malloc(n * sizeof(Person));
    makePerson(ptr,n);

    printf("--------------Result-------------\n");
    printPerson(ptr, n);

    free(ptr);
    return 0;
}

void printPerson(Person *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("Person %d\n", i+1);
        printf("Name: %s", arr[i].name);
        printf("Age: %d\n", arr[i].age);
    }
}

void makePerson(Person *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("Person %d\n", i+1);
        getchar();
        
        printf("Enter the name: ");
        fgets(arr[i].name, sizeof(arr[i].name), stdin);
        
        printf("Enter the age: ");
        scanf("%d", &arr[i].age);
    }
}