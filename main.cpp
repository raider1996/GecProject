/*
    GecProject - For GEC students to use as a base for their projects.
    Already has SFML linked and ImGui set up.
*/

#include "ExternalHeaders.h"
#include "RedirectCout.h"
#include <time.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Graphics.h"
#include "Sprite.h"
using namespace sf;

void DefineGUI();

//FPS varables
static int frames = 0;
static double starttime = 0;
static double timepassed = 0;
static bool first = false;
static float fps = 0.0f;
Clock AnimClock;
//Sprite Size
int changeAnim = -1; 
int SwitchAnim = -1;


int main()
{
    // Redirect cout to HAPI
    outbuf ob;
    std::streambuf* sb = std::cout.rdbuf(&ob);

    // Redirect cerr
    outbuferr oberr;
    std::streambuf* sberr = std::cerr.rdbuf(&oberr);

    // Turn on memory leak checking
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "GEC Milestone 2 Example");


    // Set up ImGui (the UI library)
    ImGui::SFML::Init(window);

    // Create a simple shape to draw
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // Clock required by the UI
    sf::Clock uiDeltaClock;

    Graphics graphics;

    SpriteSettings settings;
    settings.textureFilename = "Data\\Textures\\sprite\\idlesheet.png";
    settings.numFrames = 2;
    graphics.CreateSprite("Idle", settings);
   
    while (window.isOpen())
    {     
     /*   if (AnimClock.getElapsedTime().asSeconds() > 0.20f)
        {
            AnimClock.restart();


            SwitchAnim++;
            switch (changeAnim)
            {
            case 0:
                if (SwitchAnim >= (graphics.key.size())) { SwitchAnim = 0; }
                graphics.key.("idle"[SwitchAnim]);
                break;
            default:
                break;
            }
        }*/

         //display fps
        frames++;
        if (timepassed - starttime > 1000 && frames > 10)
        {
            fps = (double)frames / ((timepassed - starttime) / 1000);
            starttime = timepassed;
            frames = 0;
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(window, event);

            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }        

        // ImGui must be updated each frame
        ImGui::SFML::Update(window, uiDeltaClock.restart());

        // The UI gets defined each time
        DefineGUI();

        // Clear the window
        window.clear();



        // UI needs drawing last
        ImGui::SFML::Render(window);

        switch (changeAnim)
        {
        case 0:
            graphics.RenderSprite("idle", 30, 30, 2,window);
            break;
        default:
            break;
        }

        window.display();
        timepassed = clock();
    }

    std::cout << "Finished!" << std::endl;

	ImGui::SFML::Shutdown();

    return 0;
}

// Use IMGUI for a simple on screen GUI
void DefineGUI()
{
    // Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    ImGui::Begin("GEC");				// Create a window called "3GP" and append into it.

    ImGui::Text("Kirby");               // Display some text (you can use a format strings too)


    if (ImGui::Button("Idle"))
    {
        changeAnim = 0;
    }
    
    ImGui::Text("\n fps: %.1f", fps);

    ImGui::End();
}
