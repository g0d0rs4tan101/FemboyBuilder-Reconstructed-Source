#include "utils.h"

// Stack alignment helper
ULONG_PTR stack_align(ULONG_PTR value) {
    ULONG_PTR result = value;
    if (0xFFF < value) {
        do {
            result -= 0x1000;
        } while (0x1000 < result);
    }
    return value;
}

// Generate random hex string
void generate_hex_name(WCHAR *buffer, size_t len, DWORD seed) {
    // Implementation
}
