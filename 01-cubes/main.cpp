#include <ari/Engine.hpp>
#include "ari/en/3d/RenderSystem.hpp"
#include "ari/Program.hpp"

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
		m_pRen = new ari::RenderSystem();
	}

	bool Update() override
	{
		return true;
	}

	int Shutdown() override
	{
		return 0;
	}

	ari::RenderSystem* m_pRen;

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
