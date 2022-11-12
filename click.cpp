#include <iostream>
#include <gtk/gtk.h>
#include "click.h"
using namespace std;

void on_button_click(){
    cout << "Menu button clicked" << endl; //testing if button works
}

void burger_button_click(){
    cout << "Burger button clicked" << endl; //testing if button works
}
// static void on_button_click(GtkWidget* widget, gpointer menu_window){
//     gtk_container_add(GTK_CONTAINER(menu_window));
// }