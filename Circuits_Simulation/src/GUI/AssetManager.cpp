#include "include/AssetManager.h"
#include <iostream>

void AssetManager::LoadTexture(std::string name, std::string path)
{
	sf::Texture text;
	
	if (text.loadFromFile(path))
		m_textures[name] = text;
}

sf::Texture& AssetManager::GetTexture(std::string name)
{
	return m_textures[name];
}

void AssetManager::LoadFont(std::string path)
{
	m_font.loadFromFile(path);
}

sf::Font& AssetManager::GetFont()
{
	return m_font;
}