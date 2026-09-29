class plant():
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self):
        print(f"Plant created: {self.name.capitalize()}: {self.height}cm, "
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


if __name__ == "__main__":
    print("=== Garden Security System ===")
    rose = plant("rose", 15, 10)
    rose.show()
    rose.height_update(-25)
    rose.age_update(15)
    print(f"Current state: {rose.name.capitalize()}: {rose.height}cm, "
          f"{rose.age} days old")
