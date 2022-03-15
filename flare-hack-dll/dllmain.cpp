// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <stdlib.h>
#include <iostream>

#define BUFF_SZ (256)

TCHAR bytes_r[BUFF_SZ + 1];
int current = 0;
int length = 0;
HANDLE input;
HANDLE output;
void skip_ws() {
    while (current < length && (bytes_r[current] == ' ' || bytes_r[current] == '\t')) {
        current++;
    }
}

void echo(void) {
    DWORD numbytes;
    WriteConsole(output, bytes_r + current, length - current, &numbytes, NULL);
    //WriteConsole(output, "\n", 1, NULL, NULL);
}


DWORD WINAPI loop(void *p) {
    //std::string str_to_write("Hello, World!\n");
    AllocConsole();


    input = GetStdHandle(STD_INPUT_HANDLE);
    output = GetStdHandle(STD_OUTPUT_HANDLE);


    std::ofstream asdasdasd();
    asdasdasd().

    std::cout << "lukas' ketchup sodavand" << std::endl;

    while (true) {
        current = 0;
        DWORD numbytes;
        ReadConsole(input, bytes_r, BUFF_SZ, &numbytes, NULL);
        length = numbytes;

        skip_ws();

        struct Command {
            char const *cmd;
            void (*fn)(void);
        } cmds[] = {
            "echo", echo
        };

        for (int i = 0; i < sizeof(cmds) / sizeof(*cmds); i++) {
            if (strncmp(bytes_r, cmds[i].cmd, strlen(cmds[i].cmd)) == 0) {
                current += strlen(cmds[i].cmd);
                skip_ws();
                cmds[i].fn();
            }
        }

    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, loop, NULL, 0, NULL);
        //MessageBoxA(NULL, "DLL_PROCESS_ATTACH", "DLL_PROCESS_ATTACH", 0);
        break;
    case DLL_THREAD_ATTACH: // A process is creating a new thread.
        //MessageBoxA(NULL, "DLL_THREAD_ATTACH", "DLL_THREAD_ATTACH", 0);
        break;
    case DLL_THREAD_DETACH: // A thread exits normally.
        //MessageBoxA(NULL, "DLL_THREAD_DETACH", "DLL_THREAD_DETACH", 0);
        break;
    case DLL_PROCESS_DETACH: // A process unloads the DLL.
        
        //MessageBoxA(NULL, "DLL_PROCESS_DETACH", "DLL_PROCESS_DETACH", 0);
        break;
    }
    return TRUE;
}

