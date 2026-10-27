#ifndef CRYPTO_H
#define CRYPTO_H

#include <windows.h>
#include <stdint.h>

#define ROTL32(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

void chacha_round(uint32_t *state, int a, int b, int c, int d);
void decrypt_block(uint8_t *data, size_t len, uint32_t *key);

#endif
