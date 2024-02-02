#ifndef HELPER_H
#define HELPER_H

#include <stdbool.h>
#include <stdio.h>

inline void write_guessed(char word[], char guessed[], char letter[]) {
    for (auto a = 0; a < sizeof(word); a++) {
        if (word[a] == letter[0]) {
            guessed[a] = letter[0];
        }
    }

    printf("You guess: %s", guessed);
}

inline int contains(char word[], char letter[]) {
    for (auto a = 0; a < sizeof(word); a++) {
        if (word[a] == letter[0]) {
            return true;
        }
    }

    return false;
}

inline void init_vowels(char word[], char guessed[]) {
    char vowels[] = "aeiouAEIOU";

    for (auto a = 0; a < sizeof(word); a++) {
        const char c = word[a];
        char letter[1] = {c};

        if (c == ' ') {
            // end-line
        } else if (contains(vowels, letter)) {
            guessed[a] = '-';
        } else {
            guessed[a] = '+';
        }
    }
}

inline void get_input(char const *title, char container[]) {
    // Ask the user to input some text
    printf(title);

    // Get and save the chars
    scanf("%s", container);
}

#endif //HELPER_H
