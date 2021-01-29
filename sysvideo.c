#include "types.h"
#include "defs.h"

int sys_getch(void) {
    return consoleget();
}

// TODO: Implement your system call for switching video modes (and any other video-related syscalls)
// in here.
int sys_greeting(void) {
cprintf("Hello, user\n");
return 0;
}

int sys_setvideomode(void){

    int m;
    if (argint(0, &m) < 0) {
        return -1;
    }
    // cprintf("Getting here");
     return consolevgamode(m);
}

int sys_setpixel(void){
    int x;
    int y;
    int c;
    if (argint(0, &x) < 0 || argint(1, &y) < 0 || argint(2, &c) < 0) {
        return -1;
    }
    //cprintf("Hello, user x: %d, y: %d, c: %d \n", x,y,c);
    
   uchar* p;
   p = consolevgabuffer()+ 320 * y + x;
   
   *p = c;
   return 0;
}

int sys_drawline(void){
    int x0;
    int y0;
    int x1;
    int y1;
    int c;
     if (argint(0, &x0) < 0 || argint(1, &y0) < 0 || argint(2, &x1) < 0 || argint(3, &y1) < 0 || argint(4, &c) < 0) {
        return -1;
    }
    cprintf("x0:%d,y0:%d,x1:%d,y1:%d,c:%d\n",x0,y0,x1,y1,c);
    int dx, dy, x, y;
 
	dx=x1-x0;
	dy=y1-y0;
 
	x=x0;
	y=y0;
 
	if(dx<0){
        dx = 0 - dx;
    }
    if(dy<0){
        dy = 0 - dy;
    }
    
    if(dx > dy){
        uchar* p;
        p = consolevgabuffer()+ 320 * y + x;
        *p = c;
        
        int pk = (2*dy) - dx;

        for(int i = 0; i < dx; i++){
            x++;
            if(pk < 0){
                pk = pk + (2*dy);
            } else {
                y++;
                pk = pk + (2*dy) - (2*dx);
            }

            uchar* p;
            p = consolevgabuffer()+ 320 * y + x;
            *p = c;   
        }
    } else {
        uchar* p;
        p = consolevgabuffer()+ 320 * y + x;
        *p = c;

        int pk = (2*dx) - dy;
        for(int i = 0; i < dy; i++){
            y++;
            if(pk < 0){
                pk = pk + (2*dx);
            } else {
                x++;
                pk = pk + (2*dx) - (2*dy);
            }
        uchar* p;
        p = consolevgabuffer()+ 320 * y + x;
        *p = c;
            
        }
    }

    return 0;
}
