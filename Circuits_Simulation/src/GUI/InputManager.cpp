#include "include/InputManager.h"

bool InputManager::IsClicked(sf::Sprite obj, sf::Mouse::Button button, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::IntRect rect(obj.getPosition().x, obj.getPosition().y, obj.getGlobalBounds().width, obj.getGlobalBounds().height);

		return rect.contains(sf::Mouse::getPosition(window));
	}
	return false;
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
{
	return sf::Mouse::getPosition(window);
}