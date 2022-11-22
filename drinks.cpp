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
    GtkWidget *soda_btn, *soda_info, *lemonade_btn, *lemonade_info,
              *milkshake_btn, *milkshake_info, *bluedrink_btn, *bluedrink_info;

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
    gtk_fixed_put(GTK_FIXED(fixed), back_button, 0, 25); 
    gtk_widget_set_size_request(back_button, 100, 50); 

    // Soda Image/ Button
    soda_btn = gtk_button_new();
    gtk_widget_set_name(soda_btn, "soda_btn");

    gtk_fixed_put(GTK_FIXED(fixed), soda_btn, 0, 100); 
    gtk_widget_set_size_request(soda_btn, 200, 200);

    soda_info = gtk_button_new_with_label("Soda: \nSmall: $1.00 \nMedium: $1.25 \nLarge: $1.50");
    gtk_fixed_put(GTK_FIXED(fixed), soda_info, 200, 100); 
    gtk_widget_set_size_request(soda_info, 200, 200);

    // Lemonade Image/ Button
    lemonade_btn = gtk_button_new();
    gtk_widget_set_name(lemonade_btn, "lemonade_btn");
    gtk_fixed_put(GTK_FIXED(fixed), lemonade_btn, 0, 350); 
    gtk_widget_set_size_request(lemonade_btn, 200, 200);

    lemonade_info = gtk_button_new_with_label("Lemonade: \nSmall: $1.00 \nMedium: $1.25 \nLarge: $1.50");
    gtk_fixed_put(GTK_FIXED(fixed), lemonade_info, 200, 350); 
    gtk_widget_set_size_request(lemonade_info, 200, 200);

    // Milkshake Image/ Button
    milkshake_btn = gtk_button_new();
    gtk_widget_set_name(milkshake_btn, "milkshake_btn");
    gtk_fixed_put(GTK_FIXED(fixed), milkshake_btn, 700, 100); 
    gtk_widget_set_size_request(milkshake_btn, 200, 200);

    milkshake_info = gtk_button_new_with_label("Milkshake: "
                     "\nFlavors: Strawberry, Vanilla, Chocolate"
                     "\nSmall: $2.50 \nMedium: $2.75 \nLarge: $3.00");
    gtk_fixed_put(GTK_FIXED(fixed), milkshake_info, 900, 100); 
    gtk_widget_set_size_request(milkshake_info, 200, 200);

    // Blue Bistro Image/ Button
    bluedrink_btn = gtk_button_new();
    gtk_widget_set_name(bluedrink_btn, "bluedrink_btn");
    gtk_fixed_put(GTK_FIXED(fixed), bluedrink_btn, 700, 350); 
    gtk_widget_set_size_request(bluedrink_btn, 200, 200);

    bluedrink_info = gtk_button_new_with_label("Blue Bistro: "
                    "\nSmall: $4.00 \nMedium: $4.25 \nLarge: $4.50");
    gtk_fixed_put(GTK_FIXED(fixed), bluedrink_info, 900, 350); 
    gtk_widget_set_size_request(bluedrink_info, 200, 200);

    // Pay Online Button
    pay = gtk_button_new_with_label("Pay Online");
    gtk_fixed_put(GTK_FIXED(fixed), pay, 150, 25); 
    gtk_widget_set_size_request(pay, 100, 50); 

    g_signal_connect(G_OBJECT(window), "destroy", 
        G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}