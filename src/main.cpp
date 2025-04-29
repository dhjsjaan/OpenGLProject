#include "Application.h"

int main()
{
    auto app = std::make_unique<Application>("APP");
    app->mianLoop();
    return 0;
}