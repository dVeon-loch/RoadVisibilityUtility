# RoadVisibilityUtility

The task for the project is simple: Solve for the areas of a road where visibility is impaired.
The data for the road and the line of travel are given in csv files containing real-world coordinate data, and are converted into their corresponding entities within the program (a list of triangles for the road and a simple polyline for the view line).
## Object Diagram
![Object Diagram](docs/Object%20Diagram%20Full.png)


## Design Overview

The main motivation for this project is to design software that meets the following design goals in order of importance:

1. Create a program that solves the problem presented correctly

2. Structure the software so that it follows Object Oriented Programming principles of encapsulation, inheritance, etc.

3. The program must be easy to use and the results must be easy to interpret and verify.

4. The program should perform well and not take excessively long to run or use excessive amounts of memory.

5. The program should be simple to deploy and use.

In addition to the previous design goals, an overall goal was to solve most of the problems with my own code.

As such, when given the choice between finding a 3rd party library to solve a task (such as geometry calculations) and writing my own functions to do so, I generally chose the latter.

## Style and Formatting

The naming convention used is as follows:

- Upper camel case for class names, methods, functions and namespaces

- m_ as a prefix for class member variables. I find this useful when working in classes so that one knows at a glance which variables are members.

- Lower camel case for variables

- The “one class per file, separate header file and cpp file” convention has been mostly followed. In cases where this has not been done comments have been added as justification. This convention makes the project cleaner, especially for small projects such as this one.

- While OOP principles have been followed, I have decided to use inheritance sparingly. In the cases where it is used I have commented my justification for it. However, for this project I don’t see the purpose of over-generalizing and engineering it for some presumed expansion at a later point (e.g. the project should not be designed to work with any file type, format of data etc.)

- Commenting of each class has been performed. However, comments have been used sparingly to comply with “clean code” principles, e.g. code should be self documenting. The names of methods and variables have been made intentionally quite clear and verbose to accommodate this.

## Algorithm/Program Flow

1. Ask user to select polyline and road surface CSV files

2. Assuming step (1) was successful, create SightDistanceCalculator and calculate visibility.

3. Loop over polyline indices

	- For each view vertex: While distance of current target vertex from Vertex <= 350 and target not at end of polyline

		- Check if straight line between view and target intersects with road (See intersection algorithm below)

	- If true, record another target distance where visibility will be impaired for that vertex
	- Else, either end off one visibility range where visibility will be impaired, or move to next target distance.

2. If there were any intersections/visibility failures for the current view vertex, add a SightDistanceFailure to a buffer

	- Return all sight distance failures for all view vertices.

4. Prompt the user to enter a filename and location to save results.

5. Write all sight distance visibility ranges to the file (This is a simplified version of the raw results output)

6. Write all raw result data to the end of the file

7. End program

Intersection Algorithm

1. Input: view vertex and target vertex

2. For each triangle in the road surface:

	- Construct the implicit form of the plane equation that that the triangle lies in

	- Calculate the direction vector of the view ray

	- Calculate the dot product of the view ray direction with the normal of the plane.

		- If the dot product equals zero, return no intersection.

	- Calculate the t value of the ray equation where that ray intersects the plane.

		- If t is negative (ray intersects behind the view), return no intersection.

	- Test if intersection point is within triangle:

		- Construct vectors at each point on the triangle which correspond to the cross product of the vector from that point to the next point on the triangle (in CW order), and the intersection point on the plane.

		- Test the dot product of that vector with the normal of the plane.

		- If all of the vectors match the normal (dot product of that vector with the normal > 0), then return an intersection with that triangle


## Environment Details, Packaging and Deployment

The compiler used was the MSVC compiler packaged with Visual Studio 2022, with the ISO C++14 standard.

For convenience, an installer has been created which will install the program and its dependencies onto the user’s computer and can be found in the releases section of this repository. The installer will also create a desktop shortcut for the user to run the application. Note: All required data has also been bundled with the application, and the file dialogs for opening files will open above the Data Files folder which contains these default files for selection.

## Further Improvement

Additional further improvements are listed below:

- Error handling has been largely ignored in the project. I would like the project to be robust to malformed input files and not being able to open files etc., as well as polylines and road surface files that contain no data, malformed data, etc. As far as I know the latter two cases will be handled but they will not inform the user of anything at this point.

- Interpolate between polyline points to find a more accurate point where visibility impairment ends. Currently, I only know if visibility is now available after checking the next target point along the polyline which is usually around 10 metres away.

- Implement some kind of clustering (e.g. clustering based on distance) of the triangles such that one does not need to search for intersections with every triangle at each target point. The need for this is not apparent currently, as the program runs fast enough with the current data set, but if a more complex road surface is used this would be important to implement.

- Use parallelization when searching for triangle intersections. E.g. OpenCL or CPU vectorization 

 - Convert data to a form compatible with vectorization (AOS -> SOA)

- Use CMake for cross platform building

- Add rendering for the output results. I want to see the road, view line and low visibility areas in a 3D render. 
- Simplify class structure

- Improve the overall GUI, e.g. with Qt or ImGui. Would be better for selecting the files etc.
 - Also show raw results in GUI in a nicer form


