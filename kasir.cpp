//this is file kasir

#include <iostream>
#include "route.h"

bool Route::Kasir(){
  int a;
  do{
    std::cout<<"===kasir==="<<std::endl;
    std::cout<<"1. pembayaran"<<std::endl;
    std::cout<<"2. kembali"<<std::endl;
    std::cout<<std::endl<<"masukkan pilihan";std::cin>>a;
    if (a==1){
      Route::Price();
      std::cout<<std::endl;
    }
  }while(a==2);
  return true;
}

