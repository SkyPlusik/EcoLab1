/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include <time.h>
#include <stdlib.h>

/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoLab1.h"

/*
 *
 * <сводка>
 *   Функция проверки результата
 * </сводка>
 *
 */
void asserts(void** actual, void** expected, uint32_t count) {
    uint32_t i = 0;
    for (i = 0; i < count; i++) {
        if (actual[i] != expected[i]) {
            printf("TEST FAILED!\n");
            return;
        }
    }
    printf("TEST PASSED!\n");
}

/*
 *
 * <сводка>
 *   Функция проверки работы всех алгоритмов
 * </сводка>
 *
 */
void test_allFunctions(IEcoLab1* pIEcoLab1, IEcoMemoryAllocator1* pIMem) {
    /* bucketSortIntWithK  */
    printf("\n=== Testing bucketSortIntWithK ===\n");
    {
        int arr[] = { 2, 5, 1, 0, -3, 8, 2 };
        uint32_t n = 7, i = 0;
        int* sortedArr = 0;
        int expected_result[] = { -3, 0, 1, 2, 2, 5, 8 };
        int k = 3;
        int16_t result;

        printf("Input:\narr = [2, 5, 1, 0, -3, 8, 2], k = 3\n");

        result = pIEcoLab1->pVTbl->bucketSortIntWithK(pIEcoLab1, arr, n, k, &sortedArr);
        if (result == 0 && sortedArr != 0) {
            printf("Returned result: [");
            for (i = 0; i < n; i++) {
                printf("%d", sortedArr[i]);
                if (i < n - 1) printf(", ");
            }
            printf("]\n");
            printf("Expected result: [-3, 0, 1, 2, 2, 5, 8]\n");
            asserts(sortedArr, expected_result, n);
            pIMem->pVTbl->Free(pIMem, sortedArr);
        }
        else {
            printf("Error: %d\n", result);
        }
    }

	/* bucketSortIntAutoK  */
    printf("\n=== Testing bucketSortIntAutoK ===\n");
    {
        int arr[] = { 5, 3, 10, 3, 1, -39, -20 };
        uint32_t n = 7, i = 0;
        int* sortedArr = 0;
        int expected_result[] = { -39, -20, 1, 3, 3, 5, 10 };
        int16_t result;

        printf("Input:\narr = [5, 3, 10, 3, 1, -39, -20]\n");

        result = pIEcoLab1->pVTbl->bucketSortIntAutoK(pIEcoLab1, arr, n, &sortedArr);
        if (result == 0 && sortedArr != 0) {
            printf("Returned result: [");
            for (i = 0; i < n; i++) {
                printf("%d", sortedArr[i]);
                if (i < n - 1) printf(", ");
            }
            printf("]\n");
            printf("Expected result: [-39, -20, 1, 3, 3, 5, 10]\n");
            asserts(sortedArr, expected_result, n);
            pIMem->pVTbl->Free(pIMem, sortedArr);
        }
        else {
            printf("Error: %d\n", result);
        }
    }

	/* bucketSortLongWithK  */
    printf("\n=== Testing bucketSortLongWithK ===\n");
    {
        int64_t arr[] = { 20000, 50000, -10012, 0, -3653, 89753, 203 };
        uint32_t n = 7, i = 0;
        int64_t* sortedArr = 0;
        int64_t expected_result[] = { -10012, -3653, 0, 203, 20000, 50000, 89753 };
        int k = 3;
        int16_t result;

        printf("Input:\narr = [20000, 50000, -10012, 0, -3653, 89753, 203], k = 3\n");

        result = pIEcoLab1->pVTbl->bucketSortLongWithK(pIEcoLab1, arr, n, k, &sortedArr);
        if (result == 0 && sortedArr != 0) {
            printf("Returned result: [");
            for (i = 0; i < n; i++) {
                printf("%lld", sortedArr[i]);
                if (i < n - 1) printf(", ");
            }
            printf("]\n");
            printf("Expected result: [-10012, -3653, 0, 203, 20000, 50000, 89753]\n");
            asserts(sortedArr, expected_result, n);
            pIMem->pVTbl->Free(pIMem, sortedArr);
        }
        else {
            printf("Error: %d\n", result);
        }
    }

	/* bucketSortLongAutoK  */
    printf("\n=== Testing bucketSortLongAutoK ===\n");
    {
        int64_t arr[] = { 463735, 36253, 18430, -43, 193, -309, -2000 };
        uint32_t n = 7, i = 0;
        int64_t* sortedArr = 0;
        int64_t expected_result[] = { -2000 , -309, -43, 193, 18430, 36253, 463735 };
        int16_t result;

        printf("Input:\narr = [463735, 36253, 18430, -43, 193, -309, -2000]\n");

        result = pIEcoLab1->pVTbl->bucketSortLongAutoK(pIEcoLab1, arr, n, &sortedArr);
        if (result == 0 && sortedArr != 0) {
            printf("Returned result: [");
            for (i = 0; i < n; i++) {
                printf("%lld", sortedArr[i]);
                if (i < n - 1) printf(", ");
            }
            printf("]\n");
            printf("Expected result: [-2000 , -309, -43, 193, 18430, 36253, 463735]\n");
            asserts(sortedArr, expected_result, n);
            pIMem->pVTbl->Free(pIMem, sortedArr);
        }
        else {
            printf("Error: %d\n", result);
        }
    }

	/* bucketSortFloatWithK  */
    printf("\n=== Testing bucketSortFloatWithK ===\n");
    {
        float arr[] = { 1.2, -0.05, -8.2, 9.3, 5.4, 0.5, 9.32 };
        uint32_t n = 7, i = 0;
        float* sortedArr = 0;
        float expected_result[] = {  -8.2, -0.05, 0.5, 1.2, 5.4, 9.3, 9.32 };
        int k = 3;
        int16_t result;

        printf("Input:\narr = [1.20, -0.05, -8.20, 9.30, 5.40, 0.50, 9.32], k = 3\n");

        result = pIEcoLab1->pVTbl->bucketSortFloatWithK(pIEcoLab1, arr, n, k, &sortedArr);
        if (result == 0 && sortedArr != 0) {
            printf("Returned result: [");
            for (i = 0; i < n; i++) {
                printf("%.2f", sortedArr[i]);
                if (i < n - 1) printf(", ");
            }
            printf("]\n");
            printf("Expected result: [-8.20, -0.05, 0.50, 1.20, 5.40, 9.30, 9.32]\n");
            asserts(sortedArr, expected_result, n);
            pIMem->pVTbl->Free(pIMem, sortedArr);
        }
        else {
            printf("Error: %d\n", result);
        }
    }

	/* bucketSortFloatAutoK  */
    printf("\n=== Testing bucketSortFloatAutoK ===\n");
    {
        float arr[] = { 4.23, 4.56, -0.34, 0.98, -5.7, 4.65, 4.66 };
        uint32_t n = 7, i = 0;
        float* sortedArr = 0;
        float expected_result[] = { -5.7, -0.34, 0.98, 4.23, 4.56, 4.65, 4.66 };
        int16_t result;

        printf("Input:\narr = [4.23, 4.56, -0.34, 0.98, -5.70, 4.65, 4.66]\n");

        result = pIEcoLab1->pVTbl->bucketSortFloatAutoK(pIEcoLab1, arr, n, &sortedArr);
        if (result == 0 && sortedArr != 0) {
            printf("Returned result: [");
            for (i = 0; i < n; i++) {
                printf("%.2f", sortedArr[i]);
                if (i < n - 1) printf(", ");
            }
            printf("]\n");
            printf("Expected result: [-5.70, -0.34, 0.98, 4.23, 4.56, 4.65, 4.66]\n");
            asserts(sortedArr, expected_result, n);
            pIMem->pVTbl->Free(pIMem, sortedArr);
        }
        else {
            printf("Error: %d\n", result);
        }
    }
	
	/* bucketSortDoubleWithK  */
    printf("\n=== Testing bucketSortDoubleWithK ===\n");
    {
        double arr[] = { 123.45, 45.678, -976.34, -5.45, 3456.34, -4665.24, 4956.73 };
        uint32_t n = 7, i = 0;
        double* sortedArr = 0;
        double expected_result[] = { -4665.24, -976.34, -5.45, 45.678, 123.45, 3456.34, 4956.73 };
        int k = 3;
        int16_t result;

        printf("Input:\narr = [123.45, 45.68, -976.34, -5.45, 3456.34, -4665.24, 4956.73], k = 3\n");

        result = pIEcoLab1->pVTbl->bucketSortDoubleWithK(pIEcoLab1, arr, n, k, &sortedArr);
        if (result == 0 && sortedArr != 0) {
            printf("Returned result: [");
            for (i = 0; i < n; i++) {
                printf("%.2f", sortedArr[i]);
                if (i < n - 1) printf(", ");
            }
            printf("]\n");
            printf("Expected result: [-4665.24, -976.34, -5.45, 45.68, 123.45, 3456.34, 4956.73]\n");
            asserts(sortedArr, expected_result, n);
            pIMem->pVTbl->Free(pIMem, sortedArr);
        }
        else {
            printf("Error: %d\n", result);
        }
    }

	/* bucketSortDoubleAutoK  */
    printf("\n=== Testing bucketSortDoubleAutoK ===\n");
    {
        double arr[] = { 123.45, 567.89, 90.87, -876.54, -54.32, 234.56, -345.67 };
        uint32_t n = 7, i = 0;
        double* sortedArr = 0;
        double expected_result[] = { -876.54, -345.67, -54.32, 90.87, 123.45, 234.56, 567.89 };
        int16_t result;

        printf("Input:\narr = [123.45, 567.89, 90.87, -876.54, -54.32, 234.56, -345.67]\n");

        result = pIEcoLab1->pVTbl->bucketSortDoubleAutoK(pIEcoLab1, arr, n, &sortedArr);
        if (result == 0 && sortedArr != 0) {
            printf("Returned result: [");
            for (i = 0; i < n; i++) {
                printf("%.2f", sortedArr[i]);
                if (i < n - 1) printf(", ");
            }
            printf("]\n");
            printf("Expected result: [-876.54, -345.67, -54.32, 90.87, 123.45, 234.56, 567.89]\n");
            asserts(sortedArr, expected_result, n);
            pIMem->pVTbl->Free(pIMem, sortedArr);
        }
        else {
            printf("Error: %d\n", result);
        }
    }

	/* bucketSortLongDoubleWithK  */
    printf("\n=== Testing bucketSortLongDoubleWithK ===\n");
    {
        long double arr[] = { 1234567.89, 90876543.21, 23456788.98, -98657452.34, -45678567.64, 28377565.86, 789654.34 };
        uint32_t n = 7, i = 0;
        long double* sortedArr = 0;
        long double expected_result[] = { -98657452.34, -45678567.64, 789654.34, 1234567.89, 23456788.98, 28377565.86, 90876543.21 };
        int k = 3;
        int16_t result;

        printf("Input:\narr = [1234567.89, 90876543.21, 23456788.98, -98657452.34, -45678567.64, 28377565.86], k = 3\n");

        result = pIEcoLab1->pVTbl->bucketSortLongDoubleWithK(pIEcoLab1, arr, n, k, &sortedArr);
        if (result == 0 && sortedArr != 0) {
            printf("Returned result: [");
            for (i = 0; i < n; i++) {
                printf("%.2Lf", sortedArr[i]);
                if (i < n - 1) printf(", ");
            }
            printf("]\n");
            printf("Expected result: [-98657452.34, -45678567.64, 789654.34, 1234567.89, 23456788.98, 28377565.86, 90876543.21]\n");
            asserts(sortedArr, expected_result, n);
            pIMem->pVTbl->Free(pIMem, sortedArr);
        }
        else {
            printf("Error: %d\n", result);
        }
    }

	/* bucketSortLongDoubleAutoK  */
    printf("\n=== Testing bucketSortLongDoubleAutoK ===\n");
    {
        long double arr[] = { 12345670.89, 90876543.21, -26398.853, -37523.74, -26398.853, 37523.74, -97654.87654 };
        uint32_t n = 7, i = 0;
        long double* sortedArr = 0;
        long double expected_result[] = { -97654.87654, -37523.74, -26398.853, -26398.853, 37523.74, 12345670.89, 90876543.21 };
        int16_t result;

        printf("Input:\narr = [12345670.89, 90876543.21, -26398.85, -37523.74, -26398.85, 37523.74, -97654.88]\n");

        result = pIEcoLab1->pVTbl->bucketSortLongDoubleAutoK(pIEcoLab1, arr, n, &sortedArr);
        if (result == 0 && sortedArr != 0) {
            printf("Returned result: [");
            for (i = 0; i < n; i++) {
                printf("%.2Lf", sortedArr[i]);
                if (i < n - 1) printf(", ");
            }
            printf("]\n");
            printf("Expected result: [-97654.88, -37523.74, -26398.85, -26398.85, 37523.74, 12345670.89, 90876543.21]\n");
            asserts(sortedArr, expected_result, n);
            pIMem->pVTbl->Free(pIMem, sortedArr);
        }
        else {
            printf("Error: %d\n", result);
        }
    }
}

/*
 *
 * <сводка>
 *   Функция сравнения для qsort (int)
 * </сводка>
 *
 */
int __cdecl compare_int(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/*
 *
 * <сводка>
 *   Функция сравнения для qsort (int64_t)
 * </сводка>
 *
 */
int __cdecl compare_long(const void* a, const void* b) {
    int64_t diff = (*(int64_t*)a - *(int64_t*)b);
    return (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
}

/*
 *
 * <сводка>
 *   Функция сравнения для qsort (float)
 * </сводка>
 *
 */
int __cdecl compare_float(const void* a, const void* b) {
    float diff = (*(float*)a - *(float*)b);
    return (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
}

/*
 *
 * <сводка>
 *   Функция сравнения для qsort (double)
 * </сводка>
 *
 */
int __cdecl compare_double(const void* a, const void* b) {
    double diff = (*(double*)a - *(double*)b);
    return (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
}

/*
 *
 * <сводка>
 *   Функция сравнения для qsort (long double)
 * </сводка>
 *
 */
int __cdecl compare_long_double(const void* a, const void* b) {
    long double diff = (*(long double*)a - *(long double*)b);
    return (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
}

/*
 *
 * <сводка>
 *   Функция генерации случайного массива int
 * </сводка>
 *
 */
int* generate_random_int_array(uint32_t size, int min, int max) {
    int* arr = (int*)malloc(size * sizeof(int));
	uint32_t i = 0;
    if (arr) {
        for (i = 0; i < size; i++) {
            arr[i] = min + rand() % (max - min + 1);
        }
    }
    return arr;
}

/*
 *
 * <сводка>
 *   Функция генерации случайного массива int64_t
 * </сводка>
 *
 */
int64_t* generate_random_long_array(uint32_t size, int64_t min, int64_t max) {
    int64_t* arr = (int64_t*)malloc(size * sizeof(int64_t));
	uint32_t i = 0;
    if (arr) {
        for (i = 0; i < size; i++) {
            arr[i] = min + (int64_t)rand() % (max - min + 1);
        }
    }
    return arr;
}

/*
 *
 * <сводка>
 *   Функция генерации случайного массива float
 * </сводка>
 *
 */
float* generate_random_float_array(uint32_t size, float min, float max) {
    float* arr = (float*)malloc(size * sizeof(float));
	uint32_t i = 0;
    if (arr) {
        for (i = 0; i < size; i++) {
            arr[i] = min + (float)rand() / RAND_MAX * (max - min);
        }
    }
    return arr;
}

/*
 *
 * <сводка>
 *   Функция генерации случайного массива double
 * </сводка>
 *
 */
double* generate_random_double_array(uint32_t size, double min, double max) {
    double* arr = (double*)malloc(size * sizeof(double));
	uint32_t i = 0;
    if (arr) {
        for (i = 0; i < size; i++) {
            arr[i] = min + (double)rand() / RAND_MAX * (max - min);
        }
    }
    return arr;
}

/*
 *
 * <сводка>
 *   Функция генерации случайного массива long double
 * </сводка>
 *
 */
long double* generate_random_long_double_array(uint32_t size, long double min, long double max) {
    long double* arr = (long double*)malloc(size * sizeof(long double));
	uint32_t i = 0;
    if (arr) {
        for (i = 0; i < size; i++) {
            arr[i] = min + (long double)rand() / RAND_MAX * (max - min);
        }
    }
    return arr;
}

/*
 *
 * <сводка>
 *   Функция compareBucketSortWithQSort
 * </сводка>
 *
 * <описание>
 *   Функция сравнения производительности bucketSort и qsort для разных типов данных и размеров массивов
 * </описание>
 *
 */
void compareBucketSortWithQSort(IEcoLab1* pIEcoLab1, IEcoMemoryAllocator1* pIMem) {
    uint32_t sizes[] = {1, 10, 100, 1000, 2000, 5000, 6000, 7000, 8000};
    uint32_t numSizes = sizeof(sizes) / sizeof(sizes[0]);
    const uint32_t iterations = 1000;
	uint32_t s, size, iter, i;
	double bucket_time = 0.0, qsort_time = 0.0;
	clock_t start, end;
    
    srand((unsigned int)time(NULL));
    
    printf("\n=== Performance Comparison: BucketSort vs QSort ===\n");
    printf("Averaged over %d iterations\n\n", iterations);
    
    /* Тестирование для типа int */
    printf("========== Testing INT ==========\n");
    printf("Size\tBucketSort (ms)\tQSort (ms)\n");
    printf("---------------------------------\n");
    
    for (s = 0; s < numSizes; s++) {
        size = sizes[s];
        bucket_time = 0.0, qsort_time = 0.0;
        
        for (iter = 0; iter < iterations; iter++) {
            /* Генерация случайного массива */
            int* arr1 = generate_random_int_array(size, -1000000, 1000000);
            int* arr2 = generate_random_int_array(size, -1000000, 1000000);
            int* sorted = NULL;
			if (arr1 && arr2) {
                /* Тестирование BucketSort */
                start = clock();
                pIEcoLab1->pVTbl->bucketSortIntAutoK(pIEcoLab1, arr1, size, &sorted);
                end = clock();
                bucket_time += ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
                
                if (sorted) {
                    pIMem->pVTbl->Free(pIMem, sorted);
                }
                
                /* Тестирование QSort */
                start = clock();
                qsort(arr2, size, sizeof(int), compare_int);
                end = clock();
                qsort_time += ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
            }
            
            if (arr1) free(arr1);
            if (arr2) free(arr2);
        }
        
        bucket_time /= iterations;
        qsort_time /= iterations;
        
        printf("%d\t%.3f\t\t%.3f\n", size, bucket_time, qsort_time);
    }
    
	/* Тестирование для типа int64_t */
    printf("\n==== Testing LONG (int64_t) ====\n");
    printf("Size\tBucketSort (ms)\t QSort (ms)\n");
    printf("----------------------------------\n");
    
    for (s = 0; s < numSizes; s++) {
        size = sizes[s];
        bucket_time = 0.0, qsort_time = 0.0;
        
        for (iter = 0; iter < iterations; iter++) {
            /* Генерация случайного массива */
            int64_t* arr1 = generate_random_long_array(size, -1000000LL, 1000000LL);
            int64_t* arr2 = generate_random_long_array(size, -1000000LL, 1000000LL);
            int64_t* sorted = NULL;

            if (arr1 && arr2) {
                /* Тестирование BucketSort */
                start = clock();
                pIEcoLab1->pVTbl->bucketSortLongAutoK(pIEcoLab1, arr1, size, &sorted);
                end = clock();
                bucket_time += ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
                
                if (sorted) {
                    pIMem->pVTbl->Free(pIMem, sorted);
                }
                
                /* Тестирование QSort */
                start = clock();
                qsort(arr2, size, sizeof(int64_t), compare_long);
                end = clock();
                qsort_time += ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
            }
            
            if (arr1) free(arr1);
            if (arr2) free(arr2);
        }
        
        bucket_time /= iterations;
        qsort_time /= iterations;
        
        printf("%d\t%.3f\t\t%.3f\n", size, bucket_time, qsort_time);
    }
    
    /* Тестирование для типа float */
    printf("\n======== Testing FLOAT ========\n");
    printf("Size\tBucketSort (ms)\tQSort (ms)\n");
    printf("---------------------------------\n");
    
    for (s = 0; s < numSizes; s++) {
        size = sizes[s];
        bucket_time = 0.0, qsort_time = 0.0;
        
        for (iter = 0; iter < iterations; iter++) {
            /* Генерация случайного массива */
            float* arr1 = generate_random_float_array(size, -1000.0f, 1000.0f);
            float* arr2 = generate_random_float_array(size, -1000.0f, 1000.0f);
            float* sorted = NULL;

            if (arr1 && arr2) {
                /* Тестирование BucketSort */
                start = clock();
                pIEcoLab1->pVTbl->bucketSortFloatAutoK(pIEcoLab1, arr1, size, &sorted);
                end = clock();
                bucket_time += ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
                
                if (sorted) {
                    pIMem->pVTbl->Free(pIMem, sorted);
                }
                
                /* Тестирование QSort */
                start = clock();
                qsort(arr2, size, sizeof(float), compare_float);
                end = clock();
                qsort_time += ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
            }
            
            if (arr1) free(arr1);
            if (arr2) free(arr2);
        }
        
        bucket_time /= iterations;
        qsort_time /= iterations;
        
        printf("%d\t%.3f\t\t%.3f\n", size, bucket_time, qsort_time);
    }
    
    /* Тестирование для типа double */
    printf("\n======== Testing DOUBLE ========\n");
    printf("Size\tBucketSort (ms)\t QSort (ms)\n");
    printf("----------------------------------\n");
    
    for (s = 0; s < numSizes; s++) {
        size = sizes[s];
        bucket_time = 0.0, qsort_time = 0.0;
        
        for (iter = 0; iter < iterations; iter++) {
            /* Генерация случайного массива */
            double* arr1 = generate_random_double_array(size, -1000.0, 1000.0);
            double* arr2 = generate_random_double_array(size, -1000.0, 1000.0);
            double* sorted = NULL;
                
            if (arr1 && arr2) {
                /* Тестирование BucketSort */
                start = clock();
                pIEcoLab1->pVTbl->bucketSortDoubleAutoK(pIEcoLab1, arr1, size, &sorted);
                end = clock();
                bucket_time += ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
                
                if (sorted) {
                    pIMem->pVTbl->Free(pIMem, sorted);
                }
                
                /* Тестирование QSort */
                start = clock();
                qsort(arr2, size, sizeof(double), compare_double);
                end = clock();
                qsort_time += ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
            }
            
            if (arr1) free(arr1);
            if (arr2) free(arr2);
        }
        
        bucket_time /= iterations;
        qsort_time /= iterations;
        
        printf("%d\t%.3f\t\t%.3f\n", size, bucket_time, qsort_time);
    }
    
    /* Тестирование для типа long double */
    printf("\n===== Testing LONG DOUBLE =====\n");
    printf("Size\tBucketSort (ms)\tQSort (ms)\n");
    printf("---------------------------------\n");
    
    for (s = 0; s < numSizes; s++) {
        size = sizes[s];
        bucket_time = 0.0, qsort_time = 0.0;
        
        for (iter = 0; iter < iterations; iter++) {
            /* Генерация случайного массива */
            long double* arr1 = generate_random_long_double_array(size, -1000.0L, 1000.0L);
            long double* arr2 = generate_random_long_double_array(size, -1000.0L, 1000.0L);
            long double* sorted = NULL;
                
            if (arr1 && arr2) {
                /* Тестирование BucketSort */
                start = clock();
                pIEcoLab1->pVTbl->bucketSortLongDoubleAutoK(pIEcoLab1, arr1, size, &sorted);
                end = clock();
                bucket_time += ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
                
                if (sorted) {
                    pIMem->pVTbl->Free(pIMem, sorted);
                }
                
                /* Тестирование QSort */
                start = clock();
                qsort(arr2, size, sizeof(long double), compare_long_double);
                end = clock();
                qsort_time += ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
            }
            
            if (arr1) free(arr1);
            if (arr2) free(arr2);
        }
        
        bucket_time /= iterations;
        qsort_time /= iterations;
        
        printf("%d\t%.3f\t\t%.3f\n", size, bucket_time, qsort_time);
    }
    
    printf("\n=== Performance Comparison Completed ===\n");
}

/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    char_t* name = 0;
    char_t* copyName = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoLab1* pIEcoLab1 = 0;

    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLab1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_1F5DF16EE1BF43B999A434ED38FE8F3A);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    /* Выделение блока памяти */
    name = (char_t *)pIMem->pVTbl->Alloc(pIMem, 10);

    /* Заполнение блока памяти */
    pIMem->pVTbl->Fill(pIMem, name, 'a', 9);


    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab1, 0, &IID_IEcoLab1, (void**) &pIEcoLab1);
    if (result != 0 || pIEcoLab1 == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

	/* Запуск тестов */
    test_allFunctions(pIEcoLab1, pIMem);
	compareBucketSortWithQSort(pIEcoLab1, pIMem);

    /* Освлбождение блока памяти */
    pIMem->pVTbl->Free(pIMem, name);

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIEcoLab1 != 0) {
        pIEcoLab1->pVTbl->Release(pIEcoLab1);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

