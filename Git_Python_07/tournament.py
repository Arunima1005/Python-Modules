
from ex0 import FlameFactory, AquaFactory

from ex1 import HealingCreatureFactory, TransformCreatureFactory

from ex0.factory import CreatureFactory

from ex2.strategy import (
    BattleStrategy,
    NormalStrategy,
    DefensiveStrategy,
    AggressiveStrategy,
)

from ex2.exceptions import InvalidStrategyError

def battle(
    opponents: list[
        tuple[
            CreatureFactory,
            BattleStrategy
        ]
    ]
) -> None:

    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")

    for i in range(len(opponents)):

        for j in range(i + 1, len(opponents)):

            factory1, strategy1 = opponents[i]
            factory2, strategy2 = opponents[j]

            creature1 = factory1.create_base()
            creature2 = factory2.create_base()

            print("\n* Battle *")

            print(creature1.describe())
            print(" vs.")
            print(creature2.describe())

            print(" now fight!")

            try:
                strategy1.act(creature1)
                strategy2.act(creature2)

            except InvalidStrategyError as error:
                print("Battle error, aborting tournament:")
                print(error)
                return

def main() -> None:

    print("Tournament 0 (basic)")
    print(" [ (Flameling+Normal), (Healing+Defensive) ]")

    tournament0 = [
        (
            FlameFactory(),
            NormalStrategy(),
        ),
        (
            HealingCreatureFactory(),
            DefensiveStrategy(),
        ),
    ]

    battle(tournament0)

    print()

    print("Tournament 1 (error)")
    print(" [ (Flameling+Aggressive), (Healing+Defensive) ]")

    tournament1 = [
        (
            FlameFactory(),
            AggressiveStrategy(),
        ),
        (
            HealingCreatureFactory(),
            DefensiveStrategy(),
        ),
    ]

    battle(tournament1)

    print()

    print("Tournament 2 (multiple)")
    print(" [ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")

    tournament2 = [
        (
            AquaFactory(),
            NormalStrategy(),
        ),
        (
            HealingCreatureFactory(),
            DefensiveStrategy(),
        ),
        (
            TransformCreatureFactory(),
            AggressiveStrategy(),
        ),
    ]

    battle(tournament2)


if __name__ == "__main__":
    main()