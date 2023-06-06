# RoadVisibilityUtility

This project is intended to be an example or test case of my modern C++ learning and development. The task for the project is simple: Solve for the areas of a road where visibility is impaired.
The data for the road and the line of travel are given in csv files containing real-world coordinate data, and are converted into their corresponding entities within the program (a list of triangles for the road and a simple polyline for the view line).

## Possible Improvements
These are some improvements that I want to make to this project to either make it more computationally efficient, cleaner, or just generally better.
- Add rendering for the output results. I want to see the road, view line and low visibility areas in a 3D render. 
- Simplify class structure
- Convert data to a form compatible with vectorization (AOS -> SOA). This would be particularly useful for the triangle intersection tests.
- Improve the overall GUI, e.g. with Qt or ImGui. Would be better for selecting the files etc.
 - Also show raw results in GUI in a nicer form
