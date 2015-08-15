#include "whirlcoin.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sph_whirlpool.h"

void whirlcoin_hash(const char* input, char* output)
{
    sph_whirlpool1_context ctx_whirlpool;
    uint32_t hash[16];

    sph_whirlpool1_init(&ctx_whirlpool);
    sph_whirlpool1(&ctx_whirlpool, input, 80);
    sph_whirlpool1_close(&ctx_whirlpool, hash);

    sph_whirlpool1_init(&ctx_whirlpool);
    sph_whirlpool1(&ctx_whirlpool, hash, 64);
    sph_whirlpool1_close(&ctx_whirlpool, hash);

    sph_whirlpool1_init(&ctx_whirlpool);
    sph_whirlpool1(&ctx_whirlpool, hash, 64);
    sph_whirlpool1_close(&ctx_whirlpool, hash);

    sph_whirlpool1_init(&ctx_whirlpool);
    sph_whirlpool1(&ctx_whirlpool, hash, 64);
    sph_whirlpool1_close(&ctx_whirlpool, hash);

    memcpy(output, hash, 32);
}
