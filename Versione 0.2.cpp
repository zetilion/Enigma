#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
using namespace std;
string mess;
//-------------------------//
void cesare(string,int l_m){  //Kozak criptagio che funge
  int chiave;
  string risp;
  string t=mess; //Stringa di appoggio
  cout<<"Inserisci la chiave di criptaggio"<<endl;
  cin>>chiave;  
  for(int i=0; i<l_m;i++){
  	if(isalpha(mess[i])){
  		for(int j=0;j<chiave;j++){
        
  			if (t[i] == 'z'){
                    t[i] = 'a'; 
                }
          
                else if (t[i] == 'Z'){
                    t[i] = 'A'; 
                }
                  
                else{
                    t[i]++; 
                }
        
}
}
}
  
    cout<<t;     //Mess criptato

  //----Decriptagio---//
cout<<"Vuoi decriptare il messaggio"<<endl ;
    cin>>risp;
    if(risp=="si"){
    for(int i=0; i<l_m;i++){
  	if(isalpha(mess[i])){
  		for(int j=0;j<chiave;j++){
        
  			if (t[i] == 'a'){
                    t[i] = 'z'; 
                }
          
                else if (t[i] == 'A'){
                    t[i] = 'z'; 
                }
                  
                else{
                    t[i]--; 
                }
}
}
}
    cout<<t;
}
}

//-------------------------//
void polibio(string, int lung){
 char M[5][5];  //Pantano
  string alfabeto;
  alfabeto={"abcdefghiklmnopqrstuvwxyz"};
  string mssg;
  int lung_alf=alfabeto.size();
 for(int i=0; i<5; i++){
 for(int j=0; j<5; j++){
 for(int k=0; k<lung_alf; k++){
   alfabeto[k]=M[i][j];
 }}}
 for(int i=0; i<5; i++){
 for(int j=0; j<5; j++){
 for(int k=0; k<mssg.size(); k++){
   do{
     if(mssg[k]=M[i][j]){
       cout<<i<<" "<<j<<" ";
     } else{
       i++;
       if(i=4){
         j++;
         i-4;
       }
     }
   }while(mssg[k]!=M[i][j]);
 }}}
}//chiusura fun.
//-------------------------//
void vigenere(string M){  //Kevin
string chiave;

    cout<<"inserire la chiave necessaria per criptare il messaggio:";cin>>chiave;
  //conversione in lettere maiuscole
  int j= chiave.length();
  int v=0;
  while(v<j) {
  if((chiave[v]>='a')&&(chiave[v]<='z')){
  chiave[v]=chiave[v]-'a'+'A'; 
  }
  v++;
    }

 j= M.length();
   v=0;
  while(v<j) {
  if((M[v]>='a')&&(M[v]<='z')){
  M[v]=M[v]-'a'+'A'; 
  }
  v++;
    }
//___________________________________________

  char KeyTab[25] , WordTab[25];    
  char VigTab[25]; char s='A';
    
  for(int i=0; i<25; i++){
    
    VigTab[i]=s;
    s+=1;
  }
for( i = 0; i < ; i++){ //cifra la frase
	VigTab[i] = Vigtab[i] + 3;
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