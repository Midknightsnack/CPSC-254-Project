#include <gtk/gtk.h>
#include <cairo.h>
#include <gtkmm.h>
#include <iostream>
#include "click.h"
using namespace std;

// allows css properties to load in GUI
static void load_css(void){
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;

    const gchar *css_style_file = "styles.css";
    GFile *css_fp = g_file_new_for_path(css_style_file);
    GError *error = 0;

    provider = gtk_css_provider_new();
    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen (display);

    gtk_style_context_add_provider_for_screen (screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_css_provider_load_from_file(provider, css_fp, &error);

    g_object_unref(provider); 
}


int main(int argc, char *argv[]) {
    
    GtkWidget *window, *fixed; 
    GtkWidget *back_button, *search, *burgers, 
              *deluxe_burgers, *sides, *drinks; // declare buttons

    gtk_init(&argc, &argv);
    load_css();

    // Initialize window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Burger Bistro");
    gtk_window_set_default_size(GTK_WINDOW(window), 1360, 600); // full window size on my screen
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Back Button
    back_button = gtk_button_new_with_label("Back");
    gtk_fixed_put(GTK_FIXED(fixed), back_button, 0, 25); // (x, y) coordinates
    gtk_widget_set_size_request(back_button, 100, 50); // size of the button (x,y)

    // Search Button
    search = gtk_button_new_with_label("Search Menu");
    gtk_fixed_put(GTK_FIXED(fixed), search, 200, 25); 
    gtk_widget_set_size_request(search, 100, 50); 
    
    // Burgers Button
    burgers = gtk_button_new_with_label("Burgers");
    gtk_fixed_put(GTK_FIXED(fixed), burgers, 480, 100); 
    gtk_widget_set_size_request(burgers, 200, 200); 

    // Deluxe Burgers Button
    deluxe_burgers = gtk_button_new_with_label("Deluxe Burgers");
    gtk_fixed_put(GTK_FIXED(fixed), deluxe_burgers, 680, 100); 
    gtk_widget_set_size_request(deluxe_burgers, 200, 200); 

    // Sides Button
    sides = gtk_button_new_with_label("Sides");
    gtk_fixed_put(GTK_FIXED(fixed), sides, 480, 300); 
    gtk_widget_set_size_request(sides, 200, 200); 

    // Drinks Button
    drinks = gtk_button_new_with_label("Drinks");
    gtk_fixed_put(GTK_FIXED(fixed), drinks, 680, 300); 
    gtk_widget_set_size_request(drinks, 200, 200); 

    g_signal_connect(G_OBJECT(window), "destroy", 
        G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}