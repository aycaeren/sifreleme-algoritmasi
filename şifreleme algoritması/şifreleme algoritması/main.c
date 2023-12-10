//
//  main.c
//  şifreleme algoritması
//
//  Created by Ayça Eren on 7.12.2023.
//

#include <stdio.h>
#include <ctype.h>

void sifreleme(char metin[], int anahtar) {
    int i;
    char karakter;
    
    for (i = 0; metin[i] != '\0';i++) {
        karakter= metin[i];
        
        if (isalpha(karakter)) { //harf olup olmadığını kontrol eder.
            if(isupper(karakter)){ //büyük harf için
                karakter=tolower(karakter); //büyük harfi küçük harfe çevirir.
                karakter=(((karakter-'a')+anahtar) % 26)+'a'; //karakteri alfabede tutar ve öteler
            }
            else if (islower(karakter)){ //küçük harf için
                karakter=(((karakter-'a')+anahtar) % 26)+'a';
            }
            metin[i]=karakter;
        }
    }
    printf("Sifrelenmis metin: %s\n",metin);
}
void desifre(char metin[], int anahtar){
    sifreleme(metin,26-anahtar); //girilen şifreyi ilerlettiği kadar geri getirtir
}

int main() {
    char metin[500];
    int anahtar;
    
    printf("Sifrelemek istediginiz metni girin:\n");
    fgets(metin, sizeof(metin), stdin);
    
    printf("Anahtarı giriniz:\n");
    scanf("%d",&anahtar);
    
    sifreleme(metin,anahtar);
    desifre(metin,anahtar);

    return 0;
}
