#include "blake_sfr.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sph_blake.h"


void blake_sfr_hash(const char* input, char* output)
{
    uint32_t hash[8];

    sph_blake256_context ctx_blake;

    sph_blake256_init(&ctx_blake);
    sph_blake256(&ctx_blake, input, 80);
    sph_blake256_close(&ctx_blake, hash);

    memcpy(output, hash, 32);
}
