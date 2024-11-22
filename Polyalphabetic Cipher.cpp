#include <iostream>
#include <string>
using namespace std;
string generateKey(string str, string key) {
int x = str.size();
for (int i = 0; ; i++) {
if (key.size() == str.size())
break;
key.push_back(key[i % key.size()]);
}
return key;
}
string encrypt(string str, string key) {
string cipher_text;
for (int i = 0; i < str.size(); i++) {
char x = (str[i] + key[i]) % 26;
x += 'A';
cipher_text.push_back(x);
}
return cipher_text;
}
string decrypt(string cipher_text, string key) {
string orig_text;
for (int i = 0; i < cipher_text.size(); i++) {
char x = (cipher_text[i] - key[i] + 26) % 26;
x += 'A';
orig_text.push_back(x);
}
return orig_text;
}
int main() {
string str;
string keyword;
cout << "Enter the plaintext (A-Z only): ";
cin >> str;
cout << "Enter the keyword: ";
cin >> keyword;
for (int i = 0; i < str.length(); i++)
str[i] = toupper(str[i]);
for (int i = 0; i < keyword.length(); i++)
keyword[i] = toupper(keyword[i]);
string key = generateKey(str, keyword);
string cipher_text = encrypt(str, key);
string decrypted_text = decrypt(cipher_text, key);
cout << "Ciphertext: " << cipher_text << endl;
cout << "Decrypted text: " << decrypted_text << endl;
return 0;
}