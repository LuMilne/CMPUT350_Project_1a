#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "GameContext.h"
#include <string_view>

namespace CMPUT350 {
class Bullet;
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

        if (player_position.x + velocity < context->ScreenContext->GetWindowWidth() && player_position.x + velocity > 0) {
            SetPosition(player_position, velocity);
        }else if (player_position.x + velocity == context->ScreenContext->GetWindowWidth() || player_position.x + velocity == 0) {
            SetPosition(player_position, velocity);
            velocity = 0;
        }


        //TODO: time needs to really be something like context.GetShootTimer(). time IS CURRENTLY PLACEHOLDER
        float time = 1.0f;
        if (shooting && time >= shoot_cooldown) {
            for (auto &bullet : bullet_pool) {
                if (bullet.expired()) {
                    
                }
            }
        }

        if (!IsAlive()) {
            Kill();
        }

        //Bullet update check
        //IsAlive check


    }

    bool HandleKeyEvent(GameContext *context, char key) override {
        if (key == 'a') {
            velocity = -2;
            return true;
        }
        if (key == 'd') {
            velocity = 2;
            return true;
        }

        if (key == ' ') {
            shooting = true;
            return true;
        }

        shooting = false;
        return false;
    }

    Point2D GetPosition() const {
        return player_position;
    }

    void SetPosition(const Point2D current_position, const float new_velocity) {
        player_position.x = current_position.x + new_velocity;

    }


private:
    //Negative left, Positive Right
    float velocity = 0;
    bool shooting = false;
    Point2D player_position;
    std::string_view tag = "Player";
    const float shoot_cooldown = 0.1f;
    std::array<std::weak_ptr<Bullet>, 2> bullet_pool;
};



class Bullet : public GameObject {
    public:
    ~Bullet() override = default;

    private:
    float velocity;
    Point2D bullet_position;
};


}  // namespace CMPUT350

#endif  // GAMEOBJECT_H
