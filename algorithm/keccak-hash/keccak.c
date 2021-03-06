#include "keccak.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sph_keccak.h"

void keccak_hash(const char* input, char* output)
{
    sph_keccak256_context ctx_keccak;
    uint32_t hash[16];

    sph_keccak256_init(&ctx_keccak);
    sph_keccak256(&ctx_keccak, input, 80);
    sph_keccak256_close(&ctx_keccak, hash);

    memcpy(output, hash, 32);
}
