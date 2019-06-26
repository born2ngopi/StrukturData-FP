#include <iostream>
#include "route.h"
#include "config.h" 
#include <cstdlib>
    
int main(){
  Route::init();

mainMenu:
  std::system("clear");
  std::cout<<"|===================|"<<std::endl;
  std::cout<<"|       KOPIIN      |"<<std::endl;
  std::cout<<"|===================|"<<std::endl;
  std::cout<<std::endl;
  std::cout<<"1. barista"<<std::endl;
  std::cout<<"2. kasir"<<std::endl;
  std::cout<<"3. order"<<std::endl;
  std::cout<<"4. exit"<<std::endl;
  int val;
  std::cin>>val;

  if (val == 1){
    std::system("clear");
    Route::Barista();
    goto mainMenu;
    
  }else if(val==2){
    std::system("clear");
    Route::Kasir();
    goto mainMenu;

  }else if(val==3){
    std::system("clear");
    Route::Pelanggan();
    goto mainMenu;
  }
}