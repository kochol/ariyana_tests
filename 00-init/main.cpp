#include <ari/Engine.hpp>

int main()
{
	ari::Engine* p_device = new ari::Engine();
	ari::InitParams p{};
	p_device->Init(p);
	while (p_device->Run())
	{
		
	}
	delete p_device;
	return 0;
}