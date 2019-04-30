#include "utils.h"
#include <ctime>
#include <cstdlib>

float randRange(float begin, float end)
{
	return begin + static_cast<float>(rand() / static_cast<float>(RAND_MAX)) * (end - begin);
}
