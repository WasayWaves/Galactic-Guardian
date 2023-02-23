#include <SFML/Graphics.hpp>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class Game {
public:
    Game() : window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "2D Shooter Game"), 
             player(sf::RectangleShape(sf::Vector2f(50.f, 50.f))) {
        window.setFramerateLimit(60);
        player.setFillColor(sf::Color::Green);
        player.setPosition(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT - 100.f);
    }

    void run() {
        while (window.isOpen()) {
            handleEvents();
            update();
            render();
        }
    }

private:
    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    void update() {
        float speed = 5.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-speed, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(speed, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            // fire bullet
        }
    }

    void render() {
        window.clear();
        window.draw(player);
        window.display();
    }

    sf::RenderWindow window;
    sf::RectangleShape player;
};

int main() {
    Game game;
    game.run();
    return 0;
}
