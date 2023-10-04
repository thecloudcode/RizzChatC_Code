#include <stdio.h>
#include <string.h>

// we have taken max Hash table size as 100
#define HASH_TABLE_SIZE 100 

// taking multiple data types in one struct to store the user data precisely
struct UserInfo {
    char phoneNumber[15];
    char name[50];
    int age;
};

// hashing function : works like 
// if the phone number to be searched starts from 9, it will find all phone numbers starting with 9, it there is only one phone number starting with 9, it returns that
// otherwise, it will find all the phone numbers starting with 9
// then it will look for the next digit after 9 in the phone number to be searched 
// and continue to search the phone number like that
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

    // in the beginning, we make all the phone numbers in userDatabase as ""
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        strcpy(userDatabase[i].phoneNumber, "");
    }

    // we ask the user for the number of users
    printf("Enter the number of users: ");
    scanf("%d", &numUsers);

    // now iterating through all the users we ask for their details as input from the user
    for (int i = 0; i < numUsers; i++) {
        printf("Enter user details for user #%d:\n", i + 1);
        printf("Phone Number: ");
        scanf("%s", userDatabase[i].phoneNumber);
        printf("Name: ");
        scanf("%s", userDatabase[i].name);
        printf("Age: ");
        scanf("%d", &userDatabase[i].age);

        // now, we hash out the index order to place the inputs taken from the user at the very specific places inside the userDatabase in order to perform much easier and faster hashing
        // the code below lies in the part of hashing 
        unsigned int index = hash(userDatabase[i].phoneNumber);
        strcpy(userDatabase[index].phoneNumber, userDatabase[i].phoneNumber);
        strcpy(userDatabase[index].name, userDatabase[i].name);
        userDatabase[index].age = userDatabase[i].age;
    }

    // asking the user for the phone number to be searched
    char searchPhoneNumber[15];
    printf("Enter a phone number to search for user details: ");
    scanf("%s", searchPhoneNumber);

    // temp index
    unsigned int searchIndex = hash(searchPhoneNumber);

    // strcmp will check if both the strings are same or not
    // so we compare all the phone numbers from the phone number which is to be searched
    // if it matches we display the details otherwise no such user found
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
