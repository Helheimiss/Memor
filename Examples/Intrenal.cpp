#include <windows.h>
#include <iostream>
#include <format>
#include <string>

#include "Memor.hpp"


#define DEBUG

#ifdef DEBUG
template <typename... Args>
constexpr void PrintInDBG(const char *format, Args... args) {
    std::cout << "[+] Debug: " << std::vformat(format, std::make_format_args(args...)) << std::endl;
}
#else
template <typename... Args>
constexpr void PrintInDBG(const char *format, Args... args) {
}
#endif


DWORD injected_thread(LPVOID hModule) {

#ifdef DEBUG
    if ( AllocConsole( ) )
    {
        FILE* file{};
        freopen_s(&file, "CONOUT$", "w", stdout);
        freopen_s(&file, "CONOUT$", "w", stderr);
        freopen_s(&file, "CONIN$", "r", stdin);
    }
#endif

    while (true) {
        if (GetAsyncKeyState('H')) {
            try {
                const auto p0 = Memor::Intern::RWChainT<int>("UnityPlayer.dll", 0x01A6D6A0, {0x128, 0x38, 0x60, 0x110, 0xA8, 0x20, 0x130});
                (*p0) += 1000;
                PrintInDBG("bullets: {}", *p0);
            } catch (std::runtime_error &er) {
                PrintInDBG("error {}", er.what());
            }
        }

        if (GetAsyncKeyState(VK_F5) & 0x0001) {
            PrintInDBG("bye");
            FreeConsole();
            break;
        }

        Sleep(1);
    }

    FreeLibraryAndExitThread(static_cast<HMODULE>(hModule), 0);
}



BOOL WINAPI DllMain(
    HMODULE hModule,
    DWORD fdwReason,
    LPVOID lpvReserved )
{
    if (fdwReason == DLL_PROCESS_ATTACH) {
        CreateThread(nullptr,
            0,
            injected_thread,
            hModule,
            0,
            nullptr
        );
    }
    return TRUE;
}