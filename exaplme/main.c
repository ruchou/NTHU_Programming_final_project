#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <windows.h>
#include <mmsystem.h>

#include "console_draw3.h"
#include "kb_input2.h"
#include "image.h"
#include "font.h"

#include "intro.h"
#include "option.h"
int main()
{
    Font *large_font=read_font("font.txt");
    start();
    initializeKeyInput();
    menu();
   //clearScreen();
    return 0;
}
