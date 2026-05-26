import random

if __name__ == "__main__":
    print("=== Game Data Alchemist ===\n")

    players: list[str] = [
        "Alice",
        "bob",
        "Charlie",
        "dylan",
        "Emma",
        "Gregory",
        "john",
        "kevin",
        "Liam",
    ]

    print(f"Initial list of players: {players}")

    players_capitalised: list[str] = [
        player.capitalize() for player in players
        ]

    print("New list with all names capitalized: "
          f"{players_capitalised}")

    already_capitalised: list[str] = [
        player for player in players if player[0].isupper()
    ]

    print("New list of capitalized names only: " f"{already_capitalised}\n")

    score_dict: dict[str, int] = {
        player: random.randrange(1000) for player in players_capitalised
    }
    print(f"Score dict: {score_dict}")

    score_average = round(sum(score_dict.values()) / len(score_dict), 2)

    print(f"Score average is {score_average}")

    highest_score = {
        player: score for player, score in score_dict.items()
        if score > score_average
    }

    print(f"High scores: {highest_score}")
