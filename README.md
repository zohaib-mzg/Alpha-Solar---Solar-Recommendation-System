# AlphaSolar--Solar-Recommendation-System

A C++ console application for solar energy setup cost prediction and consumer management.

## Features
- Energy load calculation based on appliance usage
- Solar panel, battery, and inverter recommendations
- Cost prediction and system optimization
- Consumer management with CRUD operations
- Geographic-based sunlight optimization
- CSV report generation

## Installation
```bash
g++ -std=c++17 main.cpp -o solar-system
./solar-system
```

## Usage
solar -C --add      # Add new consumer

solar -C --search   # Search consumer

solar -C --display  # View all consumers

solar -h            # Help menu

## Project Structure
Includes/
├── ConsumerSection/    # Core logic
├── CustomFunctions/    # Utilities
├── Extras/            # UI components
└── Parsing/           # Data processing
Database/              # Storage
main.cpp              # Entry point

## Technologies
- C++ with OOP principles
- File handling and CSV processing
- STL and algorithms
- Input validation systems

Developed by MUHAMMAD ZOHAIB and Group. 
