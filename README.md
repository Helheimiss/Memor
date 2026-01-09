# Memor

Memor namesp
``` cpp
uintptr_t Memor::GetProcessID(LPCTSTR target) noexcept(false);
uintptr_t Memor::GetModBaseAddr(LPCTSTR target, DWORD pid) noexcept(false);

PROCESSENTRY32 Memor::SnapProcess(LPCSTR target, DWORD dwFlags) noexcept(false);
MODULEENTRY32 Memor::SnapModule(LPCSTR target, DWORD pid, DWORD dwFlags) noexcept(false);
```

Memor::Extern namesp
``` cpp
template <typename T>
T Memor::Extern::ReadChainT(std::string_view program, std::string_view module, uintptr_t baseAddres, const std::vector<uintptr_t>& offsets) noexcept(false);

template <typename T>
T Memor::Extern::WriteChainT(std::string_view program, std::string_view module, uintptr_t baseAddres, const std::vector<uintptr_t>& offsets, const T&& newValue) noexcept(false);
```

Memor::Intern namesp
``` cpp
template <typename T>
T *Memor::Intern::RWChainT(std::string_view module, uintptr_t baseAddres, const std::vector<uintptr_t> &offsets) noexcept(false);
```
