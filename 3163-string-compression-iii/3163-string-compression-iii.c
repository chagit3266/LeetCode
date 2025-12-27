char* compressedString(char* word) {
    int j = 0;
    int k = 0;
    char* new_word = malloc(2 * strlen(word) + 1);;
    while (word[j] != '\0') {
        int count = 0;
        int i = 0;
        for (; i < 9 && word[j + i] == word[j]; i++) {
            count++;
        }
        new_word[k++] = count+'0';
        new_word[k++] = word[j];
        j += i;
    }
    new_word[k] = '\0';
    return new_word;
}