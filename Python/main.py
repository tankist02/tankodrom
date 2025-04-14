print("Hello", ",", "world!")

my_var = 10

print("my_var: ", my_var)

b = True
f = False
print("b: ", b, " (", type(b), ", f: ", f, sep='')

'''
multi line comment
about nothing
'''

my_name = "Andrew"
my_number = 1

print("Hello, my name is ", my_name, " and my favorite number is ", my_number, sep = '')

def count_equal_integers(numbers):
    unique_numbers = set(numbers)
    return len(numbers) - len(unique_numbers)

numbers = [5, 5, 5, 5, 5]
count = count_equal_integers(numbers)
print(f'The number of equal integers in the list is {count}.')

print('equals: ', count_equal_integers([1, 2]))
'''
secret_number = 42
num_of_guesses = 1

while num_of_guesses <= 5:
    user_guess = int(input("Enter a number: "))
    print("user_guess:", user_guess, "secret_number:", secret_number)
    if user_guess == secret_number:
        print("You guessed right!")
        break
    num_of_guesses = num_of_guesses + 1

#print("You guessed wrong")'
'''

numbers = ["one", "two", "three"]
print(numbers)
print(len(numbers))

letters = list("abcd")
print(letters)

print(numbers[0])
print(numbers[-1])
print(numbers[-2])

print(letters[1:3])

print(numbers[1:])
print(letters[-1:])
print(letters[:-1])
print(letters[:])

numbers.append("four")
print(numbers)

numbers.extend(["five", "six"])
print(numbers)

numbers.insert(0, "zero")
print(numbers)

numbers.pop()
print(numbers)

numbers.remove("five")
print(numbers)

numbers.reverse()
print(numbers)

print(numbers.index("zero"))

numbers.sort()
print(numbers)

nums = [1, 2] + [3, 4]
print(nums)

print(nums * 3)

print(1 in nums)
print(5 in nums)
print(5 not in nums)
#print(nums.index(5))

t = (1, 2, 3, 4, 5)
print(t[:4:2])
