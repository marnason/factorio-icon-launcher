#define UNICODE
#define _UNICODE

#include <windows.h>
#include <shellapi.h>
#include <wchar.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    UNREFERENCED_PARAMETER(hInstance);
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(nCmdShow);
    wchar_t selfPath[32768];
    wchar_t folderPath[32768];
    wchar_t targetPath[32768];

    DWORD length = GetModuleFileNameW(NULL, selfPath, 32768);

    if (length == 0 || length >= 32768) {
        MessageBoxW(NULL, L"Could not determine launcher path.", L"Factorio Launcher", MB_ICONERROR);
        return 1;
    }

    wcscpy_s(folderPath, 32768, selfPath);

    wchar_t *lastSlash = wcsrchr(folderPath, L'\\');

    if (lastSlash == NULL) {
        MessageBoxW(NULL, L"Could not determine launcher folder.", L"Factorio Launcher", MB_ICONERROR);
        return 1;
    }

    *lastSlash = L'\0';

    swprintf_s(targetPath, 32768, L"%s\\factorio.exe", folderPath);

    HINSTANCE result = ShellExecuteW(
        NULL,
        L"open",
        targetPath,
        pCmdLine,
        folderPath,
        SW_SHOWNORMAL
    );

    if ((INT_PTR)result <= 32) {
        MessageBoxW(NULL, L"Could not launch factorio.exe.", L"Factorio Launcher", MB_ICONERROR);
        return 1;
    }

    return 0;
}