class tomate():
    def __init__(self, name: str, day: int, water: int):
        self.name = name
        self.day = day
        self.water = water


class GardenError(Exception):
    def __init__(self, mess: str):
        super().__init__(mess)


class PlantError(GardenError):
    def __init__(self, mess: str):
        super().__init__(mess)


class WaterError(GardenError):
    def __init__(self, mess: str):
        super().__init__(mess)


def testtomato(day: int, water: int) -> None:
    tomato = tomate("tomato", day, water)
    if tomato.day > 3:
        raise PlantError("The tomato plant is wilting!")
    if tomato.water < 30:
        raise WaterError("Not enough water in the tank!")


if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===")
    print("Testing PlantError...")
    try:
        testtomato(15, 40)
    except PlantError as e:
        print(f"Caught PlantError: {e}\n")
    print("Testing WaterError...")
    try:
        testtomato(2, 20)
    except WaterError as e:
        print(f"Caught WaterError: {e}\n")
    print("Testing catching all garden errors...")
    try:
        testtomato(15, 40)
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    try:
        testtomato(2, 20)
    except GardenError as e:
        print(f"Caught GardenError: {e}\n")
    print("All custom error types work correctly!")
