//pr
//hapus pesanan
#include <iostream>
#include "route.h"

bool Route::Barista(){
  //function ini memanggil fungsi di file func.cpp
  //melalui route.h
  int val;
  do {
   // cout<<"1. tambah daftar kopi"<<endl;
    std::cout<<"1. lihat pesanan"<<std::endl;
    std::cout<<"2. hapus pesanan"<<std::endl;
    std::cout<<"3. kembali"<<std::endl;

    std::cout<<std::endl<<"masukkan pilihan = ";std::cin>>val;

    if (val==1){
      std::system("clear");
      Route::Display_Order();
      std::system("clear");
      std::cout<<std::endl;
    }else if(val ==2){
      std::system("clear");
      Route::Delete_Order();
      std::cout<<std::endl;
    }
  }while(val!=3);
}
