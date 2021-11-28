#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <math.h>

#include "data_types.h"

using namespace utils;

float Vector3::getLength()
{
	return sqrtf((x * x) + (y * y) + (z + z));
}

float* Matrix4x4::getValuePtr()
{
	return glm::value_ptr(matrix);
}