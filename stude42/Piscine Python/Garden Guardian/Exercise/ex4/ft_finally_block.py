class GardenError(Exception):
    def __init__(self, mess: str):
        super().__init__(mess)


class PlantError(GardenError):
    def __init__(self, mess: str):
        super().__init__(mess)


def water_plant(plant_name) -> None:
    if plant_name == plant_name.capitalize():
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(f"Invalid plant name to water: '{plant_name}'"
                         f"\n.. ending tests and returning to main")


def test_watering_system() -> None:
    print("=== Garden Watering System ===")
    print("\nTesting valid plants...")
    try:
        water_plant("Tomato")
        water_plant("Lettuce")
        water_plant("Carrots")
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    finally:
        print("Closing watering system\n")
        print("Testing invalid plants...")
        print("Opening watering system")
    try:
        water_plant("Tomato")
        water_plant("lettuce")
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    finally:
        print("Closing watering system\n")
    print("Cleanup always happens, even with errors!")


if __name__ == "__main__":
    test_watering_system()
