#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PHONE_NUMBERS 100
#define MAX_PHONE_NUMBER_LENGTH 20

bool isSubsequence(char *str, char *text) {
    int strLen = strlen(str);
    int textLen = strlen(text);
    int i = 0, j = 0;
    
    while (i < strLen && j < textLen) {
        if (str[i] == text[j]) {
            i++;
        }
        j++;
    }
    
    return (i == strLen);
}

void findPhoneNumbers(char *search, char phoneNumbers[][MAX_PHONE_NUMBER_LENGTH], int numPhoneNumbers) {
    printf("Phone numbers with '%s' as a subsequence:\n", search);
    
    for (int i = 0; i < numPhoneNumbers; i++) {
        if (isSubsequence(search, phoneNumbers[i])) {
            printf("%s\n", phoneNumbers[i]);
        }
    }
}

int main() {
    int numPhoneNumbers;
    char phoneNumbers[MAX_PHONE_NUMBERS][MAX_PHONE_NUMBER_LENGTH];
    char search[MAX_PHONE_NUMBER_LENGTH];
    
    printf("Enter the number of phone numbers: ");
    scanf("%d", &numPhoneNumbers);
    
    printf("Enter the phone numbers:\n");
    for (int i = 0; i < numPhoneNumbers; i++) {
        scanf("%s", phoneNumbers[i]);
    }
    
    printf("Enter the search input: ");
    scanf("%s", search);
    
    findPhoneNumbers(search, phoneNumbers, numPhoneNumbers);
    
    return 0;
}
