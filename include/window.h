#ifndef DEF_WINDOW_H
#define DEF_WINDOW_H

#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <regex.h>

typedef struct _ScanWin ScanWin;
struct _ScanWin
{
    GtkWidget* listScanBtn;
    GtkWidget* pingScanBtn;
    GtkWidget* noPingScanBtn;
    GtkWidget* noScanBtn;

    GtkWidget* synScanBtn;
    GtkWidget* connectScanBtn;
    GtkWidget* ackScanBtn;
    GtkWidget* windowScanBtn;
    GtkWidget* maimonScanBtn;
    GtkWidget* nullScanBtn;
    GtkWidget* finScanBtn;
    GtkWidget* xmasScanBtn;
    GtkWidget* udpScanBtn;
    GtkWidget* ipScanBtn;

    GtkWidget* versionScanBtn;
    GtkWidget* scriptScanBtn;
    GtkWidget* osScanBtn;
    GtkWidget* verbosityBtn;
    GtkWidget* ipv6ScanBtn;
    GtkWidget* allScanBtn;

    GtkWidget* targetIPEntry;
    GtkWidget* commandEntry;
    GtkWidget* reportLabel;
    char* command;
};

void nmapScan(GtkButton* btn, gpointer user_data);
int isValidIp(const char* ip);
#endif