#include "qteditor.h"
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMainWindow>
#include <QApplication>

QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    //1
    /*
    QTextEdit *tE = new QTextEdit(this);
    setCentralWidget(tE); */

    //2
    QMenuBar *menubar = new QMenuBar(this);
    setMenuBar(menubar);

    //3
    QAction *newAct = new QAction(QIcon("new.png"), "&New", this);
    newAct->setShortcut(tr("Ctrl+N"));
    newAct->setStatusTip(tr("make new file"));
    connect(newAct, SIGNAL(triggered()), SLOT(newFile()));

    QMenu *fileMenu = menubar->addMenu("&File");
    fileMenu->addAction(newAct);
}

/*
//4
void QtEditor::newFile()
{
    qDebug("Make New File");
}

QtEditor::~QtEditor() {}
*/
