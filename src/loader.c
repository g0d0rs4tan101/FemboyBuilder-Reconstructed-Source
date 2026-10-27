#include "loader.h"

// Memory loading callback (FUN_00404201)
ULONG_PTR* loader_callback(ULONG_PTR *param1, LONG_PTR *param2, 
                           LONG_PTR param3, ULONG_PTR param4) {
    LONG_PTR *plVar1 = (LONG_PTR*)*param2;
    LONG_PTR offset = plVar1[2];
    ULONG_PTR size = plVar1[1] - offset;
    
    if (param4 < (ULONG_PTR)(plVar1[1] - offset)) {
        size = param4;
    }
    
    // Copy data
    memcpy((void*)param3, (void*)(offset + *plVar1), size);
    plVar1[2] = size + offset;
    *param1 = size;
    *(WORD*)(param1 + 1) = 0;
    return param1;
}
