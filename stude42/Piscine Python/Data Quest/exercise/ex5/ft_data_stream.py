import typing
import random


nom = ["kaissounet", "said", "gtan's", "hamid"]
action = ["vape like a dragon", "go to the toilet",
          "read scan", "play minecraft", "eat"]


def consume_event(lst: list[tuple[str, str]]) -> typing.Generator[
        tuple[str, str], None, None]:
    while len(lst) != 0:
        e_lst = random.choice(lst)
        lst.remove(e_lst)
        yield e_lst


def gen_event() -> typing.Generator[tuple[str, str], None, None]:
    while True:
        name = random.choice(nom)
        a_action = random.choice(action)
        yield (name, a_action)


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")
    gen = gen_event()
    for i in range(1000):
        name, b_action = next(gen)
        print(f"Event {i}: Player {name} did action {b_action}")
    events = []
    for i in range(10):
        events.append(next(gen))
    print(f"Built list of 10 events: {events}")
    for r_event in consume_event(events):
        print(f"Got event from list: {r_event}")
        print(f"Remains in list: {events}")
