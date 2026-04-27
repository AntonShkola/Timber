#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
using namespace Keyboard;

int main()
{
	VideoMode vm({ 2560, 1080 }); //создание объекта vm из класса VideoMode
	RenderWindow window(vm, "Timber!", State::Fullscreen); //создание объекта window из класса RenderWindow

	// создание текстуры

	Texture textureBackground; //создание текстуры для хранения изображения в GPU
	if (!textureBackground.loadFromFile("graphics/background.jpg")) //загрузка текстуры
	{
		cout << "Background texture loading error" << endl;
	}

	// создание спрайта текстуры

	Sprite spriteBackground(textureBackground); //создание спрайта и привязка текстуры
	spriteBackground.setPosition({ 0,0 }); //установка позиции спрайта в верхний левый  угол

	// создание текстуры дерева

	Texture textureTree;
	if (!textureTree.loadFromFile("graphics/tree2.png"))
	{
		cout << "Texture tree load error" << endl;
	}

	// создание спрайта дерева

	Sprite spriteTree(textureTree);
	spriteTree.setPosition({ 810,0 });

	// создание текстуры пчелы

	Texture textureBee;
	if (!textureBee.loadFromFile("graphics/bee.png"))
	{
		cout << "Texture bee load error";
	}

	// создание спрайта пчелы

	Sprite spriteBee(textureBee);
	spriteBee.setPosition({ 400,800 });

	bool beeActive = false;

	float beeSpeed = 0.0f;

	// создание текстуры облаков

	Texture textureCloud;
	if (!textureCloud.loadFromFile("graphics/cloud.png"))
	{
		cout << "Texture cloud load error";
	}

	// создание спрайтов облаков

	Sprite spriteCloud1(textureCloud);
	Sprite spriteCloud2(textureCloud);
	Sprite spriteCloud3(textureCloud);

	spriteCloud1.setPosition({ 150,0 });
	spriteCloud2.setPosition({ 300,250 });
	spriteCloud3.setPosition({ 1300,150 });

	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;

	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;



	// отрисовка

	window.clear(); // очищаение экрана

	window.draw(spriteBackground);

	window.draw(spriteTree);

	window.draw(spriteCloud1);
	window.draw(spriteCloud2);
	window.draw(spriteCloud3);

	window.draw(spriteTree);

	window.draw(spriteBee);

	window.display(); // вывод на экран всего отрисованного (смена буферов)

	// с какой скоростью движется каждое облако?

	//float cloud1Speed = 0;
	//float cloud2Speed = 0;
	//float cloud3Speed = 0;

	// переменные для управления временем

	Clock clock;

	// запуск игрового цикла

	while (window.isOpen())
	{

		Time dt = clock.restart(); // измеряем время

		if (isKeyPressed(Key::Escape))
		{
			window.close();
		}
	}

	return 0;
}

