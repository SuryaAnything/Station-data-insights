// Enroll no: BT22CSE062
// Created by Surya on 26-10-2023.
// This file contains the main function

#include "station_info.h"
/// This functions is used generate a log file in the same directory. It helps in keeping a track of the flow of program
void generate_testLog(FILE *, char *msg, char *src, int line_no, char *time);

/// Following function contains the input Database
void set_input(Station_param X[]) {

    // The input database contains total of 5 station by default

    Station_param first = {1, 0.7f, 83, 450, 13, 2, 0, {0, 126, 58, 68, 58},
                           {22, 15, 19, 21, 25, 15, 19, 21, 24, 22, 23, 20, 23, 20, 17, 22, 25, 15, 21, 23, 18, 24, 15,
                            22, 22, 15, 18, 18, 23, 24},
                           {85, 89, 84, 76, 76, 85, 82, 78, 94, 78, 78, 81, 94, 95, 86, 93, 88, 80, 88, 89, 86, 95, 90,
                            86, 82, 82, 84, 83, 81, 83}};
    Station_param second = {2, 0.9f, 91, 350, 12, 3, 0, {126, 0, 113, 68, 98},
                            {17, 18, 14, 16, 19, 14, 15, 16, 15, 17, 18, 13, 19, 12, 15, 14, 17, 19, 17, 12, 12, 15, 14,
                             18, 15, 16, 13, 20, 14, 17},
                            {87, 80, 83, 82, 91, 91, 95, 82, 82, 81, 83, 84, 87, 95, 81, 80, 95, 83, 86, 90, 83, 83, 92,
                             88, 88, 96, 88, 96, 92, 97}};
    Station_param third = {3, 0.4f, 53, 550, 8, 7, 1, {58, 113, 0, 68, 58},
                           {25, 32, 32, 33, 32, 34, 35, 26, 28, 33, 34, 29, 30, 32, 30, 28, 26, 25, 36, 38, 39, 35, 34,
                            38, 39, 37, 36, 32, 36, 31},
                           {68, 68, 58, 56, 56, 57, 63, 68, 69, 59, 54, 61, 53, 60, 57, 64, 63, 65, 57, 61, 55, 62, 57,
                            68, 64, 66, 53, 54, 61, 61}};
    Station_param fourth = {4, 0.5f, 46, 590, 5, 10, 1, {68, 68, 68, 0, 58},
                            {30, 28, 33, 27, 25, 29, 34, 32, 31, 26, 25, 33, 30, 27, 35, 29, 26, 34, 28, 32, 33, 30, 26,
                             31, 27, 25, 34, 33, 29, 35},
                            {74, 73, 62, 67, 69, 60, 63, 61, 73, 80, 72, 78, 66, 61, 64, 72, 79, 67, 71, 71, 73, 65, 61,
                             80, 68, 77, 64, 77, 62, 67}};
    Station_param fifth = {5, 0.6f, 39, 450, 3, 12, 1, {58, 98, 58, 58, 0},
                           {31, 28, 28, 38, 33, 36, 36, 32, 32, 27, 31, 27, 33, 30, 30, 37, 31, 35, 37, 35, 28, 29, 29,
                            31, 35, 32, 37, 31, 37, 36},
                           {82, 67, 82, 59, 59, 83, 80, 60, 60, 78, 79, 81, 83, 57, 71, 69, 79, 80, 77, 68, 72, 76, 75,
                            80, 75, 58, 60, 65, 57, 64}};

    X[0] = first;
    X[1] = second;
    X[2] = third;
    X[3] = fourth;
    X[4] = fifth;

}

/// The following function evaluates the average temperature over 30 days for all stations
float average_temp(Station_param X[], int n) {
    float sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += Arrays_sum(X[i].air_temp, 30);
    }
    return sum / ((float) (30 * n));
}

// Starting of the main function

int main() {
    /// log file is opened
    FILE *new_file = fopen("LastTest.log", "w");
    generate_testLog(new_file, "Last test ran on :", __DATE__, __LINE__, __TIME__);

    generate_testLog(new_file, "<Execution started Successfully> :", __FILE__, __LINE__, __TIME__);

    printf("Enter 0 to take use the existing data or press 1 to feed input\n");
    int input, n;
    scanf("%d", &input);
    if (input == 0) {
        generate_testLog(new_file, "Input accepted from existing data :", __FILE__, __LINE__, __TIME__);
        n = 5;
    } else {
        printf("Enter number of climate stations\n");
        scanf("%d", &n);
    }
    Station_param X[n];
    if (input == 0) {
        set_input(X);
        // Input should be provided ...... incomplete

        generate_testLog(new_file, "Data feed into stations successfully :", __FILE__, __LINE__, __TIME__);
    }
    else {
        /// Input data from the user
        for (int i = 0; i < n; ++i) {
            X[i].station = i + 1;
            printf("For station %d :-\n", i + 1);
            printf("Enter sky view factor :");
            scanf("%f", &X[i].sky_view_factor);
            printf("Enter Vegetation density ratio in %%age :");
            scanf("%f", &X[i].vegetation_density_ratio);
            printf("Enter Population density :");
            scanf("%f", &X[i].population_density);
            printf("Enter Pervious surface fraction\n");
            scanf("%d", &X[i].pervious_surface_fraction);
            printf("Enter impervious surface fraction\n");
            scanf("%d", &X[i].impervious_surface_fraction);
            printf("Enter station status(0 for rural 1 for urban) :");
            scanf("%d", &X[i].station_status);
            printf("Distance of this station from other station in order of each station :\n");
            for (int j = 0; j < n; ++j) {
                scanf("%d", &X[i].distance_of_station[j]);
            }
            printf("Enter air temperature for 30 days :\n");
            for (int j = 0; j < 30; ++j) {
                scanf("%f", &X[i].air_temp[j]);
            }
            printf("Enter relative humidity for 30 days in %%age :\n");
            for (int j = 0; j < 30; ++j) {
                scanf("%f", &X[i].rel_humidity[j]);
            }
        }
        generate_testLog(new_file, "Input taken successfully :", __FILE__, __LINE__, __TIME__);
    }
    int menu;
    bool run = true;
    float avg = average_temp(X, n);
    printf("Average temperature for all station = %f\n", avg);
    while (run) {
        printf("---------------Queries---------------\n");
        printf("Enter 1 to list the stations with highest heat degree days. \n");
        printf("Enter 2 to find the thermally comfortable days for any station \n");
        printf("Enter 3 to list dates for all stations with decreasing vegetation density ratio and for which the temperature was more than average city temperature\n");
        printf("Enter 4 to list the top k stations with minimum population density with highest maximum temperature(if population density is same).\n");
        printf("Enter 5 to find the heat island intensity for all urban stations\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &menu);
        char query[50];
        snprintf(query, 50, "Query %d accepted", menu);
        generate_testLog(new_file, query, __FILE__, __LINE__, __TIME__);
        switch (menu) {

            case 0: {
                run = false;
                break;
            }
            case 1: {
                generate_testLog(new_file, "Executing Query 1... :", __FILE__, __LINE__, __TIME__);

                // Find all required stations
                int stations[n], k;
                int max = INT_MIN;
                for (int i = 0; i < n; ++i) {
                    int count = heat_degree_days(X[i], avg);
                    if (count > max) {
                        max = count;
                        k = 0;
                        stations[k++] = X[i].station;
                    } else if (count == max) {
                        stations[k++] = X[i].station;
                    }
                }
                generate_testLog(new_file, "Case 1, required station found :", __FILE__, __LINE__, __TIME__);
                // To display all such stations
                printf("Stations : ");
                char *s = Arrays_toString((const int *) stations, k);
                printf("%s\n", s);
                free(s);
                generate_testLog(new_file, "Stations displayed successfully // Query 1 completed successfully :",
                                 __FILE__, __LINE__, __TIME__);
                break;

            }


            case 2: {
                generate_testLog(new_file, "Executing Query 2... :", __FILE__, __LINE__, __TIME__);
                printf("Enter station to search : ");
                int st;
                scanf("%d", &st);
                int flag = 1;
                int i;
                for (i = 0; i < n && flag == 1; ++i) {
                    if (X[i].station == st) {
                        flag = 0;
                    }
                }

                --i;
                generate_testLog(new_file, "Station searched DONE:", __FILE__, __LINE__, __TIME__);
                Station_param rural1[n - 1];
                int len = identify_nearest_rural(X[i], X, n, rural1);
                if (len > 1)
                    quick_sort_PSF(rural1, 0, len - 1);
                displayThermally_comfortable_days(X[i], rural1[0]);
                generate_testLog(new_file, "Displayed Thermally comfortable days // Query 2 completed successfully :",
                                 __FILE__, __LINE__, __TIME__);
                break;

            }

            case 3: {
                generate_testLog(new_file, "Executing Query 3... :", __FILE__, __LINE__, __TIME__);
                quick_sort_vegetation(X, 0, n - 1);
                generate_testLog(new_file, "Sorting successfully completed according to vegetation", __FILE__, __LINE__,
                                 __TIME__);
                temp_grt_avg(X, n, avg);
                generate_testLog(new_file, "Query 3 completed successfully :", __FILE__, __LINE__, __TIME__);
                break;
            }

            case 4: {
                generate_testLog(new_file, "Executing Query 4... :", __FILE__, __LINE__, __TIME__);
                printf("Enter value of k : ");
                int k;
                scanf("%d", &k);
                if (k>n)
                    k=n;
                quick_sort_population(X, 0, n - 1);
                generate_testLog(new_file, "Sorting DONE according to population :", __FILE__, __LINE__, __TIME__);
                int st = 0;
                for (int i = 1; i < n;) {
                    if (X[i].population_density != X[st].population_density) {
                        if (st != (i - 1)) {
                            quick_sort_temperature(X, st, i - 1);
                        }
                        st = i;
                        i++;
                    } else {
                        i++;
                    }
                }
                if (st != (n - 1)) {
                    quick_sort_temperature(X, st, n - 1);
                }

                generate_testLog(new_file, "Sorting DONE according to maximum temperature :", __FILE__, __LINE__,
                                 __TIME__);
                for (int i = 0; i < k; ++i) {
                    printf("Station: %d  Population density: %f   Maximum Temp.:  %f\n", X[i].station,
                           X[i].population_density, Arrays_maxOf(X[i].air_temp, 30));
                }
                generate_testLog(new_file, "Query 3 completed successfully :", __FILE__, __LINE__, __TIME__);
                break;
            }

            case 5: {
                generate_testLog(new_file, "Executing Query 5... :", __FILE__, __LINE__, __TIME__);
                for (int i = 0; i < n; ++i) {
                    if (X[i].station_status != 0) {
                        Station_param rural[n - 1];
                        int len = identify_nearest_rural(X[i], X, n, rural);
                        generate_testLog(new_file, "Nearest rural station Found for station", __FILE__, __LINE__,
                                         __TIME__);
                        if (len > 1) {
                            quick_sort_PSF(rural, 0, len - 1);
                            generate_testLog(new_file, "Sorting DONE according to PSF :", __FILE__, __LINE__, __TIME__);

                        }
                        // after the above execution rural[0] will contain the required nearest station
                        // Now calculating the average temp for both the stations
                        float avg_urban = Arrays_sum(X[i].air_temp, 30) / 30;
                        float avg_rural = Arrays_sum(rural[0].air_temp, 30) / 30;
                        float heat_island_intensity = fabsf(avg_urban - avg_rural);
                        printf("Station: %d , (urban) , Heat island intensity: %f\n", X[i].station,
                               heat_island_intensity);
                    }
                }
                generate_testLog(new_file, "Query 5 completed Successfully :", __FILE__, __LINE__, __TIME__);

                break;
            }
            default:
                printf("--------Wrong Input--------\n");
        }
        printf("\n\n");
    }
    generate_testLog(new_file, "Execution completed exit(0) :", __FILE__, __LINE__, __TIME__);

    fclose(new_file);

}


void generate_testLog(FILE *new_file, char *msg, char *src, int line_no, char *time) {
    fprintf(new_file, "%s  Line: %d  %s  %s(Indian Standard Time)\n", src, line_no, msg, time);
    fprintf(new_file, "--------------------------------------------------------------\n");

}