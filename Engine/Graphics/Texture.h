#pragma once
#include "Resource/Resource.h"
#include "Math/MathTypes.h"
#include <SDL.h>

namespace nc
{
	
	class Texture : public Resource
	{
	public:
		bool Load(const std::string& name, void* data) override;

		Texture() {}
		Texture(class Renderer* renderer);

		bool Create(SDL_Surface* surface);

		glm::vec3 GetSize() const;

		friend class Renderer;

	private:
		SDL_Texture* texture = nullptr;
		SDL_Renderer* renderer = nullptr;
	};


}