#include<stdio.h>
#include<gtk/gtk.h>

GtkWidget *window, *box, *grid;
GtkWidget *text[3][4];
GtkWidget *entry[3][4];
GtkWidget *button[3][4];

void change_text(GtkWidget *widget, gpointer *data){
    int pos = GPOINTER_TO_INT(*data);
    const gchar *txt = gtk_entry_get_text(GTK_ENTRY(entry[0][pos]));
    gtk_label_set_text(GTK_LABEL(text[0][pos]), txt);
    gtk_entry_set_text(GTK_ENTRY(entry[0][pos]), " ");
};

int main(int argc, char *argv[]){

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box); */

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    int num_stds = 3;
    int *ip[num_stds];
    int pos[num_stds];
    char alunos[3][25] = {"Student 1", "Student 2", "Student3"};

    for(int i=0; i<num_stds; i++){
        text[0][i] = gtk_label_new(alunos[i]);
        gtk_label_set_xalign(GTK_LABEL(text[0][i]), 0.1);
        gtk_label_set_line_wrap(GTK_LABEL(text[0][i]), TRUE);
        gtk_grid_attach(GTK_GRID(grid), text[0][i], 0, i, 1, 1);

        entry[0][i] = gtk_entry_new();
        gtk_grid_attach(GTK_GRID(grid), entry[0][i], 1, i, 1, 1);
        pos[i] = i;
        ip[i] = &pos[i];
        button[0][i] = gtk_button_new_with_label("Change");
        g_signal_connect(GTK_BUTTON(button[0][i]), "clicked", G_CALLBACK(change_text), ip[i]);
        gtk_grid_attach(GTK_GRID(grid), button[0][i], 2, i, 1, 1);
    };

/*     gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);
 */
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 420);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
