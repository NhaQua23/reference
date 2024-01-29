#include <iostream>

using namespace std;
#define MAX 100000

const int MA = 1;       // ta se khong sua MA
int n;                          // n duoc thay doi
const int* p1 = &MA;  // ta se khong sua (*p1)
//int* p = &MA;  //   ta co the sua (*p) -> loi

int* const p2 = &MA; // ta co the sua (*p2) , error
int* const p3 = &n;   // ta co the sua (*p3) , ok

int find (int number, int* value, int* count)
{
 //   p2 = ghdh
 //   p3 = sdlfgk;s

    int i = 0;
    for (; count[i] != 0; i++) {
        if (value[i] == number) return i;
    }
    value[i] = number;
    return i;
}

int main(int argc, char** argv)
{
    int count[MAX];
    int value[MAX];
    for (int i = 0; i < MAX; i++ ) count[i] = 0;

    int number;
    while (cin >> number) {
            int i = find(number, value, count);
            count[i]++;
    }

    for (int i = 0; count[i] != 0; i++ ) {
        cout << value[i] << ": " << count[i] << endl;
    }
}
