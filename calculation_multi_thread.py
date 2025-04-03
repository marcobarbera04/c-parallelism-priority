import threading
import time

# define class Calculation (like the Calculation struct)
class Calculation:
    def __init__(self, a, b, operation):
        self.a = a
        self.b = b
        self.operation = operation

def calculate_thread(calculation, result_list, index):
    if calculation.operation == '+':
        result_list[index] = calculation.a + calculation.b
    elif calculation.operation == '-':
        result_list[index] = calculation.a - calculation.b
    elif calculation.operation == '*':
        result_list[index] = calculation.a * calculation.b
    elif calculation.operation == '/':
        result_list[index] = calculation.a / calculation.b
    else:
        result_list[index] = None

MAX_CALCULATIONS = 3

# list of all calculation datas
calculations = [
    Calculation(2, 6, '*'),
    Calculation(1, 4, '+'),
    Calculation(5, 2, '-')
]

# list containing results
results = [None] * MAX_CALCULATIONS

# list containing threads
threads = []

start_time = time.time()

# create and start thread
for i in range(MAX_CALCULATIONS):
    thread = threading.Thread(target=calculate_thread, args=(calculations[i], results, i))
    threads.append(thread)
    thread.start()

# thread join
for thread in threads:
    thread.join()

# final result calculation
final_result = results[0] + results[1] * results[2]
print(f"Result: {final_result:.2f}")

finish_time = time.time()
execution_time = finish_time - start_time
print(f"Execution time: {execution_time:.12f}")