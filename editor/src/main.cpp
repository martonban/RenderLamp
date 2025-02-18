/****************************************************************************
 *                             RenderLamp - main.cpp
 *                         Copyright (c) Márton Bán 2024
 *
 *  This is going to be the entry point of the application.  
 * 
****************************************************************************/
#include "Application.h"

int main(void)
{
    Application& render_lamp_app = Application::GetInstance();
    
    render_lamp_app.Init();
    render_lamp_app.Start();

    return 0;
}