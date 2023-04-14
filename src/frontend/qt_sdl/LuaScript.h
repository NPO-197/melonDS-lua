#ifndef LUASCRIPT_H
#define LUASCRIPT_H
#include <vector>
#include <string.h>
#include "lua-5.4.4/src/lua.hpp"
#include <QFileInfo>
#include <QtCore>

class LuaThread : public QThread
{
    Q_OBJECT
    void run() override;
public:
    explicit LuaThread(QFileInfo fileinfo,QObject* parent = nullptr){scriptFile=fileinfo;}
    void luaUpdate();
    void luaStop();
    void luaYeild();
    void luaTogglePause();
    void luaLayoutChange();
    int luaDialogFunction(lua_State*,int (*)(lua_State*));
    void luaDialogReturned();
    int luaDialogStart(lua_State*,int);
    void luaDialogClosed();
    void luaPrint(QString string);
    bool flagTerminated = false;
    void luaStateSave(QString filename);
    void luaStateLoad(QString filename);
signals:
    void signalStarted();
    void signalChangeScreenLayout();
    void signalDialogFunction();
    void signalStartDialog();
    void signalPrint(QString string);
    void signalStateSave(QString filename);
    void signalStateLoad(QString filename);
private:
    QFileInfo scriptFile;
    bool flagRunning;
    bool flagUpdate;
    bool flagDialogReturn;
    bool flagDialogClosed;
    bool flagPaused=false;
};

extern LuaThread* luaThread;

namespace LuaScript
{
extern lua_State* MainLuaState;
typedef int(*lfunctpntr)(lua_State*);
struct LuaFunction
{
    lfunctpntr funct;
    const char* name;
    LuaFunction(lfunctpntr,const char*,std::vector<LuaFunction*>*);
};
void StartLuaScript(QFileInfo);
void TriggerLuaScript();
}

#endif