#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
//------------------------
#include <windows.h>
#include <iostream>
#include <string>



using namespace std;

void m1f(Fl_Widget* w, void* data);

void conf(Fl_Widget* w, void* data);

void ShowConsole() {
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

void HideConsole() {
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

int main(int argc, char** argv)
{	
	SetConsoleOutputCP(CP_UTF8); SetConsoleCP(CP_UTF8); HideConsole();

	//variables
	bool* isConsoleHere = new bool(0);

	Fl_Window win(800, 600, "Главное окно");

	//группа главного меню
	Fl_Group* bmenu = new Fl_Group(5, 5, 790, 590);
	win.add(bmenu);

	

	Fl_Button b1(10, 10, 100, 50, "Меню 1");
	Fl_Button b2(115, 10, 100, 50, "Меню 2");
	Fl_Button b3(220, 10, 100, 50, "Меню 3");
	Fl_Button con(690, 540, 100, 50, "Консоль");

	b1.tooltip("Привет");
	//events
	b1.callback(m1f, bmenu->parent());//m1
	b2.callback(m1f, bmenu->parent());//m2
	b3.callback(m1f, bmenu->parent());//m3
	con.callback(conf, isConsoleHere);



	bmenu->end();

	//меню 1
	Fl_Group* menu1 = new Fl_Group(5, 5, 790, 200);
	win.add(menu1);
	menu1->hide();
	menu1->box(FL_DOWN_BOX);

	Fl_Box text(10, 10, 200, 150, "text for menu 1");
	
	menu1->end();

	//меню 2
	Fl_Group* menu2 = new Fl_Group(5, 5, 790, 200);
	win.add(menu2);
	menu2->hide();

	menu2->box(FL_DOWN_BOX);
	Fl_Box text2(10, 10, 200, 150, "text for menu 2");

	menu2->end();

	//меню 3
	Fl_Group* menu3 = new Fl_Group(5, 5, 790, 200);
	win.add(menu3);
	menu3->hide();

	menu3->box(FL_DOWN_BOX);
	Fl_Box text3(10, 10, 200, 150, "text for menu 3");

	menu3->end();

	//back button
	Fl_Button back(695, 545, 100, 50, "Назад");
	back.hide();

	back.callback(m1f, bmenu->parent());


	

	win.end();
	win.show(argc, argv);

	return Fl::run();
}

void m1f(Fl_Widget* w, void* data)
{
	Fl_Window* m = (Fl_Window*)data;
	Fl_Button* b = (Fl_Button*)w;

	const char* b_text;
	b_text = b->label();
	short num = m->children() - 1;

	if (m->child(0)->visible())
	{
		m->child(0)->hide();

		if (b_text == "Меню 1")
		{
			m->child(1)->show();
			m->child(num)->show();
			m->color(FL_GREEN);
			cout << "открыто меню 1" << endl;
		}
		else if (b_text == "Меню 2")
		{
			m->child(2)->show();
			m->child(num)->show();
			m->color(FL_BLUE);
			cout << "открыто меню 2" << endl;
		}
		else if (b_text == "Меню 3")
		{
			m->child(3)->show();
			m->child(num)->show();
			m->color(FL_MAGENTA);
			cout << "открыто меню 3" << endl;
		}

	}
	else
	{
		m->child(num)->hide();
		for (short i = 0; i < m->children(); i++)
		{
			if (m->child(i)->visible())
			{
				m->child(i)->hide();
				break;
			}
		}
		m->color(FL_WHITE);
		m->child(0)->show();
	}
}

void conf(Fl_Widget* w, void* data)
{
	bool* con = (bool*)data;

	if (*con == 0)
	{
		*con = 1;
		ShowConsole();
	}
	else
	{
		*con = 0;
		HideConsole();
	}
}
