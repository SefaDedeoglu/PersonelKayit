#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

FILE *perDosya,*yedek;
 typedef struct {
    char isim[25];
    char TCKimlikNo[15];
    char telefon[15];
    char eposta[30];
    char adres[30];
}personel;

void KayitEkle();
void KayitListele();
void KayitDuzenle();
void KayitBulTc();
void KayitBulIsim();
void KayitSil();
void Menu();

int main(){
    setlocale(LC_ALL, "Turkish");
    Menu();
    getch();


    return(0);
}
void Menu(){
    system("RESET");
    system("color b");
    system("CLS");
    int Tercih;
    char baska;
    menu:
    printf("\t\t\t\t\t**MENU**\n");
    printf("\t\t\t\t\t1.YENI KAYIT EKLE \n");
    printf("\t\t\t\t\t2.PERSONEL KAYIT LISTESI\n");
    printf("\t\t\t\t\t3.KAYIT DUZENLEME\n");
    printf("\t\t\t\t\t4.TC KIMLIK NO ILE KAYIT BUL\n");
    printf("\t\t\t\t\t5.ISIM ILE KAYIT BUL\n");
    printf("\t\t\t\t\t6.KAYIT SIL\n");
    printf("\t\t\t\t\t7.CIKIS\n\n\n");
    printf("--->");
    scanf("%d",&Tercih);
    printf("\n\n");
    switch(Tercih){
        case 1 :{KayitEkle();break;}
        case 2 :{KayitListele();break;}
        case 3 :{KayitDuzenle();break;}
        case 4 :{KayitBulTc();break;}
        case 5 :{KayitBulIsim();break;}
        case 6 :{KayitSil();break;}
        case 7 :exit(-1);
        break;
        default:{printf("HATALI GIRIS\n\n\n");
        goto menu;
        }
    }
}
void KayitEkle(){
    system("CLS");
    system("color a");
    int yeni;
    personel *per;
    yk:
    per = (personel*) malloc(sizeof(personel));

    printf("PERSONEL ADINI GIRINIZ : \n");
    scanf("%s",per->isim);
    printf("PERSONEL TC KIMLIK NO GIRINIZ : \n");
    scanf("%s",per->TCKimlikNo);
    printf("PERSONEL TELEFON GIRINIZ : \n");
    scanf("%s",per->telefon);
    printf("PERSONEL E POSTA GIRINIZ : \n");
    scanf("%s",per->eposta);
    printf("PERSONEL ADRES GIRINIZ : \n");
    scanf("%s",per->adres);
    perDosya = fopen("Personel.txt","a");
    if(perDosya != NULL){
    fwrite(per,sizeof(personel),1,perDosya);
    fclose(perDosya);
    }
    i1:
    printf("\n\n\n\t\t\tYENI KAYIT YAPMAK ICIN -> 1 \n");
    printf("\t\t\tANA MENU ICIN -> 2 \n");
    printf("\t\t\tCIKMAK ICIN -> 3 \n");
    printf("--->");
    scanf("%d",&yeni);
    printf("\n\n");
    switch(yeni){
        case 1 :{goto yk;break;}
        case 2 :{Menu();break;}
        case 3 :exit(-1);
        break;
        default:{printf("HATALI GIRIS\n\n\n");
        goto i1;
        }
    }
}
void KayitListele(){
    system("CLS");
    system("color c");
    int yeni;
    personel *per;

    yk:
    printf("LISTE OLUSTURULUYOR\n");
    perDosya = fopen("Personel.txt","r");
    if(perDosya == NULL){
        printf("KAYITLI PERSONEL BULUNAMADI\n");
        system("PAUSE");
        goto ex;
    }

    while(!feof(perDosya)){
        per = (personel*) malloc(sizeof(personel));

        fread(per,sizeof(personel),1,perDosya);

        if(strcmp(per->TCKimlikNo,"                ")==1)
        {
            printf("PERSONEL ADI : %s\n",per->isim);
            printf("PERSONEL TC KIMLIK NO: %s\n",per->TCKimlikNo);
            printf("PERSONEL TELEFON NO : %s\n",per->telefon);
            printf("PERSONEL E POSTA : %s\n",per->eposta);
            printf("PERSONEL ADRES : %s\n\n\n",per->adres);
            }
    }
    fclose(perDosya);
    i2:
    printf("\n\n\n\t\t\tLISTEYI TEKRAR GORUNTULEMEK ICIN -> 1 \n");
    printf("\t\t\tANA MENU ICIN -> 2 \n");
    printf("\t\t\tCIKMAK ICIN -> 3 \n");
    printf("--->");
    scanf("%d",&yeni);
    printf("\n\n");
    switch(yeni){
        case 1 :{goto yk;break;}
        case 2 :ex:
            {Menu();break;}
        case 3 :exit(-1);
        break;
        default:{printf("HATALI GIRIS\n\n\n");
        goto i2;
        }

    }

}
void KayitDuzenle(){

    system("CLS");
    system("color d");
    int yeni;
    char ad[20];
    personel *per;
    duz:
    printf("SILINECEK KISININ ISIM : ");
    scanf("%s",&ad);
    perDosya = fopen("Personel.txt","r");
    yedek = fopen("duzyedek.txt","w");
    if(perDosya == NULL){
        puts("DOSYA ACILMADI");
        goto kex;
    }

    while(!feof(perDosya)){

        per = (personel*) malloc(sizeof(personel));
        fread(per,sizeof(personel),1,perDosya);

        if(strcmp(per->isim,ad)!=0)
            {
            fwrite(per,sizeof(personel),1,yedek);
            }
        else if (strcmp(per->isim,ad)){
            }

    }

    fclose(perDosya);
    fclose(yedek);

        remove("Personel.txt");
        rename("duzyedek.txt","Personel.txt");

        perDosya=fopen("Personel.txt","a");
        printf("PERSONEL ADINI GIRINIZ : \n");
        scanf("%s",&per->isim);
        printf("PERSONEL TC KIMLIK NO GIRINIZ : \n");
        scanf("%s",&per->TCKimlikNo);
        printf("PERSONEL TELEFON GIRINIZ : \n");
        scanf("%s",&per->telefon);
        printf("PERSONEL E POSTA GIRNINIZ : \n");
        scanf("%s",&per->eposta);
        printf("PERSONEL ADRES GIRINIZ : \n");
        scanf("%s",&per->adres);
        perDosya = fopen("Personel.txt","a");
        if(perDosya != NULL){
            fwrite(per,sizeof(personel) - 2*sizeof(per),1,perDosya);
        fclose(perDosya);
        }


    fflush(stdin);
    i3:
    printf("\n\n\n\t\t\tYENI ARAMA ICIN  -> 1 \n");
    printf("\t\t\tANA MENU ICIN -> 2 \n");
    printf("\t\t\tCIKMAK ICIN -> 3 \n");
    printf("--->");
    scanf("%d",&yeni);
    printf("\n\n");
    switch(yeni){
        case 1 :{goto duz;break;}
        case 2 :kex:
            {Menu();break;}
        case 3 :exit(-1);
        break;
        default:{printf("HATALI GIRIS\n\n\n");
        goto i3;
        }
    }
}
void KayitBulTc(){
    system("color e");
    system("CLS");
    char Tc[15];
    int yeni;
    int durum=0;
    fflush(stdin);
    personel *per;
    ytc:
    printf("ARANACAK TC GIRINIZ : ");
    scanf("%s",&Tc);


    perDosya = fopen("Personel.txt","r");
    if(perDosya == NULL){
        printf("DOSYA ACILMADI \n");
        goto asd;
    }

    while(!feof(perDosya)){
        per = (personel*) malloc(sizeof(personel));
        fread(per,sizeof(personel),1,perDosya);
      if(strcmp(per->TCKimlikNo,Tc)==0){
        printf("ARAMA SONUCU:\n");
        printf("PERSONEL ISIM : %s\n",per->isim);
        printf("PERSONEL TC KIMLIK NO : %s\n",per->TCKimlikNo);
        printf("PERSONEL TELEFON NO : %s\n",per->telefon);
        printf("PERSONEL E POSTA : %s\n",per->eposta);
        printf("PERSONEL ADRES : %s\n\n",per->adres);
        durum=1;
      }

    }
    if(durum==0) { // Aranan deðer dosyada yoktur.
        puts("KAYIT BULUNAMADI...\n");
        system("PAUSE");
        goto asd;
    }
    fclose(perDosya);
    i4:
    printf("\n\n\n\t\t\tYENI GIRIS ICIN  -> 1 \n");
    printf("\t\t\tANA MENU ICIN -> 2 \n");
    printf("\t\t\tCIKMAK ICIN -> 3 \n");
    printf("--->");
    scanf("%d",&yeni);
    printf("\n\n");
    switch(yeni){
        case 1 :{goto ytc;break;}
        case 2 :asd:
            {Menu();break;}
        case 3 :exit(-1);
        break;
        default:{printf("HATALI GIRIS\n\n\n");
        goto i4;
        }
    }
}
void KayitBulIsim(){
    system("CLS");
    system("color f");
    char ad[100];
    int yeni;
    int durum=0;
    fflush(stdin);
    personel *per;
    yad:
    printf("ARANACAK ISIM : ");
    scanf("%s",&ad);


    perDosya = fopen("Personel.txt","r");
    if(perDosya == NULL){
        printf("DOSYA ACILMADI \n");
        goto dsa;
    }

    while(!feof(perDosya)){
        per = (personel*) malloc(sizeof(personel));

        fread(per,sizeof(personel),1,perDosya);
      if(strcmp(per->isim,ad)==0){
        printf("ARAMA SONUCU:");
        printf("\n\n\PERSONEL ISIM : %s\n",per->isim);
        printf("PERSONEL TC KIMLIK NO : %s\n",per->TCKimlikNo);
        printf("PERSONEL TELEFON NO : %s\n",per->telefon);
        printf("PERSONEL E POSTA : %s\n",per->eposta);
        printf("PERSONEL ADRES : %s\n\n",per->adres);
        durum=1;
      }

    }


    if(durum==0) { // Aranan deðer dosyada yoktur.
        puts("KAYIT BULUNAMADI...\n");
        system("PAUSE");
        goto dsa;

    }

    fclose(perDosya);
    i5:
    printf("\n\n\n\t\t\tYENI GIRIS ICIN  -> 1 \n");
    printf("\t\t\tANA MENU ICIN -> 2 \n");
    printf("\t\t\tCIKMAK ICIN -> 3 \n");
    printf("--->");
    scanf("%d",&yeni);
    printf("\n\n");
    switch(yeni){
        case 1 :{goto yad;break;}
        case 2 :dsa:
            {Menu();break;}
        case 3 :exit(-1);
            break;
            default:{printf("HATALI GIRIS\n\n\n");
            goto i5;
            }
    }

}
void KayitSil(){

    system("color 2");
    system("CLS");
    int yeni,durum=0;
    char silTc[20];
    personel *per;

    del:
    printf("SILINECEK KISININ TC KIMLIK NO : ");
    scanf("%s",&silTc);

    perDosya = fopen("Personel.txt","r");
    yedek = fopen("Kayityedek.txt","w");
    if(perDosya == NULL){
        puts("DOSYA ACILMADI");
        goto kex;
    }
    while(!feof(perDosya)){

        per = (personel*) malloc(sizeof(personel));
        fread(per,sizeof(personel),1,perDosya);

        if(strcmp(per->TCKimlikNo,silTc)!=0)
            {
            fwrite(per,sizeof(personel),1,yedek);
            }
        else if (strcmp(per->TCKimlikNo,silTc)){
            printf("KAYIT SILINDI....\n");
        }
    }
    fclose(perDosya);
    fclose(yedek);

        remove("Personel.txt");
        rename("Kayityedek.txt","Personel.txt");
        printf("SILME ISLEMI TAMAMLANDI...");

    fflush(stdin);
    i6:
    printf("\n\n\n\t\t\tYENI ARAMA ICIN -> 1 \n");
    printf("\t\t\tANA MENU ICIN -> 2 \n");
    printf("\t\t\tCIKMAK ICIN -> 3 \n");
    printf("--->");
    scanf("%d",&yeni);
    printf("\n\n");
    switch(yeni){
        case 1 :{goto del;break;}
        case 2 :kex:
            {Menu();break;}
        case 3 :exit(-1);
            break;
            default:{printf("HATALI GIRIS\n\n\n");
            goto i6;

            }
    }

}
