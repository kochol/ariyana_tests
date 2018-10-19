#include <ari/Engine.hpp>
#include "ari/Program.hpp"
#include "ari/en/World.hpp"
#include "ari/en/Entity.hpp"
#include "ari/en/gui/GuiSystem.hpp"
#include "ari/en/gui/Window.hpp"
#include "ari/en/gui/CheckBox.hpp"
#include "ari/en/gui/Label.hpp"
#include "ari/en/gui/Dock.hpp"

class GuiProgram: public ari::IProgram
{
public:
	explicit GuiProgram(const char* programName)
		: IProgram(programName)
	{
	}

	~GuiProgram() override = default;

	void Init() override
	{
		// Init entity system
		m_world.AddSystem(&m_gui_system);
		m_world.AddEntity(&m_gui_entity);
		m_gui_entity.AddChild(&m_dock);
	//	m_dock.AddChild(&m_dock_child);
		m_gui_entity.AddChild(&m_window);
		m_window.AddChild(&m_label);
		m_window.AddChild(&m_check_box);
		m_label.Text = "Test GUI";
		m_window.Pos.x = m_window.Pos.y = 100;
		m_window.Size.x = m_window.Size.y = 200;
		m_window.Name = "Test window";
		m_check_box.Label = "OK";
		m_dock._root = true;
		m_dock.Label = "Root Dock";
		m_dock.Size.x = m_dock.Size.y = 500;	
		m_label2.Text = "Dock text";
	//	m_dock_child.AddChild(&m_label2);
		m_dock_child.Label = "Child Dock";
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

	ari::GuiSystem		m_gui_system;
	ari::World			m_world;
	ari::Entity			m_gui_entity;
	ari::Window			m_window;
	ari::CheckBox		m_check_box;
	ari::Label			m_label, m_label2;
	ari::Dock			m_dock, m_dock_child;
};

int main()
{
	ari::Engine* p_device = new ari::Engine();
	ari::InitParams p{};
	p.Program = new GuiProgram("GUI");
	p_device->Init(p);

	while (p_device->Run())
	{
		
	}
	delete p_device;
	return 0;
}
