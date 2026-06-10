from collections.abc import Callable


def fireball(target: str, power: int) -> str:
    return f"Fireball hits {target} for {power} damage"


def heal(target: str, power: int) -> str:
    return f"Heal restores {target} for {power} HP"


def spell_combiner(spell1: Callable[[str, int], str], spell2: Callable[[str, int], str]) -> Callable[[str, int], tuple[str, str]]:
    def wrapper(target: str, power: int) -> tuple[str, str]:
        return (spell1(target, power), spell2(target, power))

    return wrapper


def power_amplifier(base_spell: Callable[[str, int], str], multiplier: int) -> Callable[[str, int], str]:
    def wrapper(target: str, power: int) -> str:
        return base_spell(target, power * multiplier)

    return wrapper


def conditional_caster(condition: Callable[[str, int], bool], spell: Callable[[str, int], str]) -> Callable[[str, int], str]:
    def wrapper(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return "Spell fizzled"

    return wrapper


def spell_sequence(spells: list[Callable[[str, int], str]]) -> Callable[[str, int], list[str]]:
    def wrapper(target: str, power: int) -> list[str]:
        return [spell(target, power) for spell in spells]

    return wrapper


def strong_spell(target: str, power: int) -> bool:
    return power >= 40


if __name__ == "__main__":
    print("Testing spell combiner...")
    combined_spell = spell_combiner(fireball, heal)
    result = combined_spell("Dragon", 50)
    print(result)
    print("\nTesting power amplifier...")
    mega_fireball = power_amplifier(fireball, 3)
    print(mega_fireball("Ogre", 20))
    print("\nTesting conditional caster...")
    safe_spell = conditional_caster(strong_spell, fireball)
    print(safe_spell("Goblin", 20))
    print(safe_spell("Goblin", 60))
    print("\nTesting spell sequence...")
    combo_spell = spell_sequence([fireball, heal])
    sequence_result = combo_spell("Knight", 30)
    for spell_result in sequence_result:
        print(spell_result)
