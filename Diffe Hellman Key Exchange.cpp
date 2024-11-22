#include <iostream>
#include <cmath>
using namespace std;
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
int main() {
long long p;
long long g;
cout << "Enter a prime number (p): ";
cin >> p;
cout << "Enter a primitive root modulo p (g): ";
cin >> g;
long long a, b;
cout << "Enter Alice's private key (a): ";
cin >> a;
cout << "Enter Bob's private key (b): ";
cin >> b;
long long A = modExpo(g, a, p);
long long B = modExpo(g, b, p);
long long s1 = modExpo(B, a, p);
long long s2 = modExpo(A, b, p);
cout << "Shared secret calculated by Alice: " << s1 << endl;
cout << "Shared secret calculated by Bob: " << s2 << endl;
if (s1 == s2) {
cout << "Key exchange successful! Shared secret: " << s1 << endl;
} else {
cout << "Key exchange failed." << endl;
}
return 0;
}