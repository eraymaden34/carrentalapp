#include <stdio.h>

#define MAX 4

struct User { int id; char name[50]; } users[MAX];
struct Car { int id; char brand[50]; int available; } cars[MAX];
int userCount = 0, carCount = 0;

void addUser() {
    if (userCount < MAX) {
        printf("User ID: "); scanf("%d", &users[userCount].id);
        printf("User Name: "); scanf("%s", users[userCount++].name);
        printf("User added.\n");
    } else printf("User limit reached.\n");
}

void addCar() {
    if (carCount < MAX) {
        printf("Car ID: "); scanf("%d", &cars[carCount].id);
        printf("Car Brand: "); scanf("%s", cars[carCount].brand);
        cars[carCount++].available = 1;
        printf("Car added.\n");
    } else printf("Car limit reached.\n");
}

void listUsers() {
    for (int i = 0; i < userCount; i++)
        printf("User ID: %d, Name: %s\n", users[i].id, users[i].name);
}

void listCars() {
    for (int i = 0; i < carCount; i++)
        printf("Car ID: %d, Brand: %s, Status: %s\n",
               cars[i].id, cars[i].brand, cars[i].available ? "Available" : "Rented");
}

int main() {
    int choice;
    do {
        printf("\n1. Add User\n2. Add Car\n3. List Users\n4. List Cars\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) addUser();
        else if (choice == 2) addCar();
        else if (choice == 3) listUsers();
        else if (choice == 4) listCars();
    } while (choice != 5);
    return 0;
}