#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <string>
#include <algorithm>

typedef unsigned int uint;

namespace Str
{
    std::string Lower(const char *s)
    {
        std::string res(s);
        std::transform(res.begin(), res.end(), res.begin(), ::tolower);
        return res;
    }

    uint Hash(const std::string &str)
    {
        uint hash = 0;
        for (char c : str)
            hash = hash * 31 + c;
        return hash;
    }
}

enum AVType
{
    AV_None = 0,
    AV_TrendMicro = 1,
    AV_Kaspersky = 2,
    AV_Avast = 3,
    AV_Bitdefender = 4,
    AV_Norton = 5,
    AV_McAfee = 6
};

int DVDDetect()
{
    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE)
        return AV_None;

    if (Process32First(snap, &pe))
    {
        do
        {
            uint hash = Str::Hash(Str::Lower(pe.szExeFile));

            switch (hash)
            {
            case 0x0fc4e7c5:
                CloseHandle(snap);
                return AV_TrendMicro;
            case 0x1a2b3c4d:
                CloseHandle(snap);
                return AV_Kaspersky;
            case 0x2b3c4d5e:
                CloseHandle(snap);
                return AV_Avast;
            case 0x3c4d5e6f:
                CloseHandle(snap);
                return AV_Bitdefender;
            case 0x4d5e6f70:
                CloseHandle(snap);
                return AV_Norton;
            case 0x5e6f7081:
                CloseHandle(snap);
                return AV_McAfee;
            }

        } while (Process32Next(snap, &pe));
    }

    CloseHandle(snap);
    return AV_None;
}

int main()
{
    int av = DVDDetect();

    switch (av)
    {
    case AV_TrendMicro:
        std::cout << "Trend Micro detected!\n";
        break;
    case AV_Kaspersky:
        std::cout << "Kaspersky detected!\n";
        break;
    case AV_Avast:
        std::cout << "Avast detected!\n";
        break;
    case AV_Bitdefender:
        std::cout << "Bitdefender detected!\n";
        break;
    case AV_Norton:
        std::cout << "Norton detected!\n";
        break;
    case AV_McAfee:
        std::cout << "McAfee detected!\n";
        break;
    default:
        std::cout << "No known AV detected.\n";
        break;
    }

    return 0;
}
