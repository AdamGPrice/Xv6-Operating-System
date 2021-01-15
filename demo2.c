#include "types.h"
#include "user.h"

// MODE 12 Without batching demo

int main() {
    setvideomode(0x12);


    for (int i = 0; i < 8; i++) {
        int val = i * 10;
        setline(0, val, 639, 279 - val, i + 2);
        setline(639, val, 0, 279 - val, i + 2);
    }
    for (int i = 0; i < 8; i++) {
        int val = i * 10;
        setline(0, 200 + val, 639, 479 - val, i + 2);
        setline(639, 200 + val, 0, 479 - val, i + 2);
    }


    setpixel(280, 111, 7);
    setpixel(268, 71, 2);
    setpixel(73, 174, 3);
    setpixel(13, 84, 4);
    setpixel(73, 34, 5);
    setpixel(212, 126, 6);
    setpixel(54, 139, 7);
    setpixel(69, 79, 8);

    printf(1, "Hello this is a test\n");
    printf(1, "Does printing in video mode work?\n");

    getch();
    setvideomode(0x03);
    exit();
}