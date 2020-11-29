#ifndef _Анимация_Н
#define _Анимация_Н
#include "TinyXML/tinyxml.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class анимация
{
public:
	std::vector<IntRect> кадр, кадр_перевёрнутый;
	double ТекКадр, скорость;
	bool зеркало, ПроигАнимацию , повтор;
	Sprite картинка;
	анимация() {
		ТекКадр = 0;
		ПроигАнимацию = true;
		зеркало = false;
		повтор = true;
	}
	
	void время(double время) {

		if (!ПроигАнимацию) return;

		ТекКадр += скорость * время;

		if (ТекКадр >= кадр.size()) {
			ТекКадр -= кадр.size();
			if (!повтор) { ПроигАнимацию = false; return; }
		}

		int i = ТекКадр;
		картинка.setTextureRect(кадр[i]);
		if (зеркало)  картинка.setTextureRect(кадр_перевёрнутый[i]);
	}
};

class менеджер_анимации
{
public:
	String ИмяТекАнимации;
	std::map<String, анимация> АнимЛист;

	менеджер_анимации() {}
	~менеджер_анимации()
	{
		АнимЛист.clear();
	}
	
	void Создать(std::string name, Texture& t, int x, int y, int w, int h, int Кадры, double Скороть, int шаг = 0, bool повтор = true)
	{
		анимация a;
		a.скорость = Скороть;
		a.повтор = повтор;
		a.картинка.setTexture(t);
		a.картинка.setOrigin(0, h);

		for (int i = 0; i < Кадры; i++)
		{
			a.кадр.push_back(IntRect(x + i * шаг, y, w, h));
			a.кадр_перевёрнутый.push_back(IntRect(x + i * шаг + w, y, -w, h));
		}
		АнимЛист[name] = a;
		ИмяТекАнимации = name;
	}
	//загрузка из файла XML
	void ЗагрузитьАнимациюXML(std::string имяфайла, Texture& t)
	{
		TiXmlDocument анимфайл(имяфайла.c_str());

		анимфайл.LoadFile();

		TiXmlElement* head;
		head = анимфайл.FirstChildElement("sprites");

		TiXmlElement* animElement;
		animElement = head->FirstChildElement("animation");
		while (animElement)
		{
			анимация анимация;
			ИмяТекАнимации = animElement->Attribute("title");
			int delay = atoi(animElement->Attribute("delay"));
			анимация.скорость = 1.0 / delay; анимация.картинка.setTexture(t);

			TiXmlElement* cut;
			cut = animElement->FirstChildElement("cut");
			while (cut)
			{
				int x = atoi(cut->Attribute("x"));
				int y = atoi(cut->Attribute("y"));
				int w = atoi(cut->Attribute("w"));
				int h = atoi(cut->Attribute("h"));

				анимация.кадр.push_back(IntRect(x, y, w, h));
				анимация.кадр_перевёрнутый.push_back(IntRect(x + w, y, -w, h));
				cut = cut->NextSiblingElement("cut");
			}

			анимация.картинка.setOrigin(0, анимация.кадр[0].height);
			АнимЛист[ИмяТекАнимации] = анимация;
			animElement = animElement->NextSiblingElement("animation");
		}
	}

	void set(std::string name)
	{
		ИмяТекАнимации = name;
		АнимЛист[ИмяТекАнимации].зеркало = 0;
	}

	void показать(RenderWindow& window, int x = 0, int y = 0) {
		АнимЛист[ИмяТекАнимации].картинка.setPosition(x, y);
		window.draw(АнимЛист[ИмяТекАнимации].картинка);
	}

	void переключить(String Имя) { ИмяТекАнимации = Имя; }
	void зеркало(bool b = 1) { АнимЛист[ИмяТекАнимации].зеркало = b; }
	void время(double время) { АнимЛист[ИмяТекАнимации].время(время); }
	void пауза() { АнимЛист[ИмяТекАнимации].ПроигАнимацию = false; }
	void плэй() { АнимЛист[ИмяТекАнимации].ПроигАнимацию = true; }

	void плэй(std::string name) { АнимЛист[name].ПроигАнимацию = true; }
	bool ПроигАним() { return АнимЛист[ИмяТекАнимации].ПроигАнимацию; }
	double выс() { return АнимЛист[ИмяТекАнимации].кадр[0].height; }
	double шир() { return АнимЛист[ИмяТекАнимации].кадр[0].width; }
	int колкад() { return АнимЛист[ИмяТекАнимации].кадр.size(); }
	int кад() { return АнимЛист[ИмяТекАнимации].ТекКадр; }
	String ан() { return ИмяТекАнимации; }
};
#endif