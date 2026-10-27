#ifndef UTILS_H
#define UTILS_H

#include <windows.h>

ULONG_PTR stack_align(ULONG_PTR value);
void generate_hex_name(WCHAR *buffer, size_t len, DWORD seed);

#endif
