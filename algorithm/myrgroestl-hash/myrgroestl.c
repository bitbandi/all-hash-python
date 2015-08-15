#include "myrgroestl.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "sph_groestl.h"
#include "sph_sha2.h"

void myrgroestl_hash(const char* input, char* output)
{
    sph_groestl512_context ctx_groestl;
    sph_sha256_context ctx_sha2;

    uint32_t hash[16];

    sph_groestl512_init(&ctx_groestl);
    sph_groestl512(&ctx_groestl, input, 80);
    sph_groestl512_close(&ctx_groestl, (void*) hash);

    sph_sha256_init(&ctx_sha2);
    sph_sha256(&ctx_sha2, hash, 64);
    sph_sha256_close(&ctx_sha2, (void*) hash);

    memcpy(output, hash, 32);
}
