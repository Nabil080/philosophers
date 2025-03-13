# Philosophers - Multithreading Simulation

## About

**Philosophers** is a multithreading simulation of the **Dining Philosophers Problem**, a classic concurrency problem. The goal is to manage multiple philosophers who must alternately **think, eat, and sleep** while sharing a limited number of forks. The program ensures that no philosopher **starves** while preventing **race conditions** and **deadlocks** using mutexes.

## Features

- **Thread-based simulation**: Each philosopher runs as an independent thread.
- **Mutex-protection**: Ensures controlled access to shared resources and prevents data-races.
- **Deadlock prevention**: Implements strategies to avoid circular wait conditions.
- **Custom logging**: Tracks and prints philosopher actions in real-time.
## Dependencies

- A C compiler (`gcc` or `clang`)
- `make` (for building the project)

## Installation

Clone the repository and build the project:

```sh
git clone https://github.com/Nabil080/philo
cd philo
make
```

## Usage

Run the program with the following syntax:

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Example

```sh
./philo 5 800 200 200
```

- `5` → Number of philosophers (and forks)
- `800` → Time to die (ms) if no eating occurs
- `200` → Time to eat (ms)
- `200` → Time to sleep (ms)

The simulation continues until a philosopher dies.

#### Optional Argument

If the **number of times each philosopher must eat** is provided, the simulation ends once all philosophers have eaten at least that many times:

```sh
./philo 5 800 200 200 5
```

## Logging Format

Each action is logged with a timestamp and philosopher ID:

```
[timestamp] X has taken a fork
[timestamp] X is eating
[timestamp] X is sleeping
[timestamp] X is thinking
[timestamp] X died
```

## Cleaning Up

To remove compiled files, run:

```sh
make clean
```

To completely remove all binaries and object files:

```sh
make fclean
```
