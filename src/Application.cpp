#include "Application.h"

 Application::Application(const std::string &app_name)
{
     mWindow = std::make_unique<LK::GLWindow>();
     mWindow->init(1024, 720, app_name);
}


void Application::mianLoop()
{
     while (mWindow->isRunning())
     {
         mWindow->render();
     }
}
