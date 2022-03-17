#ifndef  BIT_VM_H
#define  BIT_VM_H

#define BIT_STACK_CAP 256
#define OP(t, p) ((Op) {t, p})

typedef enum {
    OP_ADD   ,
    OP_PUT   ,
    OP_COUNT ,
} OpType;

typedef enum {
    PREC_NONE  ,
    PREC_TERM  ,
    PREC_CALL  ,
    PREC_COUNT ,
} OpPrec;

typedef struct {
    OpType type;
    OpPrec prec;
} Op;

typedef int Value;

typedef struct {
    int ip;
    Op  data[BIT_STACK_CAP];
} Ops;

typedef struct {
    int   top;
    Value stack[BIT_STACK_CAP];
} VM;

void push(Value val);
void add(Op op);
void run();

#endif //BIT_VM_H