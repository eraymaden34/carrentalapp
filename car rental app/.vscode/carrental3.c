#include <stdio.h>

// Rental information
int rentalID = 0;
char customerName[50];
char carModel[50];
int isActive = 0; // 1 if active, 0 if cancelled

void rentCar() {
    if (isActive) {
        printf("A car is already rented. Please cancel it first.\n");
        return;
    }
    rentalID++;
    printf("Enter customer name: ");
    scanf(" %[^\n]%*c", customerName);
    printf("Enter car model: ");
    scanf(" %[^\n]%*c", carModel);
    isActive = 1;
    printf("Car rented successfully! Rental ID: %d\n", rentalID);
}

void cancelRental() {
    if (!isActive) {
        printf("No active rental to cancel.\n");
        return;
    }
    isActive = 0;
    printf("Rental ID %d has been cancelled.\n", rentalID);
}

void viewRental() {
    if (rentalID == 0) {
        printf("No rental history available.\n");
        return;
    }
    printf("Rental ID: %d\nCustomer Name: %s\nCar Model: %s\nStatus: %s\n",
           rentalID, customerName, carModel, isActive ? "Active" : "Cancelled");
}

int main() {
    int choice;
    while (1) {
        printf("\nCar Rental Operations:\n");
        printf("1. Rent a car\n2. Cancel rental\n3. View rental\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            rentCar();
        else if (choice == 2)
            cancelRental();
        else if (choice == 3)
            viewRental();
        else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } else
            printf("Invalid choice. Try again.\n");
    }
    return 0;
}