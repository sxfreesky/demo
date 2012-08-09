#include <gtk/gtk.h>

void menu(int argc, char* argv[]);

char* txt(char* c)
{
    return g_locale_to_utf8(c,-1,0,0,0);
}

int main(int argc, char* argv[])
{
    menu(argc, argv);
    return FALSE;
}

void on_menu_activate(GtkMenuItem* item, gpointer data)
{
    //g_print("�˵��� %s ������\n", (gchar*)data);
    g_print("MenuItem %s is pressed.\n", (gchar*)data);
}

void menu(int argc, char* argv[])
{
    GtkWidget* window;
    GtkWidget* box;
    GtkWidget* menubar;
    GtkWidget* menu;
    GtkWidget* editmenu;
    GtkWidget* helpmenu;
    GtkWidget* rootmenu;
    GtkWidget* menuitem;
    GtkAccelGroup* accel_group;
    gtk_init(&argc, &argv);
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), txt("�˵����Գ���"));
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    accel_group=gtk_accel_group_new();
    gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

    box=gtk_vbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(window), box);

    menu=gtk_menu_new();    //�ļ��˵�

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("�½�")));

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("��")));

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE, accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("����")));

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE_AS, accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("���Ϊ")));

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("�˳�")));

    rootmenu=gtk_menu_item_new_with_label(txt("�ļ�"));
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu), menu);

    menubar=gtk_menu_bar_new();
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), rootmenu);

    //menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, accel_group);
    //gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menuitem);

    rootmenu=gtk_menu_item_new_with_label(txt("�༭"));
    editmenu=gtk_menu_new();//�༭�˵�

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_CUT,accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("����")));

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_COPY,accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("����")));

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_PASTE,accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("ճ��")));

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_FIND,accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("����")));

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu), editmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), rootmenu);

    rootmenu=gtk_menu_item_new_with_label(txt("����"));
    helpmenu=gtk_menu_new();//�����˵�

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_HELP,accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("����")));

    menuitem=gtk_menu_item_new_with_label(txt("����..."));
    gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("����")));

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu), helpmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), rootmenu);
    gtk_box_pack_start(GTK_BOX(box), menubar, FALSE, FALSE, 0);
    gtk_widget_show_all(window);
    gtk_main();
}
