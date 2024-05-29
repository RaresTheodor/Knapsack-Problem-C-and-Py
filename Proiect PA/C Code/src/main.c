#include <stdio.h>
#include <stdlib.h>
#include "knapsack.h"

int main() {
    struct lobster *lobster_list;
    int lobster_count;
    int net_capacity;

    // Citirea capacității plasei
    printf("Enter the capacity of the net: ");
    scanf("%d", &net_capacity);

    // Citirea numărului de homari
    printf("Enter the number of lobsters: ");
    scanf("%d", &lobster_count);

    // Alocarea memoriei pentru lista de homari
    lobster_list = malloc(lobster_count * sizeof(struct lobster));
    generate_lobsters(lobster_list, lobster_count);

    // Afișarea homarilor generați aleatoriu
    printf("\n=== Generated lobsters ===");
    print_lobsters(lobster_list, lobster_count);

    // Apelarea funcției de programare dinamică pentru problema rucsacului
    dp_knapsack_discrete(lobster_list, lobster_count, net_capacity);

    // Eliberarea memoriei pentru lista de homari
    free(lobster_list);

    return 0;
}
