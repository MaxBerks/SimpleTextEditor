export module DirectMediaLayerFacade;

extern "C"
{ 
	#include <SDL.h>
}


export class DirectMediaLayerWindowFacade final
{
public:
	static DirectMediaLayerWindowFacade& GetInstance();


	

private:

	SDL_Window* m_pWindow;


private:
	DirectMediaLayerWindowFacade() = default;

	DirectMediaLayerWindowFacade(const DirectMediaLayerWindowFacade&) = delete;
	DirectMediaLayerWindowFacade& operator=(const DirectMediaLayerWindowFacade&) = delete;
	DirectMediaLayerWindowFacade(DirectMediaLayerWindowFacade&&) = delete;
	DirectMediaLayerWindowFacade& operator=(DirectMediaLayerWindowFacade&&) = delete;
};

DirectMediaLayerWindowFacade& DirectMediaLayerWindowFacade::GetInstance()
{
	static DirectMediaLayerWindowFacade* Instance = new DirectMediaLayerWindowFacade();
	return *Instance;
}

export class DirectMediaLayerFacade final
{
public:
		


private:



	SDL_Window*   m_pWindow;
	SDL_Texture*  m_pTexture;
	SDL_Renderer* m_pRenderer;
};