#include "LuaConsol.h"
#include <QScrollBar>

LuaConsolDialog::LuaConsolDialog(QWidget* parent, QFileInfo* file)
{
    this->setParent(parent);
    this->file = *file;
    this->consol = new LuaConsol(this);
    this->consol->setGeometry(0,20,200,80);
    this->pauseButton = new QPushButton("Pause/UnPause",this);
    this->pauseButton->setGeometry(0,0,100,20);
    this->resetButton = new QPushButton("Start/Reset",this);
    this->resetButton->setGeometry(110,0,100,20);
    connect(pauseButton,&QPushButton::clicked,luaThread,LuaThread::luaTogglePause);
    connect(resetButton,&QPushButton::clicked,this,LuaConsolDialog::onReset);
    onReset();
}


void LuaConsolDialog::onReset(){
    printf("reseting...");
    if (luaThread!=nullptr){
        luaThread->flagTerminated=true;
        luaThread->terminate();//might cause issues!
        luaThread->wait();
        LuaFront::LuaOverlays.clear();
    }
    luaThread = new LuaThread(file);
    connect(luaThread,LuaThread::signalPrint,consol,LuaConsol::onGetText);
    emit signalLuaStart();
}

LuaConsol::LuaConsol(QWidget* parent)
{
    this->setParent(parent);
}

void LuaConsol::onGetText(QString string)
{
    this->insertPlainText(string);
    QScrollBar* bar = verticalScrollBar();
    bar->setValue(bar->maximum());
}

void LuaConsol::onClearConsole()
{
    this->clear();
}