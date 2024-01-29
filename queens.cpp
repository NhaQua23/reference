#include <iostream>

using namespace std;

void print (int* queenY, int N)
{
    for (int x = 0; x < N; x++) {
        for (int j = 0; j < N; j++) {
            cout << (j == queenY[x] ? " x" : " .");
        }
        cout << endl;
    }
    cout << endl;
}

bool threatens(int x1, int y1, int x2, int y2) {
    return x1 == x2 || y1 == y2 || x1+y1 == x2+y2 || x1-y1 == x2-y2;
}

bool safe(int* queenY, int lastX) {
    for (int x = 0; x < lastX; x++)
        if (threatens(x, queenY[x], lastX, queenY[lastX])) return false;
    return true;
}

int bruteForce(int* queenY, int x, int N)
{
    if (x == N) {
        //print(queenY, N);
        return 1;
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        queenY[x] = i;
        if (safe(queenY, x)) {
            count += bruteForce(queenY, x+1, N);
        }
    }
    return count;
}

int main(int argc, char* argv)
{
    int N;
    int queenY[10];
    cin >> N;
    cout <<bruteForce(queenY, 0, N);
}
