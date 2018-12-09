
#include "TXLib.h"

void Rocket ();

int main()
    {
    txCreateWindow (1680, 1050);

    Rocket ();

    return 0;
    }

void Rocket ()
    {
    HDC Rocket = txLoadImage ("Rocket.bmp");
    if (Rocket == NULL) txMessageBox ("Rocket.bmp isn't found");

    HDC Space = txLoadImage ("space.bmp");
    if (Space == NULL) txMessageBox ("space.bmp isn't found");

    HDC Face = txLoadImage ("trollface.bmp");
    if (Face == NULL) txMessageBox ("trollface.bmp isn't found");

    HDC Troll = txLoadImage ("troll.bmp");
    if (Troll == NULL) txMessageBox ("troll.bmp isn't found");

    int RocketM = txGetExtentX (Rocket);

    int SpaceX = txGetExtentX (Space);

    int RocketX = 500;
    int RocketY = 500;

    int hDest = 50;
    int wDest = 50;

    int Sizing = +20;

    int SourceX = 0;

    while (! GetAsyncKeyState ('L'))
        {
        txSleep (50);

        int MouseX = txMouseX();
        int MouseY = txMouseY();

        txBitBlt (txDC (), 0, 0, SpaceX, 0, Space, 0, 0);

        //txAlphaBlend (txDC (), RocketX, RocketY, RocketM, 0, Rocket, 0, 0);

        BLENDFUNCTION blend = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };

        Win32::AlphaBlend (txDC (), RocketX, RocketY, hDest, wDest, Rocket, SourceX, 0, 450, 450, blend);

        printf ("сахарная батарея %d%d\n", hDest, wDest);

       // printf ("старый идиот %d\n", MouseY - RocketY);

        if (MouseX - RocketX < 0)
            {
            SourceX = 450;
            }
        else SourceX = 0;

        if (MouseY - RocketY > 0 )
            {
            SourceX = 450;
            }
        else SourceX = 0;


        RocketX = MouseX;

        RocketY = MouseY;

        if (hDest > 600 && wDest > 600)
            {
            txAlphaBlend (txDC (), RocketX, RocketY, 0, 0, Face);
            }

        if (hDest >100 && wDest > 100)
            {
            txAlphaBlend (txDC (), RocketX, RocketY, 0, 0, Troll);
            }


        if (GetAsyncKeyState (VK_CONTROL))
            {
            hDest = hDest + Sizing;
            wDest = wDest + Sizing;
            }

        if (GetAsyncKeyState (VK_SHIFT))
            {
            hDest = hDest - Sizing;
            wDest = wDest - Sizing;
            }


        if (GetAsyncKeyState ('M')) { wDest = 500,  hDest = 500; }


        }
    }



