struct stat;
struct rtcdate;
struct drawcalls;

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
int getch(void);

// TODO: Declare your user APIs for your system calls.
int setvideomode(int);
int setpixel(int, int, int);
int setline(int, int, int, int, int);
int senddrawcalls(struct drawcalls*);


// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, const char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);

// graphics.c
void drawbegin();
void drawend();
void fillscreen(int);
void drawpixel(int, int, int);
void drawline(int, int, int, int, int);
void drawcircle(int, int, int, int);
void fillrect(int, int, int, int, int);
void drawpolygon(int *, int, int);
void fillpolygon(int *, int, int);