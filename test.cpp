#include <iostream>
#include <fstream>
using namespace std;

void encrypt(char sourceFile[], char encryptedFile[], int shift) {
    ifstream src(sourceFile);
    ofstream enc(encryptedFile);
    char c;
    while (src.get(c)) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
        enc << c;
    }
    src.close();
    enc.close();
}

void decrypt (char encryptedFile[], char decryptedFile[], int shift) {
    ifstream enc(encryptedFile);
    ofstream dec(decryptedFile);
    char c;
    while (enc.get(c)) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base - shift + 26) % 26 + base;
        }
        dec << c;
    }
    enc.close();
    dec.close();
}

int main() {
    encrypt("source.txt", "encrypted.txt", 3);
    decrypt("encrypted.txt", "decrypted.txt", 3);
    return 0;
}

