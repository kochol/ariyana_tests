#include <ari/Device.hpp>

int main()
{
	ari::Device* p_device = new ari::Device();
	ari::InitParams p{};
	p_device->Init(p);
	getchar();
	return 0;
}