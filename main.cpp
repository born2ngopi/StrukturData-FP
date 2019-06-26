#include <iostream>
#include "route.h"
#include "config.h" 
    
int main(){
  Route::init();

mainMenu:
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
    
    Route::Barista();
    goto mainMenu;
    
  }else if(val==2){
    Route::Kasir();
    goto mainMenu;

  }else if(val==3){
    Route::Pelanggan();
    goto mainMenu;
  }
}