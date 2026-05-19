from abc import ABC, abstractmethod

class Creature(ABC):
    
    @abstractmethod
    def attack():
        pass

    def describe(name : str, type : str):
        return f"{name.capitalize()} is a {type.capitalize()} type Creature"
    
class Flameling(Creature):
    pass

class Pyrodon(Creature):
    pass

class Aquabub(Creature):
    pass

class Torragon(Creature):
    pass

class CreatureFactory(ABC):
    
    @abstractmethod
    def create_base():
        pass