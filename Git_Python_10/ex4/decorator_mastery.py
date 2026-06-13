from collections.abc import Callable
import time
from functools import wraps
from typing import Any


def spell_timer(func: Callable[..., Any]) -> Callable[..., Any]:

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


def power_validator(min_power: int) -> Callable[..., Any]:
    def decorator(func: Callable[..., str]) -> Callable[..., str]:
        @wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> str:
            power = args[-1]
            if power >= min_power:
                return func(*args, **kwargs)

            return "Insufficient power for this spell"

        return wrapper

    return decorator


@power_validator(10)
def power_light(power: int) -> str:
    return f"Lightning spell cast with {power} power"


def retry_spell(max_attempts: int) -> Callable[..., Any]:
    def decorator(func: Callable[..., str]) -> Callable[..., str]:
        @wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> str:
            for attempt in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    print(f"Spell failed, retrying... (attempt {attempt}/{max_attempts})")
            return f"Spell casting failed after max_attempts attempts"
        return wrapper
    return decorator

def create_unstable_spell() -> Callable[[], str]: 
    attempts = 0

    @retry_spell(3)
    def unstable_spell() -> str:
        nonlocal attempts
        attempts += 1
        if attempts < 3:
            raise ValueError("Spell unstable")
        return "Waaaaaaagh spelled !"
    return unstable_spell 

@retry_spell(3)
def failed_spell() -> str: 
    raise ValueError("Always fails")

class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        return ( len(name) >= 3 and 
                all( n.isalpha() or n.isspace() for n in name)) 
    
    @power_validator(10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return ( f"Successfully cast {spell_name} with {power} power" )
        
if __name__ == "__main__":
    print("Testing spell timer...")
    result = fireball_spell()
    print(f"Wrap: {fireball_spell.__name__}")
    print(f"Result: {result}")

    print("\nTesting power validator...")
    print(power_light(15))
    print(power_light(5))

    print("\nTesting retrying spell...")
    unstable_spell = create_unstable_spell()
    print(unstable_spell())
    print()
    print(failed_spell())

    print("Testing MageGuild...") 
    print( MageGuild.validate_mage_name("Gandalf"))
    print( MageGuild.validate_mage_name("Al"))
    print( MageGuild.validate_mage_name("Mage 123"))
    guild = MageGuild()
    print( guild.cast_spell("Fireball", 15)) 
    print( guild.cast_spell("Ice Storm", 5))