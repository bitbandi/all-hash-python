#include "bastion.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sph_echo.h"
#include "sph_hefty1.h"
#include "sph_luffa.h"
#include "sph_whirlpool.h"
#include "sph_shabal.h"
#include "sph_fugue.h"
#include "sph_hamsi.h"
#include "sph_skein.h"


void bastion_hash(const char* input, char* output)
{
    sph_luffa512_context    ctx_luffa;
    sph_fugue512_context    ctx_fugue;
    sph_skein512_context    ctx_skein;
    sph_whirlpool_context   ctx_whirlpool;
    sph_echo512_context     ctx_echo;
    sph_shabal512_context   ctx_shabal;
    sph_hamsi512_context    ctx_hamsi;

    uint32_t hash[16];
    uint32_t mask = 8;
    uint32_t zero = 0;

    memset(hash, 0, 16 * sizeof(uint32_t));

    HEFTY1((unsigned char *)input, 80, (unsigned char *)hash);

    sph_luffa512_init(&ctx_luffa);
    sph_luffa512(&ctx_luffa, hash, 64);
    sph_luffa512_close(&ctx_luffa, hash);

    if ((hash[0] & mask) != zero)
    {
        sph_fugue512_init(&ctx_fugue);
        sph_fugue512 (&ctx_fugue, hash, 64);
        sph_fugue512_close(&ctx_fugue, hash);
    }
    else
    {
        sph_skein512_init(&ctx_skein);
        sph_skein512 (&ctx_skein, hash, 64);
        sph_skein512_close(&ctx_skein, hash);
    }

    sph_whirlpool_init(&ctx_whirlpool);
    sph_whirlpool (&ctx_whirlpool, hash, 64);
    sph_whirlpool_close(&ctx_whirlpool, hash);

    sph_fugue512_init(&ctx_fugue);
    sph_fugue512 (&ctx_fugue, hash, 64);
    sph_fugue512_close(&ctx_fugue, hash);

    if ((hash[0] & mask) != zero)
    {
        sph_echo512_init(&ctx_echo);
        sph_echo512 (&ctx_echo, hash, 64);
        sph_echo512_close(&ctx_echo, hash);
    }
    else
    {
        sph_luffa512_init(&ctx_luffa);
        sph_luffa512 (&ctx_luffa, hash, 64);
        sph_luffa512_close(&ctx_luffa, hash);
    }

    sph_shabal512_init(&ctx_shabal);
    sph_shabal512 (&ctx_shabal, hash, 64);
    sph_shabal512_close(&ctx_shabal, hash);

    sph_skein512_init(&ctx_skein);
    sph_skein512 (&ctx_skein, hash, 64);
    sph_skein512_close(&ctx_skein, hash);

    if ((hash[0] & mask) != zero)
    {
        sph_shabal512_init(&ctx_shabal);
        sph_shabal512 (&ctx_shabal, hash, 64);
        sph_shabal512_close(&ctx_shabal, hash);
    }
    else
    {
        sph_whirlpool_init(&ctx_whirlpool);
        sph_whirlpool (&ctx_whirlpool, hash, 64);
        sph_whirlpool_close(&ctx_whirlpool, hash);
    }

    sph_shabal512_init(&ctx_shabal);
    sph_shabal512 (&ctx_shabal, hash, 64);
    sph_shabal512_close(&ctx_shabal, hash);

    if ((hash[0] & mask) != zero)
    {
        sph_hamsi512_init(&ctx_hamsi);
        sph_hamsi512 (&ctx_hamsi, hash, 64);
        sph_hamsi512_close(&ctx_hamsi, hash);
    }
    else
    {
        sph_luffa512_init(&ctx_luffa);
        sph_luffa512 (&ctx_luffa, hash, 64);
        sph_luffa512_close(&ctx_luffa, hash);
    }

    memcpy(output, hash, 32);
}
