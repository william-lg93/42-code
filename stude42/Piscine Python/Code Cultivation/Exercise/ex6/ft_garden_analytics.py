class plant():
    show_count = 0
    grow = 0
    day = 0

    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def stats(self, grow: int, day: int, show_count: int) -> None:
        self.grow = grow
        self.day = day
        self.show_count = show_count

    def show(self):
        self.show_count += 1
        print(f"{self.name.capitalize()}: {self.height}cm, "
              f"{self.age} days old")

    def height_update(self, height: float):
        if height < 0:
            print(f"{self.name.capitalize()}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self.height += height
            print(f"Height updated: {self.height}cm")
        self.grow += 1

    def age_update(self, age: int):
        if age < 0:
            print(f"{self.name.capitalize()}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self.age += age
            print(f"Age updated: {self.age} days")
        self.day += 1

    def show_stats(self):
        print(f"Stats: {self.grow} grow, {self.day}"
              f"age, {self.show_count} show")

    @classmethod
    def anonymous(cls) -> "plant":
        return cls("Unknown plant", 0.0, 0)


class Flower(plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        super().stats(0, 0, 0)
        self.color = color

    def ask_bloom(self, bloom: bool):
        print(f"Color: {self.color}")
        if bloom:
            print(f"{self.name.capitalize()} is blooming beautifully!\n")
        else:
            print(f"{self.name.capitalize()} has not bloomed yet\n")


class Seed(plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        super().stats(0, 0, 0)
        self.color = color

    def ask_bloom(self, bloom: bool):
        print(f"Color: {self.color}")
        if bloom:
            print(f"{self.name.capitalize()} is blooming beautifully!\n")
        else:
            print(f"{self.name.capitalize()} has not bloomed yet\n")

    def seeds_show(self, seeds: int) -> None:
        print(f"Seeds: {seeds}")


class Tree(plant):
    def __init__(self, name: str, height: float,
                 age: int, trunk: float) -> None:
        super().__init__(name, height, age)
        super().stats(0, 0, 0)
        self.shade_int = 0
        self.trunk = trunk

    def stats_tree(self):
        print(f"{self.shade_int} shade")

    def ask_shade(self, shade: bool):
        print(f"Trunk diameter: {self.trunk}cm")
        if shade:
            print(f"Tree {self.name.capitalize()} now produces a shade of "
                  f"{self.height}cm long and {self.trunk}cm wide.\n")
        else:
            print(f"Tree {self.name.capitalize()} not produces a shade\n")
        self.shade_int += 1


class Vegetable(plant):
    def __init__(self, name: str, height: float,
                 age: int, harvest: str) -> None:
        super().__init__(name, height, age)
        super().stats(0, 0, 0)
        self.harvest = harvest
        self.nutritional = self.age

    def nutritional_value(self):
        print(f"Harvest season: {self.harvest}")
        if self.age - self.nutritional < 1:
            print("Nutritional value: 0\n")
        else:
            print(f"Nutritional value: {self.age - self.nutritional}\n")


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("\n=== Flower")
    rose = Flower("rose", 15, 10, "red")
    rose.show()
    rose.ask_bloom(False)
    rose.show_stats()
    rose.show()
    rose.ask_bloom(True)
    rose.show_stats()
    print("\n=== Tree")
    oak = Tree("oak", 200, 365, 5)
    oak.show()
    oak.show_stats()
    oak.stats_tree()
    oak.ask_shade(False)
    oak.show_stats()
    oak.stats_tree()
    print("\n=== Seed")
    sunflower = Seed("sunflower", 80, 45, "yellow")
    sunflower.show()
    sunflower.ask_bloom(False)
    sunflower.show_stats()
    sunflower.seeds_show(0)
    sunflower.height_update(30)
    sunflower.age_update(20)
    sunflower.show()
    sunflower.ask_bloom(True)
    sunflower.seeds_show(42)
    sunflower.show_stats()
    print("\n=== Anonymous")
    caca = plant.anonymous()
    caca.show()
    caca.show_stats()
