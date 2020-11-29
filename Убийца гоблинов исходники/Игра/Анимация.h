#ifndef _��������_�
#define _��������_�
#include "TinyXML/tinyxml.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class ��������
{
public:
	std::vector<IntRect> ����, ����_�����������;
	double �������, ��������;
	bool �������, ������������� , ������;
	Sprite ��������;
	��������() {
		������� = 0;
		������������� = true;
		������� = false;
		������ = true;
	}
	
	void �����(double �����) {

		if (!�������������) return;

		������� += �������� * �����;

		if (������� >= ����.size()) {
			������� -= ����.size();
			if (!������) { ������������� = false; return; }
		}

		int i = �������;
		��������.setTextureRect(����[i]);
		if (�������)  ��������.setTextureRect(����_�����������[i]);
	}
};

class ��������_��������
{
public:
	String ��������������;
	std::map<String, ��������> ��������;

	��������_��������() {}
	~��������_��������()
	{
		��������.clear();
	}
	
	void �������(std::string name, Texture& t, int x, int y, int w, int h, int �����, double �������, int ��� = 0, bool ������ = true)
	{
		�������� a;
		a.�������� = �������;
		a.������ = ������;
		a.��������.setTexture(t);
		a.��������.setOrigin(0, h);

		for (int i = 0; i < �����; i++)
		{
			a.����.push_back(IntRect(x + i * ���, y, w, h));
			a.����_�����������.push_back(IntRect(x + i * ��� + w, y, -w, h));
		}
		��������[name] = a;
		�������������� = name;
	}
	//�������� �� ����� XML
	void �����������������XML(std::string ��������, Texture& t)
	{
		TiXmlDocument ��������(��������.c_str());

		��������.LoadFile();

		TiXmlElement* head;
		head = ��������.FirstChildElement("sprites");

		TiXmlElement* animElement;
		animElement = head->FirstChildElement("animation");
		while (animElement)
		{
			�������� ��������;
			�������������� = animElement->Attribute("title");
			int delay = atoi(animElement->Attribute("delay"));
			��������.�������� = 1.0 / delay; ��������.��������.setTexture(t);

			TiXmlElement* cut;
			cut = animElement->FirstChildElement("cut");
			while (cut)
			{
				int x = atoi(cut->Attribute("x"));
				int y = atoi(cut->Attribute("y"));
				int w = atoi(cut->Attribute("w"));
				int h = atoi(cut->Attribute("h"));

				��������.����.push_back(IntRect(x, y, w, h));
				��������.����_�����������.push_back(IntRect(x + w, y, -w, h));
				cut = cut->NextSiblingElement("cut");
			}

			��������.��������.setOrigin(0, ��������.����[0].height);
			��������[��������������] = ��������;
			animElement = animElement->NextSiblingElement("animation");
		}
	}

	void set(std::string name)
	{
		�������������� = name;
		��������[��������������].������� = 0;
	}

	void ��������(RenderWindow& window, int x = 0, int y = 0) {
		��������[��������������].��������.setPosition(x, y);
		window.draw(��������[��������������].��������);
	}

	void �����������(String ���) { �������������� = ���; }
	void �������(bool b = 1) { ��������[��������������].������� = b; }
	void �����(double �����) { ��������[��������������].�����(�����); }
	void �����() { ��������[��������������].������������� = false; }
	void ����() { ��������[��������������].������������� = true; }

	void ����(std::string name) { ��������[name].������������� = true; }
	bool ���������() { return ��������[��������������].�������������; }
	double ���() { return ��������[��������������].����[0].height; }
	double ���() { return ��������[��������������].����[0].width; }
	int ������() { return ��������[��������������].����.size(); }
	int ���() { return ��������[��������������].�������; }
	String ��() { return ��������������; }
};
#endif