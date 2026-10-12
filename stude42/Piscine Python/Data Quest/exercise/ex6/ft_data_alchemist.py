import random

liste = ["Alice", "bob", "Charlie", "dylan", "Emma",
         "Gregory", "john", "kevin", "Liam"]


if __name__ == "__main__":
    print("=== Game Data Alchemist ===\n")
    print("Initial list of players:", liste)
    lst_c = [word.capitalize() for word in liste]
    print(f"New list with all names capitalized: {lst_c}")
    lst_mj = [word for word in liste
              if word.capitalize() == word]
    print(f"New list of capitalized names only: {lst_mj}\n")
    dct_rd = {word: random.randint(0, 1000) for word in lst_c}
    print(f"Score dict: {dct_rd}")
    j = sum(dct_rd.values()) / len(dct_rd)
    print(f"Score average is {round(j, 2)}")
    final_dct = {word: dct_rd[word] for word in dct_rd if dct_rd[word] > j}
    print(f"High scores:{final_dct}")
