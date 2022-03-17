#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "lex.h"

Lexer lex = {0};

static_assert(TOKEN_COUNT == 3, "To pass this, update token_type_str table.");
const char* token_type_str[TOKEN_COUNT] = 
{
    [TOKEN_NUMBER] = "NUMBER",
    [TOKEN_PLUS  ] = "PLUS"  ,
    [TOKEN_EOF   ] = "EOF"   ,
};

static int is_digit(char c) {
    return (('0' <= c) && (c <= '9'));
}

static Token mktoken(TokenType type) {
    Token token = {0};
    token.type  = type;
    token.ptr   = lex.end;
    token.size  = lex.cur - lex.end;
    return token;
}

static char advance() {
    lex.cur += 1;
    return lex.cur[-1];
}

static char peek() {
    return *lex.cur;
}

static void skip_ws() {
    while(1) {
        switch(peek()) {
            case ' ' :
            case '\t':
            case '\r':
            case '\n':
                advance();
                break;

            default: return;
        }
    }
}

static Token number() {
    while(is_digit(peek())) advance();
    return mktoken(TOKEN_NUMBER);
}


void token_print(Token token) {
    printf("[%s]: %.*s\n", token_type_str[token.type], token.size, token.ptr);
}

void lex_set(char* src) {
    lex.src = src;
    lex.cur = src;
    lex.end = src;
}

Token lex_next() {
    skip_ws();
    lex.end = lex.cur;

    char c = advance();
    if(is_digit(c)) return number();

    switch(c) {

        case '+': return mktoken(TOKEN_PLUS);
        
        case '\0': return mktoken(TOKEN_EOF);
        default:
            fprintf(stderr, "[ERROR]: Unknown character `%c`.\n", c);
            exit(1);
    }
}