#include "qubit.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sph_luffa.h"
#include "sph_cubehash.h"
#include "sph_shavite.h"
#include "sph_simd.h"
#include "sph_echo.h"

void qubit_hash(const char* input, char* output)
{
    sph_luffa512_context       ctx_luffa;
    sph_cubehash512_context    ctx_cubehash;
    sph_shavite512_context     ctx_shavite;
    sph_simd512_context        ctx_simd;
    sph_echo512_context        ctx_echo;

    uint32_t hash[16];

    sph_luffa512_init (&ctx_luffa);
    sph_luffa512 (&ctx_luffa, input, 80);
    sph_luffa512_close (&ctx_luffa, hash);

    sph_cubehash512_init (&ctx_cubehash);
    sph_cubehash512 (&ctx_cubehash, hash, 64);
    sph_cubehash512_close(&ctx_cubehash, hash);

    sph_shavite512_init (&ctx_shavite);
    sph_shavite512 (&ctx_shavite, hash, 64);
    sph_shavite512_close(&ctx_shavite, hash);

    sph_simd512_init (&ctx_simd);
    sph_simd512 (&ctx_simd, hash, 64);
    sph_simd512_close(&ctx_simd, hash);

    sph_echo512_init (&ctx_echo);
    sph_echo512 (&ctx_echo, hash, 64);
    sph_echo512_close(&ctx_echo, hash);

    memcpy(output, hash, 32);
}
