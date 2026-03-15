#pragma once

#include "../op.hpp"

namespace llaisys::ops::nvidia {

void embedding(tensor_t out, tensor_t index, tensor_t weight);

} // namespace llaisys::ops::nvidia
