#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
string formatText(string text) {
string formattedText = "";
for (int i = 0; i < text.length(); i++) {
if (isalpha(text[i])) {
formattedText += toupper(text[i]);
}
}
for (int i = 0; i < formattedText.length() - 1; i += 2) {
if (formattedText[i] == formattedText[i + 1]) {
formattedText.insert(i + 1, "X");
}
}
if (formattedText.length() % 2 != 0) {
formattedText += 'X';
}
return formattedText;
}
void generateKeyMatrix(string key, char keyMatrix[5][5]) {
bool lettersPresent[26] = { false };
int k = 0;
for (int i = 0; i < key.length(); i++) {
if (key[i] == 'J') {
key[i] = 'I';
}
if (!lettersPresent[key[i] - 'A']) {
keyMatrix[k / 5][k % 5] = key[i];
lettersPresent[key[i] - 'A'] = true;
k++;
}
}
for (char ch = 'A'; ch <= 'Z'; ch++) {
if (ch == 'J') continue;
if (!lettersPresent[ch - 'A']) {
keyMatrix[k / 5][k % 5] = ch;
lettersPresent[ch - 'A'] = true;
k++;
}
}
}
void findPosition(char ch, char keyMatrix[5][5], int &row, int &col) {
if (ch == 'J') {
ch = 'I';
}
for (int i = 0; i < 5; i++) {
for (int j = 0; j < 5; j++) {
if (keyMatrix[i][j] == ch) {
row = i;
col = j;
return;
}
} }}
string encrypt(string text, char keyMatrix[5][5]) {
string cipherText = "";
for (int i = 0; i < text.length(); i += 2) {
int row1, col1, row2, col2;
findPosition(text[i], keyMatrix, row1, col1);
findPosition(text[i + 1], keyMatrix, row2, col2);
if (row1 == row2) {
cipherText += keyMatrix[row1][(col1 + 1) % 5];
cipherText += keyMatrix[row2][(col2 + 1) % 5];
}
else if (col1 == col2) {
cipherText += keyMatrix[(row1 + 1) % 5][col1];
cipherText += keyMatrix[(row2 + 1) % 5][col2];
}
else {
cipherText += keyMatrix[row1][col2];
cipherText += keyMatrix[row2][col1];
}
}
return cipherText;
}
string decrypt(string cipherText, char keyMatrix[5][5]) {
string plainText = "";
for (int i = 0; i < cipherText.length(); i += 2) {
int row1, col1, row2, col2;
findPosition(cipherText[i], keyMatrix, row1, col1);
findPosition(cipherText[i + 1], keyMatrix, row2, col2);
if (row1 == row2) {
plainText += keyMatrix[row1][(col1 + 4) % 5];
plainText += keyMatrix[row2][(col2 + 4) % 5];
}
else if (col1 == col2) {
plainText += keyMatrix[(row1 + 4) % 5][col1];
plainText += keyMatrix[(row2 + 4) % 5][col2];
}
else {
plainText += keyMatrix[row1][col2];
plainText += keyMatrix[row2][col1];
}
}
return plainText;
}
int main() {
string text, key;
char keyMatrix[5][5];
cout << "Enter the key: ";
cin >> key;
cout << "Enter the text to encrypt: ";
cin >> text;
text = formatText(text);
generateKeyMatrix(key, keyMatrix);
string encryptedText = encrypt(text, keyMatrix);
cout << "Encrypted Text: " << encryptedText << endl;
string decryptedText = decrypt(encryptedText, keyMatrix);
cout << "Decrypted Text: " << decryptedText << endl;
return 0;
}