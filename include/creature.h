#pragma once

#include <include/geometry.h>
#include <vector>
#include <array>

using namespace std;

struct Creature : public MyMesh {
	GLuint vao;
	GLuint texUnits[MAX_TEXTURES];
	texType texTypes[4];
	float transform[16];
	float max_pos_vert[3];
	float min_pos_vert[3];
	GLuint numIndexes;
	unsigned int type;
	struct Material mat;

	float x, y, z;
	float vx, vy, vz;
	float speed;
	float oscillationSpeed;

	Creature(const MyMesh mesh, std::array<float, 3> pos, std::array<float, 3> v, float initSpeed) {
		vao = mesh.vao;

		std::copy(std::begin(mesh.texUnits), std::end(mesh.texUnits), texUnits);
		std::copy(std::begin(mesh.texTypes), std::end(mesh.texTypes), texTypes);
		std::copy(std::begin(mesh.transform), std::end(mesh.transform), transform);
		std::copy(std::begin(mesh.max_pos_vert), std::end(mesh.max_pos_vert), max_pos_vert);
		std::copy(std::begin(mesh.min_pos_vert), std::end(mesh.min_pos_vert), min_pos_vert);

		numIndexes = mesh.numIndexes;
		type = mesh.type;
		mat = mesh.mat;

		x = pos[0];
		y = pos[1];
		z = pos[2];

		vx = v[0];
		vy = v[1];
		vz = v[2];

		speed = initSpeed;
		oscillationSpeed = 0.0f;
	}

	void update(float deltaTime, float speedMultiplier, float maxDistance, float radius);
	void rebirth(float radius);
	void applyShakeAnimation(float time, float shakeAmplitude);
};

Creature createCreatureMesh(float radius, float initialSpeed);
vector<Creature> createCreatureMeshes(int numberOfCreatures, float radius, float initialSpeed);
array<float, 3> computeRandomPosition(float radius);
array<float, 3> computeRandomDirection();