# Moviemania 🎥
-

Moviemania is a console-based movie trivia game where users answer questions related to movies, actors, and directors. The game is designed to provide an entertaining and educational experience while showcasing the use of Object-Oriented Programming (OOP) concepts.

## Table of Contents
- Introduction
- Features
- Installation
- How to Play
- OOP Concepts
- Classes and Structure

Introduction
Moviemania is a trivia game that challenges players with questions related to popular movies, famous directors, and iconic actors. The game includes various types of questions, including multiple choice, true/false, and fill-in-the-blank. As players progress through different levels, the difficulty of the questions increases. The goal is to score as high as possible by answering questions correctly and progressing through the levels.

## Features
- **Multiple Question Types**: Supports multiple choice, true/false, and fill-in-the-blank questions.
- **Scoring System**: Keeps track of player scores, including bonuses for consecutive correct answers.
- **Level Progression**: Difficulty increases with each level, providing a challenging experience.
- **Random Question Generation**: Ensures a unique set of questions in each playthrough.
- **High Score Tracking**: Saves and displays top scores for replay value.
- **User-friendly Interface**: Console-based UI that is simple and easy to use.

## How to Play
- Start the Game: Run the game using the command line. You will be prompted to enter your name.
- Answer Questions: The game will present questions from different categories. Enter your answer and press Enter.
- Score Points: Correct answers will earn you points. Consecutive correct answers may provide bonus points.
- Level Up: As you answer questions correctly, you will progress to higher levels with increasing difficulty.
- View High Scores: After finishing, you can view the top scores and try to beat them in the next playthrough.

## OOP Concepts
Moviemania demonstrates several key OOP concepts:

- **Classes and Objects**: The game is structured around classes such as Question, Player, GameLevel, and Scoreboard. Objects are instances of these classes that manage game data and state.
- **Inheritance**: Different types of questions (e.g., MultipleChoiceQuestion, TrueFalseQuestion) inherit from a base Question class.
- **Polymorphism**: The game uses polymorphism to handle different question types uniformly, allowing the game to call askQuestion() on any question type.
- **Encapsulation**: Sensitive data, such as player scores and question details, is encapsulated within classes, providing controlled access through public methods.
- **Abstraction**: The game provides a simplified interface to players, hiding complex logic for question handling and score calculation.
- **Design Patterns**: The Factory Pattern is used to create different types of questions dynamically.


## Classes and Structure
Here’s a brief overview of some key classes in Moviemania:

- Question Class: Base class for all types of questions. Defines common properties and virtual methods for question handling.
- MultipleChoiceQuestion Class: Inherits from Question and handles multiple choice questions.
- TrueFalseQuestion Class: Inherits from Question and handles true/false questions.
- FillInTheBlankQuestion Class: Inherits from Question and handles fill-in-the-blank questions.
- Player Class: Manages player information and scores.
- GameLevel Class: Represents a level in the game, managing difficulty and question lists.
- Scoreboard Class: Tracks and displays high scores.