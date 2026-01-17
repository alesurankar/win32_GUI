#pragma once
#include <string>
#include "MyWin.h"

inline std::wstring ToWide(const char* str)
{
    if (!str) return L"";

    int size = MultiByteToWideChar(
        CP_UTF8,
        0,
        str,
        -1,
        nullptr,
        0
    );

    std::wstring result(size, 0);

    MultiByteToWideChar(
        CP_UTF8,
        0,
        str,
        -1,
        result.data(),
        size
    );

    return result;
}

inline std::string FromWide(const wchar_t* wstr)
{
    if (!wstr) return {};

    int size = WideCharToMultiByte(
        CP_UTF8,
        0,
        wstr,
        -1,
        nullptr,
        0,
        nullptr,
        nullptr
    );

    std::string result(size - 1, '\0');

    WideCharToMultiByte(
        CP_UTF8,
        0,
        wstr,
        -1,
        result.data(),
        size,
        nullptr,
        nullptr
    );

    return result;
}
