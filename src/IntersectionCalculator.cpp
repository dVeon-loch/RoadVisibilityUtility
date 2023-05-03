#include "IntersectionCalculator.h"
#include "Util.h"

#include <cmath>

struct Plane
{
	Vector3 planePoint;
	Vector3 normal;
};

const float cIntersectionCalculator::EPSILON{ 0.0001f };

cIntersectionCalculator::cIntersectionCalculator(std::shared_ptr<std::vector<Triangle>> pRoadSurfaceTriangles) : m_pRoadSurfaceTriangles(pRoadSurfaceTriangles)
{
}

Intersection cIntersectionCalculator::GetIntersectsWithRoad(const Vector3& rayStartVector, const Vector3& targetVector) const
{
	Intersection defaultIntersection;
	for (const auto& triangle : *m_pRoadSurfaceTriangles)
	{
		Vector3 tri_A = triangle.GetA();
		Vector3 tri_B = triangle.GetB();
		Vector3 tri_C = triangle.GetC();

		Vector3 tri_AB = tri_B - tri_A;
		Vector3 tri_AC = tri_C - tri_A;

		Plane trianglePlane{ tri_A, Util::cross(tri_AB, tri_AC).normalized() };

		// Calculating t value of ray where ray intersects triangle plane
		//
		// t = (n dot (planePoint - rayStart) )/ (n dot rayDirection) 

		Vector3 viewRayDirection = (targetVector - rayStartVector).normalized();

		Vector3 trianglePlaneNormal = trianglePlane.normal;

		double normalDotRayDirection = Util::dot(viewRayDirection, trianglePlaneNormal);
		if (std::abs(normalDotRayDirection) < EPSILON)
		{
			return defaultIntersection;
		}

		Vector3 numeratorBracket = trianglePlane.planePoint - rayStartVector;
		double numerator = Util::dot(trianglePlaneNormal, numeratorBracket);

		double t = numerator / normalDotRayDirection;

		// Check if intersection is behind 'viewing ray'
		if (t < 0) 
		{
			return defaultIntersection;
		}

		Vector3 planeIntersectionPoint = rayStartVector + viewRayDirection * t;

		// Test if plane intersection point is within the triangle
		Vector3 AB = tri_B - tri_A;
		Vector3 BC = tri_C - tri_B;
		Vector3 CA = tri_C - tri_A;

		Vector3 A_to_Point = planeIntersectionPoint - tri_A;
		Vector3 B_to_Point = planeIntersectionPoint - tri_B;
		Vector3 C_to_Point = planeIntersectionPoint - tri_C;

		Vector3 A_test_Vec = Util::cross(AB, A_to_Point);
		Vector3 B_Test_Vec = Util::cross(BC, B_to_Point);
		Vector3 C_Test_Vec = Util::cross(CA, C_to_Point);

		bool A_Test_Matches_Normal = Util::dot(A_test_Vec, trianglePlaneNormal);
		bool B_Test_Matches_Normal = Util::dot(B_Test_Vec, trianglePlaneNormal);
		bool C_Test_Matches_Normal = Util::dot(C_Test_Vec, trianglePlaneNormal);

		return { A_Test_Matches_Normal && B_Test_Matches_Normal && C_Test_Matches_Normal, planeIntersectionPoint };
	}
	// Didn't intersect with any triangles
	return defaultIntersection;
}
