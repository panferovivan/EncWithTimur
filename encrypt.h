#ifndef ENCRYPT_H
#define ENCRYPT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    uint32_t state;
} crypto_ctx_t;


uint32_t generate_seed(const char *password);
void init_key_gen(crypto_ctx_t *ctx, uint32_t seed);
unsigned char get_next_key_byte(crypto_ctx_t *ctx);
void encrypt_meccage(const char *plan_text, const char *output_file, const char *password);
void crypto_operation(FILE *input_file, FILE *output_file, const char *password, int mode);
void decrypt_and_display(const char *input_file, const char *password);
void clear_memory(void *ptr, size_t size);


#endif