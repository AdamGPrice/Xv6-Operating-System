#include "types.h"
#include "user.h"
#include "graphics.h"


int main() {
    drawbegin(MODE_12);

    for (int i = 0; i < 8; i++) {
        int val = i * 10;
        drawline(0, 200 + val, 639, 479 - val, i + 1);
        drawline(639, 200 + val, 0, 479 - val, i + 1);
    }
    for (int i = 0; i < 8; i++) {
        int val = i * 10;
        drawline(0, val, 639, 279 - val, i + 1);
        drawline(639, val, 0, 279 - val, i + 1);
    }

    //fillscreen(8);
    fillrect(170, 144, 240, 180, 4);
    fillrect(300, 100, 200, 100, 3);
    fillrect(220, 100, 40, 90, 2);
    fillrect(500, 333, 66, 77, 5);
    fillrect(60, 220, 180, 130, 7);

    // polygon shapes
    int hexagon[] = {
        120, 120,
        120, 140,
        138, 150,
        156, 140,
        156, 120,
        138, 110,
    };

    int star[] = {
        160, 155,
        180, 200,
        230, 200,
        190, 230,
        210, 280,
        160, 248,
        110, 280,
        130, 230,
        90,  200,
        140, 200,
    };

    drawpolygon(hexagon, sizeof(hexagon) / (sizeof(int) * 2), 9);
    drawpolygon(star, sizeof(star) / (sizeof(int) * 2), 14);


    //fillpolygon(points, sizeof(points) / sizeof(int), 9);

    drawcircle(340, 177, 100, 6);
    drawcircle(175, 340, 120, 10);

    for (int i = 0; i < 40; i++) {
        drawpixel(360 + i, 170 - i, i % 8);
    }
    
    


    printf(1, "Printing text works during graphics mode\n");
    printf(1, "Test Test 123\n");

    drawend();

    exit();
}