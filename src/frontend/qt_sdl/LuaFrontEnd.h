#ifndef LUAFRONTEND_H
#define LUAFRONTEND_H
#include "LuaScript.h"
#include <QPainter>
#include <QKeyEvent>
#include <QWidget>
#include <QPlainTextEdit>
#include <QScrollBar>
namespace LuaFront{


typedef int(*lfunctpntr)(lua_State*);
extern QWidget* panel;
extern int RightPadding;
extern int BottomPadding;
extern std::vector<LuaScript::LuaFunction*> FrontEndFunctions;
struct OverlayCanvas{
    QImage* image;
    QImage* display;
    QImage* buffer1;
    QImage* buffer2;
    QRect rectangle;
    bool isActive = true;//Only Active overlays are drawn to the screen.
    unsigned int GLtexture;
    OverlayCanvas(int,int,int,int,bool);
    void flip();
};
extern std::vector<OverlayCanvas> LuaOverlays;
extern void onMousePress(QMouseEvent* event);
extern void onMouseRelease(QMouseEvent* event);
extern void onMouseMove(QMouseEvent* event);

//extern OverlayCanvas MainLuaOverlay;
}
#endif