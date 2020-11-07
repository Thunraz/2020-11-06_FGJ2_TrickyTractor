﻿#ifndef GAME_STATE_GAME_HPP_INCLUDEGUARD
#define GAME_STATE_GAME_HPP_INCLUDEGUARD

#include "JamTemplate/GameState.hpp"
#include "Target.hpp"
#include <Box2D/Box2D.h>
#include <iostream>
#include <memory>

// fwd decls
namespace JamTemplate {
class SmartShape;
}

class Hud;

class StateGame : public JamTemplate::GameState {
public:
    StateGame() = default;

protected:
    std::shared_ptr<Hud> m_hud;

private:
    std::shared_ptr<JamTemplate::SmartShape> m_background;
    std::shared_ptr<JamTemplate::SmartShape> m_overlay;
    std::shared_ptr<Target> m_target;

    std::shared_ptr<b2World> m_world;

    void doCreate() override;

    virtual void doCreateInternal();

    virtual void doInternalUpdate(float const elapsed) override;
    virtual void doInternalDraw() const override;
};

#endif
