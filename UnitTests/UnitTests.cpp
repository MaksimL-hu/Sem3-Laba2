#include "CppUnitTest.h"

#include "../Sem3Laba2/DynamicArray.h"
#include "../Sem3Laba2/LinkedList.h"
#include "../Sem3Laba2/Sorter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynamicArrayTest
{
	TEST_CLASS(UnitTests)
	{
	public:

		TEST_METHOD(СonstructorTests)
		{
			int array[] = { 1,2,3,4 };
			int size = 4;

			DynamicArray<int> dynamicArray(array, size);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i));
			}

			DynamicArray<int> dynamicArray1(size);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray1.GetElement(i));
			}

			DynamicArray<int> dynamicArray2(dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray2.GetElement(i));
			}
		}

		TEST_METHOD(CopyСonstructorTests)
		{
			int array[] = { 1,2,3,4 };
			int size = 4;

			DynamicArray<int> dynamicArray1(array, size);
			DynamicArray<int> dynamicArray2 = dynamicArray1;

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray1.GetElement(i));
			}

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray2.GetElement(i));
			}
		}

		TEST_METHOD(GetElementsTests)
		{
			int array[] = { 0,1,2,3,4,5,6,7,8,9 };
			int size = 10;

			DynamicArray<int> dynamicArray(array, size);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == array[i]);
			}

			Assert::IsTrue(dynamicArray.GetFirstElement() == array[0]);
			Assert::IsTrue(dynamicArray.GetLastElement() == array[size - 1]);

		}

		TEST_METHOD(GetSubsequencesTests)
		{
			int array[] = { 0,1,2,3,4,5,6,7,8,9 };
			int size = 10;

			DynamicArray<int> dynamicArray(array, size);

			DynamicArray<int>* subsequence = dynamicArray.GetSubsequence(0, size);

			Assert::IsTrue(dynamicArray.GetLength() == subsequence->GetLength());

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == subsequence->GetElement(i));
			}

			subsequence = dynamicArray.GetSubsequence(0, 4 * size);

			Assert::IsTrue(dynamicArray.GetLength() == subsequence->GetLength());

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == subsequence->GetElement(i));
			}

			int sliceCount = 2;

			subsequence = dynamicArray.GetSubsequence(sliceCount, size - sliceCount);

			Assert::IsTrue(size - 2 * sliceCount + 1 == subsequence->GetLength());

			for (int i = 0; i < size - sliceCount - 1; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i + sliceCount) == subsequence->GetElement(i));
			}

			int index = 3;

			subsequence = dynamicArray.GetSubsequence(index, index);

			Assert::IsTrue(subsequence->GetLength() == 1);

			Assert::IsTrue(dynamicArray.GetElement(index) == subsequence->GetElement(0));
		}

		TEST_METHOD(GetLenghtTests)
		{
			int size = 10;

			DynamicArray<int> dynamicArray(size);

			Assert::IsTrue(dynamicArray.GetLength() == size);
		}

		TEST_METHOD(AppendTest)
		{
			int array[] = { 0,1,2,3,4,5,6,7,8 };
			int size = 9;
			int number = 9;

			DynamicArray<int> dynamicArray(array, size);

			dynamicArray.Append(number);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == array[i]);
			}

			Assert::IsTrue(dynamicArray.GetElement(size) == number);
			Assert::IsTrue(dynamicArray.GetLength() == (size + 1));
		}

		TEST_METHOD(PrependTest)
		{
			int array[] = { 1,2,3,4,5,6,7,8,9 };
			int size = 9;
			int number = 0;

			DynamicArray<int> dynamicArray(array, size);

			dynamicArray.Prepend(number);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i + 1) == array[i]);
			}

			Assert::IsTrue(dynamicArray.GetElement(0) == number);
			Assert::IsTrue(dynamicArray.GetLength() == (size + 1));
		}

		TEST_METHOD(InsertAtTest)
		{
			int array[] = { 0,1,2,3,5,6,7,8,9 };
			int size = 9;
			int number = 4;
			int index = 4;

			DynamicArray<int> dynamicArray(array, size);

			dynamicArray.InsertAt(number, index);

			for (int i = 0; i < index; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == array[i]);
			}

			Assert::IsTrue(dynamicArray.GetElement(index) == number);

			for (int i = index + 1; i < dynamicArray.GetLength(); i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == array[i - 1]);
			}

			Assert::IsTrue(dynamicArray.GetLength() == (size + 1));
		}

		TEST_METHOD(UnionTest)
		{
			int array1[] = { 0,1,2,3,5 };
			int array2[] = { 6,7,8,9 };
			int size1 = 5;
			int size2 = 4;

			DynamicArray<int> dynamicArray1(array1, size1);
			DynamicArray<int> dynamicArray2(array2, size2);

			dynamicArray1.Union(&dynamicArray2);

			for (int i = 0; i < size1; i++)
			{
				Assert::IsTrue(dynamicArray1.GetElement(i) == array1[i]);
			}

			for (int i = size1 + 1; i < size1 + size2; i++)
			{
				Assert::IsTrue(dynamicArray1.GetElement(i) == array2[i - size1]);
			}
		}

		TEST_METHOD(IteratorTest)
		{
			int array[] = { 0,1,2,3,5,6,7,8,9 };
			int size = 9;
			DynamicArray<int> dynamicArray(array, size);

			auto begin = dynamicArray.ToBegin();
			auto end = dynamicArray.ToEnd();
			int i = 0;

			while (*begin != *end)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == **begin);
				++(*begin);
				i++;
			}
		}
	};
}

namespace DynamicArraySortingTest
{
	TEST_CLASS(UnitTests)
	{
	public:

		TEST_METHOD(QuickSortTest1)
		{
			Sorter<int> sorter;
			int array[] = { 5,3,1,8,9,2,34,-7 };
			int size = 8;
			int sortedArray[] = { -7,1,2,3,5,8,9,34 };

			DynamicArray<int> dynamicArray(array, size);

			sorter.QuickSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(QuickSortTest2)
		{
			Sorter<int> sorter;
			int array[] = { 1,2,3,4,5,6,7,8 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			DynamicArray<int> dynamicArray(array, size);

			sorter.QuickSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(QuickSortTest3)
		{
			Sorter<int> sorter;
			int array[] = { 1,2,3,5,4,6,7,8 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			DynamicArray<int> dynamicArray(array, size);
			
			sorter.QuickSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(QuickSortTest4)
		{
			Sorter<int> sorter;
			int array[] = { 1 };
			int size = 1;
			int sortedArray[] = { 1 };

			DynamicArray<int> dynamicArray(array, size);
			
			sorter.QuickSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(QuickSortTest5)
		{
			Sorter<int> sorter;
			int array[] = { 8,7,6,5,4,3,2,1 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			DynamicArray<int> dynamicArray(array, size);
			
			sorter.QuickSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(QuickSortTest6)
		{
			Sorter<int> sorter;
			int size = 10000;
			DynamicArray<int> dynamicArray(0);

			for (int i = 0; i < size; i++)
			{
				dynamicArray.Append(rand());
			}

			sorter.QuickSort(&dynamicArray);

			for (int i = 0; i < size - 1; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) <= dynamicArray.GetElement(i + 1));
			}
		}

		TEST_METHOD(HeapSortSortTest1)
		{
			Sorter<int> sorter;
			int array[] = { 5,3,1,8,9,2,34,-7 };
			int size = 8;
			int sortedArray[] = { -7,1,2,3,5,8,9,34 };

			DynamicArray<int> dynamicArray(array, size);

			sorter.HeapSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(HeapSortTest2)
		{
			Sorter<int> sorter;
			int array[] = { 1,2,3,4,5,6,7,8 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			DynamicArray<int> dynamicArray(array, size);

			sorter.HeapSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(HeapSortTest3)
		{
			Sorter<int> sorter;
			int array[] = { 1,2,3,5,4,6,7,8 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			DynamicArray<int> dynamicArray(array, size);
			
			sorter.HeapSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(HeapSortTest4)
		{
			Sorter<int> sorter;
			int array[] = { 1 };
			int size = 1;
			int sortedArray[] = { 1 };

			DynamicArray<int> dynamicArray(array, size);
			
			sorter.HeapSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(HeapSortTest5)
		{
			Sorter<int> sorter;
			int array[] = { 8,7,6,5,4,3,2,1 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			DynamicArray<int> dynamicArray(array, size);
			
			sorter.HeapSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(HeapSortTest6)
		{
			Sorter<int> sorter;
			int size = 10000;
			DynamicArray<int> dynamicArray(0);

			for (int i = 0; i < size; i++)
			{
				dynamicArray.Append(rand());
			}

			sorter.HeapSort(&dynamicArray);

			for (int i = 0; i < size - 1; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) <= dynamicArray.GetElement(i + 1));
			}
		}

		TEST_METHOD(MergeSortTest1)
		{
			Sorter<int> sorter;
			int array[] = { 5,3,1,8,9,2,34,-7 };
			int size = 8;
			int sortedArray[] = { -7,1,2,3,5,8,9,34 };

			DynamicArray<int> dynamicArray(array, size);
			
			sorter.MergeSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(MergeSortTest2)
		{
			Sorter<int> sorter;
			int array[] = { 1,2,3,4,5,6,7,8 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			DynamicArray<int> dynamicArray(array, size);
			
			sorter.MergeSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(MergeSortTest3)
		{
			Sorter<int> sorter;
			int array[] = { 1,2,3,5,4,6,7,8 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			DynamicArray<int> dynamicArray(array, size);
			
			sorter.MergeSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(MergeSortTest4)
		{
			Sorter<int> sorter;
			int array[] = { 1 };
			int size = 1;
			int sortedArray[] = { 1 };

			DynamicArray<int> dynamicArray(array, size);
			
			sorter.MergeSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(MergeSortTest5)
		{
			Sorter<int> sorter;
			int array[] = { 8,7,6,5,4,3,2,1 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			DynamicArray<int> dynamicArray(array, size);
			
			sorter.MergeSort(&dynamicArray);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(MergeSortTest6)
		{
			Sorter<int> sorter;
			int size = 10000;
			DynamicArray<int> dynamicArray(0);

			for (int i = 0; i < size; i++)
			{
				dynamicArray.Append(rand());
			}

			sorter.MergeSort(&dynamicArray);

			for (int i = 0; i < size - 1; i++)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) <= dynamicArray.GetElement(i + 1));
			}
		}
	};
}

namespace LinkedListTest
{
	TEST_CLASS(UnitTests)
	{
	public:

		TEST_METHOD(СonstructorTests)
		{
			int array[] = { 1,2,3,4 };
			int size = 4;

			LinkedList<int> list(array, size);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i));
			}

			LinkedList<int> list1(list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list1.GetElement(i));
			}
		}

		TEST_METHOD(GetElementsTests)
		{
			int array[] = { 0,1,2,3,4,5,6,7,8,9 };
			int size = 10;

			LinkedList<int> list(array, size);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == array[i]);
			}

			Assert::IsTrue(list.GetFirstElement() == array[0]);
			Assert::IsTrue(list.GetLastElement() == array[size - 1]);

		}

		TEST_METHOD(GetSubsequencesTests)
		{
			int array[] = { 0,1,2,3,4,5,6,7,8,9 };
			int size = 10;

			LinkedList<int> list(array, size);

			LinkedList<int>* subsequence = list.GetSubsequence(0, size);

			Assert::IsTrue(list.GetLength() == subsequence->GetLength());

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == subsequence->GetElement(i));
			}

			subsequence = list.GetSubsequence(0, 4 * size);

			Assert::IsTrue(list.GetLength() == subsequence->GetLength());

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == subsequence->GetElement(i));
			}

			int sliceCount = 2;

			subsequence = list.GetSubsequence(sliceCount, size - sliceCount);

			Assert::IsTrue(size - 2 * sliceCount + 1 == subsequence->GetLength());

			for (int i = 0; i < size - sliceCount - 1; i++)
			{
				Assert::IsTrue(list.GetElement(i + sliceCount) == subsequence->GetElement(i));
			}

			int index = 3;

			subsequence = list.GetSubsequence(index, index);

			Assert::IsTrue(subsequence->GetLength() == 1);

			Assert::IsTrue(list.GetElement(index) == subsequence->GetElement(0));
		}

		TEST_METHOD(GetLenghtTests)
		{
			int array[] = { 0,1,2,3,4,5,6,7,8,9 };
			int size = 10;

			LinkedList<int> list(array, size);

			Assert::IsTrue(list.GetLength() == size);
		}

		TEST_METHOD(AppendTest)
		{
			int array[] = { 0,1,2,3,4,5,6,7,8 };
			int size = 9;
			int number = 9;

			LinkedList<int> list(array, size);

			list.Append(number);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == array[i]);
			}

			Assert::IsTrue(list.GetElement(size) == number);
			Assert::IsTrue(list.GetLength() == (size + 1));
		}

		TEST_METHOD(PrependTest)
		{
			int array[] = { 1,2,3,4,5,6,7,8,9 };
			int size = 9;
			int number = 0;

			LinkedList<int> list(array, size);

			list.Prepend(number);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i + 1) == array[i]);
			}

			Assert::IsTrue(list.GetElement(0) == number);
			Assert::IsTrue(list.GetLength() == (size + 1));
		}

		TEST_METHOD(InsertAtTest)
		{
			int array[] = { 0,1,2,3,5,6,7,8,9 };
			int size = 9;
			int number = 4;
			int index = 4;

			LinkedList<int> list(array, size);

			list.InsertAt(number, index);

			for (int i = 0; i < index; i++)
			{
				Assert::IsTrue(list.GetElement(i) == array[i]);
			}

			Assert::IsTrue(list.GetElement(index) == number);

			for (int i = index + 1; i < list.GetLength(); i++)
			{
				Assert::IsTrue(list.GetElement(i) == array[i - 1]);
			}

			Assert::IsTrue(list.GetLength() == (size + 1));
		}

		TEST_METHOD(UnionTest)
		{
			int array1[] = { 0,1,2,3,5 };
			int array2[] = { 6,7,8,9 };
			int size1 = 5;
			int size2 = 4;

			LinkedList<int> list1(array1, size1);
			LinkedList<int> list2(array2, size2);

			list1.Union(&list2);

			for (int i = 0; i < size1; i++)
			{
				Assert::IsTrue(list1.GetElement(i) == array1[i]);
			}

			for (int i = size1 + 1; i < size1 + size2; i++)
			{
				Assert::IsTrue(list1.GetElement(i) == array2[i - size1]);
			}
		}

		TEST_METHOD(IteratorTest)
		{
			int array[] = { 0,1,2,3,5,6,7,8,9 };
			int size = 9;
			LinkedList<int> dynamicArray(array, size);

			auto begin = dynamicArray.ToBegin();
			auto end = dynamicArray.ToEnd();
			int i = 0;

			while (*begin != *end)
			{
				Assert::IsTrue(dynamicArray.GetElement(i) == **begin);
				++(*begin);
				i++;
			}
		}
	};
}

namespace LinkedListSortingTest
{
	TEST_CLASS(UnitTests)
	{
	public:

		TEST_METHOD(QuickSortTest1)
		{
			Sorter<int> sorter;
			int array[] = { 5,3,1,8,9,2,34,-7 };
			int size = 8;
			int sortedArray[] = { -7,1,2,3,5,8,9,34 };

			LinkedList<int> list(array, size);

			sorter.QuickSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(QuickSortTest2)
		{
			Sorter<int> sorter;
			int array[] = { 1,2,3,4,5,6,7,8 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			LinkedList<int> list(array, size);
			
			sorter.QuickSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(QuickSortTest3)
		{
			Sorter<int> sorter;
			int array[] = { 1,2,3,5,4,6,7,8 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			LinkedList<int> list(array, size);
			
			sorter.QuickSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(QuickSortTest4)
		{
			Sorter<int> sorter;
			int array[] = { 1 };
			int size = 1;
			int sortedArray[] = { 1 };

			LinkedList<int> list(array, size);
			
			sorter.QuickSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(QuickSortTest5)
		{
			Sorter<int> sorter;
			int array[] = { 8,7,6,5,4,3,2,1 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			LinkedList<int> list(array, size);
			
			sorter.QuickSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(QuickSortTest6)
		{
			Sorter<int> sorter;
			int size = 10000;
			LinkedList<int> list;

			for (int i = 0; i < size; i++)
			{
				list.Append(rand());
			}

			sorter.QuickSort(&list);

			for (int i = 0; i < size - 1; i++)
			{
				Assert::IsTrue(list.GetElement(i) <= list.GetElement(i + 1));
			}
		}

		TEST_METHOD(HeapSortSortTest1)
		{
			Sorter<int> sorter;
			int array[] = { 5,3,1,8,9,2,34,-7 };
			int size = 8;
			int sortedArray[] = { -7,1,2,3,5,8,9,34 };

			LinkedList<int> list(array, size);
			
			sorter.HeapSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(HeapSortTest2)
		{
			Sorter<int> sorter;
			int array[] = { 1,2,3,4,5,6,7,8 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			LinkedList<int> list(array, size);
			
			sorter.HeapSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(HeapSortTest3)
		{
			Sorter<int> sorter;
			int array[] = { 1,2,3,5,4,6,7,8 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			LinkedList<int> list(array, size);
			
			sorter.HeapSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(HeapSortTest4)
		{
			Sorter<int> sorter;
			int array[] = { 1 };
			int size = 1;
			int sortedArray[] = { 1 };

			LinkedList<int> list(array, size);
			
			sorter.HeapSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(HeapSortTest5)
		{
			Sorter<int> sorter;
			int array[] = { 8,7,6,5,4,3,2,1 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			LinkedList<int> list(array, size);
			
			sorter.HeapSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(HeapSortTest6)
		{
			Sorter<int> sorter;
			int size = 10000;
			LinkedList<int> list;

			for (int i = 0; i < size; i++)
			{
				list.Append(rand());
			}

			sorter.HeapSort(&list);

			for (int i = 0; i < size - 1; i++)
			{
				Assert::IsTrue(list.GetElement(i) <= list.GetElement(i + 1));
			}
		}

		TEST_METHOD(MergeSortTest1)
		{
			Sorter<int> sorter;
			int array[] = { 5,3,1,8,9,2,34,-7 };
			int size = 8;
			int sortedArray[] = { -7,1,2,3,5,8,9,34 };

			LinkedList<int> list(array, size);
			
			sorter.MergeSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(MergeSortTest2)
		{
			Sorter<int> sorter;
			int array[] = { 1,2,3,4,5,6,7,8 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			LinkedList<int> list(array, size);
			
			sorter.MergeSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(MergeSortTest3)
		{
			Sorter<int> sorter;
			int array[] = { 1,2,3,5,4,6,7,8 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			LinkedList<int> list(array, size);
			
			sorter.MergeSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(MergeSortTest4)
		{
			Sorter<int> sorter;
			int array[] = { 1 };
			int size = 1;
			int sortedArray[] = { 1 };

			LinkedList<int> list(array, size);
			
			sorter.MergeSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(MergeSortTest5)
		{
			Sorter<int> sorter;
			int array[] = { 8,7,6,5,4,3,2,1 };
			int size = 8;
			int sortedArray[] = { 1,2,3,4,5,6,7,8 };

			LinkedList<int> list(array, size);
			
			sorter.MergeSort(&list);

			for (int i = 0; i < size; i++)
			{
				Assert::IsTrue(list.GetElement(i) == sortedArray[i]);
			}
		}

		TEST_METHOD(MergeSortTest6)
		{
			Sorter<int> sorter;
			int size = 10000;
			LinkedList<int> list;

			for (int i = 0; i < size; i++)
			{
				list.Append(rand());
			}

			sorter.MergeSort(&list);

			for (int i = 0; i < size - 1; i++)
			{
				Assert::IsTrue(list.GetElement(i) <= list.GetElement(i + 1));
			}
		}
	};
}