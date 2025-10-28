#include "encrypt.h"

void encrypt_meccage(const char *plan_text, const char *output_file, const char *password)
{
    unit32_t seed = generate_seed (password);
    crypto_ctx_t ctx;
    init_key_gen(&ctx, seed);

    FILE *file = fopen (output_file, "wb");
    if (file == NULL)
    {
        printf("Ошибка открытия файла \n");
        return;
    }
    size_t text_len = strlen (plan_text);
    fwrite (&text_len, sizeof (size_t), 1, file);

    for (size_t i=0; i< text_len; i++ )
    {
        unsigned char key_byte = get_next_key_byte(&ctx);
        unsigned char encrypt_byte = plan_text[i] ^ key_byte;
        fwrite (&encrypted_byte, sizeof(unsigned char), 1, file);
    }
    fclose(file);

    clear_memory(&seed, sizeof(seed));
    clear_memory(&ctx, sizeof(ctx));
    printf("Сообщение успешно зашифровано и сохранено в %s\n", output_file);

}

void decrypt_and_display(const char *input_file, const char *password)
{
    printf("функиця дешифрования \n");
}

unit32_t generate_seed(const char *password)
{
    unit32_t seed = 0;
    while (*password != '\0')
    {
        seed = (seed << 5 ) + seed + (unsigned char)*password;
        password++;
    }
    return seed;
}

void init_key_gen(crypto_ctx_t *ctx, unit32_t seed)
{
    ctx->state = seed;

    for (int i = 0; i < 16; i++)
    {
        get_next_key_byte(ctx);
    }
}

unsigned char get_next_key_byte(crypto_ctx_t *ctx)
{
    ctx->state ^= ctx->state << 13;
    ctx->state ^= ctx->state >> 17;
    ctx->state ^= ctx->state << 5;
    return (unsigned char) (ctx->state & 0xFF);
}

viod crypto_operation(FILE *input_file, FILE *output_file, const char *password)
{
    
}

void clear_memory(void *ptr, size_t size)
{

}

int main()
{

    printf("====CRYPRO CHEWBACCA==== \n");
    printf("1. Зашифровать сообщение \n");
    printf("2. Расшифровать сообщение \n");
    printf("3. Досвидоний... \n");
    printf("Выбери действие: ");
    return 0;
}