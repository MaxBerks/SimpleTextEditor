// CppCon '20 Mike Shah ConfigurationManager class + mine additions
export module ConfigurationManager;

import Singleton;

export class ConfigurationManager final: public Singleton<ConfigurationManager>
{
public:
	
	const int GetWindowWidth()  noexcept;
	const int GetWindowHeight() noexcept;

	void SetWindowWidth(const int NewWidth)    noexcept;
	void SetWindowHeight(const int NewHeight)  noexcept;

private:
	int m_WindowWidth;
	int m_WindowHeight;

private:
	ConfigurationManager() = default;
};

const int ConfigurationManager::GetWindowWidth()
{
	return this->m_WindowWidth;
}
const int ConfigurationManager::GetWindowHeight()
{
	return this->m_WindowHeight;
}

void ConfigurationManager::SetWindowWidth(const int NewWidth)
{
	this->m_WindowWidth = NewWidth;
}
void ConfigurationManager::SetWindowHeight(const int NewHeight)
{
	this->m_WindowHeight = NewHeight;
}
