import random

def guess_the_number():
    # Generate a random number between 1 and 100
    number_to_guess = random.randint(1, 100)
    guessed = False

    print("Welcome to 'Guess the Number' game!")
    print("I have selected a number between 1 and 100.")
    
    # Loop until the user guesses the correct number
    while not guessed:
        try:
            # Get the user's guess
            user_guess = int(input("Enter your guess: "))
            
            # Provide feedback on the user's guess
            if user_guess < number_to_guess:
                print("Too low! Try again.")
            elif user_guess > number_to_guess:
                print("Too high! Try again.")
            else:
                print("Congratulations! You guessed the correct number!")
                guessed = True
        except ValueError:
            print("Please enter a valid number.")
            
# Start the game
guess_the_number()
