#include <iostream>
#include <cstring>
using namespace std;

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

int main()
{
    char rawText[100];
    int key = 0;
    cout << "Enter the rawText:\n";
    cin.getline(rawText, sizeof(rawText));
    cout << "Enter our key:\n";
    cin >> key;
    cout << "Text : " << rawText;
    cout << "\nKey: " << key;
    char* encryptedText = encrypt(rawText, key);
    cout << "\nCipher text: " << encryptedText;
    delete[] encryptedText;
    return 0;
}
