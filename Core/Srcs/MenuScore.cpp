/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MenuScore
*/

#include "MenuScore.hpp"

arcade::MenuScore::MenuScore(arcade::interface::graphic::WindowPtr window):
_game("Res/state_1.png", "Res/state_2.png", "Res/state_3.png", window),
_leftArrow("Res/arrow_left_1.png", "Res/arrow_left_2.png", "Res/arrow_left_2.png", window),
_rightArrow("Res/arrow_right_1.png", "Res/arrow_right_2.png", "Res/arrow_right_2.png", window)
{
    arcade::interface::graphic::EventPtr event;
    findGame();
    if (_nbGame == 0)
        _game.button_text("Res/ka1.ttf", "No Game", 700, 510);
    else
        _game.button_text("Res/ka1.ttf", _tabGame[_index], 700, 150);
    _leftArrow.button_text("Res/ka1.ttf", "", 130, 530);
    _rightArrow.button_text("Res/ka1.ttf", "", 130, 530);
    _event = event;
    _window = window;
    createBackground();
}

void arcade::MenuScore::createBackground()
{
    arcade::interface::graphic::TexturePtr texture = arcade::interface::ResourceAllocator::instance()->createTexture();
    texture->loadFromFile("Res/fond.png");
    arcade::interface::graphic::SpritePtr sprite = arcade::interface::ResourceAllocator::instance()->createSprite(texture); 
    _background = sprite;
}

void arcade::MenuScore::eventRight()
{
    _arrowIndex = 2;
    if (_index >= _nbGame - 1)
        _index = 0;
    else 
        _index++;
    _game.button_text("Res/ka1.ttf", _tabGame[_index], 880, 150);
}

void arcade::MenuScore::eventLeft()
{
    _arrowIndex = 1;
    if (_index == 0)
        _index = _nbGame - 1;
    else 
        _index--;
    _game.button_text("Res/ka1.ttf", _tabGame[_index], 880, 150);
}

void arcade::MenuScore::eventManager()
{
    if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed 
    && _event->getKey() == arcade::interface::graphic::Key::Right)
        eventRight();
    if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed 
    && _event->getKey() == arcade::interface::graphic::Key::Left)
        eventLeft();
    if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyReleased 
    && _event->getKey() == arcade::interface::graphic::Key::Right)
        _arrowIndex = 0;
    if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyReleased 
    && _event->getKey() == arcade::interface::graphic::Key::Left)
        _arrowIndex = 0;
}

void arcade::MenuScore::loopScore()
{
       while (_window->isOpen()) {
		_window->clear();
		_event = _window->processEvent();
        if (_event != nullptr && _event->getType() == arcade::interface::graphic::IEvent::EventType::OnClosed)
			exit (0);
        if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyReleased 
            && _event->getKey() == arcade::interface::graphic::Key:: Backspace)
            break;   
        if (_end == true)
            break;
        eventManager();
        displayMenu();
        _window->display();
    }
}

std::string arcade::MenuScore::parseGame(std::string str)
{
    std::size_t pos = str.find(".txt");
    str.erase(str.begin() + pos, str.end());
    return (str);
}

void arcade::MenuScore::findGame()
{
    DIR *dir;
    struct dirent *entry;
    std::string name ;
    int32_t i = 0;

    if ((dir = opendir("scores")) == NULL)
        throw std::exception();
    else {
        while ((entry = readdir(dir)) != NULL) {
            if (std::strcmp(entry->d_name, "..") != 0
            && std::strcmp(entry->d_name, ".") != 0) {
                findScore(entry->d_name, i);
                name = parseGame(entry->d_name);
                _tabGame.push_back(name);
                i++;
            }
        }
        _nbGame = _tabGame.size();
        closedir(dir);
    }
}

void arcade::MenuScore::findScore(std::string game, int32_t index)
{
    std::string line;
    std::string score = "scores/";
    std::ifstream file(std::string(score) + game);
    std::vector<std::string> _newVector;
    if (file) {
        while(getline(file, line))
            _newVector.push_back(line);
        if (_newVector.size() == 0)
            _newVector.push_back("No Score");
        _tabScore.push_back(_newVector);
    }
}

void arcade::MenuScore::printButton()
{
    _game.draw_state_1(400, 100, 700);
}

void arcade::MenuScore::printArrows()
{
    if (_arrowIndex == 2) {
        _rightArrow.draw_state_2(1200, 150, 700);
        _leftArrow.draw_state_1(250, 150, 700);
    }
    if (_arrowIndex == 1) {
        _rightArrow.draw_state_1(1200, 150, 700);
        _leftArrow.draw_state_2(250, 150, 700);
    }
    if (_arrowIndex == 0 ) {
        _rightArrow.draw_state_1(1200, 150, 700);
        _leftArrow.draw_state_1(250, 150, 700);
    }
}

void arcade::MenuScore::displayScore()
{
    int32_t i = 0;
    arcade::interface::graphic::FontPtr font;
    arcade::interface::graphic::TextPtr text;
    font = arcade::interface::ResourceAllocator::instance()->createFont("neon2.ttf");
    text = arcade::interface::ResourceAllocator::instance()->createText(font);
    text->setCharacterSize(60);
    int32_t pos= 300;
    
    while( i < _tabScore[_index].size()) {
        text->setString(_tabScore.at(_index).at(i));
        text->setPosition(400, pos);
        _window->draw(text);
        pos += 100;
        i++;
    }
}

void arcade::MenuScore::displayMenu()
{
    _window->draw(_background);

    if (_nbGame > 1) {
        printButton();
        printArrows();
        displayScore();
    }
    if (_nbGame == 1)
        _game.draw_state_1(400, 450, 700);
    if (_nbGame == 0) {
     _game.draw_state_1(400, 450, 700);
     _game.button_text("Res/ka1.ttf", "No Game", 880, 510);
    }
}