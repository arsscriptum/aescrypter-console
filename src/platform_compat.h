
//==============================================================================
//
//  platform_compat.h - Cross-platform compatibility layer
//
//==============================================================================
//  Guilaume Plante 2020 <guillaumeplante.qc@gmail.com>
//==============================================================================

#ifndef __PLATFORM_COMPAT_H__
#define __PLATFORM_COMPAT_H__

// ---------------------------------------------------------------------------
// Auto-detect platform if not passed via compiler flag
// ---------------------------------------------------------------------------
#if !defined(WIN64) && !defined(LINUX)
#  if defined(_WIN32) || defined(_WIN64)
#    define WIN64
#  elif defined(__linux__) || defined(__unix__)
#    define LINUX
#  endif
#endif

// ---------------------------------------------------------------------------
// Linux compatibility shims
// ---------------------------------------------------------------------------
#ifdef LINUX

#include <cstdio>
#include <cstring>
#include <cwchar>
#include <string>
#include <unistd.h>
#include <termios.h>

// Convert wchar_t* path to narrow UTF-8 string for POSIX calls
inline std::string wstr_to_narrow(const wchar_t* wstr) {
    if (!wstr) return "";
    size_t len = wcslen(wstr);
    std::string result(len * 4 + 1, '\0');
    size_t converted = wcstombs(result.data(), wstr, result.size());
    if (converted == static_cast<size_t>(-1)) return "";
    result.resize(converted);
    return result;
}

// POSIX equivalent of _wfopen
inline FILE* _wfopen(const wchar_t* path, const wchar_t* mode) {
    return fopen(wstr_to_narrow(path).c_str(), wstr_to_narrow(mode).c_str());
}

// POSIX equivalent of _wunlink
inline int _wunlink(const wchar_t* path) {
    return unlink(wstr_to_narrow(path).c_str());
}

// Convert std::wstring to narrow for std::ifstream
inline std::string wstring_to_string(const std::wstring& wstr) {
    return wstr_to_narrow(wstr.c_str());
}

// Echo-less single wide-char read (Windows _getwch equivalent).
// Sets terminal to raw/no-echo mode per call — correct for human-paced input.
inline wint_t _getwch(void) {
    struct termios t_old, t_new;
    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~static_cast<tcflag_t>(ECHO | ICANON);
    t_new.c_cc[VMIN]  = 1;
    t_new.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);
    wint_t c = getwchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return c;
}

#endif // LINUX

#endif // __PLATFORM_COMPAT_H__
