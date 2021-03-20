#include <string>
#include <cmath>
using namespace std;

int ascii_to_num(string str)
{
    int num = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if ((int) str[i] > 47 && (int) str[i] < 58)
        {
            num += ((int) str[i] - 48) * pow(10, str.length() - i - 1);
        }
    }
    return num;
}