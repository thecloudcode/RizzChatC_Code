#include <stdio.h>
#include <string.h>

#define HASH_TABLE_SIZE 100

struct UserInfo {
    char phoneNumber[15];
    char name[50];
    int age;
};

unsigned int hash(char *phoneNumber) {
    unsigned int hashValue = 0;
    for (int i = 0; phoneNumber[i] != '\0'; i++) {
        hashValue += phoneNumber[i];
    }
    return hashValue % HASH_TABLE_SIZE;
}

int main() {
    struct UserInfo userDatabase[HASH_TABLE_SIZE];
    int numUsers;

    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        strcpy(userDatabase[i].phoneNumber, "");
    }

    printf("Enter the number of users: ");
    scanf("%d", &numUsers);

    for (int i = 0; i < numUsers; i++) {
        printf("Enter user details for user #%d:\n", i + 1);
        printf("Phone Number: ");
        scanf("%s", userDatabase[i].phoneNumber);
        printf("Name: ");
        scanf("%s", userDatabase[i].name);
        printf("Age: ");
        scanf("%d", &userDatabase[i].age);

        unsigned int index = hash(userDatabase[i].phoneNumber);
        strcpy(userDatabase[index].phoneNumber, userDatabase[i].phoneNumber);
        strcpy(userDatabase[index].name, userDatabase[i].name);
        userDatabase[index].age = userDatabase[i].age;
    }

    char searchPhoneNumber[15];
    printf("Enter a phone number to search for user details: ");
    scanf("%s", searchPhoneNumber);

    unsigned int searchIndex = hash(searchPhoneNumber);

    if (strcmp(userDatabase[searchIndex].phoneNumber, searchPhoneNumber) == 0) {
        printf("User Found:\n");
        printf("Phone Number: %s\n", userDatabase[searchIndex].phoneNumber);
        printf("Name: %s\n", userDatabase[searchIndex].name);
        printf("Age: %d\n", userDatabase[searchIndex].age);
    } else {
        printf("User not found for phone number %s\n", searchPhoneNumber);
    }

    return 0;
}
