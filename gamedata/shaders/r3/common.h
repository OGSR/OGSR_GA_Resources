#ifndef COMMON_H
#define COMMON_H

#include "shared\common.h"

#include "common_defines.h"
#include "common_policies.h"
#include "common_iostructs.h"
#include "common_samplers.h"
#include "common_cbuffers.h"
#include "common_functions.h"

//#define USE_SUNMASK

#ifdef USE_R2_STATIC_SUN
#define xmaterial float(1.0h / 4.h)
#else
#define xmaterial float(L_material.w)
#endif

/*
#define FXPS \
    technique _render \
    { \
        pass _code { PixelShader = compile ps_3_0 main(); } \
    }
#define FXVS \
    technique _render \
    { \
        pass _code { VertexShader = compile vs_3_0 main(); } \
    }
*/

#define FXPS
#define FXVS

#endif