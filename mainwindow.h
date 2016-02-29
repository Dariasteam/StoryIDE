#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "texteditor.h"
#include "jugar.h"
#include "linketiqueta.h"
#include "historia.h"
#include "escena.h"
#include "panelcompilar.h"

#include <QScrollArea>
#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <fstream>
#include <QTabWidget>
#include <QGroupBox>
#include <QDockWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QIcon>
#include <QToolBar>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    TextEditor* textPanel;
    QMenuBar* barraMenu;
    QMenu* archivo;
    QAction* abrir;
    QAction* guardar;
    QAction* guardarComo;
    QAction* compilar;
    QAction* jugar;
    QFileDialog* dialogoArchivo;
    QString path;
    QTabWidget* modos;
    Jugar*      juego;
    PanelCompilar* compilerPanel;
    QDockWidget* dockLinks;
    QWidget* contenedorLinks;
    QScrollArea* scroll;
    QIcon iconAbrir;
    QIcon iconGuardar;
    QIcon iconGuardarComo;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addTag(LinkEtiqueta* tag);
private slots:
    void onGuardar();
    void onGuardarComo();
    void onAbrir();
    void onModificado();
    void onJugar();
    void onCompilar();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
