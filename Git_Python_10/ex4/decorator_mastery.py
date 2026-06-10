from collections.abc import Callable
import time
from functools import wraps
from typing import Any


def spell_timer(func: Callable) -> Callable:

    @wraps(func)
    def wrapper(*args: Any, **kwargs: Any) -> Any:
        print(f"Casting {func.__name__}...")
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        print(f"Spell completed in {end_time - start_time:.3f} seconds")
        return result

    return wrapper


@spell_timer
def fireball_spell() -> str:
    time.sleep(0.1)
    return "Fireball Blast!"


def power_validator(min_power: int) -> Callable:
    def power_check(func: Callable[..., str]) -> Callable[..., str]:
        @wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            power = args[0]
            if power >= min_power:
                return func(*args, **kwargs)

            return "Insuffucient power for this spell"

        return wrapper

    return power_check


@power_validator(10)
def power_light(power: int) -> str:
    return f"Lightning spell cast with {power} power"


def retry_spell(max_attempts: int) -> Callable:
    pass


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        pass

    def cast_spell(self, spell_name: str, power: int) -> str:
        pass


if __name__ == "__main__":
    print("Testing spell timer...")
    result = fireball_spell()
    print(f"Wrap: {fireball_spell.__name__}")
    print(f"Result: {result}")

    print("\nTesting power validator...")
    print(power_light(15))
    print(power_light(5))
