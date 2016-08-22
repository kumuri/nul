#include <stdio.h>
#include <stdlib.h>


float reshaem(char *un, char *uk)
{
  char *coxr = un;
  double chislo[100] = {0};
  char znak[100]={0};
  int i = 1;
  int j;
  if(*un == '-') {znak[0] = '-'; un++;} else znak[0] = '+';
  chislo[0] = atof(un);
  
  while(un < uk)
  {
     //printf("%c", *un);
     //un++;
    
    if((*un == '*') || (*un == '/') || (*un == '+') || (*un == '-'))
    {
      znak[i] = *un;
      un++;
      chislo[i] = atof(un);
      i++;
      
      while( (*un != '*') && (*un != '/') && (*un != '+') && (*un != '-')   && (un<uk))
      {
	un++;
      }
      
    }
    else un++;
    
    //un++;
  
    
  }
  

  //un = coxr;
  
  double rez=0;
  
  //умножение-деление
  int k = 0;
  for(; k < i; k++)
  {
    
      if(znak[k] == '/')
      {
	 chislo[k] = chislo[k-1] / chislo[k];
	 znak[k] = znak[k-1];
	 znak[k-1] = chislo[k-1] = 0;
      }
      if(znak[k] == '*')
      {
	 chislo[k] = chislo[k] * chislo[k-1];
	 znak[k] = znak[k-1];
	 znak[k-1] = chislo[k-1] = 0;
      }

  }
  
  int l = 0;
  while(l < i)
  {
      if(znak[l] == '+') rez+= chislo[l];
      if(znak[l] == '-') rez-= chislo[l];
      l++;
  }
  
  
  j = i;/*
  for(i = 0; i < j; i++)
  {
      printf("%i %c\n", chislo[i], znak[i]); 
  }*/
  //printf("%f\n", rez);
  char number[10];
  
  sprintf(number, "%.2f", rez);
  char *n = &number[0];
  un = coxr;
  while(un < uk)
  {
     *un = *n;
     n++;
     un++;
  }
  /*
  //*********************************************
  rez*=100;
  int cz = rez;
 
  char number[10]= {' '};
  number[0] = (rez<0) ? '-' : ' ';
  //if(cz = 0) number [0] = 0;
  cz = (cz>0) ? cz : -cz;
  int cx=0;
  int del=0;
  while(cz > 0)
  {
    
    del = cz % 10;
    cz /= 10;
    
    number[++cx] =(char)del + '0';
    
  }
  if (rez >=-1 && rez <=1) number[++cx] = '0';
  //cx--;
  int cl = 1;
  char tmp;
  for(; cx > 1; cx--)
  {
      tmp = number[cl];
      number[cl] = number[cx];
      number[cx] = tmp;
      cl++;
  }
  
  
  cx = 0;
  
  printf("num: %s, cl = %i\n", number, cl);
  number[cl+1] = number[cl];
  number[cl] = number[cl-1];
  number[cl-1] = '.';
  printf("str: %s\n", coxr);
  
  for(; cx < (uk-coxr)+1; cx++)
  {
    coxr[cx] = number[cx];    
  }
  printf("str: %s cx:%i\n", coxr, cx);
  
  *uk = ' ';
  return rez;
  //*********************************************
  
  */
  
  
}  

float funkceya(char *st)
{
  
  char *un = st+1;
  int skbk = 1;
  char *uk;
  
  while(skbk > 0 )
  {
    if(*un == '(') 
    {
     
     funkceya(un);
     *un = ' ';
    
      
    }
    if(*un == ')')
    {
      
      uk = un;
      break;
    }
    
    
    un++;
  }
  
  
  
  //*un = ' ';
  
  
  
  un = st+1;
  
  float rez = reshaem(un,uk); 
  
  
  //while(un < uk) {printf("%c", *un); un++;}
  //printf("\n");
  
  return rez;
  
  
  
}





  


int main()
{ 
  char str[100] = {0};
  str[0] = '(';
  int i = 0;
  do
  {
    scanf("%c", &str[++i]);
  }while(i < 100 && str[i] != '\n') ;
  str[i] = ')';
  for(; i-- > 0; )
  {
    str[i] = (str[i] == ',') ? '.' : str[i];
  }
  
  float z = funkceya(str);
  //printf("**%.2f**\n", z);
  printf("\n%s", &str[1]); 
  
  return 0;
}