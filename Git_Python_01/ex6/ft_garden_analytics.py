class Plant:
    class Stats:
        def __init__(self):
            self._grow_calls = 0
            self._age_calls = 0
            self._show_calls = 0

        def count_grow(self):
            self._grow_calls += 1

        def count_age(self):
            self._age_calls += 1

        def count_show(self):
            self._show_calls += 1

        def display(self):
            print(
                f"Stats: {self._grow_calls} grow, "
                f"{self._age_calls} age, {self._show_calls} show"
            )

    def __init__(self, name: str, height: float, day: int):
        self.name = name
        self.height = height
        self.day = day
        self._stats = Plant.Stats()

    def grow(self, ht: float) -> None:
        self.height += ht
        self._stats.count_grow()

    def age(self, duration: int) -> None:
        self.day += duration
        self._stats.count_age()

    def show(self) -> None:
        self._stats.count_show()
        print(f"{self.name}: {round(self.height, 1)}cm, {self.day} days old")

    @staticmethod
    def is_age_one_year_older(age: int) -> bool:
        return age > 365

    @classmethod
    def anonymous(cls):
        return cls("Unknown plant", 0.0, 0)

    def show_stats(self) -> None:
        self._stats.display()


class Flower(Plant):
    def __init__(self,
                 name: str,
                 height: float,
                 day: int,
                 color: str):
        super().__init__(name, height, day)
        self.color = color
        self._bloomed = False

    def bloom(self) -> None:
        self._bloomed = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")
        if self._bloomed:
            print(f" {self.name} is blooming beautifully!")
        else:
            print(f" {self.name} has not bloomed yet")


class Tree(Plant):
    def __init__(self,
                 name: str,
                 height: float,
                 day: int,
                 trunk_diameter: float):
        super().__init__(name, height, day)
        self.trunk_diameter = trunk_diameter
        self._shade_calls = 0

    def produce_shade(self) -> None:
        self._shade_calls += 1
        print(
            f"Tree {self.name} now produces a shade of "
            f"{round(self.height, 1)}cm long and "
            f"{round(self.trunk_diameter, 1)}cm wide."
        )

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {round(self.trunk_diameter, 1)}cm")

    def show_stats(self) -> None:
        super().show_stats()
        print(f" {self._shade_calls} shade")


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int, color: str):
        super().__init__(name, height, age, color)
        self.seeds = 0

    def bloom(self):
        super().bloom()
        self.seeds = 42

    def show(self):
        super().show()
        print(f"Seeds: {self.seeds}")


def display_stats(plant: Plant):
    plant.show_stats()


# ================= MAIN =================
if __name__ == "__main__":
    print("=== Garden statistics ===")

    print("=== Check year-old")
    print("Is 30 days more than a year? ->", Plant.is_age_one_year_older(30))
    print("Is 400 days more than a year? ->", Plant.is_age_one_year_older(400))
    print("\n")
    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    print("[statistics for Rose]")
    display_stats(rose)

    print("[asking the rose to grow and bloom]")
    rose.grow(8)
    rose.bloom()
    rose.show()
    print("[statistics for Rose]")
    display_stats(rose)
    print("\n")
    print("=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    print("[statistics for Oak]")
    display_stats(oak)

    print("[asking the oak to produce shade]")
    oak.produce_shade()

    print("[statistics for Oak]")
    display_stats(oak)

    print("\n")
    print("=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, "yellow")
    sunflower.show()

    print("[make sunflower grow, age and bloom]")
    sunflower.grow(30)
    sunflower.age(20)
    sunflower.bloom()
    sunflower.show()

    print("[statistics for Sunflower]")
    display_stats(sunflower)
    print("\n")
    print("=== Anonymous")
    unknown = Plant.anonymous()
    unknown.show()

    print("[statistics for Unknown plant]")
    display_stats(unknown)
