#include <gtk/gtk.h>

void base(int argc, char *argv[]);
void window(int argc, char *argv[]);
void hello(int argc, char *argv[]);
void box(int argc, char *argv[]);
void table(int argc, char *argv[]);
void button(int argc, char *argv[]);
void myLabel(int argc, char *argv[]);
void splash(int argc, char*argv[]);

char* txt(char* str)
{
    return g_locale_to_utf8(str,-1,0,0,0);
}

int main(int argc, char *argv[])
{
	splash(argc, argv);
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
	gtk_window_set_title(GTK_WINDOW(window), txt("һ���������ƵĴ���"));
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 100);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_widget_show(window);
	//g_signal_connect_swapped(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
}

gint count=1;
void on_button_clicked(GtkWidget *button, gpointer userdata){
    g_print(txt("���!����Hello���ܵĲ���."));
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
	gtk_window_set_title(GTK_WINDOW(window), txt("Hello ����ʵ��"));
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 100);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	//gtk_container_set_border_width(GTK_CONTAINER(window), 40);

    button=gtk_button_new_with_label(txt("���´˰�ť�����ն�����ʾһ����Ϣ"));
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
    gchar *title=txt("���а�ť");
    gtk_init(&argc, &argv);
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_set_title(GTK_WINDOW(window), title);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    
	box=gtk_hbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(window), box);
	
	button=gtk_button_new_with_label(txt("��ťһ"));
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 3);
    
	button=gtk_button_new_with_label(txt("��"));
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 3);
    
	button=gtk_button_new_with_label(txt("ť"));
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 3);
    
	button=gtk_button_new_with_label(txt("��"));
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
    gtk_window_set_title(GTK_WINDOW(window), txt("��״����"));
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 300);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);

    frame=gtk_frame_new(txt("��ע�����а�ť������"));
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

void on_button_pressed(GtkWidget* button, gpointer data)
{
    //g_print("��ť %s", (gchar*)data);
    g_print("Button %s is pressed.\n", (gchar*)data);
    //g_print("������һ��.\n");
}

GtkWidget* create_button1(void)
{
    GtkWidget* box;
    GtkWidget* image;
    GtkWidget* label;
    GtkWidget* button;
    char* title=txt("��ƻ��");
    image=gtk_image_new_from_file("apple-red.png");
    label=gtk_label_new(title);
    box=gtk_vbox_new(FALSE, 2);
    gtk_container_set_border_width(GTK_CONTAINER(box), 5);
    gtk_box_pack_start(GTK_BOX(box), image, FALSE, FALSE, 3);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 3);
    gtk_widget_show(image);
    gtk_widget_show(label);
    button=gtk_button_new();
    gtk_container_add(GTK_CONTAINER(button), box);
    gtk_widget_show(box);
    return button;
}

GtkWidget* create_button2(void)
{
    GtkWidget* box;
    GtkWidget* image;
    GtkWidget* label;
    GtkWidget* button;
    char* title=txt("СĢ��");
    image=gtk_image_new_from_file("gnome-gmush.png");
    label=gtk_label_new(title);
    box=gtk_hbox_new(FALSE, 2);
    gtk_container_set_border_width(GTK_CONTAINER(box), 5);
    gtk_box_pack_start(GTK_BOX(box), image, FALSE, FALSE, 3);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 3);
    gtk_widget_show(image);
    gtk_widget_show(label);
    button=gtk_button_new();
    gtk_container_add(GTK_CONTAINER(button), box);
    gtk_widget_show(box);
    return button;
}

void button(int argc, char* argv[])
{
    GtkWidget* window;
    GtkWidget* box;
    GtkWidget* button1;
    GtkWidget* button2;
    GtkWidget* button3;
    GtkWidget* button4;

    gchar* title=txt("��ͼ��Ϳ�ݼ��İ�ť");
    gchar* b1="Red apple";  //"��ƻ��"
    gchar* b2="Small mushroom"; //"СĢ��"
    gchar* b3="Short key";//"��ݼ�"
    gchar* b4="OK"; //"ȷ��"
    gtk_init(&argc, &argv);
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), title);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    box=gtk_hbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), box);
    button1=create_button1();
    g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(on_button_pressed), (gpointer)b1);
    gtk_box_pack_start(GTK_BOX(box), button1, FALSE, FALSE, 5);

    button2=create_button2();
    g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(on_button_pressed), (gpointer)b2);
    gtk_box_pack_start(GTK_BOX(box), button2, FALSE, FALSE, 5);

    button3=gtk_button_new_with_mnemonic(txt("��ݼ�(_H)"));
    g_signal_connect(G_OBJECT(button3), "clicked", G_CALLBACK(on_button_pressed), (gpointer)b3);
    gtk_box_pack_start(GTK_BOX(box), button3, FALSE, FALSE, 5);

    button4=gtk_button_new_from_stock(GTK_STOCK_OK);
    g_signal_connect(G_OBJECT(button4), "clicked", G_CALLBACK(on_button_pressed), (gpointer)b4);
    gtk_box_pack_start(GTK_BOX(box), button4, FALSE, FALSE, 5);

    gtk_widget_show_all(window);
    gtk_main();
}

void myLabel(int argc, char* argv[])
{
    GtkWidget* window;
    GtkWidget* box;
    GtkWidget* label1;
    GtkWidget* label2;
    GtkWidget* label3;
    GtkWidget* label4;
    GtkWidget* frame1;
    GtkWidget* frame2;
    GtkWidget* frame3;
    GtkWidget* frame4;
    gchar* title;
    gtk_init(&argc, &argv);
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), txt("������ʽ�ı�ǩ"));
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window),20);

    box=gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window),box);

    frame1=gtk_frame_new(txt("��ǩһ"));
    label1=gtk_label_new(txt("���ǵ�һ����ǩ,�����.This is first label."));
    gtk_container_add(GTK_CONTAINER(frame1), label1);
    gtk_label_set_justify(GTK_LABEL(label1), GTK_JUSTIFY_LEFT);
    gtk_box_pack_start(GTK_BOX(box), frame1, FALSE, FALSE, 5);

    frame2=gtk_frame_new(txt("��ǩ��"));
    label2=gtk_label_new(txt("���ǵڶ�����ǩ,���Ƕ��е�\n�⻹�ǵڶ�����ǩ������.���Ǿ��ҵ�."));
    gtk_container_add(GTK_CONTAINER(frame2), label2);
    gtk_label_set_justify(GTK_LABEL(label2), GTK_JUSTIFY_RIGHT);
    gtk_box_pack_start(GTK_BOX(box), frame2, FALSE, FALSE, 5);

    frame3=gtk_frame_new(txt("��ǩ��"));
    label3=gtk_label_new(NULL);
    title=txt("<span foreground=\"red\"><big><i>���ǵ�������ǩ,\n������ʽ���ɺ�ɫ����,��������Ҳ����.</i></big></span>");
    gtk_label_set_markup(GTK_LABEL(label3), title);
    gtk_container_add(GTK_CONTAINER(frame3), label3);
    gtk_box_pack_start(GTK_BOX(box), frame3, FALSE, FALSE, 5);

    frame4=gtk_frame_new(txt("��ǩ��"));
    label4=gtk_label_new(txt("��Ҳ��һ�����б�ǩ,���Ļ��з�ʽ����һ��������ͬ,��Ҫ�Ǳ���ֶβ�һ����,����ϸ�鿴һ��Դ�����������ô�����ˡ�"));
    gtk_container_add(GTK_CONTAINER(frame4), label4);
    gtk_label_set_line_wrap(GTK_LABEL(label4), TRUE);
    gtk_box_pack_start(GTK_BOX(box),frame4,FALSE,FALSE,0);
    gtk_widget_show_all(window);
    gtk_main();
}

void splash(int argc, char*argv[])
{
    GtkWidget* window;
    GtkWidget* vbox;
    GtkWidget* image;
    GtkWidget* button;
    gtk_init(&argc, &argv);
    window=gtk_window_new(GTK_WINDOW_POPUP);
    gtk_window_set_title(GTK_WINDOW(window), txt("Splash����"));
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    //gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    //gtk_window_set_default_size(GTK_WINDOW(window), 500, 400);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    vbox=gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    image=gtk_image_new_from_file("gnome-gimp.png");
    gtk_box_pack_start(GTK_BOX(vbox), image, FALSE, FALSE, 0);
    button=gtk_button_new_with_label(txt("Splash����"));
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(gtk_main_quit), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
    gtk_widget_show_all(window);
    gtk_main();
}
