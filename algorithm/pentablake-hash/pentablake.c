#include "pentablake.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "sph_blake.h"

void pentablake_hash(const char* input, char* output)
{
    sph_blake512_context ctx_blake;

    uint32_t hash[16];

    sph_blake512_init(&ctx_blake);
    sph_blake512(&ctx_blake, input, 80);
    sph_blake512_close(&ctx_blake, (void*) hash);

    sph_blake512_init(&ctx_blake);
    sph_blake512(&ctx_blake, hash, 64);
    sph_blake512_close(&ctx_blake, (void*) hash);

    sph_blake512_init(&ctx_blake);
    sph_blake512(&ctx_blake, hash, 64);
    sph_blake512_close(&ctx_blake, (void*) hash);

    sph_blake512_init(&ctx_blake);
    sph_blake512(&ctx_blake, hash, 64);
    sph_blake512_close(&ctx_blake, (void*) hash);

    sph_blake512_init(&ctx_blake);
    sph_blake512(&ctx_blake, hash, 64);
    sph_blake512_close(&ctx_blake, (void*) hash);

    memcpy(output, hash, 32);
}
