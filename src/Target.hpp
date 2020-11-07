﻿#ifndef GAME_TARGET_HPP_INCLUDEGUARD
#define GAME_TARGET_HPP_INCLUDEGUARD

#include "Box2DObject.hpp"
#include "SmartAnimation.hpp"
#include "SmartShape.hpp"
#include "SmartSprite.hpp"
#include <string>

class Target : public JamTemplate::Box2DObject {
public:
    Target(std::shared_ptr<b2World> world, const b2BodyDef* def)
        : Box2DObject { world, def }
    {
    }

    sf::Vector2f getTargetPosition();
    void setDamage(unsigned int currentDamage);
    unsigned int getDamage();

    std::shared_ptr<JamTemplate::SmartAnimation> getTarget() { return m_animation; }

private:
    std::shared_ptr<JamTemplate::SmartSprite> m_glow;
    std::shared_ptr<JamTemplate::SmartAnimation> m_animation;
    std::shared_ptr<JamTemplate::SmartShape> m_beamShape;

    mutable std::shared_ptr<JamTemplate::SmartShape> m_beamBorderShape;
    float m_beamPosX;
    float m_beamPosXLast;
    size_t m_damage = 0;
    void doUpdate(float const /*elapsed*/) override;
    void doDraw() const override;
    void doCreate() override;

    void handleInput(float const elapsed);
    void setBeamStrength(float const v);

    void registerDamageAnimation(unsigned int damage);
};

#endif
