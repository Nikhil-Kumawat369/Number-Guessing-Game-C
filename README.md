# 🎯 Number Guessing Game in C

A fun, interactive Number Guessing Game built in C, featuring Classic and Custom single-player modes, intelligent hints, penalties for invalid guesses, and a persistent High Score system.
Perfect for beginners who want to see real-world C concepts in action 🚀


## 📌 Features

- 🎮 Game Modes

    - Classic Mode (Single Player)

        - Fixed range: 1 to 100

        - Computer randomly selects a number

        - High score is saved across sessions

    - Custom Mode (Single Player)

        - User chooses their own number range

        - High score is not saved

        - Great for experimenting with difficulty

- 💡 Smart Hint System

    - After every wrong guess, the game provides:

    - Too High or Too Low hints

    - Motivation messages to encourage fewer attempts

- ⚠️ Penalty System

    - Entering a number outside the allowed range:

    - Counts as TWO attempts

    - Warns the player clearly

    - Encourages careful and strategic guessing

- 🏆 High Score Tracking

    - Best score (least attempts) is stored in a file:

    - HighScore.txt

    - Automatically updates when a new record is set


## 🛠️ Concepts Used

This project demonstrates several core C programming concepts:

- Functions & function prototypes

- Pointers and pass-by-reference

- File handling (fopen, fprintf, fscanf)

- Random number generation (rand, srand)

- Input handling (scanf, fgets)

- String manipulation (string.h)

- Control structures (loops & conditionals)
## 📂 Project Structure

📁 Number-Guessing-Game

- main.c            # Game source code

- HighScore.txt     # Stores best score (auto-created/updated)

- README.md         # Project documentation

## 🧠 How the Game Works

- Choose a game mode:

    - 0 → Classic Mode

    - 1 → Custom Mode

    - 2 → Exit

- Enter your name

- Start guessing the number!

- Use hints to narrow down the answer

- Try to finish in the least number of attempts
## 🖥️ Sample Output

Enter Your Guess 3
>> 75

Too high!

The number is smaller than your guess.

Keep going! Fewer attempts = better score.
## ❤️ Why This Project ?

This game was created to:

- Practice low-level thinking in C

- Understand memory, pointers, and file I/O

- Build something fun while learning fundamentals

If you're learning C — this is exactly the kind of project that sharpens your skills 💪
## ⭐ Show Some Love

If you found this project helpful or inspiring:

- ⭐ Star the repository

- 🍴 Fork it and improve it

- 🧠 Learn something new and build more!

Happy coding! 👨‍💻🎉