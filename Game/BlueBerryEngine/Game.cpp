#include "Game.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "ResourceManager.h"


// Camera vars
Vect CamPos(50,50,100.0f);	
Matrix CamRot( IDENTITY );	// No rotation initially
Vect CamUp(0,1,0);			// Using local Y axis as 'Up'
Vect CamDir(0,0,1);			// Using the local Z axis as 'forward'
float CamTranSpeed = 2;
float CamRotSpeed = .02f;

//-----------------------------------------------------------------------------
//  Game::Game()
//		Game Engine Constructor
//-----------------------------------------------------------------------------
Game::Game( const char * const windowName, int widthScreen, int heightScreen )
: Engine( windowName, widthScreen, heightScreen)
{
	printf("Game(): started\n");
	glfwSetWindowPos(this->window, 20, 30);
}

//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void Game::Initialize()
{

	TimeManager::InitTimeManager(); //&stopWatch,&totalWatch);
	InitializeGameContent();
}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Game::LoadContent()
{
	// Converting models from FBX format to AZUL format
		//		Note: The converter is quite verbose. Piping the output to DebugInfo.txt hides the text
		printf("Converting FBX to AZUL\n");
		system("ConverterDebug space_frigate.fbx > DebugInfo.txt");
		system("ConverterDebug Axis.fbx > DebugInfo.txt");
		system("ConverterDebug Plane.fbx > DebugInfo.txt");
		system("ConverterDebug Cottage.fbx > DebugInfo.txt");
		printf("Converting completed\n");


	// Camera Setup ---------------------------------------

		// Initially setup the camera
		CameraMan::GetCurrent()->setViewport( 0, 0, this->screenWidth, this->screenHeight);
		CameraMan::GetCurrent()->setPerspective( 45, float(this->screenWidth)/float(this->screenHeight), 1, 5000);

		// Position and Orient Camera
		//		First we create a rotation matrix pointing (z) towards the target
		Vect Target(0,0,0);
		CamRot = Matrix(Quat(ROT_ORIENT, Target - CamPos, CamUp));

		//			Second: we set the camera to its position and pointing toward the target
		CameraMan::GetCurrent()->setOrientAndPosition( CamUp * CamRot, CamPos + CamDir * CamRot, CamPos);

		// Computes all the parameters for the camera
		//   Note: This demo has a fixed camera
		CameraMan::GetCurrent()->updateCamera();
		LoadGameContent();
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void Game::Update()
{
	// Time update.
	TimeManager::TickTock();
	PrivSceneManager::UpdateCurrentScene();
	// Camera translation movement (not using time-based values for simplicity)
	if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_W ) )
	{
		CamPos += Vect(0,0,1) * CamRot * CamTranSpeed;
	}
	else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_S ) )
	{
		CamPos += Vect(0,0,1) * CamRot * - CamTranSpeed;
	}

	if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_A ) )
	{
		CamPos += Vect(1,0,0) * CamRot * CamTranSpeed;
	}
	else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_D ) )
	{
		CamPos += Vect(1,0,0) * CamRot * -CamTranSpeed;
	}

	// Camera Rotation movement (not using time-based values for simplicity)
	if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_LEFT ) )
	{
		CamRot *= Matrix( ROT_Y, CamRotSpeed );
	}
	else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_RIGHT ) )
	{
		CamRot *= Matrix( ROT_Y, -CamRotSpeed );
	}

	if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_UP ) )
	{
		CamRot *= Matrix( Quat( ROT_AXIS_ANGLE, Vect(1,0,0) * CamRot, -CamRotSpeed) );
	}
	else if ( InputMan::GetKeyboard()->GetKeyState(AZUL_KEY::KEY_DOWN ) )
	{
		CamRot *= Matrix( Quat( ROT_AXIS_ANGLE, Vect(1,0,0) * CamRot, CamRotSpeed) );
	}

	// Update the camera settings
	CameraMan::GetCurrent()->setOrientAndPosition( CamUp * CamRot, CamPos + CamDir * CamRot, CamPos);
	CameraMan::GetCurrent()->updateCamera();

}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Draw()
{ 	
	PrivSceneManager::DrawCurrentScene();
}

//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//       (also used to clean up whatever was created in Game::Initialize()  )
//-----------------------------------------------------------------------------
void Game::UnLoadContent()
{
	UnloadGameContent();
	ResourceManager::Delete();
	PrivSceneManager::Delete();
	TimeManager::Delete();
	TerminateGameContent();
}



// End of Game.cpp
