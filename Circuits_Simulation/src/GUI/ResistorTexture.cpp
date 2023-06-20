#include "include/ResistorTexture.h"

ResistorTexture::ResistorTexture(std::shared_ptr<AppData> data)
	: m_data(data)
{
}

void ResistorTexture::DrawResistors()
{
	for (int i = 0; i < resistorsSprites.size(); ++i)
	{
		for (int j = 0; j < resistorsSprites[i].size(); ++j)
			m_data->window.draw(resistorsSprites[i][j]);
	}
}

void ResistorTexture::AddResistor(std::vector<sf::Sprite> resistor)
{
	resistorsSprites.push_back(resistor);
}

std::vector<std::vector<sf::Sprite>>& ResistorTexture::GetResistors()
{
	return resistorsSprites;
}