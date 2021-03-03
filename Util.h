#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#include <iostream>
#include <cstring>
#include <fstream>
#ifdef _WIN32

#include <windows.h>
#include <cstdlib>
#define sleep(x) Sleep(x);
#define cls() system("cls");
#define gotoxy(x,y) {COORD coord={0,0};coord.X=x;coord.Y=y;SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);}

#elif defined __unix__
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#define sleep(x) sleep(x);
#define cls() system("clear");
#define gotoxy(x,y){printf("33[%d;%df", y, x);fflush(stdout);}
#else
#warning Missing sleep function

#endif
using namespace std;
static int size(char ve[]){
    int v=0;
        while(ve[v]!='\0'){
        v++;
    }
    return v;
 }
static void cleanArray(char ve[],char ca='\0'){
    int limite=size(ve);
    for(auto x=0;x<limite;x++)
        ve[x]=ca;
}
template <class T>
static void showArray(T ve[],int lim,char sp[]="\0"){
    for(int x=0;x<lim;x++){
        cout<<ve[x]<<sp;
    }
}
template <class T>
void Permutaciones(T cad[],int lim, int l=0) {
   T c;
   int i, j;
    for(i = 0; i < lim-l; i++) {
      if(lim-l > 2){Permutaciones(cad,lim, l+1);}
      else {showArray(cad,lim,"   ");cout<<"\n";}
      c = cad[l];
      cad[l] = cad[l+i+1];
      cad[l+i+1] = c;
      if(l+i == lim-1) {
         for(j = l; j < lim; j++) cad[j] = cad[j+1];
         cad[lim] = 0;
      }
   }
}
class textclass{
public :
    void color(string cad,int color){
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
        cout<<cad;
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
        }
    void color(int cad,int color){
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
        cout<<cad;
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
        }
    void color(float cad,int color){
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
        cout<<cad;
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
        }
    void color(char cad,int color){
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
        cout<<cad;
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
        }
    void color(char cad[],int color){
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
        cout<<cad;
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
        }
    void operator <<(char a[]){
        cambio(a);
    }
    private: void cambio(char a[]){
        for(int x=0;x<size(a);x++){
              switch(a[x]){
   case 'ñ':cout<<"\244";break;
   case 'ó':cout<<"\242";break;
   case 'Ñ':cout<<"\245";break;
   case 'í':cout<<"\241";break;
   case 'á':cout<<"\240";break;
   case 'é':cout<<"\202";break;
   case 'É':cout<<"\220";break;
   case 'Á':cout<<"\265";break;
   case '?':cout<<char(63);break;
            default:
                cout<<a[x];
    };
        }
    }
};
static void getch(){
    //cin.get();
    cin.ignore(255, '\n');
}
static textclass text;
static void replace(string& texto,string buscar ,string rem){
  int p=texto.find(buscar);
  while(p!=-1){
    texto.replace(p,buscar.size(),rem);
    p=texto.find(buscar,p + rem.size());
  }
}
static string charTostr(char text[]){
   return string(text);
}
static void strTochar(string x,char text[]){
strcpy(text,"");
strcpy(text,x.c_str());
}
static bool fileExist(char* local){
	ifstream file(local);
	if(file.fail()){
		file.close();
		return false;
	}
	file.close();
		return true;
}
#endif // UTIL_H_INCLUDED
