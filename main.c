#include <stdio.h>
int charDiziBoyutuBul(char dizi[]){
    int i=0;
    while(dizi[i]!='\0'){
        i++;
    }
    return i;
}

int main()
{
    char D[5]={'a','e','r','k','s'};
    char kelimeler[][6]={"asker","serak","kars","kase","sera","akse","ark","kes","kas","ser","sek","kar"};
    char kelime[20];
    int kelimelerListeBoyutu= sizeof(kelimeler)/sizeof(kelimeler[0]);
    int i,j;

    int anlikPuan=0;
    printf("Kullanabileceginiz Harfler: a e r s k \n");
    printf("Tahmininizi Giriniz: ");
    scanf("%s",kelime);
    int bulunanKelimler[kelimelerListeBoyutu];
        for(i=0;i<kelimelerListeBoyutu;i++)
            bulunanKelimler[i]=0;

    while(kelime[0]!='0'){
        int d_check;
        int kelimeBoyutu=charDiziBoyutuBul(kelime);
        int DBoyutu=charDiziBoyutuBul(D);

        int harfKontrol[DBoyutu];

        for(int i=0;i<DBoyutu;i++)
            harfKontrol[i]=0;

        int d_counter=0;
        int harf_hatasi=0;
        for(i=0;i<kelimeBoyutu;i++){ // harf kontrolu yapiliyor
            for(j=0;j<DBoyutu;j++){
               if(kelime[i]==D[j]){
                    if(harfKontrol[j]==1)
                    {
                        anlikPuan -=kelimeBoyutu;
                        harf_hatasi=1;
                        printf("Hatali harf kullanimi, Puaniniz: -%d \n",kelimeBoyutu);

                    }else{
                        d_counter++;
                        harfKontrol[j]=1;
                    }
                    break;
                }
            }
       }
        if(kelimeBoyutu>=2){
            if(d_counter==kelimeBoyutu){ // kelime kontrolü yapiliyor
                i=0;
                j=0;

                int ayniMi=-1;
                int secilenKelimeIndex;
                for(i=0;i<kelimelerListeBoyutu;i++){
                    if(ayniMi!=1){
                    secilenKelimeIndex=i;
                    ayniMi=-1;
                    int seciliKelimeBoyutu=0;
                    j=0;
                    while(kelimeler[i][j]!='\0'){
                        seciliKelimeBoyutu++;
                        j++;
                    }

                    if(kelimeBoyutu == seciliKelimeBoyutu){
                        for(j=0;j<kelimeBoyutu;j++){
                            if(kelime[j]!=kelimeler[i][j]){
                                ayniMi=0;
                            }

                            if(kelime[j]==kelimeler[i][j] && ayniMi!=0){
                                ayniMi=1;
                            }
                        }
                    }
                    }
                }
                if(ayniMi==1){
                        if(bulunanKelimler[secilenKelimeIndex]!=1){
                            bulunanKelimler[secilenKelimeIndex]=1;
                            anlikPuan+=kelimeBoyutu;
                            printf("puaniniz: +%d\n",kelimeBoyutu);
                        }else{
                            anlikPuan-=kelimeBoyutu;
                            printf("ayni kelimeyi yazdiniz ! puaniniz: -%d\n",kelimeBoyutu);
                        }
                }else{
                        anlikPuan-=kelimeBoyutu;
                        printf("puaniniz: -%d\n",kelimeBoyutu);
                }
            }else if(harf_hatasi==0){
                 anlikPuan-=kelimeBoyutu;
                 printf("puaniniz: -%d\n",kelimeBoyutu);
            }
        }
        else{
             printf("Minimum 2 harf giriniz! \n");
        }



        printf("Tahmininizi Giriniz: ");
        scanf("%s",kelime);
    }
    printf("Oyun bitmistir. Tebrikler! Toplam Puan: %d",anlikPuan);
    return 0;
}
