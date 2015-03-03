#ifndef GAME_H
#define GAME_H

#include "Azul.h"


class Game : public Engine
{

public:
	Game( const char * const windowName, int widthScreen, int heightScreen );

	void Initialize() override;
	void LoadContent() override;
	void Update() override;
	void Draw() override;
	void UnLoadContent() override;

	//User Defined
	virtual void InitializeGameContent();
	virtual void LoadGameContent();
	virtual void UnloadGameContent();
	virtual void TerminateGameContent();

private:

};



#endif 