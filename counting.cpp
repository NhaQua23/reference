#include <iostream>

using namespace std;
#define MAX 100000

int find (int number, int* value, int* count)
{
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
