// Simple example showing how to draw lines with the SGL library

#include <iostream>
#include "DisjointSet.hpp"
/*#include <memory>
 #include "sgl.hpp"

   using namespace sgl;

   class GridWindow : public Window {
   public:
   // Constructor makes a width x height window
   GridWindow(double width, double height) :
        Window("Grid", 0, width, 0, height) {
   }

   // The paint method simply draws a grid
   void paint() override {
        set_color(BLACK);
        for (int x = 30; x <= get_max_x() - 30; x += 20)
                draw_line(x, 30, x, get_max_y() - 30);
        for (int y = 30; y <= get_max_y() - 30; y += 20)
                draw_line(30, y, get_max_x() - 30, y);
   }

   };*/

int main() {
        // Make a window and start the application
        //std::make_shared<GridWindow>(600, 400)->run();
        DisjointSet newSet(13);
        newSet.unionSet(5, 6);
        newSet.unionSet(7, 1);
        newSet.unionSet(0, 5);
        newSet.unionSet(4, 2);
        newSet.unionSet(4, 5);
        newSet.unionSet(7, 4);
        newSet.unionSet(10, 8);
        newSet.unionSet(8, 10);
        newSet.print();
        std::cout << newSet.find(7) << '\n';
}
