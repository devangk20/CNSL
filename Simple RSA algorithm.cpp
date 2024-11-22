#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a, int b) {
while (b != 0) {
int temp = b;
b = a % b;
a = temp;
}
return a;
}
long long modExpo(long long base, long long exp, long long mod) {
long long result = 1;
base = base % mod;
while (exp > 0) {
if (exp % 2 == 1) {
result = (result * base) % mod;
}
exp = exp >> 1;
base = (base * base) % mod;
}
return result;
}
int modInverse(int e, int phi) {
for (int d = 1; d < phi; d++) {
if ((e * d) % phi == 1) {
return d;
}
}
return -1;
}
int main() {
int p, q;
cout << "Enter two prime numbers (p and q): ";
cin >> p >> q;
int n = p * q;
int phi = (p - 1) * (q - 1);
int e;
cout << "Enter public key exponent (e) such that gcd(e, " << phi << ") = 1: ";
cin >> e;
while (gcd(e, phi) != 1) {
cout << "Invalid choice for e, try again: ";
cin >> e;
}
int d = modInverse(e, phi);
if (d == -1) {
cout << "No modular inverse found, try different primes." << endl;
return -1;
}
cout << "Public Key: {" << e << ", " << n << "}" << endl;
cout << "Private Key: {" << d << ", " << n << "}" << endl;
long long message;
cout << "Enter the message to be encrypted (as a number): ";
cin >> message;
long long ciphertext = modExpo(message, e, n);
cout << "Encrypted message: " << ciphertext << endl;
long long decryptedMessage = modExpo(ciphertext, d, n);
cout << "Decrypted message: " << decryptedMessage << endl;
return 0;
}