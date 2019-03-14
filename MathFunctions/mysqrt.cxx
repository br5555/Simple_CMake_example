#include "MathFunctions.h"
#include "Table.h"

double mysqrt(double input)
{
	#if defined (HAVE_LOG) && defined (HAVE_EXP)
		return exp(log(input)*0.5);
	#elif defined (HAVE_LOG_CXX) && defined (HAVE_EXP_CXX)
		return exp(log(input)*0.5);
	#else
		return sqrt(input);
	#endif

}
