#include "nist5.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sph_blake.h"
#include "sph_groestl.h"
#include "sph_jh.h"
#include "sph_keccak.h"
#include "sph_skein.h"


void nist5_hash(const char* input, char* output)
{
    sph_blake512_context     ctx_blake;
    sph_groestl512_context   ctx_groestl;
    sph_skein512_context     ctx_skein;
    sph_jh512_context        ctx_jh;
    sph_keccak512_context    ctx_keccak;

    uint32_t hash[16];

    sph_blake512_init(&ctx_blake);
    sph_blake512 (&ctx_blake, input, 80);
    sph_blake512_close (&ctx_blake, hash);

    sph_groestl512_init(&ctx_groestl);
    sph_groestl512 (&ctx_groestl, hash, 64);
    sph_groestl512_close(&ctx_groestl, hash);

    sph_jh512_init(&ctx_jh);
    sph_jh512 (&ctx_jh, hash, 64);
    sph_jh512_close(&ctx_jh, hash);

    sph_keccak512_init(&ctx_keccak);
    sph_keccak512 (&ctx_keccak, hash, 64);
    sph_keccak512_close(&ctx_keccak, hash);

    sph_skein512_init(&ctx_skein);
    sph_skein512 (&ctx_skein, hash, 64);
    sph_skein512_close (&ctx_skein, hash);

    memcpy(output, hash, 32);
}
