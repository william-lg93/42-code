class plant():
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self):
        print(f"{self.name.capitalize()}: {self.height}cm, "
              f"{self.age} days old")

    def height_update(self, height: float):
        if height < 0:
            print(f"{self.name.capitalize()}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self.height += height
            print(f"Height updated: {self.height}cm")

    def age_update(self, age: int):
        if age < 0:
            print(f"{self.name.capitalize()}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self.age += age
            print(f"Age updated: {self.age} days")


class Flower(plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color

    def ask_bloom(self, bloom: bool):
        print(f"Color: {self.color}")
        if bloom:
            print(f"{self.name.capitalize()} is blooming beautifully!\n")
        else:
            print(f"{self.name.capitalize()} has not bloomed yet\n")


class Tree(plant):
    def __init__(self, name: str, height: float,
                 age: int, trunk: float) -> None:
        super().__init__(name, height, age)
        self.trunk = trunk

    def ask_shade(self, shade: bool):
        print(f"Trunk diameter: {self.trunk}cm")
        if shade:
            print(f"Tree {self.name.capitalize()} now produces a shade of "
                  f"{self.height}cm long and {self.trunk}cm wide.\n")
        else:
            print(f"Tree {self.name.capitalize()} not produces a shade\n")


class Vegetable(plant):
    def __init__(self, name: str, height: float,
                 age: int, harvest: str) -> None:
        super().__init__(name, height, age)
        self.harvest = harvest
        self.nutritional = self.age

    def nutritional_value(self):
        print(f"Harvest season: {self.harvest}")
        if self.age - self.nutritional < 1:
            print("Nutritional value: 0\n")
        else:
            print(f"Nutritional value: {self.age - self.nutritional}\n")


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose = Flower("rose", 15, 10, "red")
    rose.show()
    rose.ask_bloom(False)
    rose.show()
    rose.ask_bloom(True)
    print("=== Tree")
    oak = Tree("oak", 200, 365, 5)
    oak.show()
    oak.ask_shade(True)
    oak.show()
    oak.ask_shade(False)
    print("=== Vegetable")
    tomato = Vegetable("tomato", 5, 10, "April")
    tomato.show()
    tomato.nutritional_value()
    tomato.age_update(20)
    tomato.height_update(42)
    print("\n")
    tomato.show()
    tomato.nutritional_value()
