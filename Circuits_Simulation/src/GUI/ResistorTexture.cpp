#include "include/ResistorTexture.h"

ResistorTexture::ResistorTexture(std::shared_ptr<AppData> data)
	: m_data(data)
{
}

void ResistorTexture::DrawResistors()
{
	for (unsigned short int i = 0; i < resistorsSprites.size(); ++i)
		m_data->window.draw(resistorsSprites[i]);
}

void ResistorTexture::AddResistor(sf::Sprite resistor)
{
	resistorsSprites.push_back(resistor);
}