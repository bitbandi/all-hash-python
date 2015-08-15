#include "quark.h"

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

char *bin2hex(const unsigned char *p, size_t len)
{
        int i;
        char *s = malloc((len * 2) + 1);
        if (!s)
                return NULL;

        for (i = 0; i < len; i++)
                sprintf(s + (i * 2), "%02x", (unsigned int) p[i]);

        return s;
}


void quark_hash(const char* input, char* output)
{
    sph_blake512_context     ctx_blake;
    sph_bmw512_context       ctx_bmw;
    sph_groestl512_context   ctx_groestl;
    sph_jh512_context        ctx_jh;
    sph_keccak512_context    ctx_keccak;
    sph_skein512_context     ctx_skein;

    uint32_t hash[16];
    uint32_t mask = 8;
    uint32_t zero = 0;

    sph_blake512_init(&ctx_blake);
    sph_blake512 (&ctx_blake, input, 80);
    sph_blake512_close (&ctx_blake, hash);

    sph_bmw512_init(&ctx_bmw);
    sph_bmw512 (&ctx_bmw, hash, 64);
    sph_bmw512_close(&ctx_bmw, hash);

    if ((hash[0] & mask) != zero)
    {
        sph_groestl512_init(&ctx_groestl);
        sph_groestl512 (&ctx_groestl, hash, 64);
        sph_groestl512_close(&ctx_groestl, hash);
    }
    else
    {
        sph_skein512_init(&ctx_skein);
        sph_skein512 (&ctx_skein, hash, 64);
        sph_skein512_close(&ctx_skein, hash);
    }

    sph_groestl512_init(&ctx_groestl);
    sph_groestl512 (&ctx_groestl, hash, 64);
    sph_groestl512_close(&ctx_groestl, hash);

    sph_jh512_init(&ctx_jh);
    sph_jh512 (&ctx_jh, hash, 64);
    sph_jh512_close(&ctx_jh, hash);

    if ((hash[0] & mask) != zero)
    {
        sph_blake512_init(&ctx_blake);
        sph_blake512 (&ctx_blake, hash, 64);
        sph_blake512_close(&ctx_blake, hash);
    }
    else
    {
        sph_bmw512_init(&ctx_bmw);
        sph_bmw512 (&ctx_bmw, hash, 64);
        sph_bmw512_close(&ctx_bmw, hash);
    }

    sph_keccak512_init(&ctx_keccak);
    sph_keccak512 (&ctx_keccak,hash, 64);
    sph_keccak512_close(&ctx_keccak, hash);

    sph_skein512_init(&ctx_skein);
    sph_skein512 (&ctx_skein, hash, 64);
    sph_skein512_close(&ctx_skein, hash);

    if ((hash[0] & mask) != zero)
    {
        sph_keccak512_init(&ctx_keccak);
        sph_keccak512 (&ctx_keccak, hash, 64);
        sph_keccak512_close(&ctx_keccak, hash);
    }
    else
    {
        sph_jh512_init(&ctx_jh);
        sph_jh512 (&ctx_jh, hash, 64);
        sph_jh512_close(&ctx_jh, hash);
    }

    memcpy(output, hash, 32);
}
