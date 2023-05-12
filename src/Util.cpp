#include "Util.h"

#include "../dependencies/tinyfiledialogs.h"
#include <fstream>
#include <regex>
#include <cmath>

bool Util::isNumber(std::string string)
{
	return std::regex_match(string, std::regex(("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?")));
}

float Util::GetDistance(Vector3 start, Vector3 end)
{
	return std::sqrt(std::pow(end.x() - start.x(), 2) + std::pow(end.y() - start.y(), 2) + std::pow(end.z() - start.z(), 2));
}
// A = a1 * i + a2 * j + a3 * k and B = b1 * i + b2 * j + b3 * k. Then cross product is calculated as cross product = (a2 * b3 – a3 * b2) * i + (a3 * b1 – a1 * b3) * j + (a1 * b2 – a2 * b1) * k, where [(a2 * b3 – a3 * b2), (a3 * b1 – a1 * b3), (a1 * b2 – a2 * b1)] are the coefficient of unit vector along i, j and k directions.
Vector3 Util::cross(Vector3 vec1, Vector3 vec2)
{
	double i = vec1.y() * vec2.z() - vec1.z() * vec2.y();
	double j = vec1.z() * vec2.x() - vec1.x() * vec2.z();
	double k = vec1.x() * vec2.y() - vec1.y() * vec2.x();
	return Vector3{i , j, k};
}

double Util::dot(Vector3 vec1, Vector3 vec2)
{
	return vec1.x() * vec2.x() + vec1.y() * vec2.y() + vec1.z() * vec2.z();
}

std::string Util::OpenChooseCsvFileDialog(const std::string& title)
{
	char const* lFilterPatterns[1] = { "*.csv" };
	return std::string(tinyfd_openFileDialog(
		title.c_str(),
		"./",
		1,
		lFilterPatterns,
		NULL,
		0
	));
}

std::string Util::OpenSaveResultsFileDialog()
{
	char const* lFilterPatterns[1] = { "*.txt" };
	return tinyfd_saveFileDialog(
		"Save Results to File",
		"C:\\",
		1,
		lFilterPatterns,
		NULL
	);
}

std::string Util::OpenShaderFileDialog(const std::string& title)
{
	char const* lFilterPatterns[1] = { "*.shader" };
	return std::string(tinyfd_openFileDialog(
		title.c_str(),
		"./",
		1,
		lFilterPatterns,
		NULL,
		0
	));
}

void Util::SaveResultsToFile(std::shared_ptr<std::vector<SightDistanceFailure>> sightDistanceFailures)
{
	std::ofstream file(Util::OpenSaveResultsFileDialog());
	file << std::fixed;
	file.clear();
	if (file.is_open())
	{

		for (const auto& failure : *sightDistanceFailures)
		{
			Vector3 failureVertex = failure.GetVertex();
			file << "At Vertex " << failure.GetDistanceFromStartMetres() << " metres from the start, visibility is impaired in the following distance ranges: " << std::endl;
			for (const auto& range : failure.GetImpairedVisibilityRanges())
			{
				file << range.first << "m to " << range.second << "m" << std::endl;
			}
			file << "\n";
		}
		file << "\n\nRaw Results:" << std::endl;
		file << "------------------------------\n" << std::endl;
		for (const auto& failure : *sightDistanceFailures)
		{
			Vector3 failureVertex = failure.GetVertex();
			file << "Vertex: " << failureVertex << ", " << failure.GetDistanceFromStartMetres() << "m from the start has visibility failures with the following parameters:" << std::endl;
			for (const auto& intersectionAndDistance : failure.GetIntersectionsAndDistances())
			{
				file << "IP: " << intersectionAndDistance.first << ", Target distance along polyline: " << intersectionAndDistance.second << "m" << std::endl;
			}
			file << "\n";
		}
	}
	file.flush();
	file.close();
}
