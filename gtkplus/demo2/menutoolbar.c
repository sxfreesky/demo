#include <gtk/gtk.h>

void menu(int argc, char* argv[]);
void itemfact(int argc, char* argv[]);

char* txt(char* c)
{
    return g_locale_to_utf8(c,-1,0,0,0);
}

int main(int argc, char* argv[])
{
    itemfact(argc, argv);
    return FALSE;
}

void on_menu_activate(GtkMenuItem* item, gpointer data)
{
    //g_print("菜单项 %s 被激活\n", (gchar*)data);
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
    gtk_window_set_title(GTK_WINDOW(window), txt("菜单测试程序"));
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    accel_group=gtk_accel_group_new();
    gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

    box=gtk_vbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(window), box);

    menu=gtk_menu_new();    //文件菜单

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("新建")));

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("打开")));

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE, accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("保存")));

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE_AS, accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("另存为")));

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("退出")));

    rootmenu=gtk_menu_item_new_with_label(txt("文件"));
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu), menu);

    menubar=gtk_menu_bar_new();
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), rootmenu);

    //menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, accel_group);
    //gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menuitem);

    rootmenu=gtk_menu_item_new_with_label(txt("编辑"));
    editmenu=gtk_menu_new();//编辑菜单

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_CUT,accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("剪切")));

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_COPY,accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("复制")));

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_PASTE,accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("粘贴")));

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_FIND,accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("查找")));

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu), editmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), rootmenu);

    rootmenu=gtk_menu_item_new_with_label(txt("帮助"));
    helpmenu=gtk_menu_new();//帮助菜单

    menuitem=gtk_image_menu_item_new_from_stock(GTK_STOCK_HELP,accel_group);
    gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("帮助")));

    menuitem=gtk_menu_item_new_with_label(txt("关于..."));
    gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), menuitem);
    g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(on_menu_activate), (gpointer)(txt("关于")));

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu), helpmenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), rootmenu);
    gtk_box_pack_start(GTK_BOX(box), menubar, FALSE, FALSE, 0);
    gtk_widget_show_all(window);
    gtk_main();
}

static GtkItemFactoryEntry menu_items[]={   //定义菜单集
    {"/文件(_F)",NULL,NULL,0,"<Branch>"},
    {"/文件(_F) /新建",NULL,on_menu_activate,"新建","<StockItem>", GTK_STOCK_NEW},
    {"/文件(_F) /打开",NULL,on_menu_activate,"打开","<StockItem>", GTK_STOCK_OPEN},
    {"/文件(_F) /保存",NULL,on_menu_activate,"保存","<StockItem>", GTK_STOCK_SAVE},
    {"/文件(_F) /另存为",NULL,on_menu_activate,"另存为","<StockItem>", GTK_STOCK_SAVE_AS},
    {"/文件(_F) /-",NULL,on_menu_activate,NULL,"<Seprator>"},
    {"/文件(_F) /退出",NULL,on_menu_activate,"退出","<StockItem>", GTK_STOCK_QUIT},

    {"/编辑(_E)",NULL,NULL,0,"<Branch>"},
    {"/编辑(_E) /剪切",NULL,on_menu_activate,"剪切","<StockItem>", GTK_STOCK_CUT},
    {"/编辑(_E) /复制",NULL,on_menu_activate,"复制","<StockItem>", GTK_STOCK_COPY},
    {"/编辑(_E) /粘贴",NULL,on_menu_activate,"粘贴","<StockItem>", GTK_STOCK_PASTE},
    {"/编辑(_E) /查找",NULL,on_menu_activate,"查找","<StockItem>", GTK_STOCK_FIND},
    {"/帮助(_H)",NULL,NULL,0,"<LastBranch>"},
    {"/帮助(_H) /帮助",NULL,on_menu_activate,"帮助","<StockItem>", GTK_STOCK_HELP},
    {"/帮助(_H) /关于...",NULL,on_menu_activate,"关于",NULL}
};
void itemfact(int argc, char* argv[])
{
    GtkWidget* window;
    GtkWidget* box;
    GtkWidget* menubar;
    GtkAccelGroup* accel_group;
    GtkItemFactory* item_factory;
    gint n=15;

    gtk_init(&argc, &argv);
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), txt("添加菜单的快捷方法"));
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    accel_group=gtk_accel_group_new();
    box=gtk_vbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show(box);
    item_factory=gtk_item_factory_new(GTK_TYPE_MENU_BAR, "<main>", accel_group);
    gtk_item_factory_create_items(item_factory, n, menu_items, NULL);
    gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);
    menubar=gtk_item_factory_get_widget(item_factory, "<main>");
    gtk_box_pack_start(GTK_BOX(box), menubar, FALSE, FALSE, 0);
    gtk_widget_show(menubar);
    gtk_widget_show(window);
    gtk_main();
}
