import random
import time

class Lobster:
    def __init__(self, id, size, value):
        self.id = id
        self.size = size
        self.value = value

def generate_lobsters(lobster_count):
    random.seed(time.time())
    lobster_list = []
    for i in range(lobster_count):
        lobster_list.append(Lobster(
            id=i + 1,
            size=random.randint(1, 10),
            value=random.randint(1, 100)
        ))
    return lobster_list

def print_lobsters(lobster_list):
    print("\nLobsters:")
    for lobster in lobster_list:
        print(f"id: {lobster.id} size: {lobster.size} value: {lobster.value}")
