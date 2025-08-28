# Math Quiz Game in C++

A console-based math quiz application that tests your arithmetic skills with customizable difficulty levels and operation types.

## 🎯 Features

- **Multiple Difficulty Levels**: Easy, Medium, Hard, and Mixed
- **Various Operations**: Addition, Subtraction, Multiplication, Division, and Mixed operations
- **Customizable Quiz Length**: Choose how many questions you want to answer
- **Score Tracking**: Keep track of correct and incorrect answers
- **Multiple Attempts**: Option to retake the quiz
- **Cross-Platform**: Works on Windows, Linux, and macOS

## 📊 Difficulty Levels

| Level | Range   | Description                  |
| ----- | ------- | ---------------------------- |
| Easy  | 1-9     | Simple numbers for beginners |
| Mid   | 10-99   | Two-digit numbers            |
| Hard  | 100-999 | Three-digit numbers          |
| Mix   | 1-999   | Random difficulty            |

## ➕ Operation Types

| Operation      | Symbol | Description                    |
| -------------- | ------ | ------------------------------ |
| Addition       | +      | Sum of two numbers             |
| Subtraction    | -      | Difference between two numbers |
| Multiplication | ×      | Product of two numbers         |
| Division       | ÷      | Division with integer results  |
| Mix            | Random | Combination of all operations  |

## 🚀 Installation & Usage

### Compilation

```bash
g++ math-quiz.cpp -o math-quiz
```

Running the Program

```bash
./math-quiz
```

One-line Compilation and Execution

```bash
g++ math-quiz.cpp -o math-quiz && ./math-quiz
```

## 🎮 How to Play

1. Start the program by running the executable
2. Enter the number of questions you want to answer
3. Select difficulty level:
   - 1 for Easy
   - 2 for Medium
   - 3 for Hard
   - 4 for Mixed
4. Choose operation type:
   - 1 for Addition
   - 2 for Subtraction
   - 3 for Multiplication
   - 4 for Division
   - 5 for Mixed operations
5. Answer each question by typing your solution
6. View your results at the end of the quiz
7. Choose to play again or exit the program

## 📝 Example Game Session

```text
Please, enter the number of the question you want to answer: 2

*********************
The Numbers of levels:
[1] Easy.
[2] Mid.
[3] Hard.
[4] Mix.
************************************************************
Please, enter the number of the level you want to answer: 1

************************************************************
The Numbers of operations:
[1] for '+'.
[2] for '-'.
[3] for '*'.
[4] for '/'.
[5] Mix.
******************************************************
Please, enter the number of the operation you want: 5

======================================================
*****************
Question [1/2]:
 7
 3 *
--------
 21
------------------------------
Right Answer: -).
------------------------------

*****************
Question [2/2]:
 8
 2 ÷
--------
 4
------------------------------
Right Answer: -).
------------------------------

Final Result is Pass: -).
Number of questions: 2.
Question level: Easy.
Operation type: Mix.
Number of right answers: 2.
Number of wrong answers: 0.
```

## 🛠️ Technical Requirements

- C++ Compiler: g++, clang++, or MSVC
- C++ Standard: C++11 or higher
- Libraries: Standard C++ Library

## 📁 Project Structure

```text
math-quiz-cpp/
│
├── math-quiz.cpp          # Main source code file
├── README.md              # Documentation (this file)
└── (optional) Makefile    # Build automation (if added later)
```

## 🔧 Code Overview

The program uses:

- Enums for question levels and operation types
- Functions for modular code organization
- Input validation for user choices
- Random number generation for varied questions
- Score tracking system

## 🤝 Contributing

Contributions are welcome! Feel free to:

1. Fork the project
2. Create a feature branch
3. Commit your changes
4. Submit a pull request

## 📄 License

This project is open source and available under the [MIT] License.

## 🐛 Known Issues

- Division operations use integer arithmetic only
- No color support on Linux/macOS systems
- Console clearing command is system-specific

## 📞 Support

For questions or issues, please open an issue in the project repository.
