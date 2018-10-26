#include <ari/Engine.hpp>

int main()
{
	std::unique_ptr<ari::Engine> p_device(new ari::Engine());
	std::shared_ptr<ari::InitParams> p(new ari::InitParams);
	p_device->Init(p);

	while (p_device->Run())
	{

	}
	return 0;
}
