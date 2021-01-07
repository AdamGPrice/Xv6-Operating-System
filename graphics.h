typedef enum {
    MODE_12 = 0x12,
    MODE_13 = 0x13
} videomode;

typedef enum {
    DRAW_PIXEL,
    DRAW_LINE,

    FILL_RECT,
} drawtype;

typedef struct drawcall {
    union {
        struct {
            int x, y, width, height;
        };
        struct {
            int x0, y0, x1, y1;
        };
    };
    
    int colour;
    drawtype type;
} drawcall;

typedef struct drawcalls {
    drawcall *array;
    int index;
    int size;
} drawcalls;

drawcalls *newdrawcalls();
void addcall();
void freecalls(drawcalls *calls);