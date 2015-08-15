#include "skein.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sph_skein.h"
#include "sph_sha2.h"

void skein_hash(const char *input, char* output)
{
    sph_skein512_context ctx_skein;
    sph_sha256_context ctx_sha2;
    uint32_t hash[16];

    sph_skein512_init(&ctx_skein);
    sph_skein512(&ctx_skein, input, 80);
    sph_skein512_close(&ctx_skein, hash);

    sph_sha256_init(&ctx_sha2);
    sph_sha256(&ctx_sha2, hash, 64);
    sph_sha256_close(&ctx_sha2, hash);

    memcpy(output, hash, 32);
}
