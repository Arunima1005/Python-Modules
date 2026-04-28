class Plant:
    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self._height = 0.0
        self._age = 0
        self.set_height(height, show=True)
        self.set_age(age, show=True)

    def set_height(self, height: float, show: bool = False) -> None:
        if height < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
            return
        self._height = height
        if not show:
            print(f"Height updated: {int(height)}cm")

    def set_age(self, age: int, show: bool = False) -> None:
        if age < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
            return
        self._age = age
        if not show:
            print(f"Age updated: {age} days")

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age

    def show(self) -> None:
        print(f"{self.name}: {round(self._height, 1)}cm, {self._age} days old")


if __name__ == "__main__":
    print("=== Garden Security System ===")

    plant = Plant("Rose", 15.0, 10)
    print("Plant created:", end=" ")
    plant.show()
    print("\n")

    plant.set_height(25)
    plant.set_age(30)
    print("\n")

    plant.set_height(-5)
    plant.set_age(-10)
    print("\n")

    print("Current state:", end=" ")
    plant.show()
