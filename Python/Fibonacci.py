import sys
import time

def fib(number_of_terms):
   sys.set_int_max_str_digits(1000000)
   counter = 0
   first = 0
   second = 1
   temp = 0

   while counter <= number_of_terms:
      # print(first)
      temp = first + second
      first = second
      second = temp
      counter = counter + 1
   last = first
   print(last)

# Driver Code
t = time.process_time();
#fib(1000000)
fib(1000000 - 1)
t = time.process_time() - t
print(t)

