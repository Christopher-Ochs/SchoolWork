#include <stdio.h>
#include <math.h>
#include "linkedliststackqueue.h"
#define PI 3.14159265

class branch
{
   public:
      branch(double l, double w, double h, double initx, double inity):
         length(l), width(w), heading(h), x(initx), y(inity)
         {

         }
      void draw()
      {
         printf("penup\r\n");
         printf("goto, %f, %f, 1, white\r\n", x, y);
         printf("pendown\r\n");
         double newx = x + cos(heading * PI / 180) * length;
         double newy = y + sin(heading * PI / 180) * length;
         printf("goto, %f, %f, %f, black\r\n", newx, newy, width);
         x = newx;
         y = newy;
      }

      double length;
      double width;
      double heading;
      double x;
      double y;

};

void drawtree()
{
   Queue < branch > queue;
   queue.enqueue(new branch(200,20,90,0,-200));
   while(!queue.isEmpty())
   {
      branch *b = queue.dequeue();
      b->draw();
      if(b->length*0.6 >= 10)
      {
         queue.enqueue(new branch(b->length*0.6, b->width*0.6, b->heading-45, b->x,b->y));
         queue.enqueue(new branch(b->length*0.6, b->width*0.6, b->heading+45, b->x,b->y));
      }
   }
}

int main()
{
   drawtree();
}
