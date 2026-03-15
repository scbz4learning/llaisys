target("llaisys-device-nvidia")
    set_kind("static")
    set_languages("cxx17")
    set_warnings("all", "error")

    if not is_plat("windows") then
        add_cxflags("-fPIC", "-Wno-unknown-pragmas")
    end

    add_defines("ENABLE_NVIDIA_API")

    -- CUDA source files
    add_files("../src/device/nvidia/*.cu")

    -- Add stub implementations for ops (placeholders for future CUDA kernels)
    add_files("../src/ops/*/nvidia/*.cu")

    -- Ensure PIC for shared library linking
    add_cuflags("-Xcompiler=-fPIC")

    -- Link against CUDA runtime. xmake will use nvcc for .cu files if available.
    add_links("cudart")

    on_install(function (target) end)
target_end()
