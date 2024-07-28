#pragma once
class RenderLampManager
{
public:
	void Init();
	void Loop();
private:
	bool m_isRunning = false;

	void MainMenu();

	void CreateProject();
	void ChooseRenderer();	
	void OpenProject();
	
};

