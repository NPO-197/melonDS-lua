#include <QWidget>
#include <QPlainTextEdit>
#include <QDialog>
#include <QtCore>
#include <QPushButton>
#include "LuaScript.h"
#include "LuaFrontEnd.h"
class LuaConsol : public QPlainTextEdit {
    Q_OBJECT
public:
    LuaConsol(QWidget* parent=nullptr);
public slots:
    void onGetText(QString text);
    void onClearConsole();
};

class LuaConsolDialog : public QDialog{
    Q_OBJECT
public:
    LuaConsolDialog(QWidget* parent=nullptr,QFileInfo* file=nullptr);
    LuaConsol* consol;
    QFileInfo file;
    QPushButton* pauseButton;
    QPushButton* resetButton;
signals:
    void signalLuaStart();
public slots:
    void onReset();
};

