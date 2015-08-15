#include "twe.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sph_fugue.h"
#include "sph_hamsi.h"
#include "sph_panama.h"
#include "sph_shavite.h"

void twe_hash(const char* input, char* output)
{
    sph_fugue256_context   ctx_fugue;
    sph_shavite256_context ctx_shavite;
    sph_hamsi256_context   ctx_hamsi;
    sph_panama_context     ctx_panama;
    uint32_t hash[16];

    memset(hash, 0, 16 * sizeof(uint32_t));

    sph_fugue256_init(&ctx_fugue);
    sph_fugue256(&ctx_fugue, input, 80);
    sph_fugue256_close(&ctx_fugue, hash);

    sph_shavite256_init(&ctx_shavite);
    sph_shavite256(&ctx_shavite, hash, 64);
    sph_shavite256_close(&ctx_shavite, hash);

    sph_hamsi256_init(&ctx_hamsi);
    sph_hamsi256(&ctx_hamsi, hash, 64);
    sph_hamsi256_close(&ctx_hamsi, hash);

    sph_panama_init(&ctx_panama);
    sph_panama(&ctx_panama, hash, 64);
    sph_panama_close(&ctx_panama, hash);

    memcpy(output, hash, 32);
}
