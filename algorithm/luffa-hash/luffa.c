#include "luffa.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sph_luffa.h"

void luffa_hash(const char* input, char* output)
{
    sph_luffa512_context ctx_luffa;
    uint32_t hashA[16];

    sph_luffa512_init(&ctx_luffa);
    sph_luffa512(&ctx_luffa, input, 80);
    sph_luffa512_close(&ctx_luffa,hashA);

    memcpy(output, hashA, 32);
}
