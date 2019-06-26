#ifndef ROUTE_H
#define ROUTE_H
#include "config.h"
//#include "func.h"

namespace Route{
    void Add();
    void Delete_Order();
    //void Payment();
    void Display_Order();
    //pelanggan
    void Display_Coffee();
    void Search_Name();
    void Order();
    //kasir
    void Price();
    //function
    // void Barista();
    // void Kasir();
    // void Pelanggan();
    void init();
  bool Barista();
  bool Kasir();
  bool Pelanggan();
}
#endif
