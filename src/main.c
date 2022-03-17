#include "vm.h"

int main() {

    push(10);
    push(20);
    push(30);
    add(OP(OP_ADD, PREC_TERM));
    add(OP(OP_ADD, PREC_TERM));
    add(OP(OP_PUT, PREC_CALL));

    run();
    return 0;
}
