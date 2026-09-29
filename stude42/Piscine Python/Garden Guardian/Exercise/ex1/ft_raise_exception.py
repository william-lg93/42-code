def input_temperature(temp_str) -> int:
    variable = int(temp_str)
    return (variable)


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

    print("\nInput data is ’100’")
    try:
        variable = input_temperature("100")
        if variable <= 40:
            print(f"Temperature is valid {variable}°C")
        else:
            raise Exception(f"Caught input_temperature error: {variable} is"
                            f" too hot for plant (max 40°C)")
    except Exception as error:
        print(f"Caught input_temperature error: {error}")
    print("\nInput data is ’-50’")
    try:
        variable = input_temperature("-50")
        if variable >= 0:
            print(f"Temperature is valid {variable}°C")
        else:
            raise Exception(f"Caught input_temperature error: {variable} is"
                            f" too cold for plants (min 0°C)")
    except Exception as error:
        print(f"Caught input_temperature error: {error}")
    print("\nAll tests completed - program didn’t crash!")
