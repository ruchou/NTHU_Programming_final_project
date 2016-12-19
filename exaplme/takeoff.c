#include "takeoff.h"

#define NUM_KEYS 31
#define laserbeam 5
#define proto_torpedo 2



void boarder1()
{
    int i;
    for (i = 4; i <= 47; i++){
        putASCII2(i, 4, 0xBD, 15, 15);
        putASCII2(i, 41, 0xBD, 15, 15);
    }
    for (i = 4; i <= 40; i++){
        putASCII2(4, i, 0xBD, 15, 15);
    }
}


void boarder2()
{
    int i;
    for (i = 47; i <= 180; i++){
        putASCII2(i, 4, 0xA1, 15, 15);
        putASCII2(i, 41, 0xA1, 15, 15);
    }
    for (i = 4; i <= 40; i++){
        putASCII2(47, i, 0xA1, 15, 15);
        putASCII2(180, i, 0xA1, 15, 15);
    }
}


void xwing(int x)
{
    int i, j;

            for (i = 0; i < 2; i++){
                putASCII2(8*x+i, 36, '@', 8, 8);
                putASCII2(8*x+i, 37, '@', 8, 8);

            }
            putASCII2(8*x-3, 38, '@', 8, 6);
            putASCII2(8*x, 38, '@', 8, 8);
            putASCII2(8*x+1, 38, '@', 8, 8);
            putASCII2(8*x+4, 38, '@', 8, 6);

             putASCII2(8*x-3, 39, '@', 8, 6);
            putASCII2(8*x, 39, '@', 8, 8);
            putASCII2(8*x+1, 39, '@', 8, 8);
             putASCII2(8*x+4, 39, '@', 8, 6);

            for (i = 0; i < 8; i++){
                putASCII2(8*x-3+i, 40, '@', 8, 8);
            }


}

void removeXwing(int x)
{
      int i, j;

            for (i = 0; i < 2; i++){
                putASCII2(8*x+i, 36, '@', 0, 0);
                putASCII2(8*x+i, 37, '@', 0, 0);

            }
            putASCII2(8*x-3, 38, '@', 0, 0);
            putASCII2(8*x, 38, '@', 0, 0);
            putASCII2(8*x+1, 38, '@', 0, 0);
            putASCII2(8*x+4, 38, '@', 0, 0);

             putASCII2(8*x-3, 39, '@', 0, 0);
            putASCII2(8*x, 39, '@', 0, 0);
            putASCII2(8*x+1, 39, '@', 0, 0);
             putASCII2(8*x+4, 39, '@', 0, 0);

            for (i = 0; i < 8; i++){
                putASCII2(8*x-3+i, 40, '@', 0, 0);
            }
}




void takeoff(void ){

    clearScreen();
     int running = 1;
    int i, j, k, index = 1, wt = 0,x=0;

    //use digits char to store the dig value
    //sprintf fails in converting digits to string
    char *digits[10]={"0","1","2","3","4","5","6","7","8","9"};

    //the range of the game
    int battlefield[5][6] = {};
    int score=0;
    int life=3,d=0;
    int Tifighter[5][6] = {};
    int laserstate[5][6]={};


    int key_val[NUM_KEYS] = {VK_A,VK_B,VK_C,VK_D,VK_E,VK_F,VK_G,VK_H,VK_I,VK_J,VK_K,VK_L,VK_M,VK_N,VK_O,VK_P,VK_Q,VK_R,VK_S,VK_T,VK_U,VK_V,VK_W,VK_X,VK_Y,VK_Z,VK_LEFT,VK_RIGHT,VK_UP,VK_DOWN,VK_ESCAPE};
    int key_down[NUM_KEYS] = {0};
    int wave=1;
    srand(time(0));
    Font *large_font = read_font("font.txt");
    int ammo=10,r=3;
    int proton_torpedo=5,o_reload=6;


     Audio star_wars_theme,rebel,xwing_take_off,laser_sound;
    openAudioFile("starwars.wav",&star_wars_theme);
    openAudioFile("rebel.wav",&rebel);
    openAudioFile("takeoff.wav",&xwing_take_off);
    openAudioFile("laser_m.wav",&laser_sound);
    playAudio(&xwing_take_off);
    Sleep(5000);


    while (running){

            playAudio(&rebel);
            clearScreen();
        Sleep(10);


        wt++;
        if(wt==1000) wt=0;
        putStringLarge(large_font,48,10,"|||||",0);
       // drawCmdWindow();
        //dispay the board
        putStringLarge(large_font,80,10,digits[d%10],12);
        putStringLarge(large_font,72,10,digits[d/10%10],12);
        putStringLarge(large_font,64,10,digits[d/100%10],12);
        putStringLarge(large_font,56,10,digits[d/1000%10],12);
        putStringLarge(large_font,48,10,digits[d/10000%10],12);
        putStringLarge(large_font,95,5,"ammo",10);
        putStringLarge(large_font,119,10,digits[ammo%10],12);
        putStringLarge(large_font,110,10,digits[ammo/10%10],12);

        putStringLarge(large_font,95,15,"Torpedo",10);
        putStringLarge(large_font,119,20,digits[proton_torpedo%10],12);
        putStringLarge(large_font,110,20,digits[proton_torpedo/10%10],12);


        putStringLarge(large_font,95,25,"Death Star",10);
      putStringLarge(large_font,119,30,digits[deadth_star%10],12);





        if(d<score) d++;
        drawCmdWindow();

        putStringLarge(large_font,48,5,"SCORE",11);
        putStringLarge(large_font,48,15,"WAVE",11);
        putStringLarge(large_font,48,20,"|||||",0);
        putStringLarge(large_font,64,20,digits[wave],13);
        putStringLarge(large_font,48,25,"Damage",11);
        putStringLarge(large_font,48,35,"|||||",0);
        boarder1();
        boarder2();




        if(life==3)
        {
            putStringLarge(large_font,48,30,"|||||",10);
        }
        if(life==2)
        {
            putStringLarge(large_font,48,30,"|||",14);
            putStringLarge(large_font,64,30,"||",0);
        }
        if(life==1)
        {
            putStringLarge(large_font,48,30,"|",12);
            putStringLarge(large_font,56,30,"||||",0);
        }
        if(life<=0)
        {
            putStringLarge(large_font,48,30,"",10);
            putStringLarge(large_font,52,30,"||||",0);
            running=0;
        }


        //the key
        for (k = 0; k < NUM_KEYS; k++) {
            if(KEY_DOWN(key_val[k])){
                key_down[k]++;
                if (key_down[k] == 1){
                    switch (key_val[k]) {
                        case VK_RIGHT:{
                            if(index<5){
                                removeXwing(index);
                                index++;
                            }
                            else if(index==5){
                                removeXwing(index);
                            }
                            break;
                        }
                        case VK_LEFT:{
                            if(index>1){
                                removeXwing(index);
                                index--;
                            }
                            else if(index==1){
                                removeXwing(index);
                            }
                            break;
                        }
                        case VK_UP:
                            {
                                if(ammo>0){
                                battlefield[index-1][5]=1;
                                 ammo--;

                                // playAudio(&laser_sound);
                                }else{
                                    putStringLarge(large_font,25,43,"out of laser",10);
                                    putStringLarge(large_font,23,47,"press r to reload",10);
                                   // drawCmdWindow();

                                }
                                break;
                            }

                        case VK_ESCAPE:{
                            return;

                        }
                        case VK_R:{
                            //you can only reload if ammo is below 5
                            if(r<=0 && ammo<5){
                                ammo=10;
                                r=3;
                                //clearScreen();
                            }else r--;

                                break;

                        }
                        case VK_P:{
                            //proton torpedo

                            if(proton_torpedo>0){
                                battlefield[index-1][5]=2;
                                if(index>=1){
                                    battlefield[index-2][5]=2;
                                }
                                if(index<=4){
                                    battlefield[index][5]=2;
                                }

                                 proton_torpedo--;

                                // playAudio(&laser_sound);
                                }else{
                                    putStringLarge(large_font,25,43,"out of torpedo",10);
                                    putStringLarge(large_font,23,47,"press O to reload",10);
                                   // drawCmdWindow();

                                }
                                break;

                        }

                        case VK_O:{
                                //you can only reload if torpedo  is below 2
                            if(o_reload<=0 && proton_torpedo<2){
                                 proton_torpedo=6;
                                o_reload=6;
                                //clearScreen();
                            }else o_reload--;

                            break;

                        }

                        case VK_D:{


                            if(deadth_star==1){
                               int q,w;
                               for(q=0;q<5;q++)
                               for(w=0;w<6;w++){
                                battlefield[q][w]=1;
                               }
                                deadth_star=0;
                            }


                            break;

                        }


                        case VK_Z:{
                            //eastern egg haha!!
                               int q,w;
                               for(q=0;q<5;q++)
                               for(w=0;w<6;w++){
                                battlefield[q][w]=1;
                               }

                                break;

                        }
                         case VK_U:{
                            //eastern egg challenge!!
                              wave=5;
                                break;

                        }
                        case VK_H:{
                        //eastern egg
                            life=3;

                        }




                      //  default :{

                       //     battlefield[index-1][5]=key_val[k];
                       //     colorstate[index-1][5]=color;
                        //    break;
                       // }

                    }
                }
            }
            if (KEY_UP(key_val[k]) && key_down[k]){
                key_down[k] = 0;
            }
            if (key_down[k] == 5){
                key_down[k] = 0;
            }
        }

        //check score
        for(i=1;i<=5;i++)
        {
            for(j=1;j<=6;j++)
            {

                if(battlefield[i-1][j-1]&&battlefield[i-1][j-1]==Tifighter[i-1][j-1])
                {
                            laserstate[i-1][j-1]=1;
                            score+=10;
                }

                if(battlefield[i-1][j-1]==2&&battlefield[i-1][j-1]==(Tifighter[i-1][j-1]+1))
                {
                            laserstate[i-1][j-1]=1;
                            score+=10;
                }



            }
        }


        //set the ti fighter
        if(wt%30==1)
        {
            x=rand()%5;
            Tifighter[x][0]=1;
        }

        if(wt%31==1 && score>500){
            wave=2;
            x=rand()%5;
            Tifighter[x][0]=1;
        }


        if(wt%31==2 &&score>750){
            wave=3;
             x=rand()%5;
            Tifighter[x][0]=1;

        }
        if(wt%25==2 &&score>1000){
            wave=4;
             x=rand()%5;
            Tifighter[x][0]=1;

        }

        if(wt%25==1 &&score>1250){
            wave=5;
             x=rand()%5;
            Tifighter[x][0]=1;

        }




        //let it fall
        if(wt%20==0)
        {
            for(i=5;i<=44;i++){
                for(j=5;j<=34;j++)
                    putASCII2(i,j,' ',0,0);
            }
            for(i=1;i<=5;i++)
            {
                for(j=6;j>=1;j--)
                {
                    if(Tifighter[i-1][j-1]&&j<=5)
                    {
                        Tifighter[i-1][j]=Tifighter[i-1][j-1];
                        Tifighter[i-1][j-1]=0;
                    }
                    //fall but you dont get it
                    else if(Tifighter[i-1][5]&&j==6)
                    {
                        Tifighter[i-1][5]=0;
                        if(wave!=6)
                        {
                            life--;
                        }
                    }
                }

            }
        }



            for(i=5;i<=44;i++){
                for(j=5;j<=34;j++)
                    putASCII2(i,j,' ',0,0);
            }
            for(i=1;i<=5;i++){
                for(j=1;j<=6;j++){
                    if(battlefield[i-1][j-1]&&j-2>=0){
                        battlefield[i-1][j-2]=battlefield[i-1][j-1];
                        battlefield[i-1][j-1]=0;
                    }
                    else battlefield[i-1][j-1]=0;
                }
            }




        for(i=1;i<=5;i++){
            for(j=1;j<=6;j++){
                if(battlefield[i-1][j-1])
                putStringLarge(large_font,8*i-3,5*j,"I",9);
                if(Tifighter[i-1][j-1])
                putStringLarge(large_font,8*i-3,5*j,"H",12);
                //hit the target
                if(laserstate[i-1][j-1]==1)
                {
                    putStringLarge(large_font,8*i-3,5*j,"B",14);
                    laserstate[i-1][j-1]=0;
                    Tifighter[i-1][j-1]=0;
                    battlefield[i-1][j-1]=0;
                }
            }
        }

        xwing(index);


        drawCmdWindow();
    }
    drawCmdWindow();
    clearScreen();
    pauseAudio(&rebel);
    closeMidi();
    return score;





}
