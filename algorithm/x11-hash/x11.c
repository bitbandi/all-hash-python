#include "x11.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sph_blake.h"
#include "sph_bmw.h"
#include "sph_groestl.h"
#include "sph_jh.h"
#include "sph_keccak.h"
#include "sph_skein.h"
#include "sph_luffa.h"
#include "sph_cubehash.h"
#include "sph_shavite.h"
#include "sph_simd.h"
#include "sph_echo.h"

void x11_hash(const char* input, char* output)
{
    sph_blake512_context     ctx_blake;
    sph_bmw512_context       ctx_bmw;
    sph_groestl512_context   ctx_groestl;
    sph_skein512_context     ctx_skein;
    sph_jh512_context        ctx_jh;
    sph_keccak512_context    ctx_keccak;
    sph_luffa512_context     ctx_luffa;
    sph_cubehash512_context  ctx_cubehash;
    sph_shavite512_context   ctx_shavite;
    sph_simd512_context      ctx_simd;
    sph_echo512_context      ctx_echo;

    uint32_t hash[16];

    sph_blake512_init(&ctx_blake);
    sph_blake512 (&ctx_blake, input, 80);
    sph_blake512_close (&ctx_blake, hash);

    sph_bmw512_init(&ctx_bmw);
    sph_bmw512 (&ctx_bmw, hash, 64);
    sph_bmw512_close(&ctx_bmw, hash);

    sph_groestl512_init(&ctx_groestl);
    sph_groestl512 (&ctx_groestl, hash, 64);
    sph_groestl512_close(&ctx_groestl, hash);

    sph_skein512_init(&ctx_skein);
    sph_skein512 (&ctx_skein, hash, 64);
    sph_skein512_close (&ctx_skein, hash);

    sph_jh512_init(&ctx_jh);
    sph_jh512 (&ctx_jh, hash, 64);
    sph_jh512_close(&ctx_jh, hash);

    sph_keccak512_init(&ctx_keccak);
    sph_keccak512 (&ctx_keccak, hash, 64);
    sph_keccak512_close(&ctx_keccak, hash);

    sph_luffa512_init (&ctx_luffa);
    sph_luffa512 (&ctx_luffa, hash, 64);
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

