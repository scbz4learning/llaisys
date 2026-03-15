#pragma once

#include "../op.hpp"

namespace llaisys::ops::nvidia {

void swiglu(tensor_t out, tensor_t gate, tensor_t up);

} // namespace llaisys::ops::nvidia
