#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <time.h>
#include <iostream>
#include "ArrClass.h"
#include <thread>
#include <chrono>

void generate_array(std::vector<ArrClass>&, int);
bool bubbleSort(std::vector<ArrClass>&, int);
void insertionSort(std::vector<ArrClass>&, int);
void selectionSort(std::vector<ArrClass>&, int);

void swap(ArrClass* xp, ArrClass* yp);
void setWhite(ArrClass& elem);