//this is file pelanggan
//serching
#include <iostream>
#include "route.h"

bool Route::Pelanggan(){
    int val;
    do{
    std::cout<<"====pelanggan====="<<std::endl;
    std::cout<<"1. lihat daftar kopi"<<std::endl;
    std::cout<<"2. search nama kopi"<<std::endl;
    std::cout<<"3. pesan"<<std::endl;
    std::cout<<"4. exit"<<std::endl;
    std::cout<<std::endl<<"masukkan pilihan";std::cin>>val;

    if (val==1){
      std::system("clear");
      Route::Display_Coffee();
      std::system("clear");
      std::cout<<std::endl;
    }else if(val==2){

    }else if(val==3){
      std::system("clear");
      Route::Order();
      std::system("clear");
      std::cout<<std::endl;
    }
  }while(val!=4);

}
