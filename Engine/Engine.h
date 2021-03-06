#pragma once

#define REGISTER_CLASS(class) nc::ObjectFactory::Instance().Register<class>(#class);
#define CREATE_ENGINE_OBJECT(class) nc::ObjectFactory::Instance().Create<nc::class>(#class);

//systems
#include "Audio/AudioSystem.h"

//components
#include "Component/Component.h"
#include "Component/GraphicsComponent.h"
#include "Component/PhysicsComponent.h"
#include "Component/AudioComponent.h"
#include "Component/CameraComponent.h"
#include "Component/MeshComponent.h"
#include "Component/FreeCameraController.h"
#include "Component/ModelComponent.h"
#include "Component/LightComponent.h"

//math
#include "Math/MathTypes.h"
#include "Math/Random.h"
#include "Math/MathUtil.h"
#include "Math/Transform.h"

//graphics
#include "Graphics/Renderer.h"
#include "Graphics/Texture.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/Model.h"

//framework
#include "Framework/System.h"
#include "Framework/EventSystem.h"
#include "Framework/Singleton.h"
#include "Framework/Factory.h"

//resource
#include "Resource/ResourceSystem.h"

//Objects
#include "Object/Actor.h"
#include "Object/Scene.h"

//core
#include "Core/Utilities.h"
#include "Core/FileSystem.h"
#include "Core/FileIO.h"
#include "Core/Time.h"

//InputSystem
#include "Input/InputSystem.h"

#include <vector>
#include <memory>
#include <algorithm>

namespace nc
{
	using ObjectFactory = Singleton<Factory<std::string, Object>>;
	class Engine
	{
	public:
		FrameTimer time;

		void Startup();
		void Shutdown();
		void Update();
		void Draw(Renderer* renderer);

		template<typename T>
		T* Get();


	private:
		std::vector<std::unique_ptr<System>> systems;

	};


	template<typename T>
	inline T* Engine::Get()
	{
		for (auto& system : systems)
		{
			if (dynamic_cast<T*>(system.get())) return dynamic_cast<T*>(system.get());
		}

		return nullptr;
	}
}