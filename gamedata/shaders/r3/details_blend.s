--Normal pass, with bumpmapping
function normal (shader, t_base, t_second, t_detail)
    shader:begin("deffer_grass","deffer_grass")
    : fog (false)
    shader:dx10stencil (true, cmp_func.always,
                            255 , 127,
                            stencil_op.keep, stencil_op.replace, stencil_op.keep)
    shader:dx10stencil_ref (1)
    shader:dx10cullmode (1)

    shader:dx10texture("s_base", t_base)

    --local opt = shader:dx10Options()
    --shader:dx10texture("s_bump", "levels\\" .. opt:getLevel() .. "\\" .. t_base.."_bump")

    shader:dx10texture("s_bump", t_base.."_bump")
    shader:dx10texture("s_bumpX", t_base.."_bump#")

    shader:dx10texture("s_waves", "fx\\wind_wave")

    shader:dx10sampler("smp_base")
    shader:dx10sampler("smp_linear")
    shader:dx10sampler("smp_linear2")
end