//this is file config
//digunakan untuk menyimpan data
#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>

namespace config{
  struct Coffee{
    std::string name;
    int price;
  };

  struct OrderList{
    std::string name;
    std::string kopi;
    int totalOrder;
  };

  struct Payment{
    struct OrderList od;
    int totalPayment;
  };

  struct Waiting{
    struct Payment py;
    int head,tail;
  };
};
#endif
