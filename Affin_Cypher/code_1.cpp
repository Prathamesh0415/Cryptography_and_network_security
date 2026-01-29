#include<bits/stdc++.h>

using namespace std;

//choose a and b yourself also remember a should be a coprime with 26
// a cant be even and a cant be 13
//also a and b are between 0 to 25
const int a  = 3;
//b can be anything less than 25 and it represents the shift
const int b = 7;

const int A = 9; // a^-1

//ENCRYPTION
//Formula is (ax + b) % m
// which becomes (3x + 7) % 26

//DECRYPTION
//in decyption the formula becomes a^-1(x - b) % 26
//This follows the prooperty a^-1*a % 26 == 1 so bascially a^-1 . a == 27
//in this case since a == 3 Therfore a^-1 == 9 since 9 . 3 == 27

string ENCRYPT(string plain_text, vector<char>mapper){
    string temp = "";
    for(int i = 0; i < plain_text.size(); i++){
        temp += mapper[(a * (plain_text[i] - 'a') + b) % 26];
    }
    return temp;
}

string DECRYPT(string encrypt_text, vector<char>mapper){
    string temp = "";
    for(int i = 0; i < encrypt_text.size(); i++){
        temp += mapper[(A * (((encrypt_text[i] - 'a') - b) + 26) % 26)];
    }
    return temp;
}

int main(){
    vector<char>mapper;
    
    for(char i = 'a'; i <= 'z'; i++){
        mapper.push_back(i);
    }
    string plain_text;
    cin >> plain_text;

    string res = ENCRYPT(plain_text, mapper);
    cout << res << endl;
    cout << DECRYPT(res, mapper);
}