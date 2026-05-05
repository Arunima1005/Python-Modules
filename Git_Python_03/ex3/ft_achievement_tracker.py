import random


def gen_player_achievements(all_distinct_achievements:list[str]) -> set[str]:
    num = random.randint(3, len(all_distinct_achievements))
    return set(random.sample(all_distinct_achievements, num))


if __name__ == "__main__":
    print("=== Achievement Tracker System ===")

    all_achievements = ['Crafting Genius', 'Strategist', 'World Savior',
                                 'Speed Runner', 'Survivor', 'Master Explorer',
                                 'Treasure Hunter', 'Unstoppable', 'First Steps',
                                 'Collector Supreme', 'Untouchable', 'Sharp Mind',
                                 'Boss Slayer']
    
    players: list[str] = ["Alice", "Bob", "Charlie", "Dylan"]
    player_data: dict[str, set[str]] = {}
    for player in players:
        player_data[player]= gen_player_achievements(all_achievements)
    for player in players:
        print(f"Player {player}: {player_data[player]}")

    distinct_achievement: set[str] = set()
    for player in players:
        distinct_achievement.update(player_data[player])
    print(f"\nAll distinct achievements: {distinct_achievement}\n")

    common_achievement: set[str] = player_data[players[0]]
    for player in players[1:]:
        common_achievement = common_achievement.intersection(player_data[player])
    print(f"Common achievements: {common_achievement}\n")

    for player in players:
        others = set()

        for p in players:
            if p != player:
                others.update(player_data[p])

        unique = player_data[player] - others
        print(f"Only {player} has: {unique}")
    print("\n")
    for player in players:
        missing = set(all_achievements) - player_data[player]
        print(f"{player} is missing: {missing}")

    