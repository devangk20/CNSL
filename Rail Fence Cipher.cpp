#include <iostream>
#include <vector>
using namespace std;
string encryptRailFence(string text, int key) {
vector<string> rail(key);
int dir_down = false;
int row = 0;
for (int i = 0; i < text.length(); i++) {
rail[row] += text[i];
if (row == 0 || row == key - 1) {
dir_down = !dir_down;
}
row += dir_down ? 1 : -1;
}
string result;
for (int i = 0; i < key; i++) {
result += rail[i];
}
return result;
}
string decryptRailFence(string cipher, int key) {
vector<string> rail(key);
vector<int> pos(key, 0);
int len = cipher.length();
int dir_down = false;
int row = 0;
for (int i = 0; i < len; i++) {
pos[row]++;
if (row == 0 || row == key - 1) {
dir_down = !dir_down;
}
row += dir_down ? 1 : -1;
}
int index = 0;
for (int i = 0; i < key; i++) {
rail[i] = cipher.substr(index, pos[i]);
index += pos[i];
}
string result;
row = 0;
dir_down = false;
vector<int> currentPos(key, 0);
for (int i = 0; i < len; i++) {
result += rail[row][currentPos[row]++];
if (row == 0 || row == key - 1) {
dir_down = !dir_down;
}
row += dir_down ? 1 : -1;
}
return result;
}
int main() {
string text;
int key;
cout << "Enter the text to be encrypted: ";
cin >> text;
cout << "Enter the key (number of rails): ";
cin>>key;
string encryptedText = encryptRailFence(text, key);
cout << "Encrypted Text: " << encryptedText << endl;
string decryptedText = decryptRailFence(encryptedText, key);
cout << "Decrypted Text: " << decryptedText << endl;
return 0;
}