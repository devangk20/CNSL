#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
std::string removeSpaces(const std::string& text) {
std::string result;
for (char ch : text) {
if (ch != ' ') {
result += ch;
}
}
return result;
}
std::string encrypt(std::string text, std::string key) {
int keyLength = key.size();
int textLength = text.size();
text = removeSpaces(text);
int rows = textLength / keyLength;
if (textLength % keyLength != 0) {
rows++;
}
std::vector<std::vector<char>> table(rows, std::vector<char>(keyLength, 'X'));
int index = 0;
for (int r = 0; r < rows; r++) {
for (int c = 0; c < keyLength; c++) {
if (index < textLength) {
table[r][c] = text[index++];
}
}
}
std::vector<int> order(keyLength);
for (int i = 0; i < keyLength; i++) {
order[i] = i;
}
std::sort(order.begin(), order.end(), [&key](int i, int j) {
return key[i] < key[j];
});
std::string encryptedText;
for (int col : order) {
for (int row = 0; row < rows; row++) {
encryptedText += table[row][col];
}
}
return encryptedText;
}
std::string decrypt(std::string encryptedText, std::string key) {
int keyLength = key.size();
int textLength = encryptedText.size();
int rows = textLength / keyLength;
std::vector<std::vector<char>> table(rows, std::vector<char>(keyLength));
std::vector<int> order(keyLength);
for (int i = 0; i < keyLength; i++) {
order[i] = i;
}
std::sort(order.begin(), order.end(), [&key](int i, int j) {
return key[i] < key[j];
});
int index = 0;
for (int col : order) {
for (int row = 0; row < rows; row++) {
table[row][col] = encryptedText[index++];
}
}
std::string decryptedText;
for (int r = 0; r < rows; r++) {
for (int c = 0; c < keyLength; c++) {
decryptedText += table[r][c];
}
}
return decryptedText;
}
int main() {
std::string text, key;
std::cout << "Enter the text to encrypt: ";
std::getline(std::cin, text);
std::cout << "Enter the key: ";
std::getline(std::cin, key);
std::string encryptedText = encrypt(text, key);
std::cout << "Encrypted Text: " << encryptedText << std::endl;
std::string decryptedText = decrypt(encryptedText, key);
std::cout << "Decrypted Text: " << decryptedText << std::endl;
return 0;
}