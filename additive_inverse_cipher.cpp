#include <iostream>
#include <cctype>
// For isalpha and isupper
using namespace std;

string additiveInverseEncrypt(const string &plaintext, int key);

int main()
{
    string plaintext;
    int key;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key (an integer): ";
    cin >> key;

    string ciphertext = additiveInverseEncrypt(plaintext, key);

    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}

// Function to perform Additive Inverse Encryption
string additiveInverseEncrypt(const string &plaintext, int key)
{
    string ciphertext = "";
    for (char ch : plaintext)
    {
        if (isalpha(ch))
        {
            char base = isupper(ch) ? 'A' : 'a';
            char encryptedChar = (ch - base + key + 26) % 26 + base;
            ciphertext += encryptedChar;
        }
        else
        {
            ciphertext += ch; 
            // Preserve non-alphabetic characters
        }
    }
    return ciphertext;
}
