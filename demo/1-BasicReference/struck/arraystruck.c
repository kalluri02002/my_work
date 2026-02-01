#include <stdio.h>

// Define the struct
struct person {
    int id;
    char name[20];
};

// Function to print the struct data
void kall(struct person *p) {
    printf("ID: %d\n", p->id);
    printf("Name: %s\n", p->name);
}

int main() {
    struct person p[3];  // Array of 3 struct person

    // Input loop for the struct array
    for(int i = 0; i < 3; i++) {
        printf("Enter ID and Name for person %d:\n", i + 1);
        scanf("%d", &p[i].id);      // Use &p[i].id for scanf
        scanf("%s", p[i].name);     // No & for array name
    }

    // Output loop to call the function for each struct element
    for(int i = 0; i < 3; i++) {
        kall(&p[i]);
    }

    return 0;
}
