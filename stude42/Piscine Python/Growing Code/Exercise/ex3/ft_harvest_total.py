def ft_harvest_total():
    total = int(input("Day 1 harvest: "))
    total = int(input("Day 2 harvest: ")) + total
    total = int(input("Day 3 harvest: ")) + total
    print(f"Total harvest: {total}")
