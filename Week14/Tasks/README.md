# Задача 1

Реализирайте система за смарт устройства.

Имаме клас **Device**:
 - `brand`
 - `powerConsumption` (in Watts)
 - `turnOn()`
 - `deviceInfo()`

Имаме клас **Connectable**:
  - `ipAddress`
  - `connectToWiFi()`
  - `connectionInfo()`

Реализирайте клас **SmartTV**, който наследява и двата класа по-горе.
 - `screenSize`
 - `resolution`
 - `streamTV()`

Реализирайте клас **SmartSpeaker**, който наследява и двата класа по-горе.
 - `voiceAssistant`
 - `playMusic()`


---

# Задача 2

Реализирайте RPG игра:

Клас **Character**:
 - `name`
 - `level`
 - `health`
 - `manaPoints`
 - `attack(Character& target)`
 - `specialAbility(Character& target)`
 - `printStatus()`
 - `takeDamage(int amount)`
 - `isAlive()`

Помислете кои методи да са виртуални и кои не и какво ще е подходящо да връщаме за всеки един метод.

Имаме 3 типа герои:
1. **Warrior**
    - `strength`
    - `armor`
    - При атака damage = `strength` * 2.
    - Special ability = *Shield*, с което взима по 10 % от `strength` за damage и също така не получава damage при следващата атака.
1. **Mage**
    - `spellPower`
    - При атака damage = `manaPoints`.
    - Special ability = *Fiteball*, с което взима по `spellpower` за damage.
1. **Archer**
    - `power`
    - `criticalChance` - процент
    - При атака damage = `power`. При атака с уцелен `criticalChance` взима 150% от `power` като damage. 
    - Special ability = *Double shot*