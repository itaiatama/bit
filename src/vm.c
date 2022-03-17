#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "vm.h"

Ops ops = {0};
VM vm   = {0};

static Value pop() {
    if(vm.top - 1 < 0) {
        fprintf(stderr, "[ERROR]: Value stack is underflow.\n");
        exit(1);
    }
    return vm.stack[--vm.top];
}


static void exec(Op op) {
    switch(op.type) {
        case OP_ADD:
            {
                Value b = pop();
                Value a = pop();
                push(a + b);
            }
            break;

        case OP_PUT:
            {
                Value a = pop();
                printf("%d\n", a);
            }
            break;

        default:
            fprintf(stderr, "[ERROR]: Unknown operation `%d`.\n", op.type);
            exit(1); 
    }
}


void push(Value val) {
    if(vm.top + 1 >= BIT_STACK_CAP) {
        fprintf(stderr, "[ERROR]: Value stack is overflow.\n");
        exit(1);
    }
    vm.stack[vm.top++] = val;
}

void add(Op op) {
    if(ops.ip + 1 >= BIT_STACK_CAP) {
        fprintf(stderr, "[ERROR]: Operation stack is overflow.\n");
        exit(1);
    }
    ops.data[ops.ip++] = op;
}

void run() {
    for(int i = 0; i < ops.ip; i++) {
        Op op = ops.data[i];
        exec(op);
    }
    ops.ip = 0;
}