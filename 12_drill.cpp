#include "Simple_window.h"
#include "Graph.h"

	
int main() 
try {
	using namespace Graph_lib;
	
	int ymax = 720;
	int xmax = 1280;

	Simple_window win{Point{100,100}, xmax, ymax, "Ablakom"};

	Image ii {Point{10,10},"papo.jpg"};
	win.attach(ii);
	ii.move(100,ymax/2);

	Axis xa{Axis::x, Point{20,ymax/2}, xmax-40, 20, "x axis"};
	win.attach(xa);


	Axis ya{Axis::y, Point{xmax/2,ymax}, ymax-40, 20, "y axis"};
	win.attach(ya);
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_green);



	Rectangle r {Point{200,200}, 120, 40};
	win.attach(r);
	r.set_fill_color(Color::dark_cyan);



	Function sine{sin,0,100,Point{20,150},1000,50,50};
	win.attach(sine);



	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	win.attach(poly);
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	poly.set_style(Line_style(Line_style::dash,5));



	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});
	win.attach(poly_rect);
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);



	Text t{Point{150,150}, "HEHEJ!"};
	win.attach(t);
	t.set_font(Font::times_bold);
	t.set_font_size(40);



	


	Circle c {Point{100,200},70};
	win.attach(c);


	Ellipse e {Point{100,200}, 100,40};
	win.attach(e);
	e.set_color(Color::black);


	Mark m {Point{100,200},'x'};
	win.attach(m);



	ostringstream oss;

	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{130,40},oss.str()};
	win.attach(sizes);
	win.wait_for_button();


}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "Something went wrong" << endl;
    keep_window_open();
}