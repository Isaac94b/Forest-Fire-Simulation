# Forest Fire Simulation

This C++ program simulates the spread of fire in a forest over time.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Customization](#customization)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Introduction

This program models the dynamics of a forest, where trees can catch fire from neighboring burning trees. The simulation runs for a specified duration, updating the forest's state at each time step.

## Features

- Forest initialization from a file
- Temporal simulation of fire spread
- Customizable burn time, simulation duration, and default state for padding

## Getting Started

### Prerequisites

- C++ compiler
- (Optional) Git for cloning the repository

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/forest-fire-simulation.git
   g++ forest_fire_simulation.cpp -o forest_fire_simulation
   ./forest_fire_simulation

### Customization
You can customize the simulation parameters by modifying the following variables in the forest_fire_simulation.cpp file:

- hourToburn: Time for a tree to burn (in hours).
- timeToEndTesting: Total simulation duration (in time steps).
- defaultState: Default state for padding (0 - 5 - 1 - 9).

### Contributing
Feel free to contribute to the project by opening issues or submitting pull requests. Follow the contribution guidelines.

### License
This project is licensed under the MIT License.

