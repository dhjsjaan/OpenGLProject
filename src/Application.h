#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Head.h"
#include "GLWindow.h"
#include "mycamera.h"

class Application
{
public:
    Application(const std::string& app_name);

    static Application& Instance() {return *mInstance; }

    void mianLoop();
private:
    static Application* mInstance;
    std::unique_ptr<LK::GLWindow> mWindow;
};

#endif
