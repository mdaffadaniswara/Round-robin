#include <stdio.h>
#include <stdlib.h>

// Muhammad Daffa Daniswara
// 13220043
// Program round robin

int main(){
 
  int i,proses,time,sisa,done=0,kuantum;
  int datang[10],eksekusi[10],temp[10];
  printf("Masukkan jumlah proses: ");
  scanf("%d",&proses);
  sisa=proses;
  for(i=0;i<proses;i++)
  {
    printf("Masukkan waktu kedatangan dan waktu eksekusi untuk Proses %d : ", i+1);
    scanf("%d",&datang[i]);
    scanf("%d",&eksekusi[i]);
    temp[i]=eksekusi[i];
  }
  printf("Masukkan waktu kuantum: ");
  scanf("%d",&kuantum);
  printf("\n\nProses\t | Turnaround Time | Waiting Time\n");
  for(time=0,i=0;sisa!=0;)
  {
    if(temp[i]<=kuantum && temp[i]>0)
    {
      time+=temp[i];
      temp[i]=0;
      done=1;
    }
    else if(temp[i]>0)
    {
      temp[i]-=kuantum;
      time+=kuantum;
    }
    if(temp[i]==0 && done==1)
    {
      sisa--;
      printf("P%d\t | \t%d\t   | \t%d\n",i+1,time-datang[i],time-datang[i]-eksekusi[i]);
      done=0;
    }
    if(i==proses-1)
      i=0;
    else if(datang[i+1]<=time)
      i++;
    else
      i=0;
  }
  printf("\nTotal waktu yang dibutuhkan= %d\n", time);
  
  return 0;
}