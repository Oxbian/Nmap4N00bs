#include "window.h"

/**
 * @brief Main function of the window where it inits the gtk window
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    //Gtk Window init
    gtk_init(&argc, &argv);
    GtkBuilder *builder = gtk_builder_new_from_file("assets/glade/ui.glade");
    GtkWidget *window = GTK_WIDGET (gtk_builder_get_object(builder, "window"));
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_builder_connect_signals(builder, NULL);

    //Widget referencement
    ScanWin scanWin;
    scanWin.listScanBtn = GTK_WIDGET (gtk_builder_get_object (builder, "listScanBtn"));
    scanWin.pingScanBtn = GTK_WIDGET (gtk_builder_get_object(builder, "pingScanBtn"));
    scanWin.noPingScanBtn = GTK_WIDGET (gtk_builder_get_object(builder, "noPingScanBtn"));
    scanWin.noScanBtn = GTK_WIDGET (gtk_builder_get_object(builder, "noScanBtn"));
    
    scanWin.synScanBtn = GTK_WIDGET (gtk_builder_get_object(builder, "synScanBtn"));
    scanWin.connectScanBtn = GTK_WIDGET (gtk_builder_get_object(builder, "connectScanBtn"));
    scanWin.ackScanBtn = GTK_WIDGET(gtk_builder_get_object(builder, "ackScanBtn"));
    scanWin.windowScanBtn = GTK_WIDGET(gtk_builder_get_object(builder, "windowScanBtn"));
    scanWin.maimonScanBtn = GTK_WIDGET(gtk_builder_get_object(builder, "maimonScanBtn"));
    scanWin.nullScanBtn = GTK_WIDGET(gtk_builder_get_object(builder, "nullScanBtn"));
    scanWin.finScanBtn = GTK_WIDGET (gtk_builder_get_object(builder, "finScanBtn"));
    scanWin.xmasScanBtn = GTK_WIDGET (gtk_builder_get_object(builder, "xmasScanBtn"));
    scanWin.udpScanBtn = GTK_WIDGET (gtk_builder_get_object(builder, "updScanBtn"));
    scanWin.ipScanBtn = GTK_WIDGET (gtk_builder_get_object(builder, "ipScanBtn"));

    scanWin.versionScanBtn = GTK_WIDGET(gtk_builder_get_object(builder, "versionScanBtn"));
    scanWin.scriptScanBtn = GTK_WIDGET (gtk_builder_get_object(builder, "scriptScanBtn"));
    scanWin.osScanBtn = GTK_WIDGET(gtk_builder_get_object(builder, "osScanBtn"));
    scanWin.verbosityBtn = GTK_WIDGET (gtk_builder_get_object(builder, "verbosityBtn"));
    scanWin.ipv6ScanBtn = GTK_WIDGET (gtk_builder_get_object(builder, "ipv6ScanBtn"));
    scanWin.allScanBtn = GTK_WIDGET (gtk_builder_get_object(builder, "allScanBtn"));

    scanWin.targetIPEntry = GTK_WIDGET (gtk_builder_get_object(builder, "targetIPEntry"));
    scanWin.commandEntry = GTK_WIDGET (gtk_builder_get_object(builder, "commandEntry"));
    scanWin.reportLabel = GTK_WIDGET(gtk_builder_get_object(builder, "reportLabel"));

    //Final button referencement and signals connect
    GtkWidget *scanButton = GTK_WIDGET (gtk_builder_get_object(builder, "scanButton"));
    g_signal_connect(scanButton, "clicked", G_CALLBACK(nmapScan), &scanWin);

    //Showing all the widget and leaving
    gtk_widget_show_all(window);
    gtk_main();
    exit(EXIT_SUCCESS);
}

/**
 * @brief Function to use the nmapScan with the parameters the user has choosen
 * 
 * @param btn 
 * @param user_data 
 */
void nmapScan(GtkButton* btn, gpointer user_data)
{
    ScanWin* data = (ScanWin*) user_data;
    FILE* fp;

    if (gtk_entry_get_text_length(GTK_ENTRY(data->commandEntry)) > 2) {
        //If the user want to use a custom command, we launch it
        data->command = malloc(sizeof(char) * gtk_entry_get_text_length(GTK_ENTRY(data->commandEntry)));
        strncpy(data->command, gtk_entry_get_text(GTK_ENTRY(data->commandEntry)), gtk_entry_get_text_length(GTK_ENTRY(data->commandEntry)));
        fprintf(stderr, "Commande à executer est: %s", data->command);
        fp = popen(data->command, "r");
        if (fp == NULL) {
            gtk_label_set_text(GTK_LABEL(data->reportLabel), "Error, check the syntax of your command. Don't forget to add -oN output.txt to your command for the output");
        }
        free(data->command);
    } else {
        //Else check each scan if they are checked or not, and make the final command as an mix of it
        data->command = malloc(sizeof(char) * 75);
        strncpy(data->command, "nmap", 5);

        /*Host discovery options*/
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->listScanBtn)))
            strcat(data->command, " -sL");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->pingScanBtn)))
            strcat(data->command, " -sP");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->noPingScanBtn)))
            strcat(data->command, " -P0");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->noScanBtn)))
            strcat(data->command, " -PN");

        /*Scan options*/
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->synScanBtn)))
            strcat(data->command, " -sS");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->connectScanBtn)))
            strcat(data->command, " -sT");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->ackScanBtn)))
            strcat(data->command, " -sA");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->windowScanBtn)))
            strcat(data->command, " -sW");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->maimonScanBtn)))
            strcat(data->command, " -sM");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->nullScanBtn)))
            strcat(data->command, " -sN");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->finScanBtn)))
            strcat(data->command, " -sF");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->xmasScanBtn)))
            strcat(data->command, " -sX");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->udpScanBtn)))
            strcat(data->command, " -sU");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->ipScanBtn)))
            strcat(data->command, " -sO");

        /*Others options*/
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->versionScanBtn)))
            strcat(data->command, " -sV");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->scriptScanBtn)))
            strcat(data->command, " -sC");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->osScanBtn)))
            strcat(data->command, " -O");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->verbosityBtn)))
            strcat(data->command, " -v");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->ipv6ScanBtn)))
            strcat(data->command, " -6");
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->allScanBtn)))
            strcat(data->command, " -A"); 

        char* ip = malloc(sizeof(char) * gtk_entry_get_text_length(GTK_ENTRY(data->targetIPEntry)));
        strncpy(ip, gtk_entry_get_text(GTK_ENTRY(data->targetIPEntry)), gtk_entry_get_text_length(GTK_ENTRY(data->targetIPEntry)));
        if (ip != NULL && isValidIp(ip)) {
            strcat(data->command, " ");
            strcat(data->command, ip);
            strcat(data->command, " -oN output.txt");
            fprintf(stderr, "Commande à executer est: %s", data->command);
            fp = popen(data->command, "r");
            if (fp == NULL) {
                gtk_label_set_text(GTK_LABEL(data->reportLabel), "Error, check all the parameters all well input!");
            }
        } else {
            gtk_label_set_text(GTK_LABEL(data->reportLabel), "Error, some parameters aren't correct or the IP isn't correct!");
        }
        free(ip);
        free(data->command);

    }
    pclose(fp);
}

/**
 * @brief Function to check if an IP address is valid or not
 * 
 * @param ip 
 * @return int 
 */
int isValidIp(const char* ip)
{
    char* pattern ="^([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))."
         "([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))."
         "([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))."
         "([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))$"; //A lenghful regex for IP address
    regex_t re;
    if (regcomp(&re, pattern, REG_EXTENDED) != 0) return 0;
    int status = regexec(&re, ip, 0, NULL, 0);
    regfree(&re);
    if (status != 0) return 0;
    return 1;
}