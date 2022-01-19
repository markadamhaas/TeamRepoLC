#include <iostream>
#include <map>

using namespace std;

int romanToInt(string s) {
    int converted = 0;
    map<char,int> romankey;
    romankey['I'] = 1;
    romankey['V'] = 5;
    romankey['X'] = 10;
    romankey['L'] = 50;
    romankey['C'] = 100;
    romankey['D'] = 500;
    romankey['M'] = 1000;
    for (int i=0; i<s.length(); ++i){
        int temp = romankey[s[i]];
        // if (i+1 >= s.length()){
        //     converted += temp;
        //     return converted;
        // }
        if (temp == 1 && (romankey[s[i+1]] == 5 || romankey[s[i+1]] == 10)){
            temp = romankey[s[i+1]] - temp;
            converted += temp;
            i++;
        }
        else if (temp == 10 && (romankey[s[i+1]] == 50 || romankey[s[i+1]] == 100)){
            temp = romankey[s[i+1]] - temp;
            converted += temp;
            i++;
        }
        else if (temp == 100 && (romankey[s[i+1]] == 500 || romankey[s[i+1]] == 1000)){
            temp = romankey[s[i+1]] - temp;
            converted += temp;
            i++;
        }
        else{
            converted += temp;
        }
    }
    return converted;
}

int main(){
    string s;
    cin >> s;
    cout << romanToInt(s) << endl;

    return 0;
}