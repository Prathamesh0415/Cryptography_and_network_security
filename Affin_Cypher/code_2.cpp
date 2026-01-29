#include<bits/stdc++.h>

using namespace std;

string ENCRYPT(string plain_text, int k1, int k2){
    string temp = "";
    for(auto it: plain_text){
        temp += 'a' + ((it - 'a')*k1 + k2) % 26;
    }
    return temp;

}

int main(){
    string plain_text;
    int k1 = 0;
    int k2 = 0;

    cin >> plain_text;
    cin >> k1;
    cin >> k2;
    int k = -1;
    int counter = 1;
    while(1){
        if(((counter * 26 + 1) % k1) == 1){
            k = (counter * 26 + 1) / k1;
            break;
        }
        //cout << counter;
        counter++;
    }
    cout << ENCRYPT(plain_text, k1, k2);

}