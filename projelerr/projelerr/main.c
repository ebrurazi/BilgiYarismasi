#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

void hosgeldin(void);
int secimYap(void);
void girisYap(char [],char [],char []);
void kayitOl(void);
int bilgiYarisması(void);

int main(void){
    //Bilgilere ad,soyad ve şifreye değerler verdim
    char ad[20]="Nazım";
    char soyad[20]="YILMAZ";
    char sifre[20]="415681";
    
    hosgeldin();
    
    int secim=secimYap();
    //Giriş yapmak istiyorsa 1'e gidilir
    if(secim==1){
        girisYap(ad,soyad,sifre);
    }
    //Kayıt yapmak istiyorsa da 2'ye gidilir
    else if(secim==2){
        kayitOl();
    }
    bilgiYarisması();
    printf("\n\n");
    return 0;
}

void hosgeldin(void){
    //Kullanıcı'ya Yarışma'ya girmeden önce bilgiler verdik
    printf("*********************BİLGİ YARIŞMASISINA HOŞ GELDİNİZZ*********************\n\n");
    printf("Yarışmamıza kayıt değilseniz lütfen kayıt olunuz.\n");
    printf("*Soruya doğru cevap verdiğinizde 20 puan almaktasınız.\n");
    printf("*Toplam 5 soru bulunmaktadır.\n");
    printf("BAŞARILAR DİLERİZ!\n");
}
int secimYap(void){
    int secimler;
    //Hesabı olup olmadığı kontrol edilir yoksa kayıt olmakta
    printf("\nHesabınız varsa Giriş Yapınız(1'e basın).Yoksa Kayıt Olunuz(2'ye basınız) = ");
    scanf("%d",&secimler);
    
    return secimler;
}
void girisYap(char isimler[20],char soyadlar[20],char sifreler[20]){
    char girilenAd[20];
    char girilenSoyad[20];
    char girilenSifre[20];
    int kontrol=1;
    int hatalıGiriş=0;
    
    printf("GIRIS YAPINIZ\n");
    //Konrol birr olduğu sürece while döngüsüne gir
    while (kontrol == 1) {
        //Kullanıcının adını, soyadını ve şifreleri aldım
        printf("Kullanıcı adınız : ");
        scanf("%s",girilenAd);
        
        printf("Soyadınızı giriniz : ");
        scanf("%s",girilenSoyad);
        
        printf("Şifrenizi giriniz : ");
        scanf("%s",girilenSifre);
        
        //strcmp fonksiyonu ile dizileri karşılaştırdık eğer eşitse giriş yapılmaktadır
        if(strcmp(isimler,girilenAd) == 0 && strcmp(soyadlar,girilenSoyad) == 0 && strcmp(sifreler,girilenSifre) == 0){
            printf("Başarıyla giriş yapıldı!!\n\n");
            kontrol=0;
        }
        //Eşit değilse 3 hatalı grişten sonra da kayıtOl() fonksiyonuna yönlendirilmekte
        else{
            printf("Hatalı giriş!!\n\n");
            hatalıGiriş++;
        }
        if(hatalıGiriş == 3){
            printf("Kaydınız bulunmamaktadır.\nLütfen kayıt olup giriş yapınız!\n");
            kayitOl();
        }
    }
}
void kayitOl(void){
    char adınız[20];
    char soyadınız[20];
    char sifreniz[20];
    //Burada kayıt olmaktadır. Bilgilerini alıyoruz
    printf("\nKAYIT OLUNUZ\n");
    
    printf("Adınızı giriniz : ");
    scanf("%s",adınız);
    
    printf("Soyadınızı giriniz : ");
    scanf("%s",soyadınız);
    
    printf("Sifrenizi giriniz : ");
    scanf("%s",sifreniz);
    
    printf("Başarıyla kayıt oldunuz! Giriş ekranına yönlendiriliyorsunuz!\n\n");
    
    girisYap(adınız,soyadınız,sifreniz);
   
}
int bilgiYarisması(void){
    char cevap[1];
    int puan=0;
  
    printf("Yarışma başlmaktadır...\n");
    printf("Puanınız : %d\n\n",puan);
    //Burada sorular bulunmaktadır. Her doğru cevap verdiğinde puanı 10 artmakta. Yanlış cevap verdiğinde ise de oyun sonlanmaktadır.
    printf("SORU 1:\n");
    if(puan==0){
        printf("Türkiye’de Erozyonla mücadele amacıyla kurulan vakfın kısa adı nedir?\n");
        printf("A)Tema B)ÇEKÜL C)TAKVA D)FETAV\n");
        printf("Cevabınız : ");
        scanf("%s",cevap);
        if (strcmp(cevap,"A") == 0) {
            printf("Doğru cevap verdiniz.Tebrikler!\n");
            puan+=10;
            printf("Puanınız = %d\n\n",puan);
        }
        else{
            printf("Yanlış cevap verdiniz.Kaybettiniz!\n");
            printf("Puanınız = %d\n\n",puan);
            exit(1);
        }
    }
    
    printf("\nSORU 2:\n");
    if(puan==10){
        printf("Gece gündüz eşitliği (ekinoks) bir yılda kaç kez gerçekleşir?\n");
        printf("A)1 B)4 C)2 D)3\n");
        printf("Cevabınız : ");
        scanf("%s",cevap);
        if (strcmp(cevap,"C") == 0) {
            printf("Doğru cevap verdiniz.Tebrikler!\n");
            puan+=10;
            printf("Puanınız = %d\n",puan);
        }
        else{
            printf("Yanlış cevap verdiniz.Kaybettiniz!\n");
            printf("Puanınız = %d\n",puan);
            exit(1);
        }
    }
    printf("\nSORU 3:\n");
    if(puan==20){
        printf("Nobel ödülleri hangi ülkede verilmektedir?\n");
        printf("A)Amerika B)İsviçre C)İsveç D)Almanya\n");
        printf("Cevabınız : ");
        scanf("%s",cevap);
        if (strcmp(cevap,"C") == 0) {
            printf("Doğru cevap verdiniz.Tebrikler!\n");
            puan+=10;
            printf("Puanınız = %d\n",puan);
        }
        else{
            printf("Yanlış cevap verdiniz.Kaybettiniz!\n");
            printf("Puanınız = %d\n",puan);
            exit(1);
        }
    }
    printf("\nSORU 4:\n");
    if(puan==30){
        printf(" Mustafa Kemal Atatürk’ün Nüfusa Kayıtlı Olduğu İl Hangisidir?\n");
        printf("A) Bursa B) Ankara C) İstanbul D) Gaziantep\n");
        printf("Cevabınız : ");
        scanf("%s",cevap);
        if (strcmp(cevap,"D") == 0) {
            printf("Doğru cevap verdiniz.Tebrikler!\n");
            puan+=10;
            printf("Puanınız = %d\n",puan);
        }
        else{
            printf("Yanlış cevap verdiniz.Kaybettiniz!\n");
            printf("Puanınız = %d\n",puan);
            exit(1);
        }
    }
    printf("\nSORU 5:\n");
    if(puan==40){
        printf("“Sinekli Bakkal” Romanının Yazarı Aşağıdakilerden Hangisidir?\n");
        printf("A) Reşat Nuri Güntekin B) Halide Edip Adıvar C) Ziya Gökalp D) Ömer Seyfettin\n");
        printf("Cevabınız : ");
        scanf("%s",cevap);
        if (strcmp(cevap,"B") == 0) {
            printf("Doğru cevap verdiniz.Tebrikler!\n");
            puan+=10;
            printf("Puanınız = %d\n",puan);
            printf("\nTEBRİKLER! OYUNU KAZANDINIZ!!\n\n");
            exit(1);
        }
        else{
            printf("Yanlış cevap verdiniz.Kaybettiniz!\n");
            printf("Puanınız = %d\n",puan);
            exit(1);
        }
    }

    
    return puan;
}
