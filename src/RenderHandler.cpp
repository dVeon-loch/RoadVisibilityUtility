#include "RenderHandler.h"

#include "Renderer.h"

#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw_gl3.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"
#include <numeric>
#include <algorithm>

#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Util.h"


RenderHandler::RenderHandler(std::shared_ptr<std::vector<Triangle>> roadSurfaceTriangles, std::shared_ptr<Polyline> polyline, std::shared_ptr<std::vector<SightDistanceFailure>> sightDistanceFailures) : m_roadSurfaceTriangles(roadSurfaceTriangles), m_Polyline(polyline), m_SightDistanceFailures(sightDistanceFailures)
{
}

RenderHandler::~RenderHandler()
{
}

void RenderHandler::DrawRoadSurface(Color color) const
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	int windowWidth = 640;
	int windowHeight = 480;
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(windowWidth, windowHeight, "Application", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// Limit the frame rate to the same as our monitor
	glfwSwapInterval(1);

	// Must do this after creating valid context
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW Failed to initiate." << std::endl;
		return;
	}

	{
		std::vector<float> triangleVertices;
		std::vector<float> xPositions;
		std::vector<float> yPositions;
		std::vector<float> zPositions;
		auto test = m_roadSurfaceTriangles.get();
		for (const auto& triangle : *test)
		{
			triangleVertices.push_back((float)triangle.GetA().x());
			triangleVertices.push_back((float)triangle.GetA().y());
			triangleVertices.push_back((float)triangle.GetA().z());
			xPositions.push_back((float)triangle.GetA().x());
			yPositions.push_back((float)triangle.GetA().y());
			zPositions.push_back((float)triangle.GetA().z());
			triangleVertices.push_back((float)triangle.GetB().x());
			triangleVertices.push_back((float)triangle.GetB().y());
			triangleVertices.push_back((float)triangle.GetB().z());
			xPositions.push_back((float)triangle.GetB().x());
			yPositions.push_back((float)triangle.GetB().y());
			zPositions.push_back((float)triangle.GetB().z());
			triangleVertices.push_back((float)triangle.GetC().x());
			triangleVertices.push_back((float)triangle.GetC().y());
			triangleVertices.push_back((float)triangle.GetC().z());
			xPositions.push_back((float)triangle.GetC().x());
			yPositions.push_back((float)triangle.GetC().y());
			zPositions.push_back((float)triangle.GetC().z());
		}
		float* positions = triangleVertices.data();
		std::vector<unsigned int> a(triangleVertices.size());
		std::iota(a.begin(), a.end(), 1);
		// Indices to draw a triangle
		unsigned int* indices = a.data();



		VertexArray va;
		VertexBuffer vb(positions, triangleVertices.size()  * sizeof(float));
		VertexBufferLayout layout;
		layout.Push<float>(3);

		va.AddBuffer(vb, layout);

		IndexBuffer ib(indices, triangleVertices.size());

		float xMax = *std::max_element(xPositions.begin(), xPositions.end());
		float xMin = *std::min_element(xPositions.begin(), xPositions.end());

		float yMax = *std::max_element(yPositions.begin(), yPositions.end());
		float yMin = *std::min_element(yPositions.begin(), yPositions.end());

		float zMax = *std::max_element(zPositions.begin(), zPositions.end());
		float zMin = *std::min_element(zPositions.begin(), zPositions.end());
		// 4:3 aspect ratio
		glm::mat4 proj = glm::ortho(xMin, (float)xMax,
			yMin, (float)yMax,
			zMin-10.f, zMax+10.f);

		

		glm::mat4 view = glm::mat4(1.0f);
		// note that we're translating the scene in the reverse direction of where we want to move
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));


		Shader shader(Util::OpenShaderFileDialog("Shader File"));
		shader.Bind();

		va.Unbind();
		vb.Unbind();
		ib.Unbind();
		shader.Unbind();

		Renderer renderer;

		renderer.EnableDepthTest();



		GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));
			


		// Setup ImGui binding
		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();

		bool show_demo_window = true;
		bool show_another_window = false;
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
		static float f = 0.0f;

		auto translationA = glm::vec3(200, 200, 0);

		float increment = 0.05f;
		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			renderer.Clear();

			ImGui_ImplGlfwGL3_NewFrame();
			shader.Bind();

			{
				glm::mat4 model = glm::translate(glm::mat4(1.f), translationA);
				glm::mat4 mvp = proj * view * model;
				shader.Bind();
				shader.SetUniformMat4f("u_MVP", mvp);
				shader.SetUniform4f("u_Color", 1.f, 1.f, 1.f,1.f);
				renderer.Draw(va, ib, shader);
			}

			{
				ImGui::SliderFloat3("translation A", &translationA.x, 0.0f, (float)windowWidth);            // Edit 1 float using a slider from 0.0f to 1.0f    
				ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			}

			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
	}

	// Cleanup
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
}


	void RenderHandler::DrawPolyline(Color color) const
{
}

void RenderHandler::DrawResults(Color roadColor, Color polylineColor, Color viewLineColor, Color failedTriangleColor, Color polylineFailedColor) const
{
}




