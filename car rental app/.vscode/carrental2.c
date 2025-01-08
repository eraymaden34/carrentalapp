#include <stdio.h>

void viewAvailableCars() {
    printf("\nAvailable Cars:\n");
    printf("1. Toyota Corolla\n");
    printf("2. Honda Civic\n");
    printf("3. Ford Focus\n");
    printf("4. BMW 3 Series\n");
}

void carDetails() {
    int choice;
    printf("\nEnter the number of the car to see details: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nCar: Toyota Corolla\nType: Sedan\nTransmission: Automatic\nPrice per day: $50\n");
    } else if (choice == 2) {
        printf("\nCar: Honda Civic\nType: Sedan\nTransmission: Manual\nPrice per day: $45\n");
    } else if (choice == 3) {
        printf("\nCar: Ford Focus\nType: Hatchback\nTransmission: Automatic\nPrice per day: $40\n");
    } else if (choice == 4) {
        printf("\nCar: BMW 3 Series\nType: Sedan\nTransmission: Automatic\nPrice per day: $100\n");
    } else {
        printf("Invalid choice! Please try again.\n");
    }
}

void priceInformation() {
    int choice, days;
    printf("\nEnter the number of the car to calculate rental price: ");
    scanf("%d", &choice);

    printf("Enter the number of days you want to rent: ");
    scanf("%d", &days);

    if (days > 0) {
        if (choice == 1) {
            printf("\nTotal price: $%d\n", days * 50);
        } else if (choice == 2) {
            printf("\nTotal price: $%d\n", days * 45);
        } else if (choice == 3) {
            printf("\nTotal price: $%d\n", days * 40);
        } else if (choice == 4) {
            printf("\nTotal price: $%d\n", days * 100);
        } else {
            printf("Invalid car choice!\n");
        }
    } else {
        printf("Invalid number of days!\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nCar Rental System\n");
        printf("1. View Available Cars\n");
        printf("2. Car Details\n");
        printf("3. Price Information\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            viewAvailableCars();
        } else if (choice == 2) {
            carDetails();
        } else if (choice == 3) {
            priceInformation();
        } else if (choice == 4) {
            printf("Exiting the system. Goodbye!\n");
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}