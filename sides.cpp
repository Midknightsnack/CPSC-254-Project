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
    
    GtkWidget *window, *fixed, *back_button, *pay; 
    GtkWidget *nuggets_btn, *nuggets_info, *fries_btn, *fries_info,
              *onion_rings_btn, *onion_rings_info;

    gtk_init(&argc, &argv);
    load_css();

    // Initialize window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Burger Bistro");
    gtk_window_set_default_size(GTK_WINDOW(window), 1360, 600); 
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Back Button
    back_button = gtk_button_new_with_label("Back");
    gtk_fixed_put(GTK_FIXED(fixed), back_button, 0, 0); 
    gtk_widget_set_size_request(back_button, 70, 30); 

    // Chicken Nuggets Image/ Button
    nuggets_btn = gtk_button_new();
    gtk_widget_set_name(nuggets_btn, "nuggets_btn");

    gtk_fixed_put(GTK_FIXED(fixed), nuggets_btn, 0, 50); 
    gtk_widget_set_size_request(nuggets_btn, 200, 200);

    nuggets_info = gtk_button_new_with_label("Chicken Nuggets: \n5 pc: $3.00 \n10 pc: $4.50");
    gtk_fixed_put(GTK_FIXED(fixed), nuggets_info, 200, 50); 
    gtk_widget_set_size_request(nuggets_info, 200, 200);

    // Fries Image/ Button
    fries_btn = gtk_button_new();
    gtk_widget_set_name(fries_btn, "fries_btn");
    gtk_fixed_put(GTK_FIXED(fixed), fries_btn, 0, 300); 
    gtk_widget_set_size_request(fries_btn, 200, 200);

    fries_info = gtk_button_new_with_label("Fries: \nSmall: $1.50 \nMedium: $1.75 \nLarge: $2.00");
    gtk_fixed_put(GTK_FIXED(fixed), fries_info, 200, 300); 
    gtk_widget_set_size_request(fries_info, 200, 200);

    // Onion Rings Image/ Button
    onion_rings_btn = gtk_button_new();
    gtk_widget_set_name(onion_rings_btn, "onion_rings_btn");
    gtk_fixed_put(GTK_FIXED(fixed), onion_rings_btn, 700, 50); 
    gtk_widget_set_size_request(onion_rings_btn, 200, 200);

    onion_rings_info = gtk_button_new_with_label("Onion Rings (10 pc): \nPrice: $4.00");
    gtk_fixed_put(GTK_FIXED(fixed), onion_rings_info, 900, 50); 
    gtk_widget_set_size_request(onion_rings_info, 200, 200);

    // Pay Online Button
    pay = gtk_button_new_with_label("Pay Online");
    gtk_fixed_put(GTK_FIXED(fixed), pay, 100, 0); 
    gtk_widget_set_size_request(pay, 70, 30); 

    g_signal_connect(G_OBJECT(window), "destroy", 
        G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}