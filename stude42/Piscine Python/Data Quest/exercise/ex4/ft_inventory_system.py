import sys


def sep(a: str) -> dict[str, int]:
    try:
        key, value = a.split(":")
    except ValueError:
        print(f"Error - invalid parameter '{a}'")
        return {}
    try:
        return {key: int(value)}
    except ValueError as e:
        print(f"Quantity error for '{key}': {e}")
        return {}


def item_register() -> dict[str, int]:
    inventory: dict[str, int] = {}
    for arg in sys.argv[1:]:
        tmp = sep(arg)
        for key in tmp:
            if key in inventory:
                print(f"Redundant item '{key}' - discarding")
            else:
                inventory.update(tmp)
    return inventory


if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    items = item_register()
    print("Got inventory:", items)
    print("Item list:", list(items.keys()))
    x = len(items.keys())
    print(f"Total quantity of the {x} items:", sum(items.values()))
    if len(items) > 0:
        most_name = list(items.keys())[0]
        most_value = list(items.values())[0]
        least_name = list(items.keys())[0]
        least_value = list(items.values())[0]
        for i in items.keys():
            if items[i] > most_value:
                most_name = i
                most_value = items[i]
            if items[i] < least_value:
                least_name = i
                least_value = items[i]
            try:
                total = round(items[i] / sum(items.values()) * 100, 1)
            except ZeroDivisionError:
                total = 0.0
            print(f"Item {i} represents {total}%",)
        print(f"Item most abundant: {most_name} with quantity {most_value}")
        print(f"Item least abundant: {least_name} with quantity {least_value}")
    else:
        print("Inventory is empty - no statistics to display")
        items.update({"magic_item": 1})
        print("Updated inventory:",  items)
