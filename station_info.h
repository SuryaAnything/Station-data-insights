//
// Created by Surya on 25-10-2023.
// This file contains the structure/body of the code where all the functions related to given queries are declared

/**
 * @file station_info.h
 * @brief Declaration of functions and data structures for weather station data analysis.
 *
 * This header file contains declarations for functions and data structures used in weather station data analysis.
 * It defines the interfaces for functions that are implemented in the "station_info.c" source code file.
 * Developers can include this header to use the provided functions and work with weather station data.
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include "utils_array.h"
typedef struct {

    /** Station Parameters.
     * The distance parameter is the measure of distance of a station from other stations
     */
    int station;
    float sky_view_factor;
    float vegetation_density_ratio;
    float population_density;
    int pervious_surface_fraction;
    int impervious_surface_fraction;
    int station_status;
    int distance_of_station[100];

    /** Weather Parameters are recorded over 30 days
     * It consist of air temperature and relative humidity
     * The 30 days data is in the form of an array of size 30*/
    float air_temp[30];
    float rel_humidity[30];

} Station_param;

int heat_degree_days(Station_param , float );
void displayThermally_comfortable_days(Station_param , Station_param );
void quick_sort_vegetation(Station_param [], int , int );
void temp_grt_avg(Station_param [], int , float );
void quick_sort_population(Station_param [], int , int );
void quick_sort_temperature(Station_param [], int , int );
int identify_nearest_rural(Station_param , Station_param [], int , Station_param []);
void quick_sort_PSF(Station_param [], int , int );
