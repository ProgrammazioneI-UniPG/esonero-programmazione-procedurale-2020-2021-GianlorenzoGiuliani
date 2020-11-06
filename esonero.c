#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(){
  char str1[128], str2[128], out[128], strrand[128], dec[128];
  int sc, sc2, i, lun1, lun2=0;
  time_t t;
  srand((unsigned) time(&t));
  printf("Cifratore con operazione XOR\ninserisci stringa (max 128 caratteri)\n");
  fgets(str1, 128, stdin);
  fflush(stdin);
  lun1=strlen(str1);
  printf("la stringa è %s\n", str1);

  printf("come procedere?\n(1) inserisci chiave manualmente\n(2) genera chiave casuale\n"); //menu
  scanf("%d", &sc);
  fflush(stdin);
  switch(sc){
    case 1: //scelta 1
      printf("scelta uno\n");
      printf("inserisci chiave (lunghezza superiore alla stringa) ");
      fgets(str2, 128, stdin);
      lun2=strlen(str2);
      while(lun2<lun1){
        printf("dimensioni chiave non valida, inserisci chiave di lunghezza superiore alla stringa ");
        fgets(str2, 128, stdin);
        lun2=strlen(str2);
      }
      for(i=0;i<lun1;i++){
         out[i] = str1[i] ^ str2[i];
      }
      printf("la stringa cifrata è %s\n",out);
      for(i=0;i<lun1;i++){
         dec[i] = out[i] ^ str2[i];
      }
      printf("la stringa decifrata è %s",dec);
      break;

    case 2: //scelta 2
      printf("scelta due\n");
      for (i=0;i<lun1;i++){
        strrand[i]=rand()%128;
      }
      printf("la tua chiave è %s\n",strrand);
      for(i=0;i<lun1;i++){
         out[i] = str1[i] ^ strrand[i];
      }
      printf("la stringa cifrata è %s",out);
      for(i=0;i<lun1;i++){
         dec[i] = out[i] ^ strrand[i];
      }
      printf("la stringa decifrata è %s\n",dec);
      break;

    default: //scelta default
      printf("inserisci 1 o 2\n");
      break;
    }
  return 0;
}
