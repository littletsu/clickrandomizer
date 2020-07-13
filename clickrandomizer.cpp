#include <windows.h>
#include <random>

int main()
{    
    POINT point1;
    POINT point2;

    while (true) {
        if (GetAsyncKeyState(VK_SHIFT)) {
            GetCursorPos(&point1);
        }
        else if (GetAsyncKeyState(VK_LCONTROL)) {
            GetCursorPos(&point2);
        }
        else if (GetAsyncKeyState(VK_F10)) {

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> xdistr(point1.x, point2.x);
            std::uniform_int_distribution<> ydistr(point1.y, point2.y);
            SetCursorPos(xdistr(gen), ydistr(gen));
            INPUT ip = { 0 };
            ip.type = INPUT_MOUSE;
            ip.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN;
            ::SendInput(1, &ip, sizeof(INPUT));
            ::ZeroMemory(&ip, sizeof(INPUT));
            ip.type = INPUT_MOUSE;
            ip.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTUP;
            ::SendInput(1, &ip, sizeof(INPUT));
        }
        
    }
    
}
