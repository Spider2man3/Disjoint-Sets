//  Assignment 5: DisjointSet
//
//  Created by Thomas Manu on 3/13/17.
//  Copyright © 2017 Thomas Manu and Adams Bala. All rights reserved.
//  Honor statement: We did not give or recieve unauthorized help on this assignment.

#include <memory>
#include "sgl.hpp"
#include <time.h>
//#include <cmath>
//#include <random>
 
 using namespace sgl;

class DisjointSet {
private:
    std::vector<int> sets;
    int size;
    
public:
    DisjointSet(int n) {
        sets = std::vector<int> (n, -1);
        for (int i = 0; i < n; i++) {
            sets[i] = i;
        }
        size = n;
    }

    int findSet(int i) {
        if (sets[i] == i) {
            return i;
        }
        else
            return findSet(sets[i]);
    }
    
    void unionSet(int s1, int s2) {
        int p1 = findSet(s1), p2 = findSet(s2);
        sets[p1] = p2;
        size -= 1;
    }
    
    void splitSet() {
        for (int i = 0; i < sets.size(); i++) {
            sets[i] = i;
        }
    }
    
    int cardinality() {
        return size;
    }
};

class GridWindow : public Window {
public:
     // Constructor makes a width x height window
     GridWindow(double width, double height) :
        Window("Grid", 0, width, 0, height) {
        }
 
     // The paint method simply draws a grid
     void paint() override {
         set_color(BLACK);
         for (int x = 30; x <= get_max_x() - 30; x += 20) {
             draw_line(x, 30, x, get_max_y() - 30);
         }
         for (int y = 30; y <= get_max_y() - 30; y += 20) {
             draw_line(30, y, get_max_x() - 30, y);
         }
         set_color(WHITE);
         draw_line(30, get_max_y() - 50, 30, get_max_y() - 30);
         draw_line(get_max_x() - 30, 30, get_max_x() - 30, 50);
         //set_color(RED);
         DisjointSet set(1000);
         srand(time(NULL));
         while (set.cardinality() > 1) {
             int number = rand() % 1000;
             int number2;
             int a = random(0, 3);
             if (number > 39 && number < 959) {
                 switch(a){
                    case 0:
                        number2 = (number - 40);
                        break;
                    case 1:
                        number2 = (number - 1);
                        break;
                    case 2:
                        number2 = (number + 1);
                        break;
                    case 3:
                        number2 = (number + 40);
                        break;
                }
             }
             else if (number < 40) {number2 = random(0, 40);}
             else {number2 = random(960, 999);}
             
             if (number == (number2 + 1) || (number + 1) == number2) {
                 if ((number % 40) != 0 && (number2 % 40) != 0 && (number % 40) != 39 && (number2 % 40) != 39) {
                     if (set.findSet(number) != set.findSet(number2)) {
                         set.unionSet(number, number2);
                         if (number > number2) {
                             int x = 30 + (number % 40) * 20;
                             int y = 30 + ((25 - (number + 40)/40) * 20);
                             draw_line(x, y, x, y + 20);
                         }
                         else {
                             int x = 30 + (number2 % 40) * 20;
                             int y = 30 + ((25 - (number2 + 40)/40) * 20);
                             draw_line(x, y, x, y + 20);
                         }
                     }
                 }
                 else if (((number % 40) == 0 || (number2 % 40) == 0) && ((number % 40) == 1 || (number2 % 40) == 1)) {
                     if (set.findSet(number) != set.findSet(number2)) {
                         set.unionSet(number, number2);
                         if (number > number2) {
                             int x = 30 + (number % 40) * 20;
                             int y = 30 + ((25 - (number + 40)/40) * 20);
                             draw_line(x, y, x, y + 20);
                         }
                         else {
                             int x = 30 + (number2 % 40) * 20;
                             int y = 30 + ((25 - (number2 + 40)/40) * 20);
                             draw_line(x, y, x, y + 20);
                         }
                     }
                 }
                 else if (((number % 40) == 38 || (number2 % 40) == 38) && ((number % 40) == 39 || (number2 % 40) == 39)) {
                     if (set.findSet(number) != set.findSet(number2)) {
                         set.unionSet(number, number2);
                         if (number > number2) {
                             int x = 30 + (number % 40) * 20;
                             int y = 30 + ((25 - (number + 40)/40) * 20);
                             draw_line(x, y, x, y + 20);
                         }
                         else {
                             int x = 30 + (number2 % 40) * 20;
                             int y = 30 + ((25 - (number2 + 40)/40) * 20);
                             draw_line(x, y, x, y + 20);
                         }
                     }
                 }
             }
             else if (number == (number2 + 40) || (number + 40) == number2) {
                 if (number > number2) {
                    if (set.findSet(number) != set.findSet(number2)) {
                        set.unionSet(number, number2);
                        int x = 30 + (number2 % 40) * 20;
                        int y = 30 + ((25 - (number2 + 40)/40) * 20);
                        draw_line(x, y, x + 20, y);
                     }
                 }
                 else {
                    if (set.findSet(number) != set.findSet(number2)) {
                        set.unionSet(number, number2);
                        int x = 30 + (number % 40) * 20;
                        int y = 30 + ((25 - (number + 40)/40) * 20);
                        draw_line(x, y, x + 20, y);
                     }
                 }
             }
         }
     }
 };

int main() {
    std::make_shared<GridWindow>(860, 560)->run();
}
