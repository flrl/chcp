#include <stdio.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

int main(int argc, char **argv) {
    int r = 0;

    if (argc > 1) {
        unsigned cp = atoi(argv[1]);

        if (!SetConsoleOutputCP(cp)) {
            LPVOID lpMsgBuf;
            DWORD dw = GetLastError();
            r = 1;

            if (!FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER
                               | FORMAT_MESSAGE_FROM_SYSTEM
                               | FORMAT_MESSAGE_IGNORE_INSERTS,
                               NULL,
                               dw,
                               MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                               (LPTSTR) &lpMsgBuf,
                               0,
                               NULL))
            {
                fputs("FormatMessage failed\n", stderr);
                r = 2;
                goto done;
            }

            fputs(lpMsgBuf, stderr);
            LocalFree(lpMsgBuf);
            goto done;
        }
    }

 done:
    printf("Active code page: %u\n", GetConsoleOutputCP());
    return 0;
}
