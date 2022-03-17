#ifndef  BIT_LEX_H
#define  BIT_LEX_H

typedef enum {
    TOKEN_NUMBER ,
    TOKEN_PLUS   ,
    TOKEN_EOF    ,
    TOKEN_COUNT  ,
} TokenType;

typedef struct {
    TokenType type;
    int       size;
    char*     ptr;
} Token;

typedef struct {
    char* src;
    char* cur;
    char* end;
} Lexer;

void token_print(Token token);

void lex_set(char* src);
Token lex_next();

#endif //BIT_LEX_H