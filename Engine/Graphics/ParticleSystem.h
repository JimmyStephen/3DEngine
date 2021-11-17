#pragma once
#include "Framework/System.h"
#include "Texture.h"
#include "Math/MathTypes.h"
#include <Vector>


namespace nc
{
	class ParticleSystem : public GraphicsSystem
	{
	public:
		struct Particle
		{
			glm::vec3 position;
			glm::vec3 prevPosition;
			glm::vec3 velocity;
			std::shared_ptr<Texture> texture;

			float lifetime;
			bool isActive{ false };

			static bool isNotActive(Particle particle) { return particle.isActive == false; }
		};

	public:
		void Startup() override;
		void Shutdown() override;

		void Update(float dt) override;
		void Draw(class Renderer* renderer) override;

		void Create(const glm::vec3& position, size_t count, float lifetime, std::shared_ptr<Texture> texture, float speed);

	private:
		std::vector<Particle> particles;

	};
}