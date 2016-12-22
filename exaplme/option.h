#ifndef OPTION_H_INCLUDED
#define OPTION_H_INCLUDED
#include "console_draw3.h"
#include "kb_input2.h"
#include "image.h"
#include "font.h"
#include "takeoff.h"
#include "audio.h"



void menu()
{
    clearScreen();
    Font *large_font = read_font("font.txt");
    char option,playoption;

    Audio star_wars_theme,rebel;
    openAudioFile("starwars.wav",&star_wars_theme);
    openAudioFile("rebel.wav",&rebel);

    Image *fighter_pic=read_image("fighter1.pixel","fighter1.color");
    show_image(fighter_pic,100,5);

    deadth_star=0;

    int flag=1,menuorder[5]={1,0,0,0,0},index=0,i=0,j=0,playflag=1,hard=0,score;
    if(menuorder[0]) putStringLarge(large_font, 10, 5, "start", 0);
    else putStringLarge(large_font, 10, 5, "start", 11);
    if(menuorder[1]) putStringLarge(large_font, 10, 11, "option", 0);
    else putStringLarge(large_font, 10, 11, "option", 11);
    if(menuorder[2]) putStringLarge(large_font, 10, 17, "help",0);
    else putStringLarge(large_font, 10, 17, "help", 11);
    if(menuorder[3]) putStringLarge(large_font, 10, 23, "exit", 0);
    else putStringLarge(large_font, 10, 23, "exit", 11);
    if(menuorder[4])putStringLarge(large_font,10,29,"Developers",0);
    else putStringLarge(large_font,10,29,"Developers",11);
    drawCmdWindow();
    clearScreen();
    show_image(fighter_pic,100,5);


    while(flag)
    {
          playAudio(&star_wars_theme);

        option=getKeyEventVirtual();
        if(waitForKeyDown(0.4))
        {
            switch(option)
            {
            case VK_UP:
            {
                for(i=0;i<5;i++) menuorder[i]=0;
                if(index>0) index--;
                else if(index==0) index=4;
                menuorder[index]=1;
                break;
            }
            case VK_DOWN:
            {
                for(i=0;i<5;i++) menuorder[i]=0;
                if(index<4) index++;
                else if(index==4) index=0;
                menuorder[index]=1;
                break;
            }
            case VK_ESCAPE:
                {
                    flag=0;
                    break;
                }
            case VK_RETURN:
                {
                    if(menuorder[0])
                    {
                        //star the game
                        destroy_image(fighter_pic);
                        clearScreen();
                        pauseAudio(&star_wars_theme);
                       // playAudio(&rebel);
                        takeoff();
                        clearScreen();
                        break;
                    }
                    if(menuorder[1])
                    {
                        //option
                        clearScreen();
                        break;
                    }
                    if(menuorder[2])
                    {
                      //print the instruction
                        int option;
                        Font *large_font = read_font("font.txt");
                        clearScreen();
                        putString(8, 3, "game help", 10, 0);
                        putString(8,3,"control your X wing",10,0);
                        putString(8,5,"with left and right",10,0);

                        drawCmdWindow();
                        Sleep(1000);

                        clearScreen();


                      //  help();
                        break;
                    }
                    if(menuorder[3])
                    {

                        //say goodbye
                        clearScreen();
                        putStringLarge(large_font,0,10,"Good Bye",10);
                        drawCmdWindow();
                        Sleep(1000);
                        flag=0;
                        clearScreen();
                        break;
                    }
                    if(menuorder[4]){
                        //display fighter picture
                        clearScreen();
                        Sleep(10);
                        putStringLarge(large_font,0,10,"Developed by Team 15 in NTHU",10);
                        putStringLarge(large_font,0,16,"CS18 Bill Chou",9);
                        putStringLarge(large_font,0,22,"DMS19 Kuenway",12);
                        putStringLarge(large_font,0,28,"DMS19 Tammy",10);
                        
                        drawCmdWindow();
                        Sleep(1500);
                        clearScreen();
                        putStringLarge(large_font,0,10,"Congradulations !!!",10);
                        putStringLarge(large_font,0,16,"You Get a Death Star!!",10);
                        
                        //death pic !!!
                        deadth_star=1;
                        drawCmdWindow();
                        Sleep(1500);
                        clearScreen();
                        
                        break;
                    }
                }
           
                    
              
            if(menuorder[0]) putStringLarge(large_font, 10, 5, "start", 15);
            else putStringLarge(large_font, 10, 5, "start", 11);
            if(menuorder[1]) putStringLarge(large_font, 10, 11, "option", 15);
            else putStringLarge(large_font, 10, 11, "option", 11);
            if(menuorder[2]) putStringLarge(large_font, 10, 17, "help", 15);
            else putStringLarge(large_font, 10, 17, "help", 11);
            if(menuorder[3]) putStringLarge(large_font, 10, 23, "exit", 15);
            else putStringLarge(large_font, 10, 23, "exit", 11);
            if(menuorder[4]) putStringLarge(large_font, 10, 29, "Developers", 15);
            else putStringLarge(large_font, 10, 29, "Developers", 11);

            drawCmdWindow();
        }
    }
    clearScreen();
}



#endif // OPTION_H_INCLUDED
