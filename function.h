#pragma once

/**
 * @brief Произведение единственной тройки Пифагора.
 * @param mult_ произведение которое ищем.
 * @return произведение.
*/
double Euler9(int mult_);

/**
 * @brief Наибольшое произведение ближайщих чисел в числе.
 * @param number_ число.
 * @param size_ размер числа.
 * @param multAmount_ количество множителей.
 * @return результат.
*/
unsigned long long Euler8(char* number_, int size_, int amount_);

/**
 * @brief Сумма всех простых чисел до max_.
 * @param max_ граница чисел.
 * @return сумма.
*/
double Euler10(int max_);
