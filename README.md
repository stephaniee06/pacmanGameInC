A. DEMO VIDEO
https://github.com/user-attachments/assets/a4d0c0bd-894b-4753-9b6e-ac6f0e642d4c

B. OVERVIEW
A classic arcade-style Pac-Man game recreated for the terminal using C. The player controls Pac-Man through a maze, collecting points by eating pellets while navigating around ghosts. This implementation focuses on coordinate-based movement, collision detection for walls, and basic enemy logic within a command-line interface.

C. FEATURES
- Real-time Movement: Responsive Pac-Man control using keyboard inputs (WASD or Arrow keys).
- Automated Ghost Logic: Simple AI patterns for ghosts to move independently within the maze.
- Score Tracking: A real-time scoring system that updates as pellets are consumed.
- Dynamic Map Rendering: A grid-based maze rendered using ASCII characters.
- Collision Detection: Logic to prevent movement through walls and detect contact with ghosts.
- Win/Loss States: Automatic detection of "Game Over" (contact with ghost) or "Victory" (all pellets cleared).

D. TECH STACK
- Language: C
- Libraries: Standard I/O (or ncurses/conio.h for non-blocking input)
- Environment: Terminal / Command Line

E. RULES
- Navigate Pac-Man using the designated movement keys.
- Collect all pellets distributed throughout the maze to win the level.
- Avoid making contact with ghosts; touching a ghost results in a lost life or immediate game over.
- The game ends when all pellets are eaten or the player runs out of lives.
