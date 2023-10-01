#include <iostream>
#include<SFML/Graphics.hpp>
using namespace std;
int t;bool stop;
class Rectangle : public sf::RectangleShape {
public:
    int p;
    Rectangle() {
        setSize(sf::Vector2f(80.f, 80.f));
        setFillColor(sf::Color::Black);
        setOutlineColor(sf::Color::White);
        setOutlineThickness(+2.5);
    }
};

class Board
{
private:
    Rectangle** r;
    bool check;
public:
    Board()
    {
        check = false;
        r = new Rectangle * [3];
        for (int i = 0; i < 3; i++)
        {
            r[i] = new Rectangle[3];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                r[i][j].p = -1;
            }
        }
    }
    void printBoard(sf::RenderWindow& window)
    {
        float x = 220.f, y = 150.f;
        for (int i = 0; i < 3; i++)
        {
            x = 220.f;
            for (int j = 0; j < 3; j++)
            {
                r[i][j].setPosition(x, y);
                x += 100.f;
                window.draw(r[i][j]);
            }
            y += 100.f;
        }
    }
    void gameplay(sf::RenderWindow& window, int b, int& t)
    {
        sf::Font font;
        font.loadFromFile("my_font.ttf");
        sf::Text text1, text2; int x = 233.f, y = 150.f;
        text1.setFont(font); text1.setCharacterSize(70); text1.setFillColor(sf::Color::Red);
        text2.setFont(font); text2.setCharacterSize(70); text2.setFillColor(sf::Color::Blue);
        text1.setString("X");
        text2.setString("O");
        if (b == 1 && r[0][0].p == -1)
        {
            if (t % 2 == 0)
            {
                text1.setPosition(x, y); window.draw(text1); r[0][0].p = 1;
            }
            else
            {
                text2.setPosition(x, y); window.draw(text2); r[0][0].p = 2;
            }
        }
        else if (b == 2 && r[0][1].p == -1)
        {
            if (t % 2 == 0)
            {
                text1.setPosition(x + 100, y); window.draw(text1); r[0][1].p = 1;
            }
            else
            {
                text2.setPosition(x + 100, y); window.draw(text2); r[0][1].p = 2;
            }
        }
        else if (b == 3 && r[0][2].p == -1)
        {
            if (t % 2 == 0)
            {
                text1.setPosition(x + 200, y); window.draw(text1); r[0][2].p = 1;
            }
            else
            {
                text2.setPosition(x + 200, y); window.draw(text2); r[0][2].p = 2;
            }
        }
        else if (b == 4 && r[1][0].p == -1)
        {
            if (t % 2 == 0)
            {
                text1.setPosition(x, y + 100); window.draw(text1); r[1][0].p = 1;
            }
            else
            {
                text2.setPosition(x, y + 100); window.draw(text2); r[1][0].p = 2;
            }
        }
        else if (b == 5 && r[1][1].p == -1)
        {
            if (t % 2 == 0)
            {
                text1.setPosition(x + 100, y + 100); window.draw(text1); r[1][1].p = 1;
            }
            else
            {
                text2.setPosition(x + 100, y + 100); window.draw(text2); r[1][1].p = 2;
            }
        }
        else if (b == 6 && r[1][2].p == -1)
        {
            if (t % 2 == 0)
            {
                text1.setPosition(x + 200, y + 100); window.draw(text1); r[1][2].p = 1;
            }
            else
            {
                text2.setPosition(x + 200, y + 100); window.draw(text2); r[1][2].p = 2;
            }
        }
        else if (b == 7 && r[2][0].p == -1)
        {
            if (t % 2 == 0)
            {
                text1.setPosition(x, y + 200); window.draw(text1); r[2][0].p = 1;
            }
            else
            {
                text2.setPosition(x, y + 200); window.draw(text2); r[2][0].p = 2;
            }
        }
        else if (b == 8 && r[2][1].p == -1)
        {
            if (t % 2 == 0)
            {
                text1.setPosition(x + 100, y + 200); window.draw(text1); r[2][1].p = 1;
            }
            else
            {
                text2.setPosition(x + 100, y + 200); window.draw(text2); r[2][1].p = 2;
            }
        }
        else if (b == 9 && r[2][2].p == -1)
        {
            if (t % 2 == 0)
            {
                text1.setPosition(x + 200, y + 200); window.draw(text1); r[2][2].p = 1;
            }
            else
            {
                text2.setPosition(x + 200, y + 200); window.draw(text2); r[2][2].p = 2;
            }
        }
        else
        {
            t--;
        }
        cout << t << endl;
    }
    bool checkwin(sf::RenderWindow& window)
    {
        sf::RectangleShape rec; sf::RectangleShape rec2; int x = 220, y = 190; int x1 = 261, y1 = 150;
        rec.setSize(sf::Vector2f(280.f, 2.f)); rec2.setSize(sf::Vector2f(2.f, 280.f));
        sf::Vertex line1[] =
        {
            sf::Vertex(sf::Vector2f(220.f, 150.f)),
            sf::Vertex(sf::Vector2f(500.f, 430.f))
        };
        sf::Vertex line2[] =
        {
            sf::Vertex(sf::Vector2f(220.f, 430.f)),
            sf::Vertex(sf::Vector2f(500.f, 150.f))
        };
        
        if (r[0][0].p == 1 && r[1][1].p == 1 && r[2][2].p == 1 && r[2][0].p == 1 && r[0][2].p == 1)
        {
            window.draw(line1, 2, sf::Lines);window.draw(line2, 2, sf::Lines); check = true; return true;
        }
        else if (r[0][0].p == 1 && r[0][1].p == 1 && r[0][2].p == 1 && r[1][0].p == 1 && r[2][0].p == 1)
        {
            rec.setPosition(x, y);rec2.setPosition(x1, y1);window.draw(rec);window.draw(rec2);check = true; return true;
        }
        else if (r[0][0].p == 1 && r[0][1].p == 1 && r[0][2].p == 1 && r[1][2].p == 1 && r[2][2].p == 1)
        {
            rec.setPosition(x, y);rec2.setPosition(x1+200, y1);window.draw(rec);window.draw(rec2);check = true; return true;
        }
        else if (r[2][0].p == 1 && r[2][1].p == 1 && r[2][2].p == 1 && r[1][0].p == 1 && r[0][0].p == 1)
        {
            rec.setPosition(x, y+200);rec2.setPosition(x1, y1);window.draw(rec);window.draw(rec2);check = true; return true;
        }
        else if (r[2][0].p == 1 && r[2][1].p == 1 && r[2][2].p == 1 && r[1][2].p == 1 && r[0][2].p == 1)
        {
            rec.setPosition(x, y+200);rec2.setPosition(x1+200, y1);window.draw(rec);window.draw(rec2);check = true; return true;
        }
        else if (r[0][0].p == 1 && r[0][1].p == 1 && r[0][2].p == 1)
        {
            rec.setPosition(x, y); window.draw(rec); check = true; return true;
        }
        else if (r[1][0].p == 1 && r[1][1].p == 1 && r[1][2].p == 1)
        {
            rec.setPosition(x, y + 100); window.draw(rec); check = true; return true;
        }
        else if (r[2][0].p == 1 && r[2][1].p == 1 && r[2][2].p == 1)
        {
            rec.setPosition(x, y + 200); window.draw(rec); check = true; return true;
        }
        else if (r[0][0].p == 1 && r[1][0].p == 1 && r[2][0].p == 1)
        {
            rec2.setPosition(x1, y1); window.draw(rec2); check = true; return true;
        }
        else if (r[0][1].p == 1 && r[1][1].p == 1 && r[2][1].p == 1)
        {
            rec2.setPosition(x1 + 100, y1); window.draw(rec2); check = true; return true;
        }
        else if (r[0][2].p == 1 && r[1][2].p == 1 && r[2][2].p == 1)
        {
            rec2.setPosition(x1 + 200, y1); window.draw(rec2); check = true; return true;
        }
        else if (r[0][0].p == 2 && r[0][1].p == 2 && r[0][2].p == 2)
        {
            rec.setPosition(x, y); window.draw(rec); check = true; return true;
        }
        else if (r[1][0].p == 2 && r[1][1].p == 2 && r[1][2].p == 2)
        {
            rec.setPosition(x, y + 100); window.draw(rec); check = true; return true;
        }
        else if (r[2][0].p == 2 && r[2][1].p == 2 && r[2][2].p == 2)
        {
            rec.setPosition(x, y + 200); window.draw(rec); check = true; return true;
        }
        else if (r[0][0].p == 2 && r[1][0].p == 2 && r[2][0].p == 2)
        {
            rec2.setPosition(x1, y1); window.draw(rec2); check = true; return true;
        }
        else if (r[0][1].p == 2 && r[1][1].p == 2 && r[2][1].p == 2)
        {
            rec2.setPosition(x1 + 100, y1); window.draw(rec2); check = true; return true;
        }
        else if (r[0][2].p == 2 && r[1][2].p == 2 && r[2][2].p == 2)
        {
            rec2.setPosition(x1 + 200, y1); window.draw(rec2); check = true; return true;
        }
        else if (r[0][0].p == 1 && r[1][1].p == 1 && r[2][2].p == 1)
        {
            window.draw(line1, 2, sf::Lines); check = true; return true;
        }
        else if (r[0][0].p == 2 && r[1][1].p == 2 && r[2][2].p == 2)
        {
            window.draw(line1, 2, sf::Lines); check = true; return true;
        }
        else if (r[0][2].p == 1 && r[1][1].p == 1 && r[2][0].p == 1)
        {
            window.draw(line2, 2, sf::Lines); check = true; return true;
        }
        else if (r[0][2].p == 2 && r[1][1].p == 2 && r[2][0].p == 2)
        {
            window.draw(line2, 2, sf::Lines); check = true; return true;
        }
        else
        {
            return false;
        }
    }
    void whowin(sf::RenderWindow& window, int p)
    {
        sf::Font font;
        font.loadFromFile("my_font.ttf");
        sf::Text text1,text2; int x = 150.f, y = 450.f;
        text1.setFont(font); text1.setCharacterSize(30);
        text1.setPosition(x, y);
        if (p % 2 == 1)
        {
        	text1.setFillColor(sf::Color::Red);
            text1.setString("Congratulations! Player 1 has won");
            window.draw(text1);
        }
        else
        {
        	text1.setFillColor(sf::Color::Blue);
            text1.setString("Congratulations! Player 2 has won");
            window.draw(text1);
        }
    }
    bool checkdraw(sf::RenderWindow& window)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (r[i][j].p == -1)
                    return false;
            }
        }
        sf::Font font;
        font.loadFromFile("my_font.ttf");
        sf::Text text1; int x = 250.f, y = 450.f;
        text1.setFont(font); text1.setCharacterSize(30); text1.setFillColor(sf::Color::Red);
        text1.setPosition(x, y);
        if (check==0)
        {
        	sf::RectangleShape rec;
            rec.setSize(sf::Vector2f(200.f, 50.f));
		    rec.setFillColor(sf::Color::Black);
		    rec.setOutlineColor(sf::Color::Black);
		    rec.setPosition(250,90);
		    window.draw(rec);
	        text1.setString("Match drawn");
	        window.draw(text1);
        	return true;
        }
    }
    void playerturn(sf::RenderWindow& window,int p)
    {
    	sf::Font font;
        font.loadFromFile("my_font.ttf");
        sf::Text text1; int x = 250.f, y = 100.f;
        text1.setFont(font); text1.setCharacterSize(30);
        text1.setPosition(x, y);
        
	        if (p % 2 == 1)
	        {
	        	text1.setFillColor(sf::Color::Black);
	            text1.setString("Player2 turn");
	            window.draw(text1);
		        text1.setFillColor(sf::Color::Red);
		        text1.setString("Player1 turn");
		        window.draw(text1);
		        
	        }
	        else
	        {
				text1.setFillColor(sf::Color::Black);
	            text1.setString("Player1 turn");
	            window.draw(text1);
	        	text1.setFillColor(sf::Color::Blue);
	            text1.setString("Player2 turn");
	            window.draw(text1);
       		}
	    
	}
};
sf::FloatRect clickRanges[9]; float x = 220.f, y = 150.f;
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Square");
    t = 0;
    sf::Mouse mymouse;
    Board b; int box = -1; b.printBoard(window);
    for (int i = 0; i < 3; i++)
    {
        x = 220.f;
        for (int j = 0; j < 3; j++)
        {
            clickRanges[j + (i * 3)] = sf::FloatRect(x, y, 80.f, 80.f);
            x += 100.f;
        }
        y += 100.f;
    }
    b.playerturn(window,1);
    bool isbuttondown = 0;stop = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (stop == 0)
            {
                if (event.type == sf::Event::MouseButtonReleased)
                {
                    if (event.mouseButton.button == sf::Mouse::Button::Left)
                    {
                        for (int i = 0; i < 9; i++)
                        {
                            if (clickRanges[i].contains(event.mouseButton.x, event.mouseButton.y))
                            {
                                box = i + 1;
                                b.playerturn(window,t);
                                b.gameplay(window, box, t);
                                t++;
                                stop = b.checkdraw(window);
                                if (stop == 0)
                                    stop = b.checkwin(window);
                            }
                        }
                    }
                }
            }
            if (b.checkwin(window)==1) 
            {
                b.whowin(window, t);
                sf::RectangleShape rec;
                rec.setSize(sf::Vector2f(200.f, 50.f));
			    rec.setFillColor(sf::Color::Black);
			    rec.setOutlineColor(sf::Color::Black);
			    rec.setPosition(250,90);
			    window.draw(rec);
            }
            isbuttondown = 0;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
        if (mymouse.isButtonPressed(mymouse.Left) && isbuttondown == false)
        {
            isbuttondown = true;
        }
        window.display();
    }
    return 0;
}
