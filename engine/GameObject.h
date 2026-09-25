#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "GameContext.h"
#include <string_view>

namespace CMPUT350 {

class GameContext;

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void Initialize(GameContext *context);
    virtual void Update(GameContext *context);
    virtual void LateUpdate(GameContext *context);
    virtual void RenderUI(GameContext *context);
    virtual bool HandleKeyEvent(GameContext *context, char key);
    virtual bool IsAlive() const;
    virtual void Kill();
};

class Player : public GameObject {

public:
    ~Player() override = default;
    void Initialize(GameContext *context) override{
        velocity =  0;
        float player_x = context->ScreenContext->GetWindowWidth() / 2;
        //-30 is just a temp value to offset the player from the bottom of the screen
        float player_y = context->ScreenContext->GetWindowHeight() -30;

        player_position.x = player_x;
        player_position.y = player_y;

        //TODO: Add bullet pool (set up the weak pointer reference), anything else missing
    }

    void Update(GameContext *context) override {
        player_position = SetPosition(GetPosition(), velocity);
    }

    Point2D GetPosition() {
        return player_position;
    }

    Point2D SetPosition(Point2D current_position, float new_velocity) {
        player_position = current_position + new_velocity;
    }


private:
    //Negative left, Positive Right
    float velocity;
    Point2D player_position;
    std::string_view tag = "Player";
};


}  // namespace CMPUT350

#endif  // GAMEOBJECT_H
