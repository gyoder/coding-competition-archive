#include <iostream>
#include <algorithm>

using namespace std;

class Point
{
   public:
      double x, y;
      Point(double c_x, double c_y)
        :x(c_x),y(c_y){}
};

// y = ax + c
class Line
{
   public:
      double a, c;
      bool vertical;
      double x_origin;
      Line(double c_a, double c_c, bool c_vertical = false, double c_x_origin = 0)
        :a(c_a),c(c_c),vertical(c_vertical),x_origin(c_x_origin){}

      Point GetPointFromX(double x)
      {
         return Point(x, a*x+c);
      }
};

Line getLine(Point p1, Point p2)
{
   //check for vertical
   if(p1.x == p2.x) return Line(0,0,true,p1.x);

   double a, c;
   a = (p2.y - p1.y) / (p2.x - p1.x);

   c = p1.y - a*p1.x;

   return Line(a,c);
}

class Segment
{
   public:
      Line line;
      Point bound1;
      Point bound2;

      Segment(Line c_line, Point b1, Point b2)
         :line(c_line),bound1(b1),bound2(b2){}

      bool InBounds(Point p)
      {
         double left, right, bot, top;

         left = min(bound1.x, bound2.x);
         right = max(bound1.x, bound2.x);
         bot = min(bound1.y, bound2.y);
         top = max(bound1.y, bound2.y);

         return p.x >= left && p.x <= right
             && p.y >= bot && p.y <= top;
      }
};

Segment getSegment(Point p1, Point p2)
{
   Line line = getLine(p1, p2);

   return Segment(line, p1, p2);
}

bool Collide(Segment s1, Segment s2)
{ 

   // if both vertical, they are parallel, no collision
   if(s1.line.vertical && s2.line.vertical) return false;

   if(s1.line.vertical)
   {
      Point p = s2.line.GetPointFromX(s1.line.x_origin);

      return s1.InBounds(p) && s2.InBounds(p);
   }

   if(s2.line.vertical)
   {
      Point p = s1.line.GetPointFromX(s2.line.x_origin);

      return s1.InBounds(p) && s2.InBounds(p);
   }

   // same slope, they are parallel, no collision
   if(s1.line.a == s2.line.a) return false;

   double x = (s2.line.c - s1.line.c) / (s1.line.a - s2.line.a);

   Point p = s1.line.GetPointFromX(x);
 
   return s1.InBounds(p) && s2.InBounds(p);
}

int main()
{
   int T; cin >> T;

   for(int t = 0; t < T; t++)
   {
      double spyX, spyY, camX, camY, W;
      cin >> spyX >> spyY >> camX >> camY >> W;

      Segment spySight = getSegment(Point(spyX, spyY), Point(camX, camY));

      // if it collides with at least one of the walls, cam can't see the spy
      bool collided = false;
      for(int w = 0; w < W; w++)
      {
         double wallsx, wallsy, wallex, walley;
         cin >> wallsx >> wallsy >> wallex >> walley;

         Segment wall = getSegment(Point(wallsx,wallsy),Point(wallex,walley)); 

         // if they are colliding, cam can't see the spy
         if(Collide(wall, spySight)) collided = true;
      }

      // if they are colliding, cam can't see the spy
      if(collided) cout << "NO" << endl;
      else cout << "YES" << endl;
   }

}
