#include "���������.h"

int main() {

	RenderWindow window(sf::VideoMode(1280, 720), L"������ ��������", Style::Close);	//�����
	window.setMouseCursorVisible(0);	//��� �������

	��������_�������� ��������, ��������2, ��������3, ��������4, ��������5, ��������6, ��������7, ��������8, ��������9, ��������10;
	Texture ��������, ��������2, ��������3, ��������4, ��������5, ��������6, ��������7, ��������8, ��������9, ��������10;

	��������.loadFromFile("��������/���������/�����.png");
	��������2.loadFromFile("��������/���������/������.png");
	��������3.loadFromFile("��������/���������/������.png");
	��������4.loadFromFile("��������/���������/������.png");
	��������5.loadFromFile("��������/���������/�����.png");
	��������6.loadFromFile("��������/���������/�������_������.png");
	��������7.loadFromFile("��������/���������/����.png");
	��������8.loadFromFile("��������/���������/���.png");
	��������9.loadFromFile("��������/���������/������.png");
	��������10.loadFromFile("��������/���������/���1.png");

	��������.�����������������XML("��������/��������/�����.xml", ��������);
	��������2.�����������������XML("��������/��������/������.xml", ��������2);
	��������3.�����������������XML("��������/��������/������.xml", ��������3);
	��������4.�������("������", ��������4, 0, 0, 75, 100, 1, 0);
	��������5.�������("�����", ��������5, 0, 0, 50, 50, 1, 0);
	��������6.�����������������XML("��������/��������/�������_������.xml", ��������6);
	��������7.�����������������XML("��������/��������/����.xml", ��������7);
	��������8.�����������������XML("��������/��������/���.xml", ��������8);
	��������9.�����������������XML("��������/��������/������.xml", ��������9);
	��������10.�����������������XML("��������/��������/���1.xml", ��������10);

	std::list<������*> �������2;
	std::list<������*> �������;			//���� ��������
	std::list<������*>::iterator it;	//�������� ��� �����
	Level lvl;
	lvl.LoadFromFile("�����.tmx");

	Object pl = lvl.GetObject("Player");
	����� �����(��������, lvl, pl.rect.left, pl.rect.top);

	std::vector<Object> g = lvl.GetObjects("goblin");
	for (int i = 0; i < g.size(); i++)
		�������.push_back(new ������(��������3, lvl, g[i].rect.left, g[i].rect.top, 0.3,1));

	std::vector<Object> g1 = lvl.GetObjects("goblin1");
	for (int i = 0; i < g1.size(); i++)
		�������.push_back(new ������(��������3, lvl, g1[i].rect.left, g1[i].rect.top, 0.4,1));

	std::vector<Object> g2 = lvl.GetObjects("goblin2");
	for (int i = 0; i < g2.size(); i++)
		�������.push_back(new ������(��������3, lvl, g2[i].rect.left, g2[i].rect.top, 0.5,1));

	std::vector<Object> c = lvl.GetObjects("c");
	for (int i = 0; i < c.size(); i++)
		�������.push_back(new �����("c", ��������4, c[i].rect.left, c[i].rect.top));

	std::vector<Object> hp = lvl.GetObjects("hp");
	for (int i = 0; i < hp.size(); i++)
		�������.push_back(new �����("hp", ��������5, hp[i].rect.left, hp[i].rect.top));

	std::vector<Object> hg = lvl.GetObjects("hgoblin");
	for (int i = 0; i < hg.size(); i++)
		�������.push_back(new ������(��������6, lvl, hg[i].rect.left, hg[i].rect.top, 0.3, 2));

	std::vector<Object> hl = lvl.GetObjects("hl");
	for (int i = 0; i < hl.size(); i++)
		�������.push_back(new ����(��������7, lvl, hl[i].rect.left, hl[i].rect.top));

	std::vector<Object> npc1 = lvl.GetObjects("npc1");
	for (int i = 0; i < npc1.size(); i++)
		�������.push_back(new ���1(��������10, lvl, npc1[i].rect.left, npc1[i].rect.top));

	for (it = �������.begin(); it != �������.end(); it++)
	{
		������* � = *it; ������* r = new �����("hp", ��������5, 1, 1);;
		if (�->���_���() == "c" || �->���_���() == "hp")
			r = new �����("hp", ��������5, 1, 1);
		if (�->���_���() == "goblin" || �->���_���() == "goblin1" || �->���_���() == "goblin2")
			r = new ������(��������3, lvl, 1, 1, 0.3,1);
		if (�->���_���() == "hl")
			r = new ����(��������3, lvl, 1, 1);
		if (�->���_���() == "npc1")
			r = new ���1(��������10, lvl, 1, 1);
		*r = *�;
		�������2.push_back(r);
	}

	Object bos = lvl.GetObject("bos");
	��� ���(��������8, lvl, bos.rect.left, bos.rect.top);

	//�����
	Font font;//����� 
	Text text("", font, 50);
	Text text2("", font, 50);
	Text text3("", font, 50);
	Text text4("", font, 25);
	Text text5("", font, 50);
	Text text6("", font, 50);
	font.loadFromFile("��������/CyrilicOld.TTF");
	text.setString("������� ����� �������");
	text.setPosition(250, 600);

	//���  � ���
	Texture d, h;
	Sprite ���, ���, �����, ��������;
	h.loadFromFile("��������/������.png");
	���.setTexture(h);
	���.setTextureRect(IntRect(0, 0, 20, 22));
	���.setTextureRect(IntRect(0, 0, 1280, 720));

	//�����
	SoundBuffer a, b,cc,yr, cox;
	Sound �����������, ��������, ��������, ��������������, �������������;
	a.loadFromFile("�������/�������.ogg");
	b.loadFromFile("�������/����2.ogg");
	cc.loadFromFile("�������/���� �������.ogg");
	yr.loadFromFile("�������/����.ogg");
	cox.loadFromFile("�������/����������.ogg");
	�����������.setBuffer(a);
	��������.setBuffer(b);
	��������.setBuffer(cc);
	��������������.setBuffer(yr);
	�������������.setBuffer(cox);

	//������
	Music ��������������, ���������, �����������, ������;
	��������������.openFromFile("�������/Ready for battle (XCOM 2 OST).ogg");
	���������.openFromFile("�������/Motoi Sakuraba_-_Looking Glass Knight (Dark Souls II OST).ogg");
	�����������.openFromFile("�������/Motoi Sakuraba_-_Bell Gargoyle (Dark Souls OST).ogg");
	������.openFromFile("�������/������.ogg");
	��������������.play();
	�����������.setLoop(1);
	���������.setLoop(1);
	��������������.setLoop(1);
	

	//��������������� ����������
	int ������� = 0; int ��������� = 0; int ���������������� = 57; int ���������� = 10;
	bool �����; bool ��������� = 0;
	bool ������� = 0;
	bool ��� = 0;
	bool ��� = 0;
	bool ���1 = 0;
	bool ���2 = 0;
	bool ���3 = 0;
	bool ���4 = 0;
	Clock clok;
	double �����;
	double ����� = 1;
	double x = 1100;
	double y = 1548;
	int ��������������� = 50;
	int ��������������� = 100;
	int �1 = 578;
	int �2 = 578;
	����� = clok.getElapsedTime().asMilliseconds();

	Event event;//������ �������
	while (window.isOpen())
	{
		//��������
		if (������� == 0) {
			d.loadFromFile("��������/maxresdefault.jpg");
			���.setTexture(d);
			while (window.pollEvent(event))//��������� �������
			{
				��� = 1;
				text.setString("�����");
				text.setPosition(560, 600);
				text2.setString("�� ������� ������� ������ �������,\n�������� ������� � �������,\n��� ��������� ����������� � ����.");
				text2.setPosition(0, 0);
				//text3.setString("�� ����������� \n������� �������\n� ������ \n������������");
				//text3.setPosition(0, 200);
				text5.setString("���������");
				text5.setPosition(500, 650);
				//������������ ����
				if (event.type == sf::Event::MouseMoved)
					���.setPosition(event.mouseMove.x, event.mouseMove.y);

				//��������� ������
				text.setFillColor(Color::Black);
				text.setStyle(sf::Text::Bold);
				text2.setFillColor(Color::Red);
				//text3.setFillColor(Color::Green);
				text5.setFillColor(Color::Black);

				//��������� ����
				if (event.type == sf::Event::Closed)
					window.close();

				//������� ������ � ������
				if (Mouse::getPosition(window).x > 560 && Mouse::getPosition(window).x < 560 + 170 && \
					Mouse::getPosition(window).y < 600 + 50 && Mouse::getPosition(window).y > 600)
				{
					text.setFillColor(Color::Red);//������ �� ������
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						window.create(VideoMode(), L"������ ��������", Style::Fullscreen);
						window.setMouseCursorVisible(0);
						������� = 1; ��������������.stop();
						�����������.play();//������������� ������
					}
				}

				//������� ������ � ����������
				if (Mouse::getPosition(window).x > 500 && Mouse::getPosition(window).x < 500 + 300 && \
					Mouse::getPosition(window).y < 650 + 50 && Mouse::getPosition(window).y > 650)
				{
					text5.setFillColor(Color::Red);//������ �� ������
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						������� = 3; ��������� = 0;
					}
				}
			}
			
			//���������� �������
			window.draw(���);
			window.draw(text);
			window.draw(text2);
			//window.draw(text3);
			window.draw(text5);
			if (���) {
				window.draw(���);
			}
			window.display();
			clok.restart();
		}
		if (������� == 1)
		{
			View view(FloatRect(0, 0, 1920, 1080));
			����� = clok.getElapsedTime().asMilliseconds();
			����� *= 2;
			if (����� > 100)����� = 100;

			//��������� �����
			std::random_device random_device;
			std::mt19937 generator(random_device());
			std::uniform_int_distribution<> distribution(0, 5);

			//�����
			std::ostringstream g, k;
			g << ����������������;
			k << �����.���_����������();
			text.setString("�������� ��������:" + g.str() + "\nXP\n������:" + k.str());
			text.setFillColor(Color::Black); text.setStyle(sf::Text::Bold);
			text.setPosition(0, 0);
			text2.setString("����� �����");
			text2.setFillColor(Color::Black); text2.setStyle(sf::Text::Bold);
			text2.setPosition(1600, 0);
			text3.setString("W A D ��� ������� - ������\n+Shift - ������\n\neps-����� � ����\n\n�������� �� ����� ������\n���� ��� ������\n");
			text3.setFillColor(Color::Black);
		

			//�����
			�����.���_�����() > 1 ? �����.���_�����(1) : �����.���_�����(�����.���_�����());
			RectangleShape �����(Vector2f(�����.���_�����() * 300, 30));
			�����.setFillColor(Color::Red);
			�����.setPosition(75, 60);

			//����� �����
			RectangleShape ��������(Vector2f(���.���_�����() * 30, 30));
			��������.setFillColor(Color::Red);
			��������.setPosition(1600, 60);

			//����������
			if (   (!���1 && ���������������� == 40)
				|| (!���2 && ���������������� == 32)
				|| (!���3 && ���������������� == 13)
				|| (!���4 && ���������������� == 0))
			{
				if (���������������� == 40)
					���1 = 1;
				if (���������������� == 32)
					���2 = 1;
				if (���������������� == 13)
					���3 = 1;
				if (���������������� == 0)
					���4 = 1;

				for (it = �������2.begin(); it != �������2.end();)
				{
					������* � = *it;
					it = �������2.erase(it);
					delete �;
				}
				for (it = �������.begin(); it != �������.end(); it++)
				{
					������* � = *it; ������* r = new �����("hp", ��������5, 1, 1);
					if (�->���_���() == "c" || �->���_���() == "hp")
						r = new �����("hp", ��������5, 1, 1);
					if (�->���_���() == "goblin" || �->���_���() == "goblin1" || �->���_���() == "goblin2")
						r = new ������(��������3, lvl, 1, 1, 0.3,1);
					if (�->���_���() == "hl")
						r = new ����(��������3, lvl, 1, 1);
					if(�->���_���() == "npc1")
						r = new ���1(��������10, lvl, 1, 1);
					*r = *�;
					�������2.push_back(r);
				}
				���������� = �����.���_����������();
				����� = �����.���_�����();
				x = �����.���_x();
				y = �����.���_y();
				��� = 1;
				�������������.play();
			}

			//����
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				!��������� ? �����������.pause() : ���������.pause(); ��������������.play();
				������� = 2; ����� = 1;
				window.create(sf::VideoMode(1200, 628), L"������ ��������", Style::Close);
				window.setMouseCursorVisible(0);
			}
			
			//�����
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();
			}

			//������
			if (�����.���_��() && �����.���_����������() && �����.���_�������()) {
				if (�����.���_��������().���() >= �����.���_��������().������() - 2) {
					�������.push_back(new ������(��������2, lvl, �����.���_x() + !�����.���_�������() * 77, �����.���_y() + 64, �����.���_�������()));
					�����.���_����������(-1); �����.���_��();
				}
				if (�����.���_��������().���() == 0)
				�����������.play();
			}

			//�����
			if (���.���_����() == 3) {
				���.���_t(1);
				�������.push_back(new ������(��������9, lvl, ���.���_x(), ���.���_y() + ���.���_h() / 2, ���.���_�������()));
				//�����.���������� -= 1;
			}

			//��������������� � ���������
			���������������� = 0;
			for (it = �������.begin(); it != �������.end(); it++)
			{
				������* ������ = *it;
				//1. �����
				if (������->���_���() == "goblin" || ������->���_���() == "hl")
				{
					if (������->���_�����() <= 0) continue;
					
					����������������++;

					//�������������
					//if (�����.����� > 0)
					������->���_�������������(0);
					for (int j = (������->���_x() / ������) - 5; j < (������->���_x() / ������) + 4; j++)
						if (j == (int)(�����.���_x() / ������)
							&& ((int)((�����.���_y() + �����.���_h()) / ������) == (int)((������->���_y() + ������->���_h()) / ������)
							|| (int)((�����.���_y() + �����.���_h()) / ������) == (int)((������->���_y() + ������->���_h()) / ������ + 1)))
						{
							if (������->���_x() > �����.���_x()) ������->���_�������(1); else ������->���_�������(0);
							������->���_�������������(1);
						}

					//���� ������
					if (�����.������().intersects(������->������()))
					{
						if (������->���_���() == "goblin")
						if (������->���_t()) {
							������->���_t(0); ������->���_��������().��������[������->���_��������().��()].������� = 0;
						}
						������->����_�������();
						if (������->���_��() && ������->���_��������().���() == ������->���_�����()) {
							������->���_��();
							�����.���_�����(�����.���_�����() - ������->���_����());
							��������������.play();
						}
					}
					//���� �����
					for (std::list<������*>::iterator it2 = �������.begin(); it2 != �������.end(); it2++)
					{
						������* ������ = *it2;
						if (������->���_���() == "Bullet")
							if (������->���_�����() > 0)
								if (������->������().intersects(������->������()))
								{
									������->���_���(0); ������->���_�����(������->���_�����() - ������->���_����()); ��������.play();
									if (������->���_x() > ������->���_x()) ������->���_�������(1); else ������->���_�������(0);
								}
					}

					//��������� �������
					if (������->���_�����() <= 0) {

						int �������������� = distribution(generator); // ��������� �����.
						if (�������������� == 1)
							�������.push_back(new �����("c", ��������4, ������->���_x(), ������->���_y()));
						else if (�������������� == 0)
							�������.push_back(new �����("hp", ��������5, ������->���_x(), ������->���_y()));
					}

				}
				if (������->���_���() == "npc1")
				{
					������->���_�������������(0);
					for (std::list<������*>::iterator it2 = �������.begin(); it2 != �������.end(); it2++)
					{
						if ((*it2)->���_���() == "goblin" || (*it2)->���_���() == "hl")
						{
							for (int j = (������->���_x() / ������) - 10; j < (������->���_x() / ������) + 10; j++)
								if (j == (int)((*it2)->���_x() / ������)
									&&((int)(((*it2)->���_y() + (*it2)->���_h()) / ������) == (int)((������->���_y() + ������->���_h()) / ������)
									|| (int)(((*it2)->���_y() + (*it2)->���_h()) / ������) == (int)((������->���_y() + ������->���_h()) / ������ - 1)
									|| (int)(((*it2)->���_y() + (*it2)->���_h()) / ������) == (int)((������->���_y() + ������->���_h()) / ������ - 2)
									|| (int)(((*it2)->���_y() + (*it2)->���_h()) / ������) == (int)((������->���_y() + ������->���_h()) / ������ - 3)
									|| (int)(((*it2)->���_y() + (*it2)->���_h()) / ������) == (int)((������->���_y() + ������->���_h()) / ������ - 4)
									|| (int)(((*it2)->���_y() + (*it2)->���_h()) / ������) == (int)((������->���_y() + ������->���_h()) / ������ - 5)
									|| (int)(((*it2)->���_y() + (*it2)->���_h()) / ������) == (int)((������->���_y() + ������->���_h()) / ������ - 6)
									|| (int)(((*it2)->���_y() + (*it2)->���_h()) / ������) == (int)((������->���_y() + ������->���_h()) / ������ - 7)))
								{
									if (������->���_x() > (*it2)->���_x()) ������->���_�������(1); else ������->���_�������(0);
									������->���_�������������(1);
								}

							if ((*it2)->������().intersects(������->������()))
							{
								������->����_�������();
								(*it2)->����_�������();
							}
						}
						if ((*it2)->���_���() == "Bullet")
							if ((*it2)->���_�����() > 0)
								if ((*it2)->������().intersects(������->������()))
								{
									(*it2)->���_���(0); ������->���_�����(0);
								}
					}
					
				}

				//���� �����
				if (������->���_���() == "c") {
					if (�����.������().intersects(������->������()))
					{
						�����.���_����������(10); ������->���_���(0);
					}
				}
				//���� ��������
				if (������->���_���() == "hp") {
					if (�����.������().intersects(������->������()))
					{
						�����.���_�����(�����.���_�����() + 0.2); ������->���_���(0);
					}
				}

			}

			//��������������� � �����
			if (�����.���_x() > 45000)
			{
				//�������������
				���.���_�������������(0);
				for (int j = (���.���_x() / ������) - 7; j < (���.���_x() / ������) + 8; j++)
				{

					if (j == (int)(�����.���_x() / ������) && ((int)((�����.���_y() + �����.���_h()) / ������) == (int)((���.���_y() + ���.���_h()) / ������)
						|| (int)((�����.���_y() + �����.���_h()) / ������) == (int)((���.���_y() + ���.���_h()) / ������ - 1)
						|| (int)((�����.���_y() + �����.���_h()) / ������) == (int)((���.���_y() + ���.���_h()) / ������ - 2)
						|| (int)((�����.���_y() + �����.���_h()) / ������) == (int)((���.���_y() + ���.���_h()) / ������ - 3)
						|| (int)((�����.���_y() + �����.���_h()) / ������) == (int)((���.���_y() + ���.���_h()) / ������ + 1)))
					{
						if (���.���_x() > �����.���_x()) ���.���_�������(1); else ���.���_�������(0);
						if (���.���_������������() != ���.���_x())
						���.���_�������������(1);
						if (!�����.������().intersects(���.������()))
							���.���_�������2(1);
					}
				}

				//���� ������
				if (�����.������().intersects(���.������()))
				{
					if (���.���_t()) {
						���.���_t(0); ���.���_��������().��������[���.���_��������().��()].������� = 0;
					}
					���.����_�������();
					if (���.���_��() && ���.���_��������().���() == ���.���_�����()) {
						���.���_��();
						�����.���_�����(�����.���_�����() - ���.���_����());
						��������������.play();
					}
				}
				//���� ������ �� �����
				for (std::list<������*>::iterator it2 = �������.begin(); it2 != �������.end(); it2++)
				{
					������* ������ = *it2;
					if (������->���_���() == "cam")
						if (������->���_�����() > 0)
							if (������->������().intersects(�����.������()))
							{
								������->���_���(0);
								�����.���_�����(�����.���_�����() - ������->���_����());
								��������������.play();
							}
				}
				//���� �����
				for (std::list<������*>::iterator it2 = �������.begin(); it2 != �������.end(); it2++)
				{
					������* ������ = *it2;
					if (������->���_���() == "Bullet")
						if (������->���_�����() > 0)
							if (������->������().intersects(���.������()))
							{
								������->���_���(0); ���.���_�����(���.���_�����() - ������->���_����()); ��������.play();
							}
				}
			}

			//������ ������
			if (�����.���_�����() < 0)
			{
				�����.���_���(0);
				!��������� ? �����������.pause() : ���������.pause(); ��������������.play();
				����� = 0;
				��������.play();
				������� = 2;
				window.create(sf::VideoMode(1200, 628), L"������ ��������", Style::Close);
				window.setMouseCursorVisible(0);
			}

			//����� ������
			if (!��������� && �����.���_x() > 45000)
			{��������� = 1;�����������.stop();���������.play();}

			//������
			if (���.���_���() == 0) {
				������� = 2;
				����� = 0;
				window.create(sf::VideoMode(1200, 628), L"������ ��������", Style::Close);
				window.setMouseCursorVisible(0);
				���������.pause(); ������.play();
			}

				//�������� ������
				for (it = �������.begin(); it != �������.end();)
				{
					������* � = *it;
					if (�->���_���() == false) {
						it = �������.erase(it);
						delete �;
					}
					else it++;
				}

				//���������� ����������
				�����.��������(�����);
				���.��������(�����);
				for (it = �������.begin(); it != �������.end(); it++)
					(*it)->��������(�����);
			
			clok.restart();//����� �������

			//����������� �� �����
			view.setCenter(�����.���_x(), �����.���_y());
			window.setView(view);

			text3.setPosition(view.getCenter().x + 300, view.getCenter().y - 550);
			text2.setPosition(view.getCenter().x + 660, view.getCenter().y - 550);
			text.setPosition(view.getCenter().x - 960, view.getCenter().y - 550);
			��������.setPosition(view.getCenter().x + 660, view.getCenter().y - 550 + 60);
			�����.setPosition(view.getCenter().x - 960 + 75, view.getCenter().y - 550 + 60);

			window.clear(Color(85, 170, 255));
			lvl.Draw(window);
			for (it = �������.begin(); it != �������.end(); it++)
			{
				(*it)->��������(window);
				if ((*it)->���_���() == "npc1" && !(*it)->���_�������������())
				{
					text4.setPosition((*it)->���_x(), (*it)->���_y() - 100);
					text4.setString((*it)->���_�����());
					window.draw(text4);
				}
			}
			�����.��������(window);
			���.��������(window);

			if (�����.���_x() > 45000)window.draw(text2); window.draw(text);
			if (���) {
				text2.setString("����������");
				text2.setFillColor(Color::Green);
				text2.setPosition(view.getCenter().x + 660, view.getCenter().y - 450);
				window.draw(text2);
				if (�����.���_x() > x + 300 || �����.���_x() < x - 300)
				��� = 0;
			}
			if (�����.���_x() < 2400 && �����.���_y() < 1900)window.draw(text3);
			if (�����.���_x() > 45000)window.draw(��������);
			if (�����.���_�����() > 0) window.draw(�����);
			window.display();
		}
		if (������� == 2)
		{
			View view(FloatRect(0, 0, 1200, 628));
			window.setView(view);

			//������������ ����
			if (event.type == sf::Event::MouseMoved)
				���.setPosition(event.mouseMove.x, event.mouseMove.y);

			//���
			d.loadFromFile("��������/og_og_1540932814235486221.jpg");
			���.setTexture(d);//�������� �������� ��������
			���.setTextureRect(IntRect(0, 0, 1200, 628));

			//�����
			text.setFillColor(Color::Black);
			text2.setFillColor(Color::Black);
			text3.setFillColor(Color::Black);
			text5.setFillColor(Color::Black);
			text.setStyle(sf::Text::Bold);
			text2.setStyle(sf::Text::Bold);
			text3.setStyle(sf::Text::Bold);
			text.setString("������ � ������");
			text2.setString("���������� ����");
			text3.setString("���������� � ���������\n�����ͨ���� �����");
			text.setPosition(10, 400);
			text2.setPosition(10, 550);
			text3.setPosition(10, 450);
			text5.setPosition(850, 550);
			std::ostringstream go;
			go << ����������������;

			//�������� ����
			while (window.pollEvent(event))
				if (event.type == sf::Event::Closed)
					window.close();

			//������ � ������
			if (Mouse::getPosition(window).x > 10 && Mouse::getPosition(window).x < 10 + 475 && 
				Mouse::getPosition(window).y < 400 + 50 && Mouse::getPosition(window).y > 400)
			{

				text.setFillColor(Color::Red);//������� �����
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					
					for (it = �������.begin(); it != �������.end();)
					{
						������* � = *it;
						it = �������.erase(it);
						delete �;
					}

					for (int i = 0; i < g.size(); i++)
						�������.push_back(new ������(��������3, lvl, g[i].rect.left, g[i].rect.top, 0.3,1));

					for (int i = 0; i < g1.size(); i++)
						�������.push_back(new ������(��������3, lvl, g1[i].rect.left, g1[i].rect.top, 0.4,1));


					for (int i = 0; i < g2.size(); i++)
						�������.push_back(new ������(��������3, lvl, g2[i].rect.left, g2[i].rect.top, 0.5,1));

					for (int i = 0; i < c.size(); i++)
						�������.push_back(new �����("c", ��������4, c[i].rect.left, c[i].rect.top));

					for (int i = 0; i < hp.size(); i++)
						�������.push_back(new �����("hp", ��������5, hp[i].rect.left, hp[i].rect.top));

					for (int i = 0; i < hg.size(); i++)
						�������.push_back(new ������(��������6, lvl, hg[i].rect.left, hg[i].rect.top, 0.3, 2));

					for (int i = 0; i < hl.size(); i++)
						�������.push_back(new ����(��������7, lvl, hl[i].rect.left, hl[i].rect.top));

					for (int i = 0; i < npc1.size(); i++)
						�������.push_back(new ���1(��������10, lvl, npc1[i].rect.left, npc1[i].rect.top));

					�����.���_x(pl.rect.left);
					�����.���_y(pl.rect.top);
					�����.���_�����(1);
					�����.���_���(1);

					���.���_x(bos.rect.left);
					���.���_y(bos.rect.top);
					���.���_�����(10);
					���.���_���(1);

					�����.���_����������(10);

					//����� ����������
					��������������.stop(); ������.stop(); ���������.stop(); �����������.stop(); �����������.play();
					��������� = 0;
					������� = 1;
					
					��� = 0; ���1 = 0; ���2 = 0; ���3 = 0; ���4 = 0; ���������������� = 57;

					//��������� ����
					window.create(VideoMode(), L"������ ��������", Style::Fullscreen);
					window.setMouseCursorVisible(0);
				}
			}

			//����������
			if (Mouse::getPosition(window).x > 10 && Mouse::getPosition(window).x < 10 + 725 && 
				Mouse::getPosition(window).y < 450 + 100 && Mouse::getPosition(window).y > 450
				&& ���.���_���() == 1)
			{
				text3.setFillColor(Color::Red);//�������� �����
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					for (it = �������.begin(); it != �������.end();)
					{
						������* � = *it;
						it = �������.erase(it);
						delete �;
					}

					for (it = �������2.begin(); it != �������2.end(); it++)
					{
						������* � = *it; ������* r = new �����("hp", ��������5, 1, 1);
						if (�->���_���() == "c" || �->���_���() == "hp")
							r = new �����("hp", ��������5, 1, 1);
						if (�->���_���() == "goblin" || �->���_���() == "goblin1" || �->���_���() == "goblin2")
							r = new ������(��������3, lvl, 1, 1, 0.3,1);
						if (�->���_���() == "hl")
							r = new ����(��������3, lvl, 1, 1);
						if (�->���_���() == "npc1")
							r = new ���1(��������10, lvl, 1, 1);
						/*if (�->��� == "c" || �->��� == "hp")
							r = new ���(��������3, lvl, 1, 1);*/
						*r = *�;
						�������.push_back(r);
					}
					
					�����.���_����������(����������);
					�����.���_x(x);
					�����.���_y(y);
					�����.���_���(1);
					�����.���_�����(�����);
					���.���_�����(10);

					��������������.pause(); !��������� ? �����������.play() : ���������.play();
					window.create(VideoMode(), L"������ ��������", Style::Fullscreen);
					window.setMouseCursorVisible(0);

					������� = 1;
				}
			}

			//���������� ����
			if (�����)
			if (Mouse::getPosition(window).x > 10 && Mouse::getPosition(window).x < 10 + 500 && 
				Mouse::getPosition(window).y < 550 + 50 && Mouse::getPosition(window).y > 550
				&& ���.���_���() == 1)
			{
				text2.setFillColor(Color::Red);//�������� �����
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					//����������� � ����
					��������������.pause(); !��������� ? �����������.play() : ���������.play();
					window.create(VideoMode(), L"������ ��������", Style::Fullscreen);
					window.setMouseCursorVisible(0);
					if (!����� && �����.���_����������() < 5) { �����.���_����������(5); }
					if (!�����.���_���())
					{
						�����.���_���(1); �����.���_�����(1);
					}
					������� = 1;
				}
			}

			//������� ������ � ����������
			if (Mouse::getPosition(window).x > 850 && Mouse::getPosition(window).x < 850 + 300 && \
				Mouse::getPosition(window).y < 550 + 50 && Mouse::getPosition(window).y > 550)
			{
				text5.setFillColor(Color::Red);//������ �� ������
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					������� = 3; ��������� = 2;
				}
			}

			//����������� ��������
			window.draw(���);
			window.draw(text);
			if (!�����) {
				text.setString("�� ��������!"); text.setPosition(800, 0); text.setFillColor(Color::Red);
				if (���.���_�����() > 0)
				text.setString("�� ���������"); text.setPosition(800, 0); text.setFillColor(Color::Red);
				window.draw(text);
				text.setFillColor(Color::Green);
				if (���������������� > 0) {
					text.setPosition(700, 100);
					text.setString("�������� ��������: " + go.str() + "\n����� ��� �����\n������� �� �������");
				}
				window.draw(text);
			}
			
			

			window.draw(text2);
			window.draw(text3);
			window.draw(text5);
			window.draw(���);
			window.display();
			clok.restart();
		}
		if (������� == 3){
			bool k;
			Texture �, �;
			Sprite �����, ��������, �����1, ��������1;
			d.loadFromFile("��������/dark-4487690_1280.jpg");
			�.loadFromFile("��������/12.png");
			�.loadFromFile("��������/1.png");
			���.setTexture(d);
			�����.setTexture(�); �����1.setTexture(�);
			��������.setTexture(�); ��������1.setTexture(�);
			���.setTextureRect(IntRect(0, 0, 1280, 720));
			text.setString("�����");
			text.setPosition(560, 550);

			text4.setString("��������� ������\n\n\n\n��������� ������");
			text4.setPosition(100, 195);
			//�����.setTextureRect(IntRect(0, 0, 30, 30));
			//��������.setTextureRect(IntRect(0, 0, 258, 10));
			�����.setPosition(�1, 290); �����1.setPosition(�2, 200);
			��������.setPosition(350, 300); ��������1.setPosition(350, 210);

			while (window.pollEvent(event))//��������� �������
			{
				��� = 1;

				//������������ ����
				if (event.type == sf::Event::MouseMoved)
					���.setPosition(event.mouseMove.x, event.mouseMove.y);

				//��������� ������
				text.setFillColor(Color::Black);
				text.setStyle(sf::Text::Bold);

				//��������� ����
				if (event.type == sf::Event::Closed)
					window.close();

				//������� ������ � ��������� ������
				if (Mouse::getPosition(window).x > 350 && Mouse::getPosition(window).x < 578 + 30 &&
					Mouse::getPosition(window).y < 290 + 30 && Mouse::getPosition(window).y > 290)
					if (Mouse::isButtonPressed(Mouse::Left))
					{k = 1; �1 = Mouse::getPosition(window).x - 15; } else {if (k) { �����������.play(); k = 0; } }
				if (�1 < 350) �1 = 350; if (�1 > 578) �1 = 578;

				//������� ������ � ��������� ������
				if (Mouse::getPosition(window).x > 350 && Mouse::getPosition(window).x < 578 + 30 &&
					Mouse::getPosition(window).y < 200 + 30 && Mouse::getPosition(window).y > 200)
					if (Mouse::isButtonPressed(Mouse::Left))
						�2 = Mouse::getPosition(window).x - 15;
				if (�2 < 350) �2 = 350; if (�2 > 578) �2 = 578;
				
				�����.setPosition(�1, 290); �����1.setPosition(�2, 200);

				//������� ������ � ������
				if (Mouse::getPosition(window).x > 560 && Mouse::getPosition(window).x < 560 + 180 &&
					Mouse::getPosition(window).y < 550 + 50 && Mouse::getPosition(window).y > 550)
				{
					text.setFillColor(Color::Red);//������ �� ������
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						������� = ���������; 
					}
				}
			}
			//���������
			��������������� = ((double)(�2 - 350) / 228) * 100;
			�����������.setVolume(���������������);
			���������.setVolume(���������������);
			��������������.setVolume(���������������);
			������.setVolume(���������������);

			��������������� = ((double)(�1 - 350) / 228) * 100;
			�����������.setVolume(���������������);
			��������.setVolume(���������������);
			��������.setVolume(���������������);
			��������������.setVolume(���������������);

			//���������� �������
			window.draw(���);
			window.draw(text);
			if (���) {
				window.draw(text4);
				window.draw(��������);
				window.draw(�����);
				window.draw(��������1);
				window.draw(�����1);
				window.draw(���);
			}
			window.display();
			clok.restart();
		}
	}
	return 0;
}