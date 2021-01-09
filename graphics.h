typedef enum {
    MODE_12 = 0x12,
    MODE_13 = 0x13
} videomode;

typedef enum {
    FILL_SCREEN,
    DRAW_PIXEL,
    DRAW_LINE,
    DRAW_CIRCLE,
    FILL_RECT,
    DRAW_POLY,
    FILL_POLY,
} drawtype;

typedef struct drawcall {
    union {
        struct {
            int x, y; 
            union {
                struct {
                    int width, height;
                };
                struct {
                    int r;
                };
            };
        };
        struct {
            int x0, y0, x1, y1;
        };
        struct {
            int* points;
            int count;
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