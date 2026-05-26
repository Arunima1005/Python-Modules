import random
from typing import Generator


def gen_event() -> Generator[tuple[str, str], None, None]:
    players: list[str] = ["alice", "bob", "charlie", "dylan"]

    actions: list[str] = [
        "run",
        "eat",
        "sleep",
        "grab",
        "move",
        "climb",
        "swim",
        "release",
        "use",
    ]
    while True:
        player: str = random.choice(players)
        action: str = random.choice(actions)
        yield (player, action)


def consume_event(
    events: list[tuple[str, str]],
) -> Generator[tuple[str, str], None, None]:
    while len(events) > 0:
        index = random.randrange(len(events))
        event: tuple[str, str] = events.pop(index)
        yield event


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")

    events = gen_event()
    for i in range(1000):
        player, action = next(events)
        print(f"Event {i}: Player {player} did action {action}")

    event_list: list[tuple[str, str]] = []
    for _ in range(10):
        event_list.append(next(events))

    print(f"Built list of 10 events: {event_list}")

    for event in consume_event(event_list):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {event_list}")
