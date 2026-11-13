You farm chickens. You need safety net, place, and food, medics
You sell collect and sell eggs earn points
You have to buy food, upgrade place size and safety net.
Other birds come to your farm, eat food, spreads virus (some birds)
You have to protect the farm from other birds, virus, and food.
Game finished if you have no chicken with no points to buy a chicken, no points to buy food or medics, 
                          virus kills everything (points won't work here cause if new chicken bought attacked by virus and die)



Zero Chicken and Low Points Lock: Player has zero chickens, zero points, and inventory has no food or medics left. Trigger immediate game over screen.

Virus Contamination Loop: Virus active in the farm and player buys a new chicken. The newly bought chicken must be infected instantly or perish within a set tick if quarantine or medics are not used. Points cannot save this state.

Negative Resource Protection: Points, food stock, safety net level, and medical supplies cannot drop below zero due to deductions or upkeep costs.

Overcrowded Farm Capacity: Place size limit reached. Player attempts to buy or hatch a new chicken when capacity is full. Prompt error message or block action until place size is upgraded.

Resource Starvation Timer: Chickens consume food per time tick. If food stock equals zero, chicken health decreases per tick until medics or food are replenished.

Simultaneous Predator and Virus Event: Another bird invades and a virus outbreak occurs on the same tick. Prioritize safety net defense check first, then virus infection spread check.

Maximum Upgrade Cap: Player reaches the maximum level for place size or safety net. Disable upgrade buttons and display max level reached.
