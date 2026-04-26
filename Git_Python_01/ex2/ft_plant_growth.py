class Plant():
    def __init__(self, name: str, height: float, day: int):
        self.name = name
        self.height = height
        self.day = day
    
    def show(self) -> None:
        print(f"{self.name}: {self.height:.1f}cm, {self.day} days old")
    
    def grow(self, ht: float) -> None:
        self.height += ht

    def age(self, day: int) -> None:
        self.day += day

    
if __name__ == "__main__":
    plant = Plant("Rose", 25.0, 30)
    print("=== Garden Plant Growth ===")
    plant.show()
    height = plant.height
    day = 1
    while day < 8:
        print(f"=== Day {day} ===")
        plant.grow(.8)
        plant.age(1)
        plant.show()
        day += 1
    print(f"Growth this week: {round(plant.height - height, 1)} cm")
