#include <iostream>

using namespace std;

void sgr(int code);

int main()
{
    for (int i = 0; i < 256; i++)
    {
        sgr(i);
        cout << "Hello, World! " << i << endl;
        sgr(0);
    }

    return 0;
}

void sgr(int code)
{
    cout << "\x1b[" << code << "m";
}
