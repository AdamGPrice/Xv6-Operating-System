#include "types.h"
#include "user.h"
#include "graphics.h"


int main() {
    drawbegin(MODE_12);

    fillrect(300, 100, 200, 100, 3);
    fillrect(200, 100, 30, 60, 2);
    fillrect(500, 333, 66, 77, 5);
    fillrect(40, 260, 140, 100, 12);

    for (int i = 0; i < 40; i++) {
        drawpixel(360 + i, 170 - i, i % 8);
    }
    
    for (int i = 0; i < 16; i++)
    {
        drawline(0, i * 10, 639, 479 - (i * 10), i);
        drawline(639, i * 10, 0, 479 - (i * 10), i);
    }


    printf(1, "Printing text works during graphics mode\n");
    printf(1, "Test Test 123\n");
    drawend();

    exit();
}