#include <gtk/gtk.h>

void base(int argc, char *argv[]);
void window(int argc, char *argv[]);
void hello(int argc, char *argv[]);
void box(int argc, char *argv[]);
void table(int argc, char *argv[]);

//void demo04(int argc, char *argv[]);
//void demo05(int argc, char *argv[]);

char* txt(char* str)
{
    return g_locale_to_utf8(str,-1,0,0,0);
}

int main(int argc, char *argv[])
{
	table(argc, argv);
	return FALSE;
}

void base(int argc, char *argv[])
{
	GtkWidget *window;
	gtk_init(&argc, &argv);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_show(window);
	gtk_main();
}

void window(int argc, char *argv[])
{
	GtkWidget *window;
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_set_title(GTK_WINDOW(window), txt("一个功能完善的窗口"));
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 100);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_show(window);
	//g_signal_connect_swapped(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
}

gint count=1;
void on_button_clicked(GtkWidget *button, gpointer userdata){
    g_print(txt("你好!这是Hello功能的测试."));
    //g_print("Hello. This is a test.");
    g_print("%d\n", (gint)userdata);
    //g_print("%d\n", count);
    count=count+1;
}
void hello(int argc, char *argv[])
{
	GtkWidget *window;
    GtkWidget *button;
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_set_title(GTK_WINDOW(window), txt("Hello 功能实现"));
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 100);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	//gtk_container_set_border_width(GTK_CONTAINER(window), 40);

    button=gtk_button_new_with_label(txt("按下此按钮会在终端上显示一行信息"));
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(on_button_clicked), (gpointer)count);
    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_widget_show(button);
    gtk_widget_show(window);
	gtk_main();
}

void box(int argc, char* argv[])
{
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *button;
    gchar *title=txt("排列按钮");
    gtk_init(&argc, &argv);
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_set_title(GTK_WINDOW(window), title);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    
	box=gtk_hbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(window), box);
	
	button=gtk_button_new_with_label(txt("按钮一"));
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 3);
    
	button=gtk_button_new_with_label(txt("按"));
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 3);
    
	button=gtk_button_new_with_label(txt("钮"));
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 3);
    
	button=gtk_button_new_with_label(txt("二"));
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 3);
    
	gtk_widget_show_all(window);
    gtk_main();
}

void table(int argc, char* argv[])
{
    GtkWidget* window;
    GtkWidget* table;
    GtkWidget* button;
    GtkWidget* frame;

    gtk_init(&argc, &argv);
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), txt("格状容器"));
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 300);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);

    frame=gtk_frame_new(txt("请注意下列按钮的排列"));
    gtk_container_add(GTK_CONTAINER(window),frame);

    table=gtk_table_new(4,4,TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(table),10);
    gtk_table_set_row_spacings(GTK_TABLE(table), 5);
    gtk_table_set_col_spacings(GTK_TABLE(table), 5);
    gtk_container_add(GTK_CONTAINER(frame), table);

    button=gtk_button_new_with_label("0,1,0,1");
    gtk_table_attach(GTK_TABLE(table),button,0,1,0,1,GTK_FILL,GTK_FILL,0,0);
    //0,0-1,1
    button=gtk_button_new_with_label("1,3,1,3");
    gtk_table_attach(GTK_TABLE(table),button,1,3,1,3,GTK_FILL,GTK_FILL,0,0);
    //1,1-3,3
    button=gtk_button_new_with_label("0,1,1,3");
    gtk_table_attach_defaults(GTK_TABLE(table),button,0,1,1,3);
    //0,1-1,3
    button=gtk_button_new_with_label("1,3,0,1");
    gtk_table_attach_defaults(GTK_TABLE(table),button,1,3,0,1);
    //1,0-3,1
    button=gtk_button_new_with_label("0,4,3,4");
    gtk_table_attach_defaults(GTK_TABLE(table),button,0,4,3,4);
    //0,3-4,4
    button=gtk_button_new_with_label("3,4,0,3");
    gtk_table_attach_defaults(GTK_TABLE(table),button,3,4,0,3);
    //3,0-4,3
    gtk_widget_show_all(window);
    gtk_main();
}

/*
GdkPixbuf *create_pixbuf(const gchar * filename){
	GdkPixbuf *pixbuf;
	GError *error = NULL;
	pixbuf = gdk_pixbuf_new_from_file(filename, &error);
	if(!pixbuf){
		fprintf(stderr, "%s\n", error->message);
		g_error_free(error);
	}
	return pixbuf;
}

void demo04(int argc, char *argv[])
{
	GtkWidget *window;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "icon");
	gtk_window_set_default_size(GTK_WINDOW(window), 230, 150);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("call_servlet_16.png"));
	gtk_widget_show(window);

	g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	gtk_main();
}

//gint count=0;
char buf[5];
void increase(GtkWidget *widget, gpointer label){
    count++;
    sprintf(buf, "%d", count);
    gtk_label_set_text(label, buf);
}

void decrease(GtkWidget *widget, gpointer label){
    count--;
    sprintf(buf, "%d", count);
    gtk_label_set_text(label, buf);
}

void demo05(int argc, char** argv){
    GtkWidget *label;
    GtkWidget *window;
    GtkWidget *frame;
    GtkWidget *plus;
    GtkWidget *minus;

    gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 250, 180);
	gtk_window_set_title(GTK_WINDOW(window), "+-");

    frame=gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), frame);

    plus=gtk_button_new_with_label("+");
	gtk_widget_set_size_request(plus, 80, 35);
    gtk_fixed_put(GTK_FIXED(frame), plus, 50, 20);

    minus=gtk_button_new_with_label("-");
	gtk_widget_set_size_request(minus, 80, 35);
    gtk_fixed_put(GTK_FIXED(frame), minus, 50, 80);

    label=gtk_label_new("0");
    gtk_fixed_put(GTK_FIXED(frame), label, 190, 58);
    gtk_widget_show_all(window);

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(plus, "clicked", G_CALLBACK(increase), label);
	g_signal_connect(minus, "clicked", G_CALLBACK(decrease), label);

    gtk_main();
}
*/
