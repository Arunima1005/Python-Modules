def ft_harvest_total() -> None:
    day = int(input("Day 1 harvest: "))
    total = 0
    total += day
    day = int(input("Day 2 harvest: "))
    total += day
    day = int(input("Day 3 harvest: "))
    total += day
    print(f"Total harvest: {total}")
