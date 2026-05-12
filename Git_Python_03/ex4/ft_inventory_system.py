import sys

def parse_inventory(args: list[str]) -> dict[str, int]:
    inventory: dict[str, int] = {}

    for arg in args:
        if ":" not in arg:
            print(f"Error - invalid parameter '{arg}'")
            continue

        name, quantity_str = arg.split(":", 1)

        if name in inventory:
            print(f"Redundant item '{name}' - discarding")
            continue

        try:
            quantity = int(quantity_str)
        except ValueError as e:
            print(f"Quantity error for '{name}': {e}")
            continue

        inventory[name] = quantity

    return inventory


if __name__ == "__main__":
    print("=== Inventory System Analysis ===")

    args = sys.argv[1:]
    inventory = parse_inventory(args)

    print(f"Got inventory: {inventory}")

    items = list(inventory.keys())
    print(f"Item list: {items}")

    total = sum(inventory.values())
    print(f"Total quantity of the {len(inventory)} items: {total}")

    for item, qty in inventory.items():
        percent = (qty / total) * 100 if total > 0 else 0
        print(f"Item {item} represents {round(percent, 1)}%")

    if inventory:
        max_item = max(inventory, key=lambda item: inventory[item])
        min_item = min(inventory, key=lambda item: inventory[item])

        print(f"Item most abundant: {max_item} with quantity"
              f" {inventory[max_item]}")
        print(f"Item least abundant: {min_item} with quantity"
              f" {inventory[min_item]}")

    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")
