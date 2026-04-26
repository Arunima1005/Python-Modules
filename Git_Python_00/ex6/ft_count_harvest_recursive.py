def ft_count_harvest_recursive() -> None:
    day = int(input("Days until harvest: "))

    def count(i, day) -> None:
        if i > day:
            print("Harvest time!")
            return
        print(f"Day {i}")
        count(i + 1, day)
    count(1, day)
