#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 101
#define MAX_OUTPUT_LENGTH 201
#define MAX_WORDS 100


int is_consonant(char c) {
    return (c >= 'a' && c <= 'z') &&
           c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

int main() {
    int N;
    char words[MAX_WORDS][MAX_WORD_LENGTH];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", words[i]);
    }

    for (int w = 0; w < N; w++) {
        char *word = words[w];
        char output[MAX_OUTPUT_LENGTH];
        int i = 0, j = 0;

        while (word[i] != '\0') {
            if (word[i] == 'c') {
                if (word[i + 1] == 'h') {
                    output[j++] = 'c';
                    i += 2;
                }
                
                else if (word[i + 1] == 'e' || word[i + 1] == 'i' || word[i + 1] == 'y') {
                    output[j++] = 's';
                    i++;
                }
       
                else if (word[i + 1] == '\0') {
                    output[j++] = 'k';
                    i++;
                }
             
                else if (word[i + 1] == 'a' || word[i + 1] == 'o' || word[i + 1] == 'u' ||
                         (is_consonant(word[i + 1]) && word[i + 1] != 'h' && word[i + 1] != 'y')) {
                    output[j++] = 'k';
                    i++;
                }
         
                else {
                    i++;
                }
            } else {
            
                output[j++] = word[i];
                i++;
            }
        }
        output[j] = '\0'; 

        printf("%s\n", output);
    }

    return 0;
}




