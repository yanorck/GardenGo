#ifndef TYPES_H
#define TYPES_H

// Centralizamos as definições das structs aqui.
// Agora, tanto o parser quanto a AST podem incluir este arquivo
// sem depender um do outro.

struct coord {
    int x;
    int y;
};

struct duration {
    int val;
    char unit;
};

struct value_type {
    int value;
    int is_percent;
};

#endif // TYPES_H