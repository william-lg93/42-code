class plant():
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self):
        return (f"Created: {self.name}: {round(self.height, 1)}cm,"
                f" {self.age} days old")


if __name__ == "__main__":
    rose = plant("Rose", 25.0, 30)
    oak = plant("Oak", 200.0, 365)
    cactus = plant("Cactus", 5.0, 90)
    sunflower = plant("Sunflower", 80.0, 45)
    fern = plant("Fern", 15.0, 120)
    print("=== Garden Factory Output ===")
    print(rose.show())
    print(oak.show())
    print(cactus.show())
    print(sunflower.show())
    print(fern.show())
