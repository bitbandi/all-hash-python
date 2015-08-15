#include "lyra2re.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sph_blake.h"
#include "sph_keccak.h"
#include "sph_skein.h"
#include "sph_groestl.h"
#include "Lyra2.h"

void lyra2re_hash(const char* input, char* output)
{
    sph_blake256_context    ctx_blake;
    sph_keccak256_context   ctx_keccak;
    sph_skein256_context    ctx_skein;
    sph_groestl256_context  ctx_groestl;

    uint32_t hashA[16], hashB[16];

    memset(hashA, 0, 16 * sizeof(uint32_t));
    memset(hashB, 0, 16 * sizeof(uint32_t));

    sph_blake256_init(&ctx_blake);
    sph_blake256 (&ctx_blake, input, 80);
    sph_blake256_close (&ctx_blake, hashA);

    sph_keccak256_init(&ctx_keccak);
    sph_keccak256 (&ctx_keccak,hashA, 32);
    sph_keccak256_close(&ctx_keccak, hashB);

    LYRA2((void*)hashA, 32, (const void*)hashB, 32, (const void*)hashB, 32, 1, 8, 8);

    sph_skein256_init(&ctx_skein);
    sph_skein256 (&ctx_skein, hashA, 32);
    sph_skein256_close(&ctx_skein, hashB);

    sph_groestl256_init(&ctx_groestl);
    sph_groestl256 (&ctx_groestl, hashB, 32);
    sph_groestl256_close(&ctx_groestl, hashA);

    memcpy(output, hashA, 32);
}
