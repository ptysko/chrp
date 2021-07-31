#include <stdio.h>

int string_get_length(char *source_string); // return length of a string, not counting '\0' character
void string_char_replace(char old_character, char new_character, char *source_string, int source_string_length); // replace any given character to another
void string_copy(char *source_string, char *destination_string, int string_length); // copy string

int main(int argc, char *argv[]){
    if(argc > 4 || argc < 3){
        printf("Usage: ./chrp \"<string>\" <old_character> <new_character>\n");
        return 1;
    }
    else if(string_get_length(argv[2]) > 1 || string_get_length(argv[3]) > 1){
        printf("Error: character parameters must be SINGLE CHARACTER LENGTH!\n");
        return 1;
    }
    else {
        const int string_length = string_get_length(argv[1]);
        char string[string_length], new_string[string_length], old_character, new_character;

        string_copy(argv[1], string, string_length);
        old_character = argv[2][0];
        new_character = argv[3][0];

        string_copy(string, new_string, string_length);
        string_char_replace(old_character, new_character, new_string, string_length);
        
        printf("Old: %s\nNew: %s\n", string, new_string);
        return 0;
    }
}

void string_char_replace(char old_character, char new_character, char *source_string, int source_string_length){
    for(int x = 0; x <= source_string_length; x++)
        if(source_string[x] == old_character) source_string[x] = new_character;
}

void string_copy(char* source_string, char *destination_string, int string_length){
    for(int x = 0; x <= string_length; x++)
        destination_string[x] = source_string[x];
}

int string_get_length(char *source_string){
    int source_string_length = 0;
    while(source_string[source_string_length] != '\0')
        source_string_length++;
    return source_string_length;
}