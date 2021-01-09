//#include "graphics.h"
#include "types.h"
#include "defs.h"
#include "graphics.h"

int sys_getch(void) {
    return consoleget();
}

// TODO: Implement your system call for switching video modes (and any other video-related syscalls)
// in here.
int sys_setvideomode(void) {
    int mode;
    if (argint(0, &mode) < 0) {
        return -1;
    }
    return consolevgamode(mode);
}

int sys_setpixel(void) {
    int x;
    int y;
    int colour;
    if (argint(0, &x) < 0 || argint(1, &y) < 0 || argint(2, &colour) < 0) {
        return -1;
    }
    return consolesetpixel(x, y, colour);
}

int sys_setline(void) {
    int x0;
    int y0;
    int x1;
    int y1;
    int colour;
    if (argint(0, &x0) < 0 || argint(1, &y0) < 0 || argint(2, &x1) < 0 || argint(3, &y1) < 0 || argint(4, &colour) < 0) {
        return -1;
    }
    consoledrawline(x0, y0, x1, y1, colour);
    return 0;
}

int sys_senddrawcalls(void) {
    struct drawcalls *calls;

    if (argptr(0, (void*)&calls, sizeof(*calls)) < 0 ) {
        return -1;
    }

    for (int i = 0; i < calls->index; i++) {
        drawcall call = calls->array[i];
        
        switch (call.type)
        {
            case FILL_SCREEN:
                consoleclearscreen(call.colour);
                break;
            case DRAW_PIXEL:
                consolesetpixel(call.x, call.y, call.colour);
                break;            
            case DRAW_LINE:
                consoledrawline(call.x0, call.y0, call.x1, call.y1, call.colour);
                break;
            case DRAW_CIRCLE:
                consoledrawcircle(call.x, call.y, call.r, call.colour);
                break;
            case FILL_RECT:
                consolefillrect(call.x, call.y, call.width, call.height, call.colour);
                break;
            case FILL_POLY:
                consolefillpolygon(call.points, call.count, call.colour);
                break;
            case DRAW_POLY:
                consoledrawpolygon(call.points, call.count, call.colour);
                break;
            default:
                break;
        }
    } 
    return 0;
}