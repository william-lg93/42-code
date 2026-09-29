class plant():
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self):
        return f"{self.name}: {round(self.height, 1)}cm, {self.age} days old"

    def add_height(self):
        self.height = self.height + 0.8

    def add_age(self):
        self.age = self.age + 1


if __name__ == "__main__":
    rose = plant("Rose", 25, 30)
    print("=== Garden Plant Growth ===")
    print(rose.show())
    rose.add_height()
    rose.add_age()
    init = rose.height
    for day in range(1, 8):
        print(f"=== Day {day} ===")
        print(rose.show())
        rose.add_height()
        rose.add_age()
    init = rose.height - init
    print(f"Growth this week: {round(init, 1)}cm")
