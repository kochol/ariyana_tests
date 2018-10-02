#include <ari/Engine.hpp>
#include "ari/en/3d/RenderSystem.hpp"
#include "ari/Program.hpp"
#include "ari/en/World.hpp"
#include "ari/en/Entity.hpp"
#include "ari/en/3d/BoxShape.hpp"

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
		// Init entity system
		m_world.AddSystem(&m_ren);

		// Create entities
		m_world.AddEntity(&m_Box);
		m_Box.AddChild(new ari::BoxShape);
		
	}

	bool Update() override
	{
		return true;
	}

	int Shutdown() override
	{
		return 0;
	}

	ari::RenderSystem	m_ren;
	ari::World			m_world;
	ari::Entity			m_Box;
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
