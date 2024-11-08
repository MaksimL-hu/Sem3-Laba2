#include <iostream>
#include <string>

#include "FileWorker.h"
#include "SorterMethods.h"
#include "People.h"
#include "Commands.h"
#include "DynamicArray.h"
#include "GrathBuilder.h"

using namespace std;

void Help()
{
	cout << "'" << generateFileCommand << "' - Generate txt file\n" <<
		"'" << sortDynamicArrayByQuickSort << "' - Sort DynamicArray by QuickSort\n" <<
		"'" << sortDynamicArrayByHeapSort << "' - Sort DynamicArray by HeapSort\n" <<
		"'" << sortDynamicArrayByMergeSort << "' - Sort DynamicArray by MergeSort\n" <<
		"'" << sortDynamicArrayByAllMethods << "' - Sort DynamicArray by all available methods\n" <<
		"'" << plotGrathForQuickSort << "' - Plot grath for QuickSort\n" <<
		"'" << plotGrathForHeapSort << "' - Plot grath for HeapSort\n" <<
		"'" << plotGrathForMergeSort << "' - Plot grath for MergeSort\n";
}

template<typename T>
void TryWriteToFile(string fileNameOut, string declineWord, DynamicArray<T>* array)
{
	if (fileNameOut != declineWord)
	{
		std::cout << "Writing data to the file " << fileNameOut << std::endl;
		WriteSequenceToFile(fileNameOut, array);
	}
}

void OpenMenu()
{
	bool isOpen = true;
	string userInput;

	cout << "Write 'help' to show available commands\n";

	while (isOpen)
	{
		cin >> userInput;

		if (userInput == helpCommand)
		{
			Help();
		}
		else if (userInput == generateFileCommand)
		{
			int countNumbers;
			string fileName;

			cout << "Write file name\n";
			cin >> fileName;
			cout << "Write count data in file\n";
			cin >> countNumbers;

			GenerateRandomFile(countNumbers, fileName);
		}
		else if (userInput == sortDynamicArrayByQuickSort)
		{
			string fileNameIn;
			string fileNameOut;
			string declineWord = "no";
			DynamicArray<People> array;
			double duration = 0;

			cout << "Write file name to sort\n";
			cin >> fileNameIn;

			cout << "Write file name to save the result (type no to don't save the result)\n";
			cin >> fileNameOut;

			std::cout << "Read data from the file " << fileNameIn << std::endl;
			ReadDynamicArrayFromFile(fileNameIn, &array);

			std::cout << "Starting sorting..." << std::endl;
			SortSequenceByQuickSort(&array, &duration);

			cout << "Sorting spend " << duration << " seconds\n";

			TryWriteToFile(fileNameOut, declineWord, &array);
		}
		else if (userInput == sortDynamicArrayByHeapSort)
		{
			string fileNameIn;
			string fileNameOut;
			string declineWord = "no";
			DynamicArray<People> array;
			double duration = 0;

			cout << "Write file name to sort\n";
			cin >> fileNameIn;

			cout << "Write file name to save the result (type no to don't save the result)\n";
			cin >> fileNameOut;

			std::cout << "Read data from the file " << fileNameIn << std::endl;
			ReadDynamicArrayFromFile(fileNameIn, &array);

			std::cout << "Starting sorting..." << std::endl;
			SortSequenceByHeapSort(&array, &duration);

			cout << "Sorting spend " << duration << " seconds\n";

			TryWriteToFile(fileNameOut, declineWord, &array);
		}
		else if (userInput == sortDynamicArrayByMergeSort)
		{
			string fileNameIn;
			string fileNameOut;
			string declineWord = "no";
			DynamicArray<People> array;
			double duration = 0;

			cout << "Write file name to sort\n";
			cin >> fileNameIn;

			cout << "Write file name to save the result (type no to don't save the result)\n";
			cin >> fileNameOut;

			std::cout << "Read data from the file " << fileNameIn << std::endl;
			ReadDynamicArrayFromFile(fileNameIn, &array);

			std::cout << "Starting sorting..." << std::endl;
			SortSequenceByMergeSort(&array, &duration);

			cout << "Sorting spend " << duration << " seconds\n";

			TryWriteToFile(fileNameOut, declineWord, &array);
		}
		else if (userInput == sortDynamicArrayByAllMethods)
		{
			string fileNameIn;
			string fileNameOut;
			string declineWord = "no";
			DynamicArray<People> array;
			double durationQuickSort = 0;
			double durationHeapSort = 0;
			double durationMergeSort = 0;

			cout << "Write file name to sort\n";
			cin >> fileNameIn;

			cout << "Write file name to save the result (type no to don't save the result)\n";
			cin >> fileNameOut;

			std::cout << "Read data from the file " << fileNameIn << std::endl;
			ReadDynamicArrayFromFile(fileNameIn, &array);

			std::cout << "Starting sorting..." << std::endl;
			SortDynamicArrayByAllMethods(&array, &durationQuickSort, &durationHeapSort, &durationMergeSort);

			cout << "QuickSort spend " << durationQuickSort << " seconds\n";
			cout << "HeapSort spend " << durationHeapSort << " seconds\n";
			cout << "MergeSort spend " << durationMergeSort << " seconds\n";

			TryWriteToFile(fileNameOut, declineWord, &array);
		}
		else if (userInput == plotGrathForQuickSort || userInput == plotGrathForHeapSort || userInput == plotGrathForMergeSort)
		{
			cout << "Initializing variables\n";

			const int max = 1000000;
			const int step = 10000;

			int iteration = 1;

			DynamicArray<double> x;
			DynamicArray<double> y;

			std::string name;

			cout << "Calculating points for grath\n";
			
			for (int i = step; i < max; i+= step)
			{
				DynamicArray<People> peoples(i);

				for (int j = 0; j < i; j++)
				{
					People people = People();
					peoples[j] = people;
				}

				double duration;

				if (userInput == plotGrathForQuickSort)
				{
					SortSequenceByQuickSort(&peoples, &duration);
				}
				else if (userInput == plotGrathForHeapSort)
				{
					SortSequenceByHeapSort(&peoples, &duration);
				}
				else
				{
					SortSequenceByMergeSort(&peoples, &duration);
				}

				x.Append(i);
				y.Append(duration);

				std::cout << iteration << ") Sorting " << i << " elements spend " << duration << std::endl;

				iteration++;
			}

			cout << "Plot Grath\n";

			PlotGraph(x, y, userInput);
		}
		else
		{
			cout << "Unknown command\n";
		}
	}
}