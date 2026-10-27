#include "crypto.h"

// ChaCha20-style quarter round (as seen in FUN_00404061)
void chacha_round(uint32_t *state, int a, int b, int c, int d) {
    state[a] += state[b];
    state[d] ^= state[a];
    state[d] = ROTL32(state[d], 16);
    
    state[c] += state[d];
    state[b] ^= state[c];
    state[b] = ROTL32(state[b], 12);
    
    state[a] += state[b];
    state[d] ^= state[a];
    state[d] = ROTL32(state[d], 8);
    
    state[c] += state[d];
    state[b] ^= state[c];
    state[b] = ROTL32(state[b], 7);
}

// Decrypt block using ChaCha variant
void decrypt_block(uint8_t *data, size_t len, uint32_t *key) {
    uint32_t state[16];
    // Initialize state...
    // Apply rounds...
    // XOR keystream
}
