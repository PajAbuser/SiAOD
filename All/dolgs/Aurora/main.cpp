#include <iostream>
#include <fstream>
#include <windows.h>
#include <locale>
#include <stdio.h>
#include <sstream>
#include <time.h>

using namespace std;

void pressKeyB(char mK)
{
    HKL kbl = GetKeyboardLayout(0);
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.dwFlags = KEYEVENTF_UNICODE;
    if ((int)mK < 65 && (int)mK>90) //for lowercase
    {
        ip.ki.wScan = 0;
        ip.ki.wVk = VkKeyScanEx(mK, kbl);
    }
    else //for uppercase
    {
        if ((int)mK > 0) {
            ip.ki.wScan = mK;
            ip.ki.wVk = 0;
        }
    }
    ip.ki.dwExtraInfo = 0;
    SendInput(1, &ip, sizeof(INPUT));


    ip.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

}

void pressEnter()
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.dwFlags = KEYEVENTF_UNICODE;
    ip.ki.wScan = VK_RETURN; //VK_RETURN is the code of Return key
    ip.ki.wVk = 0;

    ip.ki.dwExtraInfo = 0;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

void pressTab()
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.dwFlags = KEYEVENTF_UNICODE;
    ip.ki.wScan = VK_TAB; //VK_RETURN is the code of Return key
    ip.ki.wVk = 0;

    ip.ki.dwExtraInfo = 0;
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

int main()
{
    srand(time(0));
    char t;

    ifstream f("D:\\Projects\\SiAOD\\SiAOD2\\dolgs\\Aurora\\zxc.txt");

    Sleep(5000);

    f.get(t);
    while (!f.eof())
    {

        switch (t) {
            case '\n':
                pressEnter();
            case '\t':
                break;
                pressTab();
                break;
            default:
                pressKeyB(t);
                break;
        }

        f.get(t);
        Sleep(50 + rand() % 100);
    }
    system("PAUSE");
    f.close();
    return 0;
}