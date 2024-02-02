#include <stdbool.h>
#include <stdio.h>

#include "helper.h"

void game_loop() {
    int errors = 0;

    char word[20] = {' '};
    char guessed[20] = {' '};

    get_input("P1 enter a word (max 20 chars):", word);

    init_vowels(word, guessed);

    while (errors < 5) {
        char letter[1];
        get_input("\nP2 enter a letter (max 1 chars):", letter);

        if (contains(word, letter) == true) {
            write_guessed(word, guessed, letter);
        } else {
            // not found
            errors++;
        }
    }

    // Output the text
    printf("The word was: %s", word);
}

int main() {
    game_loop();
    return 0;
}
