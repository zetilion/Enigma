#include <cstdlib>
#include <bits/stdc++.h>
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;
string mess;
void menu();
void sec_pagina();
int MASTER;

void cesare(string, int l_m) { 
  int chiave;
  string risp;
  string t = mess; 

  cout << "Inserisci la chiave di criptaggio:";
  cin >> chiave;
  cout << endl;
  for (int i = 0; i < l_m; i++) {
    if (isalpha(mess[i])) {
      for (int j = 0; j < chiave; j++) {

        if (t[i] == 'z') {
          t[i] = 'a';
        }

        else if (t[i] == 'Z') {
          t[i] = 'A';
        }

        else {
          t[i]++;
        }
      }
    }
  }
  cout << "Il messaggio criptato tramite cesare e':" << t;
  cout << endl;
}

void decriptaggio_cesare() {
  int chiave;
  int l_m;
  cout << "Inserisci il messaggio criptato:";
  cin >> mess;
  cout << endl;
  cout << "Inserisci la chiave che e stata utilizzata:";
  cin >> chiave;
  cout << endl;
  l_m = mess.size();
  string t = mess;
  for (int i = 0; i < l_m; i++) {
    if (isalpha(mess[i])) {
      for (int j = 0; j < chiave; j++) {

        if (t[i] == 'a') {
          t[i] = 'z';
        }

        else if (t[i] == 'A') {
          t[i] = 'z';
        }

        else {
          t[i]--;
        }
      }
    }
  }
  cout << "Il messaggio decriptato tramite cesare e':" << t;
  cout << endl;
}

void polibio(string frs) { // Pantano/tarricone

  char poltab[5][5];
  char s = 'a';
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      poltab[i][j] = s;
      s++;
    }
  }
  for (int i = 0; i < frs.length(); i++) {
    if (frs[i] == 'z') {
      int n = i;
      char replace = 'y';
      frs[i] = replace;
    }
  }
  int a;
  a = frs.length();
  int k = 0;
  cout << "Il messaggio criptato tramite polbiio e':";
  do {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (frs[k] == poltab[i][j]) {
          cout << i << " " << j << " ";
        }
      }
    }
    k++;

  } while (k < a);

} // chiusura fun.

void Criptaggio_Vigenere(string M) { // Kevin

  string Key;
  int X, Y, Z;

  cout << "Inserire una parola che verra utilizzata come chiave:";
  cin >> Key;
  cout<<endl;
  Z = M.length();
  if (Key.length() < M.length()) {
    Key = Key + Key;
  }

  // conversione in lettere maiuscole
  int j = Key.length();
  int v = 0;
  while (v < j) {
    if ((Key[v] >= 'a') && (Key[v] <= 'z')) {
      Key[v] = Key[v] - 'a' + 'A';
    }
    v++;
  }

  j = M.length();
  v = 0;
  while (v < j) {
    if ((M[v] >= 'a') && (M[v] <= 'z')) {
      M[v] = M[v] - 'a' + 'A';
    }
    v++;
  }

  int t = 26;
  char VigTab[t]; // alfabeto

  char s = 'A';

  for (int i = 0; i < t; i++) {
    VigTab[i] = s;
    s += 1;
  }

  for (int D = 0; D < M.length(); D++) {
    for (int a = 0; a < t; a++) {
      if (Key[D] == VigTab[a]) {
        X = a;
      }
    }
    M[D] += X;

    if (M[D] > 90) {
      M[D] = (M[D] % 90) + 64;
    }
  }

  cout << "Il messaggio criptato tramite vigenere e':" << M;
}

void decriptaggio_polibio() {
  char poltab[5][5];
  char s = 'a';
  string scelta;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      poltab[i][j] = s;
      s++;
    }
  }
  int i, j, k;
  char text[100];
  cout << "Da quanti caratteri e' composta la parola o frase?:";
  cin >> k;
  cout << endl;
  cout << "  0 1 2 3 4 ";
  cout << endl;
  for (int t = 0; t < 5; t++) {
    cout << t << " ";
    for (int T = 0; T < 5; T++) {

      cout << poltab[t][T] << " ";
    }

    cout << endl;
  }
  cout << endl;
  cout << "Le lettere 'Y'e'Z'";
  cout << endl << endl;
  cout << "Inserisci una coordianta alla volta divise da uno spazio:";
  for (int q = 0; q < k; q++) {
    cin >> i >> j;
    if (i == 4 && j == 4) {
      text[q] = 'z';
    } else {
      text[q] = poltab[i][j];
    }
  }
  cout << "La paroal decriptata tramite Polibio e':" << text;
  cout << endl;
  cout << "La parola decriptata e corretta?:";
  cin >> scelta;
  cout << endl;
  if (scelta == "no") {

    for (int q = 0; q < k; q++) {
      if (text[q] == 'z') {
        text[q] = 'y';
        cout << text;
      }
    }
  }
}

void Decriptaggio_Vigenere() {
  string m;
  cout << "Inserisci il messaggio criptato:";
  cin >> m;
  cout << endl;
  int T = 26;
  int S = 'A';
  string key;
  int x;
  char KeyTab[T];
  char s = 'A';

  for (int i = 0; i < T; i++) {
    KeyTab[i] = s;
    s += 1;
  }

  cout << "Inserire la parola che e stata utilizzata come chiave:";
  cin >> key;
  cout<<endl;

  if (key.length() < m.length()) {
    key = key + key;
  }

  int j = key.length();
  int v = 0;
  while (v < j) {
    if ((key[v] >= 'a') && (key[v] <= 'z')) {
      key[v] = key[v] - 'a' + 'A';
    }
    v++;
  }

  j = m.length();
  v = 0;
  while (v < j) {
    if ((m[v] >= 'a') && (m[v] <= 'z')) {
      m[v] = m[v] - 'a' + 'A';
    }
    v++;
  }

  for (int D = 0; D < m.length(); D++) {
    for (int a = 0; a < T; a++) {
      if (key[D] == KeyTab[a]) {
        x = a;
      }
    }
    m[D] -= x;

    if (m[D] < 65) {
      m[D] = 90 - (64 - m[D]);
    }
  }
  cout << "Il messaggio decriptato tramite vigenere e':" << m;
}

void menu() {
  int scelta;
  int lunghezza_mess;
  cout << "=================================================\n";
  cout << "|                   ENIGMA                      |\n";
  cout << "=================================================\n";
  cout << "|                 Cifrari:                      |\n";
  cout << "|                 1. Cesare                     |\n";
  cout << "|                 2. Vigenere                   |\n";
  cout << "|                 3. Polibio                    |\n";
  cout << "|                                               |\n";
  cout << "|                 4. Prossima pagina            |\n";
  cout << "|                 5. Esci dal programma         |\n";
  cout << "|                                               |\n";
  cout << "|                 Pagina 1 di 2                 |\n";
  cout << "=================================================\n";
  cout << "Inserisci il numero della tua scelta:";
  
  cin >> scelta;
  while(scelta< 1 or scelta>5){
  cout<<"opzione non valida, reinserire la scelta:"; cin>>scelta;
  }
  
 if(scelta==5){
 	MASTER=scelta;
}
else  {

  cout << endl;
  if (scelta == 4) {
    goto seconda_pagina;
  }
  cout << "Inserisci messaggio da criptare:";
  cin >> mess;
  cout << endl;
  lunghezza_mess = mess.size();
  int scelta1;
  switch (scelta) {
  case 1:
    cesare(mess, lunghezza_mess);
    break;
  case 2:
    Criptaggio_Vigenere(mess);
    break;
  case 3:
    polibio(mess);
    break;
  case 4:
  seconda_pagina:
    sec_pagina();

  }
}
}

void sec_pagina() {
  int scelta;
  int lunghezza_mess;
  cout << "=================================================\n";
  cout << "|                   ENIGMA                      |\n";
  cout << "=================================================\n";
  cout << "|                 Decriptazioni:                |\n";
  cout << "|                 1. Cesare                     |\n";
  cout << "|                 2. Vigenere                   |\n";
  cout << "|                 3. Polibio                    |\n";
  cout << "|                                               |\n";
  cout << "|                 4. Pagina precedente          |\n";
  cout << "|                                               |\n";
  cout << "|                 Pagina 2 di 2                 |\n";
  cout << "=================================================\n";
  
  cout << "Inserisci il numero della tua scelta:";
  cin >> scelta;
  while(scelta< 1 or scelta>4){
  cout<<"opzione non valida, reinserire la scelta:"; cin>>scelta;
  }


  
  cout << endl;
  if (scelta == 4) {
    goto prima_pagina;
  }
  switch (scelta) {
  case 1:
    decriptaggio_cesare();
    break;
  case 2:
    Decriptaggio_Vigenere();
    break;
  case 3:
    decriptaggio_polibio();
    break;
  case 4:
  prima_pagina:
    menu();
    break;
  }
}

int main() {
bool f=true; char Choose;


cout<<":::::::::: ::::    ::: ::::::::::: ::::::::  ::::    ::::      :::     \n";
cout<<":+:        :+:+:   :+:     :+:    :+:    :+: +:+:+: :+:+:+   :+: :+:   \n";
cout<<"+:+        :+:+:+  +:+     +:+    +:+        +:+ +:+:+ +:+  +:+   +:+  \n";
cout<<"+#++:++#   +#+ +:+ +#+     +#+    :#:        +#+  +:+  +#+ +#++:++#++: \n";
cout<<"+#+        +#+  +#+#+#     +#+    +#+   +#+# +#+       +#+ +#+     +#+ \n";
cout<<"#+#        #+#   #+#+#     #+#    #+#    #+# #+#       #+# #+#     #+# \n";
cout<<"########## ###    #### ########### ########  ###       ### ###     ### Versione 1.0\n";








  do{
  menu();
  cout<<endl;
  if(MASTER==5){
  	Choose='n';
  }
  else{
  
cout<<"\n ======================================\n";
 cout<<" |vuole provare altri criptaggi? y/n  |\n "; 
cout<<"======================================\n";

cin>>Choose; 
}

  }while(Choose=='y');
  return 0;
}
