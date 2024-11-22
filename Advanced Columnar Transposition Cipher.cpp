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
std::vector<int> getColumnOrder(const std::string& key) {
std::vector<int> order(key.size());
std::vector<std::pair<char, int>> keyOrder;
for (int i = 0; i < key.size(); i++) {
keyOrder.push_back(std::make_pair(key[i], i));
}
std::sort(keyOrder.begin(), keyOrder.end());
for (int i = 0; i < keyOrder.size(); i++) {
order[keyOrder[i].second] = i;
}
return order;
}
std::string encrypt(std::string text, std::string key) {
text = removeSpaces(text);
int textLength = text.size();
int keyLength = key.size();
int rows = textLength / keyLength + (textLength % keyLength ? 1 : 0);
std::vector<std::vector<char>> table(rows, std::vector<char>(keyLength, 'X'));
int index = 0;
for (int r = 0; r < rows; r++) {
for (int c = 0; c < keyLength; c++) {
if (index < textLength) {
table[r][c] = text[index++]; }
}
}
std::vector<int> columnOrder = getColumnOrder(key);
std::string encryptedText;
for (int col : columnOrder) {
for (int r = 0; r < rows; r++) {
encryptedText += table[r][col];
}
}
return encryptedText;
}
std::string decrypt(std::string encryptedText, std::string key) {
int textLength = encryptedText.size();
int keyLength = key.size();
int rows = textLength / keyLength;
std::vector<std::vector<char>> table(rows, std::vector<char>(keyLength));
std::vector<int> columnOrder = getColumnOrder(key);
int index = 0;
for (int col : columnOrder) {
for (int r = 0; r < rows; r++) {
table[r][col] = encryptedText[index++];
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