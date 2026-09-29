def ft_count_harvest_recursive():
    n = int(input("Days util harvest: "))
    recursive(n)
    print("Harvest time!")


def recursive(n):
    if n == 0:
        return
    recursive(n - 1)
    print(f"Days {n}")
