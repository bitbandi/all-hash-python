#include "groestl.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "sph_groestl.h"

void groestl_hash(const char* input, char* output)
{
    sph_groestl512_context ctx_groestl;
    uint32_t hash[16];

    sph_groestl512_init(&ctx_groestl);
    sph_groestl512(&ctx_groestl, input, 80);
    sph_groestl512_close(&ctx_groestl, (void*) hash);

    //sph_groestl512_init(&ctx_groestl);
    sph_groestl512(&ctx_groestl, hash, 64);
    sph_groestl512_close(&ctx_groestl, (void*) hash);

    memcpy(output, hash, 32);
}
