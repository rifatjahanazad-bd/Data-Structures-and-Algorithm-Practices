# Chicken Farm: The Survival Challenge

## Game Story

You are a small chicken farmer who dreams of building a successful and thriving chicken farm. You start with a few chickens, a small piece of land, limited food supplies, and a small number of points.

Your goal is to raise healthy chickens, collect and sell eggs, earn points, and expand your farm. However, running a chicken farm is not easy. You must protect your chickens from hungry wild birds, diseases, starvation, and limited space.

Every decision matters. If you fail to manage your resources or protect your chickens, your farm could collapse.

## 1. Starting the Farm

At the beginning of the game, the player receives:

- A small farm with limited capacity.
- A few healthy chickens.
- A limited amount of chicken food.
- A basic safety net to protect the farm.
- A small number of points.
- No advanced medical supplies.

The player must manage these resources carefully to keep the chickens alive and the farm running.

## 2. Raising Chickens and Collecting Eggs

Chickens are the main source of income.

As time passes, healthy chickens produce eggs. The player can collect these eggs and sell them to earn points.

Points are the farm's currency. They are used to purchase essential supplies and improve the farm.

The player can use points to:

- Buy additional chickens.
- Purchase chicken food.
- Buy medicine and medical supplies.
- Upgrade the farm's size.
- Upgrade the safety net.

The more healthy chickens the player has, the more eggs they can produce. However, more chickens also mean higher food consumption and a greater risk of disease spreading.

## 3. Managing Food Supplies

Chickens need food to survive.

Every game time tick, chickens consume a certain amount of food. The amount consumed depends on the number of chickens on the farm.

If the food supply reaches zero, the chickens begin losing health over time. If the player does not purchase more food before their health runs out, the chickens will die.

The player must regularly check the food inventory and spend points to purchase additional supplies.

A successful farmer must balance buying food with saving points for other important upgrades.

## 4. Expanding the Farm

As the player earns more points, they can upgrade the size of their farm.

A larger farm allows the player to keep more chickens, which increases the potential number of eggs they can produce.

However, every farm has a maximum capacity based on its current size.

If the farm is full, the player cannot purchase or hatch another chicken until the farm is upgraded.

Farm size upgrades have limited levels. Once the maximum level is reached, the upgrade option becomes unavailable, and the game displays a message indicating that the farm has reached its maximum capacity.

## 5. Protecting the Farm from Other Birds

The farm is not always safe.

Wild birds occasionally visit the farm, attracted by the food and eggs. Some of these birds steal food, damage the farm, or create other problems.

The player must build and upgrade safety nets to prevent unwanted birds from entering.

A stronger safety net provides better protection against invading birds.

If the safety net fails to stop an invading bird, the bird may enter the farm and:

- Steal some of the available food.
- Disturb the chickens.
- Spread dangerous diseases if it is a disease-carrying bird.

The player must invest in safety net upgrades to reduce the risk of invasion.

## 6. Disease and Virus Outbreaks

One of the biggest threats to the farm is disease.

Some invading birds carry dangerous viruses. If an infected bird enters the farm, it can infect the chickens.

Once a virus outbreak begins, infected chickens can spread the disease to other chickens over time.

The player must purchase medical supplies and use them to treat infected chickens.

If the player responds quickly, the outbreak may be contained before it destroys the entire farm.

However, a virus outbreak can become extremely dangerous.

If a virus is active on the farm and the player purchases a new chicken, the newly purchased chicken is immediately exposed to the infection. Unless the player uses the appropriate quarantine or medical treatment, the new chicken will become infected or die within a limited number of game ticks.

Buying more chickens does not automatically solve a virus outbreak. Points cannot protect chickens from an active infection.

The player must deal with the disease before rebuilding the farm.

## 7. Medical Supplies and Emergency Treatment

Medical supplies are essential for keeping the chickens alive.

The player can purchase medicine using points and use it when chickens become sick.

Medical supplies may be used to:

- Treat infected chickens.
- Reduce the risk of losing chickens during an outbreak.
- Help contain the spread of disease.

Medical supplies are limited, so the player must decide when to use them.

If the player runs out of medicine while the virus is spreading, the farm becomes increasingly difficult to save.

## 8. Unexpected Events and Difficult Decisions

As the game progresses, the player faces increasingly difficult situations.

Several problems can happen at the same time.

For example, a wild bird may invade the farm on the exact same game tick that a virus outbreak begins.

In this situation, the game checks the safety net first to determine whether the invading bird successfully enters the farm. After the invasion check, the game processes virus infection and disease spreading.

The player must constantly monitor:

- Number of healthy chickens.
- Number of infected chickens.
- Available food.
- Available medical supplies.
- Current points.
- Farm capacity.
- Safety net level.
- Current virus status.

All resource values must remain at zero or above. The player cannot have negative points, negative food, negative medicine, or negative safety net levels.

## 9. Game Difficulty and Upgrade Limits

To make the game challenging, farm upgrades have maximum levels.

Both farm size and safety net strength can only be upgraded a limited number of times.

Once an upgrade reaches its maximum level:

- The upgrade button becomes disabled.
- The player sees a message saying the maximum level has been reached.
- No additional points are deducted.

The player must make smart decisions because resources are limited and not every problem can be solved by upgrading.

# 10\. How the Game Ends

The game ends when the player can no longer keep the farm alive.

There are several possible ways to lose.

### A. Complete Resource Failure

The player has:

- Zero chickens.
- Zero points.
- No food remaining.
- No medical supplies remaining.

At this point, the player has no way to rebuild the farm or purchase anything necessary for survival.

The game immediately displays the Game Over screen.

### B. Starvation

If the player runs out of food, the chickens gradually lose health.

If the player cannot purchase food or otherwise prevent starvation, all the chickens eventually die.

If the player has no points to purchase new chickens or supplies, the game ends.

### C. Virus Destroys the Farm

A virus outbreak can kill every chicken on the farm.

This is especially dangerous because buying new chickens does not guarantee recovery.

If the virus is still active, newly purchased chickens are immediately exposed and may become infected or die within a limited time.

The player cannot escape an active virus outbreak simply by spending points on replacement chickens.

If the virus kills every chicken and the player cannot eliminate the infection, the farm is lost and the game ends.

### D. Loss of the Ability to Recover

The game also ends when the player has no chickens left and insufficient resources to restart the farm.

Having points alone does not guarantee survival if the player cannot address the remaining threats, such as an active virus.

The player must have a realistic way to rebuild and maintain the farm.

# 11\. Game Over Screen

When the player loses, the game displays a Game Over screen.

It should show:

- A message explaining why the farm failed.
- The total number of eggs collected.
- The total number of chickens raised.
- The total points earned during the game.
- The number of days the farm survived.

The player can then choose to restart the game and try a new farming strategy.

# 12\. The Main Goal

The ultimate goal is to build the biggest and healthiest chicken farm possible while surviving all the challenges.

The player must learn to balance four important responsibilities:

1. Earn: Collect and sell eggs to generate points.
2. Feed: Keep enough food available to prevent starvation.
3. Protect: Upgrade safety nets to stop dangerous birds from entering.
4. Heal: Buy medical supplies and control virus outbreaks before they destroy the farm.

A successful farmer does not simply collect the most eggs or own the most chickens.

A successful farmer knows how to manage resources, prepare for unexpected events, and keep the farm alive.

Can you build a successful chicken farm and survive every challenge, or will one mistake destroy everything you have worked for?

## 13\. Important Game Rules (For Development)

These rules define how the game should behave during gameplay.

| Situation | Expected game behavior |
| --- | --- |
| Zero chickens, zero points, no food, no medicine | Immediate Game Over |
| Virus active and new chicken purchased | New chicken is exposed immediately |
| Resource deduction | Never allow resources to become negative |
| Farm capacity reached | Block new chicken purchases or hatching |
| Food reaches zero | Chickens lose health every tick |
| Bird invasion and virus outbreak on same tick | Check safety net first, then virus spread |
| Maximum farm size reached | Disable farm upgrade |
| Maximum safety net level reached | Disable safety net upgrade |
| All chickens die from virus | Game Over if recovery is impossible |
| No food or medicine available | Player must manage the remaining resources carefully |
