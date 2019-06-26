//===pr
//indexing array struct
//
//
// #ifndef FUNC_H
// #define FUNC_H


#include <iostream>
#include "config.h"
#include "route.h"
#define MAX 10

struct config::Waiting wt[10];
struct config::Coffee cf[10];

int k =0;
//=========================
//fungsi ini dugunakan untuk memvalidasi variabel tail di struct waiting
//index 0 digunakan agar wt(struct Waiting) menjadi static 
bool full(){
 return wt[0].tail == MAX;
}

bool empty(){
  return wt[0].tail == 0;
}

void Route::init(){
  cf[0].name = "moka";cf[0].price = 10000;
  cf[1].name = "kapucino";cf[1].price = 15000;
  cf[2].name = "torabika";cf[2].price = 3000;
  cf[3].name = "whitecoffee";cf[3].price = 4000;
  cf[4].name = "goodday";cf[4].price = 2000;
  cf[5].name = "original";::cf[5].price = 4000;
  cf[6].name = "arabika";cf[6].price = 15000;
  cf[7].name ="robusta";cf[7].price = 20000;

}
//==========================


//bagian ini dipanggil di file kasir.cpp
//================ Start =====================
//
//
//
void Route::Search_Name(){
  
  int posisi;
  bool ketemu;
  std::string name;
  char Y;

  std::cout << "masukkan nama kopi yang dicari = ";std::cin>>name;
  
  ketemu=0;
  auto len = sizeof(cf)/sizeof(cf[0]);
  for (int i=0;i<len;i++){
    if (cf[i].name==name){
      ketemu = true;
      posisi = i;
      i=len;
    }
  }
  if (ketemu){
    std::cout<<"nama kopi yang dicari\n";
    std::cout<<"nama : "<<cf[posisi].name<<" harga : "<<cf[posisi].price<<std::endl;
    std::cout<<"\ningin melanjutkan transaksi?(y) ";std::cin>>Y;
    std::system("clear");
  }else{
    std::cout<<"kopi yang anda cari tidak ditemukan"<<std::endl;
    std::cout<<"\ningin melanjutkan transaksi?(y) ";std::cin>>Y;
    std::system("clear");
  }

}


void Route::Price(){
  //fungsi ini digunakan untuk menampilkan data di kasir
  //1. nama pemesan
  //2. nama kopi yang dipesan
  //3. jumlah yang dipesan
  //4. total harga
  //5. jumlah uang yang dibayar
  //6. jumlah uang kembali
  //
  std::string name;
  int money;
  std::cout<<"masukkan nama pemesan : ";std::cin>>name;
  std::system("clear");

  //lalu validasi apakah nama ada dalam daftar
  auto plan = sizeof(wt)/sizeof(wt[0]);
  // std::cout<<name<<std::endl;
  for (auto i=0;i<plan;i++){
    if (name == wt[i].py.od.name){//validasi nama
      
      std::cout<<"nama pemesan          = "<<wt[i].py.od.name<<std::endl;
      std::cout<<"kopi yang dipesan     = "<<wt[i].py.od.kopi<<std::endl;
      std::cout<<"jumlah pesanan        = "<<wt[i].py.od.totalOrder<<std::endl;
      std::cout<<"total pembayaran      = "<<wt[i].py.totalPayment<<std::endl;

      std::cout<<"uang yang dibayarkan  = ";std::cin>>money;

      //validasi apakah uang lebih atau kurang
      if (money >= wt[i].py.totalPayment){
        std::cout<<"jumlah uang kembalian = "<<money - wt[i].py.totalPayment<<std::endl;
      }else{
        std::cout<<"uang anda kurang"<<std::endl;
      }
      char Y;
      std::cout<<"ingin transaksi lagi?(y)";std::cin>>Y;
      std::system("clear");
    }
  }
}
//
//================ endl ======================

//bagian ini dipanggil di file barista.cpp
//================ Start =====================
//
//

void Route::Delete_Order(){
  if (!empty()){
    std::cout<<"antrian "<<wt[0].py.od.name<<" dihapus\n";
    for(auto i=wt[0].head;i<wt[0].tail;i++){
      wt[i].py.od=wt[i+1].py.od;
    }
    wt[0].tail--;
  }
}

void Route::Display_Order(){
  //fungsi ini digunakan untuk menampilkan 
  //nilai yang tersimpan di struct wt[].py.od
  auto len = sizeof(wt)/sizeof(wt[0]);
  //len => panjang array struct
  for(auto i=0;i<len;i++){
    std::cout<<"nama pelanggan : "<<wt[i].py.od.name<<std::endl;
    std::cout<<"kopi pesanan : "<<wt[i].py.od.kopi<<std::endl;
    std::cout<<"jumlah : "<<wt[i].py.od.totalOrder<<std::endl;
  }
  char Y;
  std::cout<<std::endl<<"lanjut transaksi?(y) ";std::cin>>Y;
}



void Route::Add(){
  //menambah daftar kopi yang tersedia
  //penambahan hanya dapat dilakukan oleh barista
  //hasil dari penambahan akan 
  //disimpan dalam struct coffee di file config.h
  char plh;
  
  do{
    std::cout<<"name coffee : ";cf[0].name;
    std::cout<<"price       : ";cf[0].price;

    std::cout<<"ingin menambah lagi ?(y/n)";std::cin>>plh;
  }while(plh == 'y');
}

void Payment(){
  //fungsi ini digunakan untuk mencari
  //total harga yang akan dibayar
  //dimana harus mengakses 2 struct
  //coffee.name & payment.orderlist.kopi

  auto plan = sizeof(cf)/sizeof(cf[0]);
  //plan => len / kapasitas array
  int i,k; //sementara
  for (auto i=0;i<plan;i++){
    if (wt[k].py.od.kopi == cf[i].name){
      wt[k].py.totalPayment = cf[i].price * wt[k].py.od.totalOrder;
    }
  }
}

//==================end=================================
void enQueue(){
  if (!full()){
    wt[wt[0].tail].py.od.name = wt[k].py.od.name;
    wt[0].tail++;
  }else{
    std::cout<<"error"<<std::endl;
  }
}

//function ini dipanggil dalam file pelanggan.cpp
//======================== start ==========================
void Route::Display_Coffee(){
  //
  //======= sorting value of struct coffee
  struct config::Coffee temp;
  //temp dibuat untuk menyimpan perubahan sementara,
  //dimana perubahan diambil dari nama alias
  // sebelumnya (cf[]), karna kembalian data berupa string name & int price 
  auto len = sizeof(cf)/sizeof(cf[0]);
  //len => panjang array struct coffee
  for(auto i=1;i<=len;i++){
    for(auto j=0;j<len-i;j++){
      if(cf[j].price > cf[j+1].price){
        temp = cf[j+1];
        cf[j+1] = cf[j];
        cf[j] = temp;
      }
    }
  }

  //====end sorting======
  for (auto i=0;i<len;i++){
    std::cout<<"nama : "<<cf[i].name<<"\tharga : "<<cf[i].price;
    std::cout<<std::endl;
  } 
  char Y;
  std::cout<<std::endl<<"lanjut transaksi?(y) ";std::cin>>Y;
}

void Route::Order(){
  char plh; 
  do{
    std::cout<<"nama pemesan : ";std::cin>>wt[k].py.od.name;
    std::cout<<"nama kopi : ";std::cin>>wt[k].py.od.kopi;
    std::cout<<"jumlah : ";std::cin>>wt[k].py.od.totalOrder;
    Payment();
    std::cout<<std::endl;
    enQueue();
    std::cout<<std::endl<<"apakah ingin memesan lagi? (y/n)";std::cin>>plh;
  }while(plh=='y');
}

//======================== end ============================

//#endif
