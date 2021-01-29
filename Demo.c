#include "types.h"
#include "user.h"

int main() {
int mode = 0x13;
int x;
int y;
int colour = 0;
greeting();
setvideomode(mode);
 for (x = 0; x <= 320; x++)
 {
     for (y = 0; y <= 200; y++)
     {
       //printf(1, "%d, %d, %d\n", x, y, c);
        
        setpixel(x,y,colour);
       
     }
 }
 
 
drawline(10,10,310,190,1);
drawline(10,100,150,190,2);
drawline(150,10,310,100,4);
sleep(200);
setvideomode(0x03);
/* greeting();
int a = 6;
int b = 12;
int c = add(a,b);
*/
greeting();
sleep(200);
exit(); 
}
