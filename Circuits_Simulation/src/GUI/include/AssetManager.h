#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

class AssetManager
{
private:
	std::unordered_map<std::string, sf::Texture> m_textures;
	sf::Font m_font;

public:
	void LoadTexture(std::string name, std::string path);
	sf::Texture& GetTexture(std::string name);

	void LoadFont(std::string path);
	sf::Font& GetFont();
};