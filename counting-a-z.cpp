#include <iostream>

using namespace std;

#define MAX 1000

int main(int argc, char** argv)
{
    int count[MAX + 1];
    for (int i = 0; i < MAX; i++) count[i] = 0;   // chua dem duoc so nao

    while (!cin.eof()) {
        string s;
        cin >> s;
        for (int i = 0; i<s.length(); i++) {
            char c = s[i];
            if (c <= 'z' && 'a' <= c ) count[c-'a']++;
        }
    }

    for (int i = 0; i < MAX; i++)  {
        if (count[i] != 0) cout << (char)('a'+ i) << ": " << count[i] << endl;
    }
}
