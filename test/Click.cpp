#include "Click.h"

void Buttons::setSprite(string spritename)
{
    sf::Texture texture;
    texture.loadFromFile(spritename);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(var1 * spritesize, var1 * spritesize, var2 * spritesize, var1 * spritesize));
    sprite.setColor(sf::Color(255, 255, 255, 200));
    sprite.setPosition(x, y);

}
void Buttons::setText(string a, string fontname)
{
    if (!font.loadFromFile(fontname))
    {
        cout << "error" << endl;
        system("pause");
    }
    text.setFont(font);
    text.setCharacterSize(sizeText);
    text.setFillColor(sf::Color::Red);
    text.setPosition(x, y);
    text.setString(a);
}
Buttons::Buttons(int xx, int yy, int sizeT)
{
    x = xx;
    y = yy;
    sizeText = sizeT;

};

string Document::createDoc()
{
    DataBaseInput e;

    string n = "Name: ";
    string d = "Date: ";
    string Doc = n + e.imie + " " + e.nazwisko + "\n" + d + e.data + "\n";
    return Doc;
}
void Document::displayDoc()
{
    a = createDoc();
    setSprite("texture.png");
    setText(a, "arial.ttf");
}
Document::Document(int xx, int yy, int sizeT)
{
    x = xx;
    y = yy;
    sizeText = sizeT;
}