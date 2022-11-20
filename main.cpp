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

//supposed to make a shape on screen but currently shows nothing
// static void do_drawing(cairo_t *cr){
//     cairo_set_source_rgb(cr, 0.5, 0.5, 1);
//     cairo_rectangle(cr, 150, 140, 100, 100);
//     cairo_fill(cr);
// }

// static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data){
//     do_drawing(cr);
//     return FALSE;
// }


int main(int argc, char *argv[]) {
    
    // GtkWidget *darea;
    // GtkWidget *menu_window;
    GtkWidget *window, *fixed; 
    GtkWidget *review, *menu, *locations, *rewards,
              *reservation, *pay, *exit; // declare buttons

    gtk_init(&argc, &argv);
    load_css();

    // Initialize window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Burger Bistro");
    gtk_window_set_default_size(GTK_WINDOW(window), 1360, 600); // full window size on my screen
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    // menu_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // gtk_window_set_default_size(GTK_WINDOW(menu_window), 1360, 600);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // darea = gtk_drawing_area_new();
    // gtk_container_add(GTK_CONTAINER(fixed), darea);
    // gtk_fixed_put(GTK_FIXED(fixed), darea, 0, 0);
    // g_signal_connect(G_OBJECT(darea), "draw", 
    //     G_CALLBACK(on_draw_event), NULL);

    // Menu Button
    menu = gtk_button_new_with_label("Menu");
    gtk_fixed_put(GTK_FIXED(fixed), menu, 0, 0); // (x, y) coordinates
    gtk_widget_set_size_request(menu, 70, 30); // size of the button (x,y)
    //g_signal_connect(menu, "clicked", G_CALLBACK(on_button_click), NULL); //call function from menu.cpp
    //g_signal_connect(menu, "clicked", G_CALLBACK(on_button_click), (gpointer)menu_window);

    // Review Button
    review = gtk_button_new_with_label("Write a Review");
    gtk_widget_set_name(review, "btn_red"); // button only turns red when clicked on
    gtk_fixed_put(GTK_FIXED(fixed), review, 0, 50); 
    gtk_widget_set_size_request(review, 70, 30); 
    
    // Location Button
    locations = gtk_button_new_with_label("View Locations");
    gtk_fixed_put(GTK_FIXED(fixed), locations, 0, 100); 
    gtk_widget_set_size_request(locations, 70, 30); 

    // Rewards Button
    rewards = gtk_button_new_with_label("Rewards");
    gtk_fixed_put(GTK_FIXED(fixed), rewards, 0, 150); 
    gtk_widget_set_size_request(rewards, 70, 30); 

    // Reservation Button
    reservation = gtk_button_new_with_label("Make a Reservation");
    gtk_fixed_put(GTK_FIXED(fixed), reservation, 0, 200); 
    gtk_widget_set_size_request(reservation, 70, 30); 

    // Pay Online Button
    pay = gtk_button_new_with_label("Pay Online");
    gtk_fixed_put(GTK_FIXED(fixed), pay, 0, 250); 
    gtk_widget_set_size_request(pay, 70, 30); 

    // Exit Button
    exit = gtk_button_new_with_label("Exit");
    gtk_fixed_put(GTK_FIXED(fixed), exit, 0, 300); 
    gtk_widget_set_size_request(exit, 70, 30); 


    g_signal_connect(G_OBJECT(exit), "clicked", 
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

    g_signal_connect(G_OBJECT(window), "destroy", 
        G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}