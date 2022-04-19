#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
    
    if (argc !=2){   
        printf("Usage: ./vigenere keyword\n");
        return 1; 
    }
    string key = argv[1];

    for(int i = 0; i < strlen(key); i++){
        if(isalpha(key[i]) == false){
            printf("Usage: ./vigenere keyword\n");
            return 1; 
        }
    }
    string pt = get_string("plaintext: ");
    int keyl = strlen(key);
    int ptl = strlen(pt);
    int j = 0;
    printf("ciphertext: ");

    for(int i = 0; i < ptl; i++){
        if(islower(key[i])) key[i] -= 97;
        else if (isupper(key[i])) key[i] -= 65;

        if(isalpha(pt[i])){ 
            if(islower(pt[i])){
                pt[i] -= 97;
                pt[i] += key[j % keyl];
                pt[i] %= 26;
                pt[i] += 97;
                printf("%c", pt[i]);
                j++;
            } else {
                pt[i] -= 65;
                pt[i] += key[j % keyl];
                pt[i] %= 26;
                pt[i] += 65;
                printf("%c", pt[i]);
                j++;
            } 
        } else printf("%c", pt[i]);
    }
    printf("\n");
}
