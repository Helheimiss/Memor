#include "Memor.hpp"
#include <format>
#include <iostream>

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


void External() {
    int bullets {};
    LPCSTR module {"UnityPlayer.dll"};
    uintptr_t baseAddress {0x01A6D6A0};
    std::vector<uintptr_t> offsets {0x128, 0x38, 0x60, 0x110, 0xA8, 0x20, 0x130};

    PrintInDBG("{}", "Read memory");
    try {
        bullets = Memor::Extern::ReadChainT<int>("ravenfield.exe", module, baseAddress, offsets);
        PrintInDBG("{0} 0x{0:X}", bullets);

    } catch (std::runtime_error &er) {
        PrintInDBG("{}", er.what());
    }

    PrintInDBG("{}", "Write memory");
    try {
        bullets = Memor::Extern::WriteChainT<int>("ravenfield.exe", module, baseAddress, offsets, std::numeric_limits<int>::max());
        PrintInDBG("{0} 0x{0:X}", bullets);

    } catch (std::runtime_error &er) {
        PrintInDBG("{}", er.what());
    }
}