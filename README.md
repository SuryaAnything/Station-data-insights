# City Station Data Analysis
Analysis of city stations with various queries.

## Overview

This project contains a collection of C functions for processing and analyzing station data. The code is organized into several queries and utility functions to perform various tasks related to climate data analysis.

## Project Structure

The project is structured as follows:

- `station_info.c`: This source code file contains the implementation of functions declared in "station_info.h." The functions handle various data processing and analysis tasks related to weather stations.

- `station_info.h`: The header file that declares the functions and data structures used in the project. It also provides a brief overview of the project's functionality.

- `utils_array.h`: Another header file that declares utility functions for working with arrays. These functions are used in the project for data manipulation.

- `main.c`: The main program file, which interacts with the user, takes input, and executes the queries on the weather station data.

## Getting Started


### Installation and Usage

To run the project files download CMake from https://cmake.org/cmake/download
You must have Visual Studio Code install in your system to build the project.
Extract and keep all the files in one directory.
Open the directory in Visual Studio Code.
Press ctrl+shift+p in keyboard and select CMake: Configure.
In the same menu then select CMake: Build
You will se a dspd_Assignment.exe file in the same directory 
To run this file, from the same menu, select CMake: Run Without Debugging

Now you can either use the input provided in the code or else you can give custom input through the keyboard by selecting the appropriate number.

### Query 1

In this query the number of heat degree days for each station is calculated and station with maximum heat degree days is appended into an array.
The final resulting array is then printed as output.

### Query 2

In this query the user is asked to provide a input station. It then generates the thermally comfortable days(out of 30 days) of that particular station.

### Query 3

In this query the stations are first sorted in order of decreasing Vegetation density ratio and then the dates are displayed for which the temperature was higher than average city temperature.

### Query 4

In this query the user is first asked to enter a value k(the no of stations to dispaly). Then the query displays the top k stations in increasing order of their population density. If the population density of and 2 or more than 2 stations are same then they are dsiplayed in order of their decreasing maximum temperature.

### Query 5

In this query, for each urban station a nearest rural station is found considering factor of pervious surface fraction in case of same distance encountered. Then the difference in average temperature over 30 days is calculated, and is displayed as Heat Island Intensity.


## Contributors
Surya Narayan Prasad
Sapnil Deshbhratar

## Contact

email: surya2019npd@outlook.com

Name: Surya Narayan Prasad


