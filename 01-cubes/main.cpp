#include <ari/Engine.hpp>
#include "ari/en/3d/RenderSystem.hpp"
#include "ari/Program.hpp"
#include "ari/en/World.hpp"
#include "ari/en/Entity.hpp"
#include "ari/en/3d/BoxShape.hpp"
#include "ari/en/3d/Camera.hpp"
#include "ari/en/3d/SceneSystem.hpp"

class RotatorSystem: public ari::System
{
public:
	void Update(ari::World* p_world, UpdateState state) override
	{
		for (auto n : nodes)
		{
			n->Rotation.x += 0.05f;
			n->Rotation.y += 0.03f;
		}
	}

	void Configure(ari::World* p_world) override { }
	void Unconfigure(ari::World* p_world) override { }
	Type GetSystemType() override { return  Type::GameplaySystem; }
	bool NeedUpdateOnState(UpdateState state) override
	{
		return state == UpdateState::GameplayState;
	}

	tinystl::vector<ari::Node3D*> nodes;
};

class CubesProgram: public ari::IProgram
{
public:
	explicit CubesProgram(const char* programName)
		: IProgram(programName)
	{
	}

	~CubesProgram() override = default;

	void Init() override
	{
		m_world.SetUpdateType(ari::World::UpdateType::Sync);
		// Init entity system
		m_world.AddSystem(&m_ren);
		m_world.AddSystem(&m_scene_system);
		m_world.AddSystem(&m_rotator_system);

		// Create entities
		m_world.AddEntity(&m_eBox);
		auto rootNode = m_eBox.AddChild(new ari::Node3D());
		m_rotator_system.nodes.push_back(rootNode);
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++)
			{
				auto box = rootNode->AddChild(new ari::BoxShape());
				box->Position.Set(x * 3, y * 3, 0);
				m_rotator_system.nodes.push_back(reinterpret_cast<ari::Node3D*>(box));
			}
		
		// Set up camera
		m_world.AddEntity(&m_eCamera);
		m_camera.Position.Set(0.0f, 0.0f, 24.0f);
		m_eCamera.AddChild(&m_camera);
	}

	bool Update(uint32_t frame_number, float elasped) override
	{
		m_world.Update(elasped);
		return true;
	}

	int Shutdown() override
	{
		return 0;
	}

	ari::RenderSystem	m_ren;
	ari::SceneSystem	m_scene_system;
	RotatorSystem		m_rotator_system;
	ari::World			m_world;
	ari::Entity			m_eBox;
	ari::Entity			m_eCamera;
	ari::Camera			m_camera;
};

int main()
{
	ari::Engine* p_device = new ari::Engine();
	ari::InitParams p{};
	p.Program = new CubesProgram("Cubes");
	p_device->Init(p);

	while (p_device->Run())
	{
		
	}
	return 0;
}
