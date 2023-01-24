# Twenty questions
The game of **twenty questions**
that you play against the computer.

The object of the game is for the computer to guess what object
you are thinking of using only yes or no questions.

## Basic Gameplay
In the game 20 questions the player begins by thinking of an object.
The computers goal is to successfully guess what that object is.
The computer will ask the player a set of 20 questions (or less),
attempting to narrow down the list of possible results
until it finally thinks it knows the answer.
It will then present the result to the player.
If the computer successfully guesses the object it wins, otherwise it loses.

The 'knowledge' the computer stores about the world can be 
represented as a binary tree, 
as in the figure below. 
Each non-leaf node stores a question that helps the computer narrow down 
the space of possible answers,
while each leaf node stores the computer guess.

![sample game tree](20q-tree.svg)

The game can be run either by loading an existing 20 questions tree 
from a text file,
or by starting with a default tree (described below). 

## Command line arguments
Process command line arguments:   
   `-h` to display `h`elp text and exit.  
   `-f` to load a game tree from `f`ile.  

## Example output

### Show help
```
./20q -h
Usage: ./20q [-h] [-f file_name]

Options:
  -h   Show this text.
  -f   Load a game tree from a file
```

### Play a default game
Play a game using the default question: 'Is it bigger than a breadbox?'

In these examples the computer's output is shown in black, 
while the user's responses are shown in green, with a leading `+`.

```diff
./20q
Is it bigger than a breadbox?
+ no
Is it spam?
+ no
OK, what was it?
+ a mouse
Give me a question that would distinguish a mouse from spam
+ Do you eat it with eggs?
And would the answer to the question for a mouse be yes or no?
+ no
Would you like to play again?
+ yes
Is it bigger than a breadbox?
+ yes
Is it a programmer?
+ no
OK, what was it?
+ a bag of trash
Give me a question that would distinguish a bag of trash from a programmer
+ Is it worth a lot of money?
And would the answer to the question for a bag of trash be yes or no?
+ no
Would you like to play again?
+ no
Would you like to save your game?
+ yes
Please enter a filename to save your game
+ data.txt
Game saved.
Goodbye!
```

### Play a game loaded from a file
Because the game can save and load questions,
it can improve the more it is played.

```diff
./20q -f data.txt
Is it bigger than a breadbox?
+ yes
Is it worth a lot of money?
+ yes
Is it a programmer?
+ no
OK, what was it?
+ a house
Give me a question that would distinguish a house from a programmer
+ Does it know C++?
And would the answer to the question for a house be yes or no?
+ no
Would you like to play again?
+ no
Would you like to save your game?
+ yes
Please enter a filename to save your game
+ tree2.txt
Game saved.
Goodbye!

```




