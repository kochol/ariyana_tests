#include <ari/Engine.hpp>
#include "ari/en/3d/RenderSystem.hpp"
#include "ari/Program.hpp"
#include "ari/en/World.hpp"
#include "ari/en/Entity.hpp"
#include "ari/en/3d/BoxShape.hpp"
#include "ari/en/3d/Camera.hpp"
#include "ari/en/3d/SceneSystem.hpp"

class CubesProgram: public ari::IProgram
{
public:
	explicit CubesProgram(const char* programName)
		: IProgram(programName)
	{
	}

	~CubesProgram() override
	{
		
	}

	void Init() override
	{
		m_world.SetUpdateType(ari::World::UpdateType::Sync);
		// Init entity system
		m_world.AddSystem(&m_ren);
		m_world.AddSystem(&m_scene_system);

		// Create entities
		m_world.AddEntity(&m_eBox);
		m_eBox.AddChild(new ari::BoxShape());
		
		// Set up camera
		m_world.AddEntity(&m_eCamera);
		m_camera.Position.Set(3.0f, 3.0f, 3.0f);
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
