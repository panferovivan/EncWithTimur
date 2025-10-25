#ifndef ENCRYPT_H
#define ENCRYPT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unit32_t generate_seed(const char *password);
viod input_key_gen(unit32_t seed);
unsigned char get_next_key_byte();
void encrypt_meccage(const char *plan_text, const char *output_file, const char password);
viod crypto_operation(FILE *input_file, FILE *output_file, const char *password);
void decrypt_and_display(const char *input_file, const char *password);
void clear_memory(void *ptr, size_t size);


#endif