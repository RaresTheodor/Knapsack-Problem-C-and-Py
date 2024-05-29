from lobster import generate_lobsters, print_lobsters
from knapsack import dp_knapsack_discrete

if __name__ == "__main__":
    net_capacity = int(input("Enter the capacity of the net: "))
    lobster_count = int(input("Enter the number of lobsters: "))

    lobster_list = generate_lobsters(lobster_count)

    print("\n=== Generated lobsters ===")
    print_lobsters(lobster_list)

    dp_knapsack_discrete(lobster_list, lobster_count, net_capacity)
