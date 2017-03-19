//
//  main.cpp
//  DisjointSet
//
//  Created by Thomas Manu on 3/13/17.
//  Copyright © 2017 Thomas Manu and Adams Bala. All rights reserved.
//

#include "DisjointSet.hpp"
#include <memory>
#include "sgl.hpp"
#include <time.h>
 
 using namespace sgl;
 
 class GridWindow : public Window {
 public:
     // Constructor makes a width x height window
     GridWindow(double width, double height) :
        Window("Grid", 0, width, 0, height) {
        }
 
     // The paint method simply draws a grid
     void paint() override {
         /*set_color(BLACK);
         for (int x = 30; x <= get_max_x() - 30; x += 20) {
             draw_line(x, 30, x, get_max_y() - 30);
         }
         for (int y = 30; y <= get_max_y() - 30; y += 20) {
             draw_line(30, y, get_max_x() - 30, y);
         }
         set_color(WHITE);
         draw_line(30, get_max_y() - 50, 30, get_max_y() - 30);
         draw_line(get_max_x() - 30, 30, get_max_x() - 30, 50);
     }*/
         
         DisjointSet set(16);
         set_color(BLACK);
         for (int x = 100; x <= get_max_x() - 100; x += 100) {
             draw_line(x, 100, x, get_max_y() - 100);
         }
         for (int y = 100; y <= get_max_y() - 100; y += 100) {
             draw_line(100, y, get_max_x() - 100, y);
         }
         set_color(WHITE);
         draw_line(100, get_max_y() - 200, 100, get_max_y() - 100);
         draw_line(get_max_x() - 100, 100, get_max_x() - 100, 200);
         srand(time(NULL));
         while (set.cardinality() > 1) {
             int number = random(0, 15);
             int number2 = random(0, 15);
             std::cout << number << number2 << " ";
             if (number == (number2 + 1) || (number + 1) == number2) {
                 if ((number % 4) != 0 && (number2 % 4) != 0 && (number % 4) != 3 && (number2 % 4) != 3) {
                     if (set.findSet(number) != set.findSet(number2)) {
                         set.unionSet(number, number2);
                         std::cout << "  Set: ";
                         set.print();
                     }
                 }
                 else if (((number % 4) == 0 || (number2 % 4) == 0) && ((number % 4) == 1 || (number2 % 4) == 1)) {
                     if (set.findSet(number) != set.findSet(number2)) {
                         set.unionSet(number, number2);
                         std::cout << "  Set: ";
                         set.print();
                     }
                 }
                 else if (((number % 4) == 2 || (number2 % 4) == 2) && ((number % 4) == 3 || (number2 % 4) == 3)) {
                     if (set.findSet(number) != set.findSet(number2)) {
                         set.unionSet(number, number2);
                         std::cout << "  Set: ";
                         set.print();
                     }
                 }
             }
             else if (number == (number2 + 4) || (number + 4) == number2) {
                 if (set.findSet(number) != set.findSet(number2)) {
                     set.unionSet(number, number2);
                     
                 }
             }
         }
     }
 };

int main() {
    std::make_shared<GridWindow>(600, 600)->run();
}
