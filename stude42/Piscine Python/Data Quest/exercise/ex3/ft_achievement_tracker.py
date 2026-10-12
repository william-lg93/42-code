import random


my_set = ["Crafting Genius", "Strategist", "WorldSavior",
          "Speed Runner", "Survivor", "Master Explorer", "TreasureHunter",
          "Unstoppable", "First Steps", "Collector Supreme",
          "Untouchable", "Sharp Mind", "Boss Slayer"]


def gen_player_achievements() -> set[str]:
    tmp = random.randint(1, 13)
    achivement: set[str] = set()
    while len(achivement) < tmp:
        finish = random.choice(my_set)
        achivement.add(finish)
    return achivement


if __name__ == "__main__":
    print("=== Achievement Tracker System ===")
    alice = gen_player_achievements()
    bob = gen_player_achievements()
    charlie = gen_player_achievements()
    dylan = gen_player_achievements()
    print("\nplayer Alice:", alice)
    print("player Bob:", bob)
    print("player Charlie:", charlie)
    print("player Dylan:", dylan)
    print("\nAll distinct achivements:", my_set)
    total = alice.intersection(bob, charlie, dylan)
    print("\nCommon achievements:", total)
    print("\nOnly Alice has:", alice.difference(bob, charlie, dylan))
    print("Only Bob has:", bob.difference(alice, charlie, dylan))
    print("Only Charlie has:", charlie.difference(alice, bob, dylan))
    print("Only Dylan has:", dylan.difference(alice, charlie, bob))
    total = set(my_set)
    print("\nAlice is missing: ", total.difference(alice))
    print("Bob is missing: ", total.difference(bob))
    print("Charlie is missing: ", total.difference(charlie))
    print("Dylan is missing: ", total.difference(dylan))
