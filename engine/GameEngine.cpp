#include "GameEngine.h"

/// @brief
namespace CMPUT350 {
#include "FontData.h"
#include <vector>

GameEngine::GameEngine(unsigned int width, unsigned int height, const std::string& name) {

    // Sample font loading code
    //	if (!mFont->openFromMemory(&_font, _font_len))
    //	{
    //		fprintf(stderr, "WARNING: Font did not load.\n");
    //	}
}

GameEngine::~GameEngine() {
    // Cleanup resources
    // mWindow->close();
}

void GameEngine::AddGameObject(std::shared_ptr<GameObject> gameObject) {
    gameObjects.push_back(gameObject);
}

/**
 * @method Run
 * @arguments None
 * @description Gives control to the game engine. Will not return until the game window is closed or
 * all objects have been destroyed.
 */
void GameEngine::Run() {
    while (true)  // window is open
    {
        // 0. Remove any objects that are now dead
        for( auto i = gameObjects.begin(); i != gameObjects.end() ) {
            if( !(*i)->IsAlive() ) {    // Dereferencing pointer to pointer. Blegh. Cleaner way to do this?
                gameObjects.erase(i);
            }
            else i++;
        }

        // 1. Activate and initialize any objects added during the last frame
        while( !incomingObjects.empty() ) {
            // Source: https://stackoverflow.com/questions/17436970/how-do-i-move-a-shared-ptr-object-between-containers-with-move-semantics
            // Time: 09/24/2026, 12:25pm
            // Referenced user quant's implementation of user David Schwartz' solution for passing shared_ptr between vectors
            incomingObjects.back()->Initialize();   //TODO: Implement GameContext
            gameObjects.push_back(std::move(incomingObjects.back()));
            assert(incomingObjects.back() == nullptr);
            incomingObjects.pop_back();
        }

        // 2. Process events
        /* Example Code from Project1a doc
        if (const auto* keyPressed = event->getIf<sf::Event::TextEntered>())
        {
            if (keyPressed->unicode == 'p')
            // do something here
        }
        */
        if (const auto* keyPressed = event->getIf<sf::Event::TextEntered>())
        {
            if (keyPressed->unicode == 'a') {

            }
            else if (keyPressed->unicode == 'd') {
                
            }
            if (keyPressed->unicode == ' ') {    // Verify this functions as correct input
                
            }
            
        }


        // 3. Update game objects
        for( auto obj : *gameObjects ) {
            obj->Update();                  // TODO: Figure out GameContext
        }

        // 4. Process collision events
        /* Example Code from Project1a doc
        std::shared_ptr<CollisionObject> objA = std::dynamic_pointer_cast<CollisionObject>(mGameObjects[a]);
        if (objA == nullptr)
            continue; // Not a collision object, skip
        */
        /*
        Collision Events:
            Bullet --> Enemy  (note: bullet object is source-independent. DON'T SHOOT YOURSELF)
            Bullet --> Player (later project phase?)
            Enemy --> Player (later project phase)
        */

        // 5. Late updates
        //? for (obj : game_objects) { obj->LateUpdate() }

        // Clear window

        // 6. Render background

        // 7. Render foreground

        // Actually render to window
    }
}

// Sample code for processing events

// bool GameEngine::ProcessEvents(GameContext *context)
//{
//	while (const std::optional event = mWindow->pollEvent())
//	{
//		if (event->is<sf::Event::Closed>())
//		{
//		}
//		else if (event->is<sf::Event::Resized>())
//		{
//		}
//		else if (const auto* keyPressed = event->getIf<sf::Event::TextEntered>())
//		{
//			// use keyPressed->unicode to get character
//		}
//	}
// }

}  // namespace CMPUT350
