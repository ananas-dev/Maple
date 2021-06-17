#pragma once

#ifdef TPZ_PLATFORM_WINDOWS

extern Topaze::Application* Topaze::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Topaze::CreateApplicaton();
    app->Run();
    delete app;
}

#elif TPZ_PLATFORM_UNIX

extern Topaze::Application* Topaze::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Topaze::CreateApplication();
    app->Run();
    delete app;
}

#else
    #error Platform not supported !
#endif