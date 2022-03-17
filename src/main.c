#include <stdio.h>

#include "vm.h"
#include "lex.h"
#include "utils.h"

int main(int argc, char* argv[]) {

    shift(&argc, &argv);

    char* exp = shift(&argc, &argv);
    printf("[EXP]: %s\n", exp);
    printf("====================\n");
    lex_set(exp);

    Token token = lex_next();

    while(token.type != TOKEN_EOF) {
        token_print(token);
        token = lex_next();
    }

    return 0;
}
