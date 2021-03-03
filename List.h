/*
  Name: List.h
  Copyright: (C) Marzo  de 2013
  Author:  Jose Ferdel Dorantes Lara
  Date: 30/05/13 09:03
  Description: ----

Copyright (C) 2013  Jose Ferdel Dorantes Lara

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/
/*
 List <Tipo de dato> a;
*/
#include <iostream>
using namespace std;
template <class T>
class List
{
struct nodo{T nrolist;nodo *sgtelist;};
int lim;
public:
typedef  nodo *TList;
TList list;
List(){list = NULL;lim=0;}
unsigned short size()
{
return lim;
}
void add(T valor)
{
    TList t, q = new(struct nodo);
	lim++;
    q->nrolist  = valor;
    q->sgtelist = NULL;
	if(list==NULL)
    {list = q;}
    else
    {
    t = list;
        while(t->sgtelist!=NULL){t = t->sgtelist;}
    t->sgtelist = q;
    }
}
void showall()
{
TList q = list;
     unsigned short i = 0;
     while(q != NULL)
     {
          cout <<"\n["<<i<<","<<q->nrolist<<"]";
          q = q->sgtelist;
          i++;
     }
}
T show(unsigned short pos)
{
TList q = list;
   unsigned short i =0;
     while(q != NULL)
     {
          if(i==pos){return q->nrolist;}
          q = q->sgtelist;
          i++;
     }
}
signed short search(T valor)
{
   TList q = list;
   unsigned short i = 0;
while(q!=NULL)
    {if(q->nrolist==valor)
        {return i-1;}
        q = q->sgtelist;i++;}
   return -1;
}
void remove(T valor)// x q 2 pops? @.@
{
    TList p, ant;
    p = list;
	lim--;
    if(list!=NULL)
    {
        while(p!=NULL)
        {
            if(p->nrolist==valor)
            {
                if(p==list){list = list->sgtelist;}
                else{ant->sgtelist = p->sgtelist;}
                delete(p);
                return;
            }
            ant = p;
            p = p->sgtelist;
        }
    }
    else
        {cout<<" list vacia..!";}
}
~List()
	{
	delete list;
	}
};
