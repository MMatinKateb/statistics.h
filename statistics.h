/*
	Developed by Mohammad Matin Kateb
	Email: matin.kateb.mk@gmail.com
	Github: MMatinKateb
*/

#include <math.h>
#ifndef STATISTICS_H_INCLUDED
#define STATISTICS_H_INCLUDED

template <class T>
// mean of elements
double mean(T arr[], int size_of_array) {
    double sum = 0;
    for (int i=0; i<size_of_array; i++)
        sum += arr[i];
    double res = sum / size_of_array;
    return res;
}

template <class T>
// median of elements
double med(T arr[], int size_of_array) {
    if (size_of_array % 2 == 0) { // if the size of array is even
        int mid = size_of_array / 2;
        double mid1 = arr[mid-1], mid2 = arr[mid];

        double res = (mid1 + mid2) / 2;
        return res;
    }
    // if the size of array is odd
    int mid = (size_of_array / 2);
    return arr[mid];
}

template <class T>
// variance of elements
double var(T arr[], int size_of_array) {
	double diff[size_of_array];	// we store the differences from every element to the mean value in this array
	double avg = mean(arr, size_of_array);

	for(int i=0; i<size_of_array; i++) {
		// store the differences inside the diff array
		if (arr[i] >= avg)
			diff[i] = arr[i] - avg;
		else
			diff[i] = avg - arr[i];

		diff[i] = pow(diff[i], 2);
	}

	double res = mean(diff, size_of_array);	// assign the mean value of squared differences as result
	return res;
}

template <class T>
// standard deviation
double stddev(T arr[], int size_of_array) {
	double variance = var(arr, size_of_array);
	double res = sqrt(variance);	// standard deviation = square root of variance
	return res;
}

#endif // STATISTICS_H_INCLUDED
