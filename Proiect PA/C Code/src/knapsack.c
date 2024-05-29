#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "knapsack.h"

// Funcția de generare aleatorie a homarilor
void generate_lobsters(struct lobster *lobster_list, int lobster_count) {
    int i;
    time_t t;

    // Inițializarea generatorului de numere aleatorii
    srand((unsigned) time(&t));
    for(i = 0; i < lobster_count; i++){
        lobster_list[i].id = i + 1;  // Setarea identificatorului
        lobster_list[i].size = rand() % 10 + 1;  // Generarea aleatorie a dimensiunii
        lobster_list[i].value = rand() % 100 + 1;  // Generarea aleatorie a valorii
    }
}

// Funcția de afișare a homarilor
void print_lobsters(struct lobster *lobster_list, int lobster_count) {
    int i;

    printf("\nLobsters:");
    for (i = 0; i < lobster_count; i++) {
        printf("\nid: %d size: %d value: %d", lobster_list[i].id, lobster_list[i].size, lobster_list[i].value);
    }
}

// Funcția de setare a unei valori în matrice
void set_matrix_value(struct matrix mat, int row, int col, int value) {
    int pos;
    pos = row * mat.cols + col;  // Calcularea poziției în vectorul linearizat
    *(mat.data + pos) = value;  // Setarea valorii
}

// Funcția de obținere a unei valori din matrice
int get_matrix_value(struct matrix mat, int row, int col) {
    int pos;
    pos = row * mat.cols + col;  // Calcularea poziției în vectorul linearizat
    return *(mat.data + pos);  // Returnarea valorii
}

// Funcția de afișare a matricei
void print_matrix(struct matrix mat) {
    int i, j;

    printf("\n=== Matrix ===\n");
    for(i = 0; i < mat.rows; i++){
        for(j = 0; j < mat.cols; j++){
            printf("%d ", mat.data[i * mat.cols + j]);
        }
        printf("\n");
    }
}

// Funcția de obținere a valorii maxime între două valori
int get_max(int a, int b) {
    return (a > b) ? a : b;
}

// Funcția de implementare a algoritmului de programare dinamică pentru problema rucsacului discret
void dp_knapsack_discrete(struct lobster *lobster_list, int lobster_count, int net_capacity) {
    struct matrix mat;
    int knapsack_value;
    int i, w;
    int val_without_current_lobster;
    int val_with_remaining_capacity;
    int val_with_current_lobster;
    int max_value;
    int remaining_capacity;

    // Inițializarea dimensiunilor matricei și alocarea memoriei
    mat.rows = lobster_count + 1;
    mat.cols = net_capacity + 1;
    mat.data = calloc((mat.rows) * (mat.cols), sizeof(int));

    // Completarea matricei folosind abordarea de programare dinamică
    for(i = 1; i <= lobster_count; i++){
        for(w = 1; w <= net_capacity; w++){
            val_without_current_lobster = get_matrix_value(mat, i - 1, w);  // Valoarea fără homarul curent
            if (lobster_list[i - 1].size <= w) {
                remaining_capacity = w - lobster_list[i - 1].size;  // Capacitatea rămasă
                val_with_remaining_capacity = get_matrix_value(mat, i - 1, remaining_capacity);  // Valoarea pentru capacitatea rămasă
                val_with_current_lobster = lobster_list[i - 1].value + val_with_remaining_capacity;  // Valoarea cu homarul curent adăugat
                max_value = get_max(val_without_current_lobster, val_with_current_lobster);  // Valoarea maximă dintre cele două opțiuni
                set_matrix_value(mat, i, w, max_value);  // Setarea valorii maxime în matrice
            } else {
                set_matrix_value(mat, i, w, val_without_current_lobster);  // Setarea valorii fără homarul curent
            }
        }
    }

    knapsack_value = get_matrix_value(mat, mat.rows - 1, mat.cols - 1);  // Valoarea maximă din rucsac
    print_matrix(mat);

    // Determinarea homarilor incluși în plasă
    int *included = malloc(lobster_count * sizeof(int));  // Vector pentru a păstra homarii incluși
    int total_weight = net_capacity;

    for (i = 0; i < lobster_count; i++) {
        included[i] = 0;  // Inițializarea vectorului included cu 0
    }

    for (i = lobster_count; i > 0 && knapsack_value > 0; i--) {
        if (knapsack_value != get_matrix_value(mat, i - 1, total_weight)) {
            included[i - 1] = 1;  // Homarul curent este inclus
            knapsack_value -= lobster_list[i - 1].value;  // Scăderea valorii homarului curent din valoarea totală
            total_weight -= lobster_list[i - 1].size;  // Scăderea dimensiunii homarului curent din greutatea totală
        }
    }

    // Afișarea homarilor incluși în plasă
    printf("\n=== Lobsters included in the net ===");
    for (i = 0; i < lobster_count; i++) {
        if (included[i]) {
            printf("\nid: %d size: %d value: %d", lobster_list[i].id, lobster_list[i].size, lobster_list[i].value);
        }
    }

    printf("\n=== Total weight of included lobsters: %d ===", net_capacity - total_weight);

    free(included);  // Eliberarea memoriei pentru vectorul included
    free(mat.data);  // Eliberarea memoriei pentru matrice

    printf("\n=== Value in the net %d ===", get_matrix_value(mat, mat.rows - 1, mat.cols - 1));  // Afișarea valorii finale din plasă
}
