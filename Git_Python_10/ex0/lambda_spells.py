from typing import Any


def artifact_sorter(artifacts: list[dict[str, Any]]) -> list[dict[str, Any]]:
    return sorted(artifacts,
                  key=lambda artifact: artifact["power"],
                  reverse=True)


def power_filter(mages: list[dict[str, Any]],
                 min_power: int) -> list[dict[str, Any]]:
    return list(filter(lambda x: x["power"] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda x: f"* {x} *", spells))


def mage_stats(mages: list[dict[str, Any]]) -> dict[str, int | float]:
    max_power = max(mages, key=lambda x: x["power"])["power"]
    min_power = min(mages, key=lambda x: x["power"])["power"]
    avg_power = round(sum(map(lambda x: x["power"], mages)) / len(mages), 2)

    return {
        "max_power": max_power,
        "min_power": min_power,
        "avg_power": avg_power
        }


if __name__ == "__main__":
    artifacts_data: list[dict[str, Any]] = [
        {"name": "Crystal Orb", "power": 85, "type": "orb"},
        {"name": "Fire Staff", "power": 92, "type": "staff"},
        {"name": "Shadow Blade", "power": 78, "type": "blade"},
    ]
    mages_data: list[dict[str, Any]] = [
        {"name": "Aelric", "power": 95, "element": "fire"},
        {"name": "Lyra", "power": 72, "element": "water"},
        {"name": "Thorne", "power": 88, "element": "earth"},
    ]
    spells_data: list[str] = ["fireball", "heal", "shield"]
    print("Testing artifact sorter...")
    sorted_artifacts = artifact_sorter(artifacts_data)
    for artifact in sorted_artifacts:
        print(f"{artifact['name']} " f"({artifact['power']} power)")
    print("\nTesting power filter...")
    powerful_mages = power_filter(mages_data, 80)
    for mage in powerful_mages:
        print(f"{mage['name']} " f"has {mage['power']} power")

    print("\nTesting spell transformer...")
    transformed_spells = spell_transformer(spells_data)
    print(" ".join(transformed_spells))
    print("\nTesting mage stats...")
    stats = mage_stats(mages_data)
    print(stats)
