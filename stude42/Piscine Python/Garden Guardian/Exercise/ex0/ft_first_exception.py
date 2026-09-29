def input_temperature(temp_str) -> int:
    variable = int(temp_str)
    return variable


if __name__ == "__main__":
    print("=== Garden Temperature ===")
    print("\nInput data is ’25’")
    try:
        variable = input_temperature("25")
        print(f"Temperature is now {variable}°C")
    except Exception as error:
        print(f"Caught input_temperature error: {error}")

    print("\nInput data is ’abc’")
    try:
        variable = input_temperature("abc")
        print(f"Temperature is now {variable}°C")
    except Exception as error:
        print(f"Caught input_temperature error: {error}")

    print("\nAll tests completed - program didn’t crash!")
