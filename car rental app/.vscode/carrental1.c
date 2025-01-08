#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_LENGTH 50

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }

    char username[MAX_LENGTH], password[MAX_LENGTH];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Check for duplicate username
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("This username is already taken.\n");
            return;
        }
    }

    // Register new user
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;
    printf("Registration successful!\n");
}

void loginUser() {
    char username[MAX_LENGTH], password[MAX_LENGTH];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful! Welcome, %s.\n", username);
            return;
        }
    }

    printf("Invalid username or password.\n");
}

void viewProfile() {
    char username[MAX_LENGTH];
    printf("Enter the username to view the profile: ");
    scanf("%s", username);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username: %s\n", users[i].username);
            printf("Password: %s\n", users[i].password);
            return;
        }
    }

    printf("This user does not exist.\n");
}

int main() {
    int choice;

    do {
        printf("\nCar Rental Application\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. View Profile\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                viewProfile();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
