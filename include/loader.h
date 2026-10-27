#ifndef LOADER_H
#define LOADER_H

#include <windows.h>

ULONG_PTR* loader_callback(ULONG_PTR *param1, LONG_PTR *param2, 
                           LONG_PTR param3, ULONG_PTR param4);

#endif
