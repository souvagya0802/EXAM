#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define BALL_RADIUS 20
#define PADDLE_WIDTH 80
#define PADDLE_HEIGHT 20

int main()
{
    int x,y,dx,dy,paddle_x,paddle_y;	
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\tc\\BGI");

     x = SCREEN_WIDTH / 2;
     y = BALL_RADIUS;
     dx = 2;
     dy = 2;

     paddle_x = (SCREEN_WIDTH - PADDLE_WIDTH) / 2;
     paddle_y = SCREEN_HEIGHT - PADDLE_HEIGHT;

    while (1)
    {
        cleardevice();

        // Draw ball
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, RED);
        circle(x, y, BALL_RADIUS);
        floodfill(x, y, WHITE);

        // Draw paddle
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, BLUE);
        bar(paddle_x, paddle_y, paddle_x + PADDLE_WIDTH, paddle_y + PADDLE_HEIGHT);

        // Move ball
        x += dx;
        y += dy;

        // Bounce ball off walls
        if (x < BALL_RADIUS || x > SCREEN_WIDTH - BALL_RADIUS)
            dx = -dx;
        if (y < BALL_RADIUS)
            dy = -dy;

        // Check for collision with paddle
        if (x > paddle_x && x < paddle_x + PADDLE_WIDTH && y > paddle_y - BALL_RADIUS)
            dy = -dy;

        // Check for game over
        if (y > SCREEN_HEIGHT - BALL_RADIUS)
            break;

        // Move paddle with arrow keys
        if (kbhit())
        {
            char ch = getch();
            if (ch == 0)
                ch = getch();
            if (ch == 75 && paddle_x > 0) // left arrow key
                paddle_x -= 10;
            if (ch == 77 && paddle_x < SCREEN_WIDTH - PADDLE_WIDTH) // right arrow key
                paddle_x += 10;
        }

        delay(10);
    }

    closegraph();
    return 0;
}
