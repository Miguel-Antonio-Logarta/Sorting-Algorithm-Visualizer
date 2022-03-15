#include "SortingAlgorithms.h"

void generate_array(std::vector<ArrClass>& arrVector, int iSize)
{
	arrVector.clear();
	arrVector.reserve(iSize);

	// Generate array in order
	for (int i = 0; i < iSize; i++)
	{
		ArrClass arrObject;
		arrObject.iValue = i + 1;
		arrVector.push_back(arrObject);
	}

	// Shuffle
	srand(time(NULL));
	for (int i = iSize - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		ArrClass temp = arrVector[i];
		arrVector[i] = arrVector[j];
		arrVector[j] = temp;
	}
}

bool bubbleSort(std::vector<ArrClass>& vecInput, int iWaitTime)
{
	int iSize = vecInput.size();
	// Bubble sort has runtime of O(n^2)
	bool bswapped = false;
	// If it does a full pass through the array without swapping, end this loop
	//ArrClass firstObject = vecInput[0];
	//ArrClass secondObject = vecInput[0];
	ArrClass* aPointer = &vecInput[0];
	ArrClass* aPointer2 = &vecInput[0];
	do
	{
		bswapped = false;
		// Loop through the array
		for (int i = 1; i < iSize; i++)
		{
			/*int* a = &arrInput[i];
			int* b = &arrInput[i-1];*/

			// Check if the pair is not in order.
			if (vecInput[i].iValue < vecInput[i - 1].iValue)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(iWaitTime));
				// Perform swap since they are not in order
				// Save a pointer to both vecInputs so that we can turn them white when needed
				/*setWhite(&firstObject, &secondObject);*/
				/*std::cout << "Before the swap" << std::endl;
				std::cout << &vecInput[i] << " " << aPointer << std::endl;
				std::cout << &vecInput[i - 1] << " " << aPointer2 << std::endl;*/
				/*aPointer->setActive(false);
				aPointer2->setActive(false);*/
				//setWhite(aPointer, aPointer2);
				swap(&vecInput[i], &vecInput[i - 1]);
				bswapped = true;
				//std::cout << "After the swap" << std::endl;
				aPointer = &vecInput[i];
				aPointer2 = &vecInput[i - 1];
				/*std::cout << &vecInput[i] << " " << aPointer << std::endl;
				std::cout << &vecInput[i - 1] << " " << aPointer2 << std::endl;*/
			}
			//PrintContents(arrInput, 10, bswapped);
		}

	} while (bswapped == true);
	//setWhite(aPointer, aPointer2);

	std::cout << "successfully sorted\n";
	return true;
}

void insertionSort(std::vector<ArrClass>& arr, int delay)
{
	int i, key, j;
	for (i = 1; i < arr.size(); i++)
	{
		key = arr[i].iValue;
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j].iValue > key)
		{
			arr[j + 1].setActive(true);
			//arr[j + 1].iValue = arr[j].iValue;
			swap(&arr[j + 1], &arr[j]);
			std::this_thread::sleep_for(std::chrono::milliseconds(delay));
			//setWhite(arr[j + 1], arr[j]);
			setWhite(arr[j + 1]);
			setWhite(arr[j]);
			j = j - 1;
		}
		arr[j + 1].iValue = key;
	}
}

void selectionSort(std::vector<ArrClass>&, int)
{
}

void swap(ArrClass* xp, ArrClass* yp)
{
	/*xp->setActive(true);
	yp->setActive(true);*/

	sf::Vector2f xpCoord = xp->rectShape.getPosition();
	sf::Vector2f ypCoord = yp->rectShape.getPosition();
	/*std::cout << xpCoord.x << " " << xpCoord.y << std::endl;
	std::cout << ypCoord.x << " " << ypCoord.y << std::endl;*/

	// Copy the variable
	ArrClass temp = *xp;

	// Perform the swap
	*xp = *yp;
	*yp = temp;

	/*sf::Vector2f xpCoord = xp->rectShape.getPosition();
	sf::Vector2f ypCoord = yp->rectShape.getPosition();*/
	/*std::cout << xpCoord.x << " " << xpCoord.y << std::endl;
	std::cout << ypCoord.x << " " << ypCoord.y << std::endl;*/

	// So the coordinates do swap, but for some reason the rectangles do not redraw.
}

//void setWhite(ArrClass* a, ArrClass* b)
//{
//	a->setActive(false);
//	b->setActive(false);
//}

void setWhite(ArrClass& elem) {
	elem.setActive(false);
}