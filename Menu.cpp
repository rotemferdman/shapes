#include "Menu.h"
#include <iostream>
#include "Arrow.h"
#include "Circle.h"
#include "Canvas.h"
#include "Point.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"
#include <stdio.h>

#define MAX 100


Menu::~Menu()
{
}

void Menu::start()
{
	/* c i r c l e  v a r s*/
	double x = 0;
	double y = 0;
	double x2 = 0;
	double y2 = 0;
	double x3 = 0;
	double y3 = 0;
	double radius = 0;
	std::string type;
	std::string name;
	double a = 0;
	double h = 0;
	int circle_count = 0;
	Circle* c_arr[MAX] = { nullptr };
	int c1 = -1;
	Point p;
	Point p2;
	Point p3;
	Arrow* pa = nullptr;
	/* ------------------------ */
	/* a r r o w  v a r s*/
	Arrow* a_arr[MAX] = { nullptr };
	int arrow_counter = 0;
	/* -------------------------*/
	/* t r i a n g l e  v a r s */
	Triangle* t_arr[MAX] = { nullptr };
	int triangle_counter = 0;
	/* ------------------------- */
	/* r e c k t a n g l e  v a r s*/
	myShapes::Rectangle* r_arr[MAX] = { nullptr };
	int rectangle_counter = 0;
	int width = 0;
	int lengh = 0;
	/* ------------------------- */
	int choice = -1;
	int choice1 = -1;
	std::string strs_c[MAX];
	int i = 0;
	Circle* pc = nullptr;
	Circle* pe = nullptr;
	std::string s;
	int options_in_1 = 0;
	int ch = 0;
	int gh = 0;
	std::string strs_a[MAX];
	Triangle* pt = nullptr;
	std::string strs_t[MAX];
	std::string strs_r[MAX];
	myShapes::Rectangle* pr = nullptr;

	while (true)
	{
		system("CLS");
		std::cout << "Welcome! please choose an option:\n[0] Add a new shape.\n[1] modify or get information about the shapes\n[2] delete all shapes\n[3] Exit :(" << std::endl;
		choice = -1;

		while (choice < 0 || choice > 3)
		{
			std::cin >> choice;
		}

		if (choice == 3)
		{
			break;;
		}

		else if (choice == 0)
		{
			system("CLS");
			std::cout << "Press 0 to add a circle\nPress 1 to add an arrow\nPress 2 to add a triangle\nPress 3 to add a rectangle\n" << std::endl;
			c1 = -1;

			while (c1 < 0 || c1 > 3)
			{
				std::cin >> c1;
			}

			if (c1 == 0)
			{
				//add circle
				std::cout << "Please enter x:" << std::endl;
				std::cin >> x;
				std::cout << "Please enter y:" << std::endl;
				std::cin >> y;
				std::cout << "Please enter radius:" << std::endl;
				std::cin >> radius;
				std::cout << "Please enter the name of the shape:" << std::endl;
				std::cin >> name;
				p.setX(x);
				p.setY(y);

				Circle* o = new Circle(p, radius, "Circle", name);
				c_arr[circle_count] = o;
				strs_c[circle_count] = o->getName();
				circle_count++;


				o->draw(this->_canvas);


			}
			else if (c1 == 1)
			{
				//add arrow
				std::cout << "Please enter x1:" << std::endl;
				std::cin >> x;
				std::cout << "Please enter y1:" << std::endl;
				std::cin >> y;
				p.setX(x);
				p.setY(y);
				std::cout << "Please enter x2:" << std::endl;
				std::cin >> x2;
				std::cout << "Please enter y2:" << std::endl;
				std::cin >> y2;
				p2.setX(x2);
				p2.setY(y2);
				std::cout << "Please enter a name: " << std::endl;
				std::cin >> name;

				Arrow* new_arrow = new Arrow(p, p2, "Arrow", name);
				a_arr[arrow_counter] = new_arrow;
				strs_a[arrow_counter] = new_arrow->getName();
				arrow_counter++;

				new_arrow->draw(this->_canvas);


			}

			else if (c1 == 2)
			{
				//add triangle
				std::cout << "Please enter x1:" << std::endl;
				std::cin >> x;
				std::cout << "Please enter y1:" << std::endl;
				std::cin >> y;
				p.setX(x);
				p.setY(y);
				std::cout << "Please enter x2:" << std::endl;
				std::cin >> x2;
				std::cout << "Please enter y2:" << std::endl;
				std::cin >> y2;
				p2.setX(x2);
				p2.setY(y2);
				std::cout << "Please enter x3:" << std::endl;
				std::cin >> x3;
				std::cout << "Please enter y3:" << std::endl;
				std::cin >> y3;
				p3.setX(x3);
				p3.setY(y3);
				std::cout << "Please enter a name: " << std::endl;
				std::cin >> name;

				Triangle* new_tri = new Triangle(p, p2, p3, "Triangle", name);

				t_arr[triangle_counter] = new_tri;
				strs_t[triangle_counter] = new_tri->getName();
				triangle_counter++;

				new_tri->draw(this->_canvas);
			}

			else if (c1 == 3)
			{
				//add rectangle
				std::cout << "Please enter x1:" << std::endl;
				std::cin >> x;
				std::cout << "Please enter y1:" << std::endl;
				std::cin >> y;
				p.setX(x);
				p.setY(y);

				std::cout << "Please enter the lengh: " << std::endl;
				std::cin >> lengh;
				std::cout << "Please enter the width: " << std::endl;
				std::cin >> width;
				std::cout << "Please enter the name: " << std::endl;
				std::cin >> name;

				myShapes::Rectangle* new_rec = new myShapes::Rectangle(p, lengh, width, "Rectangle", name);
				r_arr[rectangle_counter] = new_rec;
				strs_r[rectangle_counter] = new_rec->getName();
				rectangle_counter++;

				new_rec->draw(this->_canvas);

			}

		} //end of choice 0.


		else if (choice == 1)
		{

			std::cout << "0 for circles\n1 for arrows\n2 for triangles\n3 for rectangles" << std::endl;
			std::cin >> options_in_1;
			system("CLS");
			if (options_in_1 == 0) //circles
			{
				for (i = 0; i < circle_count; i++) //print the options
				{
					s = strs_c[i];
					std::cout << i + 1 << ": " << s << std::endl;
				}

				std::cin >> ch;
				pc = c_arr[ch - 1]; //the shape
				system("CLS");
				std::cout << "0 to move the shape\n1 to get its details\n2 to remove the shape" << std::endl;
				std::cin >> gh;

				if (gh == 0) //move the shape
				{
					pc->clearDraw(this->_canvas);

					std::cout << "Enter a new x" << std::endl;
					std::cin >> x;
					std::cout << "Enter a new y" << std::endl;
					std::cin >> y;
					p.setX(x);
					p.setY(y);
					pc->move(p);




				}
				else if (gh == 1) //show details
				{
					if (pc != nullptr)
					{
						std::cout << pc->getArea() << "  " << pc->getPerimeter() << std::endl;
						system("PAUSE");
					}
				}

				else
				{
					pc->clearDraw(this->_canvas);

					for (i = ch; i < circle_count; i++)
					{
						c_arr[i] = c_arr[i + 1];
						strs_c[i] = strs_c[i + 1];
					}
					circle_count--;

				}

			}
			else if (options_in_1 == 1) //if arrows
			{

				for (i = 0; i < arrow_counter; i++) //print the options
				{
					s = strs_a[i];
					std::cout << i + 1 << ": " << s << std::endl;
				}

				std::cin >> ch;
				pa = a_arr[ch - 1]; //the shape
				system("CLS");
				std::cout << "0 to move the shape\n1 to get its details\n2 to remove the shape" << std::endl;
				std::cin >> gh;

				if (gh == 0) //move the shape
				{
					pa->clearDraw(this->_canvas);

					std::cout << "Enter a new x" << std::endl;
					std::cin >> x;
					std::cout << "Enter a new y" << std::endl;
					std::cin >> y;
					p.setX(x);
					p.setY(y);
					pa->move(p);


					pa->draw(this->_canvas);

				}
				else if (gh == 1) //show details
				{
					if (pa != nullptr)
					{
						std::cout << pa->getArea() << "  " << pa->getPerimeter() << std::endl;
						system("PAUSE");
					}
				}

				else
				{
					pa->clearDraw(this->_canvas);

					for (i = ch; i < arrow_counter; i++)
					{
						a_arr[i] = a_arr[i + 1];
						strs_a[i] = strs_a[i + 1];
					}
					arrow_counter--;

				}
			}


			else if (options_in_1 == 2) //triangles
			{
				for (i = 0; i < triangle_counter; i++) //print the options
				{
					s = strs_t[i];
					std::cout << i + 1 << ": " << s << std::endl;
				}

				std::cin >> ch;
				pt = t_arr[ch - 1]; //the shape
				system("CLS");
				std::cout << "0 to move the shape\n1 to get its details\n2 to remove the shape" << std::endl;
				std::cin >> gh;

				if (gh == 0) //move the shape
				{
					pt->clearDraw(this->_canvas);

					std::cout << "Enter a new x" << std::endl;
					std::cin >> x;
					std::cout << "Enter a new y" << std::endl;
					std::cin >> y;
					p.setX(x);
					p.setY(y);
					pt->move(p);


					pt->draw(this->_canvas);

				}
				else if (gh == 1) //show details
				{
					if (pt != nullptr)
					{
						std::cout << pt->getArea() << "  " << pt->getPerimeter() << std::endl;
						system("PAUSE");
					}
				}

				else
				{
					pt->clearDraw(this->_canvas);

					for (i = ch; i < triangle_counter; i++)
					{
						t_arr[i] = t_arr[i + 1];
						strs_t[i] = strs_t[i + 1];
					}
					triangle_counter--;

				}
			}


			else //rectangles
			{

				for (i = 0; i < rectangle_counter; i++) //print the options
				{
					s = strs_r[i];
					std::cout << i + 1 << ": " << s << std::endl;
				}

				std::cin >> ch;
				pr = r_arr[ch - 1]; //the shape
				system("CLS");
				std::cout << "0 to move the shape\n1 to get its details\n2 to remove the shape" << std::endl;
				std::cin >> gh;

				if (gh == 0) //move the shape
				{
					pr->clearDraw(this->_canvas);

					std::cout << "Enter a new x" << std::endl;
					std::cin >> x;
					std::cout << "Enter a new y" << std::endl;
					std::cin >> y;
					p.setX(x);
					p.setY(y);
					pr->set_length(x);
					pr->set_width(y);
					pr->move(p);
					
					

					pr->draw(this->_canvas);

				}
				else if (gh == 1) //show details
				{
					if (pr != nullptr)
					{
						std::cout << pr->getArea() << "  " << pr->getPerimeter() << std::endl;
						system("PAUSE");
					}
				}

				else
				{
					pr->clearDraw(this->_canvas);

					for (i = ch; i < rectangle_counter; i++)
					{
						r_arr[i] = r_arr[i + 1];
						strs_r[i] = strs_r[i + 1];
					}
					rectangle_counter--;
				}
			}

		}
		if (choice == 2)
		{
			//deleating all the shapes and counters go back to 0.
			for (i = 0; i < circle_count; i++)
			{
				c_arr[i]->clearDraw(this->_canvas);
				c_arr[i] = nullptr;
				
				strs_c[i] = "";

			}
			for (i = 0; i < arrow_counter; i++)
			{
				a_arr[i]->clearDraw(this->_canvas);
				a_arr[i] = NULL;
				strs_a[i] = "";

			}
			for (i = 0; i < triangle_counter; i++)
			{
				t_arr[i]->clearDraw(this->_canvas);
				t_arr[i] = NULL;
				strs_t[i] = "";

			}
			for (i = 0; i < rectangle_counter; i++)
			{
				r_arr[i]->clearDraw(this->_canvas);
				r_arr[i] = NULL;
				strs_r[i] = "";

			}

			circle_count = 0;
			arrow_counter = 0;
			triangle_counter = 0;
			rectangle_counter = 0;
		}
	}
}

