#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
using namespace std;
string mess;
//-------------------------//
void cesare(string,int l_m){  //Kozak
  int chiave;
  string t; //Stringa di appoggio
  cout<<"Inserisci la chiave di criptaggio"<<endl;
  cin>>chiave;  
  for(int i=0; i<l_m;i++){
    if(isupper(mess[i])){
      t=(mess-'A'+chiave)%26+'A';  
    }else{
      t+=(mess-'a'+chiave)%26+'a'; 
    }
  }
  cout<<t;
  
}
//-------------------------//
void polibio(string, int lung){
 char M[5][5];  //Pantano
  string alfabeto={"abcdefghiklmnopqrstuvwxyz"};
  int lung_alf=alfabeto.size();
 for(int i=0; i<5; i++){
 for(int j=0; j<5; j++){
 for(int k=0; k<lung_alf; k++){
   alfabeto[k]=M[i][j];
 }
   
}
}
}
//-------------------------//
void vigenere(string A){  //Kevin
string chiave;

  int j= chiave.length();//conversione in lettere maiuscole
  int v=0;
  
  while(v<j) {
        if((chiave[v]>='a')&&(chiave[v]<='z')){
  chiave[v]=chiave[v]-'a'+'A'; 
  }
  v++;
    }

    int j= chiave.length();//conversione in lettere maiuscole
  int v=0;
  
  while(v<j) {
        if((chiave[v]>='a')&&(chiave[v]<='z')){
  chiave[v]=chiave[v]-'a'+'A'; 
  }
  v++;
    }

  cout<<"inserire la chiave necessaria per criptare il messaggio:";cin>>chiave;
  
  
}
//-------------------------//
void menu(){
  int scelta;
  int lunghezza_mess;
  cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::://";
  cout<<"MENU DI SCELTA: con quale codice di criptaggio vuoi proteggere il tuo mesaggio?"<<endl<<endl;
  cout<<"1)Criptaggio di Cesare "<<endl<<endl;
  cout<<"2)Criptaggio di Vigenere"<<endl<<endl;
  cout<<"3)Criptaggio di Polibio"<<endl<<endl;
  cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::://"<<endl;
  cin>>scelta;
  cout<<"inserisci mesaggio da criptare"<<endl;
  cin>>mess;
  lunghezza_mess=mess.size();
  switch(scelta){
    case 1: 
    cesare(mess, lunghezza_mess);
    break;
    case 2:
    vigenere(mess);
     break ;
    case 3:
    polibio(mess, lunghezza_mess);
      break;
    
  
}
}
//-------------------------//
int main(){ 
  menu();
  return 0;
}
