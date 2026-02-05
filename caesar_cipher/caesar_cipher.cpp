#include <bits/stdc++.h>

using namespace std;

string encrypt(string plain_text, int shift){
    string res = "";
    for(auto it: plain_text){
        res += ('a' + (it - 'a' + shift) % 26);
    }
    return res;
}

string decrypt(string cipher, int shift){
    string res = "";
    for(auto it: cipher){
        res += ('a' + ((it - 'a' - shift) > 0 ? (it - 'a' - shift) : 26 + (it - 'a' - shift)) % 26);
    } 
    return res;
}

int main(){
    string plain_text = "";
    int shift;
    cin >> plain_text;
    cin >> shift;
    string cipher = encrypt(plain_text, shift);    
    cout << cipher << endl;
    cout << decrypt(cipher, shift);
}