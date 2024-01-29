#include <iostream>

using namespace std;

#define MAX 10000

int find(int number, int* value, int* count)
{
    int i = 0;
    for (; count[i] != 0; i++)
        if (value[i] == number) return i;
    value[i] = number;
    return i;
}

int main(int argc, char** argv)
{
    int count[MAX];
    int value[MAX];

    for (int i = 0; i < MAX; i++) count[i] = 0;   // chua dem duoc so nao

    while (!cin.eof()) {
        int number = 0;
        cin >> number;
        if (!cin.bad())  {
            int i = find(number, value, count);
            count[i] ++;
        }
    }
    for (int i = 0; i < MAX; i++)  {
        if (count[i] != 0) cout << value[i] << ": " << count[i] << endl;
    }
}
