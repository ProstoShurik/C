/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
int deg16(unsigned char deg){
  int result=16;
  if(deg==0){
    return 1;
  }
  for(short i=1;i<deg;i++){
    result*=16;
  }
  return result;
}

int SymbolHexTranslat(char inpt_char){
    char alphabet[22]="0123456789ABCDEFabcdef";
    short summ=0;
    for(unsigned char i=0;i<22;i++){
        if(alphabet[i]==inpt_char){
            if(i>15){
                summ+=((i-6)*deg16(0));
                return summ;
            }
            else{
                summ+=((i)*deg16(0));
                return summ;
            }
            
        }
    }
    return 0;
}
int HexToDec(char input_arg[]){
    
    char len=strlen((input_arg));
    //printf("LEN %d \n",len);
    int summ=0;
    char counter=0;
    for(char y=len-2;y>=0;y--){ //len-2 это для косого степика.По хорошему должно быть len-1
      summ+=SymbolHexTranslat(input_arg[y])*deg16(counter);
        //printf("ARG %c \n",input_arg[y]);
        //printf(" SHT %d \n",SymbolHexTranslat(input_arg[y]));
        //printf(" TYC SUMM %d \n COUNTER %d \n",summ,counter);//((deg2(counter)*(arg1[y]-48)));
      counter++;
        //printf("COUNTER %d \n",counter);
  }
  return summ;
}
int main()
{
    char input[10];
    fgets(input,10,stdin);
    char c='b';
    //printf("%d",SymbolHexTranslat(c));
    //printf("INPT STR %s \n",input);
    printf("%d",HexToDec(input));
//Все эти комменты-остатки отладочной системы.Оставляю для использования в будущем.МИРОНОВ АА ИУ4-22Б

    return 0;
}




