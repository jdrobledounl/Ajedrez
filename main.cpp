#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

// Creamos las variables que utilizaremos con los archivos
Texture texture_b;
Texture texture_w;
Sprite sprite_b;
Sprite sprite_w;

float escalaX, escalaY;
float height_b, width_b;
float height_w, width_w;

int main() {

    // Cargamos la textura de los archivos blanco y negro
    texture_b.loadFromFile("chessb.png");
    texture_w.loadFromFile("chessw.png");

    // Cargamos el material de los sprites
    sprite_b.setTexture(texture_b);
    sprite_w.setTexture(texture_w);

    height_b = (float)texture_b.getSize().y;
    width_b = (float)texture_b.getSize().x;
    height_w = (float)texture_w.getSize().y;
    width_w = (float)texture_w.getSize().x;

    escalaY = 100 / height_b;
    escalaX = 100 / width_b;
    
    sprite_b.setScale(0.78125, 0.78125);
    sprite_w.setScale(0.78125, 0.78125);


    sf::RenderWindow App(sf::VideoMode(800, 800, 32), "Ajedrez");

    
    while (App.isOpen()) {
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                App.close();
            }
        }

        App.clear(sf::Color::Black); // Limpiar la ventana con color blanco

        // Dibujar los casilleros del tablero

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                // Alternar colores de las casillas
                if ((i + j) % 2 == 0) {
                    //square.setFillColor(sf::Color::White);
                    sprite_b.setPosition(i * 100,j * 100);
                    App.draw(sprite_b);
                }
                else {
                    //square.setFillColor(sf::Color::Black);
                    sprite_w.setPosition(i * 100,j * 100);
                    App.draw(sprite_w);
                }
                //square.setPosition(i * tileSize, j * tileSize);
                //window.draw(square);
            }
        }



        /*
        sprite_b.setPosition(0, 0); 
        App.draw(sprite_b);

        sprite_w.setPosition(100, 0);
        App.draw(sprite_w);

        sprite_b.setPosition(200, 0);
        App.draw(sprite_b);

        sprite_w.setPosition(300, 0);
        App.draw(sprite_w);

        sprite_b.setPosition(400, 0);
        App.draw(sprite_b);

        sprite_w.setPosition(500, 0);
        App.draw(sprite_w);

        sprite_b.setPosition(600, 0);
        App.draw(sprite_b);

        sprite_w.setPosition(700, 0);
        App.draw(sprite_w);

        sprite_w.setPosition(0, 100);
        App.draw(sprite_w);

        sprite_b.setPosition(100, 100);
        App.draw(sprite_b);

        sprite_w.setPosition(200, 100);
        App.draw(sprite_w);

        sprite_b.setPosition(300, 100);
        App.draw(sprite_b);

        sprite_w.setPosition(400, 100);
        App.draw(sprite_w);

        sprite_b.setPosition(500, 100);
        App.draw(sprite_b);

        sprite_w.setPosition(600, 100);
        App.draw(sprite_w);

        sprite_b.setPosition(700, 100);
        App.draw(sprite_b);

        */ 

        App.display(); // Mostrar todo en la ventana
    }

    return 0;
}
