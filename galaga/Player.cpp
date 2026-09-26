#include <cassert>
#include "Player.h"
#include "Bullet.h"

Player::Player(CMPUT350::Point2D loc)
{
    // TODO: Update code
    player_position = loc;
    alive = true;
}

void Player::Initialize(CMPUT350::GameContext* context)
{
}

void Player::Update(CMPUT350::GameContext* context)
{
    if (player_position.x + velocity < context->ScreenContext->GetWindowWidth() && player_position.x + velocity > 0) {
        SetPosition(player_position, velocity);
    }else if (player_position.x + velocity == context->ScreenContext->GetWindowWidth() || player_position.x + velocity == 0) {
        SetPosition(player_position, velocity);
        velocity = 0;
    }
}

void Player::LateUpdate(CMPUT350::GameContext* context)
{
}

bool Player::HandleKeyEvent(CMPUT350::GameContext* context, char key)
{
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

void Player::RenderBackground(CMPUT350::GameContext* context)
{
}

void Player::RenderForeground(CMPUT350::GameContext* context)
{
}

void Player::CollisionEnter(const std::shared_ptr<CMPUT350::CollisionObject>& obj)
{
}

void Player::Kill()
{
}

bool Player::IsAlive() const
{
    // TODO: Update code
    return alive;
}

const CMPUT350::Rect& Player::GetBounds()
{
    // TODO: Update code
    static CMPUT350::Rect sBounds(0, 0, 0, 0);
    return sBounds;
}

void Player::SetPosition(const CMPUT350::Point2D current_position, const float new_velocity) {
    player_position.x = current_position.x + new_velocity;

}
