﻿#ifndef JAMTEMPLATE_TILEMAP_HPP_GUARD
#define JAMTEMPLATE_TILEMAP_HPP_GUARD

#include "../Collider.hpp"
#include "SmartObject.hpp"
#include "tileson.h"
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <memory>
#include <vector>

namespace JamTemplate {

// forward declaration
class Game;

class SmartTilemap : public SmartObject {
public:
    using Sptr = std::shared_ptr<SmartTilemap>;

    SmartTilemap(std::filesystem::path const& path);

    void doDraw(std::shared_ptr<sf::RenderTarget> const sptr) const;

    void doDrawFlash(std::shared_ptr<sf::RenderTarget> const sptr) const;
    void doDrawShadow(std::shared_ptr<sf::RenderTarget> const sptr) const;

    void doUpdate(float elapsed);

    void setColor(sf::Color const& col);
    const sf::Color getColor() const;

    void setPosition(sf::Vector2f const& pos);
    const sf::Vector2f getPosition() const;

    sf::Transform const getTransform() const;
    sf::FloatRect const getGlobalBounds() const;
    sf::FloatRect const getLocalBounds() const;

    void setFlashColor(sf::Color const& col);
    const sf::Color getFlashColor() const;

    void setScale(sf::Vector2f const& scale);
    const sf::Vector2f getScale() const;

    const sf::Vector2i getMapSizeInTiles();

    void setOrigin(sf::Vector2f const& origin);
    const sf::Vector2f getOrigin() const;

    void doRotate(float /*rot*/);

    void setScreenSizeHint(sf::Vector2f const& hint, std::shared_ptr<Game> ptr);

    // FIXME: Not ideal because it only supports rectangles.
    std::map<std::string, std::vector<Rect>> getObjectGroups() { return m_objectGroups; };
    void toggleObjectGroupVisibility() { m_highlightObjectGroups = !m_highlightObjectGroups; };

private:
    std::unique_ptr<tson::Map> m_map;
    // Map from object layer name to vector of objects, all rectangular.
    std::map<std::string, std::vector<Rect>> m_objectGroups;
    bool m_highlightObjectGroups = false;
    mutable std::vector<std::unique_ptr<sf::Sprite>> m_tileSprites;

    sf::Vector2f m_position;

    sf::Vector2f m_screenSizeHint;
    std::weak_ptr<Game> m_gamePtr;
};

} // namespace JamTemplate

#endif // !JAMTEMPLATE_TILEMAP_HPP_GUARD
