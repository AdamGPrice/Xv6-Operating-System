#include "types.h"
#include "user.h"
#include "graphics.h"

// mode 13 with batching

int main() {
    drawbegin(MODE_12);

    for (int i = 0; i < 6; i++) {
        int val = i * 10;
        drawline(0, 200 + val, 639, 479 - val, i + 1);
        drawline(639, 200 + val, 0, 479 - val, i + 1);
    }
    for (int i = 0; i < 6; i++) {
        int val = i * 10;
        drawline(0, val, 639, 279 - val, i + 1);
        drawline(639, val, 0, 279 - val, i + 1);
    }

    //fillscreen(8);
    fillrect(170, 144, 240, 180, 4);


    // polygon shapes
    int polygon[] = {
        100, 150,
        200, 130,
        200, 270,
        100, 250,
    };

    int polygon2[] = {
        300, 120,
        400, 30,
        400, 220,
        300, 200,
        70, 100, 
        200, 100,
        240, 70
    };

    int polygon3[] = {
        236,103,
        195,120,
        161,90,
        181,155,
        227,149,
    };

    int star[] = {
        450,263,
        400,300,
        333,276,
        352,335,
        309,391,
        371,390,
        410,449,
        429,390,
        498,371,
        448,335,
    };
    
    fillpolygon(polygon2, sizeof(polygon2) / (sizeof(int) * 2), 14);
    fillrect(380, 100, 200, 100, 3);
    fillrect(220, 100, 40, 90, 2);
    fillrect(500, 207, 66, 150, 5);
    fillrect(340, 250, 200, 40, 9);
    fillrect(60, 220, 180, 130, 7);
    fillpolygon(polygon3, sizeof(polygon3) / (sizeof(int) * 2), 9);
    drawpolygon(polygon, sizeof(polygon) / (sizeof(int) * 2), 5);
    fillpolygon(star, sizeof(star) / (sizeof(int) * 2), 10);

    drawcircle(340, 177, 100, 6);
    drawcircle(175, 340, 120, 10);
    drawcircle(500, 210, 50, 15);

    for (int i = 0; i < 40; i++) {
        drawpixel(360 + i, 170 - i, i % 8);
    }


    printf(1, "Printing text works during graphics mode\n");
    printf(1, "Test Test 123\n");

    //fillrect(1, 1, 638, 478, 12);

    drawend();

    exit();
}