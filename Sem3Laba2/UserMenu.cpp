#include <iostream>
#include <string>


#include "FileWorker.h"
#include "Sorter.h"
#include "Commands.h"
#include "DynamicArray.h"

using namespace std;

void Help()
{
	cout << "'" << generateFileCommand << "' - Generate txt file\n" <<
		"'" << sortDynamicArrayByQuickSort << "' - Sort DynamicArray by QuickSort\n" <<
		"'" << sortDynamicArrayByHeapSort << "' - Sort DynamicArray by HeapSort\n" <<
		"'" << sortDynamicArrayByMergeSort << "' - Sort DynamicArray by MergeSort\n" <<
		"'" << sortLinkedListByQuickSort << "' - Sort LinkedList by QuickSort\n" <<
		"'" << sortLinkedListByHeapSort << "' - Sort LinkedList by HeapSort\n" <<
		"'" << sortLinkedListByMergeSort << "' - Sort LinkedList by MergeSort\n" <<
		"'" << sortDynamicArrayByAllMethods << "' - Sort DynamicArray by all available methods\n" <<
		"'" << sortLinkedListByAllMethods << "' - Sort LinkedList by all available methods\n";
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
		else if(userInput == generateFileCommand)
		{
			int countNumbers;
			string fileName;

			cout << "Write file name\n";
			cin >> fileName;
			cout << "Write count numbers in file\n";
			cin >> countNumbers;

			GenerateRandomNumbersFile(countNumbers, fileName);
		}
		else if (userInput == sortDynamicArrayByQuickSort)
		{
			string fileNameIn;
			string fileNameOut;
			string declineWord = "no";
			DynamicArray<int> array;
			double duration = 0;

			cout << "Write file name to sort\n";
			cin >> fileNameIn;

			cout << "Write file name to save the result (type no to don't save the result)\n";
			cin >> fileNameOut;

			ReadDynamicArrayFromFile(fileNameIn, &array);
			SortDynamicArrayByQuickSort(&array, &duration);

			cout << "Sorting spend "<< duration <<" seconds\n";

			if (fileNameOut != declineWord)
			{
				WriteDynamicArrayToFile(fileNameOut, &array);
			}
		}
		else if (userInput == sortDynamicArrayByHeapSort)
		{
			string fileNameIn;
			string fileNameOut;
			string declineWord = "no";
			DynamicArray<int> array;
			double duration = 0;

			cout << "Write file name to sort\n";
			cin >> fileNameIn;

			cout << "Write file name to save the result (type no to don't save the result)\n";
			cin >> fileNameOut;

			ReadDynamicArrayFromFile(fileNameIn, &array);
			SortDynamicArrayByHeapSort(&array, &duration);

			cout << "Sorting spend " << duration << " seconds\n";

			if (fileNameOut != declineWord)
			{
				WriteDynamicArrayToFile(fileNameOut, &array);
			}
		}
		else if (userInput == sortDynamicArrayByMergeSort)
		{
			string fileNameIn;
			string fileNameOut;
			string declineWord = "no";
			DynamicArray<int> array;
			double duration = 0;

			cout << "Write file name to sort\n";
			cin >> fileNameIn;

			cout << "Write file name to save the result (type no to don't save the result)\n";
			cin >> fileNameOut;

			ReadDynamicArrayFromFile(fileNameIn, &array);
			SortDynamicArrayByMergeSort(&array, &duration);

			cout << "Sorting spend " << duration << " seconds\n";

			if (fileNameOut != declineWord)
			{
				WriteDynamicArrayToFile(fileNameOut, &array);
			}
		}
		else if (userInput == sortLinkedListByQuickSort)
		{
			string fileNameIn;
			string fileNameOut;
			string declineWord = "no";
			LinkedList<int> list;
			double duration = 0;

			cout << "Write file name to sort\n";
			cin >> fileNameIn;

			cout << "Write file name to save the result (type no to don't save the result)\n";
			cin >> fileNameOut;

			ReadLinkedListFromFile(fileNameIn, &list);
			SortLinkedListByQuickSort(&list, &duration);

			cout << "Sorting spend " << duration << " seconds\n";

			if (fileNameOut != declineWord)
			{
				WriteLinkedListToFile(fileNameOut, &list);
			}
		}
		else if (userInput == sortLinkedListByHeapSort)
		{
			string fileNameIn;
			string fileNameOut;
			string declineWord = "no";
			LinkedList<int> list;
			double duration = 0;

			cout << "Write file name to sort\n";
			cin >> fileNameIn;

			cout << "Write file name to save the result (type no to don't save the result)\n";
			cin >> fileNameOut;

			ReadLinkedListFromFile(fileNameIn, &list);
			SortLinkedListByHeapSort(&list, &duration);

			cout << "Sorting spend " << duration << " seconds\n";

			if (fileNameOut != declineWord)
			{
				WriteLinkedListToFile(fileNameOut, &list);
			}
		}
		else if (userInput == sortLinkedListByMergeSort)
		{
			string fileNameIn;
			string fileNameOut;
			string declineWord = "no";
			LinkedList<int> list;
			double duration = 0;

			cout << "Write file name to sort\n";
			cin >> fileNameIn;

			cout << "Write file name to save the result (type no to don't save the result)\n";
			cin >> fileNameOut;

			ReadLinkedListFromFile(fileNameIn, &list);
			SortLinkedListByMergeSort(&list, &duration);

			cout << "Sorting spend " << duration << " seconds\n";

			if (fileNameOut != declineWord)
			{
				WriteLinkedListToFile(fileNameOut, &list);
			}
		}
		else if (userInput == sortDynamicArrayByAllMethods)
		{
			string fileNameIn;
			string fileNameOut;
			string declineWord = "no";
			DynamicArray<int> array;
			double durationQuickSort = 0;
			double durationHeapSort = 0;
			double durationMergeSort = 0;

			cout << "Write file name to sort\n";
			cin >> fileNameIn;

			cout << "Write file name to save the result (type no to don't save the result)\n";
			cin >> fileNameOut;

			ReadDynamicArrayFromFile(fileNameIn, &array);
			SortDynamicArrayByAllMethods(&array, &durationQuickSort, &durationHeapSort, &durationMergeSort);

			cout << "QuickSort spend " << durationQuickSort << " seconds\n";
			cout << "HeapSort spend " << durationHeapSort << " seconds\n";
			cout << "MergeSort spend " << durationMergeSort << " seconds\n";

			if (fileNameOut != declineWord)
			{
				WriteDynamicArrayToFile(fileNameOut, &array);
			}
		}
		else if (userInput == sortLinkedListByAllMethods)
		{
			string fileNameIn;
			string fileNameOut;
			string declineWord = "no";
			LinkedList<int> list;
			double durationQuickSort = 0;
			double durationHeapSort = 0;
			double durationMergeSort = 0;

			cout << "Write file name to sort\n";
			cin >> fileNameIn;

			cout << "Write file name to save the result (type no to don't save the result)\n";
			cin >> fileNameOut;

			ReadLinkedListFromFile(fileNameIn, &list);
			SortLinkedListByAllMethods(&list, &durationQuickSort, &durationHeapSort, &durationMergeSort);

			cout << "QuickSort spend " << durationQuickSort << " seconds\n";
			cout << "HeapSort spend " << durationHeapSort << " seconds\n";
			cout << "MergeSort spend " << durationMergeSort << " seconds\n";

			if (fileNameOut != declineWord)
			{
				WriteLinkedListToFile(fileNameOut, &list);
			}
			}
		else
		{
			cout << "Unknown command\n";
		}
	}
}