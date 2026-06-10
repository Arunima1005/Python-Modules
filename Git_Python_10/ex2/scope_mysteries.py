from collections.abc import Callable


def mage_counter() -> Callable[[], int]:
    counter = 0

    def wrapper() -> int:
        nonlocal counter
        counter += 1
        return counter

    return wrapper


def spell_accumulator(initial_power: int) -> Callable[[int], int]:

    def wrapper(amount: int) -> int:
        nonlocal initial_power
        initial_power += amount
        return initial_power

    return wrapper


def enchantment_factory(enchantment_type: str) -> Callable[[str], str]:
    def wrapper(item_name: str) -> str:
        return f"{enchantment_type} {item_name}"

    return wrapper


def memory_vault() -> dict[str, Callable[..., str | None]]:
    memory: dict[str, str] = {}

    def store(key: str, value: str) -> None:
        memory[key] = value

    def recall(key: str) -> str:
        return memory.get(key, "Memory not found")

    return {"store": store, "recall": recall}


if __name__ == "__main__":
    print("Testing mage counter...")
    counter_a = mage_counter()
    counter_b = mage_counter()
    print("counter_a call : ", counter_a())
    print("counter_a call : ", counter_a())
    print("counter_b call : ", counter_b())

    print("\nTesting spell accumulator...")
    accumulator = spell_accumulator(100)
    print(f"Base 100, add 20: {accumulator(20)}")
    print(f"Base 100, add 30: {accumulator(30)}")

    print("\nTesting enchantment factory...")
    fire = enchantment_factory("Flaming")
    ice = enchantment_factory("Frozen")
    print(fire("Sword"))
    print(ice("Shield"))

    print("\nTesting memory vault...")
    vault = memory_vault()
    vault["store"]("secret", "42")
    # vault["store"]("secret22", "4222")
    # vault["store"]("secret war", "92")
    print("Store 'secret' = 42")
    print(f"Recall 'secret': {vault['recall']('secret')}")
    print(f"Recall 'unknown': {vault['recall']('unknown')}")
    # print(f"Recall 'secret war': {vault['recall']('secret war')}")
    # vault["store"]("secret", "88")
    # print(f"Recall 'secret': {vault['recall']('secret')}")
