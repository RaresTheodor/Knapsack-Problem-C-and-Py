#ifndef KNAPSACK_H_INCLUDED
#define KNAPSACK_H_INCLUDED

// Structura unui homar cu identificator, dimensiune și valoare
struct lobster {
    int id;
    int size;
    int value;
};

// Structura unei matrici (matrix) cu numărul de rânduri, coloane și datele matricii
struct matrix {
    int rows;
    int cols;
    int *data;
};

// Declarațiile funcțiilor utilizate
void generate_lobsters(struct lobster *lobster_list, int lobster_count);
void print_lobsters(struct lobster *lobster_list, int lobster_count);
void set_matrix_value(struct matrix mat, int row, int col, int value);
void dp_knapsack_discrete(struct lobster *lobster_list, int lobster_count, int net_capacity);
void print_matrix(struct matrix mat);
int get_matrix_value(struct matrix mat, int row, int col);
int get_max(int a, int b);



#endif // KNAPSACK_H_INCLUDED
