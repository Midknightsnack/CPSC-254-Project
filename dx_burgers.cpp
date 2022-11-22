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
    GtkWidget *wbacon_btn, *wbacon_info, *wagyu_btn, *wagyu_info,
              *bistro_btn, *bistro_info, *gold_btn, *gold_info;

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

    // Western Bacon Image/ Button
    wbacon_btn = gtk_button_new();
    gtk_widget_set_name(wbacon_btn, "wbacon_btn");

    gtk_fixed_put(GTK_FIXED(fixed), wbacon_btn, 0, 100); 
    gtk_widget_set_size_request(wbacon_btn, 200, 200);

    wbacon_info = gtk_button_new_with_label("Western Bacon Cheeseburger (w/ side of choice): "
                            "\nbrioche buns, beef, onion rings, cheese, bacon, BBQ sauce "
                            "\nPrice: $10.00");
    gtk_fixed_put(GTK_FIXED(fixed), wbacon_info, 200, 100); 
    gtk_widget_set_size_request(wbacon_info, 200, 200);

    // Wagyu Image/ Button
    wagyu_btn = gtk_button_new();
    gtk_widget_set_name(wagyu_btn, "wagyu_btn");
    gtk_fixed_put(GTK_FIXED(fixed), wagyu_btn, 0, 350); 
    gtk_widget_set_size_request(wagyu_btn, 200, 200);

    wagyu_info = gtk_button_new_with_label("Wagyu Burger (w/ side of choice): "
                            "\nbrioche buns, wagyu beef, cheese, pickles, " 
                            "\nketchup, cheese sauce, bistro sauce \nPrice: $30.00");
    gtk_fixed_put(GTK_FIXED(fixed), wagyu_info, 200, 350); 
    gtk_widget_set_size_request(wagyu_info, 200, 200);

    // Bistro Burger Image/ Button
    bistro_btn = gtk_button_new();
    gtk_widget_set_name(bistro_btn, "bistro_btn");
    gtk_fixed_put(GTK_FIXED(fixed), bistro_btn, 700, 100); 
    gtk_widget_set_size_request(bistro_btn, 200, 200);

    bistro_info = gtk_button_new_with_label("Bistro Burger (w/ side of choice): "
                            "\nsesame buns, beef, lettuce, tomato, "
                            "\nonion rings, cheese, bistro sauce, BBQ sauce \nPrice: $20.00");
    gtk_fixed_put(GTK_FIXED(fixed), bistro_info, 900, 100); 
    gtk_widget_set_size_request(bistro_info, 200, 200);

    // Gold Burger Image/ Button
    gold_btn = gtk_button_new();
    gtk_widget_set_name(gold_btn, "gold_btn");
    gtk_fixed_put(GTK_FIXED(fixed), gold_btn, 700, 350); 
    gtk_widget_set_size_request(gold_btn, 200, 200);

    gold_info = gtk_button_new_with_label("Gold Burger (w/ side of choice): \ngold sesame buns,"
                            " wagyu beef, cheese, tomato, lettuce, bistro sauce" 
                            " \nPrice: $1500.00");
    gtk_fixed_put(GTK_FIXED(fixed), gold_info, 900, 350); 
    gtk_widget_set_size_request(gold_info, 200, 200);

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