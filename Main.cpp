#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>

#include <chrono>
#include <string>

#include <iostream>

#include "gui.h"
#include "core.h"


#include "renderer.h"
#include "importer.h"
#include "model.h"
#include "data_struct.h"
#include "data_types.h"

using namespace utils;

gui::Window window = gui::Window(800, 600, "Hello World");
renderer::ShaderProgram* sp;

void init() 
{
	window.create();
	core::init();
}

void update() 
{
	window.update();
}

void render()
{	
	
	window.render();
}

void run() 
{
	init();

	//setp 1
	std::string vstr = renderer::readShader("VertexShader.shader");
	std::string fstr = renderer::readShader("FragmentShader.shader");

	const char* vsrc = vstr.c_str();
	const char* fsrc = fstr.c_str();

	renderer::Shader vs = renderer::loadShader(vsrc, GL_VERTEX_SHADER);
	renderer::Shader fs = renderer::loadShader(fsrc, GL_FRAGMENT_SHADER);

	renderer::ShaderProgram sp(vs, fs);

	//step 2 load mesh
	model::Mesh mesh = importer::loadModel("Small Floating Island.dae");
	data_struct::loadMesh(mesh);

	//setup matrices
	Matrix4x4 transform{};
	transform.matrix = glm::mat4(1.0f);

	Matrix4x4 camera{};
	camera.matrix = glm::lookAt(glm::vec3(0, 0.5, 3), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));

	Matrix4x4 projection{};
	projection.matrix = glm::perspective(70.0f, (float)800 / (float)600, 0.1f, 100.0f);

	Vector3 v{};
	v.x = 0;
	v.y = 1;
	v.z = 0;

	float seconds = 0;
	float speed = 0.001f;
	while (window.exists())
	{
		auto start = std::chrono::high_resolution_clock::now();
		
		update();
		transform.matrix = glm::rotate(transform.matrix, speed, glm::vec3(0, 1, 0));
		speed += 0.0000002f;

		renderer::clear();
		sp.start();
		sp.uploadMatrix4x4("transform", transform);
		sp.uploadMatrix4x4("camera", camera);
		sp.uploadMatrix4x4("projection", projection);
		sp.uploadVector3("c", v);
		//render objects stuff here
		renderer::renderMesh(mesh);
		//------
		render();
		sp.stop();

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> deltaTime = end - start;

		int fps = (int)(1 / deltaTime.count());
		seconds += deltaTime.count();

		if (seconds >= 0.1f)
		{
			std::string title =  "Ignite | FPS: " + std::to_string(fps);
			window.setTitle(title.c_str());
			seconds = 0;
		}
	}
}

int main() 
{
	run();

	return 0;
}