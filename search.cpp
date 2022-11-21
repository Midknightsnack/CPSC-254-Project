#include <gtk/gtk.h>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

static void button_clicked(GtkWidget *widget, gpointer data){
    g_print("%s\n", gtk_entry_get_text(GTK_ENTRY(data)));
    gtk_editable_select_region(GTK_EDITABLE(data), 0,-1); // text from 0 to the end
    gtk_editable_copy_clipboard(GTK_EDITABLE(data));
}

static void button_click(GtkWidget* widget, gpointer data);


int main(int argc, char* argv[]){
    gtk_init(&argc, &argv);
    GtkWidget *window, *entry, *button, *vbox, *results, *search;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    entry = gtk_entry_new();
    button = gtk_button_new_with_label("Write Text"); // also writes input to terminal
    results = gtk_label_new("Hello World"); // changes to hey
    search = gtk_button_new_with_label("Click me to search"); //changes "results" when clicked
    //g_signal_connect(search, "clicked", G_CALLBACK(button_click), NULL);
    g_signal_connect(search, "clicked", G_CALLBACK(button_click), (gpointer)results);
    //g_signal_connect(search, "clicked", G_CALLBACK(button_click), entry);
    //g_signal_connect(entry, "activate", G_CALLBACK(button_click), entry); // press enter to call funtion

    g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), entry);
    g_signal_connect(entry, "activate", G_CALLBACK(button_clicked), entry); // press enter to call funtion

    vbox = gtk_vbox_new(TRUE,1);
    gtk_box_pack_start(GTK_BOX(vbox), entry, TRUE,TRUE,0);
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE,TRUE,0);
    gtk_box_pack_start(GTK_BOX(vbox), search, TRUE,TRUE,0);
    gtk_box_pack_start(GTK_BOX(vbox), results, TRUE,TRUE,0);

    gtk_container_add(GTK_CONTAINER(window), vbox);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}


static void button_click(GtkWidget* widget, gpointer data){
    // const char* hello = (char *)gtk_entry_get_text(GTK_ENTRY(data));
    // char buffer[128];
    // snprintf(buffer, sizeof(buffer), "Results: %s", hello);
    // g_print("%s\n", gtk_entry_get_text(GTK_ENTRY(data)));
    // string hello = gtk_entry_get_text(GTK_ENTRY(data));
    // const char* new_hello = hello.c_str();
    const char *hello;
    //hello = gtk_entry_get_text(data);
    hello = "whaddup";
    gtk_label_set_text(GTK_LABEL(data), hello);
}