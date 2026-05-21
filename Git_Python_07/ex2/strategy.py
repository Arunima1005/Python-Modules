
from abc import ABC, abstractmethod

from ex0.creature import Creature

from ex1.capabilities import (
    HealCapability,
    TransformCapability,
)

from .exceptions import InvalidStrategyError


class BattleStrategy(ABC):

    @abstractmethod
    def act(self, creature: Creature) -> None:
        pass

    @abstractmethod
    def is_valid(
        self,
        creature: Creature
    ) -> bool:
        pass


class NormalStrategy(BattleStrategy):

    def act(self, creature: Creature) -> None:
        print(creature.attack())

    def is_valid(
        self,
        creature: Creature
    ) -> bool:
        return True


class DefensiveStrategy(BattleStrategy):

    def act(self, creature: Creature) -> None:

        if not self.is_valid(creature):
            raise InvalidStrategyError(
                f"Invalid Creature "
                f"'{creature.name}' "
                "for this defensive strategy"
            )

        print(creature.attack())
        print(creature.heal())

    def is_valid(
        self,
        creature: Creature
    ) -> bool:
        return isinstance(
            creature,
            HealCapability
        )


class AggressiveStrategy(BattleStrategy):

    def act(self, creature: Creature) -> None:

        if not self.is_valid(creature):
            raise InvalidStrategyError(
                f"Invalid Creature "
                f"'{creature.name}' "
                "for this aggressive strategy"
            )

        print(creature.transform())
        print(creature.attack())
        print(creature.revert())

    def is_valid(
        self,
        creature: Creature
    ) -> bool:
        return isinstance(
            creature,
            TransformCapability
        )