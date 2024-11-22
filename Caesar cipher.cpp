#include <iostream>
#include <string>
using namespace std;
string encrypt(string text, int shift) {
string result = "";
for (int i = 0; i < text.length(); i++) {
if (isupper(text[i])) {
result += char(int(text[i] + shift - 65) % 26 + 65);
}
else if (islower(text[i])) {
result += char(int(text[i] + shift - 97) % 26 + 97);
}
else {
result += text[i];
}
}
return result;
}
string decrypt(string text, int shift) {
return encrypt(text, 26 - shift);
}
int main() {
string text;
int shift;
cout << "Enter the plaintext: ";
getline(cin, text);
cout << "Enter the shift value: ";
cin >> shift;
string encryptedText = encrypt(text, shift);
cout << "Encrypted Text: " << encryptedText << endl;
string decryptedText = decrypt(encryptedText, shift);
cout << "Decrypted Text: " << decryptedText << endl;
return 0;
}