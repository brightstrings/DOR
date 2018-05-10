#include "Util.h"
#include "corecrt_math.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"

float AngleDifference(float a1, float a2) 
{
	//dir in degrees
	//dir1 = 20;
	//dir2 = 210;

	//V1
	//FMath::
	float x1 = cos(FMath::DegreesToRadians(a1));
	float y1 = sin(FMath::DegreesToRadians(a1));

	//V2
	float x2 = cos(FMath::DegreesToRadians(a2));
	float y2 = sin(FMath::DegreesToRadians(a2));

	//difference angle
	float dot = x1*x2 + y1*y2;

	float len1 = sqrt(x1*x1 + y1*y1);
	float len2 = sqrt(x2*x2 + y2*y2);

	float det = x1*y2 - y1*x2;      //# determinant
							  //theta = arccos(dot/(len1*len2));

	float theta = atan2(det, dot);

	float difference = FMath::RadiansToDegrees(theta);
	return difference;
}