#include <math.h>

#include "data_types.h"

using namespace utils;

float Vector3::getLength()
{
	return sqrtf((x * x) + (y * y) + (z + z));
}