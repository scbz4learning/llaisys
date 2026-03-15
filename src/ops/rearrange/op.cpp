#include "op.hpp"

#include "../../utils.hpp"
#include <cstring>

#ifdef ENABLE_NVIDIA_API
#include "nvidia/rearrange_nvidia.hpp"
#endif

namespace llaisys::ops {
void rearrange(tensor_t out, tensor_t in) {
    CHECK_SAME_DEVICE(out, in);
    CHECK_SAME_SHAPE(out->shape(), in->shape());
    ASSERT(out->isContiguous() && in->isContiguous(), "Rearrange: tensors must be contiguous.");

    // CPU fallback
    if (out->deviceType() == LLAISYS_DEVICE_CPU) {
        // Simple copy for now
        std::memcpy(out->data(), in->data(), out->numel() * llaisys::utils::dsize(out->dtype()));
        return;
    }

    llaisys::core::context().setDevice(out->deviceType(), out->deviceId());

    switch (out->deviceType()) {
    case LLAISYS_DEVICE_CPU:
        std::memcpy(out->data(), in->data(), out->numel() * llaisys::utils::dsize(out->dtype()));
        return;
#ifdef ENABLE_NVIDIA_API
    case LLAISYS_DEVICE_NVIDIA:
        return nvidia::rearrange(out, in);
#endif
    default:
        EXCEPTION_UNSUPPORTED_DEVICE;
    }
}
} // namespace llaisys::ops
