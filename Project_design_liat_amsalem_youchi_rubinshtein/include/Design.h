#pragma once
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Consts.h"
#include <vector>



class Design
{
private:
	Design();
	Design(const Design&) = delete;
	std::vector<sf::Texture> m_pictures;
	std::vector<sf::SoundBuffer> m_sounds;
	sf::RenderWindow m_window;
	sf::Font m_font;
	void loadPictures();
	void loadSounds();
	void loadFont();
public:
	static Design& getDesign()
	{
		static Design m_design;
		return m_design;
	}
	sf::Texture& getPicture(const int pic_place);
	sf::RenderWindow& getWindow();
	sf::Font& getFont();
	sf::SoundBuffer& getSound(const int sound_place);
	void safeLoadPic(const int index, const std::string& pic);
};