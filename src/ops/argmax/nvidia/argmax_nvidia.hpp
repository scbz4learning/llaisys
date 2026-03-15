#pragma once

#include "../op.hpp"

namespace llaisys::ops::nvidia {

void argmax(tensor_t max_idx, tensor_t max_val, tensor_t vals);

} // namespace llaisys::ops::nvidia
