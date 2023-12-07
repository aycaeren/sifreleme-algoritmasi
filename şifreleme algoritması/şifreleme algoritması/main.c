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
        
        if (isalpha(karakter)) {
            if(isupper(karakter)){
                karakter=tolower(karakter);
                karakter=(((karakter-'a')+anahtar) % 26)+'a';
            }
            else if (islower(karakter)){
                karakter=(((karakter-'a')+anahtar) % 26)+'a';
            }
            metin[i]=karakter;
        }
    }
    printf("Sifrelenmis metin: %s\n",metin);
}
void desifre(char metin[], int anahtar){
    sifreleme(metin,26-anahtar);
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
