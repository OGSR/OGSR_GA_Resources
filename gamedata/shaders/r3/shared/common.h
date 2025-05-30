//////////////////////////////////////////////////
//  All comments by Nivenhbro are preceded by !
/////////////////////////////////////////////////

#ifndef SHARED_COMMON_H
#define SHARED_COMMON_H

//	Used by VS
cbuffer dynamic_transforms
{
    uniform float4x4 m_WVP; //	World View Projection composition
    uniform float3x4 m_WV;
    uniform float3x4 m_W;
    uniform float3x4 m_invW;
    uniform float4x4 m_WVP_old;
    uniform float4x4 m_VP_old;

    //	Used by VS only
    uniform float4 L_material; // 0,0,0,mid
    uniform float4 hemi_cube_pos_faces;
    uniform float4 hemi_cube_neg_faces;
    uniform float4 dt_params; //	Detail params
    uniform float4 m_taa_jitter;

    uniform float4 m_actor_params;
    uniform float4 m_actor_position;
    uniform float4 L_hotness;
}

cbuffer shader_params { uniform float m_AlphaRef; }

cbuffer static_globals
{
    uniform float3x4 m_V;
    uniform float3x4 m_inv_V;
    uniform float4x4 m_P;
    uniform float4x4 m_VP;

    uniform float4 timers;

    uniform float4 fog_plane;
    uniform float4 fog_params; // x=near*(1/(far-near)), ?,?, w = -1/(far-near)
    uniform float4 fog_color;

    uniform float4 L_ambient; // L_ambient.w = skynbox-lerp-factor
    uniform float3 L_sun_color;
    uniform float3 L_sun_dir_w;
    uniform float3 L_sun_dir_e;
    uniform float4 L_hemi_color;

    uniform float3 eye_position;
    uniform float3 eye_direction;
    uniform float4 eye_direction_lerp;
    uniform float4 eye_position_lerp;

    uniform float4 pos_decompression_params;
    uniform float4 pos_decompression_params2;

    uniform float4 dev_mProject;

    uniform float4 parallax;
    uniform float4 rain_params; // x = raindensity, y = wetness
    uniform float4 screen_res; // Screen resolution (x-Width,y-Height, zw - 1/resolution)

    uniform float4 pp_img_corrections;
    uniform float4 pp_img_cg;

    // new uniform variables - OGSE Team
    // global constants
    uniform float4 ogse_c_screen; // x - fFOV, y - fAspect, z - Zf/(Zf-Zn), w - Zn*tan(fFov/2)
}

float2 get_taa_jitter(float4 hpos) { return hpos.xy + m_taa_jitter.xy * hpos.w; }

float2 get_motion_vector(float4 hpos_curr, float4 hpos_old) { return hpos_curr.xy / hpos_curr.w - hpos_old.xy / hpos_old.w; }

float calc_cyclic(float x)
{
    float phase = 1 / (2 * 3.141592653589f);
    float sqrt2 = 1.4142136f;
    float sqrt2m2 = 2.8284271f;
    float f = sqrt2m2 * frac(x) - sqrt2; // [-sqrt2 .. +sqrt2] !No changes made, but this controls the grass wave (which is violent if I must say)
    return f * f - 1.f; // [-1     .. +1]
}

float2 calc_xz_wave(float2 dir2D, float frac)
{
    // Beizer
    float2 ctrl_A = float2(0.f, 0.f);
    float2 ctrl_B = float2(dir2D.x, dir2D.y);
    return lerp(ctrl_A, ctrl_B, frac); //! This calculates tree wave. No changes made
}

#define SKY_EPS float(0.001)
#define MAT_FLORA 6.0

#endif
