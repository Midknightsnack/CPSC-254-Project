#include <gtkmm.h>
#include <gtk/gtk.h>
#include <iostream>
using namespace std;

void on_button_click();

int main(int argc, char *argv[]){
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
    Gtk::Window window;
    Gtk::Button button("Click here"); //using Button fills up the whole window? use Box

    window.set_default_size(600, 360);
    window.set_title("Burger Bistro");
    window.set_position(Gtk::WIN_POS_CENTER);

    button.signal_clicked().connect(
        sigc::ptr_fun(&on_button_click)
    );

    button.show();
    window.add(button);

    return app->run(window);
    return 0;
}

void on_button_click(){
    cout << "Button clicked" << endl;
}