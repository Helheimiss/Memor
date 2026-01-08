# Memor
example
``` cpp
#include "Memor.hpp"


template <typename... Args>
constexpr void PrintInDBG(const char *format, Args... args) {
    std::cout << "[+] Debug: " << std::vformat(format, std::make_format_args(args...)) << std::endl;
}


int bullets {};
PrintInDBG("{}", "Read memory");
try {
    bullets = Memor::ReadChainT<int>("FarCry.exe", "XRenderD3D9.dll", 0x00162DC4, {0x20, 0x12c, 0xc, 0xa8});
    PrintInDBG("bullets {0} 0x{0:X}", bullets);

} catch (std::runtime_error er) {
    PrintInDBG("{}", er.what());
}

PrintInDBG("{}", "Write memory");
try {
    bullets = Memor::WriteChainT<int>("FarCry.exe", "XRenderD3D9.dll", 0x00162DC4, {0x20, 0x12c, 0xc, 0xa8}, 300);
    PrintInDBG("bullets {0} 0x{0:X}", bullets);

} catch (std::runtime_error er) {
    PrintInDBG("{}", er.what());
}
```
