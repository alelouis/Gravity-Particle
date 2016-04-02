
#include <Header.h>

int main()
{
    //begin_INIT_SFML_WINDOW
    double x_screen = 1600;
    double y_screen = 800;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 1;
    sf::RenderWindow window(sf::VideoMode(x_screen, y_screen), "Gravity Particles", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);
    window.setMouseCursorVisible(true);
    //end_INIT_SFML_WINDOW
    
    //begin_VARIABLE_DECLARATION
    std::vector<sf::Text> pos(2);
    sf::Vector2i position;
    sf::Clock clock;
    sf::Font MyFont;
    MyFont.loadFromFile("/Library/Fonts/arial.ttf");
    std::deque<Projectile*> projs;
    std::deque<sf::CircleShape*> projsDraw;
    
    float dt = 0.001;
    float t;
    float force = 0.01;
    int m_x = 800;
    int m_y = 400;
    float distCarre = 0;
    float angle = 0;
    int frameCounter = 0;
    //end_VARIABLE_DECLARATION

    projs.push_front(new Projectile(960,400,962,402,0,0));
    projs.push_front(new Projectile(950,400,952,402,0,0));
    projs.push_front(new Projectile(940,400,942,402,0,0));
    projs.push_front(new Projectile(930,400,932,402,0,0));
    projs.push_front(new Projectile(920,400,922,402,0,0));
    projs.push_front(new Projectile(910,400,912,402,0,0));
    projs.push_front(new Projectile(900,400,902,402,0,0));
    projs.push_front(new Projectile(890,400,892,402,0,0));
    projs.push_front(new Projectile(880,400,882,402,0,0));
    projs.push_front(new Projectile(870,400,872,402,0,0));
    projs.push_front(new Projectile(860,400,862,402,0,0));
    projs.push_front(new Projectile(850,400,852,402,0,0));
    
    //begin_PROCESS_LOOP
    while (window.isOpen())
    {
        t+=dt;
        
        //begin_EVENT_HANDLER
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(projs.size()==20){
                    projs.push_front(new Projectile(800,400,800-(position.x-800)/20,400-(position.y-400)/20,0,0));
                    projs.resize(20);
                }else{
                    projs.push_front(new Projectile(800,400,800-(position.x-800)/20,400-(position.y-400)/20,0,0));
                }
            }
        }
        position = sf::Mouse::getPosition(window);
        //end_EVENT_HANDLER
        
        //begin_UPDATE_LOOP
        
        for(int i=0;i<projs.size();i++){
            distCarre = (projs[i]->getX()-m_x)*(projs[i]->getX()-m_x)/1000.0+(projs[i]->getY()-m_y)*(projs[i]->getY()-m_y)/1000.0;
            angle = atan2(projs[i]->getY() - m_y, projs[i]->getX() - m_x);
            projs[i]->setAcc(-400*cos(angle)/distCarre, -400*sin(angle)/distCarre);
            if(t>0.1){
                projs[i]->update(dt);
                projs[i]->HandleCollision();
            }
        }
        //end_UPDATE_LOOP
        
        //begin_DRAW_LOOP
            frameCounter++;
            window.clear();
            
            //guide_line
        
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(800, 400)),
                sf::Vertex((sf::Vector2f)position),
            };
            window.draw(line, 2, sf::Lines);
            
            
            //trail
            for(int i=0;i<projs.size();i++){
                if(projs[i]->isTrailed()){
                    if(!(frameCounter%1)){
                        projs[i]->updateTrail(100);
                    }
                    for(int j=0; j<projs[i]->getTrail().size(); j++){
                        window.draw(*(projs[i]->getTrail())[j]);
                    }
                }
            }
         
            //projectile
            for(int i=0;i<projs.size();i++){
                projsDraw.push_front(new sf::CircleShape(5));
                projsDraw[i]->setOrigin(-projs[i]->getX()+2, -projs[i]->getY()+2);
                window.draw(*projsDraw[i]);
            }
            //info_text
            window.draw(simpleText(std::to_string(position.x), 10, 10, 50));
            window.draw(simpleText(std::to_string(position.y), 10, 60, 50));
            //Display
            sf::CircleShape center(30);
            center.setOrigin(-770,-370);
            window.draw(center);
            window.display();
    }
    return 0;
}
