#include <iostream>
#include <array>
using namespace std;

//£ŒËæ”y‚©‚ç‹³‚¦‚Ä‚¢‚½‚¾‚¢‚½array‚ğg—p
// ”š‚ğ“ü—Í‚·‚éŠÖ”iarray‚ğ“n‚·j
void InputNumbers(array<int, 10>& num)
{
    for (int i = 0; i < num.size(); i++)
    {
        cout << i + 1 << "ŒÂ–Ú‚Ì”š‚ğ“ü—ÍF";
        cin >> num[i];
    }
}

int main()
{
    array<int, 10> num;
    array<int, 10> even;
    array<int, 10> odd;

    int evenCount = 0;
    int oddCount = 0;

    // ”š“ü—Í
    InputNumbers(num);

    // ‹ô”EŠï”‚É•ª—Ş
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] % 2 == 0)
        {
            even[evenCount] = num[i];
            evenCount++;
        }
        else
        {
            odd[oddCount] = num[i];
            oddCount++;
        }
    }

    // ‹ô”•\¦
    cout << "\ny‹ô”(even)z" << endl;
    for (int i = 0; i < evenCount; i++)
    {
        cout << even[i] << " ";
    }

    // Šï”•\¦
    cout << "\nyŠï”(odd)z" << endl;
    for (int i = 0; i < oddCount; i++)
    {
        cout << odd[i] << " ";
    }

    cout << endl;

    return 0;
}