#include "types.h"
#include "user.h"
#include "graphics.h"

// instance of the dynamic array
drawcalls *calls = 0;

void drawbegin(videomode mode) {
    setvideomode(mode);
    calls = newdrawcalls();
}

void drawend() {
    freecalls(calls);
    senddrawcalls(calls);
    getch();
    setvideomode(0x03);
}

void drawpixel(int x, int y, int colour) {
    drawcall call = (struct drawcall){ .x = x, .y = y, .colour = colour, .type = DRAW_PIXEL };
    addcall(calls, call);
}

void drawline(int x0, int y0, int x1, int y1, int colour) {
    drawcall call = (struct drawcall){ .x0 = x0, .y0 = y0, .x1 = x1, .y1 = y1, .colour = colour, .type = DRAW_LINE };
    addcall(calls, call);
}

void fillrect(int x, int y, int width, int height, int colour) {
    drawcall call = (struct drawcall){ .x = x, .y = y, .width = width, .height = height, .colour = colour, .type = FILL_RECT };
    addcall(calls, call);
}



// **dynamic array functions**
drawcalls *newdrawcalls() {
    drawcalls *calls = (drawcalls *)malloc(sizeof(drawcalls));
    calls->array = 0;
    calls->index = 0;
    calls->size = 0;
    return calls;
}

void addcall(drawcalls *calls, drawcall call) {
    if (calls == 0 || calls->index == calls->size) {
        int newSize = calls->size + 20; // increase array size by 20
        drawcall *newCalls = (drawcall *)malloc(newSize * sizeof(drawcall));

        // copy draw calls into the new array and free the old
        for (int i = 0; i < calls->size; i++) {
            newCalls[i] = calls->array[i];
        }
        if (calls->array != 0) {
            free(calls->array);
        }

        calls->array = newCalls;
        calls->size = newSize;
    }
    calls->array[calls->index] = call;
    calls->index++;
}

void freecalls(drawcalls *calls) {
    if (calls->array != 0) {
        free(calls->array);
    } 
    free(calls);
}