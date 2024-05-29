class Matrix:
    def __init__(self, rows, cols):
        self.rows = rows
        self.cols = cols
        self.data = [[0] * cols for _ in range(rows)]

def set_matrix_value(mat, row, col, value):
    mat.data[row][col] = value

def get_matrix_value(mat, row, col):
    return mat.data[row][col]

def print_matrix(mat):
    print("\n=== Matrix ===")
    for row in mat.data:
        print(" ".join(map(str, row)))

def get_max(a, b):
    return max(a, b)

def dp_knapsack_discrete(lobster_list, lobster_count, net_capacity):
    mat = Matrix(lobster_count + 1, net_capacity + 1)

    for i in range(1, lobster_count + 1):
        for w in range(1, net_capacity + 1):
            val_without_current_lobster = get_matrix_value(mat, i - 1, w)
            if lobster_list[i - 1].size <= w:
                remaining_capacity = w - lobster_list[i - 1].size
                val_with_remaining_capacity = get_matrix_value(mat, i - 1, remaining_capacity)
                val_with_current_lobster = lobster_list[i - 1].value + val_with_remaining_capacity
                max_value = get_max(val_without_current_lobster, val_with_current_lobster)
                set_matrix_value(mat, i, w, max_value)
            else:
                set_matrix_value(mat, i, w, val_without_current_lobster)

    knapsack_value = get_matrix_value(mat, mat.rows - 1, mat.cols - 1)
    print_matrix(mat)

    included = [0] * lobster_count
    total_weight = net_capacity

    for i in range(lobster_count, 0, -1):
        if knapsack_value <= 0:
            break
        if knapsack_value != get_matrix_value(mat, i - 1, total_weight):
            included[i - 1] = 1
            knapsack_value -= lobster_list[i - 1].value
            total_weight -= lobster_list[i - 1].size

    print("\n=== Lobsters included in the net ===")
    for i in range(lobster_count):
        if included[i]:
            print(f"id: {lobster_list[i].id} size: {lobster_list[i].size} value: {lobster_list[i].value}")

    print(f"=== Total weight of included lobsters: {net_capacity - total_weight} ===")
    print(f"=== Value in the net {get_matrix_value(mat, mat.rows - 1, mat.cols - 1)} ===")
