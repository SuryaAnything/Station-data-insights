/**
 * @file station_info.c
 * @brief Implementation of functions declared in "station_info.h."
 *
 * This source code file contains the implementation of functions that are declared in the "station_info.h" header.
 * The functions in this file are designed to work with weather station data and perform various data processing and analysis tasks.
 *
 * Query - 1: `heat_degree_days` calculates the number of heat degree days for a station based on the provided average temperature.
 * Query - 2: `displayThermally_comfortable_days` identifies thermally comfortable days for an urban station and displays them.
 * Query - 3: `temp_grt_avg` lists dates for all stations with decreasing vegetation density ratio and temperatures exceeding the city's average.
 * Query - 4: Lists the top 'k' stations with the minimum population density and highest maximum temperature.
 * Query - 5: Calculates heat island intensity for all urban stations by identifying the nearest rural stations.

 * Additionally, this file includes utility functions for sorting data based on various criteria and converting arrays to strings.
 */

#include "station_info.h"

/// Query - 1
/** Count the number of heat degree days for a particular station */
int heat_degree_days(Station_param x, float avg) {
    int count = 0;
    for (int i = 0; i < 30; ++i) {
        if (x.air_temp[i] > avg)
            count++;
    }
    return count;
}


/// Query - 2
/** Find Thermally comfortable days */
void displayThermally_comfortable_days(Station_param x, Station_param rural) {

    if (!x.station_status) {
        printf("Not a urban station\n");
        return;
    }

    //Find the thermally comfortable days
    float min_temp = (float) INT_MAX;
    int days[30], k = 0;
    for (int i = 0; i < 30; ++i) {
        float temp = fabsf(x.air_temp[i] - rural.air_temp[i]);
        if (temp == min_temp) {
            days[k++] = i + 1;
        } else if (temp < min_temp) {
            k = 0;
            min_temp = temp;
            days[k++] = i + 1;
        }
    }
    // After completion of the loop, days[] will contain all days whose temperature difference is minimum
    printf("Thermally comfortable days for the station is/are :-\n");
    char *ch = Arrays_toString((const int *) days, k);
    printf("%s\n", ch);
    free(ch);
}


/// Query - 3
/** List dates for all stations with decreasing vegetation density ratio and for which the temperature was more
than average city temperature. */

/**
 * Quick sort algorithm for sorting an array of Station_param structures based on the 'vegetation_density_ratio' field.
 *
 * This algorithm takes an array of Station_param structures and sorts them in ascending order based on the 'vegetation_density_ratio' field.
 * It works by selecting a pivot element and rearranging the elements in the array so that elements with values less than the pivot are on the left, and elements with values greater than the pivot are on the right. 
 * The process is then recursively applied to the subarrays until the entire array is sorted.
 *
 * @param arr     The array of Station_param structures to be sorted.
 * @param st      The starting index of the current subarray to be sorted.
 * @param len     The ending index of the current subarray to be sorted.
 */

int partition(Station_param arr[], float x, int init, int l) {
    int i = init, j = l;
    while (i < j) {
        if (arr[i].vegetation_density_ratio == x) {
            Station_param temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        if (arr[i].vegetation_density_ratio < x) {
            Station_param temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
        } else i++;
    }

    return i;
}

void quick_sort_vegetation(Station_param arr[], int st, int len) {

    if (st < len) {
        int index = partition(arr, arr[st].vegetation_density_ratio, st, len);
        quick_sort_vegetation(arr, 0, index - 1);
        quick_sort_vegetation(arr, index + 1, len);
    }
}

void temp_grt_avg(Station_param total[], int n, float avg) {
    for (int i = 0; i < n; ++i) {
        int days[30], k = 0;
        for (int j = 0; j < 30; ++j) {
            if (total[i].air_temp[j] > avg)
                days[k++] = j + 1;
        }
        char *s = Arrays_toString((const int *) days, k);
        printf("V D : %f  Station %d  Days : %s\n", total[i].vegetation_density_ratio, total[i].station, s);
        free(s);
    }

}


/// Query - 4
/**  List the (top ‘k’, k-input) stations with minimum population density with highest maximum temperature.
If two stations have same population density, then list those in the order of highest maximum temperature. */

/**
 * Quick sort algorithm for sorting an array of Station_param structures based on the 'population_density' field.
 *
 * This algorithm takes an array of Station_param structures and sorts them in ascending order based on the 'population_density' field. 
 * It works by selecting a pivot element and rearranging the elements in the array so that elements with values less than the pivot are on the left, and elements with values greater than the pivot are on the right.
 * The process is then recursively applied to the subarrays until the entire array is sorted.
 *
 * @param arr     The array of Station_param structures to be sorted.
 * @param st      The starting index of the current subarray to be sorted.
 * @param len     The ending index of the current subarray to be sorted.
 */

int partition2(Station_param arr[], float x, int init, int l) {
    int i = init, j = l;
    while (i < j) {
        if (arr[i].population_density == x) {
            Station_param temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        if (arr[i].population_density > x) {
            Station_param temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
        } else i++;
    }

    return i;
}

void quick_sort_population(Station_param arr[], int st, int len) {

    if (st < len) {
        int index = partition2(arr, arr[st].population_density, st, len);
        quick_sort_population(arr, 0, index - 1);
        quick_sort_population(arr, index + 1, len);
    }
}

/**
 * Quick sort algorithm for sorting an array of Station_param structures based on the 'maximum temperature over 30 days'.
 *
 * This algorithm takes an array of Station_param structures and sorts them in ascending order based on the 'maximum temperature' field. 
 * The maximum temperature is calculated by the function Arrays_maxOf(), which is defined in utils_array.h
 * It works by selecting a pivot element and rearranging the elements in the array so that elements with values less than the pivot are on the left, and elements with values greater than the pivot are on the right.
 * The process is then recursively applied to the subarrays until the entire array is sorted.
 *
 * @param arr     The array of Station_param structures to be sorted.
 * @param st      The starting index of the current subarray to be sorted.
 * @param len     The ending index of the current subarray to be sorted.
 */

int partition3(Station_param arr[], float x, int init, int l) {
    int i = init, j = l;
    while (i < j) {
        if (Arrays_maxOf(arr[i].air_temp, 30) == x) {
            Station_param temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        if (Arrays_maxOf(arr[i].air_temp, 30) < x) {
            Station_param temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
        } else i++;
    }

    return i;
}

void quick_sort_temperature(Station_param arr[], int st, int len) {

    if (st < len) {
        int index = partition3(arr, Arrays_maxOf(arr[st].air_temp, 30), st, len);
        quick_sort_temperature(arr, st, index - 1);
        quick_sort_temperature(arr, index + 1, len);
    }
}


/** Query- 5
 * Find the heat island intensity for all urban stations.
 */

int identify_nearest_rural(Station_param urban, Station_param total[], int n, Station_param rural[]) {
    int minimum = INT_MAX;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (total[i].station_status == 0) {
            if (urban.distance_of_station[total[i].station - 1] < minimum) {
                k = 0;
                minimum = urban.distance_of_station[total[i].station - 1];
                rural[k++] = total[i];
            } else if (urban.distance_of_station[total[i].station - 1] == minimum) {
                rural[k++] = total[i];
            }
        }
    }
    return k;
}


/**
 * Quick sort algorithm for sorting an array of Station_param structures based on the 'pervious surface fraction' field.
 *
 * This algorithm takes an array of Station_param structures and sorts them in ascending order based on the 'pervious surface fraction' field. 
 * It works by selecting a pivot element and rearranging the elements in the array so that elements with values less than the pivot are on the left, and elements with values greater than the pivot are on the right.
 * The process is then recursively applied to the subarrays until the entire array is sorted.
 *
 * @param arr     The array of Station_param structures to be sorted.
 * @param st      The starting index of the current subarray to be sorted.
 * @param len     The ending index of the current subarray to be sorted.
 */

int partition4(Station_param arr[], int x, int init, int l) {
    int i = init, j = l;
    while (i < j) {
        if (arr[i].pervious_surface_fraction == x) {
            Station_param temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        if (arr[i].pervious_surface_fraction < x) {
            Station_param temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
        } else i++;
    }

    return i;
}

void quick_sort_PSF(Station_param rural[], int st, int len) {

    if (st < len) {
        int index = partition4(rural, rural[0].pervious_surface_fraction, st, len);
        quick_sort_PSF(rural, st, index - 1);
        quick_sort_PSF(rural, index + 1, len);
    }
}