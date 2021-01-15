#include "types.h"
#include "user.h"
#include "graphics.h"

// mode 13 with batching

int main() {
    drawbegin(MODE_13);

    for (int i = 0; i < 20; i++) {
        drawline(0, 10 * i, 319, 199 - (10 * i), i + 1);
    }
    
    fillrect(100, 140, 112, 50, 5);
    fillrect(200, 60, 50, 100, 4);
    fillrect(50, 20, 100, 50, 7);
    fillrect(100, 40, 20, 50, 1);
    drawcircle(100, 140, 20, 3);
    drawcircle(260, 120, 40, 5);
    drawcircle(40, 40, 100, 2);

    int polygon[] = {
        40,80,
        9,95,
        1,129,
        23,156,
        57,156,
        79,129,
        71,95
    };

    int polygon2[] = {
        236,103,
        195,120,
        161,90,
        181,155,
        227,149,
    };

    drawpolygon(polygon, sizeof(polygon) / (sizeof(int) * 2), 5);
    fillpolygon(polygon2, sizeof(polygon2) / (sizeof(int) * 2), 6);

    drawend();
    exit();
}