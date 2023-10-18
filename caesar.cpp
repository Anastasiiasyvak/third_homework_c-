
#include <iostream>
#include <cstring>


char* encrypt(char* rawText, int key) __attribute__((visibility("default")));
char* encrypt(char* rawText, int key)
{
    int length = strlen(rawText);
    char* result = new char[length + 1];

    for (int i = 0; i < length; i++) {
        char currentChar = rawText[i];
        if (isupper(currentChar)) {
            currentChar = char(int(currentChar + key));
        } else if (islower(currentChar)) {
            currentChar = char(int(currentChar + key));
        }
        result[i] = currentChar;
    }

    result[length] = '\0';

    return result;
}

char* decrypt(char* encryptedText, int key) __attribute__((visibility("default")));
char* decrypt(char* encryptedText, int key)
{
    int length = strlen(encryptedText);
    char* result = new char[length + 1];

    for (int i = 0; i < length; i++) {
        char currentChar = encryptedText[i];
        if (isupper(currentChar)) {
            currentChar = char(int(currentChar - key));
        } else if (islower(currentChar)) {
            currentChar = char(int(currentChar - key));
        }
        result[i] = currentChar;
    }

    result[length] = '\0';

    return result;
}
