from abc import ABC, abstractmethod
from ex0.creature import Creature


class HealCapability(ABC):

    @abstractmethod
    def heal(self) -> str:
        pass


class TransformCapability(ABC):
    @abstractmethod
    def transform(self) -> str:
        pass

    @abstractmethod
    def revert(self) -> str:
        pass


class Sproutling(Creature, HealCapability):
    def __init__(self) -> None:
        super().__init__("Sproutling", "Grass")

    def heal(self) -> str:
        return "Sproutling heals itself for a small amount"

    def attack(self) -> str:
        return "Sproutling uses Vine Whip!"


class Bloomelle(Creature, HealCapability):
    def __init__(self) -> None:
        super().__init__("Bloomelle", "Grass/Fairy")

    def heal(self) -> str:
        return "Bloomelle heals itself and others for a large amount"

    def attack(self) -> str:
        return "Bloomelle uses Petal Dance!"


class Shiftling(Creature, TransformCapability):

    def __init__(self) -> None:
        super().__init__("Shiftling", "Normal")
        self.transformed = False

    def attack(self) -> str:
        if self.transformed:
            return "Shiftling performs " "a boosted strike!"

        return "Shiftling attacks normally."

    def transform(self) -> str:
        self.transformed = True
        return "Shiftling shifts into " "a sharper form!"

    def revert(self) -> str:
        self.transformed = False
        return "Shiftling returns to normal."


class Morphagon(Creature, TransformCapability):

    def __init__(self) -> None:
        super().__init__("Morphagon", "Normal/Dragon")
        self.transformed = False

    def attack(self) -> str:
        if self.transformed:
            return "Morphagon unleashes " "a devastating morph strike!"

        return "Morphagon attacks normally."

    def transform(self) -> str:
        self.transformed = True
        return "Morphagon morphs into " "a dragonic battle form!"

    def revert(self) -> str:
        self.transformed = False
        return "Morphagon stabilizes its form."
