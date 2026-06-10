from collections.abc import Callable
from typing import Any
from functools import lru_cache, partial, reduce, singledispatch
from operator import add, mul


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0
    operations: dict[str, Callable[[int, int], int]] = {
        "add": add,
        "multiply": mul,
        "max": max,
        "min": min,
    }
    if operation not in operations:
        raise ValueError(f"It is not operation: {operation}")
    return reduce(operations[operation], spells)


def base_enchantment(power: int, element: str, target: str) -> str:
    return f"{element}: element - {power}: power - {target}: target"


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:

    return {
        "first": partial(base_enchantment, 50, "first"),
        "second": partial(base_enchantment, 50, "second"),
        "third": partial(base_enchantment, 50, "third"),
    }


@lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n

    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    @singledispatch
    def dispatcher(data: Any) -> str:
        return "Unknown spell type"

    @dispatcher.register
    def _(data: int) -> str:
        return f"Damage spell with " f"{data} power"

    @dispatcher.register
    def _(data: str) -> str:
        return f"Enchantment spell: " f"{data}"

    @dispatcher.register
    def _(data: list) -> str:
        return f"Multi-cast spell with " f"{len(data)} spells"

    return dispatcher


if __name__ == "__main__":
    print("Testing spell reducer...")
    numbers = [40, 30, 10, 20]
    print(f"Add: " f"{spell_reducer(numbers, 'add')}")
    print(f"Product: " f"{spell_reducer(numbers, 'multiply')}")
    print(f"Max: " f"{spell_reducer(numbers, 'max')}")
    print(f"Min: " f"{spell_reducer(numbers, 'min')}")

    print("\nTesting partial enchanter...")
    enchanment = partial_enchanter(base_enchantment)
    print(enchanment["first"]("target1"))
    print(enchanment["second"]("target2"))
    print(enchanment["third"]("target3"))

    print("\nTesting memoized fibonacci...")
    print(f"Fibonacci(0): {memoized_fibonacci(0)}")
    print(f"Fibonacci(1): {memoized_fibonacci(1)}")
    print(f"Fibonacci(10): {memoized_fibonacci(10)}")
    print(f"Fibonacci(15): {memoized_fibonacci(15)}")

    print("\nTesting spell dispatcher...")
    dispatcher = spell_dispatcher()
    print(dispatcher(42))
    print(dispatcher("fireball"))
    print(dispatcher(["fire", "ice", "water"]))
    print(dispatcher(42.14))
