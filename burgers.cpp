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
    GtkWidget *back_button, *cheeseburger_img, *cheeseburger_btn, *pay;

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

    // might have to resize the image manually tbh
    //cheeseburger_img = gtk_image_new_from_file("/images/burgers/cheeseburger.jpg");
    cheeseburger_btn = gtk_button_new_with_label("Cheeseburger");
    gtk_widget_set_name(cheeseburger_btn, "cburg_btn");
    //gtk_widget_set_name(cheeseburger_img, "cburg_img");

    gtk_fixed_put(GTK_FIXED(fixed), cheeseburger_btn, 0, 50); 
    gtk_widget_set_size_request(cheeseburger_btn, 200, 200);
    gtk_button_set_always_show_image(GTK_BUTTON(cheeseburger_btn), TRUE);
    gtk_button_set_image (GTK_BUTTON(cheeseburger_btn), cheeseburger_img);

    g_signal_connect(cheeseburger_btn, "clicked", G_CALLBACK(burger_button_click), NULL);

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